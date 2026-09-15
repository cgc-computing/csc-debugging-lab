# censor.py
# Replaces a word the user does not want to see in a message with asterisks.

message = input("Enter a message: ")
banned = input("Enter the word to censor: ")

stars = "*" * len(banned)

censored = message.replace(banned, stars)

print()
print("Original:", message)
print("Censored:", censored)
