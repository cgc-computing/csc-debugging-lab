# Solution: Grade Records

**Course/Module/Activity:** CSC240 · Module 3 Higher-Order Functions, Pairs, and Currying · debug03
**Bug type(s):** runtime (wrong accessor on a pair), logic (combining procedure's arguments swapped)
**Bug count:** 2 (related: both confuse *which position holds what*: the halves of a pair, and the two arguments of the combiner)

## Observed Behavior

Desk-checked (no R5RS interpreter on the authoring machine).

```scheme
> (car roster)
(ana . 92)
> (record-name (car roster))
ana
> (record-score (car roster))
car: contract violation
  expected: pair?
  given: 92
> (my-reduce (lambda (x acc) (+ x acc)) 0 '(1 2 3))
6
> (my-reduce (lambda (x acc) (cons x acc)) '() '(a b c))
(((() . c) . b) . a)
> (total-score roster)
cdr: contract violation
  expected: pair?
  given: 0
> (top-score roster)
cdr: contract violation
  expected: pair?
  given: 0
```

The `+` sample hides bug 2 because addition is commutative; the `cons` sample exposes it. The two record procedures fail on `cdr` of `0` because the fold hands the accumulator (`0`) to the combiner in the *element* position.

## The Bug(s)

1. `record-score` treats the pair as a two-element list:
   ```scheme
   (define (record-score r)
     (car (cdr r)))
   ```
2. `my-reduce` passes the accumulated result *first* and the element *second*, the opposite of what the header comment promises and what every caller assumes:
   ```scheme
   (else (f (my-reduce f init (cdr lst)) (car lst)))
   ```

## Why the Program Behaved Incorrectly

Bug 1: `(cons 'ana 92)` is a single pair whose `car` is `ana` and whose `cdr` is `92`. `(cdr r)` is the number `92`, and `(car 92)` is an error. A two-element *list* `(list 'ana 92)` would print as `(ana 92)`, without a dot, and for that structure `(car (cdr r))` would be right. The dot in `(ana . 92)` is the tell.

Bug 2: trace `(total-score roster)` with both bugs present, innermost call first. `(my-reduce f 0 '())` returns `0`. The next call up evaluates `(f 0 '(cy . 78))`, binding `r = 0` and `acc = (cy . 78)` in the combiner `(lambda (r acc) (+ (record-score r) acc))`. `(record-score 0)` is `(car (cdr 0))`, and `(cdr 0)` fails: `cdr: contract violation … given: 0`. `top-score` fails at the same point for the same reason.

The `cons` sample makes bug 2 visible on its own: with `f = (lambda (x acc) (cons x acc))` the buggy fold computes `(f (f (f '() 'c) 'b) 'a)` = `(cons (cons (cons '() 'c) 'b) 'a)`, the dotted structure shown, instead of `(f 'a (f 'b (f 'c '())))` = `(a b c)`.

After each *partial* fix the message changes, which is useful for tracing:

| state | first failing expression in `(total-score roster)` | message |
|---|---|---|
| both bugs | `(cdr 0)` | `cdr: contract violation … given: 0` |
| only bug 1 fixed (`record-score` = `cdr`) | `(cdr 0)` | `cdr: contract violation … given: 0` |
| only bug 2 fixed (argument order) | `(car 78)` from `(car (cdr '(cy . 78)))` | `car: contract violation … given: 78` |
| both fixed | none | `255` |

## The Concept This Illustrates

Pairs and higher-order procedures both come down to **positional contracts**. A pair built with `cons` has exactly two slots, `car` and `cdr`; `(car (cdr p))` assumes a *list* of two elements, which is a different structure (`(a b)` is `(a . (b . ()))`). Likewise a fold's combining procedure has a fixed argument order that the fold and every caller must agree on; R5RS has no built-in `reduce`, so the hand-written one *is* the contract, and its header comment is the documentation. Java students are used to the compiler enforcing parameter types and positions; in Scheme the runtime error is the only check, and it arrives far from the mistake.

## The Correction

```scheme
; before
(define (record-score r)
  (car (cdr r)))
...
(else (f (my-reduce f init (cdr lst)) (car lst)))

; after
(define (record-score r)
  (cdr r))
...
(else (f (car lst) (my-reduce f init (cdr lst))))
```

## Instructor Notes

- Have students predict which error message they will see after each partial fix (table above) before running; it forces them to read the fold from the inside out.
- Students who fix `record-score` by changing `make-record` to `(list name score)` have made a consistent choice, but the README asks for a single pair and `(car roster)` would then print `(ana 92)` rather than `(ana . 92)`. Discuss the trade-off (pairs are the R5RS idiom for two-field records; lists generalize to more fields).
- For bug 2, some students "fix" the callers instead, swapping to `(lambda (acc r) ...)`. That works for these two callers but contradicts the header comment and breaks the README's `cons` sample. Ask which is the single source of truth.
- `(my-reduce cons '() '(a b c))` with the corrected reduce is the identity on lists; that is the standard test for fold direction and argument order and worth stating explicitly.
- Follow-up: implement `my-reduce-left` with an accumulator parameter and compare the order in which elements are combined.
