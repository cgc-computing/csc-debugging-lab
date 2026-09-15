# Letter Grade Calculator

**Course:** CSC101 &nbsp;|&nbsp; **Module 5:** Conditionals &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

The program reads a final course score and prints the matching letter grade: 90 and above is an
A, 80–89 a B, 70–79 a C, 60–69 a D, and anything below 60 an F.

## Expected Behavior

```
Enter the final score (0-100): 85

A score of 85.0 earns a grade of B.
Congratulations on passing!
```

Try a few other scores too: `92` should earn an A, `71` a C, `59.5` an F.

## How to Run

```bash
python3 letter_grade.py
```

Type `85` and press Enter. Run it again with other scores.

## Your Task

Run the program with several scores and compare each result with the Expected Behavior. This
program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be
ready to explain *why* the original version behaved the way it did. Do not rewrite the program;
the structure is fine.

## Think About

* In an `if`/`elif` chain, how many branches can run? Which one is chosen when more than one
  condition would be true?
* Trace the score 85 through the chain by hand, one condition at a time. Where does it stop?
* Does the order of the conditions matter here? Would it matter if the comparisons used `<`
  instead of `>=`?
