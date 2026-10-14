/* least recently used cache 

1. how we can maintain recency in O(1)
   -> list : (head) MRU - item - item - LRU (tail)
   -> new insertion in tail
   -> eviction in head
   -> challenge is how can we (1) find , (2) remove
2. how can we read/write in O(1)
   -> key to value mapping => hash table
   -> hash table value has pointer to list node; the node include the value
*/

/* to do for LRU later

1. extand to hot/cold LRU
2. extend to reflect frequency
3. using locking mechanism

*/

#include <cstdlib>
#include <iostream>

struct source_location {
    const char* file_name;
    unsigned line_number;
    const char* function_name;
};

#define CUR_SOURCE_LOCATION source_location{__FILE__, __LINE__, __func__}

inline void do_assert(bool expr, const source_location& loc, const char* expression) {
    if (!expr) {
        std::cerr << "Assertion failed: " << expression 
                  << " at " << loc.file_name 
                  << " line " << loc.line_number 
                  << " in " << loc.function_name << '\n';
        std::abort();
    }
}

#define DEBUG_ASSERT_ENABLED 1

#if DEBUG_ASSERT_ENABLED
#define my_assert(Expr) do_assert((Expr), CUR_SOURCE_LOCATION, #Expr)
#else
#define my_assert(Expr) ((void)0)
#endif

class ListNode {
public:
    // ListNode():key(-1),value(-1),prev(0),next(0) {}
    ListNode(int k, int v):key(k),value(v) {
        prev = nullptr;
        next = nullptr;
    }
    int key, value;
    ListNode *prev, *next;
};


class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        // search from ht
        auto it = ht.find(key);
        // it->first == key int
        // it->second == node ListNode*
        if (it != ht.end()) {
            ListNode* node = it->second;
            list_promote(node);
            // my_assert(node->key == key);
            return node->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // search from ht
        auto it = ht.find(key);
        if (it != ht.end()) {
            ListNode* node = it->second;
            list_promote(node);
            // my_assert(node->key == key);
            node->value = value;
        } else {
            ListNode *node = nullptr;
            if (ht.size() < capacity) {
                node = new ListNode(key,value);
            } else {
                node = list_pop_back();
                ht.erase(node->key);
                node->key = key;
                node->value = value;
            }
            list_push_front(node);
            ht.insert({key,node});
        }
    }

private:
    unordered_map<int,ListNode*> ht; // search
    int capacity;

    // doubly linked list
    ListNode *head, *tail;

    // list operations
    void list_push_front(ListNode *node) {
        my_assert(node);
        my_assert(node->next == nullptr);
        my_assert(node->prev == nullptr);

        node->next = head;
        if (head) head->prev = node;

        // update head & tail
        head = node;
        if(node->next == nullptr) tail = node;
    }

    ListNode* list_pop_back() {
        my_assert(head && tail);
        ListNode *node = tail;
        if (node->prev) node->prev->next = nullptr;
        tail = node->prev;
        if (tail) tail->next = nullptr;
        if (!tail) head = nullptr;

        // reset node's next & prev
        my_assert(node->next == nullptr);
        node->prev = nullptr;

        return node;
    }

    // any point to MRU pos
    void list_promote(ListNode* node) {
        // remove from list
        if (node->next) node->next->prev = node->prev;
        if (node->prev) node->prev->next = node->next;

        // update head & tail

        /*
        a <-> b <-> c
            
            [node]

        a <-> c

        node->next == c
        node->prev == a
        */

        if(node->next == nullptr) {
            tail = node->prev;
            if (tail) tail->next = nullptr;
        }
        if(node->prev == nullptr) {
            head = node->next;
            if (head) head->prev = nullptr;
        }

        // reset
        node->next = nullptr;
        node->prev = nullptr;


        // push_front
        list_push_front(node);
    }
};
