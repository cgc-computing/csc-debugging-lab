# Name Tag Formatter

**Course:** CSC110 &nbsp;|&nbsp; **Module 3:** Using Classes and Objects &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

The program reads a first name and a last name and prints a name tag. The full name on the tag must appear in all capital letters, followed by the person's initials and the length of the full name.

## Expected Behavior

With the input `ada` and `lovelace`:

```
First name: ada
Last name: lovelace

HELLO, my name is
   ADA LOVELACE
Initials: AL
Name length: 12 characters
```

## How to Run

```bash
javac NameFormatter.java
java NameFormatter
```

Type a first name and press Enter, then a last name and press Enter. Use `ada` and `lovelace` to reproduce the sample run.

## Your Task

Run the program with the sample names and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite the program; the structure is fine.

## Think About

- What does a `String` method such as `toUpperCase()` actually *do* to the object it is called on? What does it give back?
- The initials come out correctly capitalized. Compare how `toUpperCase()` is used on that line with how it is used elsewhere in the program.
- If you call a method and it returns a value, what happens to that value if you do nothing with it?
