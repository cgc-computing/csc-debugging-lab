# Solution: Movie Ticket Pricing

**Course/Module/Activity:** CSC101 · Module 5 Conditionals · debug02  
**Bug type(s):** logic (boolean expression / truthiness)  
**Bug count:** 1

## Observed Behavior

```
What day is the show (e.g., Monday)? Friday
How many tickets? 2
Midweek discount applied!
2 ticket(s) for Friday: $16.00
```

The discount is applied on every day, including Friday. The Tuesday run looks correct, which
hides the problem.

## The Bug(s)

`ticket_price.py`, line 12: `if day == "Tuesday" or "Wednesday":`. Python parses this as
`(day == "Tuesday") or ("Wednesday")`. The right operand is the string literal `"Wednesday"`,
which is non-empty and therefore truthy, so the whole condition is always true.

## Why the Program Behaved Incorrectly

`or` combines two *expressions*, each of which is evaluated to a truth value. `day == "Tuesday"`
is a comparison, but `"Wednesday"` by itself is just a string — it is never compared with `day`.
Because any non-empty string counts as true, `False or "Wednesday"` evaluates to `"Wednesday"`,
which `if` treats as true.

## The Concept This Illustrates

Boolean operators join complete conditions, not a condition and a list of alternatives. The
English sentence "day is Tuesday or Wednesday" does not translate word-for-word. Also introduces
truthiness: non-empty strings and non-zero numbers are true in a boolean context.

## The Correction

```python
# before
if day == "Tuesday" or "Wednesday":
# after
if day == "Tuesday" or day == "Wednesday":
```

## Instructor Notes

* Have students evaluate `"Wednesday" or day == "Tuesday"` and `day == "Tuesday" and "Wednesday"`
  in the shell and predict the results first.
* `if day in ("Tuesday", "Wednesday"):` is an acceptable alternative; ask why it works.
* A common partial fix is `if day == "Tuesday" or == "Wednesday":`, which is a SyntaxError — a
  good moment to explain that each side of `or` must be a complete expression.
* Ask what `capitalize()` on line 9 is for and whether `TUESDAY` would still work.
