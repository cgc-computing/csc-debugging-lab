# Solution: Shape Collection Areas

**Course/Module/Activity:** CSC205 · Module 3 Polymorphism and Interfaces · debug01
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

```
shape area = 0
shape area = 0
shape area = 0
Total area = 0
```

Every element behaves like a plain `Shape`.

## The Bug(s)

`main` declares `vector<Shape> shapes;` — a vector of `Shape` *objects* — and pushes `Rectangle`, `Circle`, and `Square` temporaries into it. Each `push_back` copy-constructs a `Shape` from the derived object, discarding everything that is not part of `Shape` (object slicing).

## Why the Program Behaved Incorrectly

A `vector<Shape>` allocates slots exactly the size of a `Shape`. Copying a `Circle` into such a slot invokes `Shape`'s copy constructor, which copies only the `Shape` part: the `radius`, the derived vtable pointer — everything that made it a `Circle` — is gone. The stored element's dynamic type is `Shape`, so `name()` and `area()` resolve to `Shape::name` and `Shape::area`. `virtual` and `override` are correct but irrelevant: there is no derived object left to dispatch to.

## The Concept This Illustrates

Polymorphism in C++ works only through pointers or references to the base type. Storing derived objects *by value* in a base-typed variable or container slices them. Students coming from Java expect a `List<Shape>` to hold "real" circles because Java references are implicit; in C++ that must be written explicitly (`Shape*`, `Shape&`, or a smart pointer).

## The Correction

```cpp
// before
vector<Shape> shapes;
shapes.push_back(Rectangle(3.0, 4.0));
...
cout << shapes[i].name() << ...

// after
vector<Shape*> shapes;
shapes.push_back(new Rectangle(3.0, 4.0));
...
cout << shapes[i]->name() << ...
// and delete each element before returning
```

`vector<unique_ptr<Shape>>` is an equally good fix if students know smart pointers.

## Instructor Notes

- Students frequently try to "fix" this by making `Shape` abstract (`= 0`). The program then fails to compile with "cannot allocate an object of abstract type" — which is a *good* outcome to discuss: the compiler is now telling them that a `vector<Shape>` never made sense.
- Ask students to add `cout << sizeof(Shape) << " " << sizeof(Circle)` to see the slicing concretely.
- Check that whoever switches to raw pointers also deletes them (the virtual destructor is already in place; ask why it matters).
- Follow-up: pass a `Circle` to `void show(Shape s)` versus `void show(const Shape& s)` and predict the output of each.
