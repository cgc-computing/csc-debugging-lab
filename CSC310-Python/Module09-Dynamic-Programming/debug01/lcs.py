"""Longest common subsequence (CLRS Section 14.4).

lcs_length fills the table c[0..m][0..n], where c[i][j] is the length of
an LCS of the prefixes of X and Y ending at positions i and j, plus a
direction table b used to reconstruct one LCS.  The main block runs the textbook example and a
pair of DNA fragments.
"""


def lcs_length(X, Y):
    m, n = len(X), len(Y)
    c = [[0] * (n + 1) for _ in range(m + 1)]
    b = [[""] * (n + 1) for _ in range(m + 1)]
    for i in range(1, m):
        for j in range(1, n):
            if X[i] == Y[j]:
                c[i][j] = c[i - 1][j - 1] + 1
                b[i][j] = "diag"
            elif c[i - 1][j] >= c[i][j - 1]:
                c[i][j] = c[i - 1][j]
                b[i][j] = "up"
            else:
                c[i][j] = c[i][j - 1]
                b[i][j] = "left"
    return c, b


def build_lcs(b, X, i, j):
    out = []
    while i > 0 and j > 0:
        if b[i][j] == "diag":
            out.append(X[i])
            i -= 1
            j -= 1
        elif b[i][j] == "up":
            i -= 1
        else:
            j -= 1
    return "".join(reversed(out))


def print_table(c, X, Y):
    print("      " + "  ".join(Y))
    for i, row in enumerate(c):
        label = " " if i == 0 else X[i - 1]
        print(f"  {label} " + "  ".join(str(v) for v in row))


def report(X, Y, show_table):
    c, b = lcs_length(X, Y)
    m, n = len(X), len(Y)
    if show_table:
        print_table(c, X, Y)
    print(f"X = {X}, Y = {Y}")
    print(f"  LCS length = {c[m - 1][n - 1]}, one LCS = {build_lcs(b, X, m - 1, n - 1)!r}")


def main():
    report("ABCBDAB", "BDCABA", show_table=True)
    print()
    report("ACCGGTCGAGTGCGCGGAAGCCGGCCGAA", "GTCGTTCGGAATGCCGTTGCTCTGTAAA", show_table=False)


if __name__ == "__main__":
    main()
