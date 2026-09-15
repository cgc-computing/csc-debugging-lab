# Solution: Geometry Helpers

**Course/Module/Activity:** CSC240 · Module 0 Introduction to Scheme · debug01
**Bug type(s):** runtime, paradigm-specific (parentheses mean application)
**Bug count:** 1

## Observed Behavior

Desk-checked (no R5RS interpreter on the authoring machine). The file loads without complaint; `define` does not evaluate procedure bodies. Four of the five sample calls work. `hypotenuse` fails:

```scheme
> (square 5)
25
> (average 6 10)
8
> (average 7 10)
17/2
> (fahrenheit->celsius 212)
100
> (hypotenuse 3 4)
application: not a procedure;
 expected a procedure that can be applied to arguments
  given: 3
> (distance 3 10)
7
```

(DrRacket highlights the sub-expression `(a)` in the definitions window. The exact wording may differ slightly between DrRacket versions; the key phrase is "not a procedure" together with the value `3`.)

## The Bug(s)

In `hypotenuse`, the parameter `a` is wrapped in its own parentheses:

```scheme
(define (hypotenuse a b)
  (sqrt (+ (square (a)) (square b))))
```

## Why the Program Behaved Incorrectly

In Scheme every parenthesized form `(f x ...)` is a procedure application: evaluate `f`, evaluate the arguments, call `f`. The form `(a)` therefore means "call `a` with no arguments". When `(hypotenuse 3 4)` runs, `a` is bound to `3`, so Scheme tries to apply the number `3` as a procedure and stops with the "not a procedure" error. Nothing is wrong with `square`; it is never reached because the argument expression `(a)` fails first.

## The Concept This Illustrates

Prefix notation: parentheses are not grouping symbols in Scheme, they are the syntax of application. Java programmers wrap things in parentheses freely, since `(a)` in Java is just `a`. In Scheme an extra pair of parentheses around a value changes the meaning of the expression. Reading "application: not a procedure … given: 3" as "you asked me to call 3" is the first debugging skill in this language.

## The Correction

```scheme
; before
(sqrt (+ (square (a)) (square b)))

; after
(sqrt (+ (square a) (square b)))
```

## Instructor Notes

- Students sometimes "fix" it by writing `(square (a b))` or `((square a))`, moving the extra parentheses instead of removing them. Each produces a different error (`a` applied to `b`; the number `9` applied to nothing). Reading each new message aloud is good practice.
- Ask students to predict, before running, what `(3)` typed directly into the Interactions window does. Then `((square 3))`. Then `(square)` (arity error: a different message; note the difference).
- `(average 7 10)` returning `17/2` surprises Java students who expect `8` (integer division) or `8.5`. Point out `(exact->inexact 17/2)` or `(average 7.0 10)` and ask which behavior they would want for grades.
- `(sqrt 25)` returns exact `5` in Racket's R5RS mode because 25 is a perfect square; `(sqrt 2)` returns `1.4142135623730951`. Not a bug, but worth a comment if a student notices.
