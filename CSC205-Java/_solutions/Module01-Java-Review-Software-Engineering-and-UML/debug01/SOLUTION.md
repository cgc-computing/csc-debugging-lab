# Solution: Course Roster Lookup

**Course/Module/Activity:** CSC205 · Module 1 Java Review, Software Engineering, and UML · debug01
**Bug type(s):** conceptual/design, logic
**Bug count:** 2

## Observed Behavior

The roster prints correctly, but the lookup for an enrolled student fails:

```
Course: CSC205 (3 students)
  Alice Chen (1001)
  Brianna Ortiz (1002)
  Carlos Diaz (1003)
Looking up Brianna Ortiz: not enrolled
Looking up Dmitri Volkov: not enrolled
```

The code also does not match the UML: `Student.name` is `public` and `getName()` is missing.

## The Bug(s)

1. `Student.java`: `public String name;` — the UML marks `name` as private (`-`) and lists a public `getName()` accessor, which the class does not provide. `Course.findStudent` reaches into the field directly (`students[i].name`).
2. `Course.java`, `findStudent`: `if (students[i].name == name)` compares two `String` references with `==` instead of `.equals(...)`.

## Why the Program Behaved Incorrectly

The roster names come from `rosterLine.split(",")` and the query names from a second `split` call. Each `split` creates fresh `String` objects, so `"Brianna Ortiz"` in the roster and `"Brianna Ortiz"` in the query list are two distinct objects with identical contents. `==` tests whether both references point at the same object, which they do not, so the loop never matches and `findStudent` returns `null`. (If the names had been written as literals in the source, string interning would have hidden the problem — which is exactly why this mistake survives casual testing.)

The public field is not a runtime failure but a design failure: the class advertises a private field and an accessor in its UML contract, and any client (like `Course`) that depends on the public field is coupled to an implementation detail the diagram says is hidden.

## The Concept This Illustrates

Two CSC110 review points that Module 1 formalizes: (a) UML visibility markers are a contract — `-` means callers go through the public interface, so `Course` should call `getName()`; (b) reference equality (`==`) versus value equality (`equals`) for objects, `String` in particular.

## The Correction

```java
// Student.java
private String name;
public String getName() { return name; }

// Course.java
if (students[i].getName().equals(name)) {
```

## Instructor Notes

- Some students will "fix" the lookup by calling `name.intern()` or by changing the data to literals. Ask them what happens when the names come from a file or from `Scanner`.
- Others will change only the `==` to `.equals` and leave `name` public. Point back at the diagram: the exercise is to make the code honor the design, not just to make the output match.
- Ask: "Which object should be the receiver of `equals` — the roster name or the query name? Does it matter if one of them could be `null`?"
- Worth mentioning `Objects.equals(a, b)` as the null-safe idiom, but do not require it.
