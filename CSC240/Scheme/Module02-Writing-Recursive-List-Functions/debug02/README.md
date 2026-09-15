# List Builders

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Writing Recursive List Functions &nbsp;|&nbsp; **Activity:** debug02
**Language:** Scheme (R5RS, DrRacket)

## Goal

Three list-building procedures over lists of atoms. `add-to-end` returns the list with an atom added at the back. `insertR` inserts a new atom immediately to the right of the first occurrence of an old one. `my-reverse` returns the list with its elements in the opposite order.

## Expected Behavior

```scheme
> (add-to-end 'd '(a b c))
(a b c d)
> (insertR 'topping 'fudge '(ice cream with fudge for dessert))
(ice cream with fudge topping for dessert)
> (my-reverse '(a b c))
(c b a)
> (my-reverse '(one))
(one)
> (my-reverse '())
()
```

## How to Run

Open `list-builders.scm` in DrRacket. Set **Language → Choose Language → Other Languages → R5RS**. Click **Run**, then type the sample calls in the Interactions window.

Command-line alternative: add lines such as `(display (my-reverse '(a b c))) (newline)` at the bottom of the file and run

```bash
plt-r5rs list-builders.scm
```

or start an interactive session with the file loaded using `plt-r5rs -i list-builders.scm`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the file; the structure is fine, and you may use the other procedures in the file as helpers.

## Think About

- The output contains dots. What does a dot mean when Scheme prints a structure, and what does it tell you about how the structure was built?
- In `my-reverse`, what *kind* of value does the recursive call return, and what kind of value is `(car lat)`? Which one is `cons` treating as "the rest of the list"?
- Once you have reversed the `cdr`, where does the original first element need to go, and which procedure in this file already knows how to put something there?
