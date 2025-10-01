---
title: "🔄 All Unique Permutations of an Array | GFG Solution 🎯"
keywords🏷️: ["🔄 permutations", "🔍 backtracking", "📊 STL", "🎯 next_permutation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the All Unique Permutations of an Array problem: generate all distinct permutations of an array that may contain duplicates using efficient algorithms. 🚀"
date: 📅 2025-10-01
---

# *01. All Unique Permutations of an Array*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1)

## **🧩 Problem Description**

You are given an array `arr[]` that may contain duplicates. Your task is to find all possible **distinct permutations** of the array in **sorted order**.

A permutation is a rearrangement of all elements of the array. Since the array may contain duplicate elements, some permutations might be identical. We need to generate only the unique permutations and return them in lexicographically sorted order.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 3, 3]
Output: [[1, 3, 3], [3, 1, 3], [3, 3, 1]]
Explanation: These are the only possible distinct permutations for the given array.
```

### Example 2

```cpp
Input: arr[] = [2, 3]
Output: [[2, 3], [3, 2]]
Explanation: These are the only possible distinct permutations for the given array.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 9$

## **✅ My Approach**

The optimal approach uses **STL's `next_permutation`** function which efficiently generates permutations in lexicographically sorted order:

### **STL Next Permutation**

1. **Sort the Array:**
   * First, sort the input array to get the smallest lexicographical permutation.
   * This ensures we start from the beginning and generate permutations in sorted order.

2. **Generate Permutations:**
   * Use `next_permutation()` function which rearranges elements into the next lexicographically greater permutation.
   * It returns `true` if a next permutation exists, `false` otherwise.

3. **Store Results:**
   * Add each permutation to the result vector.
   * Continue until `next_permutation()` returns `false`.

4. **Automatic Duplicate Handling:**
   * `next_permutation()` inherently skips duplicate permutations when the array is sorted.
   * This is because it always generates the next unique lexicographical arrangement.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n! × n), where n is the size of the array. We generate n! permutations, and each permutation takes O(n) time to copy into the result.
