# Solution: Recursive Vowel Counter

**Course/Module/Activity:** CSC205 · Module 5 Recursion and Analysis of Algorithms · debug02
**Bug type(s):** logic
**Bug count:** 1

## Observed Behavior

```
programming has 1 vowel(s)
rhythm has 0 vowel(s)
Education has 1 vowel(s)
aeiou has 1 vowel(s)
recursion has 1 vowel(s)
```

Every word with at least one vowel reports exactly 1.

## The Bug(s)

The recursive step does not combine the current character's contribution with the result of the recursive call:

```cpp
return isVowel(s[i]) ? 1 : 0 + countVowels(s, i + 1);
```

Because `+` binds tighter than `?:`, this parses as `isVowel(s[i]) ? 1 : (0 + countVowels(s, i + 1))`.

## Why the Program Behaved Incorrectly

For a consonant, the expression evaluates the recursive call and returns its result — fine. For a vowel, it returns the constant `1` and *never makes the recursive call*, so the rest of the string is ignored. The count therefore becomes 1 at the first vowel encountered and 0 if there is none. "rhythm" is the one case that comes out right, which is a useful clue: the bug only shows when the "current element" branch is taken.

## The Concept This Illustrates

A recursive definition has two parts: what *this* step contributes and what the recursion on the *rest* contributes, and the answer is their combination. Dropping the recursive result on one branch is the most common recursion logic error, and here it is hidden by operator precedence — the author *intended* "(1 or 0) + rest" and wrote something that reads that way. Recursion bugs often look like arithmetic typos; the fix is to make the structure explicit with parentheses (or an `if`).

## The Correction

```cpp
// before
return isVowel(s[i]) ? 1 : 0 + countVowels(s, i + 1);
// after
return (isVowel(s[i]) ? 1 : 0) + countVowels(s, i + 1);
```

## Instructor Notes

- Many students spot "vowel branch returns 1" and rewrite the function as an `if/else` with `1 + countVowels(...)` and `countVowels(...)`. That is a perfectly good fix; make sure they can still explain why the original one-liner failed, since the precedence trap will bite them again elsewhere.
- Ask students to predict the output for `"rhythm"` *before* running the buggy version; the fact that it is correct is a nice example of a test that passes for the wrong reason.
- Follow-up: rewrite the function to recurse on a substring (`s.substr(1)`) and discuss the cost — every call copies the string, turning O(n) into O(n²). This sets up the analysis theme of debug03.
