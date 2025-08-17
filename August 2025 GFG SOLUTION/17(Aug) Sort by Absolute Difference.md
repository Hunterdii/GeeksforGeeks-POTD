---
title: "📏 Sort by Absolute Difference | GFG Solution 🔍"
keywords🏷️: ["📏 sorting", "🔍 absolute difference", "📍 stable sort", "📈 custom comparator", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Sort by Absolute Difference problem: rearrange array elements based on their absolute difference from a target value using stable sorting technique. 🚀"
date: 📅 2025-08-17
---

# *17. Sort by Absolute Difference*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sort-by-absolute-difference-1587115621/1)

## **🧩 Problem Description**

You are given a number `x` and array `arr[]`. Your task is to rearrange the elements of the array according to the **absolute difference** with `x`, i.e., an element having minimum difference comes first, and so on.

**Note:** If two or more elements are at equal distances arrange them in the same sequence as in the given array.

## **📘 Examples**

### Example 1

```cpp
Input: x = 7, arr[] = [10, 5, 3, 9, 2]
Output: [5, 9, 10, 3, 2]
Explanation: Sorting the numbers according to the absolute difference with 7:
- |5-7| = 2 (closest)
- |9-7| = 2 (same distance, maintain original order)
- |10-7| = 3
- |3-7| = 4
- |2-7| = 5 (farthest)
```

### Example 2

```cpp
Input: x = 6, arr[] = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
Explanation: Sorting the numbers according to the absolute difference with 6:
- |5-6| = 1 (closest)
- |4-6| = 2
- |3-6| = 3
- |2-6| = 4
- |1-6| = 5 (farthest)
```

## **🔒 Constraints**

* $1 \le x \le 10^5$
* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses **Stable Sort** with a **Custom Comparator** to maintain the original relative order of elements with equal absolute differences:

### **Stable Sort with Lambda Comparator**

1. **Custom Comparator:**
   * Define a lambda function that compares two elements based on their absolute difference from `x`.
   * For elements `a` and `b`, compare `|a - x|` with `|b - x|`.

2. **Stable Sorting:**
   * Use `stable_sort()` instead of regular `sort()` to preserve the original order of elements with equal distances.
   * This ensures that if `|a - x| == |b - x|`, then `a` and `b` maintain their relative positions from the original array.

3. **In-Place Rearrangement:**
   * The sorting is performed directly on the input array without requiring additional space for the result.

4. **Algorithm Flow:**
   * Calculate absolute difference for each element with respect to `x`.
   * Sort elements in ascending order of their absolute differences.
   * Elements with smaller differences appear first in the final arrangement.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. This is due to the stable sorting operation which has a time complexity of O(n log n).
* **Expected Auxiliary Space Complexity:** O(1), as we perform the sorting operation in-place without using any additional data structures proportional to the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    void rearrange(vector<int> &arr, int x) {
        stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x);
        });
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Custom Comparison with Pair Approach**

### 💡 Algorithm Steps:

1. Create pairs of (distance, original_index) to maintain stability manually.
2. Sort based on distance from target value x.
3. Extract elements in the new sorted order.
4. Copy back to original array maintaining relative order for equal distances.

```cpp
class Solution {
public:
    void rearrange(vector<int> &arr, int x) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < arr.size(); i++) {
            pairs.push_back({abs(arr[i] - x), i});
        }
        sort(pairs.begin(), pairs.end());
        vector<int> temp(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            temp[i] = arr[pairs[i].second];
        }
        arr = temp;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Due to sorting operation
* **Auxiliary Space:** 💾 O(n) - Extra space for pairs and temporary array

### ✅ **Why This Approach?**

* Maintains stability explicitly through index tracking
* Clear separation of distance calculation and sorting logic
* Easy to debug and understand the sorting process

## 📊 **3️⃣ Counting Sort for Limited Range**

### 💡 Algorithm Steps:

1. Calculate maximum possible distance in the array.
2. Use counting sort if distance range is reasonable (≤ 10^6).
3. Count frequency of each distance value.
4. Reconstruct array by iterating through distances in ascending order.

```cpp
class Solution {
public:
    void rearrange(vector<int> &arr, int x) {
        int maxDist = 0;
        for (int val : arr) maxDist = max(maxDist, abs(val - x));
        if (maxDist > 1000000) {
            stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
                return abs(a - x) < abs(b - x);
            });
            return;
        }
        vector<vector<int>> buckets(maxDist + 1);
        for (int val : arr) buckets[abs(val - x)].push_back(val);
        int idx = 0;
        for (auto& bucket : buckets) {
            for (int val : bucket) arr[idx++] = val;
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + k) where k is max distance - Linear when k is small
* **Auxiliary Space:** 💾 O(n + k) - Buckets and temporary storage

### ✅ **Why This Approach?**

* Optimal for small distance ranges
* Linear time complexity when applicable
* Natural stability preservation within buckets


## 📊 **4️⃣ Bucket Sort with Distance Grouping**

### 💡 Algorithm Steps:

1. Create buckets for each possible distance value (0 to max_distance).
2. Place elements into appropriate buckets based on their absolute difference from x.
3. Concatenate buckets in order to get the final sorted array.
4. Natural stability preservation since elements are added to buckets in original order.

```cpp
class Solution {
public:
    void rearrange(vector<int> &arr, int x) {
        map<int, vector<int>> buckets;
        for (int val : arr) {
            buckets[abs(val - x)].push_back(val);
        }
        int idx = 0;
        for (auto& [distance, elements] : buckets) {
            for (int val : elements) {
                arr[idx++] = val;
            }
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + k log k) where k is unique distances
* **Auxiliary Space:** 💾 O(n) - Bucket storage

### ✅ **Why This Approach?**

* Natural grouping by distance
* Automatic stability within buckets
* Clean and intuitive implementation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Stable Sort Lambda**         | 🟢 O(n log n)          | 🟢 O(1)                 | 🚀 Optimal and concise            | 🔧 Relies on STL stability           |
| 🔍 **Pair-Based**                 | 🟢 O(n log n)          | 🟡 O(n)                 | 📖 Explicit stability control    | 💾 Extra space required              |
| 📊 **Counting Sort**              | 🟢 O(n + k)            | 🟡 O(n + k)             | 🎯 Linear for small ranges        | 🐌 Poor for large distance ranges    |
| 🪣 **Bucket Sort**                | 🟡 O(n + k log k)      | 🟡 O(n)                 | 🎯 Natural grouping               | 💾 Extra space for buckets           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General optimal solution**                      | 🥇 **Stable Sort Lambda**            | ★★★★★                     |
| 📖 **Need explicit stability control**               | 🥈 **Pair-Based**                    | ★★★★☆                     |
| 🔧 **Small distance ranges**                        | 🥉 **Counting Sort**                 | ★★★★☆                     |
| 📊 **Educational/Learning purposes**                 | 🏅 **Bucket Sort**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public void rearrange(int[] arr, int x) {
        Integer[] indices = new Integer[arr.length];
        for (int i = 0; i < arr.length; i++) indices[i] = i;
        Arrays.sort(indices, (a, b) -> Integer.compare(Math.abs(arr[a] - x), Math.abs(arr[b] - x)));
        int[] temp = new int[arr.length];
        for (int i = 0; i < arr.length; i++) temp[i] = arr[indices[i]];
        System.arraycopy(temp, 0, arr, 0, arr.length);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def rearrange(self, arr, x):
        arr.sort(key=lambda val: abs(val - x))
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
