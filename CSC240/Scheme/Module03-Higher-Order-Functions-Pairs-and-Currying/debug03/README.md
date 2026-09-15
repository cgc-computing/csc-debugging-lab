# Grade Records

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** Higher-Order Functions, Pairs, and Currying &nbsp;|&nbsp; **Activity:** debug03
**Language:** Scheme (R5RS, DrRacket)

## Goal

A grade record is a pair built with `cons`: a student's name and a score. `record-name` and `record-score` pull the two halves back out. `my-reduce` is a hand-written right fold whose combining procedure receives *the current element* and *the result so far*, in that order. `total-score` and `top-score` use it over `roster`, a list of three records.

## Expected Behavior

```scheme
> (car roster)
(ana . 92)
> (record-name (car roster))
ana
> (record-score (car roster))
92
> (my-reduce (lambda (x acc) (+ x acc)) 0 '(1 2 3))
6
> (my-reduce (lambda (x acc) (cons x acc)) '() '(a b c))
(a b c)
> (total-score roster)
255
> (top-score roster)
92
```

## How to Run

Open `grade-records.scm` in DrRacket. Set **Language → Choose Language → Other Languages → R5RS**. Click **Run**, then type the sample calls in the Interactions window.

Command-line alternative: add lines such as `(display (total-score roster)) (newline)` at the bottom of the file and run

```bash
plt-r5rs grade-records.scm
```

or start an interactive session with the file loaded using `plt-r5rs -i grade-records.scm`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the record representation as a single `cons` pair and keep the documented argument order of `my-reduce`'s combining procedure.

## Think About

- `(cons 'ana 92)` prints as `(ana . 92)`. Draw the pair. What is its `car`? What is its `cdr`? Is the `cdr` a list?
- The header comment says what the combining procedure receives first and second. In the recursive case of `my-reduce`, which expression is passed first, and which second? Try it on the tiny examples with `+` and `cons`.
- Three of the sample calls give errors that mention `car` or `cdr`. In each one, what value did Scheme actually have in hand when it tried to take it apart?
