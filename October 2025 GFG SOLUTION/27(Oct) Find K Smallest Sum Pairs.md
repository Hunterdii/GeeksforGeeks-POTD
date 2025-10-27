---
title: "🔢 Find K Smallest Sum Pairs | GFG Solution 🔍"
keywords🏷️: ["🔢 k smallest pairs", "🔍 min heap", "📍 priority queue", "📈 two pointers", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Find K Smallest Sum Pairs problem: efficiently find k pairs with smallest sums from two sorted arrays using optimized heap approach. 🚀"
date: 📅 2025-10-27
---

# *27. Find K Smallest Sum Pairs*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-k-smallest-sum-pairs/1)

## **🧩 Problem Description**

You are given two integer arrays `arr1[]` and `arr2[]` sorted in ascending order and an integer `k`. Your task is to find `k` pairs with the **smallest sums**, such that one element of each pair belongs to `arr1[]` and the other belongs to `arr2[]`.

Return the list of these `k` pairs, where each pair is represented as `[arr1[i], arr2[j]]`.

## **📘 Examples**

### Example 1

```cpp
Input: arr1[] = [1, 7, 11], arr2[] = [2, 4, 6], k = 3
Output: true
Explanation: All possible combinations of elements from the two arrays are:
[1, 2], [1, 4], [1, 6], [7, 2], [7, 4], [7, 6], [11, 2], [11, 4], [11, 6]. 
Among these, the three pairs with the minimum sums are [1, 2], [1, 4], [1, 6].
```

### Example 2

```cpp
Input: arr1[] = [1, 3], arr2[] = [2, 4] k = 2
Output: true
Explanation: All possible combinations are [1, 2], [1, 4], [3, 2], [3, 4]. 
Among these, the two pairs with the minimum sums are [1, 2], [3, 2].
```

## **🔒 Constraints**

* $1 \le \text{arr1.size()}, \text{arr2.size()} \le 5 \times 10^4$
* $1 \le \text{arr1}[i], \text{arr2}[j] \le 10^9$
* $1 \le k \le 10^3$

## **✅ My Approach**

The optimal approach uses a **Min-Heap (Priority Queue)** with an intelligent initialization strategy to efficiently find k smallest sum pairs:

### **Optimized Row-by-Row Heap Approach**

1. **Initialize Min-Heap:**
   * Start by pushing the first element of each row in `arr1[]` paired with `arr2[0]` into the min-heap.
   * Only push `min(arr1.size(), k)` initial pairs to optimize space.
   * Each heap entry stores: `{sum, index_i, index_j}`.

2. **Extract Minimum Pairs:**
   * Pop the top element (smallest sum) from the heap.
   * Add the corresponding pair `[arr1[i], arr2[j]]` to the result.

3. **Expand Window:**
   * After extracting pair at indices `(i, j)`, push the next pair from the same row: `(i, j+1)`.
   * This ensures we only explore necessary pairs in sorted order.

4. **Repeat Until k Pairs:**
   * Continue extracting and expanding until we have collected `k` pairs or heap becomes empty.

5. **Key Optimization:**
   * By initializing only the first column and expanding row-wise, we avoid exploring all `n*m` pairs.
   * The sorted property ensures we always get the next smallest sum.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(k*log(min(k,n))), where n is the size of arr1. We perform at most k heap operations, and the heap size is bounded by min(k, n) since we only initialize that many rows. Each heap operation takes O(log(heap_size)) time.
* **Expected Auxiliary Space Complexity:** O(min(k,n)), as the heap stores at most min(k, n) elements at any time. This is significantly better than storing all n*m pairs.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        for(int i = 0; i < min((int)arr1.size(), k); i++) pq.push({arr1[i] + arr2[0], {i, 0}});
        while(k-- && !pq.empty()) {
            auto [sum, idx] = pq.top(); pq.pop();
            auto [i, j] = idx;
            res.push_back({arr1[i], arr2[j]});
            if(j + 1 < arr2.size()) pq.push({arr1[i] + arr2[j + 1], {i, j + 1}});
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Set-Based Heap Approach**

### 💡 Algorithm Steps:

1. Use min-heap with set to track visited indices.
2. Start with pair (0,0) and expand neighbors.
3. Track visited pairs to avoid duplicates.
4. Extract k smallest pairs from heap progressively.

```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        set<pair<int,int>> vis;
        pq.push({arr1[0] + arr2[0], 0, 0});
        vis.insert({0, 0});
        while(k-- && !pq.empty()) {
            auto v = pq.top(); pq.pop();
            int i = v[1], j = v[2];
            res.push_back({arr1[i], arr2[j]});
            if(i + 1 < arr1.size() && !vis.count({i+1, j})) {
                pq.push({arr1[i+1] + arr2[j], i+1, j});
                vis.insert({i+1, j});
            }
            if(j + 1 < arr2.size() && !vis.count({i, j+1})) {
                pq.push({arr1[i] + arr2[j+1], i, j+1});
                vis.insert({i, j+1});
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(k*log(k)) - Heap operations for k pairs
* **Auxiliary Space:** 💾 O(k) - Set and heap storage

### ✅ **Why This Approach?**

* Prevents duplicate pairs effectively with set
* Handles edge cases with bounds checking
* Similar to original provided solution

## 📊 **3️⃣ Custom Comparator Heap**

### 💡 Algorithm Steps:

1. Initialize heap with first element from each row paired with arr2[0].
2. Use custom lambda comparator to compare sums directly.
3. Extract minimum and add next element from same row.
4. Continue until k pairs extracted or heap empty.

```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<vector<int>> res;
        auto cmp = [&](pair<int,int> a, pair<int,int> b) {
            return arr1[a.first] + arr2[a.second] > arr1[b.first] + arr2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
        for(int i = 0; i < min((int)arr1.size(), k); i++) pq.push({i, 0});
        while(k-- && !pq.empty()) {
            auto [i, j] = pq.top(); pq.pop();
            res.push_back({arr1[i], arr2[j]});
            if(j + 1 < arr2.size()) pq.push({i, j + 1});
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(k*log(min(k,n))) - Optimized heap size
* **Auxiliary Space:** 💾 O(min(k,n)) - Limited heap size

### ✅ **Why This Approach?**

* Most space efficient among heap approaches
* Custom comparator provides cleaner code
* Optimal for cases where k is small

## 📊 **4️⃣ Brute Force with Sorting**

### 💡 Algorithm Steps:

1. Generate all possible pairs from both arrays.
2. Store pairs with their sums in a structure.
3. Sort all pairs based on their sum values.
4. Return the first k pairs from sorted result.

```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        vector<pair<int, pair<int,int>>> pairs;
        for(int i = 0; i < arr1.size(); i++)
            for(int j = 0; j < arr2.size(); j++)
                pairs.push_back({arr1[i] + arr2[j], {arr1[i], arr2[j]}});
        sort(pairs.begin(), pairs.end());
        vector<vector<int>> res;
        for(int i = 0; i < k && i < pairs.size(); i++)
            res.push_back({pairs[i].second.first, pairs[i].second.second});
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m*log(n*m)) - Generating and sorting all pairs
* **Auxiliary Space:** 💾 O(n*m) - Storing all pairs

### ✅ **Why This Approach?**

* Simple implementation without complex data structures
* Works for any input without additional constraints
* Good for small input sizes

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1010/1112 test cases due to time constraints).

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Row-by-Row Heap**           | 🟢 O(k*log(min(k,n))) | 🟢 O(min(k,n))         | 🚀 Most space efficient           | 🔧 Requires sorted arrays            |
| 🔍 **Set-Based Heap**             | 🟢 O(k*log(k))         | 🟡 O(k)                | 📖 Prevents duplicates            | 💾 Extra set overhead                |
| 🔄 **Custom Comparator Heap**     | 🟢 O(k*log(min(k,n))) | 🟢 O(min(k,n))         | ⭐ Clean structured pairs         | 🔧 Lambda syntax complexity          |
| 📊 **Brute Force (TLE)**          | 🔴 O(n*m*log(n*m))     | 🔴 O(n*m)              | 🎯 Simple implementation          | 🐌 Inefficient for large inputs      |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Row-by-Row Heap**               | ★★★★★                     |
| 📖 **Need duplicate prevention**                      | 🥈 **Set-Based Heap**                | ★★★★☆                     |
| 🔧 **Small inputs only**                              | 🥉 **Brute Force (TLE)**             | ★★★☆☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Custom Comparator Heap**        | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<ArrayList<Integer>> kSmallestPair(int[] arr1, int[] arr2, int k) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for(int i = 0; i < Math.min(arr1.length, k); i++) pq.offer(new int[]{arr1[i] + arr2[0], i, 0});
        while(k-- > 0 && !pq.isEmpty()) {
            int[] cur = pq.poll();
            int i = cur[1], j = cur[2];
            ArrayList<Integer> pair = new ArrayList<>();
            pair.add(arr1[i]); pair.add(arr2[j]);
            res.add(pair);
            if(j + 1 < arr2.length) pq.offer(new int[]{arr1[i] + arr2[j + 1], i, j + 1});
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def kSmallestPair(self, arr1, arr2, k):
        res = []
        pq = [(arr1[i] + arr2[0], i, 0) for i in range(min(len(arr1), k))]
        heapq.heapify(pq)
        while k and pq:
            s, i, j = heapq.heappop(pq)
            res.append([arr1[i], arr2[j]])
            if j + 1 < len(arr2): heapq.heappush(pq, (arr1[i] + arr2[j + 1], i, j + 1))
            k -= 1
        return res
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>



