# Recursive Vowel Counter

**Course:** CSC205 &nbsp;|&nbsp; **Module 5:** Recursion and Analysis of Algorithms &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`countVowels` counts the vowels (a, e, i, o, u in either case) in a string recursively: look at one character, then recurse on the rest of the string.

## Expected Behavior

```
programming has 3 vowel(s)
rhythm has 0 vowel(s)
Education has 5 vowel(s)
aeiou has 5 vowel(s)
recursion has 4 vowel(s)
```

## How to Run

```bash
g++ -std=c++17 -Wall -o count_vowels count_vowels.cpp
./count_vowels
```
(on Windows: `count_vowels.exe` or `.\count_vowels.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. Keep the solution recursive.

## Think About

- In a recursive count, what two things must be combined to produce the answer for the whole string?
- Trace `countVowels("aeiou")` by hand. When the first character is a vowel, what value is returned, and does the rest of the string ever get examined?
- Without looking anything up, how do you think C++ groups `a ? b : c + d`? Now check your answer against a precedence table.
