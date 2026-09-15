# Grocery List

**Course:** CSC101 &nbsp;|&nbsp; **Module 4:** Lists, Tuples, Sets, and Dictionaries &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

The program starts with a three-item grocery list, asks the user for one more item, adds it, and
then prints the list sorted alphabetically along with its length and its first item.

## Expected Behavior

```
Starting list: ['milk', 'bread', 'apples']
What else do you need? eggs

You need 4 items:
['apples', 'bread', 'eggs', 'milk']
First item to grab: apples
```

## How to Run

```bash
python3 grocery_list.py
```

Type `eggs` and press Enter.

## Your Task

Run the program, read the full output, and compare it with the Expected Behavior. This program
contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to
explain *why* the original version behaved the way it did. Do not rewrite the program; the
structure is fine.

## Think About

* Which list methods change the list "in place," and what value do those methods give back?
* After the line that adds the new item runs, what does the name `groceries` refer to?
* In the Python shell, try `nums = [3, 1, 2]` and then `print(nums.sort())`. What prints, and
  what does `nums` look like afterward?
