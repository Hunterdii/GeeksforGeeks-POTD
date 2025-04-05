---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Dynamic Programming
  - Subset
---

# 🚀 _Day 15. Partition Equal Subset Sum_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/subset-sum-problem2014)

## 💡 **Problem Description:**

Given an array `arr[]`, determine if it can be **partitioned into two subsets** such that the sum of elements in both parts is the same.

Each element must be in exactly **one subset**.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```
arr = [1, 5, 11, 5]
```

#### **Output:**

```
True
```

#### **Explanation:**

The array can be partitioned into **[1, 5, 5]** and **[11]**, both having the sum **11**.

### **Example 2:**

#### **Input:**

```
arr = [1, 3, 5]
```

#### **Output:**

```
False
```

#### **Explanation:**

There is no way to split the array into two subsets with equal sum.

## **Constraints:**

- $\(1 \leq arr.size \leq 100\)$
- $\(1 \leq arr[i] \leq 200\)$

## 🎯 **My Approach:**

## **Optimized 1D Dynamic Programming**

### **Algorithm Steps:**

1. **Calculate the total sum** of the array. If it's **odd**, return false (cannot be evenly split).
2. **Use a DP table (`dp[j]`)**, where `dp[j]` tells if we can form sum `j`.
3. **Initialize** `dp[0] = true`, since a sum of **0** is always possible.
4. **Iterate through each element** in the array:
   - Update `dp[j] = dp[j] OR dp[j - num]` for `j = target` down to `num`.
5. If `dp[target]` is **true**, we can partition the array into two subsets with equal sum.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** $O(N \times sum)$, as we iterate over the elements and process sums up to `sum/2`.
- **Expected Auxiliary Space Complexity:** $O(sum)$, as we use a 1D DP array of size `sum/2 + 1`.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : arr)
            for (int j = target; j >= num; --j)
                dp[j] = dp[j] || dp[j - num];
        return dp[target];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming (O(N×sum) Time, O(N×sum) Space) — 2D DP**

### **Algorithm Steps:**

1. Use a **2D DP table**, where `dp[i][j]` represents whether a subset with sum `j` can be formed using the first `i` elements.
2. **Base Case:**
   - `dp[0][0] = true` (sum 0 can be formed with zero elements).
   - `dp[i][0] = true` for all `i` (sum 0 is always achievable).
3. **Recurrence Relation:**  
   $\[
   dp[i][j] = dp[i-1][j] \quad \text{(exclude element)}
   $\]
   If `arr[i-1] ≤ j`, then:
   $\[
   dp[i][j] = dp[i-1][j] \text{ OR } dp[i-1][j - arr[i-1]]
   $\]
   (include element if possible).

```cpp
class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= arr[i-1]) dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
            }
        }
        return dp[n][target];
    }
};
```

✅ **Time Complexity:** `O(N × sum)`  
✅ **Space Complexity:** `O(N × sum)`

## **3️⃣ Recursive + Memoization (O(N×sum) Time, O(N×sum) Space)**

### **Algorithm Steps:**

1. Define a **recursive function** `canPartition(i, target)` that checks if a subset of `arr[0...i]` sums up to `target`.
2. **Base Cases:**
   - If `target == 0`, return `true`.
   - If `i < 0` or `target < 0`, return `false`.
3. **Recurrence Relation:**
   - Exclude `arr[i]`: `canPartition(i - 1, target)`.
   - Include `arr[i]` if `arr[i] ≤ target`: `canPartition(i - 1, target - arr[i])`.
4. **Use Memoization (`dp[i][target]`)** to avoid redundant calculations.

```cpp
class Solution {
  public:
    vector<vector<int>> dp;
    bool solve(vector<int>& arr, int i, int target) {
        if (target == 0) return true;
        if (i < 0 || target < 0) return false;
        if (dp[i][target] != -1) return dp[i][target];
        return dp[i][target] = solve(arr, i - 1, target) || solve(arr, i - 1, target - arr[i]);
    }

    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2, n = arr.size();
        dp.assign(n, vector<int>(target + 1, -1));
        return solve(arr, n - 1, target);
    }
};
```

✅ **Time Complexity:** `O(N × sum)`  
✅ **Space Complexity:** `O(N × sum) (recursion stack)`

## **Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                   | ⚠️ **Cons**               |
| --------------------------- | ---------------------- | ----------------------- | ----------------------------- | ------------------------- |
| **1D DP (Space Optimized)** | 🟡 `O(N × sum)`        | 🟢 `O(sum/2)`           | Best space-efficient solution | Requires careful indexing |
| **2D DP (Tabulation)**      | 🟡 `O(N × sum)`        | 🔴 `O(N × sum)`         | Intuitive approach            | High space usage          |
| **Recursive + Memoization** | 🟡 `O(N × sum)`        | 🔴 `O(N × sum)`         | Natural recursion flow        | Stack overhead            |

✅ **Best Choice?**

- **If optimizing space:** Use **1D DP (Space-Optimized)**.
- **If space is not a concern:** Use **2D DP (Tabulation)** for easier understanding.
- **For recursion lovers:** Use **Recursive + Memoization**.

</details>

## **Code (Java)**

```java
class Solution {
    static boolean equalPartition(int[] arr) {
        int sum = Arrays.stream(arr).sum();
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        boolean[] dp = new boolean[target + 1];
        dp[0] = true;
        for (int num : arr)
            for (int j = target; j >= num; --j)
                dp[j] |= dp[j - num];
        return dp[target];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def equalPartition(self, arr):
        s = sum(arr)
        if s % 2: return False
        target, dp = s // 2, [False] * (s // 2 + 1)
        dp[0] = True
        for num in arr:
            for j in range(target, num - 1, -1):
                dp[j] |= dp[j - num]
        return dp[target]
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
