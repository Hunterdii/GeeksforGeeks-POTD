---
title: "🔢 K Sized Subarray Maximum | GFG Solution 🔍"
keywords🏷️: ["🔢 sliding window", "🔍 deque", "📍 maximum subarray", "📈 monotonic queue", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the K Sized Subarray Maximum problem: find maximum value for each contiguous subarray of size k using deque-based sliding window technique. 🚀"
date: 📅 2025-01-12
---

# *12. K Sized Subarray Maximum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1)

## **🧩 Problem Description**

You are given an array `arr[]` of positive integers and an integer `k`. Your task is to find the **maximum value** for each contiguous subarray of size `k`. Return an array of maximum values corresponding to each contiguous subarray.

A subarray is a contiguous sequence of elements within an array. The goal is to efficiently compute the maximum element in every window of size `k` as it slides through the array.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3
Output: [3, 3, 4, 5, 5, 5, 6]
Explanation: 
1st contiguous subarray [1, 2, 3], max = 3
2nd contiguous subarray [2, 3, 1], max = 3
3rd contiguous subarray [3, 1, 4], max = 4
4th contiguous subarray [1, 4, 5], max = 5
5th contiguous subarray [4, 5, 2], max = 5
6th contiguous subarray [5, 2, 3], max = 5
7th contiguous subarray [2, 3, 6], max = 6
```

### Example 2

```cpp
Input: arr[] = [5, 1, 3, 4, 2], k = 1
Output: [5, 1, 3, 4, 2]
Explanation: When k = 1, each element in the array is its own subarray, 
so the output is simply the same array.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $1 \le k \le \text{arr.size()}$
* $0 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses a **Deque-based Sliding Window** technique to maintain indices of potentially maximum elements in the current window:

### **Monotonic Deque Sliding Window**

1. **Initialize Variables:**
   * Use a deque to store indices of array elements.
   * The deque maintains elements in decreasing order of their values.
   * Result vector to store maximum of each window.

2. **Process Each Element:**
   * Remove indices from the front if they are outside the current window (index <= i - k).
   * Remove indices from the back if their corresponding values are smaller than or equal to the current element.
   * Add the current index to the deque.

3. **Extract Maximum:**
   * Once we've processed at least k elements (i >= k - 1), the front of the deque contains the index of the maximum element in the current window.
   * Add this maximum value to the result.

4. **Maintain Monotonic Property:**
   * The deque always maintains indices in decreasing order of their values.
   * This ensures the front always has the maximum element's index.

5. **Continue Until End:**
   * Repeat for all elements to get all window maximums.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), as each element is added to and removed from the deque at most once. Although we have nested loops, each element is processed a constant number of times across all iterations.
* **Expected Auxiliary Space Complexity:** O(k), as the deque stores at most k indices corresponding to the current window size. The result array requires O(n-k+1) space but that's part of the output, not auxiliary space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < arr.size(); i++) {
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(arr[dq.front()]);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Multiset-Based Approach**

### 💡 Algorithm Steps:

1. Use a multiset to maintain the current window in sorted order.
2. Insert first k elements into the multiset for the initial window.
3. The maximum element is always the last element in the multiset.
4. Slide the window by removing the leftmost element and adding the new element.

```cpp
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res;
        multiset<int> ms;
        for (int i = 0; i < k; i++) ms.insert(arr[i]);
        res.push_back(*ms.rbegin());
        for (int i = k; i < arr.size(); i++) {
            ms.erase(ms.find(arr[i - k]));
            ms.insert(arr[i]);
            res.push_back(*ms.rbegin());
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k) - Log k operations for each element
* **Auxiliary Space:** 💾 O(k) - Space for the multiset

### ✅ **Why This Approach?**

* Simple to implement and understand
* Automatically maintains sorted order
* Good for dynamic range queries

## 📊 **3️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. Iterate through all possible windows of size k.
2. For each window, find the maximum element by scanning all k elements.
3. Store the maximum in the result array.
4. Continue until all windows are processed.

```cpp
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> res;
        for (int i = 0; i <= arr.size() - k; i++) {
            int mx = arr[i];
            for (int j = i + 1; j < i + k; j++) mx = max(mx, arr[j]);
            res.push_back(mx);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * k) - k operations for each of n-k+1 windows
* **Auxiliary Space:** 💾 O(1) - Only constant extra space

### ✅ **Why This Approach?**

* Simple and straightforward implementation
* No additional data structures needed
* Easy to debug and verify correctness

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1111 test cases due to time constraints).



## 📊 **4️⃣ Dynamic Programming with Blocks**

### 💡 Algorithm Steps:

1. Divide the array into blocks of size k.
2. Precompute maximum from left for each block and from right.
3. For each window, the maximum is the max of right[left] and left[right].
4. This eliminates redundant comparisons across windows.

```cpp
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> left(n), right(n), res;
        for (int i = 0; i < n; i++) {
            if (i % k == 0) left[i] = arr[i];
            else left[i] = max(left[i - 1], arr[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1 || (i + 1) % k == 0) right[i] = arr[i];
            else right[i] = max(right[i + 1], arr[i]);
        }
        for (int i = 0; i <= n - k; i++) res.push_back(max(right[i], left[i + k - 1]));
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Three linear passes through the array
* **Auxiliary Space:** 💾 O(n) - Two additional arrays for preprocessing

### ✅ **Why This Approach?**

* Linear time complexity without complex data structures
* Good for static arrays with multiple queries
* Elegant use of preprocessing

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Deque (Sliding Window)**     | 🟢 O(n)                | 🟢 O(k)                 | 🚀 Optimal time complexity        | 🔧 Requires deque understanding      |
| 🔍 **Multiset-Based**              | 🟡 O(n log k)          | 🟡 O(k)                 | 📖 Clean implementation           | 🐌 Slower than deque                 |
| 📊 **Brute Force**                 | 🔴 O(n * k)            | 🟢 O(1)                 | 🎯 Simple logic                   | ⏰ Poor time complexity              |
| 🔄 **DP with Blocks**              | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Linear time                    | 💾 Extra space needed                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Deque (Sliding Window)**        | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Multiset-Based**                | ★★★★☆                     |
| 🔧 **Small k, minimal space**                         | 🥉 **Brute Force**                   | ★★★☆☆                     |
| 🎯 **Multiple queries on static array**               | 🏅 **DP with Blocks**                | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> maxOfSubarrays(int[] arr, int k) {
        ArrayList<Integer> res = new ArrayList<>();
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 0; i < arr.length; i++) {
            if (!dq.isEmpty() && dq.peekFirst() <= i - k) dq.pollFirst();
            while (!dq.isEmpty() && arr[dq.peekLast()] <= arr[i]) dq.pollLast();
            dq.offerLast(i);
            if (i >= k - 1) res.add(arr[dq.peekFirst()]);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxOfSubarrays(self, arr, k):
        res, dq = [], []
        for i in range(len(arr)):
            if dq and dq[0] <= i - k: dq.pop(0)
            while dq and arr[dq[-1]] <= arr[i]: dq.pop()
            dq.append(i)
            if i >= k - 1: res.append(arr[dq[0]])
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
