# Solution: Raffle Ticket Numbering

**Course/Module/Activity:** CSC110 · Module 7 Writing Classes · debug02
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

Every ticket is number 1 and the sold count is 1:

```
Ticket #1 - Maria
Ticket #1 - Devon
Ticket #1 - Priya
Tickets sold so far: 1
```

## The Bug(s)

`Ticket.java`, field declaration:

```java
private int nextNumber = 0;
```

The counter that must be shared by all tickets is declared as an instance field, so every `Ticket` object gets its own private copy.

## Why the Program Behaved Incorrectly

Each `new Ticket(...)` creates a fresh object with its own `nextNumber` initialized to 0. The constructor increments *that object's* copy to 1 and assigns it as the ticket number. The next ticket starts over from its own 0. No object ever sees another object's counter, so all tickets are #1 and `getTicketsSold()` on any ticket reports 1.

## The Concept This Illustrates

The difference between instance (per-object) state and class-level (`static`) state. A "next available number" is a fact about the class as a whole, not about any single ticket, so it must be `static`. Students at this stage often reach for a field without asking "how many of these should exist?"

## The Correction

```java
// before
private int nextNumber = 0;

// after
private static int nextNumber = 0;
```

## Instructor Notes

- After the fix, ask whether `getTicketsSold()` should also be `static` (yes — it reports class-level information and does not need an object; `Ticket.getTicketsSold()` would then work). This is a natural extension.
- A wrong "fix" is to pass the number into the constructor from the tester (`new Ticket("Maria", 1)`). It produces the right output but pushes the class's responsibility onto every caller; discuss why the class should own its numbering.
- Ask: if `ticketNumber` were also made `static`, what would print? (All three would show #3.) This sharpens the distinction between the two fields.
