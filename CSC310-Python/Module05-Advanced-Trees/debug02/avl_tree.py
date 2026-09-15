"""AVL tree: a height-balanced binary search tree.

Every node stores the height of its subtree.  After each insert or
delete, the nodes on the path back to the root have their heights
recomputed and are rebalanced with single or double rotations whenever
the balance factor (height(left) - height(right)) leaves {-1, 0, 1}.
The main block inserts sorted keys, deletes a few, and checks that the
tree really is balanced by measuring it directly.
"""


class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 0


def height(node):
    return -1 if node is None else node.height


def update_height(node):
    node.height = 1 + max(height(node.left), height(node.right))


def balance(node):
    return height(node.left) - height(node.right)


def rotate_right(y):
    x = y.left
    y.left = x.right
    x.right = y
    update_height(x)
    update_height(y)
    return x


def rotate_left(x):
    y = x.right
    x.right = y.left
    y.left = x
    update_height(y)
    update_height(x)
    return y


def rebalance(node):
    update_height(node)
    b = balance(node)
    if b > 1:                                   # left-heavy
        if balance(node.left) < 0:
            node.left = rotate_left(node.left)
        return rotate_right(node)
    if b < -1:                                  # right-heavy
        if balance(node.right) > 0:
            node.right = rotate_right(node.right)
        return rotate_left(node)
    return node


def insert(node, key):
    if node is None:
        return Node(key)
    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)
    return rebalance(node)


def min_node(node):
    while node.left is not None:
        node = node.left
    return node


def delete(node, key):
    if node is None:
        return None
    if key < node.key:
        node.left = delete(node.left, key)
    elif key > node.key:
        node.right = delete(node.right, key)
    else:
        if node.left is None:
            return node.right
        if node.right is None:
            return node.left
        succ = min_node(node.right)
        node.key = succ.key
        node.right = delete(node.right, succ.key)
    return rebalance(node)


def inorder(node, out):
    if node is not None:
        inorder(node.left, out)
        out.append(node.key)
        inorder(node.right, out)
    return out


def measured_height(node):
    """Height computed from scratch, ignoring the stored fields."""
    if node is None:
        return -1
    return 1 + max(measured_height(node.left), measured_height(node.right))


def is_avl(node):
    if node is None:
        return True
    if abs(measured_height(node.left) - measured_height(node.right)) > 1:
        return False
    return is_avl(node.left) and is_avl(node.right)


def main():
    root = None
    for k in range(1, 16):
        root = insert(root, k)
    print("after inserting 1..15")
    print("  inorder        :", inorder(root, []))
    print("  root           :", root.key)
    print("  stored height  :", root.height)
    print("  measured height:", measured_height(root))
    print("  balanced       :", is_avl(root))

    for k in [1, 2, 3, 4, 8]:
        root = delete(root, k)
    print("after deleting 1, 2, 3, 4, 8")
    print("  inorder        :", inorder(root, []))
    print("  root           :", root.key)
    print("  stored height  :", root.height)
    print("  measured height:", measured_height(root))
    print("  balanced       :", is_avl(root))


if __name__ == "__main__":
    main()
