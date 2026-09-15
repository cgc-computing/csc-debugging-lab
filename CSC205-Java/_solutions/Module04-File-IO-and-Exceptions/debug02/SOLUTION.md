# Solution: Letter Grade Report Writer

**Course/Module/Activity:** CSC205 · Module 4 File I/O and Exceptions · debug02
**Bug type(s):** runtime, conceptual/design
**Bug count:** 1

## Observed Behavior

The program reports success but the file is empty:

```
Skipping Dana Whitfield: score 105 is out of range
Report saved to report.txt
Contents of report.txt:
```

`report.txt` exists on disk with size 0.

## The Bug(s)

`GradeReport.java`, `writeReport`: the `PrintWriter` is never closed (or flushed). `PrintWriter` over a `FileWriter` buffers output in memory; the buffered text is written to the file only on `flush()`/`close()`. The method returns with the data still sitting in the buffer.

## Why the Program Behaved Incorrectly

Each `out.println` appends to an in-memory buffer (a few KB). Four short lines never fill it, so nothing reaches the operating system. `echoFile` then opens the file and finds it empty. When the JVM exits, the unflushed `PrintWriter` is simply discarded — Java does not flush writers automatically at shutdown — so the file stays empty even after the program ends.

## The Concept This Illustrates

Buffered output streams and resource management. Writing to a `Writer` is not the same as writing to the disk; `close()` both flushes and releases the file handle. The idiomatic guarantee is try-with-resources (`try (PrintWriter out = ...) { ... }`), which closes the writer even if an exception escapes the loop. Students meeting exceptions and file I/O together in Module 4 should connect the two: closing in a `finally` (or try-with-resources) is *why* those constructs exist.

## The Correction

```java
// before
PrintWriter out = new PrintWriter(new FileWriter(fileName));
for (...) { ... }

// after
try (PrintWriter out = new PrintWriter(new FileWriter(fileName))) {
    for (...) { ... }
}
```

Adding `out.close();` after the loop also works for this program, but does not close the writer if an unexpected exception is thrown inside the loop.

## Instructor Notes

- Students sometimes add `out.flush()` inside the loop. It "works" but leaks the file handle; ask what happens in a program that opens thousands of files.
- Contrast with `echoFile`, which already uses try-with-resources correctly — a good "spot the difference" prompt.
- Ask: "Why does the console output appear immediately even though `System.out` is also a `PrintStream`?" (It is created with autoflush on newline.)
- Extension: what if `letterGrade` threw an *unchecked* exception for one student? With the corrected code the file still contains the earlier lines; with the original it would be empty.
