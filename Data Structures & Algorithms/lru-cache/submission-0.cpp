#include <unordered_map>
#include <iostream>

class LRUCache {
public:
    explicit LRUCache(size_t capacity) : cap(capacity) {}

    int get(int key) {
        auto it = value_of.find(key);
        if (it == value_of.end()) {
            // std::cout << key << " not found\n";
            return -1;
        }
        list.move_to_back(node_of[key]);         // touch -> most recent
        return it->second;
    }

    void put(int key, int value) {
        auto it = value_of.find(key);
        if (it != value_of.end()) {
            it->second = value;
            list.move_to_back(node_of[key]);     // update recency
            return;
        }

        // insert new
        auto* n = new LRUNode{key};
        list.push_back(n);
        value_of[key] = value;
        node_of[key] = n;

        if (list.size() > cap) {                 // evict LRU (front)
            LRUNode* lru = list.pop_front();     // detached, not deleted
            int oldKey = lru->key;
            value_of.erase(oldKey);
            node_of.erase(oldKey);
            delete lru;                          // free the node
        }
    }

    ~LRUCache() {
        while (auto* n = list.pop_front()) delete n;
    }

private:
    struct LRUNode {
        int key;
        LRUNode* prev = nullptr;
        LRUNode* next = nullptr;
    };

    class LRUList {
        size_t _size = 0;
        LRUNode* head = nullptr;
        LRUNode* tail = nullptr;

    public:
        void push_back(LRUNode* n) {
            n->next = nullptr;
            n->prev = tail;
            if (tail) tail->next = n; else head = n;
            tail = n;
            ++_size;
        }

        // detach node from wherever it is (does NOT delete)
        void detach(LRUNode* n) {
            if (!n) return;
            if (n->prev) n->prev->next = n->next; else head = n->next;
            if (n->next) n->next->prev = n->prev; else tail = n->prev;
            n->prev = n->next = nullptr;
            --_size;
        }

        void move_to_back(LRUNode* n) {
            if (!n || n == tail) return;
            detach(n);
            push_back(n);
        }

        // remove and return front (caller decides to delete or reuse)
        LRUNode* pop_front() {
            if (!head) return nullptr;
            LRUNode* n = head;
            detach(n);           // now n is isolated, size already decremented
            return n;
        }

        size_t size() const { return _size; }
    };

    size_t cap;
    std::unordered_map<int, int> value_of;         // key -> value
    std::unordered_map<int, LRUNode*> node_of;     // key -> node in list
    LRUList list;
};
