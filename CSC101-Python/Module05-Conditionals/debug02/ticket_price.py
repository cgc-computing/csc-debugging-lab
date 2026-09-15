# ticket_price.py
# Calculates the cost of movie tickets. Tickets are discounted on Tuesdays
# and Wednesdays; every other day is regular price.

REGULAR_PRICE = 12.00
DISCOUNT_PRICE = 8.00

day = input("What day is the show (e.g., Monday)? ")
day = day.capitalize()
tickets = int(input("How many tickets? "))

if day == "Tuesday" or "Wednesday":
    price = DISCOUNT_PRICE
    print("Midweek discount applied!")
else:
    price = REGULAR_PRICE

total = price * tickets
print(f"{tickets} ticket(s) for {day}: ${total:.2f}")
