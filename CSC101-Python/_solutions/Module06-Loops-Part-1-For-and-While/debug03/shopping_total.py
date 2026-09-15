# shopping_total.py
# Adds up the prices of several items and reports the total with sales tax.

TAX_RATE = 0.08

count = int(input("How many items did you buy? "))

total = 0.0
for item in range(1, count + 1):
    price = float(input(f"Price of item {item}: $"))
    total = total + price

tax = total * TAX_RATE

print()
print(f"Subtotal: ${total:.2f}")
print(f"Tax:      ${tax:.2f}")
print(f"Total:    ${total + tax:.2f}")
