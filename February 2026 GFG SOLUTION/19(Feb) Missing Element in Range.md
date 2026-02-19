---
title: "🔍 Missing Element in Range | GFG Solution 🎯"
keywords🏷️: ["🔍 missing elements", "📊 range query", "📈 set operations", "🔢 array search", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Missing Element in Range: find all numbers within a given range not present in array using efficient marking technique. 🚀"
date: 📅 2025-02-19
---

# *19. Missing Element in Range*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/missing-element-in-range/1)

## **🧩 Problem Description**

Given an array `arr[]` of integers and a range `[low, high]`, find all the numbers within the range that are **not present** in the array. Return the missing numbers in sorted order.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [10, 12, 11, 15], low = 10, high = 15
Output: [13, 14]
Explanation: Numbers 13 and 14 lie in the range [10, 15] but are not present in the array.
```

### Example 2

```cpp
Input: arr[] = [1, 4, 11, 51, 15], low = 50, high = 55
Output: [50, 52, 53, 54, 55]
Explanation: Numbers 50, 52, 53, 54 and 55 lie in the range [50, 55] but are not present in the array.
```

### Example 3

```cpp
Input: arr[] = [5, 6, 7, 8, 9], low = 1, high = 10
Output: [1, 2, 3, 4, 10]
Explanation: Numbers 1, 2, 3, 4, and 10 are missing from the range [1, 10].
```

## **🔒 Constraints**

* $1 \le \text{arr.size()}, \text{low}, \text{high} \le 10^5$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal solution uses **Boolean Array Marking** to efficiently track present elements:

### **Boolean Marking with Range Filtering**

1. **Create Marking Array:**
   * Build a boolean array of size `(high - low + 1)` initialized to `false`.
   * This represents all positions in the range `[low, high]`.

2. **Mark Present Elements:**
   * Iterate through the input array.
   * For each element `x` that falls within `[low, high]`, mark `present[x - low] = true`.
   * Ignore elements outside the range (optimization over set approach).

3. **Collect Missing Numbers:**
   * Iterate through the boolean array.
   * For each `false` position at index `i`, add `low + i` to the result.
   * The result is automatically sorted due to sequential iteration.

4. **Return Result:**
   * Return the collected missing numbers.

**Key Advantage:** This approach only processes elements within the range and provides O(1) lookup and marking time, making it more efficient than set-based approaches for small to medium ranges.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + r), where n is the size of the array and r is the range size (high - low + 1). We iterate through the array once to mark present elements O(n), then iterate through the range once to collect missing elements O(r).
* **Expected Auxiliary Space Complexity:** O(r), where r is the range size (high - low + 1). We use a boolean array of size equal to the range, which is more space-efficient than a set when the range is smaller than the array size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> missingRange(vector<int>& arr, int low, int high) {
        vector<bool> present(high - low + 1, false);
        for (int x : arr) {
            if (x >= low && x <= high) present[x - low] = true;
        }
        vector<int> ans;
        for (int i = 0; i <= high - low; i++) {
            if (!present[i]) ans.push_back(low + i);
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Set-Based Approach**

### 💡 Algorithm Steps:

1. Insert all array elements into an unordered set for O(1) average lookup.
2. Iterate through the range [low, high] sequentially.
3. For each number, check if it exists in the set.
4. Collect all numbers not found in the set into result vector.

```cpp
class Solution {
public:
    vector<int> missingRange(vector<int>& arr, int low, int high) {
        unordered_set<int> s(arr.begin(), arr.end());
        vector<int> ans;
        for (int x = low; x <= high; x++) {
            if (s.find(x) == s.end()) ans.push_back(x);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + r) - Set creation O(n), range iteration O(r)
* **Auxiliary Space:** 💾 O(n) - Set stores all n elements

### ✅ **Why This Approach?**

* Simple and straightforward implementation
* Good when array size is much smaller than range
* Intuitive logic flow for beginners

## 📊 **3️⃣ Sorting with Two Pointers**

### 💡 Algorithm Steps:

1. Sort the input array in ascending order.
2. Use two pointers: one for the current range number and one for array index.
3. For each number in [low, high], check if it matches the current array element.
4. If match found, move array pointer; otherwise, add to missing list.

```cpp
class Solution {
public:
    vector<int> missingRange(vector<int>& arr, int low, int high) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int j = 0, n = arr.size();
        for (int i = low; i <= high; i++) {
            while (j < n && arr[j] < i) j++;
            if (j >= n || arr[j] != i) ans.push_back(i);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + r) - Sorting plus range traversal
* **Auxiliary Space:** 💾 O(1) - Excluding output array

### ✅ **Why This Approach?**

* Space efficient without additional data structures
* Natural for problems requiring sorted input
* Good when array contains many duplicates

## 📊 **4️⃣ Binary Search on Sorted Array (Optional)**

### 💡 Algorithm Steps:

1. Sort the input array for binary search capability.
2. For each number in the range [low, high], perform binary search.
3. If binary search fails to find the number, add it to result.
4. Return collected missing numbers.

```cpp
class Solution {
public:
    vector<int> missingRange(vector<int>& arr, int low, int high) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (int x = low; x <= high; x++) {
            if (!binary_search(arr.begin(), arr.end(), x)) ans.push_back(x);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + r log n) - Sorting plus r binary searches
* **Auxiliary Space:** 💾 O(1) - Constant extra space

### ✅ **Why This Approach?**

* Leverages standard library functions
* Good when range is small but array is large
* Clean and concise implementation

## 📊 **4️⃣ Optimized Set with Range Pre-filtering**

### 💡 Algorithm Steps:

1. Create a set but only insert elements that fall within [low, high].
2. This reduces memory usage when array has many out-of-range elements.
3. Iterate through range and check against filtered set.
4. Collect missing numbers into result.

```cpp
class Solution {
public:
    vector<int> missingRange(vector<int>& arr, int low, int high) {
        unordered_set<int> s;
        for (int x : arr) {
            if (x >= low && x <= high) s.insert(x);
        }
        vector<int> ans;
        for (int i = low; i <= high; i++) {
            if (s.find(i) == s.end()) ans.push_back(i);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + r) - Linear passes through array and range
* **Auxiliary Space:** 💾 O(min(n, r)) - Set size limited by range

### ✅ **Why This Approach?**

* Memory efficient when many elements are out of range
* Combines benefits of set and filtering
* Better cache locality than full set

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Boolean Marking**            | 🟢 O(n + r)            | 🟢 O(r)                 | 🚀 Fast, predictable memory       | 💾 High space for large ranges       |
| 🔍 **Set-Based**                  | 🟢 O(n + r)            | 🟡 O(n)                 | 📖 Simple implementation          | 💾 Stores all elements               |
| 📊 **Sorting + Two Pointers**     | 🟡 O(n log n + r)      | 🟢 O(1)                 | 💾 Space efficient                | 🐌 Sorting overhead                  |
| 🔎 **Binary Search (Optional)**              | 🔴 O(n log n + r log n)| 🟢 O(1)                 | 🎯 Uses standard library          | 🐌 Repeated binary searches          |
| 🔧 **Filtered Set**               | 🟢 O(n + r)            | 🟢 O(min(n,r))          | ⚡ Memory optimized               | 🔧 Extra condition checks            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Small to medium range size**                     | 🥇 **Boolean Marking**               | ★★★★★                     |
| 📖 **Simple implementation needed**                   | 🥈 **Set-Based**                     | ★★★★☆                     |
| 💾 **Memory constrained**                             | 🥉 **Sorting + Two Pointers**        | ★★★★☆                     |
| 🎯 **Large range, small array**                       | 🏅 **Filtered Set**                  | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> missingRange(int[] arr, int low, int high) {
        boolean[] present = new boolean[high - low + 1];
        for (int x : arr) {
            if (x >= low && x <= high) present[x - low] = true;
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i <= high - low; i++) {
            if (!present[i]) ans.add(low + i);
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def missingRange(self, arr, low, high):
        present = [False] * (high - low + 1)
        for x in arr:
            if low <= x <= high:
                present[x - low] = True
        return [low + i for i in range(high - low + 1) if not present[i]]
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
