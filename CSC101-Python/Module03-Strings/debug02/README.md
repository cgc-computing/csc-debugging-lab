# Word Censor

**Course:** CSC101 &nbsp;|&nbsp; **Module 3:** Strings &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

The program reads a message and a word to censor, then prints the original message and a censored
copy in which every occurrence of that word is replaced by the same number of asterisks.

## Expected Behavior

```
Enter a message: this homework is dumb, really dumb
Enter the word to censor: dumb

Original: this homework is dumb, really dumb
Censored: this homework is ****, really ****
```

## How to Run

```bash
python3 censor.py
```

Type `this homework is dumb, really dumb` and press Enter, then type `dumb` and press Enter.

## Your Task

Run the program with the sample input and compare the "Censored" line with the Expected Behavior.
This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and
be ready to explain *why* the original version behaved the way it did. Do not rewrite the program;
the structure is fine.

## Think About

* What does the `replace` method give back, and what happens to that value in this program?
* Can a string be changed after it has been created? What does that mean for methods like
  `upper`, `replace`, and `strip`?
* In the Python shell, create a short string, call a method on it, and then print the original
  variable. Did the variable change? Where did the method's result go?
