// word_count_table.cpp
// A chained hash table mapping std::string -> int, used to count words.
// Each bucket is a singly linked list of (key, value) nodes. The hash code
// is a Java-style polynomial over the characters (h = 31*h + c).
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

class WordCountTable {
public:
    explicit WordCountTable(int buckets) : table_(buckets, nullptr), size_(0) {}

    ~WordCountTable() {
        for (Node* head : table_) {
            while (head != nullptr) {
                Node* next = head->next;
                delete head;
                head = next;
            }
        }
    }
    WordCountTable(const WordCountTable&) = delete;
    WordCountTable& operator=(const WordCountTable&) = delete;

    // Adds delta to the count stored for key (inserting the key if new).
    void add(const std::string& key, int delta) {
        int idx = bucketIndex(key);
        for (Node* n = table_.at(idx); n != nullptr; n = n->next) {
            if (n->key == key) {
                n->value += delta;
                return;
            }
        }
        table_.at(idx) = new Node{key, delta, table_.at(idx)};
        ++size_;
    }

    // Returns the count for key, or 0 if the key is absent.
    int get(const std::string& key) const {
        int idx = bucketIndex(key);
        for (Node* n = table_.at(idx); n != nullptr; n = n->next) {
            if (n->key == key) {
                return n->value;
            }
        }
        return 0;
    }

    int size() const { return size_; }

private:
    struct Node {
        std::string key;
        int value;
        Node* next;
    };

    // Unsigned throughout: the polynomial wraps around modulo 2^32 and the
    // bucket index is reduced while the value is still non-negative.
    std::uint32_t hashCode(const std::string& key) const {
        std::uint32_t h = 0;
        for (unsigned char c : key) {
            h = 31 * h + c;
        }
        return h;
    }

    int bucketIndex(const std::string& key) const {
        return static_cast<int>(hashCode(key) % table_.size());
    }

    std::vector<Node*> table_;
    int size_;
};

int main() {
    const std::string text =
        "the analysis of sorting algorithms uses recurrences and the analysis "
        "of hashing uses expected linear time while balanced trees and priority "
        "queues give logarithmic bounds and the sorting lower bound is linear "
        "in n log n";

    WordCountTable counts(13);
    std::string word;
    for (std::size_t i = 0; i <= text.size(); ++i) {
        if (i == text.size() || text[i] == ' ') {
            if (!word.empty()) {
                counts.add(word, 1);
                word.clear();
            }
        } else {
            word += text[i];
        }
    }

    std::cout << "distinct words: " << counts.size() << '\n';
    for (const std::string& w : {"the", "analysis", "sorting", "linear", "priority", "n", "zebra"}) {
        std::cout << w << ": " << counts.get(w) << '\n';
    }
    return 0;
}
