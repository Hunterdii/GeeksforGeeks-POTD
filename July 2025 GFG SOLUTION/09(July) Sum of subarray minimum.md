---
title: "➕ Sum of Subarray Minimums | GFG Solution 🔍"
keywords🏷️: ["➕ sum of subarray minimums", "🔍 monotonic stack", "📍 contribution technique", "📈 stack", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Sum of Subarray Minimums problem: find the total sum of minimum elements in all subarrays using monotonic stack and contribution technique. 🚀"
date: 📅 2025-07-09
---

# *09. Sum of Subarray Minimums*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sum-of-subarray-minimum/1)

## **🧩 Problem Description**

Given an array `arr[]` of positive integers, find the **total sum of the minimum elements** of every possible subarrays.

A subarray is a contiguous sequence of elements within an array. For each subarray, we need to find its minimum element and sum all these minimum values.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [3, 1, 2, 4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3, 1], [1, 2], [2, 4], [3, 1, 2], [1, 2, 4], [3, 1, 2, 4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum of all these is 17.
```

### Example 2

```cpp
Input: arr[] = [71, 55, 82, 55]
Output: 593
Explanation: The sum of the minimum of all the subarrays is 593.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 3 \times 10^4$
* $1 \le \text{arr}[i] \le 10^3$

## **✅ My Approach**

The optimal approach uses **Monotonic Stack** with **Contribution Technique** to efficiently calculate how many times each element contributes as a minimum in different subarrays:

### **Two-Pass Stack**

1. **Calculate Left Boundaries:**
   * For each element at index `i`, find how many elements to the left are greater than or equal to `arr[i]`.
   * Use a monotonic stack to find the nearest smaller element on the left.
   * `left[i]` represents the number of subarrays ending at `i` where `arr[i]` is the minimum.

2. **Calculate Right Boundaries:**
   * For each element at index `i`, find how many elements to the right are strictly greater than `arr[i]`.
   * Use a monotonic stack to find the nearest smaller element on the right.
   * `right[i]` represents the number of subarrays starting at `i` where `arr[i]` is the minimum.

3. **Calculate Contribution:**
   * For each element `arr[i]`, its total contribution = `arr[i] × left[i] × right[i]`.
   * This gives the sum of `arr[i]` across all subarrays where it's the minimum.

4. **Sum All Contributions:**
   * Add up all individual contributions to get the final result.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is pushed and popped from the stack at most once, resulting in linear time complexity.
* **Expected Auxiliary Space Complexity:** O(n), as we use additional arrays for left and right boundaries and a stack for processing, all of which require O(n) space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass Stack Approach**

### 💡 Algorithm Steps:

1. Use single stack to process elements
2. Calculate contribution while maintaining stack
3. Handle boundary conditions efficiently
4. Optimize space usage

```cpp
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        stack<pair<int, long long>> st;
        long long res = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top().first] >= arr[i])) {
                int idx = st.top().first;
                long long sum = st.top().second;
                st.pop();
                int left = st.empty() ? idx + 1 : idx - st.top().first;
                int right = i - idx;
                res = (res + arr[idx] * left * right) % MOD;
            }
            if (i < n) {
                long long sum = st.empty() ? (i + 1) * arr[i] : st.top().second + (i - st.top().first) * arr[i];
                st.push({i, sum});
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - for stack

### ✅ **Why This Approach?**

* Single pass through array
* Efficient stack operations
* Reduced memory allocations

## 📊 **3️⃣ Monotonic Stack with Contribution**

### 💡 Algorithm Steps:

1. Maintain strictly increasing stack
2. Calculate contribution when popping elements
3. Handle duplicate values correctly
4. Optimize for memory usage

```cpp
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        long long res = 0;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;
                res = (res + (long long)arr[mid] * left * right) % MOD;
            }
            if (i < n) st.push(i);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - for stack

### ✅ **Why This Approach?**

* Clean monotonic stack implementation
* Handles duplicates efficiently
* Optimal time complexity

## 📊 **4️⃣ Dynamic Programming Approach**

### 💡 Algorithm Steps:

1. Use DP to track minimum contributions
2. Calculate sum incrementally
3. Optimize space with rolling arrays
4. Handle edge cases efficiently

```cpp
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<long long> dp(n);
        stack<int> st;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (st.empty()) {
                dp[i] = (i + 1) * arr[i];
            } else {
                int j = st.top();
                dp[i] = dp[j] + (i - j) * arr[i];
            }
            st.push(i);
            res = (res + dp[i]) % MOD;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - for DP array and stack

### ✅ **Why This Approach?**

* Intuitive DP approach
* Builds solution incrementally
* Easy to understand and debug

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Two-Pass Stack**             | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Clear logic, easy to debug    | 💾 Two passes through array          |
| 🔺 **Single Pass Stack**          | 🟢 O(n)                | 🟡 O(n)                 | 🔧 Optimal passes                | 💾 More complex implementation       |
| ⏰ **Monotonic Stack**             | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Clean implementation          | 🔄 Requires careful duplicate handling|
| 📊 **Dynamic Programming**        | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Intuitive approach             | 🔧 Additional DP array needed        |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Interview/Competitive Programming**              | 🥇 **Two-Pass Stack**                | ★★★★★                     |
| 📊 **Production Code**                               | 🥈 **Monotonic Stack**               | ★★★★☆                     |
| 🎯 **Learning/Educational**                          | 🥉 **Dynamic Programming**           | ★★★★☆                     |
| 🚀 **Memory Constrained**                            | 🏅 **Single Pass Stack**             | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int sumSubMins(int[] arr) {
        final int MOD = 1000000007;
        int n = arr.length;
        int[] left = new int[n];
        int[] right = new int[n];
        Deque<Integer> st = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && arr[st.peekLast()] >= arr[i]) st.pollLast();
            left[i] = st.isEmpty() ? i + 1 : i - st.peekLast();
            st.offerLast(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.isEmpty() && arr[st.peekLast()] > arr[i]) st.pollLast();
            right[i] = st.isEmpty() ? n - i : st.peekLast() - i;
            st.offerLast(i);
        }
        long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + (long) arr[i] * left[i] * right[i]) % MOD;
        }
        return (int) res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def sumSubMins(self, arr):
        MOD = 10**9 + 7
        n = len(arr)
        left = [0] * n
        right = [0] * n
        st = []
        for i in range(n):
            while st and arr[st[-1]] >= arr[i]:
                st.pop()
            left[i] = i + 1 if not st else i - st[-1]
            st.append(i)
        st.clear()
        for i in range(n - 1, -1, -1):
            while st and arr[st[-1]] > arr[i]:
                st.pop()
            right[i] = n - i if not st else st[-1] - i
            st.append(i)
        return sum(arr[i] * left[i] * right[i] for i in range(n)) % MOD
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
