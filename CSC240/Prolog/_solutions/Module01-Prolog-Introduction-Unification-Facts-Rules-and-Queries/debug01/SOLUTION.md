# Solution: Family Rules

**Course/Module/Activity:** CSC240 · Module 1 Prolog Introduction, Unification, Facts, Rules, and Queries · debug01
**Bug type(s):** logic, paradigm-specific (unification does not imply distinctness)
**Bug count:** 1

## Observed Behavior

Desk-checked (no SWI-Prolog on the authoring machine). The file loads cleanly. Everyone with a parent is reported as their own sibling:

```prolog
?- sibling(ann, Who).
Who = ann ;
Who = pat.

?- sibling(bob, liz).
true.

?- sibling(jim, Who).
Who = jim.

?- sister(liz, bob).
true.

?- sister(Who, ann).
Who = ann ;
Who = pat ;
false.

?- grandparent(tom, Who).
Who = ann ;
Who = pat ;
false.
```

(The trailing `false.` after `;` on the last two queries is normal in both the buggy and the corrected file: `parent(P, Who)` and `parent(tom, Y)` still have untried facts when the last answer is found.)

## The Bug(s)

The `sibling` rule never requires the two people to be different:

```prolog
sibling(X, Y) :-
    parent(P, X),
    parent(P, Y).
```

## Why the Program Behaved Incorrectly

For `sibling(ann, Who)`, Prolog first proves `parent(P, ann)`, binding `P = bob`. It then looks for `parent(bob, Who)` and finds two facts in order: `parent(bob, ann)` and `parent(bob, pat)`. Nothing in the rule rules out `Who = ann`, so the first answer is Ann herself. For Jim, whose only sibling candidate is himself, the rule returns `Who = jim` instead of failing. `sister` inherits the same problem because it is defined through `sibling`.

## The Concept This Illustrates

Unification finds *any* consistent assignment; it does not assume that two different variable names refer to two different things. A Java programmer writing this rule imagines iterating over "the other children", but Prolog has no notion of "other" unless the rule states it. Inequality must be asserted explicitly with `\=` (which succeeds when its arguments *cannot* be unified). Note the placement: `X \= Y` must come after both variables are bound, otherwise it compares two unbound variables, which *can* unify, and fails.

## The Correction

```prolog
% before
sibling(X, Y) :-
    parent(P, X),
    parent(P, Y).

% after
sibling(X, Y) :-
    parent(P, X),
    parent(P, Y),
    X \= Y.
```

## Instructor Notes

- Students who put `X \= Y` *first* in the body will see `sibling(ann, Who)` fail outright. That is the best five minutes of this activity: ask what `X` and `Y` are bound to when `\=` runs in that position, and what `\=` means for two unbound variables.
- Some students write `X \== Y` (not identical) or `dif(X, Y)`. Both work here; `dif/2` is the more general (it delays the check until the variables are bound) but is beyond Module 1. Accept and mention.
- Ask why `sibling(bob, liz)` was `true.` even before the fix (the bug only adds wrong answers; it never removes right ones).
- Follow-up question: if both parents were listed for each child (a `parent(pam, bob).` fact, say), `sibling(bob, liz)` would succeed twice. Ask how they would tell that from the output and whether it is a bug.
