# bake_sale.py
# Records the sales at a bake sale and keeps a running total for the day.

total_sales = 0.0


def record_sale(amount):
    """Add one sale to the day's total and print a receipt line."""
    total_sales = total_sales + amount
    print(f"  Recorded ${amount:.2f}  (total so far: ${total_sales:.2f})")


print("Bake Sale Tracker")
count = int(input("How many sales to record? "))

for sale in range(1, count + 1):
    amount = float(input(f"Sale {sale} amount: $"))
    record_sale(amount)

print()
print(f"Total for the day: ${total_sales:.2f}")
