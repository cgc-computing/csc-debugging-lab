# Paint Estimate

**Course:** CSC101 &nbsp;|&nbsp; **Module 9:** Functions &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

The program reads a room's length, width, and wall height, uses a helper function to compute the
area of each wall, adds up the four walls, and reports the total area and the gallons of paint
needed at 350 square feet per gallon.

## Expected Behavior

```
Room length (ft): 15
Room width (ft): 12
Wall height (ft): 10

Total wall area: 540.0 sq ft
Gallons needed:  1.54
```

## How to Run

```bash
python3 paint_estimate.py
```

Type `15`, `12`, and `10`, pressing Enter after each.

## Your Task

Run the program with the sample values and read *all* of the output carefully. This program
contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to
explain *why* the original version behaved the way it did. Do not rewrite the program; the
structure is fine.

## Think About

* What is the difference between a function that *prints* a value and a function that *returns*
  a value? What does the caller receive in each case?
* What value does a function give back if it has no `return` statement?
* Compare `wall_area` with `gallons_needed`. How is each one used by the code at the bottom of
  the file?
