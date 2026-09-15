# Solution: Help-Desk Ticket Numbers

**Course/Module/Activity:** CSC110 · Module 7 Writing Classes · debug02
**Bug type(s):** conceptual/design (instance vs. class data)
**Bug count:** 1

## Observed Behavior

Every ticket is #1 and the count never grows:

```
#1: Printer jam in room 204
#1: Password reset
#1: Monitor flickers
Tickets issued so far: 1
```

## The Bug(s)

`ticket.cpp`, class `Ticket`:

```cpp
int ticketsIssued = 0;
```

The counter is an ordinary (instance) field, so every `Ticket` object gets its own copy that
starts at `0`. It needs to be a `static` member shared by all objects.

## Why the Program Behaved Incorrectly

Constructing `t1` creates a fresh `ticketsIssued` inside `t1`, increments it to `1`, and copies it
to `t1.id`. Constructing `t2` creates *another* `ticketsIssued` inside `t2`, also starting at `0`,
so `t2.id` is also `1`. No object ever sees another object's counter. `t3.getTicketsIssued()`
reports `t3`'s private count, which is `1`.

## The Concept This Illustrates

The difference between per-object state (instance fields) and per-class state (`static` fields).
"How many tickets have been issued" is a fact about the class, not about any single ticket, so it
must live in one place shared by all instances. Students who have only written instance fields
tend to put every variable in the class body without asking who owns it.

## The Correction

```cpp
// before
class Ticket {
private:
    int ticketsIssued = 0;
    ...
    int getTicketsIssued() { return ticketsIssued; }
};

// after
class Ticket {
private:
    static int ticketsIssued;
    ...
    static int getTicketsIssued() { return ticketsIssued; }
};

int Ticket::ticketsIssued = 0;   // one definition, outside the class
```

In `main`, `Ticket::getTicketsIssued()` replaces `t3.getTicketsIssued()` (calling it on an
object still works, but the class-qualified form says what is meant). In C++17,
`inline static int ticketsIssued = 0;` inside the class is also acceptable and avoids the
out-of-class definition.

## Instructor Notes

- Students who write `static int ticketsIssued = 0;` inside the class will get a compiler error
  about in-class initialization of a non-const static member. Explain the one-definition rule and
  show both the out-of-class definition and the `inline static` form.
- Some students move the counter into `main` and pass it to the constructor. It works, but ask
  who should be responsible for numbering tickets — the class, or every caller?
- Ask: should `getTicketsIssued` be `static`? What does it mean to call it on `t3`? (It works but
  misleads; the count is not "t3's".)
