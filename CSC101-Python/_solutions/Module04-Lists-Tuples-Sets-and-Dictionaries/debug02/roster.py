# roster.py
# Copies the Section A roster to start Section B, then makes changes to
# Section B only.

section_a = ["Ana", "Ben", "Chloe", "Dev"]
section_b = section_a.copy()

# Section B swaps out its first student and gains a new one.
transfer = input("Name of the student transferring into Section B: ")
section_b[0] = transfer
section_b.append("Eli")

print()
print("Section A:", section_a)
print("Section B:", section_b)
print("Section A has", len(section_a), "students.")
print("Section B has", len(section_b), "students.")
