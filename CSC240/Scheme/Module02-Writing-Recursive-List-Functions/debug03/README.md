# Occur Star

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Writing Recursive List Functions &nbsp;|&nbsp; **Activity:** debug03
**Language:** Scheme (R5RS, DrRacket)

## Goal

`occur` counts how many times an atom appears in a flat list of atoms. `occur*` does the same for a list that may contain lists inside lists to any depth: every occurrence of the atom, however deeply nested, is counted.

## Expected Behavior

```scheme
> (occur 'banana '(banana split banana))
2
> (occur 'kiwi '(banana split))
0
> (occur* 'banana '())
0
> (occur* 'banana '(banana))
1
> (occur* 'banana '((banana) (split ((((banana ice))) (cream (banana)) sherbet)) (banana) (bread) (banana brandy)))
5
> (occur* 'kiwi '((banana) (split)))
0
```

## How to Run

Open `occur-star.scm` in DrRacket. Set **Language → Choose Language → Other Languages → R5RS**. Click **Run**, then type the sample calls in the Interactions window.

Command-line alternative: add lines such as `(display (occur* 'banana '((banana) (split)))) (newline)` at the bottom of the file and run

```bash
plt-r5rs occur-star.scm
```

or start an interactive session with the file loaded using `plt-r5rs -i occur-star.scm`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the file; the structure is fine.

## Think About

- What *type* of value should `occur*` return in every case, including the empty list? What type does `+` need each of its arguments to be?
- A `*`-function asks three questions instead of two. What is the third situation, and what should `occur*` do with *both* halves of the list in that situation?
- After you fix one problem the answers change but may still be wrong. Trace the big sample by hand: which occurrences of `banana` are being counted, and which are being skipped?
