# quiz_average.py
# Reads three quiz scores and reports the total and the average.

print("Quiz Average Calculator")
print("-----------------------")

score1 = int(input("Enter the first quiz score: "))
score2 = int(input("Enter the second quiz score: "))
score3 = int(input("Enter the third quiz score: "))

total = score1 + score2 + score3
average = total / 3

print()
print("Total points:", total)
print("Average score:", round(average, 2))
