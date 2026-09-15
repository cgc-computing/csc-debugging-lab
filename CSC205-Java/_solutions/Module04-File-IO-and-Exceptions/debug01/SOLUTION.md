# Solution: Class Score Report From CSV

**Course/Module/Activity:** CSC205 · Module 4 File I/O and Exceptions · debug01
**Bug type(s):** conceptual/design, runtime (swallowed)
**Bug count:** 1

## Observed Behavior

Brianna is printed with Alice's score and the average is off:

```
Alice Chen       1001   88
Brianna Ortiz    1002   88
Carlos Diaz      1003   75
Dana Whitfield   1004   95
Class average: 86.5
```

## The Bug(s)

`ScoreReport.java`, inside the `while` loop: the `catch (NumberFormatException e)` block is empty, and the variables `name`, `id`, `score` are declared *outside* the loop. When a field fails to parse, execution falls out of the `catch` and continues with the print/accumulate statements using whatever values those variables held from the *previous* line. The trigger is the second data line, `Brianna Ortiz,1002, 92`, whose score field has a leading space; `Integer.parseInt(" 92")` throws.

## Why the Program Behaved Incorrectly

For line 2, `name` is set to `"Brianna Ortiz"` and `id` to `1002` before `parseInt(" 92")` throws. The exception is caught and ignored; `score` still holds `88` from Alice's line. The program then prints Brianna with 88, adds 88 to the total, and counts her. The average becomes `(88 + 88 + 75 + 95) / 4 = 86.5` instead of `87.5`. Nothing on the console indicates that anything went wrong.

## The Concept This Illustrates

Exception *design*: a `catch` block must leave the program in a state that makes sense for the code that follows. "Catch and continue" only works if the rest of the iteration is skipped or the data is repaired. Two supporting habits: declare per-record variables inside the loop so stale values cannot leak across iterations, and normalize input (`trim()`) before parsing, because real data files have stray whitespace.

## The Correction

```java
// before
try {
    name = parts[0];
    id = Integer.parseInt(parts[1]);
    score = Integer.parseInt(parts[2]);
} catch (NumberFormatException e) {
}
System.out.printf(...); total += score; count++;

// after
try {
    String name = parts[0].trim();
    int id = Integer.parseInt(parts[1].trim());
    int score = Integer.parseInt(parts[2].trim());
    System.out.printf(...); total += score; count++;
} catch (NumberFormatException e) {
    System.out.println("Skipping unreadable line: " + line);
}
```

Either half alone is incomplete: `trim()` alone leaves the silent-stale-value hazard for the next messy file; fixing the `catch` alone makes the program *skip* Brianna, which is honest but does not match the Expected Behavior.

## Instructor Notes

- Some students edit `students.csv` to remove the space. Ask whether they can edit every file the program will ever read.
- Some add `continue;` in the `catch`. That is a legitimate fix for the stale-value problem; combine it with `trim()` and a message, and discuss why an *empty* catch is almost always a smell.
- Ask: "Where would a bad *id* (e.g., `10O2` with a letter O) be detected, and what would print?" Good prompt for tracing which assignments completed before the throw.
- Follow-up: what if a line has only two fields? (`ArrayIndexOutOfBoundsException` is not a `NumberFormatException`, so it escapes the inner catch.)
