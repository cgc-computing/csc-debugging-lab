# shopping_cart.py
# Builds separate shopping carts for two customers using one helper function.


def add_item(item, cart=[]):
    """Add an item to a cart and return the cart. Starts a new cart if none is given."""
    cart.append(item)
    return cart


alice_cart = add_item("apples")
alice_cart = add_item("bread", alice_cart)

bob_cart = add_item("cereal")
bob_cart = add_item("milk", bob_cart)

print("Alice's cart:", alice_cart)
print("Bob's cart:  ", bob_cart)
