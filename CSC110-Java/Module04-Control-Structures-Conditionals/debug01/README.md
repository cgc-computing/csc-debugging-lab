# Letter Grade Calculator

**Course:** CSC110 &nbsp;|&nbsp; **Module 4:** Control Structures: Conditionals &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

The program reads a final course score from 0 to 100 and prints the matching letter grade on the usual scale: 90 and above is an A, 80–89 is a B, 70–79 is a C, 60–69 is a D, and anything below 60 is an F. Grades of A or B also earn a short compliment.

## Expected Behavior

```
Enter the final score (0-100): 85
Score 85 earns a grade of B
Nice work!
```

Other checks: `92` should earn an A, `71` a C, `64` a D, and `40` an F.

## How to Run

```bash
javac LetterGrade.java
java LetterGrade
```

Type a whole number and press Enter. Use `85` to reproduce the sample run, then try the other scores listed above.

## Your Task

Run the program with several scores and compare the results with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- In an `if / else if / else if` chain, how many of the branches can run? Which one is chosen when several conditions are true at the same time?
- For a score of 85, walk through the conditions in order. Which is the first one that is true?
- Does the order of the tests matter in this chain? Would it matter if every condition tested a range with both a lower and an upper bound?
