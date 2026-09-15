// kmp.cpp
// Knuth-Morris-Pratt string matching (CLRS 32.4). computePrefixFunction
// builds pi, where pi[q] is the length of the longest proper prefix of the
// pattern that is also a suffix of pattern[0..q]. The matcher then scans the
// text once, never moving backwards in it.
#include <iostream>
#include <string>
#include <vector>

std::vector<int> computePrefixFunction(const std::string& P) {
    const int m = static_cast<int>(P.size());
    std::vector<int> pi(m, 0);
    int k = 0;   // length of the current longest border
    for (int q = 1; q < m; ++q) {
        while (k > 0 && P.at(k) != P.at(q)) {
            k = pi.at(k);
        }
        if (P.at(k) == P.at(q)) {
            ++k;
        }
        pi[q] = k;
    }
    return pi;
}

std::vector<int> kmpMatch(const std::string& T, const std::string& P, const std::vector<int>& pi) {
    const int n = static_cast<int>(T.size());
    const int m = static_cast<int>(P.size());
    std::vector<int> shifts;
    int q = 0;   // number of pattern characters matched so far
    for (int i = 0; i < n; ++i) {
        while (q > 0 && P.at(q) != T.at(i)) {
            q = pi.at(q - 1);
        }
        if (P.at(q) == T.at(i)) {
            ++q;
        }
        if (q == m) {
            shifts.push_back(i - m + 1);
            q = pi.at(q - 1);
        }
    }
    return shifts;
}

void report(const std::string& T, const std::string& P) {
    std::vector<int> pi = computePrefixFunction(P);
    std::cout << "pattern \"" << P << "\"  pi =";
    for (int v : pi) {
        std::cout << ' ' << v;
    }
    std::cout << '\n';
    std::vector<int> shifts = kmpMatch(T, P, pi);
    std::cout << "  in \"" << T << "\": ";
    if (shifts.empty()) {
        std::cout << "no match\n";
    } else {
        for (int s : shifts) {
            std::cout << "shift " << s << " (\"" << T.substr(s, P.size()) << "\") ";
        }
        std::cout << '\n';
    }
}

int main() {
    report("abababacaba", "ababaca");
    report("ababbabb", "ababb");
    report("ababbababbabababb", "ababb");
    report("aabaabaaabaab", "abaab");
    return 0;
}
