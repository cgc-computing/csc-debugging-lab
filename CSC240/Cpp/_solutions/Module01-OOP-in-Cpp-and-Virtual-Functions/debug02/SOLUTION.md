# Solution: Shape Registry

**Course/Module/Activity:** CSC240 · Module 1 OOP in C++ and Virtual Functions · debug02
**Bug type(s):** logic, paradigm-specific (virtual dispatch during construction)
**Bug count:** 1

## Observed Behavior

Compiles cleanly. Both shapes register under the base-class name, even though `kind()` dispatches correctly afterwards:

```
Registered a generic shape
Registered a generic shape
circle registered as "generic shape", area 12.57
rectangle registered as "generic shape", area 12.00
```

## The Bug(s)

The `Shape` constructor calls a virtual function on the object under construction:

```cpp
Shape()
{
    registered_as_ = kind();
    std::cout << "Registered a " << registered_as_ << std::endl;
}
```

## Why the Program Behaved Incorrectly

Construction runs base-first. While `Shape::Shape()` executes, the `Circle` part of the object does not exist yet, so the object's dynamic type *is* `Shape`. C++ therefore dispatches `kind()` to `Shape::kind`, returning `"generic shape"`, and that string is stored permanently. After construction finishes, the dynamic type is `Circle` and `kind()` dispatches normally, which is why the final loop prints `circle` for the kind but the stale name for `registered_as()`.

## The Concept This Illustrates

Virtual dispatch depends on the dynamic type, and during a base-class constructor (or destructor) the dynamic type is the base class. Java does the opposite (calls the subclass override, which may then read fields the subclass has not initialized), so students bring the expectation that "constructors see the real class". The C++ rule is safer but means a base class cannot ask a derived class for information during construction; the information has to be *passed in*.

## The Correction

Pass the kind to the base constructor instead of asking for it:

```cpp
// before
Shape() { registered_as_ = kind(); ... }
explicit Circle(double radius) : Shape(), radius_(radius) {}

// after
explicit Shape(const std::string& kind_name) : registered_as_(kind_name) { ... }
explicit Circle(double radius) : Shape("circle"), radius_(radius) {}
```

## Instructor Notes

- Students often try to "fix" it by making `kind()` pure virtual. Then the call in the constructor is undefined behavior and clang typically emits a "pure virtual method called" runtime abort; a useful demonstration if time allows.
- Another attempt: move the `registered_as_ = kind()` line into each *derived* constructor body. It works but duplicates the registration logic; ask which design keeps the "register once" promise in one place.
- A two-phase design (`shape.register()` called by `main` after construction) is also valid; discuss why it is fragile (easy to forget the call).
- Note there is no initializer-list order issue here; the base class is always initialized first regardless of where `Shape(...)` appears in the derived initializer list.
