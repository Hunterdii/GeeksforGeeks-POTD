# _27. LRU Cache_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/lru-cache/1)

## Problem Description

Design a data structure that works like an **LRU (Least Recently Used) Cache**. The cache should have the following operations:

1. `GET x`: Return the value associated with key `x` if it exists in the cache. Otherwise, return `-1`.
2. `PUT x y`: Set the value of key `x` to `y`. If the key is already present, update its value. If the cache reaches its capacity, remove the least recently used item before inserting the new item.

**Input:**

- `cap` (integer): The capacity of the cache.
- `Q` (integer): The number of queries.
- `Queries`: A list of queries where each query is either a `PUT` or `GET` operation.

**Output:**

- A list of results for the `GET` operations.

**Example:**

Input:

```
cap = 2
Q = 8
Queries = [["PUT", 1, 2], ["PUT", 2, 3], ["PUT", 1, 5], ["PUT", 4, 5], ["PUT", 6, 7], ["GET", 4], ["PUT", 1, 2], ["GET", 3]]
```

Output:

```
[5, -1]
```

Explanation:

1. `PUT 1, 2` inserts `(1, 2)` into the cache.
2. `PUT 2, 3` inserts `(2, 3)` into the cache.
3. `PUT 1, 5` updates `(1, 2)` to `(1, 5)` as the key `1` already exists.
4. `PUT 4, 5` removes the least recently used `(2, 3)` and inserts `(4, 5)`.
5. `PUT 6, 7` removes the least recently used `(1, 5)` and inserts `(6, 7)`.
6. `GET 4` returns `5` as key `4` is present in the cache.
7. `PUT 1, 2` removes the least recently used `(6, 7)` and inserts `(1, 2)`.
8. `GET 3` returns `-1` as key `3` is not in the cache.

### Constraints:

- 1 <= cap <= $10^3$
- 1 <= Q <= $10^5$
- 1 <= x, y <= $10^4$

## My Approach

1. **Key Data Structures:**

   - Use a combination of a **doubly linked list** and a **hash map** to implement the cache.
     - The doubly linked list stores the cache keys and their values, maintaining the order of usage (most recently used at the head, least recently used at the tail).
     - The hash map stores the mapping of keys to their corresponding nodes in the doubly linked list, allowing for O(1) access.

2. **Implementation Details:**
   - **GET operation:** Check if the key exists in the hash map:
     - If yes, move the key to the head of the linked list (marking it as most recently used) and return its value.
     - If no, return `-1`.
   - **PUT operation:**
     - If the key already exists, update its value and move it to the head of the linked list.
     - If the key does not exist:
       - If the cache size is at capacity, remove the least recently used item (the tail of the linked list).
       - Insert the new key-value pair at the head of the linked list and update the hash map.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:**

  - `GET`: O(1), as both the hash map lookup and linked list operations are O(1).
  - `PUT`: O(1), as both insertion/removal from the linked list and updating the hash map are O(1).

- **Expected Auxiliary Space Complexity:** O(capacity), where `capacity` is the maximum number of key-value pairs in the cache. This space is used for the doubly linked list and hash map.

## Code (C++)

```cpp
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
```

## Code (Java)

```java
class LRUCache {
    private int capacity;
    private LinkedHashMap<Integer, Integer> cache;

    LRUCache(int cap) {
        this.capacity = cap;
        this.cache = new LinkedHashMap<>(cap, 0.75f, true) {
            protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
                return size() > capacity;
            }
        };
    }
    public int get(int key) {
        return cache.getOrDefault(key, -1);
    }
    public void put(int key, int value) {
        cache.put(key, value);
    }
}
```

## Code (Python)

```python
from collections import OrderedDict

class LRUCache:
    def __init__(self, cap):
        self.cap = cap
        self.cache = OrderedDict()

    def get(self, key):
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)
        return self.cache[key]

    def put(self, key, value):
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.cap:
            self.cache.popitem(last=False)
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
