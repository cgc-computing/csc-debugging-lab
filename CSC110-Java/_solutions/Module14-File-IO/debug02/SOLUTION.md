# Solution: Writing a Score Report

**Course/Module/Activity:** CSC110 · Module 14 File I/O · debug02
**Bug type(s):** runtime, conceptual/design
**Bug count:** 1

## Observed Behavior

The screen output looks right, but `report.txt` is created and is completely empty (0 bytes):

```
Report written to report.txt (6 scores).
```

```
$ cat report.txt
$
```

## The Bug(s)

`ReportWriter.java`, in `main`: the `PrintWriter` is never closed (or flushed).

```java
PrintWriter report = new PrintWriter("report.txt");
...
report.printf("Average: %.2f%n", (double) total / count);

System.out.println("Report written to report.txt (" + count + " scores).");
```

## Why the Program Behaved Incorrectly

A `PrintWriter` built from a file name wraps a buffered stream. Each `println` puts text into an in-memory buffer; the buffer is written to the file only when it fills up, when `flush()` is called, or when `close()` is called. This report is far smaller than the buffer, so nothing is ever pushed to disk. When `main` ends, the JVM exits without flushing the buffer, and the data is lost. The file exists (opening it created it) but is empty.

## The Concept This Illustrates

Output streams are buffered and must be closed. Closing a writer is not just "tidying up" — it is the step that guarantees the data is actually written. Students see `fileIn.close()` as optional housekeeping and assume the writer is the same; for readers it mostly is, for writers it is not.

## The Correction

```java
// after
report.printf("Average: %.2f%n", (double) total / count);
report.close();
```

## Instructor Notes

- `report.flush()` also makes the text appear but leaves the file handle open; ask why `close()` is preferred at the end.
- `System.out` is also a `PrintStream`, and students may ask why *its* output appears without closing. It is created with auto-flush on newline; `new PrintWriter("file")` is not. `new PrintWriter(new FileWriter("report.txt"), true)` would auto-flush; discuss the trade-off.
- Try-with-resources (`try (PrintWriter report = new PrintWriter("report.txt")) { ... }`) closes automatically and is the modern idiom. If students know it, encourage it; if not, this is a good moment to introduce it.
- Some students think the file is empty because of a path problem. Have them check `report.txt` exists (it does) and note its size — that distinction is a good diagnostic habit.
