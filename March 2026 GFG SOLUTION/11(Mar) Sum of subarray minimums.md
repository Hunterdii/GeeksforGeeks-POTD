---
title: "🔢 Sum of Subarray Minimums | GFG Solution 🔍"
keywords🏷️: ["🔢 sum of minimums", "🔍 monotonic stack", "📍 stack", "📈 arrays", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Sum of Subarray Minimums problem: calculate the sum of minimum elements across all subarrays using monotonic stack technique. 🚀"
date: 📅 2025-03-11
---

# *11. Sum of Subarray Minimums*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1)

## **🧩 Problem Description**

Given an array `arr[]` of positive integers, find the **total sum of the minimum elements** of every possible subarray.

A subarray is a contiguous sequence of elements within an array. For each subarray, we identify its minimum element and sum all these minimums together.

**Note:** It is guaranteed that the total sum will fit within a 32-bit unsigned integer.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [10, 20]
Output: 40
Explanation: Subarrays are [10], [20], [10, 20]. 
Minimums are 10, 20, 10.
Sum of all these is 10 + 20 + 10 = 40.
```

### Example 2

```cpp
Input: arr[] = [1, 2, 3, 4]
Output: 20
Explanation: Subarrays are [1], [2], [3], [4], [1, 2], [1, 2, 3], [1, 2, 3, 4], 
[2, 3], [2, 3, 4], [3, 4]. 
Minimums are 1, 2, 3, 4, 1, 1, 1, 2, 2, 3.
Sum of all these is 1 + 2 + 3 + 4 + 1 + 1 + 1 + 2 + 2 + 3 = 20.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 3 \times 10^4$
* $1 \le \text{arr}[i] \le 10^3$

## **✅ My Approach**

The optimal approach uses the **Monotonic Stack** technique to efficiently calculate how many subarrays each element serves as the minimum for:

### **Two-Boundary Monotonic Stack**

1. **Key Insight:**
   * For each element `arr[i]`, we need to find how many subarrays have `arr[i]` as their minimum.
   * This equals: (number of elements we can extend left) × (number of elements we can extend right) × arr[i].

2. **Find Left Boundaries:**
   * Use a monotonic increasing stack to find the previous smaller element for each position.
   * `left[i]` stores the index of the previous smaller element (or -1 if none exists).
   * This tells us how far left we can extend while `arr[i]` remains the minimum.

3. **Find Right Boundaries:**
   * Use another monotonic increasing stack (traverse right to left) to find the next smaller element.
   * `right[i]` stores the index of the next smaller element (or n if none exists).
   * This tells us how far right we can extend while `arr[i]` remains the minimum.

4. **Calculate Contribution:**
   * For each element at index `i`:
     - It can be the minimum in `(i - left[i])` choices for the left boundary.
     - It can be the minimum in `(right[i] - i)` choices for the right boundary.
     - Total subarrays where `arr[i]` is minimum: `(i - left[i]) × (right[i] - i)`.
     - Contribution to sum: `arr[i] × (i - left[i]) × (right[i] - i)`.

5. **Handle Duplicates:**
   * Use `>=` for left boundary and `>` for right boundary to avoid counting the same subarray twice.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is pushed and popped from the stack at most once during the left boundary calculation, and once during the right boundary calculation. The final summation loop is also O(n). Therefore, total time is O(n) + O(n) + O(n) = O(n).

* **Expected Auxiliary Space Complexity:** O(n), as we use three arrays (left, right, and stack) each of size n. The stack can grow up to n elements in the worst case. Thus, auxiliary space is O(n) + O(n) + O(n) = O(n).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        long res = 0;
        vector<int> left(n), right(n), st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.back()] >= arr[i]) st.pop_back();
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.back()] > arr[i]) st.pop_back();
            right[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
        for (int i = 0; i < n; i++)
            res = (res + (long)arr[i] * (i - left[i]) * (right[i] - i)) % mod;
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dynamic Programming with Right Boundary**

### 💡 Algorithm Steps:

1. Use monotonic stack to find the next smaller element on the right for each position.
2. Build DP array from right to left where dp[i] represents sum of minimums for all subarrays starting at index i.
3. For each position, calculate contribution based on whether there's a smaller element to the right.
4. Sum all DP values to get the final answer.

```cpp
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 0), right(n), st;
        for (int i = 0; i < n; i++) right[i] = i;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.back()]) {
                right[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        dp[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int r = right[i];
            dp[i] = r == i ? (n - i) * arr[i] : (r - i) * arr[i] + dp[r];
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two passes through array with stack operations
* **Auxiliary Space:** 💾 O(n) - Stack, right array, and DP array

### ✅ **Why This Approach?**

* Clear DP recurrence relation
* Easy to understand subproblem structure
* Good for learning DP with monotonic stack

## 📊 **3️⃣ Stack with Immediate Contribution**

### 💡 Algorithm Steps:

1. Use a single monotonic stack to process elements from left to right.
2. When an element is popped, calculate its contribution to all subarrays where it's the minimum.
3. Track cumulative sum of contributions as we process each element.
4. Add a sentinel value at the end to flush remaining stack elements.

```cpp
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        long res = 0;
        vector<pair<int,int>> st;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[i] < st.back().first)) {
                auto [val, idx] = st.back();
                st.pop_back();
                int left = st.empty() ? -1 : st.back().second;
                res = (res + (long)val * (idx - left) * (i - idx)) % mod;
            }
            if (i < n) st.push_back({arr[i], i});
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with amortized O(1) stack operations
* **Auxiliary Space:** 💾 O(n) - Only the stack is needed

