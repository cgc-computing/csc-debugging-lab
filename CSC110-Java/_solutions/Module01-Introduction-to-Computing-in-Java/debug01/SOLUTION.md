# Solution: Quotation Printer

**Course/Module/Activity:** CSC110 · Module 1 Introduction to Computing in Java · debug01
**Bug type(s):** logic
**Bug count:** 1 (the same misconception appears on two consecutive lines)

## Observed Behavior

The three lines of the quotation run together on one line, with no spaces between them:

```
A Favorite Quotation
--------------------
Do not go where the path may lead;go instead where there is no pathand leave a trail.
      -- Ralph Waldo Emerson
```

## The Bug(s)

`QuotePrinter.java`, in `main`, the two statements that print the first and second lines of the quotation use `System.out.print(...)` instead of `System.out.println(...)`:

```java
System.out.print("Do not go where the path may lead;");
System.out.print("go instead where there is no path");
```

## Why the Program Behaved Incorrectly

`print` writes its text and leaves the cursor at the end of that text. `println` writes its text and then moves to the start of the next line. Because the first two quotation lines use `print`, nothing moves the cursor down, so the next output continues on the same line. The third line uses `println`, which is why the author line does start on a new line.

## The Concept This Illustrates

The difference between `print` and `println`: the newline is *part of the output*, produced by the statement, not something that happens automatically between statements. Students often assume each `System.out` statement produces its own line.

## The Correction

```java
// before
System.out.print("Do not go where the path may lead;");
System.out.print("go instead where there is no path");

// after
System.out.println("Do not go where the path may lead;");
System.out.println("go instead where there is no path");
```

## Instructor Notes

- Some students will "fix" it by adding `System.out.println();` after each `print`. That produces correct output and is a good moment to ask: what does an empty `println()` do, and why does it work?
- Others will add `"\n"` inside the strings. Also correct; ask them to compare the three approaches.
- This is a good first exposure to reading output carefully rather than assuming it is right because the program "ran".
