---
title: "📏 Maximize the Minimum Difference Between K Elements | GFG Solution 🔍"
keywords🏷️: ["📏 maximize minimum", "🔍 binary search", "📍 greedy algorithm", "📈 sorting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximize the Minimum Difference Between K Elements problem: select k elements to maximize minimum absolute difference using binary search and greedy approach. 🚀"
date: 📅 2025-08-21
---

# *21. Maximize the Minimum Difference Between K Elements*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximize-the-minimum-difference-between-k-elements/1)

## **🧩 Problem Description**

You are given an array `arr[]` of integers and an integer `k`. Your task is to select **k elements** from the array such that the **minimum absolute difference** between any two of the selected elements is **maximized**. Return this maximum possible minimum difference.

The goal is to strategically choose k elements from the array to ensure that even the closest pair among the selected elements has the largest possible difference.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 6, 2, 5], k = 3
Output: 1
Explanation: 3 elements out of 4 elements are to be selected with a minimum difference as large as possible. 
Selecting 2, 2, 5 will result in minimum difference as 0. 
Selecting 2, 5, 6 will result in minimum difference as 6 - 5 = 1.
```

### Example 2

```cpp
Input: arr[] = [1, 4, 9, 0, 2, 13, 3], k = 4
Output: 4
Explanation: Selecting 0, 4, 9, 13 will result in minimum difference of 4, 
which is the largest minimum difference possible.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^6$
* $2 \le k \le \text{arr.size()}$

## **✅ My Approach**

The optimal approach uses **Binary Search on Answer** combined with a **Greedy Algorithm**:

### **Binary Search + Greedy Selection**

1. **Sort the Array:**
   * First, sort the array to enable efficient greedy selection.
   * This allows us to consider elements in ascending order.

2. **Binary Search Setup:**
   * Set search range: `left = 0` (minimum possible difference) to `right = max - min` (maximum possible difference).
   * We binary search on the possible values of minimum difference.

3. **Validation Function (Greedy):**
   * For a given minimum difference `mid`, check if we can select k elements.
   * Start with the first element, then greedily select the next element that is at least `mid` distance away.
   * Continue until we either select k elements (valid) or exhaust the array (invalid).

4. **Binary Search Logic:**
   * If we can achieve difference `mid` with k elements, try for a larger difference (`left = mid + 1`).
   * If we cannot achieve difference `mid`, try for a smaller difference (`right = mid - 1`).
   * Store the maximum achievable difference as our answer.

5. **Return Result:**
   * The binary search converges to the maximum possible minimum difference.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n + n log(max-min)), where n is the size of the array. The sorting takes O(n log n), and binary search takes O(log(max-min)) iterations, each requiring O(n) validation.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant additional space beyond the input array for sorting (in-place sorting).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int l = 0, r = a.back() - a[0], ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = 1, last = a[0];
            for (int i = 1; i < a.size() && cnt < k; i++)
                if (a[i] - last >= m) cnt++, last = a[i];
            cnt >= k ? ans = m, l = m + 1 : r = m - 1;
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Greedy with Early Termination**

### 💡 Algorithm Steps:

1. Sort array and use binary search on answer space
2. For each mid value, greedily select elements with minimum difference
3. Use early termination when k elements are found
4. Optimize by avoiding unnecessary iterations

```cpp
class Solution {
public:
    int maxMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int lo = 1, hi = (a.back() - a[0]) / (k - 1), res = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int picked = 1, pos = a[0];
            for (int i = 1; i < a.size(); i++) {
                if (a[i] - pos >= mid) {
                    picked++;
                    pos = a[i];
                    if (picked == k) break;
                }
            }
            if (picked >= k) res = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + n log(max-min)) - Binary search with linear validation
* **Auxiliary Space:** 💾 O(1) - Only constant extra space

### ✅ **Why This Approach?**

* Optimized search range based on theoretical maximum
* Early termination reduces unnecessary iterations
* Better practical performance for large arrays

## 📊 **3️⃣ Sliding Window Optimization**

### 💡 Algorithm Steps:

1. Sort array and use sliding window technique
2. For each possible minimum difference, validate using sliding approach
3. Optimize by maintaining window of valid elements
4. Use binary search combined with efficient window validation

```cpp
class Solution {
public:
    int maxMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int left = 0, right = a.back() - a[0], answer = 0;
        auto canAchieve = [&](int minDiff) {
            int count = 1, lastPicked = 0;
            for (int i = 1; i < a.size(); i++) {
                if (a[i] - a[lastPicked] >= minDiff) {
                    count++;
                    lastPicked = i;
                    if (count == k) return true;
                }
            }
            return false;
        };
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAchieve(mid)) answer = mid, left = mid + 1;
            else right = mid - 1;
        }
        return answer;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + n log(max-min)) - Binary search with O(n) validation
* **Auxiliary Space:** 💾 O(1) - Constant space with lambda function

### ✅ **Why This Approach?**

* Clean separation of binary search logic and validation
* Lambda function improves code readability
* Efficient for competitive programming scenarios

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Optimized Binary Search**    | 🟢 O(n log n + n log range) | 🟢 O(1)                 | 🚀 Most efficient                 | 🔧 Complex boundary conditions        |
| 🔍 **Greedy Early Termination**   | 🟢 O(n log n + n log range) | 🟢 O(1)                 | 📖 Good practical performance     | 🎯 Similar complexity                 |
| 🔄 **Sliding Window**             | 🟢 O(n log n + n log range) | 🟢 O(1)                 | ⭐ Clean code structure           | 🔧 Lambda overhead                    |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive Programming**                     | 🥇 **Optimized Binary Search**       | ★★★★★                     |
| 📖 **Code Interviews**                             | 🥈 **Sliding Window**                | ★★★★☆                     |
| 🎯 **Production Code**                             | 🏅 **Greedy Early Termination**      | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxMinDiff(int[] a, int k) {
        Arrays.sort(a);
        int l = 0, r = a[a.length - 1] - a[0], ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = 1, last = a[0];
            for (int i = 1; i < a.length && cnt < k; i++)
                if (a[i] - last >= m) { cnt++; last = a[i]; }
            if (cnt >= k) { ans = m; l = m + 1; } else r = m - 1;
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxMinDiff(self, a, k):
        a.sort()
        l, r, ans = 0, a[-1] - a[0], 0
        while l <= r:
            m = (l + r) // 2
            cnt, last = 1, a[0]
            for x in a[1:]:
                if x - last >= m:
                    cnt += 1
                    last = x
                    if cnt == k: break
            if cnt >= k:
                ans, l = m, m + 1
            else:
                r = m - 1
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
