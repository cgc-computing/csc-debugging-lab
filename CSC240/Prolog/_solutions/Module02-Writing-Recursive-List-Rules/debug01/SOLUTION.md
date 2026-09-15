# Solution: List Basics

**Course/Module/Activity:** CSC240 · Module 2 Writing Recursive List Rules · debug01
**Bug type(s):** logic, paradigm-specific (single assignment / `N is N + 1`)
**Bug count:** 1

## Observed Behavior

Desk-checked (no SWI-Prolog on the authoring machine). The file loads cleanly. `my_length` works only for the empty list; every non-empty list makes it fail:

```prolog
?- my_length([], N).
N = 0.

?- my_length([a, b, c], N).
false.

?- my_length([a, b, c], 3).
false.

?- my_last([a, b, c], X).
X = c ;
false.
```

## The Bug(s)

The recursive clause of `my_length` uses the same variable for the tail's length and the whole list's length:

```prolog
my_length([_|T], N) :-
    my_length(T, N),
    N is N + 1.
```

## Why the Program Behaved Incorrectly

Prolog variables are **single-assignment**: once bound, a variable keeps that value for the rest of the proof. Trace `my_length([a], N)`:

1. Clause 2 matches with `T = []` and the head's `N` shared with the query's `N`.
2. `my_length([], N)` matches the base clause, binding `N = 0`.
3. The next goal is `N is N + 1`, which is now `0 is 0 + 1`, i.e. `0 is 1`. That is false.
4. There are no other clauses to try, so the whole query fails.

With longer lists the same failure happens at the innermost step and propagates back as `false.` The base case alone succeeds because it never reaches the `is`.

## The Concept This Illustrates

Recursion in Prolog does not "return" a value that you then increment; it *relates* quantities through distinct variables. The length of the tail and the length of the whole list are two different numbers and need two different names, connected by `is`. `N is N + 1` is a Java reflex (`n++`) that in Prolog reads as "N equals N plus one", which no number satisfies. Recognizing `false.` as "I asked for something impossible" rather than "there is a runtime error" is part of learning the language.

## The Correction

```prolog
% before
my_length([_|T], N) :-
    my_length(T, N),
    N is N + 1.

% after
my_length([_|T], N) :-
    my_length(T, N0),
    N is N0 + 1.
```

## Instructor Notes

- Have students run `?- trace, my_length([a], N).` (then press Enter/`c` to creep). Watching `0 is 0+1` fail is more convincing than any explanation.
- A common wrong fix is swapping the two goals: `N is N + 1, my_length(T, N)`. Now `is` runs with `N` unbound on the right and raises `Arguments are not sufficiently instantiated`. Ask what `is` needs to know before it can run.
- Another attempt: `my_length([_|T], N + 1) :- my_length(T, N).` This "works" in a sense but returns the unevaluated term `0+1+1+1`; connect it back to Module 1's `=` vs `is` lesson.
- The accumulator version (`len(L, N) :- len(L, 0, N).` with `len([], Acc, Acc).`) is a natural follow-up and previews tail recursion.
- The `X = c ; false.` from `my_last` is not a bug: the second clause could still apply to `[c]`, so Prolog leaves a choice point. Ask students why the built-in `last/2` avoids it (it is written to make the one-element case deterministic).
