---
title: "🔢 Find H-Index | GFG Solution 🔍"
keywords🏷️: ["🔢 h-index", "🏷️ bucket counting", "📊 sorting", "🔍 binary search", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Find H-Index problem: calculate researcher's h-index using optimal bucket counting technique with linear time complexity. 🚀"
date: 📅 2025-08-18
---

# *18. Find H-Index*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-h-index--165609/1)

## **🧩 Problem Description**

You are given an array `citations[]`, where each element `citations[i]` represents the number of citations received by the ith paper of a researcher. Your task is to calculate the researcher's **H-index**.

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
Explanation: There are 3 papers (with citation counts of 5, 2, and 4) that have 2 or more citations. 
However, the H-Index cannot be 3 because there aren't 3 papers with 3 or more citations.
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

The optimal approach uses **Bucket Counting** technique to achieve linear time complexity:

### **Bucket Counting Approach**

1. **Create Bucket Array:**
   * Create a bucket array of size `n+1` where `n` is the number of papers.
   * Index `i` represents papers with exactly `i` citations (or `n+` citations for index `n`).

2. **Count Citations:**
   * For each citation count, increment the corresponding bucket.
   * Citations greater than `n` are placed in bucket `n` since h-index cannot exceed `n`.

3. **Calculate H-Index:**
   * Traverse buckets from right to left (highest to lowest citations).
   * Maintain cumulative count of papers with at least `i` citations.
   * Return the largest `i` where cumulative count ≥ `i`.

4. **Key Insight:**
   * H-index cannot exceed the total number of papers.
   * We only need to track counts, not exact citation values above `n`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the citations array. We make two single passes: one to populate buckets and one to calculate h-index.
* **Expected Auxiliary Space Complexity:** O(n), where n is the size of the citations array. We use a bucket array of size n+1 to store citation counts.

## **🔧 Code (C)**

```c
int hIndex(int* citations, int citationsSize) {
    int n = citationsSize;
    int* bucket = (int*)calloc(n + 1, sizeof(int));
    
    for (int i = 0; i < n; i++) 
        bucket[citations[i] > n ? n : citations[i]]++;
    
    int count = 0;
    for (int i = n; i >= 0; i--) {
        count += bucket[i];
        if (count >= i) {
            free(bucket);
            return i;
        }
    }
    free(bucket);
    return 0;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> bucket(n + 1, 0);
        
        for (int c : citations) bucket[min(c, n)]++;
        
        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += bucket[i];
            if (count >= i) return i;
        }
        return 0;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Sorting Approach**

### 💡 Algorithm Steps:

1. Sort citations in descending order for optimal comparison.
2. Iterate through sorted array comparing index with citation values.
3. Return maximum valid h-index found during iteration.
4. Early termination when h-index condition cannot be satisfied.

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = 0;
        for (int i = 0; i < citations.size() && citations[i] > h; i++) h++;
        return h;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Dominated by sorting operation
* **Auxiliary Space:** 💾 O(1) - In-place sorting with constant extra space

### ✅ **Why This Approach?**

* Intuitive and easy to understand algorithm flow
* Minimal memory overhead with in-place operations
* Good performance for medium-sized datasets

## 📊 **3️⃣ Binary Search Approach**

### 💡 Algorithm Steps:

1. Binary search on possible h-index values from 0 to n.
2. For each candidate h-value, count citations >= h efficiently.
3. Find maximum h where at least h papers have h+ citations.
4. Optimize search space by eliminating impossible ranges.

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            int count = 0;
            for (int c : citations) if (c >= mid) count++;
            if (count >= mid) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Binary search with linear validation
* **Auxiliary Space:** 💾 O(1) - Constant space complexity

### ✅ **Why This Approach?**

* Elegant divide and conquer strategy
* Works well when citations are already sorted
* Good for theoretical analysis and interviews

## 📊 **4️⃣ Direct Counting Approach**

### 💡 Algorithm Steps:

1. Count papers with exactly i citations for each possible value.
2. Build cumulative count from highest to lowest citations.
3. Find largest h where cumulative count >= h papers exist.
4. Single pass counting with reverse cumulative sum.

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> papers(n + 1);
        for (int c : citations) papers[min(c, n)]++;
        
        int k = n;
        for (int s = papers[n]; k > s; s += papers[--k]);
        return k;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass counting and accumulation
* **Auxiliary Space:** 💾 O(n) - Bucket array for counting

### ✅ **Why This Approach?**

* Optimal linear time complexity
* Cache-friendly sequential access patterns
* Minimal conditional branches

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Bucket Counting**            | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Optimal time complexity        | 💾 Requires extra space              |
| 🔍 **Sorting**                     | 🟡 O(n log n)          | 🟢 O(1)                 | 📖 Simple and intuitive           | 🐌 Slower for large inputs          |
| 📊 **Binary Search**              | 🟡 O(n log n)          | 🟢 O(1)                 | 🎯 Space efficient                | 💻 Complex implementation            |
| 🔄 **Direct Counting**            | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Linear time optimal            | 🔧 Similar to bucket approach       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General use case, optimal performance**      | 🥇 **Bucket Counting**               | ★★★★★                     |
| 📖 **Memory constraints, simplicity**             | 🥈 **Sorting**                       | ★★★★☆                     |
| 🔧 **Educational, interview prep**                | 🥉 **Binary Search**                 | ★★★☆☆                     |
| 🎯 **Alternative linear solution**                | 🏅 **Direct Counting**               | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int[] bucket = new int[n + 1];
        
        for (int c : citations) bucket[Math.min(c, n)]++;
        
        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += bucket[i];
            if (count >= i) return i;
        }
        return 0;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def hIndex(self, citations):
        n = len(citations)
        bucket = [0] * (n + 1)
        
        for c in citations:
            bucket[min(c, n)] += 1
        
        count = 0
        for i in range(n, -1, -1):
            count += bucket[i]
            if count >= i:
                return i
        return 0
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
