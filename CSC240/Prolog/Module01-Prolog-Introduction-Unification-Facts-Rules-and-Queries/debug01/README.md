# Family Rules

**Course:** CSC240 &nbsp;|&nbsp; **Module 1:** Prolog Introduction, Unification, Facts, Rules, and Queries &nbsp;|&nbsp; **Activity:** debug01
**Language:** Prolog (SWI-Prolog)

## Goal

The knowledge base holds `parent/2`, `male/1`, and `female/1` facts and defines `father`, `mother`, `grandparent`, `sibling`, and `sister` as rules. Two people are siblings when they share a parent; a sister is a female sibling.

## Expected Behavior

```prolog
?- sibling(ann, Who).
Who = pat.

?- sibling(bob, liz).
true.

?- sibling(jim, Who).
false.

?- sister(liz, bob).
true.

?- sister(Who, ann).
Who = pat ;
false.

?- grandparent(tom, Who).
Who = ann ;
Who = pat ;
false.
```

(If Prolog pauses after an answer, press `;` to ask for another or Enter to stop. A final `false.` after the last answer only means there were no more.)

## How to Run

```bash
swipl family_rules.pl
```

Type the sample queries at the `?-` prompt, each ending with a period. Type `halt.` to leave Prolog.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not change the facts; the fix is in one rule.

## Think About

- Read the `sibling` rule aloud as an English sentence: "X is a sibling of Y if ...". Is there a person for whom that sentence is true but who should *not* count as a sibling?
- When Prolog proves `sibling(ann, Who)`, what values can `P` take, and for each `P`, what values can `Who` take? List them all.
- Unification will happily make two different variables stand for the same person. What must a rule say if it needs them to be different?