### ✅ **Why This Approach?**

* Single-pass processing is elegant
* Immediate contribution calculation
* Good for competitive programming

## 📊 **4️⃣ Brute Force Enumeration**

### 💡 Algorithm Steps:

1. Enumerate all possible subarrays using two nested loops.
2. For each subarray, track the minimum element while extending the right boundary.
3. Add the minimum to the running sum.
4. Return the total sum modulo 10^9+7.

```cpp
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        long res = 0;
        for (int i = 0; i < n; i++) {
            int minVal = arr[i];
            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                res = (res + minVal) % mod;
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested loops with optimized min tracking
* **Auxiliary Space:** 💾 O(1) - Only constant extra space

### ✅ **Why This Approach?**

* Simplest to implement and understand
* No complex data structures needed
* Good baseline for testing and comparison

> ⚠️ Note: This approach results in Time Limit Exceeded (TLE) for large inputs near the constraint boundary. (fails ~1110/1120 test cases due to time constraints).

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Two-Boundary Stack**        | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Optimal & intuitive            | 💾 Requires three arrays              |
| 📊 **DP with Right Boundary**     | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear DP structure             | 🔄 More complex recurrence            |
| ⚡ **Stack Immediate Contrib**    | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Single pass elegance           | 🧠 Requires careful index tracking    |
| 🔍 **Brute Force**                | 🔴 O(n²)               | 🟢 O(1)                 | 🎯 Simple implementation          | 🐌 Too slow for large inputs          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Two-Boundary Stack**            | ★★★★★                     |
| 📖 **Learning DP patterns**                           | 🥈 **DP with Right Boundary**        | ★★★★☆                     |
| 🔧 **Competitive programming**                        | 🥉 **Stack Immediate Contrib**       | ★★★★★                     |
| 🎯 **Small inputs/Testing**                           | 🏅 **Brute Force**                   | ★★★☆☆                     |

</details>


## **☕ Code (Java)**

```java
class Solution {
    public int sumSubMins(int[] arr) {
        int n = arr.length, mod = 1000000007;
        long res = 0;
        int[] left = new int[n], right = new int[n];
        int[] st = new int[n];
        int top = -1;
        for (int i = 0; i < n; i++) {
            while (top >= 0 && arr[st[top]] >= arr[i]) top--;
            left[i] = top < 0 ? -1 : st[top];
            st[++top] = i;
        }
        top = -1;
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && arr[st[top]] > arr[i]) top--;
            right[i] = top < 0 ? n : st[top];
            st[++top] = i;
        }
        for (int i = 0; i < n; i++)
            res = (res + (long)arr[i] * (i - left[i]) * (right[i] - i)) % mod;
        return (int)res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def sumSubMins(self, arr):
        n, mod = len(arr), 10**9 + 7
        res, st = 0, []
        left, right = [-1] * n, [n] * n
        for i in range(n):
            while st and arr[st[-1]] >= arr[i]: st.pop()
            if st: left[i] = st[-1]
            st.append(i)
        st = []
        for i in range(n - 1, -1, -1):
            while st and arr[st[-1]] > arr[i]: st.pop()
            if st: right[i] = st[-1]
            st.append(i)
        for i in range(n):
            res = (res + arr[i] * (i - left[i]) * (right[i] - i)) % mod
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
