# Solution: Employees and Managers

**Course/Module/Activity:** CSC110 · Module 11 Inheritance · debug01
**Bug type(s):** logic (base-class constructor not invoked with arguments)
**Bug count:** 1

## Observed Behavior

The manager's inherited fields hold the default values:

```
Ana Ruiz earns $52000
unassigned manages Engineering and earns $0
Manager's name on file: unassigned
```

The program compiles with no warnings.

## The Bug(s)

`employee_manager.cpp`, `Manager::Manager`:

```cpp
Manager(string name, double salary, string department)
    : department(department) {
}
```

The initializer list initializes only `department`. It never calls `Employee(name, salary)`, so
the `name` and `salary` parameters are accepted and ignored.

## Why the Program Behaved Incorrectly

Every derived-class constructor must construct its base-class part first. If the initializer list
does not name a base constructor, C++ calls the base's *default* constructor. `Employee()` sets
`name = "unassigned"` and `salary = 0.0`. The `Manager` constructor cannot fix this afterwards
because `name` and `salary` are private to `Employee` (and it does not try). Only `department`
receives a real value.

## The Concept This Illustrates

Constructor chaining in inheritance: the derived class is responsible for passing the base class's
data up to the base constructor through the member initializer list (`: Employee(name, salary)`).
Students often assume that because `Manager` "is an" `Employee`, the parameters with matching names
somehow reach the base fields automatically, or that the base constructor runs with "the same
arguments." Java students expect an implicit `super(...)`; C++ (like Java) only inserts the
no-argument call.

## The Correction

```cpp
// before
Manager(string name, double salary, string department)
    : department(department) {
}

// after
Manager(string name, double salary, string department)
    : Employee(name, salary), department(department) {
}
```

## Instructor Notes

- Ask students to delete `Employee()` and recompile. The error ("constructor for 'Manager' must
  explicitly initialize the base class 'Employee' which does not have a default constructor")
  is a great illustration of what the compiler was silently doing.
- Some students try `this->name = name;` inside the `Manager` body; the private-access error leads
  to a good conversation about `protected` vs. passing data upward.
- Note the print output shows `52000` without decimals because of default stream formatting; that
  is not a bug.
- Follow-up: which constructor body runs first, `Employee`'s or `Manager`'s? Add a `cout` to
  each to demonstrate.
