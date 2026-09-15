# top_scorers.py
# Ranks students by exam score and prints the top three.

students = [
    ("Ana", 88),
    ("Ben", 95),
    ("Chloe", 72),
    ("Dev", 91),
    ("Eli", 84),
    ("Fatima", 99),
]

ranked = sorted(students, key=lambda student: student[1])

print("Top 3 scorers")
print("-------------")
for place in range(3):
    name, score = ranked[place]
    print(f"{place + 1}. {name:<8}{score:>4}")
