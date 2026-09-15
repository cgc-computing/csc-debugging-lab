# username.py
# Builds a campus username from a student's full name: the first five letters
# of the last name followed by the first initial, all in lowercase.

full_name = input("Enter your full name (first last): ")

space = full_name.find(" ")
first = full_name[:space]
last = full_name[space + 1:]

username = last[0:4] + first[0]
username = username.lower()

print()
print("First name:", first)
print("Last name: ", last)
print("Username:  ", username)
