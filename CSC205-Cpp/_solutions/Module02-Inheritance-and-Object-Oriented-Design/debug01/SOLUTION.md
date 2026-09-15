# Solution: Employee and Manager Pay

**Course/Module/Activity:** CSC205 · Module 2 Inheritance and Object-Oriented Design · debug01
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

```
Employee Alice ($20/hr): $800
Manager Bob ($35/hr): $800
Manager Cara ($30/hr): $600
```

Managers show the correct hourly rate but are paid at the base $20 rate.

## The Bug(s)

`Employee::Employee` computes and stores the pay in the constructor body:

```cpp
Employee(const string& employeeName, int hours)
    : name(employeeName), hoursWorked(hours) {
    weeklyPay = hoursWorked * hourlyRate();   // virtual call during base construction
}
```

## Why the Program Behaved Incorrectly

When a `Manager` is created, the `Employee` base sub-object is constructed first. While the base constructor runs, the object's dynamic type *is* `Employee` — the `Manager` part (including `rateBonus`) does not exist yet. C++ therefore dispatches `hourlyRate()` to `Employee::hourlyRate`, which returns 20.0, and that value is frozen into `weeklyPay`. Later, `printPay` calls `hourlyRate()` on a fully constructed `Manager`, so the *rate* prints correctly, but `getPay()` just returns the stale stored number.

This is well-defined behavior in C++ (unlike Java, where the same call would reach the subclass override and read an uninitialized field), which is why the output is consistent and not garbage.

## The Concept This Illustrates

Construction order and dynamic dispatch. During a base-class constructor, virtual calls resolve to the base-class version. Storing a derived-dependent computation in the base constructor is a design mistake; either compute it on demand or let the most-derived class trigger the calculation after construction completes.

## The Correction

```cpp
// before
Employee(...) : name(employeeName), hoursWorked(hours) {
    weeklyPay = hoursWorked * hourlyRate();
}
double getPay() const { return weeklyPay; }

// after
Employee(...) : name(employeeName), hoursWorked(hours) {}
double getPay() const { return hoursWorked * hourlyRate(); }
```

(The `weeklyPay` member is removed.)

## Instructor Notes

- A common partial fix is recomputing `weeklyPay` in the `Manager` constructor body. It works for this program but duplicates the formula in every subclass; ask what happens when a third subclass is added and someone forgets.
- Some students propose making `hourlyRate()` non-virtual "so it is consistent." Have them predict the rate line in the output if they do that.
- Good follow-up: "Java would run the override here — why is that *worse*?" (It would read `rateBonus` before it is initialized.) Contrast the two languages' rules.
- Watch for students who add `virtual` to the constructor; constructors cannot be virtual, and the error message is a good discussion point.
