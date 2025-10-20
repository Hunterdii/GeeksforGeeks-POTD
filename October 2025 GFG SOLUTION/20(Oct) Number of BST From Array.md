---
title: "🌳 Number of BST From Array | GFG Solution 🔍"
keywords🏷️: ["🌳 binary search tree", "🔢 catalan numbers", "📊 dynamic programming", "📈 combinatorics", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Number of BST From Array problem: count unique BSTs possible with each element as root using Catalan numbers and dynamic programming. 🚀"
date: 📅 2025-10-20
---

# *20. Number of BST From Array*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/number-of-bst-from-array/1)

## **🧩 Problem Description**

You are given an integer array `arr[]` containing distinct elements. Your task is to return an array where the **ith element** denotes the number of **unique BSTs** formed when `arr[i]` is chosen as the root.

In a Binary Search Tree (BST), all elements in the left subtree are smaller than the root, and all elements in the right subtree are greater than the root. The problem requires calculating how many structurally unique BSTs can be formed for each element when it serves as the root node.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 1, 3]
Output: [1, 2, 2]
Explanation: 
- When 2 is root: left subtree has 1 element (1), right subtree has 1 element (3)
  Number of BSTs = C(1) * C(1) = 1 * 1 = 1
- When 1 is root: left subtree has 0 elements, right subtree has 2 elements (2, 3)
  Number of BSTs = C(0) * C(2) = 1 * 2 = 2
- When 3 is root: left subtree has 2 elements (1, 2), right subtree has 0 elements
  Number of BSTs = C(2) * C(0) = 2 * 1 = 2
```

### Example 2

```cpp
Input: arr[] = [2, 1]
Output: [1, 1]
Explanation:
- When 2 is root: left has 1 element (1), right has 0 elements
  Number of BSTs = C(1) * C(0) = 1 * 1 = 1
- When 1 is root: left has 0 elements, right has 1 element (2)
  Number of BSTs = C(0) * C(1) = 1 * 1 = 1
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 6$
* $1 \le \text{arr}[i] \le 15$

## **✅ My Approach**

The optimal solution uses **Catalan Numbers** combined with **sorting and indexing** to determine BST counts efficiently:

### **Catalan Number with Dynamic Programming**

1. **Sort and Index Mapping:**
   * Create pairs of (value, original_index) for each array element.
   * Sort these pairs by value to determine relative ordering.
   * After sorting, the position `i` tells us how many elements are smaller (left subtree size = i) and how many are larger (right subtree size = n - i - 1).

2. **Precompute Catalan Numbers:**
   * The nth Catalan number C(n) represents the number of structurally unique BSTs with n nodes.
   * Use dynamic programming: C(n) = Σ(C(i) * C(n-i-1)) for i from 0 to n-1.
   * Precompute all Catalan numbers from 0 to n.

3. **Calculate BST Count for Each Element:**
   * For element at sorted position i:
     * Left subtree can have C(i) unique structures (i smaller elements)
     * Right subtree can have C(n-i-1) unique structures (n-i-1 larger elements)
     * Total BSTs with this element as root = C(i) * C(n-i-1)

4. **Map Back to Original Indices:**
   * Store results at original positions using the saved indices.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n² + n log n), as we perform O(n²) operations to compute Catalan numbers using nested loops and O(n log n) for sorting the array. The overall complexity is dominated by the Catalan computation and sorting.
* **Expected Auxiliary Space Complexity:** O(n), as we use additional space for storing pairs (value, index), Catalan numbers array, and result array, all proportional to the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> p(n);
        for (int i = 0; i < n; i++) p[i] = {arr[i], i};
        sort(p.begin(), p.end());
        vector<long> c(n + 1);
        c[0] = c[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) 
                c[i] += c[j] * c[i - j - 1];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) 
            res[p[i].second] = c[i] * c[n - i - 1];
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Formula-Based Catalan Approach**

### 💡 Algorithm Steps:

1. Sort array elements with their original indices preserved.
2. Precompute Catalan numbers using direct formula with factorials.
3. For each element, multiply left and right Catalan numbers based on position.
4. Map results back to original indices for final output.

