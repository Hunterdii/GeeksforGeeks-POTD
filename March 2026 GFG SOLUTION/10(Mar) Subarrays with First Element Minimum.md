---
title: "🔢 Subarrays with First Element Minimum | GFG Solution 🔍"
keywords🏷️: ["🔢 subarrays minimum", "🔍 monotonic stack", "📍 next smaller element", "📈 greedy counting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Subarrays with First Element Minimum problem: count subarrays where the first element is the minimum using monotonic stack technique. 🚀"
date: 📅 2025-03-10
---

# *10. Subarrays with First Element Minimum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/subarrays-with-first-element-minimum/1)

## **🧩 Problem Description**

You are given an integer array `arr[]`. Your task is to **count the number of subarrays** where the **first element is the minimum element** of that subarray.

A subarray is valid if its first element is **not greater than** any other element in that subarray.

## **📘 Examples**

### Example 1

```
Input: arr[] = [1, 2, 1]
Output: 5
Explanation:
All possible subarrays are:
[1], [1, 2], [1, 2, 1], [2], [2, 1], [1]
Valid subarrays are:
[1], [1, 2], [1, 2, 1], [2], [1] → total 5
```

### Example 2

```
Input: arr[] = [1, 3, 5, 2]
Output: 8
Explanation:
Valid subarrays are: [1], [1, 3], [1, 3, 5], [1, 3, 5, 2], [3], [3, 5], [5], [2] → total 8
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 5 \times 10^4$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses a **Monotonic Stack** traversed from **right to left** to efficiently determine for each index how far the subarray can extend while keeping the first element as the minimum:

### **Monotonic Stack (Right to Left)**

1. **Key Observation:**
   * For any index `i`, `arr[i]` remains the minimum of subarray `arr[i..j]` as long as no element in `arr[i+1..j]` is strictly less than `arr[i]`.
   * So we need to find the **next index to the right** where a strictly smaller element appears — call it `nxt`.
   * The number of valid subarrays starting at `i` is exactly `nxt - i`.

2. **Traverse Right to Left:**
   * Maintain an array-based monotonic stack that stores indices in increasing order of their values (from bottom to top).
   * For each index `i` (moving right to left), pop all stack entries whose corresponding values are **≥ arr[i]** — those are no longer useful as "next smaller" boundaries.
   * The top of the stack now holds the index of the next element strictly smaller than `arr[i]`.

3. **Count Contribution:**
   * If the stack is empty, all indices from `i` to `n-1` are valid, so add `n - i`.
   * Otherwise, add `st[top] - i`, where `st[top]` is the nearest smaller boundary.

4. **Push Current Index:**
   * Push `i` onto the stack for future elements to use as their boundary.

5. **Accumulate and Return:**
   * Sum all contributions and return the total count.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), as each element is pushed onto and popped from the stack at most once, resulting in a total of at most 2n stack operations across the entire traversal.
* **Expected Auxiliary Space Complexity:** O(n), as the stack can hold at most n indices in the worst case (e.g., a strictly decreasing array where no element is ever popped).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size(), top = -1, ans = 0;
        vector<int> st(n);
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && arr[st[top]] >= arr[i]) top--;
            ans += ((top < 0 ? n : st[top]) - i);
            st[++top] = i;
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Standard Stack Approach**

### 💡 Algorithm Steps:

1. Traverse array from right to left using a standard STL monotonic stack.
2. For each index, pop elements from the stack while they are greater than or equal to the current element.
3. The stack top gives the next strictly smaller element's index — this becomes the right boundary.
4. Add `(boundary - i)` to the answer and push the current index.

```cpp
class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        stack<int> st;
        int ans = 0, n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            int nxt = st.empty() ? n : st.top();
            ans += nxt - i;
            st.push(i);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) — Each element is pushed and popped at most once
* **Auxiliary Space:** 💾 O(n) — Stack can hold up to n elements

### ✅ **Why This Approach?**

* Most readable and standard implementation using STL.
* Clear monotonic stack pattern with intuitive variable naming.
* Easy to debug and verify correctness.

## 📊 **3️⃣ Next Smaller Precomputation**

### 💡 Algorithm Steps:

1. Precompute the next strictly smaller element's index for each position using a monotonic stack in a separate pass.
2. Store boundaries in a `nxt[]` array; default value is `n` (meaning no smaller element exists).
3. In a second pass, sum up `nxt[i] - i` for all indices to get the final count.

```cpp
class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> nxt(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) nxt[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans += nxt[i] - i;
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) — Two independent linear passes through the array
* **Auxiliary Space:** 💾 O(n) — Extra `nxt[]` array plus the stack

### ✅ **Why This Approach?**

* Cleanly separates the precomputation and accumulation phases.
* The `nxt[]` array is reusable if boundary information is needed later.
* Easier to test boundary values individually.

## 📊 **4️⃣ Greedy Expansion Approach**

### 💡 Algorithm Steps:

1. For each starting index `i`, greedily extend the subarray to the right.
2. Continue extending as long as the next element is greater than or equal to `arr[i]` (keeping `arr[i]` the minimum).
3. Count all valid subarrays that start at `i` as `(j - i + 1)` where `j` is the furthest valid index.
4. No extra data structure is needed — direct comparison.

```cpp
class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && arr[i] <= arr[j + 1]) j++;
            ans += j - i + 1;
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) worst case, O(n) for strictly decreasing sequences
* **Auxiliary Space:** 💾 O(1) — No extra space required

### ✅ **Why This Approach?**

* Simple and intuitive — no stack or extra data structure needed.
* Great for understanding the problem from first principles.
* Works efficiently in practice for random or nearly decreasing inputs.

> ⚠️ **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs near the constraint boundary. (fails ~1010/1120 test cases due to time constraints).


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                          | ⚠️ **Cons**                          |
| ---------------------------------- | ---------------------- | ----------------------- | ------------------------------------ | ------------------------------------- |
| 🏷️ **Array-Based Stack**          | 🟢 O(n)                | 🟢 O(n)                 | 🚀 Fastest, cache-friendly           | 🔧 Manual stack management           |
| 🔍 **Standard Stack**              | 🟢 O(n)                | 🟢 O(n)                 | 📖 Most readable                     | 💾 STL overhead                      |
| 📊 **Precomputation**              | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Clear separation of phases        | 💾 Extra array storage               |
| 🔄 **Greedy Expansion**            | 🟡 O(n²) worst         | 🟢 O(1)                 | ⭐ No extra space, simple logic      | 🔧 Worst case quadratic, TLE risk    |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive Programming**                     | 🥇 **Array-Based Stack**             | ★★★★★                     |
| 📖 **Readability & Debugging**                     | 🥈 **Standard Stack**                | ★★★★☆                     |
| 🔧 **Need Boundary Information**                   | 🥉 **Precomputation**                | ★★★★☆                     |
| 🎯 **Space Critical / Small Inputs**               | 🏅 **Greedy Expansion**              | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int countSubarrays(int[] arr) {
        int n = arr.length, top = -1, ans = 0;
        int[] st = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && arr[st[top]] >= arr[i]) top--;
            ans += ((top < 0 ? n : st[top]) - i);
            st[++top] = i;
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countSubarrays(self, arr):
        st, ans, n = [], 0, len(arr)
        for i in range(n - 1, -1, -1):
            while st and arr[st[-1]] >= arr[i]: st.pop()
            ans += ((st[-1] if st else n) - i)
            st.append(i)
        return ans
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
