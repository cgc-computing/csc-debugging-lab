# Remove Even Numbers From a List

**Course:** CSC205 &nbsp;|&nbsp; **Module 6:** Arrays, ArrayLists, Collections, and Iterators &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`removeEvens` deletes every even integer from an `ArrayList<Integer>`, in place, leaving the odd values in their original order.

## Expected Behavior

```
Before: [3, 8, 6, 10, 7, 12, 14, 5, 2]
After:  [3, 7, 5]
```

## How to Run

```bash
javac RemoveEvens.java
java RemoveEvens
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The list must be modified in place (do not build a second list).

## Think About

- After `values.remove(i)` succeeds, which element now sits at index `i`? Has the loop looked at it?
- Which of the even numbers survive, and what do their positions in the original list have in common?
- What tools does Java offer for removing elements while walking a collection?
