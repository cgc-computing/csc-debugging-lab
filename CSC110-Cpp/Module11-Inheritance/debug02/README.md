# Pet Sounds

**Course:** CSC110 &nbsp;|&nbsp; **Module 11:** Inheritance &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

`Pet` is a base class whose `speak()` returns `"..."`. `Dog` and `Cat` inherit from `Pet` and
provide their own `speak()`. The function `introduce` takes any pet by reference and prints the
pet's name and sound. The program introduces a dog, a cat, and a plain pet.

## Expected Behavior

The program takes no input. A correct run prints:

```
Rex says Woof!
Luna says Meow.
Pet Rock says ...
```

## How to Run

```bash
g++ -std=c++17 -Wall -o pet_sounds pet_sounds.cpp
./pet_sounds
```

(on Windows: `pet_sounds.exe` or `.\pet_sounds.exe`)

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Keep `introduce` as a
single function that accepts a `const Pet&`; do not write one version per animal.

## Think About

- Inside `introduce`, what is the declared type of `pet`? What is the actual type of the object it refers to when `rex` is passed?
- Which `speak()` does the compiler choose, and *when* does it decide — while compiling, or while the program runs?
- What must a base class do to let a call through a base reference reach the derived class's version?
- Would `rex.speak()` called directly in `main` behave the same way? Why or why not?
