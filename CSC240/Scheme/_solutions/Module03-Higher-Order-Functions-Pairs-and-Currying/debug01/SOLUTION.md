# Solution: Number Tools

**Course/Module/Activity:** CSC240 · Module 3 Higher-Order Functions, Pairs, and Currying · debug01
**Bug type(s):** logic, conceptual/design (`map` used as a filter)
**Bug count:** 1

## Observed Behavior

Desk-checked (no R5RS interpreter on the authoring machine). `squares` is correct. `evens` returns a list of booleans the same length as its input, and `sum-evens` then fails trying to add them:

```scheme
> (squares '(1 2 3 4))
(1 4 9 16)
> (evens '(1 2 3 4 5 6))
(#f #t #f #t #f #t)
> (evens '(1 3 5))
(#f #f #f)
> (sum-evens '(1 2 3 4 5 6))
+: contract violation
  expected: number?
  given: #f
```

## The Bug(s)

`evens` applies `map` with a predicate:

```scheme
(define (evens lst)
  (map even? lst))
```

## Why the Program Behaved Incorrectly

`map` applies a procedure to *every* element and returns the list of results, one per element. With `even?` the results are `#t`/`#f`, so `(evens '(1 2 3 4 5 6))` is `(#f #t #f #t #f #t)`: a list of six booleans, not a list of the three even numbers. `sum-evens` then evaluates `(apply + '(#f #t #f #t #f #t))`, which is `(+ #f #t #f #t #f #t)`, and `+` rejects the first boolean.

## The Concept This Illustrates

Higher-order procedures each capture one *shape* of computation. `map` is "transform every element, same length out". Selecting a subset is a different shape, "keep or drop each element", conventionally called `filter`, and R5RS does not include it: the student must write it, taking the predicate as a parameter. Students who have only met `map` tend to reach for it whenever a procedure is applied to each element, without asking what the *result* of that application is used for. In Java-stream terms: `map` versus `filter`.

## The Correction

Add a general filtering procedure and use it:

```scheme
; before
(define (evens lst)
  (map even? lst))

; after
(define (keep-if pred lst)
  (cond ((null? lst) '())
        ((pred (car lst)) (cons (car lst) (keep-if pred (cdr lst))))
        (else (keep-if pred (cdr lst)))))

(define (evens lst)
  (keep-if even? lst))
```

## Instructor Notes

- Students may write a non-generic `evens` directly by recursion (`(cond ((null? lst) '()) ((even? (car lst)) (cons ...)) ...)`). That is correct and acceptable; then ask them to pull the predicate out as a parameter so `odds` or `positives` come for free. That step *is* the module's lesson.
- A wrong "fix" is `(map (lambda (x) (if (even? x) x 0)) lst)`, giving `(0 2 0 4 0 6)`. `sum-evens` then returns the right total by accident. Ask what `(evens '(1 3 5))` returns and whether the README's `()` is satisfied.
- Racket-trained students will type `filter` and get an "undefined" error in R5RS mode; explain that the course uses pure R5RS precisely so they learn to build it.
- Follow-up: rewrite `sum-evens` with a hand-written `reduce`/`fold` instead of `apply`, previewing debug03.
- Note `apply`'s role here for students who have not seen it: `(apply + '(2 4 6))` is `(+ 2 4 6)`.
