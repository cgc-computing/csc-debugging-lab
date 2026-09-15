# Enrollment

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** Advanced Prolog Topics, Cuts, and Database Manipulation &nbsp;|&nbsp; **Activity:** debug02
**Language:** Prolog (SWI-Prolog)

## Goal

Four students and three enrollments. `unenrolled(S)` should be true for each student who is not enrolled in any course, and it should be able to *find* such students, not just check a name you already have. `takes_with(S1, S2, Course)` finds classmates.

## Expected Behavior

```prolog
?- unenrolled(dana).
true.

?- unenrolled(ana).
false.

?- unenrolled(Who).
Who = dana.

?- takes_with(ana, Who, csc240).
Who = ben.
```

(If Prolog pauses after an answer, press `;` to ask for another or Enter to stop.)

## How to Run

```bash
swipl enrollment.pl
```

Type the sample queries at the `?-` prompt, each ending with a period. Type `halt.` to leave Prolog.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not change the facts; the fix is in one rule.

## Think About

- `unenrolled(dana)` works and `unenrolled(Who)` does not. What is different about `S` at the moment the first goal of the rule runs?
- `\+ Goal` means "Goal cannot be proved". If `Goal` contains an unbound variable, what question is Prolog actually being asked? Is there *any* enrollment fact at all?
- Negation in Prolog is often described as "negation as failure". Why does that make the order of goals matter more than it would for an ordinary `AND`?
