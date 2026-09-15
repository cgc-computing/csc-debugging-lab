# Solution: Course Roster

**Course/Module/Activity:** CSC110 · Module 8 Designing Classes · debug01
**Bug type(s):** conceptual/design (object copied by value)
**Bug count:** 1

## Observed Behavior

All three names are read, but the roster stays empty:

```
CSC110 - Introduction to C++
Enrolled: 0
Roster:
```

## The Bug(s)

`course_roster.cpp`, class `Course`:

```cpp
Roster getRoster() { return roster; }
```

`getRoster` returns the roster *by value* — a copy. `cpp.getRoster().add(name)` adds the name
to a temporary copy, which is destroyed at the end of the statement. The `Roster` inside the
`Course` is never modified.

## Why the Program Behaved Incorrectly

In C++, objects are values. Returning `roster` from a function whose return type is `Roster`
constructs a brand-new `Roster` initialized from the member. Each loop iteration therefore
creates a fresh copy (count 0, empty names), adds one name to it, and throws it away. The final
three `getRoster()` calls also each return fresh copies of the still-empty member.

## The Concept This Illustrates

Aggregation in C++ means the containing object *owns* the contained object as a value, and any
access path must not silently copy it. Students coming from Java expect `getRoster()` to return a
reference to "the" roster (as a Java getter would). In C++ the return type decides: `Roster`
copies, `Roster&` refers to the member itself. The design question — should `main` reach in and
modify the roster at all, or should `Course` offer `enroll(name)`? — is the Module 8 theme.

## The Correction

```cpp
// before
Roster getRoster() { return roster; }

// after
Roster& getRoster() { return roster; }
```

A better design alternative (also accepted) adds a method to `Course` and leaves the getter alone:

```cpp
void enroll(string name) { roster.add(name); }
// main:  cpp.enroll(name);
```

## Instructor Notes

- Ask students to add a `cout` inside `Roster::add` printing `count`; seeing `1, 1, 1` instead of
  `1, 2, 3` makes the "new copy each time" mechanism concrete.
- Students who choose the `enroll` design should still be asked why the original code failed —
  otherwise they will write the same by-value getter in their next project.
- Follow-up: is exposing a non-const reference to a private member good encapsulation? Compare
  with `const Roster& getRoster() const` for reading plus `enroll` for writing.
