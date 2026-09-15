# Solution: Name Tag Formatter

**Course/Module/Activity:** CSC110 · Module 3 Using Classes and Objects · debug01
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

The full name on the tag stays in lowercase; everything else is right:

```
HELLO, my name is
   ada lovelace
Initials: AL
Name length: 12 characters
```

## The Bug(s)

`NameFormatter.java`, in `main`:

```java
String fullName = first + " " + last;
fullName.toUpperCase();
```

The result of `toUpperCase()` is discarded; `fullName` is never changed.

## Why the Program Behaved Incorrectly

`String` objects are immutable. `toUpperCase()` does not modify the string it is called on; it builds and *returns* a new string. The statement `fullName.toUpperCase();` computes `"ADA LOVELACE"` and throws it away, so `fullName` still refers to `"ada lovelace"` when it is printed. The initials line works because there the returned string is used immediately (`first.toUpperCase().charAt(0)`).

## The Concept This Illustrates

Method calls on objects return values that must be captured. Students often carry a mental model of "the method changes the variable," which is wrong for immutable `String` and for many library methods generally. The contrast with the working initials line is deliberate.

## The Correction

```java
// before
fullName.toUpperCase();

// after
fullName = fullName.toUpperCase();
```

## Instructor Notes

- Ask students to predict `Name length:` before and after the fix (unchanged, 12). Why doesn't the length change even though the string was "changed"?
- Some will fix it by writing `String fullName = (first + " " + last).toUpperCase();` — correct.
- Others may uppercase `first` and `last` separately before building `fullName`; fine, but ask them to spot the same pattern (assignment of the return value) in their fix.
- Good follow-up: name two other `String` methods that return a new string rather than modifying the original (`trim`, `replace`, `substring`).
