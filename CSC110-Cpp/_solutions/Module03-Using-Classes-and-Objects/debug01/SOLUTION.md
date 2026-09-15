# Solution: Name Formatter

**Course/Module/Activity:** CSC110 · Module 3 Using Classes and Objects · debug01
**Bug type(s):** conceptual/design (library API misunderstanding)
**Bug count:** 1

## Observed Behavior

With input `Ada King Lovelace`:

```
First name:  Ada
Middle name: King Lov
Last name:   Lovelace
Formal:      Lovelace, Ada King Lov
Initials:    AKL
```

The middle name spills into the last name.

## The Bug(s)

`name_formatter.cpp`, `main`:

```cpp
string middle = fullName.substr(firstSpace + 1, lastSpace);
```

The second argument of `substr` is a *length*, not an ending index. The student passed the
position of the last space (`8`) as if `substr(start, end)` were the signature.

## Why the Program Behaved Incorrectly

For `Ada King Lovelace`, `firstSpace = 3` and `lastSpace = 8`. `substr(4, 8)` returns eight
characters starting at index 4: `K i n g ' ' L o v` → `"King Lov"`. The first name happens to work
because it starts at 0, where start index and length coincide (`substr(0, 3)`), and the last name
uses the one-argument form, which reads to the end. Only the middle name exposes the mistake.

## The Concept This Illustrates

Using a library class means reading its documentation carefully: `std::string::substr(pos, count)`
takes a starting position and a *count*. Students who know Java's `substring(begin, end)` or
Python slicing import the wrong signature. The activity also shows why a call can appear to work
in one place (start index 0) and fail in another.

## The Correction

```cpp
// before
string middle = fullName.substr(firstSpace + 1, lastSpace);

// after
string middle = fullName.substr(firstSpace + 1, lastSpace - firstSpace - 1);
```

## Instructor Notes

- Some students will "fix" the symptom by trimming the result (`substr(..., 4)`) hard-coded for the
  sample name; ask them to try `Grace Brewster Hopper`.
- Ask why `substr(0, firstSpace)` is correct even though it looks like it uses the same pattern.
- The program stores `find` results in `int`; mention that `std::string::npos`/`size_t` is the
  precise type, but that is not the bug here.
