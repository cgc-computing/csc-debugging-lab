# List Basics

**Course:** CSC240 &nbsp;|&nbsp; **Module 2:** Writing Recursive List Rules &nbsp;|&nbsp; **Activity:** debug01
**Language:** Prolog (SWI-Prolog)

## Goal

Two hand-written recursive predicates over lists. `my_length(List, N)` relates a list to the number of elements in it. `my_last(List, X)` relates a non-empty list to its final element. (The built-in `length/2` and `last/2` do the same jobs; the point here is to write them yourself.)

## Expected Behavior

```prolog
?- my_length([], N).
N = 0.

?- my_length([a, b, c], N).
N = 3.

?- my_length([a, b, c], 3).
true.

?- my_last([a, b, c], X).
X = c ;
false.
```

(The `false.` after `X = c` appears when you press `;`; it just means there is no second answer.)

## How to Run

```bash
swipl list_basics.pl
```

Type the sample queries at the `?-` prompt, each ending with a period. Type `halt.` to leave Prolog.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the two-clause recursive structure.

## Think About

- Trace `my_length([a], N)` by hand. The recursive call reaches the base clause and binds a variable to `0`. Which variable? Then what does the next goal ask Prolog to prove?
- In Java, `n = n + 1` changes `n`. Can a Prolog variable ever be given a second value once it has one? What does that make `N is N + 1` mean?
- The recursive clause needs *two* different quantities: the length of the tail and the length of the whole list. How many variable names does it use for them?
