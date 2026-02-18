---
title: "🔢 Count Inversions | GFG Solution 🔍"
keywords🏷️: ["🔢 count inversions", "🔍 merge sort", "📍 divide and conquer", "📈 BIT fenwick tree", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Count Inversions problem: find the number of inversion pairs in an array using merge sort, BIT, and segment tree techniques. 🚀"
date: 📅 2025-02-18
---

# *18. Count Inversions*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1)

## **🧩 Problem Description**

Given an array of integers `arr[]`, find the **Inversion Count** of the array.

An inversion count refers to the number of pairs of elements `(i, j)` such that `i < j` and `arr[i] > arr[j]`. In other words, it measures how far (or close) the array is from being sorted — the higher the inversion count, the more unsorted the array is.

## **📘 Examples**

### Example 1

```
Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions: (2, 1), (4, 1), (4, 3).
```

### Example 2

```
Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: The sequence is already sorted, so there is no inversion count.
```

### Example 3

```
Input: arr[] = [10, 10, 10]
Output: 0
Explanation: All elements are equal, so no inversion exists.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses **Merge Sort (Divide and Conquer)** to count inversions efficiently during the merge step itself:

### **Modified Merge Sort**

1. **Divide:** Split the array into two halves recursively until each subarray has one element.
2. **Count During Merge:** When merging two sorted halves, if an element from the right half is smaller than an element from the left half, all remaining elements in the left half form inversions with it. Add `(mid - left_pointer + 1)` to the count.
3. **Merge:** Combine the two sorted halves back into a single sorted array using a temporary buffer.
4. **Propagate Count:** Return the total inversion count by summing counts from left half, right half, and the merge step.

This piggybacks inversion counting onto the natural comparison process of merge sort, avoiding the need for any separate O(n²) scan.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), as the array is divided into halves recursively (log n levels) and each merge step processes all n elements linearly, giving O(n log n) total work.
* **Expected Auxiliary Space Complexity:** O(n), as a temporary array of size n is required during the merge step to hold elements before placing them back into the original array.

## **🧑‍💻 Code (C)**

```c
int merge(int arr[], int temp[], int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2, cnt = 0;
    cnt += merge(arr, temp, l, m);
    cnt += merge(arr, temp, m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
        arr[i] <= arr[j] ? (temp[k++] = arr[i++]) : (cnt += m - i + 1, temp[k++] = arr[j++]);
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (i = l; i <= r; i++) arr[i] = temp[i];
    return cnt;
}

int countInversions(int arr[], int n) {
    int temp[n];
    return merge(arr, temp, 0, n - 1);
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
    int merge(vector<int>& a, int l, int m, int r) {
        vector<int> t(a.begin() + l, a.begin() + r + 1);
        int i = 0, j = m - l + 1, k = l, cnt = 0, lsz = m - l + 1;
        while (i < lsz && j < (int)t.size())
            t[i] <= t[j] ? a[k++] = t[i++] : (cnt += lsz - i, a[k++] = t[j++]);
        while (i < lsz) a[k++] = t[i++];
        while (j < (int)t.size()) a[k++] = t[j++];
        return cnt;
    }
    int sort(vector<int>& a, int l, int r) {
        if (l >= r) return 0;
        int m = (l + r) / 2;
        return sort(a, l, m) + sort(a, m + 1, r) + merge(a, l, m, r);
    }
public:
    int inversionCount(vector<int>& arr) { return sort(arr, 0, arr.size() - 1); }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ BIT (Binary Indexed Tree / Fenwick Tree) Approach**

### 💡 Algorithm Steps:

1. Coordinate compress the array values to the range [1, n] to make them usable as BIT indices.
2. Traverse the array from right to left; for each element, query the BIT to get the count of elements already seen that are smaller than the current element — each such element forms an inversion.
3. After querying, update the BIT at the compressed index of the current element.
4. Accumulate all query results to get the total inversion count.

```cpp
class Solution {
    int bit[100005] = {};
    void update(int i, int n) { for (; i <= n; i += i & -i) bit[i]++; }
    int query(int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
public:
    int inversionCount(vector<int>& arr) {
        int n = arr.size(), cnt = 0;
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        auto compress = [&](int x) { return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1; };
        memset(bit, 0, sizeof(bit));
        for (int i = n - 1; i >= 0; i--) {
            int v = compress(arr[i]);
            cnt += query(v - 1);
            update(v, sorted.size());
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) — Sorting for compression takes O(n log n); each BIT update and query runs in O(log n), done n times.
* **Auxiliary Space:** 💾 O(n) — BIT array and compressed values array each require O(n) space.

### ✅ **Why This Approach?**

* Elegant point-update range-query pattern used widely in competitive programming.
* Very fast in practice due to simple bit manipulation operations.
* Ideal when the array is dynamic or elements arrive in a stream.

## 📊 **3️⃣ Segment Tree Approach**

### 💡 Algorithm Steps:

1. Coordinate compress the array values to reduce the value range to [1, m] where m is the number of distinct elements.
2. Traverse the array left to right; for each element, query the segment tree for the count of already-inserted elements that are strictly greater than the current element — these form inversions with the current element.
3. After querying, update the segment tree at the position of the current compressed value.
4. Sum all query results to obtain the final inversion count.

```cpp
class Solution {
    vector<int> seg;
    void update(int node, int s, int e, int i) {
        if (s == e) { seg[node]++; return; }
        int m = (s + e) / 2;
        i <= m ? update(2*node, s, m, i) : update(2*node+1, m+1, e, i);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return seg[node];
        int m = (s + e) / 2;
        return query(2*node, s, m, l, r) + query(2*node+1, m+1, e, l, r);
    }
public:
    int inversionCount(vector<int>& arr) {
        int n = arr.size(), cnt = 0;
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();
        seg.assign(4 * m, 0);
        for (int i = 0; i < n; i++) {
            int v = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() + 1;
            cnt += query(1, 1, m, v + 1, m);
            update(1, 1, m, v);
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) — Compression takes O(n log n); each segment tree update and range query runs in O(log n), repeated n times.
* **Auxiliary Space:** 💾 O(n) — Segment tree requires 4 × m nodes where m ≤ n, giving O(n) space.

### ✅ **Why This Approach?**

* Highly flexible — easily extends to harder variants like range inversion queries or weighted inversions.
* Supports both point updates and range sum queries in a unified structure.
* Solid foundation for more complex problems in competitive programming.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach** | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros** | ⚠️ **Cons** |
|---|---|---|---|---|
| 🔀 **Merge Sort** | 🟢 O(n log n) | 🟢 O(n) | 🚀 Simple, no preprocessing needed | 🔧 Modifies input array |
| 🌲 **BIT / Fenwick Tree** | 🟢 O(n log n) | 🟡 O(n) | ⚡ Fastest in practice, minimal overhead | 🔧 Requires coordinate compression |
| 📐 **Segment Tree** | 🟢 O(n log n) | 🟡 O(n) | 🎯 Most flexible for range variants | 🐌 Higher constant factor |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario** | 🎖️ **Recommended Approach** | 🔥 **Performance Rating** |
|---|---|---|
| 🏅 **General use / interviews** | 🥇 **Merge Sort** | ★★★★★ |
| ⚡ **Competitive programming** | 🥈 **BIT / Fenwick Tree** | ★★★★★ |
| 🎯 **Complex range inversion variants** | 🏅 **Segment Tree** | ★★★★☆ |

</details>

## **☕ Code (Java)**

```java
class Solution {
    static int merge(int[] arr, int l, int m, int r) {
        int[] t = Arrays.copyOfRange(arr, l, r + 1);
        int i = 0, j = m - l + 1, k = l, cnt = 0, lsz = m - l + 1;
        while (i < lsz && j < t.length)
            if (t[i] <= t[j]) arr[k++] = t[i++];
            else { cnt += lsz - i; arr[k++] = t[j++]; }
        while (i < lsz) arr[k++] = t[i++];
        while (j < t.length) arr[k++] = t[j++];
        return cnt;
    }
    static int sort(int[] arr, int l, int r) {
        if (l >= r) return 0;
        int m = (l + r) / 2;
        return sort(arr, l, m) + sort(arr, m + 1, r) + merge(arr, l, m, r);
    }
    static int inversionCount(int[] arr) { return sort(arr, 0, arr.length - 1); }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def inversionCount(self, arr):
        def merge_sort(a):
            if len(a) <= 1: return a, 0
            m = len(a) // 2
            l, lc = merge_sort(a[:m])
            r, rc = merge_sort(a[m:])
            merged, cnt, i, j = [], lc + rc, 0, 0
            while i < len(l) and j < len(r):
                if l[i] <= r[j]: merged.append(l[i]); i += 1
                else: merged.append(r[j]); cnt += len(l) - i; j += 1
            return merged + l[i:] + r[j:], cnt
        _, ans = merge_sort(arr)
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
