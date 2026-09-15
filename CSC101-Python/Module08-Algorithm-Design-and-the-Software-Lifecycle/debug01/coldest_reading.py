# coldest_reading.py
# Finds the coldest temperature in a series of readings taken over one day.
#
# Algorithm (from the design document):
#   1. Ask for the number of readings, n.
#   2. Read the n temperatures one at a time.
#   3. Keep track of the coldest temperature seen so far and which reading
#      it was (1 for the first reading, 2 for the second, and so on).
#   4. Report the coldest temperature and its position.

count = int(input("How many readings? "))

coldest = 0
coldest_position = 0

for position in range(1, count + 1):
    temperature = float(input(f"Reading {position} (degrees F): "))
    if temperature < coldest:
        coldest = temperature
        coldest_position = position

print()
print(f"Coldest reading: {coldest:.1f} F (reading #{coldest_position})")
