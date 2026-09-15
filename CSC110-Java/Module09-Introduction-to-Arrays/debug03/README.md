# Reverse an Array in Place

**Course:** CSC110 &nbsp;|&nbsp; **Module 9:** Introduction to Arrays &nbsp;|&nbsp; **Activity:** debug03
**Language:** Java 17+

## Goal

The program reverses an integer array *in place* — without building a second array — by swapping pairs of elements from the two ends toward the middle. It prints the array before and after.

## Expected Behavior

```
Original: 3, 8, 12, 5, 21, 7
Reversed: 7, 21, 5, 12, 8, 3
```

## How to Run

```bash
javac ReverseArray.java
java ReverseArray
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the in-place swapping approach; the structure is fine.

## Think About

- For an array of 6 elements, how many *swaps* are needed to reverse it? How many does the loop perform?
- Trace the array by hand after each iteration of the loop. What does it look like halfway through? At the end?
- What happens when you swap the same pair of elements twice?
