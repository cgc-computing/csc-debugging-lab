# grocery_list.py
# Keeps a short grocery list, adds one more item, and shows the list in
# alphabetical order.

groceries = ["milk", "bread", "apples"]
print("Starting list:", groceries)

new_item = input("What else do you need? ")
groceries = groceries.append(new_item)

groceries.sort()
print()
print("You need", len(groceries), "items:")
print(groceries)
print("First item to grab:", groceries[0])
