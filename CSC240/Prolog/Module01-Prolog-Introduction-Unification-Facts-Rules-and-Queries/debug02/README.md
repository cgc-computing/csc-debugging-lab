# Campus Store

**Course:** CSC240 &nbsp;|&nbsp; **Module 1:** Prolog Introduction, Unification, Facts, Rules, and Queries &nbsp;|&nbsp; **Activity:** debug02
**Language:** Prolog (SWI-Prolog)

## Goal

Three `price/2` facts give unit prices. `cost(Item, Qty, Total)` computes the total for a quantity of an item, `affordable/3` checks a total against a budget, and `cheaper/2` compares two items' unit prices.

## Expected Behavior

```prolog
?- cost(pen, 3, Total).
Total = 6.

?- cost(backpack, 1, Total).
Total = 40.

?- cost(notebook, 2, 10).
true.

?- affordable(notebook, 4, 25).
true.

?- cheaper(pen, notebook).
true.
```

## How to Run

```bash
swipl campus_store.pl
```

Type the sample queries at the `?-` prompt, each ending with a period. Type `halt.` to leave Prolog.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not change the facts; the fix is in one rule.

## Think About

- Look closely at what Prolog prints for `Total`. Is that a number, or something else? What kind of thing is `2*3` to Prolog if nobody asks it to do arithmetic?
- `affordable(notebook, 4, 25)` works even though `cost` is broken. Which operator in `affordable` is doing work that `cost` never did?
- Prolog has more than one operator that looks like "equals". What does each one actually do with the expression on its right-hand side?
