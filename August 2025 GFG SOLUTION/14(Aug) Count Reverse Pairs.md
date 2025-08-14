---
title: "🔢 Count Reverse Pairs | GFG Solution 🔍"
keywords🏷️: ["🔢 reverse pairs", "🔍 merge sort", "📍 divide conquer", "📈 inversion count", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Count Reverse Pairs problem: efficiently count pairs (i,j) where arr[i] > 2*arr[j] using modified merge sort technique. 🚀"
date: 📅 2025-08-14
---

# *14. Count Reverse Pairs*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-reverse-pairs/1)

## **🧩 Problem Description**

You are given an array `arr[]` of positive integers. Your task is to find the count of **reverse pairs**. A pair of indices `(i, j)` is said to be a reverse pair if both the following conditions are met:

- `0 ≤ i < j < arr.size()`
- `arr[i] > 2 * arr[j]`

The goal is to efficiently count all such pairs in the given array.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [3, 2, 4, 5, 1, 20]
Output: 3
Explanation: The Reverse pairs are 
(0, 4), arr[0] = 3, arr[4] = 1, 3 > 2*1 
(2, 4), arr[2] = 4, arr[4] = 1, 4 > 2*1 
(3, 4), arr[3] = 5, arr[4] = 1, 5 > 2*1 
```

### Example 2

```cpp
Input: arr[] = [5, 4, 3, 2, 2]
Output: 2
Explanation: The Reverse pairs are
(0, 3), arr[0] = 5, arr[3] = 2, 5 > 2*2
(0, 4), arr[0] = 5, arr[4] = 2, 5 > 2*2
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 5 \times 10^4$
* $1 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses a **Modified Merge Sort** technique to efficiently count reverse pairs while maintaining the divide-and-conquer paradigm:

### **Modified Merge Sort Algorithm**

1. **Divide Phase:**
   * Recursively divide the array into two halves until single elements remain.
   * Count reverse pairs in left half, right half, and cross-partition pairs.

2. **Count Cross-Partition Pairs:**
   * For each element in the left sorted subarray, count how many elements in the right sorted subarray satisfy the reverse pair condition.
   * Use two pointers technique: for each `arr[i]` in left half, find all `arr[j]` in right half where `arr[i] > 2 * arr[j]`.

3. **Merge Phase:**
   * Merge the two sorted halves back into a single sorted array.
   * This ensures subsequent recursive calls work with sorted subarrays.

4. **Optimization:**
   * Since both halves are sorted, we can use the two-pointer technique efficiently.
   * Once we find the rightmost valid `j` for a given `i`, all elements from `m+1` to `j` form valid pairs with `arr[i]`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. The divide phase creates O(log n) levels, and each level performs O(n) work for counting pairs and merging.
* **Expected Auxiliary Space Complexity:** O(n), as we use temporary arrays during the merge process and the recursion stack depth is O(log n).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countRevPairs(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
private:
    int mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        return mergeSort(arr, l, m) + mergeSort(arr, m + 1, r) + merge(arr, l, m, r);
    }
    int merge(vector<int>& arr, int l, int m, int r) {
        int cnt = 0, j = m + 1;
        for (int i = l; i <= m; i++) {
            while (j <= r && arr[i] > 2LL * arr[j]) j++;
            cnt += j - m - 1;
        }
        vector<int> temp(r - l + 1);
        int i = l, k = 0;
        j = m + 1;
        while (i <= m && j <= r) temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
        while (i <= m) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];
        for (i = l; i <= r; i++) arr[i] = temp[i - l];
        return cnt;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Divide and Conquer with Inversion Count**

### 💡 Algorithm Steps:

1. Use modified merge sort focusing on cross-partition pairs only.
2. For left and right sorted subarrays, count valid pairs across partitions.
3. Use two pointers technique to efficiently count pairs.
4. Merge subarrays while maintaining sorted order for recursive calls.

```cpp
class Solution {
public:
    int countRevPairs(vector<int>& arr) {
        vector<int> temp = arr;
        return divideConquer(temp, 0, arr.size() - 1);
    }
private:
    int divideConquer(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        int cnt = divideConquer(arr, l, m) + divideConquer(arr, m + 1, r);
        
        int j = m + 1;
        for (int i = l; i <= m; i++) {
            while (j <= r && arr[i] > 2LL * arr[j]) j++;
            cnt += j - m - 1;
        }
        
        inplace_merge(arr.begin() + l, arr.begin() + m + 1, arr.begin() + r + 1);
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Divide and conquer with linear merge
* **Auxiliary Space:** 💾 O(n) - Space for inplace_merge operations

### ✅ **Why This Approach?**

* Clean separation of counting and merging logic
* Uses STL inplace_merge for reliability
* Easy to modify for different pair conditions

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Merge Sort**                  | 🟢 O(n log n)          | 🟢 O(n)                 | 🚀 Optimal and stable             | 🔧 Modifies input array              |
| ⚡ **Divide & Conquer**            | 🟢 O(n log n)          | 🟡 O(n)                 | 🎯 Clean logic separation         | 🔧 Uses STL merge operations         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Overall best performance**                       | 🥇 **Merge Sort**                     | ★★★★★                     |
| 🎯 **Interview/Learning**                             | 🥈 **Divide & Conquer**               | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int countRevPairs(int[] arr) {
        return mergeSort(arr, 0, arr.length - 1);
    }
    private int mergeSort(int[] arr, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        return mergeSort(arr, l, m) + mergeSort(arr, m + 1, r) + merge(arr, l, m, r);
    }
    private int merge(int[] arr, int l, int m, int r) {
        int cnt = 0, j = m + 1;
        for (int i = l; i <= m; i++) {
            while (j <= r && arr[i] > 2L * arr[j]) j++;
            cnt += j - m - 1;
        }
        int[] temp = new int[r - l + 1];
        int i = l, k = 0;
        j = m + 1;
        while (i <= m && j <= r) temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
        while (i <= m) temp[k++] = arr[i++];
        while (j <= r) temp[k++] = arr[j++];
        System.arraycopy(temp, 0, arr, l, temp.length);
        return cnt;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countRevPairs(self, arr):
        def mergeSort(l, r):
            if l >= r: return 0
            m = (l + r) // 2
            return mergeSort(l, m) + mergeSort(m + 1, r) + merge(l, m, r)
        
        def merge(l, m, r):
            cnt = j = 0
            for i in range(l, m + 1):
                while m + 1 + j <= r and arr[i] > 2 * arr[m + 1 + j]: j += 1
                cnt += j
            arr[l:r+1] = sorted(arr[l:r+1])
            return cnt
        
        return mergeSort(0, len(arr) - 1)
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
