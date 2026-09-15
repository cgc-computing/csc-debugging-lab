# Campus Username Builder

**Course:** CSC101 &nbsp;|&nbsp; **Module 3:** Strings &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

The program reads a full name such as `Grace Hopper` and builds a campus username: the first
**five** letters of the last name, followed by the first initial, all lowercase.

## Expected Behavior

```
Enter your full name (first last): Grace Hopper

First name: Grace
Last name:  Hopper
Username:   hoppeg
```

## How to Run

```bash
python3 username.py
```

Type `Grace Hopper` and press Enter.

## Your Task

Run the program with the sample name and compare the username with the Expected Behavior. This
program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be
ready to explain *why* the original version behaved the way it did. Do not rewrite the program;
the structure is fine.

## Think About

* Write down the index of each letter in `Hopper`, starting from 0.
* When you slice a string with `text[a:b]`, exactly which indexes are included? Is the letter at
  index `b` part of the result?
* How many characters should the last-name part of the username contain, and how many does the
  program produce?
