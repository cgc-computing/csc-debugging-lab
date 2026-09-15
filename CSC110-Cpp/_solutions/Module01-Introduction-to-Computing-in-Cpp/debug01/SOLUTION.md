# Solution: Quote of the Day Printer

**Course/Module/Activity:** CSC110 · Module 1 Introduction to Computing in C++ · debug01
**Bug type(s):** logic
**Bug count:** 2 (the same misconception twice)

## Observed Behavior

The banner prints correctly, but the quotation and attribution run together on one line:

```
===============================
       Quote of the Day
===============================
The most dangerous phrase in the language is,'We've always done it this way.'        -- Grace Hopper

Have a great lab session!
```

## The Bug(s)

`quote_printer.cpp`, `main`, the two statements that print the quotation:

```cpp
cout << "The most dangerous phrase in the language is,";
cout << "'We've always done it this way.'";
```

Neither statement ends its line with `endl` (or `"\n"`), so the next output continues on the same line.

## Why the Program Behaved Incorrectly

`cout <<` writes characters to the output stream and nothing more. Ending a *statement* with `;`
does not end an output *line*. A line break appears only when the program explicitly sends one
(`endl` or `'\n'`). The third quotation statement does end with `endl`, which is why the blank
line and the closing message are positioned correctly.

## The Concept This Illustrates

Students coming from a "one statement = one line of output" mental model (or from Java's
`println`) expect each `cout` statement to produce its own line. In C++ the newline is data the
program must output, exactly like any other character.

## The Correction

```cpp
// before
cout << "The most dangerous phrase in the language is,";
cout << "'We've always done it this way.'";

// after
cout << "The most dangerous phrase in the language is," << endl;
cout << "'We've always done it this way.'" << endl;
```

## Instructor Notes

- Some students will add a single `endl` to only the first line; ask them to compare the output
  character by character against the Expected Behavior.
- Ask whether `"\n"` inside the string literal would also work, and what the difference between
  `endl` and `'\n'` is (flushing). At this level "both end the line" is a fine answer.
- A few students may try to merge everything into one long `cout` chain; that is acceptable if the
  output matches, but ask them to keep the structure readable.
