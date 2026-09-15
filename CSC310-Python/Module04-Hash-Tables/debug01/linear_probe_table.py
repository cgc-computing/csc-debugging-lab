"""A fixed-size hash table using open addressing with linear probing.

Keys are strings.  The hash function is a simple polynomial rolling hash
so that every run of the program produces the same slot assignments.
Follows the HASH-INSERT / HASH-SEARCH procedures of CLRS Section 11.4.
"""


class LinearProbeTable:
    def __init__(self, capacity):
        self.m = capacity
        self.slots = [None] * capacity      # each slot holds (key, value) or None
        self.count = 0

    def _hash(self, key):
        h = 0
        for ch in key:
            h = (h * 31 + ord(ch)) % self.m
        return h

    def _probe(self, key, i):
        # i-th slot in the probe sequence for key
        return self._hash(key) + i

    def insert(self, key, value):
        for i in range(self.m):
            j = self._probe(key, i)
            if self.slots[j] is None or self.slots[j][0] == key:
                if self.slots[j] is None:
                    self.count += 1
                self.slots[j] = (key, value)
                return j
        raise OverflowError("hash table overflow")

    def search(self, key):
        for i in range(self.m):
            j = self._probe(key, i)
            if self.slots[j] is None:
                return None
            if self.slots[j][0] == key:
                return self.slots[j][1]
        return None

    def __str__(self):
        cells = []
        for j, slot in enumerate(self.slots):
            cells.append(f"{j}:{'-' if slot is None else slot[0]}")
        return " ".join(cells)


def main():
    table = LinearProbeTable(11)
    courses = [("CSC101", 3), ("CSC110", 4), ("CSC205", 4), ("CSC240", 3),
               ("CSC310", 3), ("MAT227", 4), ("PSY101", 3), ("GEO101", 4),
               ("CHM130", 4), ("ENG101", 3)]
    for name, credits in courses:
        home = table._hash(name)
        landed = table.insert(name, credits)
        print(f"insert {name}: home slot {home:>2}, stored in slot {landed:>2}")

    print()
    print("table:", table)
    print("occupied slots:", table.count)
    print()
    for name in ["CSC310", "ENG101", "MAT227", "BIO100"]:
        print(f"search {name}: {table.search(name)}")


if __name__ == "__main__":
    main()
