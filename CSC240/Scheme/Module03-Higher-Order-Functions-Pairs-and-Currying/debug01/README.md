# Number Tools

**Course:** CSC240 &nbsp;|&nbsp; **Module 3:** Higher-Order Functions, Pairs, and Currying &nbsp;|&nbsp; **Activity:** debug01
**Language:** Scheme (R5RS, DrRacket)

## Goal

Three utilities over lists of numbers. `squares` returns the square of every element. `evens` returns only the elements that are even, in their original order. `sum-evens` adds up the even elements.

## Expected Behavior

```scheme
> (squares '(1 2 3 4))
(1 4 9 16)
> (evens '(1 2 3 4 5 6))
(2 4 6)
> (evens '(1 3 5))
()
> (sum-evens '(1 2 3 4 5 6))
12
```

## How to Run

Open `number-tools.scm` in DrRacket. Set **Language → Choose Language → Other Languages → R5RS**. Click **Run**, then type the sample calls in the Interactions window.

Command-line alternative: add lines such as `(display (evens '(1 2 3 4 5 6))) (newline)` at the bottom of the file and run

```bash
plt-r5rs number-tools.scm
```

or start an interactive session with the file loaded using `plt-r5rs -i number-tools.scm`.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem.

This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. You may add a helper procedure to the file; R5RS does not provide one for this job.

## Think About

- How many elements does `map` return compared with the list it is given? Can `map` ever produce a shorter list?
- What does `even?` return for each number, and what does the result of `evens` actually contain?
- Write in one sentence what a procedure would have to do to *keep some elements and drop others*. What would its parameters be, and how would you write it recursively?
