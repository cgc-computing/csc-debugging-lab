# letter_grade.py
# Converts a numeric course score into a letter grade using the standard
# 90/80/70/60 cutoffs.

score = float(input("Enter the final score (0-100): "))

if score >= 90:
    grade = "A"
elif score >= 80:
    grade = "B"
elif score >= 70:
    grade = "C"
elif score >= 60:
    grade = "D"
else:
    grade = "F"

print(f"A score of {score:.1f} earns a grade of {grade}.")
if grade == "F":
    print("Please see your instructor about your options.")
else:
    print("Congratulations on passing!")
