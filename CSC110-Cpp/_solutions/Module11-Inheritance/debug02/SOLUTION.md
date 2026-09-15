# Solution: Pet Sounds

**Course/Module/Activity:** CSC110 · Module 11 Inheritance · debug02
**Bug type(s):** conceptual/design (missing `virtual`; static vs. dynamic binding)
**Bug count:** 1

## Observed Behavior

Every pet makes the base-class sound:

```
Rex says ...
Luna says ...
Pet Rock says ...
```

The program compiles with no warnings.

## The Bug(s)

`pet_sounds.cpp`, class `Pet`:

```cpp
string speak() const { return "..."; }
```

`speak` is not declared `virtual`. `Dog::speak` and `Cat::speak` therefore *hide* the base
function rather than override it, and a call through a `Pet&` is bound to `Pet::speak` at compile
time.

## Why the Program Behaved Incorrectly

Inside `introduce`, `pet` has static type `const Pet&`. For a non-virtual member function, C++
resolves the call using the static type only: `pet.speak()` means `Pet::speak()` no matter what
object the reference actually refers to. The `Dog` and `Cat` versions exist but are never reached
through the reference. Calling `rex.speak()` directly in `main` *would* print `Woof!`, because
there the static type is `Dog`.

## The Concept This Illustrates

Polymorphism in C++ is opt-in. Only member functions declared `virtual` in the base class are
dispatched on the object's dynamic type when called through a base-class reference or pointer.
Students coming from Java (where every instance method is virtual) or who have only called methods
on objects directly (never through a base reference) do not see the need for the keyword until a
program like this one goes quiet.

## The Correction

```cpp
// before  (in Pet)
string speak() const { return "..."; }

// after   (in Pet)
virtual string speak() const { return "..."; }

// and, in Dog and Cat (recommended, not required):
string speak() const override { return "Woof!"; }
```

## Instructor Notes

- The `override` keyword is the safety net: with `virtual` still missing from the base, adding
  `override` in `Dog` produces a compile error ("only virtual member functions can be marked
  'override'"). Have students add it first and read the message.
- Some students "fix" this by changing `introduce` to take a `Dog&` and writing a second copy for
  `Cat&`. The README forbids it; ask what happens when a `Bird` class is added.
- Others try passing by value (`Pet pet`); it compiles, still prints `...`, and introduces object
  slicing — worth a brief mention as a preview of CSC205.
- Ask: should `getName` also be `virtual`? (No need — no subclass changes it. Discuss the cost and
  intent of `virtual`.)
