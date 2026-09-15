// fibonacci_timing.cpp
// Computes Fibonacci numbers and reports how long each computation takes.
// The fib() function runs in linear time, O(n), so fib(40) takes only a
// little longer than fib(30).

#include <iostream>
#include <chrono>
using namespace std;

// Returns the n-th Fibonacci number (fib(0) = 0, fib(1) = 1).
// Running time: O(n) -- one addition per number computed.
long long fib(int n) {
    if (n < 2) {
        return n;
    }
    long long previous = 0;   // fib(0)
    long long current = 1;    // fib(1)
    for (int i = 2; i <= n; i++) {
        long long next = previous + current;
        previous = current;
        current = next;
    }
    return current;
}

void timeFib(int n) {
    auto start = chrono::steady_clock::now();
    long long result = fib(n);
    auto stop = chrono::steady_clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
    cout << "fib(" << n << ") = " << result << "   (" << ms << " ms)" << endl;
}

int main() {
    timeFib(30);
    timeFib(40);
    return 0;
}
