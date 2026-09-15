# student.py
# Tracks which courses each student is enrolled in.


class Student:
    courses = []

    def __init__(self, name):
        self.name = name

    def enroll(self, course):
        self.courses.append(course)

    def course_count(self):
        return len(self.courses)

    def __str__(self):
        return f"{self.name} is enrolled in {self.course_count()} course(s): {self.courses}"


ana = Student("Ana")
ben = Student("Ben")

ana.enroll("CSC101")
ana.enroll("MAT151")
ben.enroll("ENG101")

print(ana)
print(ben)
