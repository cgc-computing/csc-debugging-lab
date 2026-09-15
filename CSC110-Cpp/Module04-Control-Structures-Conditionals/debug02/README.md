# Membership Discount

**Course:** CSC110 &nbsp;|&nbsp; **Module 4:** Control Structures: Conditionals &nbsp;|&nbsp; **Activity:** debug02
**Language:** C++17

## Goal

The program reads a membership level (`G` for Gold, `S` for Silver, `B` for Bronze) and an item
price, then applies the matching discount: Gold 20%, Silver 10%, Bronze 5%, any other letter 0%.

## Expected Behavior

Sample run (the user types `G`, then `80`):

```
Enter membership level (G/S/B): G
Enter the item price: 80
Discount rate: 20%
You pay: $64
```

Other checks: `S` and `80` gives `10%` and `$72`; `B` and `80` gives `5%` and `$76`;
`X` and `80` gives `0%` and `$80`.

## How to Run

```bash
g++ -std=c++17 -Wall -o member_discount member_discount.cpp
./member_discount
```

(on Windows: `member_discount.exe` or `.\member_discount.exe`)

Type a single letter and press Enter, then type a price such as `80` and press Enter. Try all
four levels.

## Your Task

Run the program, compare what it does with the Expected Behavior, and inspect the code to find and
fix the problem. This program contains one or more bugs. Fix them so the program matches the Expected Behavior,
and be ready to explain *why* the original version behaved the way it did. Do not rewrite the
program; the structure is fine.

## Think About

- When a `switch` jumps to a matching `case` label, where does execution stop?
- Trace the program by hand for level `G`: which assignments to the discount rate run, and in what order?
- Which levels behave correctly? What is different about how their `case` sections end?
