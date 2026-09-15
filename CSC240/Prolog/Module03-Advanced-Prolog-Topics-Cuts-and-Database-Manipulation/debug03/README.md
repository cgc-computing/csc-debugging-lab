# Sales Log

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** Advanced Prolog Topics, Cuts, and Database Manipulation &nbsp;|&nbsp; **Activity:** debug03
**Language:** Prolog (SWI-Prolog)

## Goal

A tiny point-of-sale tally kept in Prolog's dynamic database. `sold(Item, N)` facts record how many of each item have been sold today. `sell/1` bumps an item's tally, `sales/2` reads one tally, `total_sold/1` adds all tallies together, and `reset_sales/0` wipes the tallies and starts both items at zero.

## Expected Behavior

Run these queries **in this order** in one session:

```prolog
?- sell(apples), sell(apples), sell(pears).
true.

?- sales(apples, N).
N = 2.

?- sales(pears, N).
N = 1.

?- total_sold(T).
T = 3.

?- reset_sales.
true.

?- sales(pears, N).
N = 0.

?- total_sold(T).
T = 0.
```

Each query has exactly one answer; Prolog should not offer a `;` prompt after any of them.

## How to Run

```bash
swipl sales_log.pl
```

Type the sample queries at the `?-` prompt in the order shown, each ending with a period. Type `halt.` to leave Prolog. To start over, quit and reload the file (the database lives only in memory).

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the tallies as `sold/2` facts in the dynamic database.

## Think About

- After the three sales, use `?- listing(sold).` to look at the facts. Do the same right after `reset_sales`. How many `sold` facts are there each time, and which ones?
- `retract/1` removes a clause. How many? What would it take to remove *every* matching clause?
- In `total_sold`, the goal inside the collecting predicate mentions a variable (`_`) that is not in the template. Look up how `bagof/3` treats variables that appear in the goal but not in the template. How does `findall/3` treat them?
- Which of the two collecting predicates would still give a sensible total if there were no `sold` facts at all?
