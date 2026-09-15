# Solution: Rember

**Course/Module/Activity:** CSC240 · Module 2 Writing Recursive List Functions · debug01
**Bug type(s):** logic, paradigm-specific (forgetting to rebuild the list on the way back)
**Bug count:** 1

## Observed Behavior

Desk-checked (no R5RS interpreter on the authoring machine). No errors; `rember` throws away every element that comes *before* the one it removes:

```scheme
> (rember 'mint '(lamb chops and mint jelly))
(jelly)
> (rember 'cup '(coffee cup tea cup and hick cup))
(tea cup and hick cup)
> (rember 'toast '(bacon and eggs))
()
> (rember 'bacon '(bacon and eggs))
(and eggs)
> (firsts '((apple peach pumpkin) (plum pear cherry) (grape raisin pea)))
(apple plum grape)
```

Only the call where the atom is already first (`'bacon`) comes out right. `firsts` is correct.

## The Bug(s)

The `else` clause of `rember` recurs on `(cdr lat)` but never puts `(car lat)` back:

```scheme
(else (rember a (cdr lat)))
```

## Why the Program Behaved Incorrectly

Trace `(rember 'mint '(lamb chops and mint jelly))`:

| call | `lat` | clause taken | value returned |
|---|---|---|---|
| 1 | `(lamb chops and mint jelly)` | else | whatever call 2 returns |
| 2 | `(chops and mint jelly)` | else | whatever call 3 returns |
| 3 | `(and mint jelly)` | else | whatever call 4 returns |
| 4 | `(mint jelly)` | `eq?` | `(jelly)` |

Each `else` simply *passes along* the result of the recursive call, so `lamb`, `chops`, and `and` are dropped. The recursion correctly finds the atom; it just fails to reconstruct the part of the list it walked past. When nothing matches (`'toast`), every clause is `else` until the base case returns `'()`, so the whole list vanishes.

## The Concept This Illustrates

Natural recursion over a list has two halves: *taking apart* with `cdr` on the way down and *building up* with `cons` on the way back. *The Little Schemer* calls this the Second Commandment: use `cons` to build lists. A Java programmer thinks of removal as an in-place operation on one list; in Scheme the result is a **new** list, so every element you decide to keep must be explicitly `cons`ed onto the result of the recursion. `firsts`, defined right below, shows the pattern.

## The Correction

```scheme
; before
(else (rember a (cdr lat)))

; after
(else (cons (car lat) (rember a (cdr lat))))
```

## Instructor Notes

- Have students trace the corrected version on the same input and watch the `cons` calls "unwind": `(cons 'lamb (cons 'chops (cons 'and '(jelly))))`.
- A common wrong fix is `(cons a (rember a (cdr lat)))`, which re-inserts the atom being removed at every step. Ask them what `a` is versus `(car lat)` in the `else` branch.
- Another attempt is `(append (car lat) (rember a (cdr lat)))`. `append` wants two lists and `(car lat)` is an atom; in R5RS this is an error (`append: contract violation`). Good moment to contrast `cons` (element onto list) with `append` (list onto list).
- Ask what the corrected `rember` does with `(rember 'cup '(coffee cup tea cup and hick cup))` and why only the first `cup` is removed. `multirember` (removing all) is the next natural exercise.
