# savings_goal.py
# Figures out how many monthly deposits it takes to reach a savings goal.

balance = float(input("Current balance: $"))
goal = float(input("Savings goal: $"))
deposit = float(input("Monthly deposit: $"))

months = 0
while balance < goal:
    balance = balance + deposit
    months = months + 1

print()
print(f"You will reach ${goal:.2f} in {months} month(s).")
print(f"Ending balance: ${balance:.2f}")
