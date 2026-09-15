"""A hash map with separate chaining (CLRS Section 11.2).

Each bucket is a Python list of (key, value) pairs.  When the load factor
n/m exceeds 0.75 the table doubles its bucket count and rehashes every
pair.  The hash function is a fixed polynomial hash so runs repeat.
The main block uses the map as a word-frequency counter.
"""


class ChainedHashMap:
    def __init__(self, capacity=8):
        self.buckets = [[] for _ in range(capacity)]
        self.count = 0          # number of distinct keys stored
        self.rehashes = 0

    def _hash(self, key):
        h = 0
        for ch in key:
            h = (h * 131 + ord(ch)) % 1000003
        return h % len(self.buckets)

    def put(self, key, value):
        bucket = self.buckets[self._hash(key)]
        for idx, (k, _) in enumerate(bucket):
            if k == key:
                bucket[idx] = (key, value)
                return
        bucket.append((key, value))
        self.count += 1
        if self.count / len(self.buckets) > 0.75:
            self._resize(2 * len(self.buckets))

    def get(self, key, default=None):
        bucket = self.buckets[self._hash(key)]
        for k, v in bucket:
            if k == key:
                return v
        return default

    def remove(self, key):
        bucket = self.buckets[self._hash(key)]
        for idx, (k, _) in enumerate(bucket):
            if k == key:
                del bucket[idx]
                self.count -= 1
                return True
        return False

    def _resize(self, new_capacity):
        old = self.buckets
        self.buckets = [[] for _ in range(new_capacity)]
        for bucket in old:
            for k, v in bucket:
                self.buckets[self._hash(k)].append((k, v))
        self.rehashes += 1

    def __len__(self):
        return self.count

    def longest_chain(self):
        return max(len(b) for b in self.buckets)


def main():
    text = ("the quick brown fox jumps over the lazy dog the dog sleeps "
            "and the fox runs over the hill while the quick dog watches")
    words = text.split()
    counts = ChainedHashMap()
    for w in words:
        counts.put(w, counts.get(w, 0) + 1)

    print("words processed :", len(words))
    print("distinct words  :", len(counts))
    print("buckets         :", len(counts.buckets))
    print("rehashes        :", counts.rehashes)
    print("longest chain   :", counts.longest_chain())
    print()
    for w in ["the", "dog", "fox", "quick", "over", "hill", "cat"]:
        print(f"count[{w!r}] = {counts.get(w, 0)}")

    print()
    print("remove 'the'   :", counts.remove("the"))
    print("count['the']   :", counts.get("the", 0))
    print("distinct words :", len(counts))


if __name__ == "__main__":
    main()
