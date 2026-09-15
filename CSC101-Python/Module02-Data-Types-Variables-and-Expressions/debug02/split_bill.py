# split_bill.py
# Computes the tip on a restaurant bill and each person's share of the total.

subtotal = float(input("Bill subtotal: $"))
tip_percent = float(input("Tip percentage (e.g., 18): "))
people = int(input("Number of people splitting the bill: "))

tip = subtotal * tip_percent / 100
total = subtotal + tip
share = subtotal + tip / people

print()
print(f"Tip amount:       ${tip:.2f}")
print(f"Total with tip:   ${total:.2f}")
print(f"Each person pays: ${share:.2f}")
