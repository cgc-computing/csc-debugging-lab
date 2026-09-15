// fibonacci_timing.cpp
// Computes Fibonacci numbers and reports how long each computation takes.
// The fib() function is documented as running in linear time, O(n), so
// fib(40) should take only a little longer than fib(30).

#include <iostream>
#include <chrono>
using namespace std;

// Returns the n-th Fibonacci number (fib(0) = 0, fib(1) = 1).
// Running time: O(n) -- one addition per number computed.
long long fib(int n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
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
