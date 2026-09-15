# Daily Weather Summary

**Course:** CSC101 &nbsp;|&nbsp; **Module 9:** Functions &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

The program reads the morning (low) and afternoon (high) temperatures, uses one function to
compute how many degrees the temperature rose, and another to describe that change in words.

## Expected Behavior

```
Morning temperature (F): 54
Afternoon temperature (F): 78

Low:  54.0 F
High: 78.0 F
The temperature rose 24.0 degrees, a big swing.
```

## How to Run

```bash
python3 weather_summary.py
```

Type `54` and then `78`, pressing Enter after each.

## Your Task

Run the program with the sample values and compare the last line with the Expected Behavior. This
program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be
ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the
structure is fine.

## Think About

* When a function is called, how does Python decide which argument goes into which parameter?
* Look at the parameter names in the function definition and the variable names at the call.
  Which value does `high` receive when the program runs with the sample input?
* Why does `describe_range` also give an unexpected answer, even though nothing in it is
  incorrect?
