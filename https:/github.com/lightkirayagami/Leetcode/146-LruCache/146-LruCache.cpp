// Last updated: 27/04/2026, 21:50:36
class LRUCache {

    // using DLL to do easy deletion and avoid shifting
    // we are saving address so that we can do look of elemnt in O(1)
    // to delete a node ..after deletion we need prev ponter address so that is
    // why we use DLL we dont do push_back as we ll have to iterate everytime so
    // we do push_front

public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> mp;
    int n;
    LRUCache(int capacity) { n = capacity; }
    void makeRecentlyUsed(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        makeRecentlyUsed(key);
        return mp[key].second;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            makeRecentlyUsed(key);
            mp[key].second = value;
        } else {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if (n < 0) {
            int key_del = dll.back();
            mp.erase(key_del);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */