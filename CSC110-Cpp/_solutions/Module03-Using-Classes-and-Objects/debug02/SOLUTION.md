# Solution: High Score Entry

**Course/Module/Activity:** CSC110 · Module 3 Using Classes and Objects · debug02
**Bug type(s):** runtime (input stream state)
**Bug count:** 1

## Observed Behavior

The second prompt appears but the program does not wait for the name; it immediately prints:

```
Enter the new high score: 1200
Enter the player's full name:
*** NEW HIGH SCORE ***
 scored 1200 points!
Name length: 0 characters
```

The player's name is empty.

## The Bug(s)

`high_score.cpp`, `main`: `cin >> score;` is immediately followed by `getline(cin, playerName);`
with nothing in between to remove the newline left behind by the first read.

## Why the Program Behaved Incorrectly

`cin >> score` skips leading whitespace, reads the digits `1200`, and stops at the first
non-digit, which is the `'\n'` the user typed by pressing Enter. That `'\n'` stays in the stream.
`getline` then reads "up to the next newline", finds it immediately, and returns an empty string
without ever waiting for the user. `playerName.length()` is therefore `0`.

## The Concept This Illustrates

Formatted input (`>>`) and line-oriented input (`getline`) treat the newline differently. Mixing
them requires understanding that `cin` is a stream with state: what one read leaves behind is what
the next read sees. This is a library-usage lesson (the `std::string`/`getline` interface), not a
typo.

## The Correction

```cpp
// before
cin >> score;

cout << "Enter the player's full name: ";
getline(cin, playerName);

// after
cin >> score;
cin.ignore(1000, '\n');   // discard the rest of the line after the number

cout << "Enter the player's full name: ";
getline(cin, playerName);
```

`cin >> ws;` before `getline` is an equally good fix at this level (it discards leading
whitespace including the newline). `std::numeric_limits<std::streamsize>::max()` in place of
`1000` is the fully general form.

## Instructor Notes

- Some students replace `getline` with `cin >> playerName`; that "works" for `Maria` but drops
  `Santos`. Point back to the Expected Behavior (name length 12).
- Others add a second `getline` call "to eat the blank one"; that works too, but ask them to
  explain what the first `getline` actually consumed.
- Follow-up: why did the *first* read not have this problem? (There was nothing pending before it.)
