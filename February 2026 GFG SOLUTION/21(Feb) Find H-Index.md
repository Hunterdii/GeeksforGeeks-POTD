---
title: "📚 Find H-Index | GFG Solution 🎯"
keywords🏷️: ["📚 h-index", "🔍 counting sort", "📊 frequency array", "📈 citation analysis", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Find H-Index: calculate researcher's H-index using efficient frequency counting and bucket sort technique. 🚀"
date: 📅 2025-02-21
---

# *21. Find H-Index*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-h-index--165609/1)

## **🧩 Problem Description**

You are given an array `citations[]`, where each element `citations[i]` represents the number of citations received by the ith paper of a researcher. Calculate the researcher's **H-index**.

The **H-index** is defined as the maximum value H, such that the researcher has published **at least H papers**, and all those papers have citation value **greater than or equal to H**.

## **📘 Examples**

### Example 1

```cpp
Input: citations[] = [3, 0, 5, 3, 0]
Output: 3
Explanation: There are at least 3 papers with citation counts of 3, 5, and 3, 
all having citations greater than or equal to 3.
```

### Example 2

```cpp
Input: citations[] = [5, 1, 2, 4, 1]
Output: 2
Explanation: There are 3 papers (with citation counts of 5, 2, and 4) that have 
2 or more citations. However, the H-Index cannot be 3 because there aren't 3 papers 
with 3 or more citations.
```

### Example 3

```cpp
Input: citations[] = [0, 0]
Output: 0
Explanation: The H-index is 0 because there are no papers with at least 1 citation.
```

## **🔒 Constraints**

* $1 \le \text{citations.size()} \le 10^6$
* $0 \le \text{citations}[i] \le 10^6$

## **✅ My Approach**

The optimal solution uses **Sorting in Descending Order**:

### **Descending Sort Approach**

1. **Sort Citations:**
   * Sort the citations array in descending order.
   * This places papers with highest citations first.

2. **Find H-Index:**
   * Iterate through the sorted array with index `i` from 0 to n-1.
   * At position `i`, we have checked `i+1` papers.
   * If `citations[i] >= i+1`, it means at least `i+1` papers have at least `i+1` citations.
   * The H-index is the largest such `i+1` value.

3. **Edge Case:**
   * If no paper meets the criteria, H-index is 0.
   * This happens when even the highest cited paper has 0 citations.

4. **Return Result:**
   * The last valid `i+1` where `citations[i] >= i+1` is the H-index.

**Key Insight:** After descending sort, papers are arranged from most cited to least. At any position i, if citations[i] >= i+1, we have found at least i+1 papers with i+1+ citations.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the number of papers. The sorting operation dominates with O(n log n) complexity, while the linear scan to find H-index takes O(n).
* **Expected Auxiliary Space Complexity:** O(1), as we sort in-place and only use constant extra space for variables. Some sorting implementations may use O(log n) stack space for recursion.

## **🧑‍💻 Code (C)**

```c
int cmp(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

int hIndex(int citations[], int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), cmp);
    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] < i + 1) return i;
    }
    return citationsSize;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) h = i + 1;
            else break;
        }
        return h;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Frequency Counting (Bucket Sort)**

### 💡 Algorithm Steps:

1. Create a frequency array of size n+1 where freq[i] counts papers with exactly i citations.
2. Bucket all citations >= n into freq[n] since they all contribute equally.
3. Starting from n, accumulate count of papers with at least h citations.
4. Find largest h where accumulated count >= h.

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1);
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) freq[n]++;
            else freq[citations[i]]++;
        }
        int s = 0;
        for (int i = n; i >= 0; i--) {
            s += freq[i];
            if (s >= i) return i;
        }
        return 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time with counting
* **Auxiliary Space:** 💾 O(n) - Frequency array of size n+1

### ✅ **Why This Approach?**

* Linear time complexity (faster than sorting for large n)
* Optimal for competitive programming
* Bucket sort principle application

## 📊 **3️⃣ Binary Search on Answer**

### 💡 Algorithm Steps:

1. Binary search on possible H-index values from 0 to n.
2. For each candidate H, count papers with citations >= H.
3. If count >= H, try for larger H; otherwise try smaller.
4. Return the largest valid H found.

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), lo = 0, hi = n, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for (int c : citations) {
                if (c >= mid) cnt++;
            }
            if (cnt >= mid) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Binary search with linear counting
* **Auxiliary Space:** 💾 O(1) - Constant extra space

### ✅ **Why This Approach?**

* Demonstrates binary search on answer pattern
* Space efficient
* Good for educational purposes

## 📊 **4️⃣ Sorting with Early Termination**

### 💡 Algorithm Steps:

1. Sort citations in ascending order.
2. Iterate from end to beginning.
3. At position i from the end, check if n-i papers have citations[i] citations.
4. Return first valid H-index found.

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i < n; i++) {
            int h = n - i;
            if (citations[i] >= h) return h;
        }
        return 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting dominates
* **Auxiliary Space:** 💾 O(1) - In-place sorting

### ✅ **Why This Approach?**

* Ascending sort with clean logic
* Early termination optimization
* Alternative sorting perspective

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **🎯 Descending Sort + Linear Scan**            | 🟡 O(n log n)          | 🟢 O(1)                 | 🚀 Clean, intuitive logic         | 🐌 Slower than linear approaches     |
| 📊 **Frequency Counting**         | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Fastest time complexity        | 💾 Extra space required              |
| 🔍 **Binary Search**              | 🟡 O(n log n)          | 🟢 O(1)                 | 📚 Search pattern practice        | 🔧 Repeated counting overhead        |
| 📈 **Ascending Sort**             | 🟡 O(n log n)          | 🟢 O(1)                 | 🎯 Alternative perspective        | 🔧 Similar to main approach          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal time complexity**                        | 🥇 **Frequency Counting**            | ★★★★★                     |
| 📖 **Simplicity and clarity**                         | 🥈 **Descending Sort + Linear Scan**               | ★★★★★                     |
| 💾 **Memory constrained**                             | 🥉 **Ascending Sort**                | ★★★★☆                     |
| 🎯 **Learning binary search**                         | 🏅 **Binary Search**                 | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int n = citations.length, h = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (citations[i] >= n - i) h = n - i;
            else break;
        }
        return h;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def hIndex(self, citations):
        citations.sort(reverse=True)
        h = 0
        for i in range(len(citations)):
            if citations[i] >= i + 1:
                h = i + 1
            else:
                break
        return h
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
