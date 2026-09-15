# Solution: Sensor Report

**Course/Module/Activity:** CSC240 · Module 3 C Preprocessor, User-Defined Types, and Modules · debug01
**Bug type(s):** logic, paradigm-specific (macro expansion)
**Bug count:** 2 (related: both are textual-substitution pitfalls)

## Observed Behavior

Compiles cleanly with `-Wall`. Both results are wrong:

```
Border areas (width 2):
  side  3 ->  10 cells
  side  5 ->   4 cells
  side 10 -> -46 cells
Peak reading: 5
```

## The Bug(s)

1. `#define SQUARE(x) x * x` has no parentheses. `SQUARE(side + 2 * BORDER_WIDTH) - SQUARE(side)` expands to `side + 2 * 2 * side + 2 * 2 - side * side`, i.e. `5 * side + 4 - side * side`, instead of `(side + 4) * (side + 4) - side * side`.
2. `peak = MAX(read_sensor(), peak);` expands to `((read_sensor()) > (peak) ? (read_sensor()) : (peak))`. Whenever the comparison is true, `read_sensor()` is called a *second* time, so the value stored in `peak` is the reading *after* the one that won, and the winning reading is lost.

## Why the Program Behaved Incorrectly

The preprocessor performs text substitution before the compiler sees the code. In bug 1 the substituted text has operator precedence the macro author did not intend; for `side = 3` it evaluates `3 + 12 + 4 - 9 = 10` rather than `49 - 9 = 40`.

In bug 2 an argument with a side effect is evaluated twice. Trace with readings 14, 27, 9, 31, 22, 18, 40, 5 (`read_sensor()` returns -1 once the run is used up):

| iteration | comparison (1st call) | 2nd call? | `peak` after |
|---|---|---|---|
| 1 | 14 > 0 true | yes, returns 27 | 27 |
| 2 | 9 > 27 false | no | 27 |
| 3 | 31 > 27 true | yes, returns 22 | 22 |
| 4 | 18 > 22 false | no | 22 |
| 5 | 40 > 22 true | yes, returns 5 | 5 |
| 6-8 | -1 > 5 false | no | 5 |

The true peak, 40, was consumed by a comparison and then thrown away by the second call.

## The Concept This Illustrates

Function-like macros are not functions. Two rules students must learn: parenthesize every parameter *and* the whole body, and never pass an expression with side effects (`i++`, a function call that consumes input) to a macro that may evaluate its argument more than once. Java has no preprocessor, so this failure mode is entirely new to these students.

## The Correction

```c
/* before */
#define SQUARE(x) x * x
...
peak = MAX(read_sensor(), peak);

/* after */
#define SQUARE(x) ((x) * (x))
...
int value = read_sensor();
peak = MAX(value, peak);
```

## Instructor Notes

- `gcc -E sensor_report.c` makes bug 1 undeniable; have students find the expanded line for `border_area`.
- Some students fix `SQUARE` as `(x * x)`: the outer parentheses alone do not help here (`(side + 2 * side + 2)` is still wrong). Both the arguments and the body need parentheses.
- For bug 2 some students will "fix" `MAX` itself; there is no portable way to make a macro evaluate its argument once, so the fix belongs at the call site (or `MAX` becomes an inline function, which the README forbids for this exercise). Discuss why the C standard library documents this hazard for macros like `putc`.
- Follow-up: is `BORDER_WIDTH` safe as written? Yes: it is an object-like macro with a single token.
