# Movie Ticket Pricing

**Course:** CSC101 &nbsp;|&nbsp; **Module 5:** Conditionals &nbsp;|&nbsp; **Activity:** debug02  
**Language:** Python 3

## Goal

Movie tickets cost $12.00, except on Tuesdays and Wednesdays when they cost $8.00. The program
reads the day of the show and the number of tickets, applies the discount only on those two days,
and prints the total.

## Expected Behavior

```
What day is the show (e.g., Monday)? Friday
How many tickets? 2
2 ticket(s) for Friday: $24.00
```

```
What day is the show (e.g., Monday)? tuesday
How many tickets? 2
Midweek discount applied!
2 ticket(s) for Tuesday: $16.00
```

## How to Run

```bash
python3 ticket_price.py
```

Run it twice: first type `Friday` then `2`; then run again with `tuesday` and `2`.

## Your Task

Run the program with both sample inputs and compare with the Expected Behavior. This program
contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to
explain *why* the original version behaved the way it did. Do not rewrite the program; the
structure is fine.

## Think About

* Read the `if` condition out loud in English. Now read it the way Python does: what are the two
  operands of `or`, and what is the value of each one?
* In the Python shell, try `bool("Wednesday")`. What does Python consider true or false about a
  string by itself?
* Try `"Friday" == "Tuesday" or "Wednesday"` in the Python shell, then try `"Friday" == "Wednesday"`.
  Why do the two results differ?
