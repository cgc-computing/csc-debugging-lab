# Solution: Sum of Valid Entries

**Course/Module/Activity:** CSC110 · Module 13 Exceptions · debug01
**Bug type(s):** conceptual/design, logic
**Bug count:** 1

## Observed Behavior

Only one bad entry is reported and every number after it is lost:

```
Enter whole numbers separated by spaces: 12 7 abc 30 x 5
  Skipping invalid entry: For input string: "abc"

Sum of valid entries: 19
Entries skipped:      1
```

## The Bug(s)

`NumberSummer.java`, in `main`: the `try`/`catch` wraps the entire `for` loop instead of the body of one iteration.

```java
try {
    for (int i = 0; i < tokens.length; i++) {
        int value = Integer.parseInt(tokens[i]);
        sum += value;
    }
} catch (NumberFormatException e) {
    ...
}
```

## Why the Program Behaved Incorrectly

When `parseInt("abc")` throws, control leaves the `try` block immediately — and the loop is *inside* that block, so the loop is abandoned along with it. The `catch` runs once, and then execution continues after the whole `try`/`catch`, straight to the summary. The tokens `30`, `x`, and `5` are never examined. The sum is 12 + 7 = 19 and only one entry is counted as skipped.

## The Concept This Illustrates

The placement of a `try` block defines the *scope of recovery*. Wrapping a whole loop means "if anything goes wrong, give up on the loop"; wrapping the body means "if this one item goes wrong, handle it and go on to the next." Students often put `try` at the outermost point that makes the compiler happy without thinking about where they want execution to resume.

## The Correction

```java
// after
for (int i = 0; i < tokens.length; i++) {
    try {
        int value = Integer.parseInt(tokens[i]);
        sum += value;
    } catch (NumberFormatException e) {
        System.out.println("  Skipping invalid entry: " + e.getMessage());
        skipped++;
    }
}
```

## Instructor Notes

- Ask students to point at the exact statement where execution resumes after the `catch` in each version. Drawing an arrow on paper is more convincing than talking.
- Some students try to avoid exceptions altogether with a manual digit check on each token. It works for this input; ask about `"-4"` or `"+7"` and whether re-implementing `parseInt`'s rules is a good idea.
- A `continue` inside the `catch` is unnecessary (the loop continues anyway) but harmless; ask why.
- Contrast: when *would* you want the `try` around the whole loop? (When one bad item makes the entire result meaningless.)
