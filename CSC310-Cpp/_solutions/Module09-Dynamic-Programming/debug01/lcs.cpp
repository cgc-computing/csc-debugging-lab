// lcs.cpp
// Longest common subsequence (CLRS 14.4). Fills the table c[0..m][0..n]
// bottom-up, records the direction of each choice in b, and reconstructs one
// LCS by walking b from the bottom-right corner.
#include <iostream>
#include <string>
#include <vector>

struct LcsResult {
    int length;
    std::string subsequence;
};

LcsResult longestCommonSubsequence(const std::string& X, const std::string& Y) {
    const int m = static_cast<int>(X.size());
    const int n = static_cast<int>(Y.size());
    std::vector<std::vector<int>> c(m + 1, std::vector<int>(n + 1, 0));
    std::vector<std::vector<char>> b(m + 1, std::vector<char>(n + 1, ' '));

    // c[i][j] is the LCS length of the first i characters of X and the
    // first j characters of Y.
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X.at(i - 1) == Y.at(j - 1)) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '^';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '<';
            }
        }
    }

    std::string result;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (b[i][j] == '\\') {
            result.insert(result.begin(), X.at(i - 1));
            --i;
            --j;
        } else if (b[i][j] == '^') {
            --i;
        } else {
            --j;
        }
    }
    return {c[m][n], result};
}

void report(const std::string& X, const std::string& Y) {
    std::cout << "LCS(\"" << X << "\", \"" << Y << "\"): ";
    try {
        LcsResult r = longestCommonSubsequence(X, Y);
        std::cout << "length " << r.length << ", one LCS is \"" << r.subsequence << "\"\n";
    } catch (const std::exception& e) {
        std::cout << "exception: " << e.what() << '\n';
    }
}

int main() {
    report("ABCBDAB", "BDCABA");
    report("XMJYAUZ", "MZJAWXU");
    report("AGGTAB", "GXTXAYB");
    report("ABC", "DEF");
    return 0;
}
