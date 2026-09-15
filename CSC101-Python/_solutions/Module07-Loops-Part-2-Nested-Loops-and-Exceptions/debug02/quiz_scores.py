# quiz_scores.py
# Collects three quiz scores, asking again whenever the entry is not a whole
# number, then reports the average.

scores_needed = 3
total = 0
count = 0

while count < scores_needed:
    entry = input(f"Enter quiz score {count + 1}: ")
    try:
        score = int(entry)
        total = total + score
        count = count + 1
    except ValueError:
        print("That is not a whole number. Try again.")

print()
print(f"Scores entered: {count}")
print(f"Average: {total / count:.1f}")
