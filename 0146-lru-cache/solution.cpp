class LRUCache {
public:
    class node {
    public:
        int key, val;
        node *prev, *next;
        node(int k, int v) : key(k), val(v), prev(NULL), next(NULL) {}
    };

    int cap, size;
    unordered_map<int, node*> mp;
    node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // add right after head
    void addNode(node* curr) {
        curr->next = head->next;
        curr->prev = head;
        head->next->prev = curr;
        head->next = curr;
    }

    // remove node
    void removeNode(node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        node* curr = mp[key];
        removeNode(curr);
        addNode(curr);
        return curr->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            node* curr = mp[key];
            curr->val = value;
            removeNode(curr);
            addNode(curr);
            return;
        }

        if (size == cap) {
            node* lru = tail->prev;
            removeNode(lru);
            mp.erase(lru->key);
            delete lru;
            size--;
        }

        node* curr = new node(key, value);
        mp[key] = curr;
        addNode(curr);
        size++;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
