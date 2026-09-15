# List Reverse

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Writing Recursive List Rules &nbsp;|&nbsp; **Activity:** debug02
**Language:** Prolog (SWI-Prolog)

## Goal

`my_reverse(List, Reversed)` relates a list to the same elements in the opposite order, using ordinary (non-accumulator) recursion. `my_append/3` is a hand-written `append` provided as a helper.

## Expected Behavior

```prolog
?- my_append([1, 2], [3], L).
L = [1, 2, 3].

?- my_reverse([1, 2, 3], R).
R = [3, 2, 1].

?- my_reverse([a], R).
R = [a].

?- my_reverse([], R).
R = [].

?- my_reverse([1, 2, 3], [3, 2, 1]).
true.
```

## How to Run

```bash
swipl list_reverse.pl
```

Type the sample queries at the `?-` prompt, each ending with a period. Type `halt.` to leave Prolog.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the plain recursive structure (no accumulator); you may use `my_append`.

## Think About

- After the recursive call, `RT` holds the reversed tail. Where in the final answer does the original head `H` belong: at the front of `RT` or at the back?
- What does `[H|RT]` build? Which end of the list does the `|` notation give you access to?
- Trace `my_reverse([1, 2, 3], R)` from the innermost call outward, writing down `RT` and `R` at each level. At which level does the answer first look wrong?
