# Solution: Star Box

**Course/Module/Activity:** CSC110 · Module 5 Control Structures: Loops · debug02
**Bug type(s):** logic (syntax-shaped: the program compiles, but the syntax does not mean what it looks like)
**Bug count:** 1

## Observed Behavior

Each row contains a single star regardless of the requested width:

```
Rows: 3
Columns: 5

*
*
*

Drew a 3 x 5 box.
```

## The Bug(s)

`StarBox.java`, in `main`, a stray semicolon terminates the inner `for` statement:

```java
for (int col = 1; col <= columns; col++);
{
    System.out.print("*");
}
```

## Why the Program Behaved Incorrectly

The `;` right after the `for (...)` header is an *empty statement*, and that empty statement is the loop's entire body. The loop spins `columns` times doing nothing. The block `{ System.out.print("*"); }` that follows is a free-standing block, not attached to any loop, so it executes exactly once per row. The program is syntactically valid, which is why the compiler says nothing.

## The Concept This Illustrates

A loop header controls exactly *one* statement: the one immediately after it (a block counts as one statement). Students who habitually end lines with semicolons can accidentally give a loop an empty body. Indentation and braces express intent to humans but mean nothing to the compiler.

## The Correction

```java
// before
for (int col = 1; col <= columns; col++);
{

// after
for (int col = 1; col <= columns; col++) {
```

## Instructor Notes

- Students often stare at this for a long time because the code "looks right." Encourage them to ask what the compiler sees rather than what the indentation implies.
- The same mistake with `while (...) ;` produces an infinite loop; ask students why the `for` version does not hang.
- `javac -Xlint:empty` would warn about the empty statement; showing this is a good excuse to mention compiler warnings.
- Adopting the habit of always writing the opening brace on the same line as the loop header makes this mistake almost impossible.
