# Solution: Quiz Score Statistics

**Course/Module/Activity:** CSC110 · Module 9 Introduction to Arrays · debug01
**Bug type(s):** runtime, boundary
**Bug count:** 1

## Observed Behavior

The program crashes after printing the first line:

```
Number of scores: 5
Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: Index 5 out of bounds for length 5
	at ScoreStats.main(ScoreStats.java:13)
```

## The Bug(s)

`ScoreStats.java`, in `main`:

```java
for (int i = 0; i <= scores.length; i++) {
```

The loop condition allows `i` to reach `scores.length`.

## Why the Program Behaved Incorrectly

An array of length 5 has indices 0 through 4. With `i <= scores.length`, the loop runs one extra time with `i` = 5 and evaluates `scores[5]`, which does not exist. Java checks every array access at run time and throws `ArrayIndexOutOfBoundsException` rather than reading memory it should not.

## The Concept This Illustrates

Zero-based indexing: the last valid index is `length - 1`, so the canonical loop is `for (int i = 0; i < arr.length; i++)`. This is the same off-by-one from Module 5 in its most common disguise, and the exception message (index vs. length) tells students exactly what happened if they read it.

## The Correction

```java
// before
for (int i = 0; i <= scores.length; i++) {

// after
for (int i = 0; i < scores.length; i++) {
```

## Instructor Notes

- Some students will write `i <= scores.length - 1`. Correct, but ask which form they will actually remember and type reliably.
- Make sure students read the stack trace line `at ScoreStats.main(ScoreStats.java:13)` and locate that line — this may be their first exception with a useful trace.
- Ask: why does Java throw an exception here when the earlier Module 5 off-by-one just produced a wrong number? (Arrays have a hard boundary; a counter does not.)
- Enhanced `for` (`for (int s : scores)`) also fixes it and is worth showing after they understand the indexed version.
