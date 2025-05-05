# *5. Search in an Almost Sorted Array*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1)

## **🧩 Problem Description**

Given a sorted integer array `arr[]` consisting of distinct elements, where some elements of the array are moved to either of the adjacent positions, i.e. `arr[i]` may be present at `arr[i-1]` or `arr[i+1]`.
Given an integer `target`. You have to return the index (0-based) of the target in the array. If `target` is not present return -1.

## **📘 Examples**

### **Example 1:**
#### **Input:**
`arr[] = [10, 3, 40, 20, 50, 80, 70]`, `target = 40`
#### **Output:**
`2`
#### **Explanation:**
Index of 40 in the given array is 2.

### **Example 2:**
#### **Input:**
`arr[] = [10, 3, 40, 20, 50, 80, 70]`, `target = 90`
#### **Output:**
`-1`
#### **Explanation:**
90 is not present in the array.

### **Example 3:**
#### **Input:**
`arr[] = [-20]`, `target = -20`
#### **Output:**
`0`
#### **Explanation:**
-20 is the only element present in the array.

## **🔒 Constraints**

- $1 \leq arr.size() \leq 10^5$
- $-10^9 \leq arr[i] \leq 10^9$

## ✅ **My Approach**

### **Linear Search**

This is the most straightforward searching technique where we iterate through the array from the beginning to the end, comparing each element to the target. The search stops as soon as we find the element, returning its index. If we reach the end of the array without finding the target, we return -1.

### **Algorithm Steps:**

1. Start from the first element of the array (`i = 0`).
2. Compare each element `arr[i]` with the `target`.
3. If a match is found, return the index `i`.
4. If the loop completes without a match, return `-1`.



## 🧮 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n), where `n` is the number of elements in the array. In the worst case, we may have to check every element.
* **Expected Auxiliary Space Complexity:** O(1), as we do not use any extra space beyond a few variables.

## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        for(int i = 0; i < arr.size(); ++i)
            if(arr[i] == target) return i;
        return -1;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Optimized Binary Search for Almost Sorted Arrays**

This approach modifies binary search to account for the fact that the target may be at `mid`, `mid-1`, or `mid+1`.

### **Algorithm Steps:**

1. Initialize `low = 0`, `high = n - 1`.
2. While `low <= high`:

   * Compute `mid = low + (high - low) / 2`.
   * Check if `arr[mid] == target`. If yes, return `mid`.
   * Check `arr[mid - 1]` if `mid > low`, and `arr[mid + 1]` if `mid < high`.
   * If `target < arr[mid]`, move `high = mid - 2`.
   * Else, move `low = mid + 2`.
3. Return `-1` if not found.

```cpp
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) return mid;
            if (mid > l && arr[mid - 1] == target) return mid - 1;
            if (mid < r && arr[mid + 1] == target) return mid + 1;

            if (arr[mid] > target) r = mid - 2;
            else l = mid + 2;
        }
        return -1;
    }
};
```

### ✅ **Why This Approach?**

* Leverages the “almost sorted” nature of the array.
* More efficient than linear search for large arrays.

#### 📝 **Complexity Analysis:**

* **Time:** O(log n)
* **Auxiliary Space:** O(1)

## 📊 **3️⃣ Using `std::find`**

### **Algorithm Steps:**

1. Call `std::find(arr.begin(), arr.end(), target)`.
2. If iterator != `arr.end()`, return distance from `arr.begin()`; else return -1.

```cpp
#include <algorithm>
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        auto it = find(arr.begin(), arr.end(), target);
        return it == arr.end() ? -1 : it - arr.begin();
    }
};
```
### ✅ **Why This Approach?**

* Cleaner and more readable using STL.
* Avoids explicit loops—ideal for quick and concise code.

#### 📝 **Complexity Analysis:**

* **Time:** O(n)
* **Auxiliary Space:** O(1)


## 📊 **4️⃣ Hash Map Lookup (Best for unsorted data, many queries)**

### **Algorithm Steps:**

1. Create a hash map and store each element's value → index.
2. Look up the target in the map and return its index if found.

```cpp

#include <unordered_map>

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); ++i) {
            if (mp.find(arr[i]) == mp.end())
                mp[arr[i]] = i;
        }
        return mp.count(target) ? mp[target] : -1;
    }
};
```

### ✅ **Why This Approach?**

* Extremely fast for large arrays with repeated queries.
* Good preprocessing strategy.

#### 📝 **Complexity Analysis:**

* **Time:** O(n) to build, O(1) query
* **Auxiliary Space:** O(n)

## 📊 **5️⃣ Binary Search (Only for Sorted Arrays)**

### **Algorithm Steps:**

1. Sort a copy of the array and maintain a value → index mapping.
2. Apply binary search on the sorted array.
3. Use the map to return the original index.

```cpp
#include <unordered_map>
#include <algorithm>

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        unordered_map<int, int> indexMap;
        for (int i = 0; i < arr.size(); ++i)
            if (indexMap.find(arr[i]) == indexMap.end())
                indexMap[arr[i]] = i;

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        int l = 0, r = sortedArr.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (sortedArr[m] == target)
                return indexMap[target];
            else if (sortedArr[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;
    }
};
```

### ✅ **Why This Approach?**

* Optimal for large **sorted** arrays with infrequent updates.
* Faster lookup in O(log n) time after preprocessing.

#### 📝 **Complexity Analysis:**

* **Time:** O(n log n) for sorting, O(log n) for search
* **Auxiliary Space:** O(n) for map + copy

## 🆚 **Comparison of Approaches**

| **Approach**               | ⏱️ **Time**              | 🗂️ **Space** | ✅ **Pros**                         | ⚠️ **Cons**                  |
| -------------------------- | ------------------------ | ------------- | ---------------------------------- | ---------------------------- |
| Linear Search              | 🔸 O(n)                  | 🟢 O(1)       | Simple and works for unsorted data | Slow for large arrays        |
| Optimized Binary Search    | 🟢 O(log n)              | 🟢 O(1)       | Best for almost sorted arrays      | Needs careful mid checks     |
| `std::find` (STL)          | 🔸 O(n)                  | 🟢 O(1)       | Clean code using STL               | Still linear time            |
| Hash Map Lookup            | 🟢 O(n) + O(1)           | 🔸 O(n)       | Fastest for repeated searches      | Extra space needed           |
| Binary Search with Mapping | 🟡 O(n log n) + O(log n) | 🔸 O(n)       | Fast lookups after sorting         | Requires sorting and mapping |

### ✅ **Best Choice?**

| **Scenario**                   | **Recommended Approach**       |
| ------------------------------ | ------------------------------ |
| Single lookup, unsorted array  | 🥇 Linear Search / `std::find` |
| Many queries on same array     | 🥈 Hash Map Lookup             |
| Array is almost sorted         | 🥉 Optimized Binary Search     |
| Fully sorted, high-performance | 🎖️ Binary Search with Mapping  |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int findTarget(int[] arr, int target) {
        for(int i=0;i<arr.length;i++) if(arr[i]==target) return i;
        return -1;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def findTarget(self, arr, target):
        for i in range(len(arr)):
            if arr[i] == target: return i
        return -1
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>



