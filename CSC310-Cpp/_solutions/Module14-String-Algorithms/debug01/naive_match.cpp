// naive_match.cpp
// Naive string matching (CLRS 32.1): tries every shift s of the pattern
// against the text and reports each shift where all m characters agree.
#include <iostream>
#include <string>
#include <vector>

std::vector<int> naiveMatch(const std::string& text, const std::string& pattern) {
    const int n = static_cast<int>(text.size());
    const int m = static_cast<int>(pattern.size());
    std::vector<int> shifts;
    for (int s = 0; s <= n - m; ++s) {
        int k = 0;
        while (k < m && text.at(s + k) == pattern.at(k)) {
            ++k;
        }
        if (k == m) {
            shifts.push_back(s);
        }
    }
    return shifts;
}

void report(const std::string& text, const std::string& pattern) {
    std::vector<int> shifts = naiveMatch(text, pattern);
    std::cout << "\"" << pattern << "\" in \"" << text << "\": ";
    if (shifts.empty()) {
        std::cout << "no match\n";
        return;
    }
    std::cout << shifts.size() << " match" << (shifts.size() == 1 ? "" : "es") << " at shift"
              << (shifts.size() == 1 ? "" : "s");
    for (int s : shifts) {
        std::cout << ' ' << s;
    }
    std::cout << '\n';
}

int main() {
    report("abracadabra", "abra");
    report("aaaaa", "aa");
    report("hello world", "world");
    report("mississippi", "issi");
    report("abc", "abcd");
    report("banana", "nan");
    return 0;
}
