---
title: "🔢 Farthest Smaller Right | GFG Solution 🔍"
keywords🏷️: ["🔢 farthest smaller", "🔍 binary search", "📍 suffix array", "📈 preprocessing", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Farthest Smaller Right problem: find the farthest index with smaller element to the right using suffix minimum array and binary search technique. 🚀"
date: 📅 2025-08-19
---

# *19. Farthest Smaller Right*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/farthest-smaller-right/1)

## **🧩 Problem Description**

You are given an array `arr[]`. For each element at index `i` (0-based indexing), find the **farthest index j** to the right (i.e., `j > i`) such that `arr[j] < arr[i]`. If no such index exists for a given position, return `-1` for that index. Return the resulting array of answers.

The goal is to efficiently find the rightmost position where a smaller element exists for each array element.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 5, 1, 3, 2]
Output: [2, 4, -1, 4, -1]
Explanation: 
arr[0] = 2: Farthest smaller element to the right is arr[2] = 1.
arr[1] = 5: Farthest smaller element to the right is arr[4] = 2.
arr[2] = 1: No smaller element to the right → -1.
arr[3] = 3: Farthest smaller element to the right is arr[4] = 2.
arr[4] = 2: No elements to the right → -1.
```

### Example 2

```cpp
Input: arr[] = [2, 3, 5, 4, 1]
Output: [4, 4, 4, 4, -1]
Explanation: arr[4] is the farthest smallest element to the right for arr[0], arr[1], arr[2] and arr[3].
```

### Example 3

```cpp
Input: arr[] = [5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, -1]
Explanation: Each element finds its immediate next smaller element as the farthest smaller element.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $1 \le \text{arr}[i] \le 10^6$

## **✅ My Approach**

The optimal approach uses **Suffix Minimum Array** preprocessing combined with **Binary Search** to efficiently find the farthest smaller element:

### **Suffix Minimum + Binary Search**

1. **Preprocessing Phase:**
   * Create a suffix minimum array `suff[]` where `suff[i]` represents the minimum element from index `i` to the end of array.
   * Build this array from right to left: `suff[i] = min(arr[i], suff[i+1])`.

2. **Query Phase:**
   * For each element at index `i`, search in the range `[i+1, n-1]` using binary search.
   * Find the farthest index `j` where `suff[j] < arr[i]`.

3. **Binary Search Logic:**
   * If `suff[mid] < arr[i]`, the answer could be at `mid` or further right, so search in `[mid+1, hi]`.
   * If `suff[mid] >= arr[i]`, search in `[lo, mid-1]`.

4. **Result:**
   * Store the farthest valid index for each element, or `-1` if no such index exists.

### **Key Insight:**
The suffix minimum array allows us to quickly check if there exists any element smaller than `arr[i]` in the suffix starting from any index `j`. Binary search then helps us find the farthest such position efficiently.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. Building suffix array takes O(n) time, and for each element, we perform binary search taking O(log n) time.
* **Expected Auxiliary Space Complexity:** O(n), for storing the suffix minimum array and the result array.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        vector<int> suff(n);
        suff[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i) suff[i] = min(arr[i], suff[i+1]);
        for(int i = 0; i < n; ++i) {
            int lo = i+1, hi = n-1, res = -1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if(suff[mid] < arr[i]) {
                    res = mid;
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. For each element at index `i`, iterate through all indices `j` where `j > i`.
2. Keep track of the farthest index where `arr[j] < arr[i]`.
3. Update the result for index `i` with the farthest valid index found.

```cpp
class Solution {
public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; ++i) {
            for(int j = n-1; j > i; --j) {
                if(arr[j] < arr[i]) {
                    ans[i] = j;
                    break;
                }
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²)
* **Auxiliary Space:** 💾 O(1) - Only result array

### ✅ **Why This Approach?**

* Simple and intuitive logic.
* No additional preprocessing required.
* Good for small arrays or when simplicity is preferred.

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1112 /1114 test cases due to time constraints).


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Suffix Min + Binary Search**    | 🟢 O(n log n)          | 🟡 O(n)                 | ⚡ Optimal for large inputs       | 💾 Requires preprocessing            |
| 🔄 **Brute Force**                | 🔴 O(n²)               | 🟢 O(1)                 | 🚀 Simple, no extra space        | ⏱️ Slow for large inputs             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**         | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------ | ------------------------- |
| ⚡ **Large arrays, performance critical**              | 🥇 **Suffix Min + Binary Search**   | ★★★★★                     |
| 🔧 **Small arrays, simple implementation**            | 🥈 **Brute Force**                  | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> farMin(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>();
        int[] suff = new int[n];
        suff[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; --i) suff[i] = Math.min(arr[i], suff[i+1]);
        for(int i = 0; i < n; ++i) {
            int lo = i+1, hi = n-1, res = -1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if(suff[mid] < arr[i]) {
                    res = mid;
                    lo = mid+1;
                } else {
                    hi = mid-1;
                }
            }
            ans.add(res);
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def farMin(self, arr):
        n = len(arr)
        ans = []
        suff = [0] * n
        suff[n-1] = arr[n-1]
        for i in range(n-2, -1, -1):
            suff[i] = min(arr[i], suff[i+1])
        for i in range(n):
            lo, hi, res = i+1, n-1, -1
            while lo <= hi:
                mid = lo + (hi-lo)//2
                if suff[mid] < arr[i]:
                    res = mid
                    lo = mid+1
                else:
                    hi = mid-1
            ans.append(res)
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
