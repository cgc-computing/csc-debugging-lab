# Solution: List Builders

**Course/Module/Activity:** CSC240 · Module 2 Writing Recursive List Functions · debug02
**Bug type(s):** logic, paradigm-specific (`cons` arguments reversed; element where a list is required)
**Bug count:** 1

## Observed Behavior

Desk-checked (no R5RS interpreter on the authoring machine). `add-to-end` and `insertR` are correct. `my-reverse` returns nested dotted pairs instead of a list:

```scheme
> (my-reverse '(a b c))
(((() . c) . b) . a)
> (my-reverse '(one))
(() . one)
> (my-reverse '())
()
```

## The Bug(s)

The recursive case of `my-reverse` conses the *reversed rest* onto the *first element*, i.e. the arguments of `cons` are the wrong way round and, more fundamentally, an atom is being used where a list must go:

```scheme
(else (cons (my-reverse (cdr lat)) (car lat)))
```

## Why the Program Behaved Incorrectly

`(cons x y)` makes a pair whose `car` is `x` and whose `cdr` is `y`. A proper list is a chain of pairs whose final `cdr` is `'()`. Trace `(my-reverse '(a b c))` from the inside out:

| call | `lat` | returns |
|---|---|---|
| 4 | `()` | `()` |
| 3 | `(c)` | `(cons '() 'c)` → `(() . c)` |
| 2 | `(b c)` | `(cons '(() . c) 'b)` → `((() . c) . b)` |
| 1 | `(a b c)` | `(cons '((() . c) . b) 'a)` → `(((() . c) . b) . a)` |

Each `cons` puts a *list* in the `car` position and an *atom* in the `cdr` position. Because the `cdr` is an atom rather than a list, the printer has to show the pair with a dot. The intent, "put `a` after the reversed `(b c)`", requires adding an element at the **end** of a list, which `cons` cannot do in one step.

## The Concept This Illustrates

`cons` always adds to the **front**. Reversing a list requires placing the first element at the **back** of the reversed remainder, which means either `append`ing a one-element list (`(append (my-reverse (cdr lat)) (list (car lat)))`) or using a helper written for exactly that job (`add-to-end`, which this file already provides). Students who think of `cons` as "combine these two things" produce dotted pairs; the dot in the output is Scheme telling you that the second argument was not a list.

## The Correction

```scheme
; before
(else (cons (my-reverse (cdr lat)) (car lat)))

; after
(else (add-to-end (car lat) (my-reverse (cdr lat))))
```

`(else (append (my-reverse (cdr lat)) (list (car lat))))` is equally correct.

## Instructor Notes

- Ask students to type `(cons '(b c) 'a)` and `(cons 'a '(b c))` directly and compare the printed forms. The dot appears in exactly one of them.
- A frequent half-fix is swapping the arguments: `(cons (car lat) (my-reverse (cdr lat)))`. That is a proper list again but it is the *identity* (`(a b c)`), because `cons` puts `a` at the front. Ask where `a` needs to end up.
- Another attempt: `(cons (my-reverse (cdr lat)) (list (car lat)))` gives `(((() (c)) (b)) (a))`, nested lists without dots. Still wrong, but a good moment to say that `cons` of a list onto a list nests, while `append` splices.
- The accumulator-style reverse (`(define (rev lat acc) ...)`) is more efficient and worth showing after the fix as a preview of Module 3's helper-with-extra-argument pattern, but it is not required here.
- `insertR` is included as a correct model of the `cons`-back-what-you-walked-past pattern from debug01; ask students why it never produces dots.
