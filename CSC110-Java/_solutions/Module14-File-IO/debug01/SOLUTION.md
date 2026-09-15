# Solution: Exam Scores from a File

**Course/Module/Activity:** CSC110 · Module 14 File I/O · debug01
**Bug type(s):** runtime, logic
**Bug count:** 1

## Observed Behavior

The program reads all six scores and then crashes before printing anything:

```
Exception in thread "main" java.util.NoSuchElementException
	at java.base/java.util.Scanner.throwFor(Scanner.java:975)
	at java.base/java.util.Scanner.next(Scanner.java:1632)
	at java.base/java.util.Scanner.nextInt(Scanner.java:2297)
	at java.base/java.util.Scanner.nextInt(Scanner.java:2251)
	at ScoreReader.main(ScoreReader.java:24)
```

## The Bug(s)

`ScoreReader.java`, in `main`: the loop guard and the read do not match.

```java
while (fileIn.hasNextLine()) {
    int score = fileIn.nextInt();
```

## Why the Program Behaved Incorrectly

`nextInt()` consumes the digits of a token but *not* the line terminator after it. After the sixth score (`71`) is read, the `Scanner` is positioned just before the final newline. `hasNextLine()` returns `true` because a (empty) line is still available. The loop body then calls `nextInt()`, which looks for another integer token, finds none, and throws `NoSuchElementException`. The guard answered a question about lines while the body asked for a token — two different units of input.

## The Concept This Illustrates

`Scanner`'s "has-next" methods must be paired with the matching "next" method: `hasNextInt()` with `nextInt()`, `hasNextLine()` with `nextLine()`, `hasNext()` with `next()`. Mixing token-based and line-based reading is the root of most `Scanner` surprises, including the well-known "skipped input" problem after `nextInt()` at the keyboard.

## The Correction

```java
// before
while (fileIn.hasNextLine()) {
    int score = fileIn.nextInt();

// after
while (fileIn.hasNextInt()) {
    int score = fileIn.nextInt();
```

## Instructor Notes

- The equally valid line-based fix is `String line = fileIn.nextLine(); int score = Integer.parseInt(line.trim());` inside a `hasNextLine()` loop. Ask students what happens with a blank line at the end of the file in that version (`parseInt("")` throws) — and why `hasNextInt()` is the more robust choice for this file.
- Demonstrate the subtlety: delete the final newline from `scores.txt` and the buggy program works. Ask why a bug that depends on an invisible trailing newline is dangerous.
- Some students wrap `nextInt()` in `try/catch` and swallow the exception. Output becomes correct; ask whether the program is fixed or merely quiet.
- Point out that `count`, `total`, and `highest` were all correct at the moment of the crash — the read logic was fine; only the termination test was wrong.
