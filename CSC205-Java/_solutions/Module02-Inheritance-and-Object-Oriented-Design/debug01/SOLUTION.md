# Solution: Payroll With Manager Bonuses

**Course/Module/Activity:** CSC205 · Module 2 Inheritance and Object-Oriented Design · debug01
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

Managers are paid only their base salary; the bonus disappears:

```
Ana    $52,000.00
Ben    $70,000.00
Cleo   $81,000.00
Payroll total: $203,000.00
```

## The Bug(s)

`Employee.java`, constructor: `this.annualPay = computePay();` calls an overridable method from the superclass constructor and caches the result. `Manager.computePay()` reads `bonus`, which has not been assigned yet when the `Employee` constructor runs.

## Why the Program Behaved Incorrectly

`new Manager("Ben", 70000, 12000)` runs `super(name, baseSalary)` first. Inside the `Employee` constructor the object is already a `Manager`, so the dynamic dispatch of `computePay()` selects `Manager.computePay()`. That method returns `baseSalary + bonus`, but `bonus` is still at its default value `0.0` because `this.bonus = bonus;` in `Manager`'s constructor has not executed yet. The result `70000.0` is stored in `annualPay` and is never recomputed, so the bonus assigned a moment later is never reflected.

## The Concept This Illustrates

Constructor chaining and dynamic dispatch. Subclass fields are initialized only after the superclass constructor returns, yet virtual calls made from the superclass constructor already dispatch to subclass overrides. Calling an overridable method from a constructor is therefore a design hazard; either make the computation lazy (compute in the getter) or make the method `final`/`private`.

## The Correction

```java
// before (Employee.java)
private double annualPay;
public Employee(String name, double baseSalary) {
    this.name = name;
    this.baseSalary = baseSalary;
    this.annualPay = computePay();
}
public double getAnnualPay() { return annualPay; }

// after
public Employee(String name, double baseSalary) {
    this.name = name;
    this.baseSalary = baseSalary;
}
public double getAnnualPay() { return computePay(); }
```

## Instructor Notes

- A tempting "fix" is to have `Manager`'s constructor re-run the calculation (e.g., add a protected `recompute()` in `Employee` and call it after setting `bonus`). It works but keeps the fragile pattern; ask what happens when a third subclass forgets to call it.
- Another partial fix: move `bonus` to `Employee`. Ask whether every employee should carry a bonus field.
- Good trace question: add `System.out.println("bonus=" + bonus)` inside `Manager.computePay()` and run once; students see `bonus=0.0` printed during construction.
- Connects forward to Module 3: the same dispatch rule is what makes polymorphism work in the normal case.
