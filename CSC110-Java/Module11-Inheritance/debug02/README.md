# Box Office Ticket Pricing

**Course:** CSC110 &nbsp;|&nbsp; **Module 11:** Inheritance &nbsp;|&nbsp; **Activity:** debug02
**Language:** Java 17+

## Goal

`Ticket` is a regular ticket that costs the base fare. `StudentTicket` should cost half the base fare and `SeniorTicket` 70% of it; each subclass overrides `cost` and `getType`. `BoxOffice` holds a mix of tickets in a `Ticket[]` array, prices each one polymorphically at a $12.00 base fare, and totals the money collected.

## Expected Behavior

```
Base fare: $12.00

Noah     Regular  $ 12.00
Elena    Student  $  6.00
Walter   Senior   $  8.40
Kai      Student  $  6.00

Total collected: $32.40
```

## How to Run

```bash
javac *.java
java BoxOffice
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. `Ticket`, `SeniorTicket`, and `BoxOffice` are correct.

## Think About

- The senior discount works and the student discount does not. Compare the two subclasses line by line — what is different?
- For a method in a subclass to *override* a superclass method, what must match exactly?
- When `BoxOffice` calls `sold[i].cost(BASE_FARE)` on a `StudentTicket`, which `cost` method does Java choose, and how does it decide?
