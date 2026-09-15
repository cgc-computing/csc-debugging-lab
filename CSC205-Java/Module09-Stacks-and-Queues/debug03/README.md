# Balanced Brackets Checker

**Course:** CSC205 &nbsp;|&nbsp; **Module 9:** Stacks and Queues &nbsp;|&nbsp; **Activity:** debug03
**Language:** Java 17+

## Goal

`isBalanced(text)` uses a hand-built `CharStack` to decide whether every opening bracket `(`, `[`, `{` in `text` is closed by the matching closing bracket in the correct nesting order. Other characters are ignored. `main` runs the checker on several strings.

## Expected Behavior

```
"(a + b) * [c]"  balanced
"{[()]}"         balanced
"[(])"           NOT balanced
"((a)"           NOT balanced
")("             NOT balanced
""               balanced
```

## How to Run

```bash
javac *.java
java BracketChecker
```

## Your Task

Run the program and compare its output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. `CharStack` is correct; concentrate on how `isBalanced` uses it.

## Think About

- What should be true about the stack at the moment a closing bracket is encountered? What if it is not true?
- When the loop finishes without returning, what should be true about the stack for the string to count as balanced?
- List the three different ways a string can fail to be balanced. Which ones does the current code detect?
