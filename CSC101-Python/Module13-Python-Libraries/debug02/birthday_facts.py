# birthday_facts.py
# Tells the user which day of the week they were born on and how many days
# old they were on New Year's Day 2026.

from datetime import date

year = int(input("Birth year (e.g., 2005): "))
month = int(input("Birth month (1-12): "))
day = int(input("Birth day (1-31): "))

birthday = date(year, day, month)
reference = date(2026, 1, 1)

days_old = (reference - birthday).days
weekday_name = birthday.strftime("%A")

print()
print(f"You were born on a {weekday_name}.")
print(f"On January 1, 2026 you were {days_old} days old.")
print(f"That is about {days_old / 365.25:.1f} years.")
