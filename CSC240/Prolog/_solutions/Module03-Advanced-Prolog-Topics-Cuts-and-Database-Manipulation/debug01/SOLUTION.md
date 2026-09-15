# Solution: Tournament

**Course/Module/Activity:** CSC240 · Module 3 Advanced Prolog Topics, Cuts, and Database Manipulation · debug01
**Bug type(s):** logic, paradigm-specific (red cut; second clause relies on the first having been tried)
**Bug count:** 1

## Observed Behavior

Desk-checked (no SWI-Prolog on the authoring machine). The file loads cleanly. Queries that *compute* the maximum are right; queries that *check* a wrong maximum wrongly succeed:

```prolog
?- my_max(3, 1, M).
M = 3.

?- my_max(1, 3, M).
M = 3.

?- my_max(3, 1, 3).
true.

?- my_max(3, 1, 1).
true.

?- loses_to(1, 3).
true.

?- loses_to(3, 1).
true.

?- best_score([4, 9, 2], B).
B = 9 ;
false.
```

`my_max(3, 1, 1)` and `loses_to(3, 1)` should be `false.`

## The Bug(s)

The first clause does the output unification **in the head**, so when the third argument is already bound to the wrong value the head fails to unify and the cut is never executed:

```prolog
my_max(X, Y, X) :-
    X >= Y,
    !.
my_max(_, Y, Y).
```

## Why the Program Behaved Incorrectly

Trace `my_max(3, 1, 1)`:

1. Clause 1 head `my_max(X, Y, X)`: `X = 3`, `Y = 1`, then the third argument requires `X = 1`. `3` and `1` do not unify, so the **head fails**. The body, including the cut, is never reached.
2. Clause 2 head `my_max(_, Y, Y)`: `Y = 1`, third argument `1`. Unifies. Clause 2 has no body, so the query succeeds.

The second clause was written assuming "we only get here when `X >= Y` is false", but that assumption is enforced by the cut, and the cut only runs when the *body* of clause 1 is entered. When the third argument is supplied, clause 1 can be skipped for a reason (head mismatch) that has nothing to do with the comparison. `loses_to(3, 1)` inherits the bug because it calls `my_max` in checking mode.

## The Concept This Illustrates

A **red cut** is one that changes the meaning of the program: the second clause is *incorrect on its own* (`my_max(_, Y, Y)` says "the max of anything and Y is Y") and is only right when the first clause has been tried and rejected by the comparison. Such a program is correct in one calling mode (third argument unbound) and wrong in another (third argument bound). The safe pattern is to make every clause true by itself (a **green cut**, `my_max(X, Y, Y) :- X < Y.`), or, if you keep the cut, to do the comparison and the cut *before* committing to the output value, so the cut is guaranteed to run whenever the comparison holds.

## The Correction

```prolog
% before
my_max(X, Y, X) :-
    X >= Y,
    !.
my_max(_, Y, Y).

% after
my_max(X, Y, M) :-
    X >= Y,
    !,
    M = X.
my_max(_, Y, Y).
```

Now `my_max(3, 1, 1)` enters clause 1 (the head no longer constrains `M`), passes `3 >= 1`, executes the cut, and then fails at `1 = 3`; the cut has already discarded clause 2, so the query is `false.` The pure alternative is equally acceptable:

```prolog
my_max(X, Y, X) :- X >= Y.
my_max(X, Y, Y) :- X < Y.
```

## Instructor Notes

- Ask students to run `my_max(3, 1, M)` with *both* the buggy and the fixed version and explain why the computing mode never showed the problem. Then ask which mode `best_score` uses (computing), which is why it, too, looked fine.
- Some students fix it by adding the comparison to the second clause *and* keeping the cut in the first. That is the green-cut version; discuss what the cut now buys (avoiding a redundant `X < Y` test) and whether it is worth having.
- A wrong "fix" is moving the cut before the comparison (`my_max(X, Y, X) :- !, X >= Y.`). Now `my_max(1, 3, M)` commits to clause 1, fails the comparison, and the whole query fails. Ask what the cut promised too early.
- The `B = 9 ; false.` from `best_score` is normal: the `[S]` clause matches `[2]`, and the `[H|T]` clause is still a candidate for `[2]` until it fails on `best_score([], _)`. Not a bug; optionally ask how to make it deterministic.
- Terminology to leave them with: "red cut" (removes solutions that should exist or admits ones that should not) versus "green cut" (only prunes redundant work).