* **Expected Auxiliary Space Complexity:** O(1), excluding the space used to store the output. We only use a constant amount of additional space for the algorithm itself, as `next_permutation` works in-place.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        do {
            res.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Backtracking with Visited Array**

### 💡 Algorithm Steps:

1. Sort the input array to group duplicate elements together.
2. Use a boolean visited array to track which elements are currently in the permutation.
3. For each position, try adding unused elements while skipping duplicates.
4. Skip an element if its previous duplicate hasn't been used yet to avoid duplicate permutations.

```cpp
class Solution {
public:
    void solve(vector<int>& arr, vector<bool>& vis, vector<int>& temp, vector<vector<int>>& res) {
        if (temp.size() == arr.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (vis[i] || (i > 0 && arr[i] == arr[i-1] && !vis[i-1])) continue;
            vis[i] = true;
            temp.push_back(arr[i]);
            solve(arr, vis, temp, res);
            temp.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> vis(arr.size(), false);
        solve(arr, vis, temp, res);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n! × n) - Generate all permutations and copy each
* **Auxiliary Space:** 💾 O(n) - Recursion stack and temporary arrays

### ✅ **Why This Approach?**

* Educational value for understanding backtracking patterns
* Fine-grained control over permutation generation
* Natural duplicate handling through sorted order

## 📊 **3️⃣ Set-Based Deduplication**

### 💡 Algorithm Steps:

1. Generate all permutations without considering duplicates initially.
2. Use a set to automatically filter out duplicate permutations.
3. Convert the set back to a vector for the final result.
4. Sorting at each level ensures consistent ordering for set comparison.

```cpp
class Solution {
public:
    void solve(vector<int>& arr, int idx, set<vector<int>>& res) {
        if (idx == arr.size()) {
            res.insert(arr);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            swap(arr[idx], arr[i]);
            solve(arr, idx + 1, res);
            swap(arr[idx], arr[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        set<vector<int>> st;
        solve(arr, 0, st);
        return vector<vector<int>>(st.begin(), st.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n! × n log n) - Set operations add logarithmic factor
* **Auxiliary Space:** 💾 O(n!) - Set stores all unique permutations

### ✅ **Why This Approach?**

* Simpler logic without manual duplicate checking
* Automatic deduplication through set properties
* Works well when duplicates are rare

## 📊 **4️⃣ Swap-Based with Duplicate Check**

### 💡 Algorithm Steps:

1. At each recursion level, maintain a set of already used elements.
2. Swap elements to generate permutations in place.
3. Use local set to prevent swapping the same value multiple times at current position.
4. Backtrack by swapping elements back to restore original state.

```cpp
class Solution {
public:
    void solve(vector<int>& arr, int idx, vector<vector<int>>& res) {
        if (idx == arr.size()) {
            res.push_back(arr);
            return;
        }
        unordered_set<int> used;
        for (int i = idx; i < arr.size(); i++) {
            if (used.count(arr[i])) continue;
            used.insert(arr[i]);
            swap(arr[idx], arr[i]);
            solve(arr, idx + 1, res);
            swap(arr[idx], arr[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> res;
        solve(arr, 0, res);
        sort(res.begin(), res.end());
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n! × n) - Efficient duplicate pruning at each level
* **Auxiliary Space:** 💾 O(n) - Local sets and recursion stack

### ✅ **Why This Approach?**

* In-place swapping reduces space overhead
* Level-wise duplicate detection is efficient
* Good balance between time and space

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **STL next_permutation**       | 🟢 O(n! × n)           | 🟢 O(1)                 | 🚀 Shortest code, built-in        | 🔧 Modifies input, less educational   |
| 🔍 **Backtracking + Visited**     | 🟢 O(n! × n)           | 🟡 O(n)                 | 📖 Clear logic, educational       | 💾 Extra visited array needed         |
| 📊 **Set-Based**                  | 🟡 O(n! × n log n)     | 🔴 O(n!)                | 🎯 Simple deduplication           | 🐌 Slower, high space usage           |
| 🔄 **Swap + Local Set**           | 🟢 O(n! × n)           | 🟢 O(n)                 | ⭐ Space efficient                | 🔧 Needs final sorting                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production/Competition**                     | 🥇 **STL next_permutation**          | ★★★★★                     |
| 📖 **Learning/Interview**                         | 🥈 **Backtracking + Visited**        | ★★★★★                     |
| 🔧 **Few duplicates**                             | 🥉 **Set-Based**                     | ★★★☆☆                     |
| 🎯 **Space constraints**                          | 🏅 **Swap + Local Set**              | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static ArrayList<ArrayList<Integer>> uniquePerms(int[] arr) {
        Arrays.sort(arr);
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        do {
            ArrayList<Integer> perm = new ArrayList<>();
            for (int num : arr) perm.add(num);
            res.add(perm);
        } while (nextPermutation(arr));
        return res;
    }
    private static boolean nextPermutation(int[] nums) {
        int n = nums.length;
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i < 0) return false;
        int j = n - 1;
        while (nums[j] <= nums[i]) j--;
        swap(nums, i, j);
        reverse(nums, i + 1, n - 1);
        return true;
    }
    private static void swap(int[] nums, int i, int j) {
        int t = nums[i]; nums[i] = nums[j]; nums[j] = t;
    }
    private static void reverse(int[] nums, int i, int j) {
        while (i < j) swap(nums, i++, j--);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def uniquePerms(self, arr):
        arr.sort()
        res = []
        def next_permutation(nums):
            n = len(nums)
            i = n - 2
            while i >= 0 and nums[i] >= nums[i + 1]:
                i -= 1
            if i < 0:
                return False
            j = n - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
            nums[i + 1:] = reversed(nums[i + 1:])
            return True
        res.append(arr[:])
        while next_permutation(arr):
            res.append(arr[:])
        return res
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
