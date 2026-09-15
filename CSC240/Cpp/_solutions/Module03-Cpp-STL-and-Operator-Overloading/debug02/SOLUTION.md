# Solution: Money

**Course/Module/Activity:** CSC240 · Module 3 C++ STL and Operator Overloading · debug02
**Bug type(s):** syntax/compile (operator declared as the wrong kind of function), logic (operator with a side effect)
**Bug count:** 2 (related: both operators fail to behave like their built-in counterparts)

## Observed Behavior

The program does not compile. Every `std::cout << <Money>` line fails:

```
money.cpp:57:34: error: invalid operands to binary expression ('basic_ostream<char, std::char_traits<char>>' and 'Money')
   57 |     std::cout << "Coffee:      " << coffee << std::endl;
      |     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^  ~~~~~~
...
6 errors generated.
```

Once `operator<<` is made a non-member (bug 1), the program compiles and runs, but `coffee` and `subtotal` have been changed by the additions and "two coffees" is priced from the inflated coffee:

```
Coffee:      $6.25
Bagel:       $2.50
Subtotal:    $6.72
Tax:         $0.47
Total:       $6.72
Two coffees: $12.50
Two coffees cost at least as much as the whole order.
```

(The final message happens to match the expected one, for the wrong reason: $12.50 is not less than $6.72.)

## The Bug(s)

1. `operator<<` is declared as a **member** of `Money`:
   ```cpp
   std::ostream& operator<<(std::ostream& out) const
   ```
   A member binary operator takes `*this` as its *left* operand. This declaration therefore defines `money << out`, not `out << money`. For `std::cout << coffee` the compiler looks for a member of `std::ostream` or a free function taking `(std::ostream&, Money)`; neither exists.

2. `operator+` **modifies the left operand** and is not `const`:
   ```cpp
   Money operator+(const Money& other)
   {
       cents_ += other.cents_;
       return *this;
   }
   ```
   `coffee + bagel` adds the bagel *into* `coffee` and then returns a copy. `subtotal + tax` then adds the tax into `subtotal`, which is a copy of the mutated `coffee` object, so `coffee`, `subtotal`, and `total` all end up equal to the total.

## Why the Program Behaved Incorrectly

For bug 1 the compiler is simply right: there is no `operator<<(std::ostream&, Money)`. For bug 2, trace the cents: `coffee = 375`, `bagel = 250`, `tax = 47`.

| statement | effect on `*this` | value returned |
|---|---|---|
| `coffee + bagel` | `coffee` becomes 625 | copy of `coffee` (625) → `subtotal` |
| `subtotal + tax` | `subtotal` becomes 672 | copy of `subtotal` (672) → `total` |
| `coffee * 2` | none (`operator*` is correct) | 1250 → `two_coffees` |

So `coffee` prints as $6.25, `subtotal` as $6.72 (it should be $6.25), and `two_coffees` as $12.50 because it was doubled from the already-inflated coffee. Only `bagel`, `tax`, and `total` are right.

## The Concept This Illustrates

Overloaded operators are just functions with a special calling syntax, and two conventions govern them. First, **operand position is fixed by the operator**: for a member `a OP b`, `a` is `*this`. When the left operand is not your class (a stream), the operator cannot be a member; it must be a free function (often a `friend`). Second, **overloaded operators should mean what the built-in ones mean**: `a + b` yields a new value and leaves `a` and `b` alone; only `+=` mutates. Java students are used to operator semantics being fixed by the language; in C++ the class author is responsible for keeping them sane.

## The Correction

```cpp
// before (member)
std::ostream& operator<<(std::ostream& out) const { ... cents_ ... }

// after (free function, uses the public accessor)
std::ostream& operator<<(std::ostream& out, const Money& amount)
{
    long dollars = amount.cents() / 100;
    long cents = amount.cents() % 100;
    out << "$" << dollars << "." << (cents < 10 ? "0" : "") << cents;
    return out;
}

// before
Money operator+(const Money& other)
{
    cents_ += other.cents_;
    return *this;
}

// after
Money operator+(const Money& other) const
{
    Money result;
    result.cents_ = cents_ + other.cents_;
    return result;
}
```

## Instructor Notes

- Students frequently try to fix the compile error by rewriting `main` as `coffee << std::cout`. It compiles and prints, but the README forbids changing `main`, and the point is that users of a class expect the standard stream syntax.
- The `friend` keyword is the other standard route (`friend std::ostream& operator<<(std::ostream&, const Money&);` inside the class, giving the free function access to `cents_`). Either is acceptable; ask what `friend` buys here versus using the public `cents()` accessor.
- For bug 2, some students notice only that `operator+` is not `const` and add `const`, at which point `cents_ += ...` fails to compile inside a const member. That compile error is a productive one: it points straight at the mutation.
- Compare `operator+` (broken) with `operator*` (correct, builds a `result`). Ask students to describe the difference in one sentence before they write the fix.
- Follow-up: implement `operator+=` that *does* mutate and returns `Money&`, then define `+` in terms of it. That is the idiomatic pattern.
