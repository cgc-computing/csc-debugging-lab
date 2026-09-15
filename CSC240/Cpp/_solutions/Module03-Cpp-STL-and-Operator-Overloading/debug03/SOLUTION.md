# Solution: Parts Inventory

**Course/Module/Activity:** CSC240 · Module 3 C++ STL and Operator Overloading · debug03
**Bug type(s):** logic, conceptual/design (STL operations whose names promise more than they do)
**Bug count:** 2 (related: both are library calls a Java programmer reads as "look up" / "remove" but which actually "insert" / "shift")

## Observed Behavior

Compiles with one warning that points straight at bug 2:

```
parts_inventory.cpp:28:5: warning: ignoring return value of function declared with 'nodiscard' attribute [-Wunused-result]
```

The yes/no answers are right, but the map has grown a phantom `gasket` entry and the order list still has five elements, with a stale tail:

```
bolt: in stock
gasket: not stocked
nut: in stock
Distinct parts tracked: 4
  bolt 120
  gasket 0
  nut 300
  washer 75
Pending orders (5): 102 117 130 0 130
```

## The Bug(s)

1. `in_stock` "checks" with `operator[]`:
   ```cpp
   return stock[part] > 0;
   ```
   `std::map::operator[]` **inserts** a value-initialized element (`0`) when the key is absent and returns a reference to it. Asking about `gasket` created `gasket -> 0`. (The non-`const` parameter was the giveaway: `operator[]` cannot be called on a `const` map.)

2. `drop_cancelled` calls `std::remove` and ignores its result:
   ```cpp
   std::remove(orders.begin(), orders.end(), 0);
   ```
   `std::remove` cannot change the vector's size; it only shifts the elements that are *not* equal to `0` toward the front and returns an iterator to the new logical end. The elements after that iterator are left over.

## Why the Program Behaved Incorrectly

Bug 1: on the `gasket` request, `stock["gasket"]` finds no such key, inserts `{"gasket", 0}`, and returns `0`; `0 > 0` is false so the answer is correct, but the side effect remains and `report_stock` shows four entries.

Bug 2: `std::remove` walks `{102, 0, 117, 0, 130}`, writing the keepers forward: position 0 ← 102, position 1 ← 117, position 2 ← 130. It returns `begin() + 3`. Positions 3 and 4 are never touched, so they still hold their old contents `0` and `130`. Because the vector's size is unchanged, `report_orders` prints all five. (Formally the elements past the returned iterator are "valid but unspecified"; for `int` they are, in practice, simply the old values.)

## The Concept This Illustrates

STL names describe what the operation does to the *range*, not what a Java programmer expects the method to do to the *container*. `map[k]` is "get-or-create", not "get" (use `find`, `count`, or in C++20 `contains` for a pure lookup). Algorithms in `<algorithm>` receive only iterators and therefore cannot resize anything; `std::remove` rearranges and returns the new end, and the caller must call the container's `erase` to shrink it (the erase-remove idiom). Both bugs come from assuming a method does the whole job its name suggests.

## The Correction

```cpp
// before
bool in_stock(std::map<std::string, int>& stock, const std::string& part)
{
    return stock[part] > 0;
}
...
std::remove(orders.begin(), orders.end(), 0);

// after
bool in_stock(const std::map<std::string, int>& stock, const std::string& part)
{
    auto it = stock.find(part);
    return it != stock.end() && it->second > 0;
}
...
orders.erase(std::remove(orders.begin(), orders.end(), 0), orders.end());
```

## Instructor Notes

- Ask students to make the `stock` parameter `const` *before* fixing anything else and read the error. The compiler refusing `operator[]` on a `const` map is the lesson in one line.
- A partial fix for bug 1 is `stock.count(part) > 0 && stock[part] > 0`. The second half still calls `operator[]`, but only for keys that exist, so it is correct; discuss why `find` is cleaner (one lookup instead of two).
- For bug 2, some students write a manual loop with `orders.erase(it)` inside a range-for. That invalidates the iterator they are looping with (Module 2's lesson in STL clothing). Steer them to the erase-remove idiom or to C++20's `std::erase(orders, 0)` if their compiler supports it.
- Others "fix" bug 2 by capturing the returned iterator and printing only up to it. The size stays 5; ask what `orders.size()` should report to a caller who never saw `drop_cancelled`.
- The map printing in sorted key order (`bolt`, `nut`, `washer`) is a property of `std::map`, not of insertion order; it is not a bug and is worth pointing out.
