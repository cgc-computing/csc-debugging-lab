# times_table.py
# Prints a multiplication table from 1 x 1 up to n x n.

size = int(input("Table size (1-12): "))

# Header row
print("    ", end="")
for col in range(1, size + 1):
    print(f"{col:4}", end="")
print()
print("    " + "-" * (4 * size))

# One row per multiplier
for row in range(1, size + 1):
    print(f"{row:2} |", end="")
    for col in range(1, size + 1):
        print(f"{row * col:4}", end="")
    print()
