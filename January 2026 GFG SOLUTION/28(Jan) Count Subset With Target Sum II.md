---
title: "🔢 Count Subset With Target Sum II | GFG Solution 🔍"
keywords🏷️: ["🔢 subset sum", "🔍 meet in the middle", "📍 divide and conquer", "📈 hash map", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Count Subset With Target Sum II: find the number of subsets with sum equal to k using meet-in-the-middle technique for optimal performance. 🚀"
date: 📅 2025-01-28
---

# *28. Count Subset With Target Sum II*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-the-subset-with-sum-equal-to-k/1)

## **🧩 Problem Description**

You are given an array `arr[]` and an integer `k`. Your task is to find the **count of subsets** whose sum equals `k`.

A subset is any combination of elements from the array (including the empty subset). The goal is to efficiently count all possible subsets that sum to the target value `k`.

**Note:** It is guaranteed that the number of valid subsets will fit within a 32-bit integer.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 3, 2], k = 3
Output: 2
Explanation: The two subsets whose sum equals k are [1, 2] and [3].
```

### Example 2

```cpp
Input: arr[] = [4, 2, 3, 1, 2], k = 4
Output: 3
Explanation: The three subsets whose sum equals k are [4], [2, 2] and [3, 1].
```

### Example 3

```cpp
Input: arr[] = [10, 20, 30], k = 25
Output: 0
Explanation: No subsets exist with sum equal to k.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 40$
* $-10^7 \le \text{arr}[i], k \le 10^7$

## **✅ My Approach**

The optimal solution uses the **Meet-in-the-Middle** technique, which is perfect for subset problems with constraints up to n ≤ 40:

### **Meet-in-the-Middle with Hash Map**

1. **Split Array:**
   * Divide the array into two halves of approximately equal size.
   * This reduces the problem space from O(2^n) to O(2^(n/2)).

2. **Generate Subset Sums:**
   * For the left half, recursively generate all possible subset sums and store their frequencies in a hash map.
   * For the right half, do the same and store in another hash map.

3. **Combine Results:**
   * For each sum `s` in the left half, check if `k - s` exists in the right half.
   * If it exists, multiply their frequencies to get the count of valid pairs.
   * Accumulate all such counts to get the final answer.

4. **Recursive Generation:**
   * Use a recursive lambda function to explore both choices: include or exclude current element.
   * Base case: when we've processed all elements, increment frequency of current sum.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(2^(n/2) × n), where n is the size of the array. We generate all 2^(n/2) subsets for each half, and for each subset, we perform O(n) operations in the worst case to calculate the sum. The final combination step takes O(2^(n/2)) to iterate through one map and perform constant-time lookups in the other.
* **Expected Auxiliary Space Complexity:** O(2^(n/2)), as we store all possible subset sums for both halves in hash maps. In the worst case, each half can have up to 2^(n/2) unique subset sums, and we also use O(n) recursion stack space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size(), m = n / 2, res = 0;
        unordered_map<int, int> lf, rf;
        function<void(int, int, int, unordered_map<int, int>&)> gen = [&](int i, int e, int s, unordered_map<int, int>& f) {
            if (i == e) { f[s]++; return; }
            gen(i + 1, e, s + arr[i], f);
            gen(i + 1, e, s, f);
        };
        gen(0, m, 0, lf);
        gen(m, n, 0, rf);
        for (auto& [s, c] : lf) if (rf.count(k - s)) res += c * rf[k - s];
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative Bitmask Approach**

### 💡 Algorithm Steps:

1. Split array into two halves for divide and conquer optimization.
2. Use bitmask iteration to generate all possible subset sums for each half.
3. Store frequency of each subset sum in hash maps.
4. For each sum in left half, find complement in right half and multiply frequencies.

```cpp
class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size(), m = n / 2, res = 0;
        unordered_map<int, int> lf, rf;
        for (int mask = 0; mask < (1 << m); mask++) {
            int s = 0;
            for (int i = 0; i < m; i++) if (mask & (1 << i)) s += arr[i];
            lf[s]++;
        }
        for (int mask = 0; mask < (1 << (n - m)); mask++) {
            int s = 0;
            for (int i = 0; i < n - m; i++) if (mask & (1 << i)) s += arr[m + i];
            rf[s]++;
        }
        for (auto& [s, c] : lf) if (rf.count(k - s)) res += c * rf[k - s];
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(2^(n/2) × n) - Generate subsets for both halves with bit operations
* **Auxiliary Space:** 💾 O(2^(n/2)) - Store subset sums in hash maps

### ✅ **Why This Approach?**

* Avoids recursion overhead with iterative generation
* Clear bit manipulation for subset enumeration
* Better for understanding meet-in-the-middle technique

## 📊 **3️⃣ Dynamic Programming Approach**

### 💡 Algorithm Steps:

1. Use DP to count subsets with specific sums in each half.
2. Create frequency maps for achievable sums in left and right halves.
3. Build DP table iteratively for each element.
4. Combine results by matching complementary sums.

```cpp
class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size(), m = n / 2, res = 0;
        map<int, int> lf, rf;
        lf[0] = 1;
        for (int i = 0; i < m; i++) {
            map<int, int> temp = lf;
            for (auto& [s, c] : lf) temp[s + arr[i]] += c;
            lf = temp;
        }
        rf[0] = 1;
        for (int i = m; i < n; i++) {
            map<int, int> temp = rf;
            for (auto& [s, c] : rf) temp[s + arr[i]] += c;
            rf = temp;
        }
        for (auto& [s, c] : lf) if (rf.count(k - s)) res += c * rf[k - s];
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(2^(n/2) × log(2^(n/2))) - Map operations for each subset
* **Auxiliary Space:** 💾 O(2^(n/2)) - DP state storage

