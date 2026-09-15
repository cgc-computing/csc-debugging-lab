# Solution: Grade Report Writer

**Course/Module/Activity:** CSC110 · Module 14 File I/O · debug02
**Bug type(s):** logic (output file opened in truncate mode when append was intended)
**Bug count:** 1

## Observed Behavior

The finished report contains only the last student; the header and the first three students are
gone:

```
Report written to report.txt

--- report.txt ---
Dmitri 95 A
```

The program compiles with no warnings.

## The Bug(s)

`grade_report.cpp`, `appendLine`:

```cpp
void appendLine(const string& filename, const string& line) {
    ofstream out(filename);
    ...
}
```

The `ofstream` is opened with the default mode, which *truncates* the file (erases its contents)
every time it is opened. The function is called once per student, so each call wipes out
everything written before it.

## Why the Program Behaved Incorrectly

`main` opens `report.txt`, writes the header, and closes it. Then, for each of the four students,
`appendLine` opens `report.txt` again in the default `ios::out` mode. Opening an existing file for
output without `ios::app` discards its previous contents, so the header disappears at the first
call, `Ana 88 B` disappears at the second, and so on. After the loop the file holds only the line
written by the final call, `Dmitri 95 A`. The echo loop at the end faithfully shows that one line.

## The Concept This Illustrates

File streams have *open modes*, and the default for `ofstream` is "start over." Adding to the end
of an existing file requires opening it with `ios::app` (or keeping a single stream open for the
whole job). Students often assume that because a file already exists, writing to it will
naturally continue where it left off — as if it were `cout`. Opening a file is not free of side
effects; the open itself can change the file.

## The Correction

```cpp
// before
ofstream out(filename);

// after
ofstream out(filename, ios::app);
```

An equally good design opens `report.txt` once in `main`, writes the header and every student
line through that one stream, and closes it after the loop (removing `appendLine` or passing the
stream to it). Either version yields the expected report and is stable across repeated runs,
because `main`'s first open still truncates the file and rewrites the header.

## Instructor Notes

- Ask students to insert a `cout` inside `appendLine` printing the line being written; all four
  lines print, which proves the writes happen and the problem is what happens *between* them.
- Some students "fix" it by adding `ios::app` to *every* `ofstream` in the program, including the
  header's. That works once, but a second run appends a second header and four more lines. The
  README's "run it twice" check catches this; discuss why the header open is *supposed* to
  truncate.
- Ask what `appendLine` would do if `report.txt` did not exist yet with `ios::app`. (It is
  created; `app` implies `out`.)
- Follow-up: the program never checks whether `report.txt` opened successfully. Where would an
  `is_open()` check go, and what should the program do if it fails?
- Related: `ios::app` vs. `ios::ate` is a common confusion; `ate` seeks to the end once but does
  not force every write to the end.
