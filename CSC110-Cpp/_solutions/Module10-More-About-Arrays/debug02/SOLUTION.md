# Solution: Class Roster With a Vector

**Course/Module/Activity:** CSC110 · Module 10 More About Arrays · debug02
**Bug type(s):** logic (vector sizing: pre-sized then `push_back`)
**Bug count:** 1

## Observed Behavior

The roster is twice as long as it should be, padded with blank students, and the average is
halved:

```
Roster (6 students)
1.  - 0
2.  - 0
3.  - 0
4. Ana - 90
5. Ben - 84
6. Chloe - 96
Class average: 45
```

## The Bug(s)

`class_roster.cpp`, `main`:

```cpp
vector<Student> roster(count);
...
roster.push_back(Student(name, score));
```

The vector is constructed with `count` default-constructed `Student`s already in it, and then
each real student is *appended* after them.

## Why the Program Behaved Incorrectly

`vector<Student> roster(count)` is not a capacity hint; it creates a vector whose `size()` is
already `count`, filled by calling `Student()` `count` times (name `""`, score `0`). `push_back`
always grows the vector by one and places the new element at the end. After the loop, `size()` is
`2 * count`: three placeholders followed by the three real students. The average divides by
`roster.size()` (6), so `270 / 6 = 45`.

## The Concept This Illustrates

A `vector` differs from a raw array in that its size is dynamic and is *changed* by `push_back`.
Two consistent idioms exist: start empty and `push_back`, or pre-size and assign with
`roster[i] = ...`. Mixing them doubles the data. Students arriving from fixed-size arrays (where
declaring the size is mandatory) naturally write the sized constructor out of habit and then use
`push_back` because that is "how you add to a vector."

## The Correction

```cpp
// before
vector<Student> roster(count);
...
roster.push_back(Student(name, score));

// after (idiom 1: start empty, append)
vector<Student> roster;
...
roster.push_back(Student(name, score));

// alternative (idiom 2: pre-size, assign by index)
vector<Student> roster(count);
...
roster[i] = Student(name, score);
```

## Instructor Notes

- Ask students to print `roster.size()` immediately after the declaration; seeing `3` before any
  input is read makes the mechanism obvious.
- Students who pick idiom 2 should be asked what would happen if `count` were 0 or if the loop
  ever ran one iteration too many (`roster[count]` is out of bounds — no exception with
  `operator[]`; `at()` would throw, a preview of Module 13).
- Mention `reserve(count)` as the actual "capacity hint" for students who ask; it does not change
  `size()`.
- Note the default constructor is needed only by the sized constructor; with idiom 1 it could be
  removed. Ask why.
