# Ancestry

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Writing Recursive List Rules &nbsp;|&nbsp; **Activity:** debug03
**Language:** Prolog (SWI-Prolog)

## Goal

Five `parent/2` facts describe a family. `ancestor(A, D)` should be true when `A` is a parent of `D`, or a parent of an ancestor of `D`, to any depth. `descendant/2` is the same relation with the arguments swapped.

## Expected Behavior

```prolog
?- ancestor(tom, jim).
true ;
false.

?- ancestor(bob, Who).
Who = ann ;
Who = pat ;
Who = jim ;
false.

?- ancestor(Who, jim).
Who = pat ;
Who = tom ;
Who = bob ;
false.

?- ancestor(liz, Who).
false.

?- descendant(jim, tom).
true ;
false.
```

Every query answers **immediately**. A trailing `false.` after you press `;` just means there were no further answers. If a query sits there for several seconds with no output, that is a symptom, not normal behavior: press **Ctrl-C** and then **a** to abort it.

## How to Run

```bash
swipl ancestry.pl
```

Type the sample queries at the `?-` prompt, each ending with a period. Type `halt.` to leave Prolog.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not change the facts; keep `ancestor` as two clauses.

## Think About

- When Prolog tries to prove `ancestor(tom, jim)`, which clause does it try first, and what is the *first goal* inside that clause? What does it have to prove to make progress on that goal?
- Prolog tries clauses top to bottom and goals left to right. For a recursive rule, what has to be true about the first goal in the body so that each call is "smaller" than the last?
- Try swapping the two clauses without changing anything else. Which queries start working, and which one still misbehaves? Why?
