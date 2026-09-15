# Solution: Long Words With an Iterator

**Course/Module/Activity:** CSC205 · Module 6 Arrays, ArrayLists, Collections, and Iterators · debug02
**Bug type(s):** logic, runtime
**Bug count:** 1

## Observed Behavior

The wrong words are printed and the program crashes at the end:

```
Words longer than 4 letters:
node
queue
heap
Exception in thread "main" java.util.NoSuchElementException
	at java.base/java.util.ArrayList$Itr.next(...)
	at LongWords.printLongerThan(LongWords.java:11)
	at LongWords.main(LongWords.java:24)
```

## The Bug(s)

`LongWords.java`, `printLongerThan`: `it.next()` is called twice in one iteration — once inside the `if` condition to test the length, and again inside the body to print. Each call advances the iterator, so the word that passed the test is not the word that gets printed, and the second call can run past the end of the list.

## Why the Program Behaved Incorrectly

`next()` both *returns the current element* and *moves the cursor forward*. Trace: `next()` → "tree" (4, no). `next()` → "binary" (6, yes) → body calls `next()` → prints "node". `next()` → "stack" (5, yes) → prints "queue". `next()` → "graph" (5, yes) → prints "heap". `hasNext()` is true (one left) → `next()` → "recursion" (9, yes) → body calls `next()` with nothing left → `NoSuchElementException`. `hasNext()` only guaranteed *one* more element, not two.

## The Concept This Illustrates

The `Iterator` protocol: `hasNext()` asks whether one more element exists; `next()` consumes it. Exactly one `next()` per `hasNext()` is the invariant, and the element must be captured in a local variable if it is needed more than once. This is the same mistake as reading `scanner.nextInt()` twice when you meant to reuse a value.

## The Correction

```java
// before
if (it.next().length() > minLength) {
    System.out.println(it.next());
}
// after
String word = it.next();
if (word.length() > minLength) {
    System.out.println(word);
}
```

## Instructor Notes

- Remove "recursion" from the data and the crash disappears while the output stays wrong — a nice demonstration that a bug can be present without a crash, and why the sample data matters.
- Students sometimes wrap the second `next()` in `if (it.hasNext())`. That prevents the exception but still prints the wrong word; ask them to compare the printed list with the expected one.
- Connect to the for-each loop: `for (String word : words)` is exactly the corrected pattern with the iterator hidden. Ask why the explicit form is still worth knowing (removal during iteration, iterating two collections in step).
