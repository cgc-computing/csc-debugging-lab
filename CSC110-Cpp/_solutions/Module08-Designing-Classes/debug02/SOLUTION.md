# Solution: Student Record Summary

**Course/Module/Activity:** CSC110 · Module 8 Designing Classes · debug02
**Bug type(s):** syntax/compile (const correctness)
**Bug count:** 1

## Observed Behavior

The program does not compile:

```
student_record.cpp:36:26: error: 'this' argument to member function 'getGpa' has type 'const Student', but function is not marked const
   36 |          << " - GPA " << s.getGpa() << endl;
      |                          ^
student_record.cpp:23:12: note: 'getGpa' declared here
```

## The Bug(s)

`student_record.cpp`, class `Student`:

```cpp
double getGpa() { return gpa; }
```

`getGpa` is the only getter not declared `const`. `printSummary` receives a `const Student&`, and
a non-`const` member function cannot be called on a `const` object.

## Why the Program Behaved Incorrectly

A member function without `const` is allowed to modify the object, so the compiler must assume it
might. Calling it through a `const` reference would break the promise that `s` will not change,
so the call is rejected at compile time. `getName` and `getIdNumber` are marked `const`, which is
why those two calls in the same expression are accepted.

## The Concept This Illustrates

Const correctness is part of designing a class's interface: every method that does not change
the object should say so with a trailing `const`, so that callers holding `const` objects or
`const` references (the idiomatic way to pass objects to functions in C++) can use it. A getter
that forgets `const` is unusable in exactly the places where getters are needed most.

## The Correction

```cpp
// before
double getGpa() { return gpa; }

// after
double getGpa() const { return gpa; }
```

## Instructor Notes

- The "fix" students reach for first is removing `const` from `printSummary`'s parameter (or
  passing by value). The README forbids it; ask why passing a large object by value would be a
  poor design, and why a print function should never be able to change what it prints.
- Ask whether `setGpa` should be `const`. (No — it modifies `gpa`; adding `const` would produce a
  different compile error. Let them try it.)
- Follow-up: what is the rule of thumb? Every method that does not modify the object gets
  `const`. Have students audit `Roster`/`Course` from debug01 with that rule.
