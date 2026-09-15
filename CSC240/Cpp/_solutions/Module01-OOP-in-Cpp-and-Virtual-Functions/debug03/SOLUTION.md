# Solution: Session Log

**Course/Module/Activity:** CSC240 · Module 1 OOP in C++ and Virtual Functions · debug03
**Bug type(s):** runtime (resource leak), paradigm-specific (non-virtual destructor)
**Bug count:** 1

## Observed Behavior

`g++ -Wall` warns:

```
session_log.cpp:71:9: warning: delete called on non-final 'Session' that has virtual functions but non-virtual destructor [-Wdelete-non-abstract-non-virtual-dtor]
```

The program runs, but the two `[free]` lines never appear; the `FileSession` destructor is skipped and both buffers leak:

```
Logging everyone out...
[close] session for guest
[close] session for maria
[close] session for devin
```

## The Bug(s)

`Session`'s destructor is not virtual:

```cpp
~Session()
{
    std::cout << "[close] session for " << user_ << std::endl;
}
```

## Why the Program Behaved Incorrectly

`delete s` where `s` is a `Session*` calls the destructor selected by `s`'s *static* type unless that destructor is virtual. So `Session::~Session()` runs directly on a `FileSession` object, prints `[close]`, and frees the memory; `FileSession::~FileSession()` is never invoked, so `delete[] buffer_` never happens and `[free]` is never printed. Deleting a derived object through a base pointer whose destructor is non-virtual is undefined behavior in C++; here the visible symptom is the missing log lines and the leaked buffers.

## The Concept This Illustrates

A destructor is dispatched like any other member function. If a class is meant to be used polymorphically (it has virtual functions and objects are deleted through base pointers), its destructor must be `virtual` so that `delete` starts from the most-derived destructor and runs the chain down to the base. This is the "virtual destructor rule". Java students have never had to think about *which* cleanup code runs, because the collector reclaims memory and there is no destructor chain.

## The Correction

```cpp
// before
~Session()

// after
virtual ~Session()
```

(In the derived class, `~FileSession() override` may be written for clarity; it is not required.)

## Instructor Notes

- The compiler warning names the exact problem. Ask students whether they read it before running, and what "non-final" is doing in that message (marking `Session` `final` would be a different, wrong fix here because `FileSession` derives from it).
- Some students will move `delete[] buffer_` into `Session`. That does not compile (`Session` has no `buffer_`) and is the wrong direction: ask who owns the buffer.
- Another attempt: make `describe()` non-virtual "for consistency". Point out that it breaks the Active-sessions output and has nothing to do with deletion.
- Follow-up: why does `guest`, a plain `Session`, behave identically before and after the fix?
- Connect back to debug01: the base class there already had `virtual ~Employee() = default;`, so it was correct. Ask students to find that line.
