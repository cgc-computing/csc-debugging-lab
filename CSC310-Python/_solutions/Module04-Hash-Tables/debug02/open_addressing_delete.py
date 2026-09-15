"""Open-addressing hash table (linear probing) with insert, search and delete.

Keys are distinct non-negative integers (student ID numbers) and the hash
function is h(k) = k mod m, so the probe sequences are easy to trace by
hand.  Deletion follows the CLRS Section 11.4 discussion of the DELETED
marker.  The table never resizes.
"""

EMPTY = None
DELETED = "<deleted>"


class ProbingTable:
    def __init__(self, capacity):
        self.m = capacity
        self.slots = [EMPTY] * capacity     # EMPTY, DELETED, or (key, value)

    def _hash(self, key):
        return key % self.m

    def insert(self, key, value):
        for i in range(self.m):
            j = (self._hash(key) + i) % self.m
            if self.slots[j] is EMPTY or self.slots[j] is DELETED:
                self.slots[j] = (key, value)
                return j
        raise OverflowError("hash table overflow")

    def _find_slot(self, key):
        """Index of the slot holding key, or None if key is absent."""
        for i in range(self.m):
            j = (self._hash(key) + i) % self.m
            if self.slots[j] is EMPTY:
                return None
            if self.slots[j] is not DELETED and self.slots[j][0] == key:
                return j
        return None

    def search(self, key):
        j = self._find_slot(key)
        return None if j is None else self.slots[j][1]

    def delete(self, key):
        j = self._find_slot(key)
        if j is None:
            return False
        self.slots[j] = DELETED
        return True

    def __str__(self):
        cells = []
        for j, slot in enumerate(self.slots):
            if slot is EMPTY:
                cells.append(f"{j}:-")
            elif slot is DELETED:
                cells.append(f"{j}:X")
            else:
                cells.append(f"{j}:{slot[0]}")
        return " ".join(cells)


def main():
    table = ProbingTable(11)
    students = [(22, "Ana"), (33, "Ben"), (44, "Cho"), (5, "Dev"),
                (16, "Eli"), (27, "Fay"), (38, "Gus"), (9, "Hal")]
    for sid, name in students:
        table.insert(sid, name)
    print("after inserts :", table)

    table.delete(33)
    table.delete(16)
    print("after deletes :", table)
    print()

    for sid in [22, 33, 44, 5, 16, 27, 38, 9]:
        print(f"search {sid:>2}: {table.search(sid)}")
    print()

    table.insert(55, "Ivy")
    print("after insert 55:", table)
    print("search 55:", table.search(55))
    print("search 44:", table.search(44))


if __name__ == "__main__":
    main()
