# Solution: Payroll with Managers

**Course/Module/Activity:** CSC110 · Module 11 Inheritance · debug01
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

The manager's inherited fields hold the defaults:

```
Rosa Diaz earns $42,000.00
Unassigned earns $0.00 and manages Operations
Total payroll: $42,000.00
```

## The Bug(s)

`Manager.java`, constructor:

```java
public Manager(String name, double salary, String department) {
    this.department = department;
}
```

The `name` and `salary` parameters are never passed to the superclass.

## Why the Program Behaved Incorrectly

A subclass constructor must begin by running a superclass constructor. When none is named, Java inserts an implicit `super();`, which here calls `Employee()` — the no-argument constructor that sets `"Unassigned"` and `0.0`. The manager's own `name` and `salary` parameters are simply ignored, so the inherited fields keep those defaults. The program compiles only because `Employee` happens to have a no-arg constructor; without it, the compiler would have refused.

## The Concept This Illustrates

Constructor chaining and the role of `super(...)`: private superclass fields can be initialized only by the superclass's constructor, and the subclass must explicitly choose which one and pass the data along. Students often believe that declaring parameters with the same names as the base fields is enough.

## The Correction

```java
// before
public Manager(String name, double salary, String department) {
    this.department = department;
}

// after
public Manager(String name, double salary, String department) {
    super(name, salary);
    this.department = department;
}
```

## Instructor Notes

- A tempting wrong fix is `this.name = name;` in `Manager` — it does not compile because `name` is private in `Employee`. Use that error to explain why `super(...)` is the right tool rather than loosening `private`.
- Ask what would happen if the no-arg `Employee()` constructor were deleted (compile error in `Manager`: "constructor Employee cannot be applied"). Discuss why having a no-arg constructor "for convenience" hid this bug.
- Ask students to note that `super.toString()` in `Manager.toString()` was already correct — the output format was fine, only the data was missing.