```cpp
class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> idx(n);
        for (int i = 0; i < n; i++) idx[i] = {arr[i], i};
        sort(idx.begin(), idx.end());
        vector<long> f(2 * n + 1);
        f[0] = 1;
        for (int i = 1; i <= 2 * n; i++) f[i] = f[i - 1] * i;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            long left = f[2 * i] / (f[i] * f[i + 1]);
            long right = f[2 * (n - i - 1)] / (f[n - i - 1] * f[n - i]);
            ans[idx[i].second] = left * right;
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Dominated by sorting operation
* **Auxiliary Space:** 💾 O(n) - Factorial and sorting arrays

### ✅ **Why This Approach?**

* Direct mathematical formula implementation
* Avoids nested loops for Catalan computation
* Efficient for moderate array sizes

## 📊 **3️⃣ DP Memoization Approach**

### 💡 Algorithm Steps:

1. Create index mapping by sorting elements with positions.
2. Build Catalan numbers using dynamic programming with memoization.
3. Cache computed Catalan values to avoid redundant calculations.
4. Calculate BST counts by retrieving cached Catalan values.

```cpp
class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        map<pair<int,int>, int> m;
        for (int i = 0; i < n; i++) m[{arr[i], i}] = i;
        sort(arr.begin(), arr.end());
        unordered_map<int,long> cat;
        function<long(int)> getCat = [&](int x) {
            if (x <= 1) return 1L;
            if (cat.count(x)) return cat[x];
            long val = 0;
            for (int i = 0; i < x; i++) val += getCat(i) * getCat(x - i - 1);
            return cat[x] = val;
        };
        vector<int> res(n);
        int pos = 0;
        for (auto& [p, idx] : m) {
            res[idx] = getCat(pos) * getCat(n - pos - 1);
            pos++;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² + n log n) - DP computation plus sorting
* **Auxiliary Space:** 💾 O(n) - Memoization cache and auxiliary structures

### ✅ **Why This Approach?**

* Avoids redundant Catalan number calculations
* Flexible memoization for repeated queries
* Natural recursive structure with caching

## 📊 **4️⃣ Binomial Coefficient Approach**

### 💡 Algorithm Steps:

1. Sort elements while maintaining original index information.
2. Compute Catalan numbers using binomial coefficient formula C(2n,n)/(n+1).
3. Use Pascal's triangle method to calculate binomial coefficients efficiently.
4. Multiply left and right subtree Catalan counts for each root position.

```cpp
class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) { return arr[i] < arr[j]; });
        auto catalan = [](int k) {
            if (k <= 1) return 1L;
            long c = 1;
            for (int i = 0; i < k; i++) c = c * (2 * k - i) / (i + 1);
            return c / (k + 1);
        };
        vector<int> res(n);
        for (int i = 0; i < n; i++) 
            res[ord[i]] = catalan(i) * catalan(n - i - 1);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² + n log n) - Catalan computation for each element
* **Auxiliary Space:** 💾 O(n) - Index ordering array

### ✅ **Why This Approach?**

* Mathematically elegant binomial representation
* No need for full factorial precomputation
* Compact code with clear mathematical intent

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔢 **DP Catalan**                 | 🟢 O(n² + n log n)     | 🟢 O(n)                 | 🎯 Simple iterative logic         | 🐌 Nested loops for Catalan          |
| 📐 **Formula-Based**              | 🟢 O(n log n)          | 🟡 O(n)                 | 🚀 No nested Catalan loops        | 🔧 Overflow risk with factorials     |
| 💾 **DP Memoization**             | 🟡 O(n² + n log n)     | 🟡 O(n)                 | ♻️ Reuses computed values         | 📦 Extra cache overhead              |
| 🎲 **Binomial Coefficient**       | 🟡 O(n² + n log n)     | 🟢 O(n)                 | 📊 Mathematical elegance          | 🧮 Complex coefficient calculation   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Small to medium arrays**                         | 🥇 **DP Catalan**                    | ★★★★★                     |
| 📖 **Large arrays optimal speed**                     | 🥈 **Formula-Based**                 | ★★★★★                     |
| 🔧 **Multiple queries same size**                     | 🥉 **DP Memoization**                | ★★★★☆                     |
| 🎯 **Space efficiency priority**                      | 🏅 **Binomial Coefficient**          | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> countBSTs(int[] arr) {
        int n = arr.length;
        int[][] p = new int[n][2];
        for (int i = 0; i < n; i++) {
            p[i][0] = arr[i];
            p[i][1] = i;
        }
        Arrays.sort(p, (a, b) -> a[0] - b[0]);
        long[] c = new long[n + 1];
        c[0] = c[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) 
                c[i] += c[j] * c[i - j - 1];
        }
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) res.add(0);
        for (int i = 0; i < n; i++) 
            res.set(p[i][1], (int)(c[i] * c[n - i - 1]));
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countBSTs(self, arr):
        n = len(arr)
        p = sorted((arr[i], i) for i in range(n))
        c = [0] * (n + 1)
        c[0] = c[1] = 1
        for i in range(2, n + 1):
            for j in range(i):
                c[i] += c[j] * c[i - j - 1]
        res = [0] * n
        for i in range(n):
            res[p[i][1]] = c[i] * c[n - i - 1]
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
