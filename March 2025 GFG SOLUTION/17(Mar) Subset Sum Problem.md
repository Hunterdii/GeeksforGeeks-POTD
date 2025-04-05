# **17. Subset Sum Problem**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1)

## **Problem Description**

Given an array of positive integers **arr[]** and a target value **sum**, determine if there exists a **subset** of `arr[]` whose sum is exactly equal to the given sum.

## **Examples**

### **Example 1:**

#### **Input:**

```cpp
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
```

#### **Output:**

```cpp
true
```

#### **Explanation:**

A subset `{4, 3, 2}` exists with sum = **9**.

### **Example 2:**

#### **Input:**

```cpp
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
```

#### **Output:**

```cpp
false
```

#### **Explanation:**

There is no subset with sum = **30**.

### **Example 3:**

#### **Input:**

```cpp
arr[] = {1, 2, 3}
sum = 6
```

#### **Output:**

```cpp
true
```

#### **Explanation:**

The entire array `{1, 2, 3}` forms the subset with sum = **6**.

## **Constraints:**

- $1 \leq \text{size of arr} \leq 200$
- $1 \leq arr[i] \leq 200$
- $1 \leq sum \leq 10^4$

## **My Approach**

### **Dynamic Programming (Optimized 1D DP) – O(N × sum) Time, O(sum) Space**

1. **Define a boolean DP array** `dp[sum + 1]`, where `dp[j]` tells whether sum `j` is possible.
2. **Base Case:** `dp[0] = true` (sum 0 is always achievable).
3. **Iterate through each number in the array** and update `dp[j]` for all `j` from `sum` down to `num`.
4. **Transition Formula:**  
   $\[
   \text{dp}[j] = \text{dp}[j] \ OR\ \text{dp}[j - \text{num}]
   $\]
   - If `dp[j - num]` was `true`, then `dp[j]` can also become `true` by including `num`.
5. **Return `dp[sum]` as the final answer**.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N × sum), since we iterate through all elements and update the DP table.
- **Expected Auxiliary Space Complexity:** O(sum), as we use a 1D array of size `sum + 1`.

## **Code (C++)**

```cpp
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int num : arr)
            for (int j = sum; j >= num; --j)
                dp[j] = dp[j] || dp[j - num];
        return dp[sum];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming (O(N×sum) Time, O(N×sum) Space) — 2D DP**

### **Algorithm Steps:**

1. Use a **2D DP table** where `dp[i][j]` represents whether it's possible to achieve sum `j` using the first `i` elements.
2. **Base Case:**
   - `dp[i][0] = true` for all `i` (sum `0` is always achievable).
   - `dp[0][j] = false` for `j > 0` (no elements can't form non-zero sum).
3. **Recurrence Relation:**  
   $\[
   \text{dp}[i][j] = \text{dp}[i-1][j] || \text{dp}[i-1][j - arr[i-1]]
   $\]
   - Exclude the element (`dp[i-1][j]`).
   - Include the element (`dp[i-1][j - arr[i-1]]`).

```cpp
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i - 1]) dp[i][j] |= dp[i - 1][j - arr[i - 1]];
            }
        }
        return dp[n][sum];
    }
};
```

✅ **Time Complexity:** `O(N × sum)`  
✅ **Space Complexity:** `O(N × sum)`

## **3️⃣ Recursive + Memoization (O(N×sum) Time, O(N×sum) Space)**

### **Algorithm Steps:**

1. Define a recursive function `solve(index, sum)`:
   - Base Case: If `sum == 0`, return `true`.
   - If `index < 0` or `sum < 0`, return `false`.
   - Memoize results to avoid recomputation.
2. **Recurrence Relation:**  
   $\[
   \text{solve(index, sum)} = \text{solve(index - 1, sum)} \quad \text{OR} \quad \text{solve(index - 1, sum - arr[index])}
   \]$
   - Exclude the element.
   - Include the element.
3. **Use memoization (`dp[index][sum]`)** to avoid redundant calculations.

```cpp
class Solution {
  public:
    vector<vector<int>> dp;
    bool solve(vector<int>& arr, int i, int sum) {
        if (sum == 0) return true;
        if (i < 0 || sum < 0) return false;
        if (dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = solve(arr, i - 1, sum) || solve(arr, i - 1, sum - arr[i]);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        dp.assign(n, vector<int>(sum + 1, -1));
        return solve(arr, n - 1, sum);
    }
};
```

✅ **Time Complexity:** `O(N × sum)`  
✅ **Space Complexity:** `O(N × sum)`

## **Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                  | ⚠️ **Cons**               |
| --------------------------- | ---------------------- | ----------------------- | ---------------------------- | ------------------------- |
| **1D Space Optimized DP**   | 🟡 `O(N × sum)`        | 🟢 `O(sum)`             | Most efficient space-wise    | Requires careful indexing |
| **2D DP (Tabulation)**      | 🟡 `O(N × sum)`        | 🔴 `O(N × sum)`         | Easy to implement, intuitive | High space usage          |
| **Recursive + Memoization** | 🟡 `O(N × sum)`        | 🔴 `O(N × sum)`         | Natural recursion flow       | Stack overhead            |

✅ **Best Choice?**

- **If optimizing space:** Use **1D DP (Space-Optimized)**.
- **If space is not a concern:** Use **2D DP (Tabulation)** for easy understanding.
- **For recursion lovers:** Use **Recursive + Memoization**.

</details>

## **Code (Java)**

```java
class Solution {
    static boolean isSubsetSum(int[] arr, int sum) {
        boolean[] dp = new boolean[sum + 1];
        dp[0] = true;
        for (int num : arr)
            for (int j = sum; j >= num; --j)
                dp[j] |= dp[j - num];
        return dp[sum];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def isSubsetSum(self, arr, sum):
        dp = [False] * (sum + 1)
        dp[0] = True
        for num in arr:
            for j in range(sum, num - 1, -1):
                dp[j] |= dp[j - num]
        return dp[sum]
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
