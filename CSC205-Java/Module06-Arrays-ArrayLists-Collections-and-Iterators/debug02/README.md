# Long Words With an Iterator

**Course:** CSC205 &nbsp;|&nbsp; **Module 6:** Arrays, ArrayLists, Collections, and Iterators &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`printLongerThan(words, minLength)` walks a `List<String>` with an explicit `Iterator` and prints each word whose length exceeds `minLength`, in list order.

## Expected Behavior

```
Words longer than 4 letters:
binary
stack
queue
graph
recursion
Done.
```

## How to Run

```bash
javac LongWords.java
java LongWords
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the explicit `Iterator`; do not switch to a for-each loop.

## Think About

- What does `Iterator.next()` do besides returning an element? How many times per loop iteration should it be called?
- Which word was checked for length, and which word was printed? Are they the same word?
- What does `hasNext()` promise, and about how many elements?
