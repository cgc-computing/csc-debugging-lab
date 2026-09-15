# Solution: Occur Star

**Course/Module/Activity:** CSC240 · Module 2 Writing Recursive List Functions · debug03
**Bug type(s):** runtime (wrong base-case type), logic (nested `car` not searched)
**Bug count:** 2 (related: both are the places where a `*`-function differs from its flat counterpart)

## Observed Behavior

Desk-checked (no R5RS interpreter on the authoring machine). `occur` is correct. `occur*` either errors or returns the empty list, depending on whether a top-level match exists:

```scheme
> (occur* 'banana '())
()
> (occur* 'banana '(banana))
+: contract violation
  expected: number?
  given: ()
> (occur* 'banana '((banana) (split ((((banana ice))) (cream (banana)) sherbet)) (banana) (bread) (banana brandy)))
()
> (occur* 'kiwi '((banana) (split)))
()
```

After the base case is repaired (bug 1) the errors disappear but the big sample returns `0` instead of `5`; nothing nested is ever counted.

## The Bug(s)

1. The base case returns a list where a number is required:
   ```scheme
   (cond ((null? l) '())
   ```
2. The third clause, for a `car` that is itself a list, skips that sublist entirely instead of counting inside it:
   ```scheme
   (else (occur* a (cdr l)))
   ```

## Why the Program Behaved Incorrectly

Bug 1: `(occur* 'banana '(banana))` takes the `atom?` branch, finds a match, and evaluates `(+ 1 (occur* 'banana '()))`. The inner call returns `'()`, and `+` refuses a non-number. When no top-level atom matches, no `+` is ever evaluated and the `'()` from the base case is simply passed back as the "count".

Bug 2: with `0` as the base case, trace the big sample. Every top-level element is a *list* (`(banana)`, `(split ...)`, ...), so every call takes the `else` clause, which only looks at `(cdr l)`. The five `banana`s all live inside the `car`s that were skipped. The count is `0`. The `(occur* 'banana '(banana))` case works only because that `banana` is a top-level atom.

## The Concept This Illustrates

A `*`-function (Little Schemer chapter 6) asks **three** questions: is the list empty, is the `car` an atom, or is the `car` a list. In the third case the function must recur on **both** the `car` and the `cdr` and **combine** the two results, here with `+`. The base case must return the identity of that combining operation: `0` for counting/summing, `'()` for functions that build lists. Copying the `'()` base case from a list-building function into a counting function, and copying the two-question shape of a flat function into a `*`-function, are the two most common mistakes when students first write over nested lists.

## The Correction

```scheme
; before
(cond ((null? l) '())
      ...
      (else (occur* a (cdr l))))

; after
(cond ((null? l) 0)
      ...
      (else (+ (occur* a (car l))
               (occur* a (cdr l)))))
```

## Instructor Notes

- Whichever bug students fix first, the other remains visible: fixing the base case gives `0` for the big sample; fixing the recursion first still yields the `+` error (now from deeper inside). Encourage them to trace the small cases `'()`, `'(banana)`, `'((banana))` in that order.
- A tempting wrong fix for bug 2 is `(else (occur* a (car l)))`, which searches the sublist but drops the rest of the list. On the big sample that gives `1`. Ask what happened to the other four.
- Some students write `(cons ...)` or `(append ...)` in the third clause out of habit; remind them that `occur*` returns a number, so the combining operation is `+`.
- Compare with `rember*` or `leftmost` if students have seen them: same three questions, different combining operations and base values.
- Ask why `atom?` has to be defined by hand: R5RS does not provide it, and the definition (`not pair?` and `not null?`) is worth reading closely: is `'()` an atom?
