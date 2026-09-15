# Solution: Duplicate Student Checker

**Course/Module/Activity:** CSC110 · Module 8 Designing Classes · debug02
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

Identical records are reported as different:

```
Record A: Ada Lovelace (#1815)
Record B: Ada Lovelace (#1815)
These records describe DIFFERENT students.
```

## The Bug(s)

`Student.java`, in `equals`:

```java
return name == other.name && id == other.id;
```

The names are compared with `==`, which compares references, not contents.

## Why the Program Behaved Incorrectly

Each call to `keyboard.nextLine()` creates a brand-new `String` object. The two names have identical characters but are two distinct objects at different addresses, so `name == other.name` is `false`. The `id` comparison is fine because `int` is a primitive and `==` compares values. Because the `&&` fails on the first operand, `equals` returns `false`.

## The Concept This Illustrates

Reference equality (`==`) versus value equality (`.equals`). When writing a class's own `equals`, every object-typed field must be compared with its own `equals` method; only primitives use `==`. The bug is especially sneaky because comparing string *literals* with `==` often appears to work (the compiler pools identical literals), which is exactly why the sample input comes from the keyboard.

## The Correction

```java
// before
return name == other.name && id == other.id;

// after
return name.equals(other.name) && id == other.id;
```

## Instructor Notes

- Demonstrate the sneakiness: in a scratch file, `"Ada" == "Ada"` is `true` while `new String("Ada") == "Ada"` is `false`. Ask why this makes `==` on strings a bug even when it "works."
- Some students will change the tester to compare `a.getName().equals(b.getName())` directly and skip `equals`. Redirect: the class's `equals` is the thing that must be right, because other code (and later, collections) will call it.
- If `name` could be `null`, `name.equals(...)` throws; `java.util.Objects.equals(name, other.name)` handles that. Mention only if asked — it is beyond the module.
- Optional: point out that `equals` and `hashCode` should be overridden together, as a preview for Module 10+ collections.
