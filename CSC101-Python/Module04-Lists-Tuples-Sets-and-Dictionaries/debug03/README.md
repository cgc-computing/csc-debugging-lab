# Store Inventory Lookup

**Course:** CSC101 &nbsp;|&nbsp; **Module 4:** Lists, Tuples, Sets, and Dictionaries &nbsp;|&nbsp; **Activity:** debug03  
**Language:** Python 3

## Goal

The campus store tracks stock counts in a dictionary. The program shows which items are tracked,
asks the user for an item name, and reports how many are in stock. An item that is not tracked
should be reported as `0` in stock, not treated as a failure.

## Expected Behavior

```
Items we track: ['notebook', 'pencil', 'backpack', 'calculator']
Which item are you looking for? Backpack

Stock for backpack: 6
Number of different items tracked: 4
```

```
Items we track: ['notebook', 'pencil', 'backpack', 'calculator']
Which item are you looking for? stapler

Stock for stapler: 0
Number of different items tracked: 4
```

## How to Run

```bash
python3 inventory.py
```

Run it twice: first type `Backpack` and press Enter; then run it again and type `stapler`.

## Your Task

Run the program with both sample inputs and compare each run with the Expected Behavior. This
program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be
ready to explain *why* the original version behaved the way it did. Do not rewrite the program;
the structure is fine.

## Think About

* What happens when you use square brackets to look up a key that is not in a dictionary?
* Dictionaries have a method that looks up a key and lets you supply a value to use when the key
  is missing. What is it, and how is it different from square brackets?
* Should looking up something the store does not carry be treated as a problem with the program,
  or as an ordinary answer?
