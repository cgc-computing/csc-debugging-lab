# Solution: Ticket Block

**Course/Module/Activity:** CSC240 · Module 2 Memory Management · debug02
**Bug type(s):** runtime (mismatched deallocation), paradigm-specific (`new[]` / `delete[]`)
**Bug count:** 1

## Observed Behavior

Compiles cleanly with `-Wall`. The tickets print, then only **one** `[returned]` line appears (for seat 14, the first element) before the sanitizer aborts the program:

```
Tickets issued:
  seat 14 -> Omar
  seat 15 -> Lena
  seat 16 -> Chris
Returning the block...
[returned] seat 14 (Omar)
=================================================================
==5150==ERROR: AddressSanitizer: attempting free on address which was not malloc()-ed: 0x... in thread T0
    #0 ... in operator delete(void*)
    #1 ... in release_block(Ticket*) ticket_block.cpp:47
    #2 ... in main ticket_block.cpp:61
0x... is located 16 bytes inside of 112-byte region [0x..., 0x...)
allocated by thread T0 here:
    #0 ... in operator new[](unsigned long)
    #1 ... in reserve_block(int, int, std::string const*) ticket_block.cpp:37
    #2 ... in main ticket_block.cpp:54
SUMMARY: AddressSanitizer: bad-free ticket_block.cpp:47 in release_block(Ticket*)
```

(Some sanitizer builds report this as `alloc-dealloc-mismatch (operator new [] vs operator delete)` instead; the meaning is the same.) Without the sanitizer, macOS prints `malloc: *** error for object 0x...: pointer being freed was not allocated` and aborts; glibc prints `free(): invalid pointer`. Either way the last two tickets are never returned and "All seats returned." never prints.

## The Bug(s)

`release_block` uses the scalar form of `delete` on memory that came from the array form of `new`:

```cpp
Ticket* block = new Ticket[count];   // reserve_block
...
delete block;                        // release_block
```

## Why the Program Behaved Incorrectly

`new Ticket[3]` allocates space for three `Ticket`s **plus** a small hidden header (the "array cookie") that records the element count, so that `delete[]` knows how many destructors to run. The pointer returned to the program points just past that cookie.

`delete block` is the single-object form. It (a) runs exactly one destructor, on `*block`, which is why only seat 14 prints `[returned]`, and (b) hands `block` to the allocator as if it were the start of an allocation. Because the real allocation starts 16 bytes earlier (at the cookie), the allocator is asked to free an address it never handed out. The sanitizer reports exactly that: "16 bytes inside of 112-byte region". Formally the mismatch is undefined behavior; in practice it destroys one element and crashes.

## The Concept This Illustrates

In C++ the programmer states, at deallocation time, whether a pointer refers to one object or an array, and the two forms are not interchangeable: `new` pairs with `delete`, `new[]` pairs with `delete[]`. The array form exists precisely so that *every* element's destructor runs. Java students have never faced this because Java arrays are objects the collector understands. The general lesson for this module: every allocation has exactly one matching release, and the *form* of the release must match the form of the allocation.

## The Correction

```cpp
// before
delete block;

// after
delete[] block;
```

## Instructor Notes

- Ask students to predict the output *before* fixing: most expect either three `[returned]` lines or zero. Seeing exactly one is the clue that `delete` treated the array as a single object.
- Try the experiment of changing `Ticket` to hold only an `int` (no `std::string`, no destructor). The mismatch is still undefined behavior, but many compilers omit the cookie for trivially destructible types and the crash disappears. That is a useful conversation about why "it did not crash" is not the same as "it is correct".
- A student may "fix" the crash by looping over the elements and calling `delete &block[i]`. It does not compile sensibly (and would be wrong if it did); ask what a single `delete[]` does that the loop cannot.
- Modern follow-up: `std::vector<Ticket>` or `std::unique_ptr<Ticket[]>` would make the release automatic and correct. Ask which one they would choose here and why.
- The reverse destruction order (16, 15, 14) is what the standard specifies for arrays; it is not a bug.
