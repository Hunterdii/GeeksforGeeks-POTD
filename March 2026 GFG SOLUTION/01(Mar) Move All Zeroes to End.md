---
title: "🔄 Move All Zeroes to End | GFG Solution 🎯"
keywords🏷️: ["🔄 move zeros", "🔍 two pointers", "📊 array rearrangement", "📈 in-place algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Move All Zeroes to End: rearrange array by moving zeros to end while maintaining order using efficient two-pointer technique. 🚀"
date: 📅 2025-03-01
---

# *01. Move All Zeroes to End*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1)

## **🧩 Problem Description**

You are given an array `arr[]` of non-negative integers. You have to move all the zeros in the array to the **right end** while maintaining the **relative order** of the non-zero elements. The operation must be performed **in place**, meaning you should not use extra space for another array.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end while maintaining 
the relative order of non-zero elements.
```

### Example 2

```cpp
Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: No change in array as there are no 0s.
```

### Example 3

```cpp
Input: arr[] = [0, 0]
Output: [0, 0]
Explanation: No change in array as there are all 0s.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal solution uses **Two-Pointer In-Place Rearrangement**:

### **Two-Pointer Strategy**

1. **Key Insight:**
   * Use a pointer to track the position where the next non-zero element should be placed.
   * Traverse the array and move non-zero elements to their correct positions.
   * This automatically pushes zeros to the end.

2. **Position Tracking:**
   * Maintain a `pos` pointer starting at index 0.
   * This pointer always points to the next position for a non-zero element.
   * When we find a non-zero element, place it at `pos` and increment `pos`.

3. **In-Place Operation:**
   * Simply copy non-zero elements to positions 0, 1, 2, ...
   * After all non-zeros are placed, fill remaining positions with zeros.
   * This maintains relative order and works in-place.

4. **Algorithm Steps:**
   * Iterate through array with index `i`.
   * If `arr[i] != 0`, copy it to `arr[pos]` and increment `pos`.
   * After loop, fill `arr[pos]` to `arr[n-1]` with zeros.
   * Return the modified array.

**Why This Works:** By copying non-zeros to the front sequentially, we preserve their order. Filling remaining positions with zeros pushes all zeros to the end.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We make a single pass to move non-zero elements, and another pass to fill zeros in the remaining positions, resulting in linear time.
* **Expected Auxiliary Space Complexity:** O(1), as we perform the rearrangement in-place using only a constant amount of extra space for pointer variables.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int pos = 0;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] != 0) arr[pos++] = arr[i];
        while (pos < arr.size()) arr[pos++] = 0;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Swap-Based Two-Pointer**

### 💡 Algorithm Steps:

1. Use a pointer to track position for next non-zero element.
2. When non-zero element found, swap with element at tracked position.
3. Increment position pointer after each swap.
4. This preserves order and moves zeros to end in single pass.

```cpp
class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[count]);
                count++;
            }
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with swaps
* **Auxiliary Space:** 💾 O(1) - In-place with constant space

### ✅ **Why This Approach?**

* Single pass solution
* Uses swap instead of copy + fill
* Elegant and widely used approach

## 📊 **3️⃣ Stable Partition Approach**

### 💡 Algorithm Steps:

1. Use stable partition to separate non-zeros and zeros.
2. Maintain relative order during partitioning.
3. All non-zeros move to front, zeros to end.
4. STL stable_partition maintains element order.

```cpp
class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        stable_partition(arr.begin(), arr.end(), [](int x) { return x != 0; });
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear partitioning
* **Auxiliary Space:** 💾 O(1) - In-place partition

### ✅ **Why This Approach?**

* One-liner solution using STL
* Clean and concise
* Maintains stability automatically

## 📊 **4️⃣ Count and Fill Approach**

### 💡 Algorithm Steps:

1. Count number of non-zero elements.
2. Create temporary storage for non-zeros.
3. Fill original array with non-zeros first, then zeros.
4. Two-pass solution with explicit separation.

```cpp
class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp;
        for (int x : arr)
            if (x != 0) temp.push_back(x);
        for (int i = 0; i < temp.size(); i++)
            arr[i] = temp[i];
        for (int i = temp.size(); i < n; i++)
            arr[i] = 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time with multiple passes
* **Auxiliary Space:** 💾 O(n) - Temporary array for non-zeros

### ✅ **Why This Approach?**

* Very clear and easy to understand
* Good for educational purposes
* Explicit separation of concerns

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Copy + Fill**                | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Simple two-pass solution       | 🔧 Two passes required               |
| 🔄 **Swap-Based**                 | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Single pass with swaps         | 🔧 Swap overhead                     |
| 📊 **Stable Partition**           | 🟢 O(n)                | 🟢 O(1)                 | 🎯 One-liner, clean               | 🔧 STL dependency                    |
| 📈 **Count and Fill**             | 🟢 O(n)                | 🔴 O(n)                 | 📖 Very clear logic               | 💾 Extra space required              |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Swap-Based**                    | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Copy + Fill**                   | ★★★★★                     |
| 🔧 **Shortest code**                                  | 🥉 **Stable Partition**              | ★★★★☆                     |
| 🎯 **Learning purposes**                              | 🏅 **Count and Fill**                | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    void pushZerosToEnd(int[] arr) {
        int pos = 0;
        for (int i = 0; i < arr.length; i++)
            if (arr[i] != 0) arr[pos++] = arr[i];
        while (pos < arr.length) arr[pos++] = 0;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def pushZerosToEnd(self, arr):
        pos = 0
        for i in range(len(arr)):
            if arr[i] != 0:
                arr[pos] = arr[i]
                pos += 1
        while pos < len(arr):
            arr[pos] = 0
            pos += 1
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
