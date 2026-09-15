# Solution: Ancestry

**Course/Module/Activity:** CSC240 · Module 2 Writing Recursive List Rules · debug03
**Bug type(s):** runtime (non-termination), paradigm-specific (left recursion and clause order)
**Bug count:** 1

## Observed Behavior

Desk-checked (no SWI-Prolog on the authoring machine). The file loads cleanly. **Every** `ancestor` query, including ones that should fail, hangs for a few seconds and then aborts with a stack overflow:

```prolog
?- ancestor(tom, jim).
ERROR: Stack limit (1.0Gb) exceeded
ERROR:   Stack sizes: local: 1.0Gb, global: 28Kb, trail: 1Kb
ERROR:   Stack depth: 12,200,621, last-call: 0%, Choice points: 12,200,603
ERROR:   Possible non-terminating recursion:
ERROR:     [12,200,621] user:ancestor(tom, _G1234)
ERROR:     [12,200,620] user:ancestor(tom, _G1240)
ERROR: ...
```

(Exact numbers vary with machine and SWI version; the repeated `ancestor(tom, _)` frames are the point.) `ancestor(liz, Who)` behaves identically instead of answering `false.`, and `descendant(jim, tom)` fails the same way because it calls `ancestor`.

## The Bug(s)

The recursive clause is **left-recursive** and is listed **first**:

```prolog
ancestor(A, D) :-
    ancestor(A, X),
    parent(X, D).
ancestor(A, D) :-
    parent(A, D).
```

## Why the Program Behaved Incorrectly

To prove `ancestor(tom, jim)` Prolog tries the first clause. Its first goal is `ancestor(tom, X)` with `X` fresh. To prove *that*, Prolog again tries the first clause, whose first goal is `ancestor(tom, X')`... Nothing has been consumed between one call and the next: no `parent` fact has been looked up, no variable has been narrowed. The recursion never reaches the `parent(X, D)` goal or the second clause, so the local stack grows until SWI-Prolog stops it. The logical *reading* of the rule ("A is an ancestor of D if A is an ancestor of someone who is a parent of D") is perfectly true; the *procedural* reading, top-to-bottom and left-to-right, never terminates.

## The Concept This Illustrates

Prolog's search is depth-first, clauses in order, goals in order. A recursive rule terminates only if something in the body **before** the recursive call makes progress (here, consulting a `parent` fact, which binds `X` to a concrete person and moves one generation down). Putting the base clause first matters too, but is not sufficient on its own: with the clauses merely swapped, `ancestor(liz, Who)` still loops, because after `parent(liz, _)` fails the recursive clause is tried and its first goal is again `ancestor(liz, X)`. The fix is to make the recursion **right-recursive** (`parent` first, then `ancestor` on the smaller problem) and to keep the base case first so answers appear in a sensible order.

## The Correction

```prolog
% before
ancestor(A, D) :-
    ancestor(A, X),
    parent(X, D).
ancestor(A, D) :-
    parent(A, D).

% after
ancestor(A, D) :-
    parent(A, D).
ancestor(A, D) :-
    parent(A, X),
    ancestor(X, D).
```

## Instructor Notes

- The README's third Think About question is the core of the session: ask students to *only* swap the clauses and run all five queries. `ancestor(tom, jim)` and `ancestor(bob, Who)` now work, but `ancestor(liz, Who)` (and pressing `;` after the last answer of any query) still overflows. That experiment separates "clause order" from "left recursion" in their minds.
- Answer order in the corrected version for `ancestor(Who, jim)` is `pat`, `tom`, `bob`: `pat` from the base clause, then the recursive clause walks the `parent` facts in file order (`tom`'s children first). Students sometimes expect `bob` before `tom`; tracing why is good practice.
- The trailing `false.` after the last answer is normal (the recursive clause is tried and fails). If a student wants `ancestor(tom, jim)` to print a plain `true.`, that is a conversation about determinism and cuts for Module 3, not a bug here.
- Some students "fix" the hang by adding a cut to the first clause. That stops the loop but also stops `ancestor(bob, Who)` from producing more than one answer. Ask them to run the sample set.
- `?- trace, ancestor(tom, jim).` on the *buggy* file shows the same call repeated; abort with `a`. Seeing it once is worth more than the explanation.
