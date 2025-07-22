---
title: "🧩 Smallest Positive Missing | GFG Solution 🔍"
keywords🏷️: ["🧩 smallest positive missing", "🔍 index marking", "📍 array manipulation", "📈 cyclic sort", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Smallest Positive Missing Number problem: find the smallest missing positive integer using index marking technique with O(n) time and O(1) space. 🚀"
date: 📅 2025-07-22
---

# *22. Smallest Positive Missing*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1)

## **🧩 Problem Description**

You are given an unsorted array `arr[]` of size `N` that can contain **negative numbers** and **zeros**. Your task is to **find the smallest positive number missing from the array**.

### 📝 Important Notes:

* Positive integers start from `1`.
* Ignore all values ≤ 0 and values greater than the array size while computing the result.
* The missing number must be **positive** and **strictly greater than 0**.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.
The array contains 1, 2, 4, 7 but missing 3.
```

### Example 2

```cpp
Input: arr[] = [5, 3, 2, 5, 1]
Output: 4
Explanation: Smallest positive missing number is 4.
The array contains 1, 2, 3, 5 but missing 4.
```

### Example 3

```cpp
Input: arr[] = [-8, 0, -1, -4, -3]
Output: 1
Explanation: Smallest positive missing number is 1.
The array contains no positive numbers, so 1 is missing.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $-10^6 \le \text{arr}[i] \le 10^6$

## **✅ My Approach**

The optimal approach uses **Index Marking** technique to achieve O(n) time complexity with O(1) space complexity:

### **Index Marking Technique**

1. **Clean Invalid Numbers:**
   * Replace all non-positive numbers (≤ 0) with a value greater than n (array size).
   * This ensures all numbers are positive and within a manageable range.

2. **Mark Presence Using Signs:**
   * For each number `x` in the array, mark its presence by making `arr[x-1]` negative.
   * Use `abs(arr[i])` to get the actual value since we're modifying signs.
   * Only mark if `x` is within valid range [1, n].

3. **Find First Unmarked Position:**
   * Traverse the array to find the first positive number.
   * The index of first positive number + 1 gives the smallest missing positive.
   * If all numbers are negative (marked), return n+1.

4. **Key Insight:**
   * We use the array itself as a hash map where index represents the number.
   * Negative sign indicates presence, positive indicates absence.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We make three separate passes through the array: first to clean invalid numbers, second to mark presence, and third to find the first unmarked position.
* **Expected Auxiliary Space Complexity:** O(1), as we only use the input array for marking and a few constant variables, requiring no additional space proportional to input size.

## **🔧 Code (C)**

```c
int missingNumber(int a[], int n) {
    for (int i = 0; i < n; i++) if (a[i] <= 0) a[i] = n + 1;
    for (int i = 0; i < n; i++) {
        int x = abs(a[i]);
        if (x <= n) a[x - 1] = -abs(a[x - 1]);
    }
    for (int i = 0; i < n; i++) if (a[i] > 0) return i + 1;
    return n + 1;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) if (a[i] <= 0) a[i] = n + 1;
        for (int i = 0; i < n; i++) {
            int x = abs(a[i]);
            if (x <= n) a[x - 1] = -abs(a[x - 1]);
        }
        for (int i = 0; i < n; i++) if (a[i] > 0) return i + 1;
        return n + 1;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Set-Based Approach**

### 💡 Algorithm Steps:

1. Insert all positive numbers into an unordered set for O(1) lookup.
2. Starting from 1, check each positive integer sequentially.
3. Return the first integer not found in the set.
4. Continue until we find the missing positive number.

```cpp
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        for (int i = 1; i <= arr.size() + 1; i++) {
            if (s.find(i) == s.end()) return i;
        }
        return arr.size() + 1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time for set creation and lookup
* **Auxiliary Space:** 💾 O(n) - Additional space for the set

### ✅ **Why This Approach?**

* Simple and intuitive logic flow
* Easy to understand and implement
* Good for interview discussions and debugging

## 📊 **3️⃣ Sorting Approach**

### 💡 Algorithm Steps:

1. Sort the entire array to arrange elements in ascending order.
2. Skip all negative numbers and zeros at the beginning.
3. Track the expected positive number starting from 1.
4. Find the first gap in the positive sequence where expected number is missing.

```cpp
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int missing = 1;
        for (int x : arr) {
            if (x == missing) missing++;
            else if (x > missing) break;
        }
        return missing;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Due to sorting operation
* **Auxiliary Space:** 💾 O(1) - Only constant extra space used

### ✅ **Why This Approach?**

* Space efficient with constant space usage
* Handles duplicates naturally without extra logic
* Clear sequential processing after sorting

## 📊 **4️⃣ Swap-Based Cyclic Sort**

### 💡 Algorithm Steps:

1. Use cyclic sort to place each positive number at its correct index position.
2. For each element, if it's positive and within range [1,n], swap it to position `arr[i]-1`.
3. Continue swapping until each element is in its correct position or out of range.
4. After sorting, find the first position where `arr[i] != i+1`.

```cpp
class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; ++i)
            while (a[i] > 0 && a[i] <= n && a[i] != a[a[i] - 1])
                swap(a[i], a[a[i] - 1]);
        for (int i = 0; i < n; ++i)
            if (a[i] != i + 1) return i + 1;
        return n + 1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each element is moved at most once to its correct position
* **Auxiliary Space:** 💾 O(1) - In-place sorting with constant space

### ✅ **Why This Approach?**

* Optimal time and space complexity combination
* In-place arrangement without extra data structures
* Classic cyclic sort pattern for missing number problems

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Index Marking**              | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal time & space           | 🔧 Modifies input array              |
| 🔍 **Set-Based**                  | 🟢 O(n)                | 🟡 O(n)                 | 📖 Easy to understand             | 💾 Extra space required              |
| 📊 **Sorting**                    | 🟡 O(n log n)          | 🟢 O(1)                 | 🎯 Handles duplicates well        | 🐌 Slower time complexity            |
| 🔄 **Cyclic Sort**                | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Classic approach               | 🔧 Complex swapping logic            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Index Marking**                 | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Set-Based**                     | ★★★★☆                     |
| 🔧 **Cannot modify input**                            | 🥉 **Sorting**                     | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Cyclic Sort**                 | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int missingNumber(int[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) if (a[i] <= 0) a[i] = n + 1;
        for (int i = 0; i < n; i++) {
            int x = Math.abs(a[i]);
            if (x <= n) a[x - 1] = -Math.abs(a[x - 1]);
        }
        for (int i = 0; i < n; i++) if (a[i] > 0) return i + 1;
        return n + 1;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def missingNumber(self, a):
        n = len(a)
        for i in range(n):
            if a[i] <= 0: a[i] = n + 1
        for i in range(n):
            x = abs(a[i])
            if x <= n: a[x - 1] = -abs(a[x - 1])
        for i in range(n):
            if a[i] > 0: return i + 1
        return n + 1
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
