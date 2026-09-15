"""Naive string matching (CLRS Section 32.1).

naive_match(text, pattern) implements NAIVE-STRING-MATCHER: for every
shift s at which the pattern still fits inside the text, compare the
pattern with the text characters starting at s and record the shift if
every character agrees.  The main block runs seven text/pattern pairs and
prints the shifts found.
"""


def naive_match(text, pattern):
    n = len(text)
    m = len(pattern)
    shifts = []
    for s in range(n - m):
        j = 0
        while j < m and text[s + j] == pattern[j]:
            j += 1
        if j == m:
            shifts.append(s)
    return shifts


def describe(text, pattern):
    shifts = naive_match(text, pattern)
    if not shifts:
        return f'"{pattern}" in "{text}": no match'
    label = "match" if len(shifts) == 1 else "matches"
    where = " ".join(str(s) for s in shifts)
    plural = "shift" if len(shifts) == 1 else "shifts"
    return f'"{pattern}" in "{text}": {len(shifts)} {label} at {plural} {where}'


def main():
    cases = [
        ("abracadabra", "abra"),
        ("aaaaa", "aa"),
        ("hello world", "world"),
        ("mississippi", "issi"),
        ("abc", "abcd"),
        ("banana", "nan"),
        ("abc", "abc"),
    ]
    for text, pattern in cases:
        print(describe(text, pattern))


if __name__ == "__main__":
    main()
