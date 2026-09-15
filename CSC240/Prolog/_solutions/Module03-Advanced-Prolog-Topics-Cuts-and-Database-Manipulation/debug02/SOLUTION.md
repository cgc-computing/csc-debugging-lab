# Solution: Enrollment

**Course/Module/Activity:** CSC240 · Module 3 Advanced Prolog Topics, Cuts, and Database Manipulation · debug02
**Bug type(s):** logic, paradigm-specific (negation as failure with an unbound variable)
**Bug count:** 1

## Observed Behavior

Desk-checked (no SWI-Prolog on the authoring machine). The file loads cleanly. `unenrolled` works as a check but cannot generate:

```prolog
?- unenrolled(dana).
true.

?- unenrolled(ana).
false.

?- unenrolled(Who).
false.

?- takes_with(ana, Who, csc240).
Who = ben.
```

## The Bug(s)

`unenrolled` negates a goal **before** its variable is bound:

```prolog
unenrolled(S) :-
    \+ enrolled(S, _),
    student(S).
```

## Why the Program Behaved Incorrectly

`\+ G` succeeds only if `G` has no proof. With `S` unbound, the goal inside is `enrolled(S, _)`, i.e. "is *anyone* enrolled in *anything*?" Since `enrolled(ana, csc240)` exists, that goal succeeds, so `\+` fails, and `unenrolled(Who)` fails before `student(S)` is ever consulted. When `S` is already bound (`unenrolled(dana)`), the inner goal is `enrolled(dana, _)`, which has no proof, so `\+` succeeds and the rule continues; that is why the checking queries work.

## The Concept This Illustrates

Prolog's negation is **negation as failure**, and it never binds variables: `\+` cannot say "here are the S for which `enrolled(S, _)` fails". A negated goal is only meaningful once every variable in it that matters has been bound by an earlier goal. So the rule must first *generate* candidates (`student(S)`) and then *filter* them (`\+ enrolled(S, _)`). Conjunction in Prolog is not commutative once `\+`, `is`, or comparison operators are involved; a Java programmer expects `a && b` and `b && a` to agree, and here they do not.

## The Correction

```prolog
% before
unenrolled(S) :-
    \+ enrolled(S, _),
    student(S).

% after
unenrolled(S) :-
    student(S),
    \+ enrolled(S, _).
```

## Instructor Notes

- Ask students to type `?- \+ enrolled(S, _).` and `?- \+ enrolled(dana, _).` directly. The pair makes the point without any rule in the way.
- Some students try to "fix" it by writing `\+ enrolled(S, _), S = dana` or similar, hard-coding the answer. Ask what happens when a fifth student is added.
- Others reach for `forall/2` or `findall/3` to compute the complement. Those work but are heavier; the reordering is the idiomatic fix and the lesson is about goal order.
- Point out that `takes_with` already follows the generate-then-test pattern (`enrolled` goals first, then `\=`) and was never broken. Ask students to state the rule of thumb in their own words: bind first, negate or compare after.
- If the `Who = ben` answer offers a `;`, pressing it yields `false.`; that is Prolog checking the remaining `enrolled` facts and is not a bug.
