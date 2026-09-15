# inventory.py
# Looks up how many of an item the campus store currently has in stock.

inventory = {
    "notebook": 24,
    "pencil": 130,
    "backpack": 6,
    "calculator": 3,
}

print("Items we track:", list(inventory.keys()))
item = input("Which item are you looking for? ")
item = item.lower()

count = inventory[item]

print()
print("Stock for", item + ":", count)
print("Number of different items tracked:", len(inventory))
