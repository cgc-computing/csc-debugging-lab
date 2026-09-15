# Solution: Family Facts

**Course/Module/Activity:** CSC240 · Module 0 Introduction to Prolog · debug01
**Bug type(s):** paradigm-specific (atoms vs variables), logic
**Bug count:** 1 misconception, appearing twice

## Observed Behavior

Desk-checked (no SWI-Prolog on the authoring machine). Loading prints two singleton warnings:

```
Warning: /path/to/family.pl:5:
Warning:    Singleton variables: [Tom]
Warning: /path/to/family.pl:9:
Warning:    Singleton variables: [Pat]
```

The queries then over-succeed:

```prolog
?- parent(tom, bob).
true.

?- parent(X, bob).
true.

?- parent(X, jim).
true.

?- parent(bob, X).
X = bob ;
X = ann ;
X = pat ;
X = jim.

?- parent(sue, bob).
true.
```

`parent(X, bob)` and `parent(X, jim)` answer `true.` without binding `X`; `parent(sue, bob)` succeeds although Sue is not in the tree; and `parent(bob, X)` gains two extra answers, `bob` and `jim`, because the variable in each bad fact unifies with `bob` in the *first* argument position too.

## The Bug(s)

Two facts capitalize a name:

```prolog
parent(Tom, bob).
parent(Pat, jim).
```

## Why the Program Behaved Incorrectly

In Prolog an identifier that begins with an **uppercase letter (or underscore) is a variable**; one that begins with a lowercase letter is an atom (a constant). `parent(Tom, bob).` therefore does not say "tom is a parent of bob"; it says "*anything* is a parent of bob", because the variable `Tom` unifies with any term. That is why `parent(sue, bob)` is `true.` and why `parent(X, bob)` succeeds without binding `X` (two unbound variables unify with each other, and SWI prints `true.` rather than an anonymous binding). The same happens for Jim. SWI-Prolog warns about `Tom` and `Pat` because a variable that appears only once in a clause is almost always a typo; that warning is the whole clue.

## The Concept This Illustrates

The most basic piece of Prolog syntax, and the one Java programmers get wrong first: capitalization is not style, it is *meaning*. `Tom` is a variable; `tom` is a constant. Every proper noun in a knowledge base must be lowercase (or quoted, `'Tom'`). Recognizing the singleton-variable warning as "you probably meant a constant" is a habit worth forming on day one.

## The Correction

```prolog
% before
parent(Tom, bob).
parent(Pat, jim).

% after
parent(tom, bob).
parent(pat, jim).
```

## Instructor Notes

- Ask students to query `parent(anything_at_all, bob).` before the fix and explain the `true.` The moment they see that a variable in a *fact* means "for all", the lesson lands.
- Some students silence the warning by renaming to `_Tom` (a named singleton). The warning goes away and the bug stays. Ask what the underscore changed and what it did not.
- Quoting (`'Tom'`) is a legitimate alternative when capitalized data is genuinely wanted; note that `'Tom'` and `tom` are then *different* atoms, so every query must quote too.
- `parent(bob, X)` is the richest symptom: Bob comes out as his own parent (clause 1, `Tom = bob`, `X = bob`) and as Jim's parent (clause 5, `Pat = bob`). Ask students to name which clause produced each of the four answers; it shows that a variable in a fact unifies in *every* query that touches that argument position, not only the one the author was thinking about.
- If time allows, show that `?- parent(X, Y).` before the fix lists `X` unbound for the two bad facts, another visible symptom.
