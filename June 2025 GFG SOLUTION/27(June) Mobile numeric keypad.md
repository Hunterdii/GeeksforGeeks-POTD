---
title: "📱 Mobile Numeric Keypad | GFG Solution 🔢"
keywords🏷️: ["📱 mobile keypad", "🔢 dynamic programming", "📊 2D array", "🎯 unique sequences", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Mobile Numeric Keypad problem: count unique sequences of length n using keypad movements with dynamic programming. 🚀"
date: 📅 2025-06-27
---

# *27. Mobile Numeric Keypad*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1)

## **🧩 Problem Description**

You have a standard numeric keypad on a mobile phone. You can press the current button or any button that is directly **above, below, left, or right** of it. Diagonal movements and pressing the bottom row corner buttons (* and #) are **not allowed**.

Given an integer `n`, determine how many **unique sequences** of length `n` can be formed by pressing buttons on the keypad, starting from any digit.

**Keypad Layout:**

<img src="https://github.com/user-attachments/assets/c450610f-073a-4c56-8b3b-85dfc1ddd253" width="20%">

## **📘 Examples**

### Example 1

```cpp
Input: n = 1
Output: 10
Explanation: Possible 1-digit numbers follow keypad moves - 
From 0 → 0, 1 → 1, 2 → 2 and so on, total 10 valid combinations are possible.
```

### Example 2

```cpp
Input: n = 2
Output: 36
Explanation: Possible 2-digit numbers follow keypad moves -
From 0 → 00, 08 (2), 
From 1 → 11, 12, 14 (3),
From 3 → 33, 32, 36 (3), and so on,
total 36 valid combinations are possible.
```

## **🔒 Constraints**

* $1 \le n \le 15$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** with a 2D array representing the keypad layout. We simulate the keypad as a 4×3 grid and use direction vectors to handle valid movements.

### **Dynamic Programming with 2D Grid Simulation**

1. **Model the Keypad:**
   * Represent keypad as a 4×3 grid where [3][0] and [3][2] are invalid (* and # positions).
   * Initialize all valid positions with 1 (base case for n=1).

2. **Define Movement Directions:**
   * Use direction vectors: stay in place (0,0), up/down/left/right movements.
   * This allows pressing current button or adjacent buttons.

3. **Iterative DP Transition:**
   * For each step from 2 to n, calculate new possibilities.
   * For each position, sum up contributions from all reachable positions.
   * Use two arrays (previous and current) to avoid overwriting.

4. **Boundary Handling:**
   * Skip invalid keypad positions ([3][0] and [3][2]).
   * Ensure movements stay within 4×3 grid bounds.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the sequence length. We iterate n-1 times, and for each iteration, we process a constant 4×3 grid with constant direction moves.
* **Expected Auxiliary Space Complexity:** O(1), as we only use two fixed-size 4×3 arrays regardless of input size, making it constant extra space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int getCount(int n) {
        int ans = 0;
        vector<vector<int>> p(4, vector<int>(3, 1)), c(4, vector<int>(3));
        p[3][0] = p[3][2] = 0;
        vector<vector<int>> d = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 3; j++) {
                    if (i==3&&(j==0||j==2)) continue;
                    c[i][j] = 0;
                    for (auto &v : d) {
                        int x = i+v[0], y = j+v[1];
                        if (x>=0 && x<4 && y>=0 && y<3) c[i][j] += p[x][y];
                    }
                }
            p = c;
        }
        for (auto &r : p) for (int v : r) ans += v;
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Recursion + Memoization**

### 💡 Algorithm Steps:

1. Use a recursive function to explore valid digits for each press.
2. Use a memoization table (3D: position × n) to cache overlapping results.
3. Skip invalid keypad positions.

```cpp
class Solution {
public:
    int dp[16][4][3];
    
    int dfs(int n, int i, int j) {
        if (i < 0 || i > 3 || j < 0 || j > 2 || (i==3 && j!=1)) return 0;
        if (n == 1) return 1;
        if (dp[n][i][j] != -1) return dp[n][i][j];
        
        vector<pair<int,int>> dir = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        int res = 0;
        for (auto d : dir) 
            res += dfs(n-1, i+d.first, j+d.second);
        
        return dp[n][i][j] = res;
    }
    
    int getCount(int n) {
        memset(dp, -1, sizeof(dp));
        int res = 0;
        for (int i=0; i<4; ++i)
            for (int j=0; j<3; ++j)
                if (!(i==3 && j!=1))
                    res += dfs(n, i, j);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) due to memoization table and recursion stack

### ✅ **Why This Approach?**

* Natural recursive thinking.
* Easy to understand the state transitions.

## 📊 **3️⃣ Adjacency List Based DP**

### 💡 Algorithm Steps:

1. Pre-define adjacency list for each digit (0-9).
2. Use 1D DP array where dp[i] represents count from digit i.
3. Update based on adjacent digits for each step.

```cpp
class Solution {
public:
    int getCount(int n) {
        vector<vector<int>> adj = {
            {0, 8}, {1, 2, 4}, {1, 2, 3, 5}, {2, 3, 6},
            {1, 4, 5, 7}, {2, 4, 5, 6, 8}, {3, 5, 6, 9},
            {4, 7, 8}, {5, 7, 8, 9, 0}, {6, 8, 9}
        };
        
        vector<int> dp(10, 1), next(10, 0);
        
        for (int step = 2; step <= n; step++) {
            fill(next.begin(), next.end(), 0);
            for (int digit = 0; digit <= 9; digit++) {
                for (int neighbor : adj[digit]) {
                    next[digit] += dp[neighbor];
                }
            }
            dp = next;
        }
        
        int result = 0;
        for (int count : dp) result += count;
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1) - Fixed size arrays for 10 digits

### ✅ **Why This Approach?**

* Direct digit-to-digit mapping.
* Clean separation of adjacency logic.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                       | ⚠️ **Cons**                    |
| ------------------------------ | ---------------------- | ----------------------- | -------------------------------- | ------------------------------ |
| 🔁 **2D Grid DP**              | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Most space efficient          | 🧮 Grid indexing complexity     |
| 🧠 **Recursive + Memoization** | 🟢 O(n)                | 🟡 O(n)                 | 🧩 Natural recursive thinking    | 💾 Higher memory usage         |
| 📋 **Adjacency List DP**       | 🟢 O(n)                | 🟢 O(1)                 | 🔧 Clean digit-based logic       | 🔄 Requires pre-defined mapping |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                              | 🎖️ **Recommended Approach** | 🔥 **Performance Rating** |
| -------------------------------------------- | ---------------------------- | ------------------------- |
| ⚡ Memory-critical applications              | 🥇 **2D Grid DP**            | ★★★★★                     |
| 📚 Learning recursion and memoization       | 🥈 **Recursive + Memo**      | ★★★★☆                     |
| 🔧 Clean, maintainable code                 | 🥉 **Adjacency List DP**     | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int getCount(int n) {
        int[][] p = new int[4][3], c = new int[4][3];
        for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++) p[i][j] = 1;
        p[3][0] = p[3][2] = 0;
        int[][] d = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 3; j++) {
                    if (i==3&&(j==0||j==2)) continue;
                    c[i][j] = 0;
                    for (int[] v : d) {
                        int x = i + v[0], y = j + v[1];
                        if (x >= 0 && x < 4 && y >= 0 && y < 3) c[i][j] += p[x][y];
                    }
                }
            for (int i = 0; i < 4; i++) System.arraycopy(c[i], 0, p[i], 0, 3);
        }
        int ans = 0;
        for (int[] r : p) for (int v : r) ans += v;
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def getCount(self, n):
        p = [[1]*3 for _ in range(4)]
        p[3][0] = p[3][2] = 0
        d = [(0,0),(0,1),(0,-1),(1,0),(-1,0)]
        for _ in range(2,n+1):
            c = [[0]*3 for _ in range(4)]
            for i in range(4):
                for j in range(3):
                    if i==3 and j in (0,2): continue
                    for dx,dy in d:
                        x,y = i+dx,j+dy
                        if 0<=x<4 and 0<=y<3: c[i][j] += p[x][y]
            p = c
        return sum(sum(r) for r in p)
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
