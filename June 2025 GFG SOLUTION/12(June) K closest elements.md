---
title: "🎯 K Closest Elements | GFG Solution 🔍"
keywords🏷️: ["🎯 k closest", "🔍 binary search", "📍 two pointers", "📈 sorted array", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the K Closest Elements problem: find k closest elements to target x in sorted array using binary search and two pointers. 🚀"
date: 📅 2025-06-12
---

# *12. K Closest Elements*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/k-closest-elements3619/1)

## **🧩 Problem Description**

You are given a **sorted array** `arr[]` of unique integers, an integer `k`, and a target value `x`. Return exactly **k elements** from the array closest to `x`, **excluding x if it exists**.

An element `a` is closer to `x` than `b` if:
- `|a - x| < |b - x|`, or
- `|a - x| == |b - x|` and `a > b` (prefer the larger element if tied)

Return the k closest elements in **order of closeness**.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 3, 4, 10, 12], k = 2, x = 4
Output: 3 1
Explanation: 4 is excluded. Closest elements to 4 are: 
- 3 (distance = 1)
- 1 (distance = 3)
So, the 2 closest elements are: 3 1
```

### Example 2

```cpp
Input: arr[] = [12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56], k = 4, x = 35
Output: 39 30 42 45
Explanation: 
- First closest: 39 (distance = 4)
- Second closest: 30 (distance = 5)  
- Third closest: 42 (distance = 7)
- Fourth closest: 45 (distance = 10)
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le k \le \text{arr.size()}$
* $1 \le x \le 10^6$
* $1 \le \text{arr}[i] \le 10^6$

## **✅ My Approach**

The optimal approach uses **Binary Search** to find the insertion point, followed by **Two Pointers** technique to find the k closest elements:

### **Binary Search + Two Pointers**

1. **Find Insertion Point:**
   * Use binary search to find the largest element smaller than `x`.
   * This gives us the optimal starting position for two pointers.

2. **Initialize Two Pointers:**
   * `i = p` (pointing to largest element < x)
   * `j = p + 1` (pointing to smallest element ≥ x)
   * If `arr[j] == x`, increment `j` to skip the target element.

3. **Expand Outward:**
   * Compare distances `|arr[i] - x|` and `|arr[j] - x|`.
   * Choose the closer element and move the corresponding pointer.
   * If distances are equal, prefer the larger element.

4. **Handle Remaining Elements:**
   * If one pointer goes out of bounds, collect remaining elements from the other side.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(log n + k), where n is the array size. Binary search takes O(log n) and collecting k elements takes O(k).
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for pointers and variables (excluding the output array).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    vector<int> printKClosest(vector<int> a, int k, int x) {
        int n = a.size(), l = 0, h = n - 1, p = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (a[m] < x) p = m, l = m + 1;
            else h = m - 1;
        }
        int i = p, j = p + 1;
        if (j < n && a[j] == x) j++;
        vector<int> r;
        while (i >= 0 && j < n && r.size() < k)
            r.push_back(abs(a[i] - x) < abs(a[j] - x) ? a[i--] : a[j++]);
        while (i >= 0 && r.size() < k) r.push_back(a[i--]);
        while (j < n && r.size() < k) r.push_back(a[j++]);
        return r;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two Pointers with Linear Search**

### 💡 Algorithm Steps:

1. Find the position where `x` would be inserted using linear search.
2. Use two pointers to expand outward from that position.
3. Compare distances and pick the closer element.

```cpp
class Solution {
  public:
    vector<int> printKClosest(vector<int> a, int k, int x) {
        int n = a.size(), pos = 0;
        while (pos < n && a[pos] < x) pos++;
        int i = pos - 1, j = pos;
        if (j < n && a[j] == x) j++;
        vector<int> r;
        while (i >= 0 && j < n && r.size() < k)
            r.push_back(abs(a[i] - x) < abs(a[j] - x) ? a[i--] : a[j++]);
        while (i >= 0 && r.size() < k) r.push_back(a[i--]);
        while (j < n && r.size() < k) r.push_back(a[j++]);
        return r;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + k)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Simple linear search approach.
* Good when array size is small or unsorted.

## 📊 **3️⃣ Priority Queue (Min Heap)**

### 💡 Algorithm Steps:

1. Create a min-heap with custom comparator based on distance from x.
2. Add all elements except x to the heap.
3. Extract k smallest elements from the heap.

```cpp
class Solution {
  public:
    vector<int> printKClosest(vector<int> a, int k, int x) {
        auto cmp = [x](int a, int b) {
            int distA = abs(a - x), distB = abs(b - x);
            return distA == distB ? a < b : distA > distB;
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int num : a) {
            if (num != x) pq.push(num);
        }
        vector<int> r;
        while (r.size() < k && !pq.empty()) {
            r.push_back(pq.top());
            pq.pop();
        }
        return r;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + k log n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Handles unsorted arrays naturally.
* Good for small k values.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**           | ⏱️ **Time Complexity**           | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ------------------------- | -------------------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Binary Search**      | 🟢 O(log n + k)                  | 🟢 O(1)                 | ⚡ Fastest for sorted arrays       | 🧮 Requires sorted input              |
| 🔄 **Linear Search**      | 🟡 O(n + k)                      | 🟢 O(1)                 | 🔧 Simple, works with unsorted    | 🐢 Slower for large arrays           |
| 📦 **Priority Queue**     | 🔸 O(n log n + k log n)          | 🔸 O(n)                 | 🪄 Natural ordering by distance   | 🚫 High time and space complexity     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ Large sorted array, performance critical        | 🥇 **Binary Search**            | ★★★★★                     |
| 🔧 Small array, simplicity preferred              | 🥈 **Linear Search**            | ★★★★☆                     |
| 📊 Need flexible distance-based ordering          | 🥉 **Priority Queue**           | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    int[] printKClosest(int[] a, int k, int x) {
        int n = a.length, l = 0, h = n - 1, p = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (a[m] < x) { p = m; l = m + 1; }
            else h = m - 1;
        }
        int i = p, j = p + 1;
        if (j < n && a[j] == x) j++;
        int[] r = new int[k]; int idx = 0;
        while (i >= 0 && j < n && idx < k)
            r[idx++] = Math.abs(a[i] - x) < Math.abs(a[j] - x) ? a[i--] : a[j++];
        while (i >= 0 && idx < k) r[idx++] = a[i--];
        while (j < n && idx < k) r[idx++] = a[j++];
        return r;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def printKClosest(self, a, k, x):
        n, l, h, p = len(a), 0, len(a) - 1, -1
        while l <= h:
            m = (l + h) // 2
            if a[m] < x: p = m; l = m + 1
            else: h = m - 1
        i, j, r = p, p + 1, []
        if j < n and a[j] == x: j += 1
        while i >= 0 and j < n and len(r) < k:
            r.append(a[i] if abs(a[i] - x) < abs(a[j] - x) else a[j])
            if abs(a[i] - x) < abs(a[j] - x): i -= 1
            else: j += 1
        while i >= 0 and len(r) < k: r.append(a[i]); i -= 1
        while j < n and len(r) < k: r.append(a[j]); j += 1
        return r
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
