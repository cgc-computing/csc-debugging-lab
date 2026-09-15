# Raffle Ticket Numbering

**Course:** CSC110 &nbsp;|&nbsp; **Module 7:** Writing Classes &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`Ticket` represents a raffle ticket. Every ticket created is automatically given the next ticket number, starting at 1, and remembers the buyer's name. The class can also report how many tickets have been sold in total. `TicketTester` sells three tickets and prints them.

## Expected Behavior

```
Ticket #1 - Maria
Ticket #2 - Devon
Ticket #3 - Priya
Tickets sold so far: 3
```

## How to Run

```bash
javac *.java
java TicketTester
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The tester is correct; look at the class.

## Think About

- How many copies of `ticketNumber` exist after three tickets are created? How many copies of the "next available number" *should* exist?
- Which pieces of information belong to one particular ticket, and which belong to the whole class of tickets?
- What is the "next available number" when the constructor runs for the second ticket? Trace it by hand before you run it.
