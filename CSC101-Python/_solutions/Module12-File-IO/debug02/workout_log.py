# workout_log.py
# Adds one entry to a running workout log and then shows the whole log.

LOG_FILE = "workout_log.txt"

entry = input("What did you do today? ")

with open(LOG_FILE, "a") as log:
    log.write(entry + "\n")

print()
print("Your workout log so far:")
with open(LOG_FILE) as log:
    for line in log:
        print("  " + line.strip())
