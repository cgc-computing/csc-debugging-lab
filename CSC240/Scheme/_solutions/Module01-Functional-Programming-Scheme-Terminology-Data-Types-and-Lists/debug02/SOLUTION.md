# Solution: Lat Functions

**Course/Module/Activity:** CSC240 · Module 1 Functional Programming, Scheme Terminology, Data Types, and Lists · debug02
**Bug type(s):** runtime, boundary (empty-list case tested too late)
**Bug count:** 1

## Observed Behavior

Desk-checked (no R5RS interpreter on the authoring machine). `atom?`, `lat?`, and the *successful* `member?` call all behave as expected. Any `member?` call whose answer should be `#f` fails instead:

```scheme
> (member? 'eggs '(bacon and eggs))
#t
> (member? 'toast '(bacon and eggs))
car: contract violation
  expected: pair?
  given: ()
> (member? 'toast '())
car: contract violation
  expected: pair?
  given: ()
```

(DrRacket may print the offending value as `'()`; the message names `car` either way.)

## The Bug(s)

In `member?` the `cond` asks `(eq? (car lat) a)` **before** asking `(null? lat)`:

```scheme
(define (member? a lat)
  (cond ((eq? (car lat) a) #t)
        ((null? lat) #f)
        (else (member? a (cdr lat)))))
```

## Why the Program Behaved Incorrectly

Trace `(member? 'toast '(bacon and eggs))`:

| call | `lat` | first question `(eq? (car lat) 'toast)` |
|---|---|---|
| 1 | `(bacon and eggs)` | `bacon`? no → recurse |
| 2 | `(and eggs)` | `and`? no → recurse |
| 3 | `(eggs)` | `eggs`? no → recurse |
| 4 | `()` | `(car '())` → **error** |

On the fourth call `lat` is the empty list. The first `cond` clause evaluates `(car lat)`, and `car` of the empty list is an error in Scheme, so the `null?` clause on the next line is never reached. The successful case `(member? 'eggs ...)` returns `#t` on call 3, before the list runs out, which is why that one call looks fine.

## The Concept This Illustrates

*The Little Schemer*'s **First Commandment**: always ask `null?` as the first question in expressing any function over a list of atoms. The order of `cond` clauses is the control flow; unlike Java's `if`/`else if`, there is no exception to catch, and `car` on `'()` is a hard error rather than a `null` you can compare later. A predicate that only works when the answer is "yes" has not handled its base case.

## The Correction

```scheme
; before
(cond ((eq? (car lat) a) #t)
      ((null? lat) #f)
      ...)

; after
(cond ((null? lat) #f)
      ((eq? (car lat) a) #t)
      ...)
```

## Instructor Notes

- Ask students to point at the line in `lat?` that plays the same role, and to say why `lat?` never crashes. They wrote (or read) the correct pattern one definition earlier.
- Some students propose wrapping the first clause as `((and (not (null? lat)) (eq? (car lat) a)) #t)`. It works, but ask why the simpler reordering is preferred, and what happens to readability when every clause has to defend itself.
- A wrong "fix" is to change `(car lat)` to `lat`: `(eq? lat a)` compares the whole list with the atom, always `#f`, so `member?` returns `#f` for everything and no longer crashes. Ask them to re-run the `'eggs` case.
- `eq?` on symbols is exactly right in R5RS; if a student asks about numbers, note that `eq?` on numbers is not guaranteed and `eqv?`/`equal?` would be used instead. Module 2 will revisit this.
