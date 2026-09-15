# Tournament

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** Advanced Prolog Topics, Cuts, and Database Manipulation &nbsp;|&nbsp; **Activity:** debug01
**Language:** Prolog (SWI-Prolog)

## Goal

`my_max(X, Y, M)` relates two scores to the larger of them, using a cut so that only one answer is produced. `loses_to(Score, Other)` is true when `Other` is strictly higher than `Score`. `best_score(List, Best)` finds the highest score in a non-empty list by leaning on `my_max`.

## Expected Behavior

```prolog
?- my_max(3, 1, M).
M = 3.

?- my_max(1, 3, M).
M = 3.

?- my_max(3, 1, 3).
true.

?- my_max(3, 1, 1).
false.

?- loses_to(1, 3).
true.

?- loses_to(3, 1).
false.

?- best_score([4, 9, 2], B).
B = 9 ;
false.
```

## How to Run

```bash
swipl tournament.pl
```

Type the sample queries at the `?-` prompt, each ending with a period. Type `halt.` to leave Prolog.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep `my_max` as two clauses; you may keep or remove the cut as long as the sample queries behave as shown.

## Think About

- For `my_max(3, 1, 1)`, does the *head* of the first clause even unify with the query? If not, which clause does Prolog fall through to, and what does that clause check?
- The cut is supposed to say "if the first clause applies, do not consider the second". Under what circumstances is the cut never reached, and what does the second clause then assume that is not actually true?
- What is the difference between a cut that only saves work and a cut that changes which answers are possible? Which kind is this one?
