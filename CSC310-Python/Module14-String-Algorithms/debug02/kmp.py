"""Knuth-Morris-Pratt string matching (CLRS Section 32.4).

compute_prefix_function(pattern) returns the list pi where pi[q] is the
length of the longest proper prefix of the pattern that is also a suffix
of pattern[:q + 1].  kmp_match(text, pattern) then scans the text once,
using pi to decide how far to fall back after a mismatch, and returns
every shift at which the pattern occurs.  The main block prints pi for
each pattern and the matches found in a few texts.
"""


def compute_prefix_function(pattern):
    m = len(pattern)
    pi = [0] * m
    k = 0
    for q in range(1, m):
        while k > 0 and pattern[k] != pattern[q]:
            k = pi[k]
        if pattern[k] == pattern[q]:
            k += 1
        pi[q] = k
    return pi


def kmp_match(text, pattern):
    n = len(text)
    m = len(pattern)
    pi = compute_prefix_function(pattern)
    shifts = []
    q = 0
    for i in range(n):
        while q > 0 and pattern[q] != text[i]:
            q = pi[q - 1]
        if pattern[q] == text[i]:
            q += 1
        if q == m:
            shifts.append(i - m + 1)
            q = pi[q - 1]
    return shifts


def main():
    cases = [
        ("ababaca", ["abababacaba"]),
        ("ababb", ["ababbabb", "ababbababbabababb"]),
        ("abacabab", ["abacababacabab"]),
    ]
    for pattern, texts in cases:
        pi = compute_prefix_function(pattern)
        print(f'pattern "{pattern}"  pi = {" ".join(map(str, pi))}')
        for text in texts:
            shifts = kmp_match(text, pattern)
            found = " ".join(f'shift {s} ("{text[s:s + len(pattern)]}")'
                             for s in shifts)
            print(f'  in "{text}": {found if shifts else "no match"}')


if __name__ == "__main__":
    main()
