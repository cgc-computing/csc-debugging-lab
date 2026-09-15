# dice_simulator.py
# Rolls a six-sided die many times and shows how often each face came up.

import random

ROLLS = 600

counts = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0}

for roll in range(ROLLS):
    face = random.randint(1, 6)
    counts[face] = counts[face] + 1

print(f"Results of {ROLLS} rolls:")
for face in range(1, 7):
    bar = "#" * (counts[face] // 5)
    print(f"{face}: {counts[face]:4}  {bar}")
