# _22. Stickler Thief II_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/house-robber-ii/1)

## **Problem Description**

You are given an array `arr[]` representing houses arranged in a **circular** fashion. Each house contains a certain value, and a thief aims to **maximize** the stolen amount while ensuring that **no two adjacent houses are robbed**.

Since the houses form a **circle**, the first and last house are also considered adjacent.

### **Examples**

### **Example 1:**

#### **Input:**

```
arr[] = [2, 3, 2]
```

#### **Output:**

```
3
```

#### **Explanation:**

The houses at index **0 and 2** are adjacent, so they **cannot** be robbed together. The maximum amount that can be stolen is **3** (robbing the house at index `1`).

### **Example 2:**

#### **Input:**

```
arr[] = [1, 2, 3, 1]
```

#### **Output:**

```
4
```

#### **Explanation:**

The optimal strategy is to rob houses at index **0 and 2**, which gives **1 + 3 = 4**.

### **Example 3:**

#### **Input:**

```
arr[] = [2, 2, 3, 1, 2]
```

#### **Output:**

```
5
```

#### **Explanation:**

Possible choices:

1. **Rob house at index 0 and 2** → `2 + 3 = 5`
2. **Rob house at index 2 and 4** → `3 + 2 = 5`  
   The maximum amount that can be stolen is **5**.

### **Constraints:**

- $\(2 \leq \text{arr.size()} \leq 10^5\)$
- $\(0 \leq \text{arr}[i] \leq 10^4\)$

## **My Approach**

### **Optimized Dynamic Programming**

1. Since the houses are arranged **in a circle**, the **first and last houses cannot be robbed together**.
2. The problem reduces to **two linear House Robber problems**:
   - Robbing **from house 0 to n-2** (excluding the last house).
   - Robbing **from house 1 to n-1** (excluding the first house).
3. We solve the **House Robber problem** for both cases using **Dynamic Programming** with space optimization.
4. The final answer is the **maximum of both cases**.

### **Algorithm Steps:**

1. **Define a helper function** `robRange(l, r)`:
   - Use **two variables (prev1, prev2)** to track maximum money stolen up to the previous two houses.
   - Iterate through the houses from `l` to `r`, updating the maximum amount stolen.
   - Return `prev1` (max stolen amount).
2. **Compute the result** by taking the maximum of:
   - `robRange(0, n-2)` (excluding last house).
   - `robRange(1, n-1)` (excluding first house).
3. **Edge case:** If there's only **one house**, return its value.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), since we iterate through the houses twice.
- **Expected Auxiliary Space Complexity:** O(1), since we use only a few variables (constant space).

## **Code (C++)**

```cpp
class Solution {
public:
    int maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        auto robRange = [&](int l, int r) {
            int prev2 = 0, prev1 = 0;
            for (int i = l; i <= r; i++) {
                int curr = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1;
        };

        return max(robRange(0, n - 2), robRange(1, n - 1));
    }
};
```

<details>
  <summary><h2 align="center">🛠 Alternative Solutions</h2></summary>

## **2️⃣ Dynamic Programming with Array (O(N) Time, O(N) Space)**

### **Approach:**

Instead of using **two variables**, maintain a **DP array** where `dp[i]` stores the **maximum amount** that can be stolen up to house `i`.

### **Code (C++)**

```cpp
class Solution {
public:
    int maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        auto robRange = [&](int l, int r) {
            vector<int> dp(r - l + 2, 0);
            dp[1] = nums[l];
            for (int i = l + 1; i <= r; i++) {
                dp[i - l + 1] = max(dp[i - l], dp[i - l - 1] + nums[i]);
            }
            return dp[r - l + 1];
        };

        return max(robRange(0, n - 2), robRange(1, n - 1));
    }
};
```

## **3️⃣ Memoization (Top-Down DP)**

### **Approach:**

Instead of using **iterative DP**, we use **recursion with memoization**:

1. Define a recursive function `robRange(l, r, dp)`.
2. Use memoization (`dp[i]`) to avoid recomputation.
3. Solve for both cases:
   - Excluding the last house (`robRange(0, n-2)`).
   - Excluding the first house (`robRange(1, n-1)`).
4. Return the **maximum** of both cases.

### **Code (C++)**

```cpp
class Solution {
public:
    int robRange(vector<int>& nums, int i, int r, vector<int>& dp) {
        if (i > r) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(robRange(nums, i + 1, r, dp), nums[i] + robRange(nums, i + 2, r, dp));
    }

    int maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);
        return max(robRange(nums, 0, n - 2, dp1), robRange(nums, 1, n - 1, dp2));
    }
};
```

## **Comparison of Approaches**

| **Approach**                     | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**               | ⚠️ **Cons**                   |
| -------------------------------- | ---------------------- | ----------------------- | ------------------------- | ----------------------------- |
| **Optimized DP (Two Variables)** | 🟡 **O(N)**            | 🟢 **O(1)**             | Space efficient, faster   | Slightly harder to understand |
| **DP with Array**                | 🟡 **O(N)**            | 🟡 **O(N)**             | Easier to implement       | Extra space for DP array      |
| **Memoization (Top-Down DP)**    | 🟡 **O(N)**            | 🔴 **O(N)**             | Good for recursion lovers | Higher memory consumption     |

## **💡 Best Choice?**

- ✅ **Optimized DP (O(1) Space)** is the best solution due to minimal space usage.
- ✅ **DP with Array** is useful for **educational purposes**, but not efficient for large inputs.
- ✅ **Memoization?** Useful for recursion-based approaches.

</details>

## **Code (Java)**

```java
class Solution {
    public int maxValue(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];

        return Math.max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }

    private int rob(int[] nums, int l, int r) {
        int prev2 = 0, prev1 = 0;
        for (int i = l; i <= r; i++) {
            int curr = Math.max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def maxValue(self, nums):
        if len(nums) == 1:
            return nums[0]

        def rob(l, r):
            prev2 = prev1 = 0
            for i in range(l, r + 1):
                prev2, prev1 = prev1, max(prev1, prev2 + nums[i])
            return prev1

        return max(rob(0, len(nums) - 2), rob(1, len(nums) - 1))
```

## **Contributions and Support**

For discussions, questions, or doubts related to this solution, feel free to connect on **LinkedIn**: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a **star**! ⭐

---

<div align="center">
  <h3><b>📍 Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
