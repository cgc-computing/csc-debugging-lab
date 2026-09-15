# Solution: Staff Payroll

**Course/Module/Activity:** CSC240 · Module 1 OOP in C++ and Virtual Functions · debug01
**Bug type(s):** logic, paradigm-specific (static vs dynamic dispatch)
**Bug count:** 1

## Observed Behavior

Compiles cleanly with `-Wall`. Titles are right, pay is wrong for the two derived types:

```
Employee Priya Shah: 5000.00
Manager Tom Reyes: 7500.00
Intern Lee Chen: 0.00
Total monthly payroll: 12500.00
```

## The Bug(s)

`Employee::monthly_pay` is not declared `virtual`:

```cpp
double monthly_pay() const { return annual_salary_ / 12.0; }
```

`Manager::monthly_pay` and `Intern::monthly_pay` therefore *hide* the base function rather than override it.

## Why the Program Behaved Incorrectly

`e` has static type `Employee*`. For a non-virtual member function the compiler binds the call at compile time based on that static type, so `e->monthly_pay()` always runs `Employee::monthly_pay`, which returns `annual_salary_ / 12`. For the manager that omits the bonus (90000/12 = 7500). The intern was constructed with an annual salary of 0.0, so the base version returns 0. `title()` *is* virtual, which is why that column dispatches correctly.

## The Concept This Illustrates

C++ member functions are non-virtual by default; dynamic dispatch through a base pointer or reference happens only for functions the base class marks `virtual`. Java students assume the runtime type always wins. This example puts a virtual and a non-virtual function side by side so students can see that the *declaration in the base class* is what decides.

## The Correction

```cpp
// before (Employee)
double monthly_pay() const { return annual_salary_ / 12.0; }

// after
virtual double monthly_pay() const { return annual_salary_ / 12.0; }
```

The derived versions are also marked `override` in the corrected file, which is how the compiler would have caught this: `override` on a function that does not override anything is an error.

## Instructor Notes

- Ask students to add `override` to `Manager::monthly_pay` *before* fixing the base class and read the error. That is the habit to build.
- Some students mark the *derived* functions `virtual` but not the base. That compiles and changes nothing; good moment to ask where virtual-ness has to be introduced.
- Others will try to fix it by casting or by storing `Manager` objects directly. Ask why that defeats the purpose of the array of `Employee*`.
- The base class already has a `virtual` destructor and `main` deletes through base pointers; that is correct and sets up the Module 1 debug03 discussion.
