# Rember

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Writing Recursive List Functions &nbsp;|&nbsp; **Activity:** debug01
**Language:** Scheme (R5RS, DrRacket)

## Goal

`rember` ("remove member") takes an atom and a list of atoms and returns the list with the *first* occurrence of that atom removed; everything else stays in its original order. `firsts` takes a list of lists and returns a list of each inner list's first element.

## Expected Behavior

```scheme
> (rember 'mint '(lamb chops and mint jelly))
(lamb chops and jelly)
> (rember 'cup '(coffee cup tea cup and hick cup))
(coffee tea cup and hick cup)
> (rember 'toast '(bacon and eggs))
(bacon and eggs)
> (rember 'bacon '(bacon and eggs))
(and eggs)
> (firsts '((apple peach pumpkin) (plum pear cherry) (grape raisin pea)))
(apple plum grape)
```

## How to Run

Open `rember.scm` in DrRacket. Set **Language → Choose Language → Other Languages → R5RS**. Click **Run**, then type the sample calls in the Interactions window.

Command-line alternative: add lines such as `(display (rember 'mint '(lamb chops and mint jelly))) (newline)` at the bottom of the file and run

```bash
plt-r5rs rember.scm
```

or start an interactive session with the file loaded using `plt-r5rs -i rember.scm`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the file; the structure is fine.

## Think About

- One of the sample calls gives the right answer and the others do not. What is special about the atom's position in the call that works?
- When `rember` decides that `(car lat)` is *not* the atom to remove, what should happen to that element? Where in the result does it belong?
- Compare the `else` line of `rember` with the `else` line of `firsts`. What does `firsts` do that `rember` does not?
