---
title: "🔍 Find the Closest Pair from Two Arrays | GFG Solution 🎯"
keywords🏷️: ["🔍 closest pair", "📊 two pointers", "📈 sorted arrays", "🔢 binary search", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Find the Closest Pair from Two Arrays: find pair with sum closest to target using efficient two-pointer technique. 🚀"
date: 📅 2025-02-28
---

# *28. Find the Closest Pair from Two Arrays*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1)

## **🧩 Problem Description**

Given two sorted arrays `arr1[]` and `arr2[]` of size n and m and a number `x`, find the pair whose sum is **closest to x** and the pair has an element from each array. In the case of multiple closest pairs, return any one of them.

**Note:** In the driver code, the absolute difference between the sum of the closest pair and x is printed.

## **📘 Examples**

### Example 1

```cpp
Input: arr1[] = [1, 4, 5, 7], arr2[] = [10, 20, 30, 40], x = 32
Output: [1, 30]
Explanation: The closest pair whose sum is closest to 32 is [1, 30] = 31.
```

### Example 2

```cpp
Input: arr1[] = [1, 4, 5, 7], arr2[] = [10, 20, 30, 40], x = 50
Output: [7, 40]
Explanation: The closest pair whose sum is closest to 50 is [7, 40] = 47.
```

### Example 3

```cpp
Input: arr1[] = [1, 2, 3], arr2[] = [4, 5, 6], x = 9
Output: [3, 6]
Explanation: The sum 3 + 6 = 9 is exactly equal to x.
```

## **🔒 Constraints**

* $1 \le \text{arr1.size()}, \text{arr2.size()} \le 10^5$
* $1 \le \text{arr1}[i], \text{arr2}[i] \le 10^9$
* $1 \le x \le 10^9$

## **✅ My Approach**

The optimal solution uses **Two-Pointer Technique**:

### **Two-Pointer Strategy**

1. **Key Insight:**
   * Since both arrays are sorted, we can use two pointers efficiently.
   * Start with smallest element from arr1 and largest from arr2.
   * Move pointers to bring sum closer to target x.

2. **Pointer Movement Logic:**
   * If `sum > x`: decrease sum by moving right pointer left (arr2).
   * If `sum < x`: increase sum by moving left pointer right (arr1).
   * If `sum == x`: we found exact match, but continue to check all pairs.

3. **Tracking Best Pair:**
   * Maintain minimum difference seen so far.
   * Update result whenever we find a pair with smaller difference.
   * Use `abs(sum - x)` to calculate difference.

4. **Algorithm Steps:**
   * Initialize left pointer at start of arr1, right at end of arr2.
   * While both pointers are valid:
     - Calculate current sum and difference from x.
     - Update result if this is closer than previous best.
     - Move pointers based on comparison with x.
   * Return the closest pair found.

**Why This Works:** The two-pointer approach explores all potentially optimal pairs by systematically moving through both arrays based on whether we need to increase or decrease the sum.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + m), where n and m are the sizes of the two arrays. We traverse each array at most once, with each element being visited by at most one pointer movement.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for variables like pointers, difference tracking, and result storage.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int i = 0, j = arr2.size() - 1, minDiff = INT_MAX;
        vector<int> res(2);
        while (i < arr1.size() && j >= 0) {
            int sum = arr1[i] + arr2[j], diff = abs(sum - x);
            if (diff < minDiff) minDiff = diff, res = {arr1[i], arr2[j]};
            (sum < x) ? i++ : j--;
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. Try all possible pairs from both arrays.
2. For each pair, calculate sum and difference from x.
3. Track the pair with minimum difference.
4. Return the closest pair found.

```cpp
class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int minDiff = INT_MAX;
        vector<int> res(2);
        for (int i = 0; i < arr1.size(); i++) {
            for (int j = 0; j < arr2.size(); j++) {
                int sum = arr1[i] + arr2[j];
                int diff = abs(sum - x);
                if (diff < minDiff) {
                    minDiff = diff;
                    res[0] = arr1[i];
                    res[1] = arr2[j];
                }
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m) - Two nested loops
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Simple and straightforward
* No need to utilize sorted property
* Good for small arrays

  
> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1120 test cases due to time constraints).


## 📊 **3️⃣ Binary Search Approach**

### 💡 Algorithm Steps:

1. For each element in arr1, use binary search to find closest element in arr2.
2. The target for binary search is (x - arr1[i]).
3. Check both floor and ceiling values from binary search.
4. Track the pair with minimum difference globally.

```cpp
class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int minDiff = INT_MAX;
        vector<int> res(2);
        for (int i = 0; i < arr1.size(); i++) {
            int target = x - arr1[i];
            auto it = lower_bound(arr2.begin(), arr2.end(), target);
            
            if (it != arr2.end()) {
                int diff = abs(arr1[i] + *it - x);
                if (diff < minDiff) {
                    minDiff = diff;
                    res = {arr1[i], *it};
                }
            }
            
            if (it != arr2.begin()) {
                --it;
                int diff = abs(arr1[i] + *it - x);
                if (diff < minDiff) {
                    minDiff = diff;
                    res = {arr1[i], *it};
                }
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log m) - n iterations with binary search
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Utilizes sorted property of arr2
* Better than brute force when n << m
* Good balance of simplicity and efficiency

## 📊 **4️⃣ Optimized Two-Pointer with Early Exit**

### 💡 Algorithm Steps:

1. Use two-pointer technique as main approach.
2. Add early exit when exact match found (difference = 0).
3. Track both pointers from optimal starting positions.
4. Return immediately when perfect pair found.

```cpp
class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int l = 0, r = arr2.size() - 1, diff = INT_MAX;
        vector<int> result(2);
        
        while (l < arr1.size() && r >= 0) {
            int sum = arr1[l] + arr2[r];
            int currDiff = abs(sum - x);
            
            if (currDiff < diff) {
                diff = currDiff;
                result[0] = arr1[l];
                result[1] = arr2[r];
                if (diff == 0) return result;
            }
            
            if (sum > x) r--;
            else l++;
        }
        
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + m) - Linear with early exit
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Optimized with early exit for exact matches
* Best average case performance
* Maintains optimal worst case

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Two-Pointer**                | 🟢 O(n + m)            | 🟢 O(1)                 | 🚀 Optimal linear time            | 🔧 Requires sorted arrays            |
| 🔄 **Brute Force**                | 🔴 O(n × m)            | 🟢 O(1)                 | 📖 Simple implementation          | 🐌 Quadratic time complexity         |
| 🔍 **Binary Search**              | 🟡 O(n log m)          | 🟢 O(1)                 | 🎯 Better than brute force        | 🔧 Logarithmic factor overhead       |
| ⚡ **Two-Pointer + Early Exit**   | 🟢 O(n + m)            | 🟢 O(1)                 | ⭐ Best average case              | 🔧 Similar to main approach          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Two-Pointer**                   | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥈 **Brute Force**                   | ★★★☆☆                     |
| 🎯 **Unbalanced array sizes**                         | 🥉 **Binary Search**                 | ★★★★☆                     |
| ⚡ **Many exact matches expected**                    | 🏅 **Two-Pointer + Early Exit**      | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static ArrayList<Integer> findClosestPair(int arr1[], int arr2[], int x) {
        int i = 0, j = arr2.length - 1, minDiff = Integer.MAX_VALUE;
        ArrayList<Integer> res = new ArrayList<>();
        while (i < arr1.length && j >= 0) {
            int sum = arr1[i] + arr2[j], diff = Math.abs(sum - x);
            if (diff < minDiff) {
                minDiff = diff;
                res = new ArrayList<>(Arrays.asList(arr1[i], arr2[j]));
            }
            if (sum < x) i++;
            else j--;
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findClosestPair(self, arr1, arr2, x):
        i, j, min_diff = 0, len(arr2) - 1, float('inf')
        res = []
        while i < len(arr1) and j >= 0:
            s, diff = arr1[i] + arr2[j], abs(arr1[i] + arr2[j] - x)
            if diff < min_diff:
                min_diff, res = diff, [arr1[i], arr2[j]]
            i, j = (i + 1, j) if s < x else (i, j - 1)
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
