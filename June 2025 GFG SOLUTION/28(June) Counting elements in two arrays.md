---
title: "🔢 Counting Elements in Two Arrays | GFG Solution 📊"
keywords🏷️: ["🔢 count elements", "📊 frequency array", "🔍 binary search", "📈 prefix sum", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to count elements in array b that are less than or equal to each element in array a using frequency array and prefix sum technique. 🚀"
date: 📅 2025-06-28
---

# *28. Counting Elements in Two Arrays*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1)

## **🧩 Problem Description**

You are given two **unsorted arrays** `a[]` and `b[]`. Both arrays may contain **duplicate elements**. For each element in `a[]`, your task is to count how many elements in `b[]` are **less than or equal** to that element.

## **📘 Examples**

### Example 1

```cpp
Input: a[] = [4, 8, 7, 5, 1], b[] = [4, 48, 3, 0, 1, 1, 5]
Output: [5, 6, 6, 6, 3]
Explanation: 
For a[0] = 4, there are 5 elements in b (4, 3, 0, 1, 1) that are ≤ 4.
For a[1] = 8 and a[2] = 7, there are 6 elements in b that are ≤ 8 and ≤ 7.
For a[3] = 5, there are 6 elements in b that are ≤ 5.
For a[4] = 1, there are 3 elements in b (0, 1, 1) that are ≤ 1.
```

### Example 2

```cpp
Input: a[] = [10, 20], b[] = [30, 40, 50]
Output: [0, 0]
Explanation: 
For a[0] = 10 and a[1] = 20, there are no elements in b that are less than or equal to 10 or 20. Hence, the output is [0, 0].
```

## **🔒 Constraints**

* $1 \le a.size(), b.size() \le 10^5$
* $0 \le a[i], b[j] \le 10^5$

## **✅ My Approach**

The optimal approach uses **Frequency Array** with **Prefix Sum** technique to efficiently count elements:

### **Frequency Array + Prefix Sum**

1. **Find Maximum Element:**
   * Determine the maximum element in array `b` to create frequency array.

2. **Build Frequency Array:**
   * Create a frequency array `cnt[]` where `cnt[i]` represents count of element `i` in array `b`.

3. **Convert to Prefix Sum:**
   * Transform frequency array into prefix sum array where `cnt[i]` now represents count of elements ≤ `i`.

4. **Query Processing:**
   * For each element `x` in array `a`, the answer is `cnt[min(x, max_element)]`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + m + max), where n is size of array a, m is size of array b, and max is the maximum element in array b. We traverse both arrays once and build prefix sum in O(max) time.
* **Expected Auxiliary Space Complexity:** O(max), where max is the maximum element in array b. We use a frequency array of size max+1 to store element counts.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size(), mx = *max_element(b.begin(), b.end());
        vector<int> res(n), cnt(mx + 1);
        for (int x : b) cnt[x]++;
        for (int i = 1; i <= mx; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < n; i++) res[i] = cnt[min(a[i], mx)];
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Sorting + Binary Search Approach**

### 💡 Algorithm Steps:

1. Sort array `b` to enable binary search.
2. For each element in `a`, use upper_bound to find count of elements ≤ current element.
3. Return the distance from begin to upper_bound iterator.

```cpp
class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int> res(a.size());
        sort(b.begin(), b.end());
        for (int i = 0; i < a.size(); i++) {
            res[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m log m + n log m)
* **Auxiliary Space:** 💾 O(1) - Excluding output array

### ✅ **Why This Approach?**

* Simple implementation using STL functions.
* Memory efficient for large maximum values.

## 📊 **3️⃣ HashMap + Prefix Sum Approach**

### 💡 Algorithm Steps:

1. Count frequency of each unique element in `b` using HashMap.
2. Sort unique elements and build cumulative prefix sum.
3. For each element in `a`, use binary search on sorted unique elements.

```cpp
class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int> res(a.size());
        map<int, int> freq;
        for (int x : b) freq[x]++;
        vector<pair<int, int>> sorted_freq;
        for (auto& p : freq) sorted_freq.push_back(p);
        for (int i = 1; i < sorted_freq.size(); i++) {
            sorted_freq[i].second += sorted_freq[i-1].second;
        }
        for (int i = 0; i < a.size(); i++) {
            auto it = upper_bound(sorted_freq.begin(), sorted_freq.end(), 
                                make_pair(a[i], INT_MAX));
            res[i] = (it == sorted_freq.begin()) ? 0 : prev(it)->second;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m log m + n log m)
* **Auxiliary Space:** 💾 O(unique elements in b)

### ✅ **Why This Approach?**

* Efficient for sparse data with many unique values.
* Handles extremely large element ranges gracefully.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| ✅ **Frequency Array**            | 🟢 O(n + m + max)      | 🟡 O(max)               | ⚡ Fastest for small max values   | 💾 Space depends on max element      |
| 🔍 **Binary Search**              | 🟡 O(m log m + n log m)| 🟢 O(1)                 | 🔧 Memory efficient               | ⏱️ Slower for large arrays           |
| 🔢 **HashMap + Prefix Sum**       | 🟡 O(m log m + n log m)| 🟢 O(unique)            | 🚀 Handles sparse data well      | 🧮 Complex implementation            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                | 🎖️ **Recommended Approach** | 🔥 **Rating** |
| ---------------------------------------------- | ---------------------------- | ------------- |
| ⚡ Small range (0 ≤ elements ≤ 10⁶)             | 🥇 **Frequency Array**       | ★★★★★         |
| 🔍 High max value, low memory usage required   | 🥈 **Binary Search**         | ★★★★☆         |
| 📊 Sparse distribution with many unique values | 🥉 **HashMap + Prefix Sum**  | ★★★☆☆         |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public static ArrayList<Integer> countLessEq(int[] a, int[] b) {
        int max = 0;
        for (int x : b) max = Math.max(max, x);
        int[] cnt = new int[max + 1];
        for (int x : b) cnt[x]++;
        for (int i = 1; i <= max; i++) cnt[i] += cnt[i - 1];
        ArrayList<Integer> res = new ArrayList<>();
        for (int x : a) res.add(cnt[Math.min(x, max)]);
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countLessEq(self, a, b):
        if not b: return [0]*len(a)
        m = max(b)
        cnt = [0]*(m+1)
        for x in b: cnt[x] += 1
        for i in range(1, m+1): cnt[i] += cnt[i-1]
        return [cnt[min(x, m)] for x in a]
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
