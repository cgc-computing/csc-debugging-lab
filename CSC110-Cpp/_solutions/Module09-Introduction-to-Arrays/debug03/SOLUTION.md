# Solution: Reverse an Array in Place

**Course/Module/Activity:** CSC110 · Module 9 Introduction to Arrays · debug03
**Bug type(s):** logic (array decay / sizeof misuse)
**Bug count:** 1

## Observed Behavior

The program compiles with two warnings on the same line:

```
warning: sizeof on array function parameter will return size of 'int *' instead of 'int[]' [-Wsizeof-array-argument]
warning: 'sizeof (arr)' will return the size of the pointer, not the array itself [-Wsizeof-pointer-div]
```

and only the first two elements are exchanged:

```
Original: 10 20 30 40 50 60
Reversed: 20 10 30 40 50 60
```

## The Bug(s)

`reverse_array.cpp`, `reverseArray`:

```cpp
void reverseArray(int arr[]) {
    int size = sizeof(arr) / sizeof(arr[0]);
```

The function tries to compute the array's length from the parameter. Inside a function, `int arr[]`
is really `int* arr` (a pointer), so `sizeof(arr)` is the size of a pointer (8 bytes on this
machine), and `size` becomes `8 / 4 = 2`.

## Why the Program Behaved Incorrectly

When an array is passed to a function, it *decays* to a pointer to its first element; the length
is not carried along. `sizeof(arr) / sizeof(arr[0])` is a valid idiom only where `arr` is the
actual array object (in `main`), not for a parameter. With `size == 2`, the loop runs once
(`i < 1`) and swaps `arr[0]` with `arr[1]`, leaving the other four elements alone. The result is
deterministic on any 64-bit platform (on 32-bit it would be `4 / 4 = 1` and nothing would move).

## The Concept This Illustrates

A C++ array does not know its own length once it leaves the scope where it was declared. Any
function that works on an array must receive the size as a separate argument — which is exactly
what `printArray` in the same file already does. Students who have seen the `sizeof` idiom in
`main` assume it is a general "length of array" operation.

## The Correction

```cpp
// before
void reverseArray(int arr[]) {
    int size = sizeof(arr) / sizeof(arr[0]);
    ...
}
reverseArray(values);

// after
void reverseArray(int arr[], int size) {
    ...
}
reverseArray(values, SIZE);
```

## Instructor Notes

- The compiler warning names the problem directly; use this activity to reinforce that warnings
  are worth reading even when the program "runs."
- Ask students to print `sizeof(values)` in `main` and `sizeof(arr)` inside the function and
  compare (24 vs 8).
- Some students "fix" it by hard-coding `int size = 6;` inside the function; ask what happens
  when `SIZE` changes to 8. Point to `printArray`'s signature as the model.
- Related Java contrast: `arr.length` exists because Java arrays are objects that carry their size.
