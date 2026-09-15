"""Binary search tree with parent pointers and the two rotations from
CLRS Section 13.2 (LEFT-ROTATE and RIGHT-ROTATE).

The main block builds a degenerate (chain-shaped) tree by inserting the
keys 1..7 in order, then applies a fixed sequence of rotations that should
turn the chain into a perfectly balanced tree of height 2.
"""


class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.parent = None


class BST:
    def __init__(self):
        self.root = None

    def insert(self, key):
        z = Node(key)
        y = None
        x = self.root
        while x is not None:
            y = x
            x = x.left if key < x.key else x.right
        z.parent = y
        if y is None:
            self.root = z
        elif key < y.key:
            y.left = z
        else:
            y.right = z

    def find(self, key):
        x = self.root
        while x is not None and x.key != key:
            x = x.left if key < x.key else x.right
        return x

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left is not None:
            y.left.parent = x
        y.parent = x.parent
        if x.parent is None:
            self.root = y
        elif x is x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def right_rotate(self, y):
        x = y.left
        y.left = x.right
        if x.right is not None:
            x.right.parent = y
        x.parent = y.parent
        if y.parent is None:
            self.root = x
        elif y is y.parent.left:
            y.parent.left = x
        else:
            y.parent.right = x
        x.right = y
        y.parent = x

    def inorder(self):
        out = []

        def walk(n):
            if n is not None:
                walk(n.left)
                out.append(n.key)
                walk(n.right)
        walk(self.root)
        return out

    def height(self):
        def h(n):
            return -1 if n is None else 1 + max(h(n.left), h(n.right))
        return h(self.root)

    def parent_links_ok(self):
        """Every child's parent pointer must point back at its parent."""
        def check(n):
            if n is None:
                return True
            for child in (n.left, n.right):
                if child is not None and child.parent is not n:
                    return False
            return check(n.left) and check(n.right)
        return self.root is not None and self.root.parent is None and check(self.root)


def main():
    tree = BST()
    for k in range(1, 8):
        tree.insert(k)
    print("chain     :", tree.inorder(), "height", tree.height())

    # Rotate the chain into a balanced tree rooted at 4.
    for key, op in [(1, "L"), (2, "L"), (3, "L"), (3, "R"), (5, "L")]:
        node = tree.find(key)
        if op == "L":
            tree.left_rotate(node)
        else:
            tree.right_rotate(node)
        print(f"after {op}-rotate at {key}: root {tree.root.key}, "
              f"inorder {tree.inorder()}")

    print()
    print("final root      :", tree.root.key)
    print("final height    :", tree.height())
    print("parent links ok :", tree.parent_links_ok())


if __name__ == "__main__":
    main()
