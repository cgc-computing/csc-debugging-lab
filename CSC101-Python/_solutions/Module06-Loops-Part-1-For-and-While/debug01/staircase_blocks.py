# staircase_blocks.py
# A staircase with n steps uses 1 block for step 1, 2 blocks for step 2, and
# so on. This program reports how many blocks the whole staircase needs.

steps = int(input("How many steps in the staircase? "))

total_blocks = 0
for step in range(1, steps + 1):
    total_blocks = total_blocks + step
    print(f"Step {step} uses {step} block(s). Running total: {total_blocks}")

print()
print(f"A staircase with {steps} steps needs {total_blocks} blocks.")
