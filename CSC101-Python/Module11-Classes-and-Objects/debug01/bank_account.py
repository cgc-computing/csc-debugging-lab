# bank_account.py
# A simple bank account that supports deposits and withdrawals.


class BankAccount:
    def __init__(self, owner, balance=0.0):
        self.owner = owner
        self.balance = balance

    def deposit(self, amount):
        balance = self.balance + amount
        print(f"Deposited ${amount:.2f}")

    def withdraw(self, amount):
        if amount > self.balance:
            print("Insufficient funds.")
        else:
            self.balance = self.balance - amount
            print(f"Withdrew ${amount:.2f}")

    def __str__(self):
        return f"{self.owner}: ${self.balance:.2f}"


account = BankAccount("Jordan", 50.00)
print(account)
account.deposit(25.00)
account.withdraw(60.00)
print(account)
