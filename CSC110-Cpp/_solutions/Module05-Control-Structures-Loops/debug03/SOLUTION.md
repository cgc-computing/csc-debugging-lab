# Solution: Quiz Average With a Sentinel

**Course/Module/Activity:** CSC110 · Module 5 Control Structures: Loops · debug03
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

With input `90 80 70 -1`:

```
Scores entered: 4
Average: 59.75
```

The count is one too high and the average is pulled down. Entering `-1` immediately prints
`Scores entered: 1` and `Average: -1` instead of the no-scores message.

## The Bug(s)

`quiz_average.cpp`, `main`: the `do { ... } while (score != -1);` loop adds `score` to `sum` and
increments `count` *before* the sentinel test, so the `-1` that ends input is processed as a
score.

## Why the Program Behaved Incorrectly

A `do-while` runs its body first and tests afterward. On the final pass, `cin >> score` reads
`-1`, then `sum += score` makes `sum = 239` and `count++` makes `count = 4`, and only then does
`score != -1` fail. Average `239 / 4 = 59.75`. The `count > 0` guard never helps because the
sentinel itself is always counted.

## The Concept This Illustrates

Sentinel-controlled loops must check the sentinel *between* reading a value and using it. The
standard shape is "read first value; while (value is not the sentinel) { process; read next }".
Students often reach for `do-while` because "we must read at least once," but that places the
processing on the wrong side of the test.

## The Correction

```cpp
// before
do {
    cin >> score;
    sum += score;
    count++;
} while (score != -1);

// after
cin >> score;
while (score != -1) {
    sum += score;
    count++;
    cin >> score;
}
```

An `if (score != -1) { sum += score; count++; }` inside the original `do-while` also works and is
a reasonable first fix; the priming-read `while` is the cleaner idiom.

## Instructor Notes

- Students who add `count--` and `sum += 1` after the loop have patched the symptom, not the
  logic. Ask what happens if the sentinel changes to `-999`.
- Ask why the "No scores were entered" branch could never run in the original program.
- Follow-up: what would happen if the user typed a letter instead of a number? (`cin` fails and
  `score` becomes 0; the loop spins reading nothing — a good preview of input validation.)
