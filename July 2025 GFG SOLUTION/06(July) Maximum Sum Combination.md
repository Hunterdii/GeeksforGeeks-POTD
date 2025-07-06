---
title: "🏆 Maximum Sum Combination | GFG Solution 🔍"
keywords🏷️: ["🏆 maximum sum", "🔍 priority queue", "📍 heap", "📈 greedy", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum Sum Combination problem: find top k maximum sum pairs from two arrays using priority queue and greedy approach. 🚀"
date: 📅 2025-07-06
---

# *06. Maximum Sum Combination*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-sum-combination/1)

## **🧩 Problem Description**

You are given two integer arrays `a[]` and `b[]` of equal size. A sum combination is formed by adding one element from `a[]` and one from `b[]`, using each index pair `(i, j)` at most once. Your task is to return the **top k maximum sum combinations**, sorted in non-increasing order.

The goal is to efficiently find the k largest possible sums without generating all n² combinations, which would be inefficient for large arrays.

## **📘 Examples**

### Example 1

```cpp
Input: a[] = [3, 2], b[] = [1, 4], k = 2
Output: [7, 6]
Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6
Top 2 sums are 7 and 6.
```

### Example 2

```cpp
Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
Output: [10, 9, 9]
Explanation: The top 3 maximum possible sums are: 4 + 6 = 10, 3 + 6 = 9, and 4 + 5 = 9
```

## **🔒 Constraints**

* $1 \le a.size() = b.size() \le 10^5$
* $1 \le k \le a.size()$
* $1 \le a[i], b[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses a **Priority Queue (Max-Heap)** combined with a **Greedy Strategy** and **Visited Set** to efficiently find the k largest sums without generating all combinations:

### **Max-Heap + Greedy + Visited Tracking**

1. **Sort Both Arrays:**
   * Sort both arrays in descending order to start with the largest possible elements.
   * This ensures we begin with the maximum possible sum: `a[0] + b[0]`.

2. **Initialize Data Structures:**
   * Use a max-heap (priority queue) to always get the largest available sum.
   * Use a visited set to track already processed index pairs to avoid duplicates.
   * Store tuples of `(sum, index_i, index_j)` in the heap.

3. **Start with Maximum Sum:**
   * Push the largest possible sum `a[0] + b[0]` with indices `(0, 0)` into the heap.
   * Mark `(0, 0)` as visited.

4. **Greedy Selection:**
   * For each iteration (k times):
     * Pop the maximum sum from the heap and add it to the result.
     * From the current position `(i, j)`, explore two adjacent possibilities:
       * `(i+1, j)`: Next element from array `a` with same element from array `b`
       * `(i, j+1)`: Same element from array `a` with next element from array `b`
     * Add these new combinations to the heap if not already visited.

5. **Avoid Duplicates:**
   * Use a visited set with unique pair encoding to prevent processing the same combination twice.
   * This ensures each index pair is used at most once.

6. **Continue Until k Results:**
   * Repeat until we have collected k maximum sums.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n + k log k), where n is the size of the arrays. The sorting takes O(n log n) time, and we perform k heap operations, each taking O(log k) time in the worst case.
* **Expected Auxiliary Space Complexity:** O(k), where k is the number of elements we need to find. We use a heap of size at most k and a visited set that stores at most k unique pairs.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<>());
        sort(b.begin(), b.end(), greater<>());
        priority_queue<tuple<int, int, int>> pq;
        unordered_set<long long> vis;
        pq.emplace(a[0] + b[0], 0, 0);
        vis.insert(0);
        vector<int> res;
        while (res.size() < k) {
            int sum = get<0>(pq.top());
            int i = get<1>(pq.top());
            int j = get<2>(pq.top());
            pq.pop();
            res.push_back(sum);
            if (i + 1 < n && vis.insert((long long)(i + 1) * n + j).second)
                pq.emplace(a[i + 1] + b[j], i + 1, j);
            if (j + 1 < n && vis.insert((long long)i * n + j + 1).second)
                pq.emplace(a[i] + b[j + 1], i, j + 1);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Optimized Max-Heap with Unordered Set**

### 💡 Algorithm Steps:

1. Use unordered_set instead of set for O(1) lookup
2. Maintain max-heap for largest sums first
3. Track visited pairs efficiently
4. Early termination when k results found

```cpp
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        priority_queue<pair<int, pair<int, int>>> pq;
        unordered_set<string> vis;
        pq.push({a[0] + b[0], {0, 0}});
        vis.insert("0,0");
        vector<int> res;
        while (res.size() < k && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            res.push_back(sum);
            string key1 = to_string(i + 1) + "," + to_string(j);
            string key2 = to_string(i) + "," + to_string(j + 1);
            if (i + 1 < n && vis.find(key1) == vis.end()) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                vis.insert(key1);
            }
            if (j + 1 < n && vis.find(key2) == vis.end()) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                vis.insert(key2);
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + k log k)
* **Auxiliary Space:** 💾 O(k) - for heap and set

### ✅ **Why This Approach?**

* Faster lookup with unordered_set
* Efficient string-based key generation
* Better average case performance

## 📊 **3️⃣ Two-Pointer Merge Approach**

### 💡 Algorithm Steps:

1. Sort both arrays in descending order
2. Use merge technique to find k largest sums
3. Maintain multiple pointers for each row
4. Select maximum sum at each step

```cpp
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({a[i] + b[0], i});
        }
        vector<int> res;
        vector<int> indices(n, 0);
        while (res.size() < k && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int i = top.second;
            res.push_back(sum);
            indices[i]++;
            if (indices[i] < n) {
                pq.push({a[i] + b[indices[i]], i});
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + k log n)
* **Auxiliary Space:** 💾 O(n) - for priority queue and indices

### ✅ **Why This Approach?**

* Efficient for sparse result sets
* Systematic exploration of combinations
* Optimal when k << n²

## 📊 **4️⃣ Coordinate Compression Approach**

### 💡 Algorithm Steps:

1. Use coordinate system for pair tracking
2. Compress indices to single integer keys
3. Maintain heap with compressed coordinates
4. Efficient memory usage for large arrays

```cpp
class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        priority_queue<pair<int, int>> pq;
        unordered_set<int> vis;
        pq.push({a[0] + b[0], 0});
        vis.insert(0);
        vector<int> res;
        while (res.size() < k && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int coord = top.second;
            int i = coord / n;
            int j = coord % n;
            res.push_back(sum);
            if (i + 1 < n && vis.find((i + 1) * n + j) == vis.end()) {
                pq.push({a[i + 1] + b[j], (i + 1) * n + j});
                vis.insert((i + 1) * n + j);
            }
            if (j + 1 < n && vis.find(i * n + (j + 1)) == vis.end()) {
                pq.push({a[i] + b[j + 1], i * n + (j + 1)});
                vis.insert(i * n + (j + 1));
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + k log k)
* **Auxiliary Space:** 💾 O(k) - for heap and set

### ✅ **Why This Approach?**

* Single integer key for coordinates
* Efficient hash operations
* Reduced memory overhead

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Max-Heap with Set**          | 🟢 O(n log n + k log k)| 🟡 O(k)                 | 🚀 Optimal for small k           | 💾 Set overhead for large k          |
| 🔺 **Unordered Set Optimization** | 🟢 O(n log n + k log k)| 🟡 O(k)                 | 🔧 Faster lookup operations      | 💾 String key generation overhead    |
| ⏰ **Two-Pointer Merge**          | 🟢 O(n log n + k log n)| 🟡 O(n)                 | 🚀 Systematic exploration        | 🔄 Higher space for indices          |
| 📊 **Coordinate Compression**     | 🟢 O(n log n + k log k)| 🟡 O(k)                 | ⚡ Efficient coordinate handling  | 🔧 Coordinate calculation overhead    |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Small k, large arrays**                          | 🥇 **Max-Heap with Set**             | ★★★★★                     |
| 📊 **Balanced performance**                           | 🥈 **Coordinate Compression**        | ★★★★☆                     |
| 🎯 **Sparse results (k << n²)**                       | 🥉 **Two-Pointer Merge**            | ★★★★☆                     |
| 🚀 **Competitive programming**                        | 🏅 **Max-Heap with Set**             | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public ArrayList<Integer> topKSumPairs(int[] a, int[] b, int k) {
        int n = a.length;
        Arrays.sort(a); Arrays.sort(b);
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> y[0] - x[0]);
        Set<String> vis = new HashSet<>();
        pq.add(new int[]{a[n - 1] + b[n - 1], n - 1, n - 1});
        vis.add((n - 1) + "#" + (n - 1));
        ArrayList<Integer> res = new ArrayList<>();
        while (res.size() < k) {
            int[] top = pq.poll();
            res.add(top[0]);
            int i = top[1], j = top[2];
            if (i > 0 && vis.add((i - 1) + "#" + j))
                pq.add(new int[]{a[i - 1] + b[j], i - 1, j});
            if (j > 0 && vis.add(i + "#" + (j - 1)))
                pq.add(new int[]{a[i] + b[j - 1], i, j - 1});
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def topKSumPairs(self, a, b, k):
        n = len(a)
        a.sort()
        b.sort()
        pq = [(-(a[-1] + b[-1]), n - 1, n - 1)]
        vis = {(n - 1, n - 1)}
        res = []
        while len(res) < k:
            s, i, j = heapq.heappop(pq)
            res.append(-s)
            if i > 0 and (i - 1, j) not in vis:
                vis.add((i - 1, j))
                heapq.heappush(pq, (-(a[i - 1] + b[j]), i - 1, j))
            if j > 0 and (i, j - 1) not in vis:
                vis.add((i, j - 1))
                heapq.heappush(pq, (-(a[i] + b[j - 1]), i, j - 1))
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
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>


