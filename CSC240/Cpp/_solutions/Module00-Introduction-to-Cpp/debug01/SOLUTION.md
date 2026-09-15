# Solution: Welcome Badge

**Course/Module/Activity:** CSC240 · Module 0 Introduction to C++ · debug01
**Bug type(s):** logic, paradigm-specific (stream input)
**Bug count:** 1

## Observed Behavior

Compiles cleanly. The second prompt appears without waiting for input, the name is truncated, the age is 0, and (because 0 is below 18) the greeting picks up the junior-visitor suffix:

```
Enter your full name: Ada Lovelace
Enter your age: +--------------------------------+
| Hello, Ada! (junior visitor)   |
| Age: 0                         |
+--------------------------------+
```

## The Bug(s)

`main` reads the name with the extraction operator:

```cpp
std::cin >> name;
```

`>>` into a `std::string` skips leading whitespace and then stops at the *next* whitespace, so only `Ada` is stored and ` Lovelace\n36\n` remains in the stream.

## Why the Program Behaved Incorrectly

The next statement, `std::cin >> age;`, skips the space and tries to parse `Lovelace` as an integer. That fails: the stream enters the fail state, and (since C++11) the target `int` is set to 0. Nothing is consumed, so the program never waits for the user again; it proceeds with `name == "Ada"` and `age == 0`. Every later `>>` would also fail until `std::cin.clear()` is called.

## The Concept This Illustrates

Formatted input (`>>`) is token-based; a line of text is read with `std::getline`. Java students know `next()` versus `nextLine()`; the C++ equivalents are `>>` versus `getline`. A related trap worth mentioning even though it is not the bug here: `getline` *after* a `>>` reads the leftover newline as an empty line, which is why programs mixing the two often need `std::cin.ignore(...)`.

## The Correction

```cpp
// before
std::cin >> name;

// after
std::getline(std::cin, name);
```

The subsequent `std::cin >> age;` is fine because `>>` skips the newline that `getline` left nothing of, and `getline` consumed the whole first line including its newline.

## Instructor Notes

- If students reverse the order (ask for age first, then name with `getline`), they will hit the leftover-newline problem and get an empty name. Let them; it is the natural follow-up lesson and the fix is `std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');` after reading the age.
- Some students propose `std::cin >> first >> last;` and concatenate. That works for two-word names only; ask what happens with "Ada King Lovelace".
- Ask why the padding helper takes `std::string&` and not `std::string`. Changing it to pass by value silently breaks the box alignment: a good five-minute detour on references (the module topic).
- The age check (`age < 18`) is never exercised by the sample; you can ask students to run it with `15` to see the badge text change.
