# Inventory Search by Item

**Course:** CSC205 &nbsp;|&nbsp; **Module 10:** Searching &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`Item` describes one product (name and SKU) and defines what it means for two items to be equal. `ItemSearch` performs a linear search through an unsorted shelf of items: `indexOf` returns the position of the first matching item and `count` returns how many matching items are on the shelf.

## Expected Behavior

```
indexOf pliers (#1003): 2
indexOf wrench (#1002): 1
count   wrench (#1002): 2
indexOf drill (#2001): -1
```

## How to Run

```bash
javac *.java
java ItemSearch
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The `Item` class is correct as written; concentrate on the search code.

## Think About

- The first search succeeds and the second fails, yet both describe an item that is sitting on the shelf. What is different about how the two targets were created?
- In Java, what are the two different ways to ask whether two objects are "the same"? Which one does each search use?
- Why does `count` report 0 for the wrench when there are clearly two wrenches?
- If the search had been over an `int[]` of SKUs instead of an `Item[]`, would the same code have worked?
