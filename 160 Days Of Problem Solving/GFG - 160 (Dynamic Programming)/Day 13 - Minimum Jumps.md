---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Dynamic Programming
  - Greedy
  - Arrays
---

# 🚀 _Day 13. Minimum Jumps_ 🧠

The problem can be found at the following link: [Question Link](http://geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/minimum-number-of-jumps-1587115620)

## 💡 **Problem Description:**

Given an array `arr[]` of non-negative integers, each element represents the **maximum number of steps** that can be taken forward from that index.

Find the **minimum number of jumps** required to reach the last index.  
If the last index is not reachable, return `-1`.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```
arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
```

#### **Output:**

```
3
```

#### **Explanation:**

- Jump from `arr[0] = 1` → `arr[1] = 3`.
- Jump from `arr[1] = 3` → `arr[4] = 9`.
- Jump from `arr[4] = 9` → last index.

### **Example 2:**

#### **Input:**

```
arr = [1, 4, 3, 2, 6, 7]
```

#### **Output:**

```
2
```

#### **Explanation:**

- Jump from `arr[0] = 1` → `arr[1] = 4`.
- Jump from `arr[1] = 4` → last index.

### **Example 3:**

#### **Input:**

```
arr = [0, 10, 20]
```

#### **Output:**

```
-1
```

#### **Explanation:**

Since `arr[0] = 0`, we cannot move forward.

### **Constraints:**

- $2 \leq \text{arr.size()} \leq 10^4$
- $0 \leq \text{arr[i]} \leq 10^4$

## 🎯 **My Approach:**

### **Greedy Approach**

1. **Track the farthest position** reachable at every step.
2. **Use a variable `end`** to mark the last index reachable within the current jump.
3. **If `i` reaches `end`**, make a jump and update `end`.
4. **If at any point `i == end` and `end < n-1`**, return `-1`.

### **Algorithm Steps:**

1. **Initialize three variables:**
   - `jumps = 0` → Tracks the number of jumps.
   - `farthest = 0` → Tracks the farthest reachable index.
   - `end = 0` → Marks the end of the current jump.
2. **Iterate through the array (except the last element):**
   - Update `farthest = max(farthest, i + arr[i])`.
   - If `i == end`:
     - Increase `jumps`.
     - Update `end = farthest`.
     - If `end >= n-1`, return `jumps`.
3. **If the last index is never reached, return `-1`.**

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N)`, as we iterate through the array only once.
- **Expected Auxiliary Space Complexity:** `O(1)`, as we use only a few variables for tracking jumps and indices.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), jumps = 0, farthest = 0, end = 0;
        if (n == 1) return 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]);
            if (i == end) {
                jumps++;
                end = farthest;
                if (end >= n - 1) return jumps;
            }
        }
        return -1;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming (O(N²) Time, O(N) Space) — DP Approach**

### **Algorithm Steps:**

1. Use a **1D DP array** `dp[i]`, where `dp[i]` stores the **minimum jumps** needed to reach index `i`.
2. **Base Case:**
   - `dp[0] = 0` (0 jumps needed at the start).
   - Initialize `dp[i] = INT_MAX` for all `i > 0`.
3. **Transition:**
   - For every `j < i`, check if `j` can reach `i` (`j + arr[j] ≥ i`).
   - If yes, update `dp[i] = min(dp[i], dp[j] + 1)`.
4. **Return `dp[n-1]`, or `-1` if `dp[n-1]` is `INT_MAX` (unreachable).**

```cpp
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (j + arr[j] >= i && dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
        return dp[n-1] == INT_MAX ? -1 : dp[n-1];
    }
};
```

✅ **Time Complexity:** `O(N²)`  
✅ **Space Complexity:** `O(N)`

## **3️⃣ BFS (O(N) Time, O(N) Space) — Optimal Approach**

### **Algorithm Steps:**

1. Use a **queue** to track the farthest reachable index in **BFS style**.
2. At each level, explore all possible jumps.
3. **Use BFS levels as jump count**:
   - Process all indices reachable from the current level before moving to the next.
   - When reaching the last index, return the number of jumps.

```cpp
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int jumps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                q.pop();
                for (int j = 1; j <= arr[i]; j++) {
                    int next = i + j;
                    if (next >= n - 1) return jumps + 1;
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            jumps++;
        }
        return -1;
    }
};
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(N)`

## **Comparison of Approaches**

| **Approach**            | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                      | ⚠️ **Cons**               |
| ----------------------- | ---------------------- | ----------------------- | -------------------------------- | ------------------------- |
| **Greedy (Optimized)**  | 🟢 `O(N)`              | 🟢 `O(1)`               | Fastest, simple, works in `O(N)` | Requires greedy intuition |
| **Dynamic Programming** | 🟡 `O(N²)`             | 🟡 `O(N)`               | Intuitive                        | Slower for large inputs   |
| **BFS Approach**        | 🟢 `O(N)`              | 🔴 `O(N)`               | Good for large inputs            | Uses extra space          |

✅ **Best Choice?**

- **For fast execution:** Use **Greedy Approach (`O(N)`)**.
- **For structured approach:** Use **1D DP (`O(N²)`)**.
- **For handling larger inputs:** Use **BFS (`O(N)`)**.

</details>

## **Code (Java)**

```java
class Solution {
    static int minJumps(int[] arr) {
        int n = arr.length, jumps = 0, farthest = 0, end = 0;
        if (n == 1) return 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = Math.max(farthest, i + arr[i]);
            if (i == end) {
                jumps++;
                end = farthest;
                if (end >= n - 1) return jumps;
            }
        }
        return -1;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def minJumps(self, arr):
        n, jumps, farthest, end = len(arr), 0, 0, 0
        if n == 1: return 0
        for i in range(n - 1):
            farthest = max(farthest, i + arr[i])
            if i == end:
                jumps += 1
                end = farthest
                if end >= n - 1: return jumps
        return -1
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
