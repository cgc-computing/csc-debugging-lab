# Solution: Curried Adders

**Course/Module/Activity:** CSC240 · Module 3 Higher-Order Functions, Pairs, and Currying · debug02
**Bug type(s):** runtime (arity mismatch), paradigm-specific (currying)
**Bug count:** 1

## Observed Behavior

Desk-checked (no R5RS interpreter on the authoring machine). The first three calls work. `total-with-bonus` fails as soon as `map` applies the lambda to the first score:

```scheme
> ((add 3) 4)
7
> (add5 10)
15
> (add-to-all 10 '(1 2 3))
(11 12 13)
> (total-with-bonus 5 '(80 90 70))
add: arity mismatch;
 the expected number of arguments does not match the given number
  expected: 1
  given: 2
```

(Older DrRacket versions phrase it as "add: expects 1 argument, given 2: 5 80". The key facts are the procedure name `add`, "expected 1", "given 2".)

## The Bug(s)

Inside `total-with-bonus` the curried `add` is called as if it took two arguments:

```scheme
(map (lambda (s) (add bonus s)) scores)
```

## Why the Program Behaved Incorrectly

`add` is defined with **one** parameter, `a`, and returns a `lambda` of one parameter, `b`. Adding two numbers with it therefore takes two applications: `(add bonus)` produces the adder, and `((add bonus) s)` applies it. The lambda in `total-with-bonus` performs one application with two arguments, `(add 5 80)`, and Scheme rejects it before `+` is ever reached. `add-to-all` gets it right: `(add n)` is evaluated once to make a one-argument procedure, which `map` then applies to each element.

## The Concept This Illustrates

**Currying**: a procedure of two arguments can be rewritten as a procedure of one argument that returns a procedure of one argument. The payoff is that partial application (`(add 5)`) yields a reusable procedure to hand to `map` or store under a name (`add5`). The cost is that the call syntax changes: `((add a) b)`, not `(add a b)`. Java programmers, whose methods have a fixed arity, tend to read `add` as "a two-argument function that happens to be written oddly". The arity error is Scheme insisting that `(add a)` is the *whole* call.

## The Correction

```scheme
; before
(map (lambda (s) (add bonus s)) scores)

; after
(map (lambda (s) ((add bonus) s)) scores)
```

Even better, drop the wrapper lambda, exactly as `add-to-all` does: `(map (add bonus) scores)`.

## Instructor Notes

- Ask students to evaluate `(add 5)` alone in the Interactions window. Seeing `#<procedure>` printed makes the point that `add` returns a procedure, not a number.
- Some students "fix" the bug by changing `add` to `(define (add a b) (+ a b))`. Then `add5` breaks (`(add 5)` becomes an arity error the other way) and `add-to-all` breaks too. Have them run the *whole* sample set after any change.
- The simplification `(map (add bonus) scores)` is a nice moment to compare with `add-to-all` and to ask what the `lambda` wrapper was contributing (nothing).
- Follow-up: write `compose` or a curried `multiply` and use it with `map` to reinforce the pattern.
