# Family Facts

**Course:** CSC240 &nbsp;|&nbsp; **Module 0:** Introduction to Prolog &nbsp;|&nbsp; **Activity:** debug01
**Language:** Prolog (SWI-Prolog)

## Goal

A five-fact family tree: `parent(P, C)` says that `P` is a parent of `C`. Tom is the parent of Bob and Liz, Bob is the parent of Ann and Pat, and Pat is the parent of Jim. Queries should say exactly who is whose parent and nothing more.

## Expected Behavior

The file loads with no warnings. At the `?-` prompt:

```prolog
?- parent(tom, bob).
true.

?- parent(X, bob).
X = tom.

?- parent(X, jim).
X = pat.

?- parent(bob, X).
X = ann ;
X = pat.

?- parent(sue, bob).
false.
```

(When Prolog pauses after an answer, press `;` to ask for another one or Enter to stop.)

## How to Run

```bash
swipl family.pl
```

Type the sample queries at the `?-` prompt, each ending with a period. Watch the messages printed while the file loads. Type `halt.` to leave Prolog.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not add or remove facts; the family is correct.

## Think About

- Prolog printed something while loading the file. What is a "singleton variable", and why would a file of plain facts have any variables in it at all?
- In Prolog, what decides whether a name is a constant or a variable? Which names in this file fall on each side of that line?
- Why does `parent(sue, bob)` succeed even though nobody named Sue is in the family? What did Prolog match it against?
