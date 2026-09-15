# Solution: Campus Store

**Course/Module/Activity:** CSC240 · Module 1 Prolog Introduction, Unification, Facts, Rules, and Queries · debug02
**Bug type(s):** logic, paradigm-specific (`=` unifies, `is` evaluates)
**Bug count:** 1

## Observed Behavior

Desk-checked (no SWI-Prolog on the authoring machine). The file loads cleanly. `cost` returns an unevaluated expression, and checking a known total fails:

```prolog
?- cost(pen, 3, Total).
Total = 2*3.

?- cost(backpack, 1, Total).
Total = 40*1.

?- cost(notebook, 2, 10).
false.

?- affordable(notebook, 4, 25).
true.

?- cheaper(pen, notebook).
true.
```

## The Bug(s)

`cost` uses `=` where arithmetic evaluation is needed:

```prolog
cost(Item, Qty, Total) :-
    price(Item, Price),
    Total = Price * Qty.
```

## Why the Program Behaved Incorrectly

`=` is **unification**, not assignment and not arithmetic. `Total = 2*3` succeeds by binding `Total` to the *term* `2*3` (the structure `*(2, 3)`); no multiplication happens. That is what the toplevel prints. In `cost(notebook, 2, 10)` the goal becomes `10 = 5*2`, and the integer `10` does not unify with the compound term `5*2`, so the query fails. `affordable` happens to work because `=<` *does* evaluate both sides arithmetically before comparing: `5*4 =< 25` is `20 =< 25`. `cheaper` never touches the bug.

## The Concept This Illustrates

Java's `=` both computes the right-hand side and stores it. Prolog splits those jobs: `=` matches two terms structurally, while `is` evaluates the expression on its right and unifies the result with the left. Arithmetic comparison operators (`<`, `=<`, `=:=`, ...) evaluate too, which is why `affordable` masks the problem. Seeing `Total = 2*3` printed is the clearest possible demonstration that Prolog terms are data until something asks for them to be evaluated.

## The Correction

```prolog
% before
Total = Price * Qty.

% after
Total is Price * Qty.
```

## Instructor Notes

- Ask students to type `X = 2*3.` and `X is 2*3.` directly at the prompt, then `6 = 2*3.` and `6 =:= 2*3.` The four results make the whole lesson.
- `is` requires its right-hand side to be fully instantiated. If a student reorders the body to put `Total is Price * Qty` *before* `price(Item, Price)`, they get `Arguments are not sufficiently instantiated`. That is a good moment to discuss why goal order matters for arithmetic even in a "declarative" language.
- Some students "fix" by writing `Total =:= Price * Qty`. That compares and never binds `Total`, so `cost(pen, 3, Total)` raises an instantiation error. Ask what `=:=` needs on both sides.
- Point out that `affordable` working was a trap: a rule can appear correct while depending on a broken helper. Ask how they would have caught it without the README's `cost` queries.
