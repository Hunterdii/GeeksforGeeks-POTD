---
title: "🔢 Generate Permutations of an Array | GFG Solution 🔍"
keywords: ["🔢 permutations", "🔍 backtracking", "📍 recursion", "📈 STL algorithms", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Generate Permutations problem: find all possible permutations of array elements using backtracking and STL algorithms. 🚀"
date: 📅 2025-01-26
---

# *26. Generate Permutations of an Array*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/generate-permutations-of-an-array/1)

## **🧩 Problem Description**

You are given an array `arr[]` of unique elements. Your task is to generate all possible permutations of the elements in the array.

A permutation is an arrangement of all elements where order matters. For an array of n elements, there are n! (n factorial) possible permutations.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3]
Output: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
Explanation: There are 6 possible permutations (3! = 6) of the array.
```

### Example 2

```cpp
Input: arr[] = [1, 3]
Output: [[1, 3], [3, 1]]
Explanation: There are 2 possible permutations (2! = 2) of the array.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 9$

## **✅ My Approach**

The optimal approach uses **STL's next_permutation** function which generates permutations in lexicographic order:

### **STL next_permutation Approach**

1. **Sort the Array:**
   * First sort the array to get the lexicographically smallest permutation.
   * This ensures we start from the beginning and generate all permutations systematically.

2. **Generate Permutations:**
   * Use `next_permutation()` which rearranges elements to the next lexicographically greater permutation.
   * Store each permutation in the result vector.

3. **Continue Until All Generated:**
   * The `next_permutation()` function returns false when no more permutations exist (when array is in descending order).
   * This automatically handles generation of all n! permutations.

4. **Return Result:**
   * Return the collected permutations.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n! × n), as we generate n! permutations and each permutation requires O(n) time to copy into the result. The `next_permutation()` function itself operates in O(n) time per call.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for the algorithm (excluding the output storage). The sorting and permutation generation happen in-place.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        do {
            res.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Backtracking with Swap Approach**

### 💡 Algorithm Steps:

1. Use recursion with index-based swapping to generate permutations.
2. At each recursion level, swap current element with all elements from current index to end.
3. Recursively generate permutations for remaining elements.
4. Backtrack by swapping elements back to restore original state.

```cpp
class Solution {
public:
    void solve(vector<int>& arr, int idx, vector<vector<int>>& res) {
        if (idx == arr.size()) {
            res.push_back(arr);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            swap(arr[idx], arr[i]);
            solve(arr, idx + 1, res);
            swap(arr[idx], arr[i]);
        }
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        solve(arr, 0, res);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n! × n) - Generating all permutations and copying each
* **Auxiliary Space:** 💾 O(n) - Recursion stack depth

### ✅ **Why This Approach?**

* Classic backtracking pattern for permutations
* In-place swapping reduces space overhead
* Easy to understand recursion flow

## 📊 **3️⃣ Iterative Heap's Algorithm**

### 💡 Algorithm Steps:

1. Use Heap's algorithm to generate permutations iteratively without recursion.
2. Maintain a counter array to track swap positions at each level.
3. Generate permutations by systematic swapping based on counter values.
4. Continue until all permutations are generated.

```cpp
class Solution {
public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();
        vector<int> c(n, 0);
        res.push_back(arr);
        int i = 0;
        while (i < n) {
            if (c[i] < i) {
                if (i % 2 == 0) swap(arr[0], arr[i]);
                else swap(arr[c[i]], arr[i]);
                res.push_back(arr);
                c[i]++;
                i = 0;
            } else {
                c[i] = 0;
                i++;
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n! × n) - All permutations with copying
* **Auxiliary Space:** 💾 O(n) - Counter array only

### ✅ **Why This Approach?**

* No recursion overhead, purely iterative
* Efficient systematic generation pattern
* Optimal for memory-constrained environments

## 📊 **4️⃣ Manual next_permutation Implementation**

### 💡 Algorithm Steps:

1. Sort array to start from lexicographically smallest permutation.
2. Find rightmost ascending pair from end of array.
3. Swap pivot with smallest element greater than it from right.
4. Reverse suffix after pivot position to get next permutation.

```cpp
class Solution {
public:
    bool nextPerm(vector<int>& arr) {
        int i = arr.size() - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) i--;
        if (i < 0) return false;
        int j = arr.size() - 1;
        while (arr[j] <= arr[i]) j--;
        swap(arr[i], arr[j]);
        reverse(arr.begin() + i + 1, arr.end());
        return true;
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        res.push_back(arr);
        while (nextPerm(arr)) res.push_back(arr);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n! × n) - Each permutation generation is O(n)
* **Auxiliary Space:** 💾 O(1) - In-place modifications

### ✅ **Why This Approach?**

* Generates permutations in lexicographic order
* Educational value in understanding algorithm internals
* No recursion stack overhead

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **STL next_permutation**       | 🟢 O(n! × n)           | 🟢 O(1)                 | 🚀 Clean and concise              | 🔧 Requires sorting first            |
| 🔍 **Backtracking Swap**          | 🟢 O(n! × n)           | 🟡 O(n)                 | 📖 Intuitive recursion            | 💾 Recursion stack space             |
| 📊 **Heap's Algorithm**           | 🟢 O(n! × n)           | 🟢 O(n)                 | 🎯 No recursion overhead          | 🐌 Complex iteration logic           |
| 🔄 **Manual next_permutation**    | 🟢 O(n! × n)           | 🟢 O(1)                 | ⭐ Lexicographic order            | 🔧 Longer implementation             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production code simplicity**                     | 🥇 **STL next_permutation**          | ★★★★★                     |
| 📖 **Learning/Interview context**                     | 🥈 **Backtracking Swap**             | ★★★★☆                     |
| 🔧 **Avoiding recursion**                             | 🥉 **Heap's Algorithm**              | ★★★★☆                     |
| 🎯 **Lexicographic order required**                   | 🏅 **Manual next_permutation**       | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static ArrayList<ArrayList<Integer>> permuteDist(int[] arr) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        Arrays.sort(arr);
        res.add(toList(arr));
        while (nextPerm(arr)) res.add(toList(arr));
        return res;
    }
    static boolean nextPerm(int[] arr) {
        int i = arr.length - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) i--;
        if (i < 0) return false;
        int j = arr.length - 1;
        while (arr[j] <= arr[i]) j--;
        swap(arr, i, j);
        reverse(arr, i + 1);
        return true;
    }
    static void swap(int[] arr, int i, int j) {
        int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
    }
    static void reverse(int[] arr, int start) {
        int i = start, j = arr.length - 1;
        while (i < j) swap(arr, i++, j--);
    }
    static ArrayList<Integer> toList(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int x : arr) list.add(x);
        return list;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def permuteDist(self, arr):
        from itertools import permutations
        return [list(p) for p in permutations(arr)]
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
