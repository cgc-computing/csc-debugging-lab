# Solution: Bank Withdrawals

**Course/Module/Activity:** CSC110 · Module 13 Exceptions · debug02
**Bug type(s):** conceptual/design (catch-handler order; compiles with a warning)
**Bug count:** 1

## Observed Behavior

The program compiles, and clang warns twice:

```
bank_withdrawals.cpp:47:24: warning: exception of type 'const InsufficientFunds &' will be caught by earlier handler [-Wexceptions]
bank_withdrawals.cpp:45:24: note: for type 'const exception &'
bank_withdrawals.cpp:50:24: warning: exception of type 'const invalid_argument &' will be caught by earlier handler [-Wexceptions]
```

Both rejected requests are reported by the generic handler, and the shortfall is never shown:

```
Starting balance: $120
Withdraw $40: OK, balance is now $80
Withdraw $-5: Transaction failed: Amount must be positive
Withdraw $500: Transaction failed: Insufficient funds
Final balance: $80
```

## The Bug(s)

`bank_withdrawals.cpp`, `main`, the `catch` clauses. The base-class handler comes first:

```cpp
} catch (const exception& e) {
    cout << "Transaction failed: " << e.what() << endl;
} catch (const InsufficientFunds& e) {
    ...
} catch (const invalid_argument& e) {
    ...
}
```

`std::exception` is the base of both `std::invalid_argument` and `InsufficientFunds`, so it
matches every exception the program throws and the two specific handlers are unreachable.

## Why the Program Behaved Incorrectly

Handlers are tried *in order*, and the first one whose type matches wins; a `catch` for a
reference to a base class matches any derived-class exception. Throwing `InsufficientFunds(380)`
first reaches `catch (const exception& e)`; because `InsufficientFunds` *is an* `exception`, the
match succeeds, `e.what()` prints the base message, and the search stops. The
`InsufficientFunds` handler — the only one that can call `getShortfall()` — is never considered.
The same happens for `invalid_argument`. Unlike Java, where a derived-class `catch` after its
base is a compile error, C++ accepts the code and clang only warns.

## The Concept This Illustrates

Exception handlers must be ordered from most specific (derived) to most general (base). A
catch-all `catch (const exception&)` is a good safety net, but only when it comes *last*. The
underlying idea is the "is-a" relationship from inheritance applied to exception types: a base
handler is a superset of every derived handler that follows it. Students frequently write the
safety net first "so nothing gets through," not realizing that *everything* gets caught there.

## The Correction

```cpp
// before
} catch (const exception& e) {
    cout << "Transaction failed: " << e.what() << endl;
} catch (const InsufficientFunds& e) {
    cout << "Declined: " << e.what() << " (short by $" << e.getShortfall() << ")" << endl;
} catch (const invalid_argument& e) {
    cout << "Invalid amount: " << e.what() << endl;
}

// after
} catch (const InsufficientFunds& e) {
    cout << "Declined: " << e.what() << " (short by $" << e.getShortfall() << ")" << endl;
} catch (const invalid_argument& e) {
    cout << "Invalid amount: " << e.what() << endl;
} catch (const exception& e) {
    cout << "Transaction failed: " << e.what() << endl;
}
```

`InsufficientFunds` and `invalid_argument` are unrelated siblings, so their relative order does
not matter; only the `exception` handler must move to the end.

## Instructor Notes

- The compiler warning names the problem precisely. Ask students to read it *before* running and
  predict the output.
- Some students "fix" it by deleting the `exception` handler. The output matches, but the README
  asks to keep all three; ask what would happen if `withdraw` someday threw `out_of_range`.
- Ask why `InsufficientFunds` was written as a class deriving from `runtime_error` instead of
  just throwing `runtime_error("Insufficient funds")`. (It can carry extra data — the shortfall —
  and it can be caught separately from other runtime errors.)
- Follow-up: would `catch (InsufficientFunds e)` (by value) work? Yes, but it copies the object;
  `const&` is the idiom. Mention slicing if the group is ready.
- Java contrast for students who know it: `catch (Exception e)` before `catch (ArithmeticException e)`
  is a compile error ("exception has already been caught"). C++ leaves it to the warning.
