//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way
class LRUCache {
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
public:
    LRUCache(int cap) : capacity(cap) {}
    int get(int key) {
        if (!map.count(key)) return -1;
        cache.splice(cache.begin(), cache, map[key]); // Move the accessed node to the front
        return map[key]->second;
    }
    void put(int key, int value) {
        if (map.count(key)) cache.splice(cache.begin(), cache, map[key]), map[key]->second = value;
        else {
            if (cache.size() == capacity) map.erase(cache.back().first), cache.pop_back();
            cache.emplace_front(key, value), map[key] = cache.begin();
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
