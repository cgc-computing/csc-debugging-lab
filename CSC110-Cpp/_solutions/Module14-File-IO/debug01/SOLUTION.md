# Solution: Score File Reader

**Course/Module/Activity:** CSC110 · Module 14 File I/O · debug01
**Bug type(s):** logic (end-of-file test in the wrong place)
**Bug count:** 1

## Observed Behavior

The last student is printed twice, and both the count and the average are wrong:

```
Ana: 88
Ben: 92
Chloe: 79
Dmitri: 95
Dmitri: 95
Students: 5
Average: 89.8
```

The program compiles with no warnings.

## The Bug(s)

`score_reader.cpp`, `main`, the read loop:

```cpp
while (!in.eof()) {
    in >> name >> score;
    cout << name << ": " << score << endl;
    total += score;
    count++;
}
```

The loop tests for end-of-file *before* reading and then uses the values *without checking whether
the read succeeded*.

## Why the Program Behaved Incorrectly

`scores.txt` ends with a newline after `95` (as text files normally do). After the fourth
`in >> name >> score`, the stream has consumed `95` but is positioned at that final `'\n'`; it has
not yet *tried* to read past the end, so `eof()` is still false and the loop runs a fifth time. That
read skips the newline, hits the end of the file, and fails, setting `eofbit` and `failbit`. A
failed extraction into a `string` leaves the string unchanged, and once the stream is in a failed
state the extraction into `score` does nothing either. `name` and `score` therefore still hold
`Dmitri` and `95`, which the body dutifully prints and adds. Total becomes 449 over 5 students.

## The Concept This Illustrates

End-of-file is detected by a read that *fails*, not by arriving at the last byte. The correct
pattern is to make the read itself the loop condition — `while (in >> name >> score)` — so the
body runs only when a complete record was actually obtained. `while (!file.eof())` is one of the
most common file-processing mistakes in C++ precisely because it works "except for the last
line."

## The Correction

```cpp
// before
while (!in.eof()) {
    in >> name >> score;
    ...
}

// after
while (in >> name >> score) {
    ...
}
```

## Instructor Notes

- Have students delete the trailing newline from a *copy* of `scores.txt` and run the original
  again; it then "works," which shows how fragile the `eof()` test is.
- A common partial fix is `if (in.eof()) break;` after the read. It happens to work here; ask
  what happens if a line contains a name with no score (the failed read is still processed).
- Ask why `in >> name >> score` can be used as a condition at all. (The extraction returns the
  stream, and a stream converts to `false` when a read has failed.)
- Follow-up: what should the program do if the file cannot be opened? (It already checks
  `is_open()`; have students rename the file to see that branch run.)
