// count_vowels.cpp
// Counts the vowels in a string recursively, one character at a time.

#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Counts vowels in s starting at position i.
int countVowels(const string& s, size_t i) {
    if (i == s.size()) {
        return 0;
    }
    return isVowel(s[i]) ? 1 : 0 + countVowels(s, i + 1);
}

int countVowels(const string& s) {
    return countVowels(s, 0);
}

int main() {
    string words[] = { "programming", "rhythm", "Education", "aeiou", "recursion" };

    for (const string& w : words) {
        cout << w << " has " << countVowels(w) << " vowel(s)" << endl;
    }
    return 0;
}
