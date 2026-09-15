# Dice Simulator

**Course:** CSC101 &nbsp;|&nbsp; **Module 13:** Python Libraries &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

The program simulates rolling a fair six-sided die 600 times using the `random` module, counts
how many times each face (1 through 6) appears, and prints the counts with a small bar chart.

## Expected Behavior

Because the rolls are random, the exact counts change every run, but every face from 1 to 6 should
appear roughly 100 times (typically somewhere between about 80 and 120). A sample run:

```
Results of 600 rolls:
1:  103  ####################
2:   97  ###################
3:  108  #####################
4:   94  ##################
5:  101  ####################
6:   97  ###################
```

## How to Run

```bash
python3 dice_simulator.py
```

No input is required. Run it several times.

## Your Task

Run the program a few times and compare the pattern of counts with the Expected Behavior. This
program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be
ready to explain *why* the original version behaved the way it did. Do not rewrite the program;
the structure is fine.

## Think About

* Which face never shows up, no matter how many times you run the program? Is that plausible for
  a fair die?
* Look up `random.randrange` and `random.randint` in the Python documentation. Is the upper
  limit included or excluded for each one?
* Which other Python feature you have used follows the same convention for its stop value?
