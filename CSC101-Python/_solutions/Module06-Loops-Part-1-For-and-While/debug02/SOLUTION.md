# Solution: Savings Goal Countdown

**Course/Module/Activity:** CSC101 · Module 6 Loops Part 1: For and While · debug02  
**Bug type(s):** runtime (infinite loop) / logic  
**Bug count:** 1

## Observed Behavior

After the third input is entered, the program prints nothing and never ends. It must be stopped
with `Ctrl+C` (which shows a `KeyboardInterrupt` traceback pointing into the `while` loop).

## The Bug(s)

`savings_goal.py`, line 10: `balance + deposit` is an expression statement. It computes a new
number and immediately discards it; `balance` is never updated. The loop condition
`balance < goal` therefore never changes.

## Why the Program Behaved Incorrectly

Each trip through the loop increments `months` but leaves `balance` at 100.0. Since 100 < 1000
stays true forever, the `while` loop never exits. Nothing is printed inside the loop, so the
program appears frozen.

## The Concept This Illustrates

A `while` loop's body must make progress toward making the condition false. Also the distinction
between *evaluating* an expression and *assigning* its result: `balance + deposit` on its own is
legal Python that does nothing useful.

## The Correction

```python
# before
    balance + deposit
# after
    balance = balance + deposit      # or: balance += deposit
```

## Instructor Notes

* Ask students to add a temporary `print(balance, months)` inside the loop, run for two seconds,
  and stop. Seeing `100.0 1`, `100.0 2`, `100.0 3`... makes the diagnosis concrete.
* Some students propose changing the condition to `months < 6`; that hard-codes the answer. Ask
  what happens for a different goal.
* Follow-up: what does the corrected program do if `deposit` is 0 or negative? How could you
  guard against that?