### ✅ **Why This Approach?**

* Builds solution incrementally element by element
* More intuitive for DP-familiar programmers
* Easier to extend for weighted variants

## 📊 **4️⃣ Optimized Vector-Based Storage**

### 💡 Algorithm Steps:

1. Generate all subset sums using vectors instead of hash maps.
2. Sort one vector for binary search optimization.
3. For each sum in first vector, binary search for complement.
4. Count matching pairs efficiently.

```cpp
class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size(), m = n / 2, res = 0;
        vector<int> lv, rv;
        for (int mask = 0; mask < (1 << m); mask++) {
            int s = 0;
            for (int i = 0; i < m; i++) if (mask & (1 << i)) s += arr[i];
            lv.push_back(s);
        }
        for (int mask = 0; mask < (1 << (n - m)); mask++) {
            int s = 0;
            for (int i = 0; i < n - m; i++) if (mask & (1 << i)) s += arr[m + i];
            rv.push_back(s);
        }
        sort(rv.begin(), rv.end());
        for (int s : lv) {
            int t = k - s;
            res += upper_bound(rv.begin(), rv.end(), t) - lower_bound(rv.begin(), rv.end(), t);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(2^(n/2) × (n + log(2^(n/2)))) - Sorting and binary search
* **Auxiliary Space:** 💾 O(2^(n/2)) - Vector storage

### ✅ **Why This Approach?**

* Cache-friendly vector access patterns
* Binary search for efficient counting
* Good for competitive programming constraints

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Recursive Lambda**           | 🟢 O(2^(n/2) × n)      | 🟢 O(2^(n/2))           | 🚀 Clean and concise              | 🔧 Recursion stack overhead          |
| 🎯 **Iterative Bitmask**          | 🟢 O(2^(n/2) × n)      | 🟢 O(2^(n/2))           | 📖 No recursion overhead          | 🔢 Bit manipulation complexity       |
| 📊 **Dynamic Programming**        | 🟡 O(2^(n/2) × log n)  | 🟢 O(2^(n/2))           | 🎯 Incremental building           | 🐌 Map overhead                      |
| 🔍 **Vector Binary Search**       | 🟡 O(2^(n/2) × log n)  | 🟢 O(2^(n/2))           | ⚡ Cache-friendly                 | 🔧 Sorting required                  |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Recursive Lambda**              | ★★★★★                     |
| 📖 **Avoid recursion**                                | 🥈 **Iterative Bitmask**             | ★★★★☆                     |
| 🔧 **DP understanding**                               | 🥉 **Dynamic Programming**           | ★★★★☆                     |
| 🎯 **Cache optimization**                             | 🏅 **Vector Binary Search**          | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int countSubset(int[] arr, int k) {
        int n = arr.length, m = n / 2, res = 0;
        Map<Integer, Integer> lf = new HashMap<>(), rf = new HashMap<>();
        gen(arr, 0, m, 0, lf);
        gen(arr, m, n, 0, rf);
        for (var e : lf.entrySet()) res += e.getValue() * rf.getOrDefault(k - e.getKey(), 0);
        return res;
    }
    void gen(int[] arr, int i, int e, int s, Map<Integer, Integer> f) {
        if (i == e) { f.merge(s, 1, Integer::sum); return; }
        gen(arr, i + 1, e, s + arr[i], f);
        gen(arr, i + 1, e, s, f);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countSubset(self, arr, k):
        n, m = len(arr), len(arr) // 2
        lf, rf = {}, {}
        def gen(i, e, s, f):
            if i == e: f[s] = f.get(s, 0) + 1; return
            gen(i + 1, e, s + arr[i], f)
            gen(i + 1, e, s, f)
        gen(0, m, 0, lf)
        gen(m, n, 0, rf)
        return sum(c * rf.get(k - s, 0) for s, c in lf.items())
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
