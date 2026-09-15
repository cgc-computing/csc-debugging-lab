# Solution: Validated Score Reader

**Course/Module/Activity:** CSC205 · Module 4 File I/O and Exceptions · debug02
**Bug type(s):** runtime (stream error state), logic
**Bug count:** 1

## Observed Behavior

After `abc` is typed, the program never waits for input again and loops forever:

```
Score: 85
Score: 92
Score: abc
Skipping invalid input:
Score: Skipping invalid input:
Score: Skipping invalid input:
Score: Skipping invalid input:
...
```

(The program must be killed with Ctrl+C.)

## The Bug(s)

The `else` branch tries to discard the bad token with `cin >> junk;` without first calling `cin.clear()`:

```cpp
} else {
    if (cin.eof()) { break; }
    string junk;
    cin >> junk;          // stream still has failbit set
    cout << "Skipping invalid input: " << junk << endl;
}
```

## Why the Program Behaved Incorrectly

When `cin >> value` cannot parse `abc` as an `int`, it sets `failbit` and leaves `abc` unread in the buffer. Every subsequent extraction on a stream whose `failbit` is set does nothing and immediately fails. So `cin >> junk` reads nothing (`junk` stays empty), `abc` stays in the buffer, the loop comes back, `cin >> value` fails again instantly, and so on — an infinite loop that never blocks for keyboard input. The `eof()` check does not help because end of file has not been reached; the stream is in the *fail* state, not the *eof* state.

## The Concept This Illustrates

Stream error states are sticky. A failed read is not a one-time event; it puts the stream into a mode where all I/O is refused until the program acknowledges the error with `clear()`. Recovering from bad input is therefore a two-step protocol: (1) reset the state, (2) remove the offending characters. Students who know exceptions expect the failed read to be "thrown away" automatically; C++ streams instead require an explicit reset. This is the C++ counterpart of a swallowed exception leaving the program in an unusable state.

## The Correction

```cpp
// before
string junk;
cin >> junk;

// after
cin.clear();
string junk;
cin >> junk;
```

`cin.ignore(numeric_limits<streamsize>::max(), '\n')` after `clear()` is another accepted way to discard the rest of the line.

## Instructor Notes

- Students who add `cin.ignore(...)` *without* `cin.clear()` see no change; use this to reinforce that `ignore` is also an I/O operation and is refused in the fail state.
- Ask why `cin.eof()` did not fire. Then have them press Ctrl+D (or Ctrl+Z on Windows) at the prompt in the fixed program to see the eof branch work.
- Some students propose reading everything as a `string` and converting with `stoi` inside a try/catch. That is a valid alternative design; compare it with the stream-state approach and note both need a way to detect and discard bad tokens.
- Discussion prompt: what would happen if the user typed `12abc`? (`12` is read; `abc` is the next token and gets skipped.)
