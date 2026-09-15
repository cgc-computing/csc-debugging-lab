# Array-Based Stack

**Course:** CSC205 &nbsp;|&nbsp; **Module 9:** Stacks and Queues &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`ArrayStack` implements a LIFO stack of `int` values in a fixed-size array, using `top` as the count of items. `Main` pushes 10, 20, 30, peeks, and then pops until the stack is empty.

## Expected Behavior

```
size after 3 pushes: 3
peek: 30
pop:  30
pop:  20
pop:  10
empty: true
```

## How to Run

```bash
javac *.java
java Main
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep `top` meaning "number of items on the stack."

## Think About

- If `top` is the number of items, which array index holds the most recently pushed value?
- Draw the array after the three pushes. What is stored at `data[top]`?
- In `push`, does the store happen before or after `top` changes? What should the matching order be in `pop`?
