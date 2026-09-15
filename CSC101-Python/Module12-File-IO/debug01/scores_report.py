# scores_report.py
# Reads exam scores from scores.txt (one score per line) and reports the
# count, total, and average.

with open("scores.txt") as file:
    contents = file.read()

lines = contents.split("\n")

total = 0
count = 0
for line in lines:
    score = int(line)
    total = total + score
    count = count + 1
    print(f"Score {count}: {score}")

print()
print(f"Number of scores: {count}")
print(f"Total points:     {total}")
print(f"Average score:    {total / count:.1f}")
