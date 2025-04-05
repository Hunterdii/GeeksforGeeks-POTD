# _21. Stickler Thief_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1)

## **Problem Description**

Stickler the thief wants to loot money from houses arranged in a line. However, he **cannot loot two consecutive houses** to avoid being caught. His goal is to **maximize** the total amount looted.

Given an array **arr[]**, where `arr[i]` represents the amount of money in the `i`-th house, determine the **maximum amount** he can loot.

## **Examples**

### **Example 1:**

#### **Input:**

```cpp
arr[] = [6, 5, 5, 7, 4]
```

#### **Output:**

```cpp
15
```

#### **Explanation:**

Maximum loot can be obtained by robbing the **1st, 3rd, and 5th houses**:  
**6 + 5 + 4 = 15**

### **Example 2:**

#### **Input:**

```cpp
arr[] = [1, 5, 3]
```

#### **Output:**

```cpp
5
```

#### **Explanation:**

Best choice is to **loot only the 2nd house**, obtaining **5**.

### **Example 3:**

#### **Input:**

```cpp
arr[] = [4, 4, 4, 4]
```

#### **Output:**

```cpp
8
```

#### **Explanation:**

Stickler can loot **either** the **1st & 3rd houses** or **2nd & 4th houses** for a total of **4 + 4 = 8**.

### **Constraints:**

- $1 \leq \text{arr.size()} \leq 10^5$
- $1 \leq \text{arr}[i] \leq 10^4$

## **My Approach:**

## **Optimized Dynamic Programming**

### **Algorithm Steps:**

1. Maintain **two variables**:
   - `prev2` → Stores the **loot obtained up to the house before the previous one**.
   - `prev1` → Stores the **loot obtained up to the previous house**.
2. Iterate through the array:
   - For each house `arr[i]`, decide whether to **loot it** or **skip it**.
   - If looted, the total becomes `prev2 + arr[i]`.
   - If skipped, the total remains `prev1`.
   - Update `prev2` and `prev1` accordingly.
3. Return `prev1` as the final answer.

### **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** **O(N)**, since we iterate over the array once.
- **Expected Auxiliary Space Complexity:** **O(1)**, as we use only a few variables.

## **Code (C++)**

```cpp
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int prev2 = 0, prev1 = 0;
        for (int num : arr) {
            int temp = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming - O(N) Time, O(N) Space (DP Array)**

### **Algorithm Steps:**

1. **Use a DP array `dp[i]`**, where `dp[i]` represents the **maximum sum possible** considering elements up to index `i`.
2. **Base Cases**:
   - `dp[0] = arr[0]` → The only available option is to loot the first house.
   - `dp[1] = max(arr[0], arr[1])` → Choose the maximum of the first two houses.
3. **Recurrence Relation:**
   ```cpp
   dp[i] = max(dp[i-1], arr[i] + dp[i-2])
   ```
   - Either **exclude** `arr[i]` (use `dp[i-1]`).
   - Or **include** `arr[i]` (use `arr[i] + dp[i-2]`).

```cpp
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        vector<int> dp(n, 0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], arr[i] + dp[i-2]);
        }
        return dp[n-1];
    }
};
```

## **3️⃣ Recursive + Memoization (O(N) Time, O(N) Space)**

### **Algorithm Steps:**

1. Define a **recursive function** `maxSum(index)` where `index` is the current house.
2. **Base Case:**
   - If `index < 0`, return `0` (out of bounds).
   - If `index == 0`, return `arr[0]`.
3. **Recurrence Relation:**
   ```cpp
   maxSum(index) = max(maxSum(index - 1), arr[index] + maxSum(index - 2))
   ```
   - Either **skip** the house (`maxSum(index - 1)`).
   - Or **loot** it (`arr[index] + maxSum(index - 2)`).
4. **Use memoization** to store results.

```cpp
class Solution {
  public:
    vector<int> dp;
    int solve(vector<int>& arr, int index) {
        if (index < 0) return 0;
        if (dp[index] != -1) return dp[index];
        return dp[index] = max(solve(arr, index - 1), arr[index] + solve(arr, index - 2));
    }

    int findMaxSum(vector<int>& arr) {
        dp.assign(arr.size(), -1);
        return solve(arr, arr.size() - 1);
    }
};
```

## **Comparison of Approaches**

| **Approach**                  | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**       | ⚠️ **Cons**          |
| ----------------------------- | ---------------------- | ----------------------- | ----------------- | -------------------- |
| **Optimized DP (O(1) Space)** | 🟢 **O(N)**            | 🟢 **O(1)**             | Most efficient    | None                 |
| **DP Array (O(N) Space)**     | 🟢 **O(N)**            | 🟡 **O(N)**             | Easy to implement | Uses extra space     |
| **Memoization (Recursion)**   | 🟡 **O(N)**            | 🔴 **O(N)**             | Simple recursion  | Uses recursion stack |

✅ **Best Choice?**

- **For most cases**: Use **Optimized DP (O(1) Space)**.
- **For beginners**: Use **DP Array (O(N) Space)** for clarity.
- **If recursion is required**: Use **Memoization**.

</details>

## **Code (Java)**

```java
class Solution {
    public int findMaxSum(int[] arr) {
        int prev2 = 0, prev1 = 0;
        for (int num : arr) {
            int temp = Math.max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def findMaxSum(self, arr):
        prev2 = prev1 = 0
        for num in arr:
            prev2, prev1 = prev1, max(prev1, prev2 + num)
        return prev1
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
