# Lat Functions

**Course:** CSC240 &nbsp;|&nbsp; **Module 1:** Functional Programming, Scheme Terminology, Data Types, and Lists &nbsp;|&nbsp; **Activity:** debug02
**Language:** Scheme (R5RS, DrRacket)

## Goal

Three predicates in the style of *The Little Schemer*: `atom?` decides whether something is an atom, `lat?` decides whether a list contains only atoms, and `member?` decides whether an atom appears somewhere in a list of atoms.

## Expected Behavior

```scheme
> (atom? 'bacon)
#t
> (atom? '(bacon))
#f
> (lat? '(bacon and eggs))
#t
> (lat? '(bacon (and eggs)))
#f
> (member? 'eggs '(bacon and eggs))
#t
> (member? 'toast '(bacon and eggs))
#f
> (member? 'toast '())
#f
```

## How to Run

Open `lat-functions.scm` in DrRacket. Set **Language → Choose Language → Other Languages → R5RS**. Click **Run**, then type the sample calls in the Interactions window.

Command-line alternative: add lines such as `(display (member? 'toast '(bacon and eggs))) (newline)` at the bottom of the file and run

```bash
plt-r5rs lat-functions.scm
```

or start an interactive session with the file loaded using `plt-r5rs -i lat-functions.scm`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the file; the structure is fine.

## Think About

- Trace `(member? 'toast '(bacon and eggs))` by hand, one recursive call at a time. What is `lat` on the last call, and which `cond` question gets asked first?
- The Little Schemer's First Commandment says to ask a particular question first about any list. Which question is it, and why does it have to come first?
- `lat?` handles the same situation without trouble. What does it do differently?
