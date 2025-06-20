---
title: "🏀 Group Balls by Sequence | GFG Solution 🔍"
keywords🏷️: ["🏀 group balls", "🔍 frequency map", "🔢 consecutive sequence", "🗂️ hash map", "📊 counting sort", "🚀 coding interview", "🧩 greedy", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Group Balls by Sequence problem: determine if balls can be grouped into consecutive sequences of length k using frequency mapping. 🚀"
date: 📅 2025-06-20
---

# *20. Group Balls by Sequence*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/group-balls-by-sequence/1)

## **🧩 Problem Description**

You are given an array `arr[]` of positive integers, where each element `arr[i]` represents the number written on the i-th ball, and a positive integer `k`. Your task is to determine whether it is possible to rearrange all the balls into groups such that:

- Each group contains exactly **k balls**.
- The numbers in each group are **consecutive integers**.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [10, 1, 2, 11], k = 2
Output: true
Explanation: The balls can be rearranged as [1, 2], [10, 11]. 
There are two groups of size 2. Each group has 2 consecutive numbers.
```

### Example 2

```cpp
Input: arr[] = [7, 8, 9, 10, 11], k = 2
Output: false
Explanation: The balls cannot be rearranged into groups of 2, 
since there are 5 balls, and 5 balls cannot be divided into groups of 2.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $0 \le \text{arr}[i] \le 10^5$
* $1 \le k \le 10^3$

## **✅ My Approach**

The optimal approach uses **Frequency Mapping** with **Greedy Algorithm**:

### **Frequency Map + Greedy Processing**

1. **Check Divisibility:**
   * First, verify if the total number of balls is divisible by `k`.
   * If not, return `false` immediately.

2. **Build Frequency Map:**
   * Use a `TreeMap` (or sorted map) to store frequency of each number.
   * TreeMap ensures we process numbers in ascending order.

3. **Greedy Group Formation:**
   * For each number with non-zero frequency, try to form consecutive groups.
   * Starting from current number, check if next `k-1` consecutive numbers exist.
   * Deduct the required frequency from all numbers in the sequence.

4. **Validation:**
   * If any consecutive number has insufficient frequency, return `false`.
   * Continue until all numbers are processed.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n + n * k), where n is the array size. Building the frequency map takes O(n log n) time, and processing each element with k consecutive checks takes O(n * k) time.
* **Expected Auxiliary Space Complexity:** O(n), as we use a frequency map to store at most n distinct elements.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        map<int, int> m;
        for (int x : arr) m[x]++;
        for (auto& p : m) {
            int v = p.first, f = p.second;
            if (f == 0) continue;
            for (int i = 1; i < k; i++) {
                if (m[v + i] < f) return false;
                m[v + i] -= f;
            }
        }
        return true;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ TreeMap with Iterator Optimization**

### 💡 Algorithm Steps:

1. Build a sorted `map<int,int>` of frequencies.
2. Traverse with an iterator, skipping zero counts.
3. For each non-zero entry `(start, cnt)`, deduct `cnt` from each of the next `k` keys.
4. Return false if any required key has insufficient count.

```cpp
class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        map<int, int> freq;
        for (int val : arr) freq[val]++;
        
        auto it = freq.begin();
        while (it != freq.end()) {
            if (it->second == 0) { ++it; continue; }
            int start = it->first, cnt = it->second;
            for (int i = 0; i < k; i++) {
                if (freq[start + i] < cnt) return false;
                freq[start + i] -= cnt;
            }
            ++it;
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * k + n log n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Iterator-based traversal avoids redundant lookups.
* Cleaner code structure with early exits.

## 📊 **3️⃣ Counting Sort Based Approach**

### 💡 Algorithm Steps:

1. Find `minVal` and `maxVal`.
2. Build an array `freq` of size `maxVal–minVal+1`.
3. For each index `i`, if `freq[i]>0`, deduct from the next `k` slots.
4. Fail early if any slot lacks enough cards.

```cpp
class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        int mn = *min_element(arr.begin(), arr.end());
        int mx = *max_element(arr.begin(), arr.end());
        vector<int> freq(mx - mn + 1);
        for (int v : arr) freq[v - mn]++;
        for (int i = 0; i < freq.size(); i++) {
            int cnt = freq[i];
            if (cnt == 0) continue;
            for (int j = 1; j < k; j++) {
                if (i + j >= freq.size() || freq[i + j] < cnt) 
                    return false;
                freq[i + j] -= cnt;
            }
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + range * k)
* **Auxiliary Space:** 💾 O(range)

### ✅ **Why This Approach?**

* O(1) array access instead of O(log n) map access.
* Better performance for bounded integer ranges.

## 📊 **4️⃣ Greedy with Sliding Window**

### 💡 Algorithm Steps:

1. Sort the array.
2. Build an `unordered_map<int,int>` of counts.
3. Iterate through sorted values; when `cnt>0`, deduct from next `k` consecutive keys.
4. Return false on any shortage.

```cpp
class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        for (int x : arr) {
            int cnt = freq[x];
            if (cnt == 0) continue;
            for (int i = 0; i < k; i++) {
                if (freq[x + i] < cnt) return false;
                freq[x + i] -= cnt;
            }
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + n * k)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Unordered_map for O(1) average access time.
* Sorted processing ensures optimal grouping.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**           | ⏱️ **Time Complexity**           | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ------------------------- | -------------------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Map Ultra-Optimized**| 🟢 O(n log n + n * k)            | 🟢 O(n)                 | ⚡ Cleanest, most readable         | 🧮 Map overhead                      |
| 🔄 **TreeMap Iterator**   | 🟢 O(n log n + n * k)            | 🟢 O(n)                 | 🔧 Iterator efficiency             | 🐢 Still map-based                   |
| 🔺 **Counting Sort**      | 🟢 O(n + range * k)              | 🟢 O(range)             | 🚀 O(1) access, fastest for bounded| 🧮 Only works for bounded ranges    |
| 📊 **Greedy Sliding**     | 🟢 O(n log n + n * k)            | 🟢 O(n)                 | 🏎️ Unordered_map speed            | 💾 Extra sorting step               |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ General case, clean code                        | 🥇 **Map Ultra-Optimized**     | ★★★★★                     |
| 🔧 Bounded integer range (≤ 10^5)                 | 🥈 **Counting Sort**            | ★★★★★                     |
| 📊 Large datasets, hash-friendly                  | 🥉 **Greedy Sliding**           | ★★★★☆                     |
| 🏎️ Iterator-heavy processing                      | 🏅 **TreeMap Iterator**         | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public boolean validgroup(int[] arr, int k) {
        Map<Integer, Integer> m = new TreeMap<>();
        for (int x : arr) m.put(x, m.getOrDefault(x, 0) + 1);
        for (Map.Entry<Integer, Integer> e : m.entrySet()) {
            int v = e.getKey(), f = e.getValue();
            if (f == 0) continue;
            for (int i = 1; i < k; i++) {
                if (m.getOrDefault(v + i, 0) < f) return false;
                m.put(v + i, m.get(v + i) - f);
            }
        }
        return true;
    }
}
```

## **🐍 Code (Python)**

```python
from collections import Counter
class Solution:
    def validgroup(self, arr, k):
        m = Counter(arr)
        for v in sorted(m.keys()):
            f = m[v]
            if f == 0: continue
            for i in range(1, k):
                if m[v + i] < f: return False
                m[v + i] -= f
        return True
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
