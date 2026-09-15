# Solution: Class Sections

**Course/Module/Activity:** CSC240 · Module 1 Functional Programming, Scheme Terminology, Data Types, and Lists · debug01
**Bug type(s):** logic, paradigm-specific (`cons` vs `append`)
**Bug count:** 1

## Observed Behavior

Desk-checked (no R5RS interpreter on the authoring machine). No errors; the merged roster is nested instead of flat, and the two helpers report on that nested structure:

```scheme
> (merge-sections morning afternoon)
((ana ben carlos) dee eli)
> (count-students (merge-sections morning afternoon))
3
> (first-student (merge-sections morning afternoon))
(ana ben carlos)
```

## The Bug(s)

`merge-sections` uses `cons` where `append` is needed:

```scheme
(define (merge-sections first-section second-section)
  (cons first-section second-section))
```

## Why the Program Behaved Incorrectly

`(cons x lst)` builds a list whose **first element is `x`**, whatever `x` is, followed by the elements of `lst`. Here `x` is the whole list `(ana ben carlos)`, so the result is a three-element list: the morning list as a single element, then `dee`, then `eli`. `count-students` correctly counts three elements; `first-student` correctly returns the first element, which is the entire morning list. The helpers are fine; they were handed the wrong shape of data.

## The Concept This Illustrates

`cons` adds **one element** to the front of a list; `append` joins **two lists** end to end. Java students reach for something like `list1.addAll(list2)` and assume the closest Scheme primitive does the same. Recognizing the printed shape `((ana ben carlos) dee eli)` as "a list whose first element is a list" is the Module 1 skill (atoms vs. lists, S-expressions), and it is what tells you which primitive was used.

## The Correction

```scheme
; before
(cons first-section second-section)

; after
(append first-section second-section)
```

## Instructor Notes

- Ask students to evaluate `(cons 'ana '(dee eli))` and `(cons '(ana) '(dee eli))` side by side in the Interactions window and describe the difference in words before touching the file.
- Some students try `(list first-section second-section)`, which gives `((ana ben carlos) (dee eli))`: still nested, now both halves. Good contrast: `list` wraps its arguments, `append` splices them.
- Another attempt is `(cons (car first-section) second-section)`, which produces `(ana dee eli)`. Ask what happened to `ben` and `carlos`; this leads naturally to the recursive definition of `append`, which Module 2 will write by hand.
- If someone asks why `count-students` is named with `lat`, connect it to *The Little Schemer*'s "list of atoms" terminology from this module.
