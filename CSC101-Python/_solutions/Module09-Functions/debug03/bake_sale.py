# bake_sale.py
# Records the sales at a bake sale and keeps a running total for the day.

total_sales = 0.0


def record_sale(total_so_far, amount):
    """Add one sale to the running total, print a receipt line, and return the new total."""
    new_total = total_so_far + amount
    print(f"  Recorded ${amount:.2f}  (total so far: ${new_total:.2f})")
    return new_total


print("Bake Sale Tracker")
count = int(input("How many sales to record? "))

for sale in range(1, count + 1):
    amount = float(input(f"Sale {sale} amount: $"))
    total_sales = record_sale(total_sales, amount)

print()
print(f"Total for the day: ${total_sales:.2f}")
