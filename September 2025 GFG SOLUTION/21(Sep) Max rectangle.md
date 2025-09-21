---
title: "🔲 Max Rectangle | GFG Solution 🔍"
keywords🏷️: ["🔲 max rectangle", "📊 histogram", "📍 stack", "🔄 dynamic programming", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Max Rectangle problem: find maximum area rectangle in binary matrix using largest rectangle in histogram approach with stack optimization. 🚀"
date: 📅 2025-09-21
---

# *21. Max Rectangle*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/max-rectangle/1)

## **🧩 Problem Description**

You are given a 2D binary matrix `mat[][]`, where each cell contains either 0 or 1. Your task is to find the **maximum area of a rectangle** that can be formed using only 1's within the matrix.

A rectangle is formed by selecting a submatrix where all elements are 1. The goal is to find the rectangle with the maximum possible area.

## **📘 Examples**

### Example 1

```cpp
Input: mat[][] = [[0, 1, 1, 0],
                  [1, 1, 1, 1],
                  [1, 1, 1, 1],
                  [1, 1, 0, 0]]
Output: 8
Explanation: The largest rectangle with only 1's is from (1, 0) to (2, 3) which is
[1, 1, 1, 1]
[1, 1, 1, 1]
and area is 4 * 2 = 8.
```

### Example 2

```cpp
Input: mat[][] = [[0, 1, 1],
                  [1, 1, 1],
                  [0, 1, 1]]
Output: 6
Explanation: The largest rectangle with only 1's is from (0, 1) to (2, 2) which is
[1, 1]
[1, 1]
[1, 1]
and area is 2 * 3 = 6.
```

## **🔒 Constraints**

* $1 \le \text{mat.size()}, \text{mat[0].size()} \le 1000$
* $0 \le \text{mat}[i][j] \le 1$

## **✅ My Approach**

The optimal approach transforms this problem into the **Largest Rectangle in Histogram** problem by treating each row as the base of a histogram:

### **Histogram + Stack Approach**

1. **Transform to Histogram:**
   * For each row, calculate the height of consecutive 1's ending at that row.
   * If `mat[i][j] = 1`, then `height[j] = height[j] + 1`
   * If `mat[i][j] = 0`, then `height[j] = 0`

2. **Apply Largest Rectangle in Histogram:**
   * For each row's histogram, find the maximum rectangle area using stack.
   * Use a monotonic stack to efficiently find the largest rectangle.

3. **Stack Algorithm:**
   * Push indices to stack while heights are increasing.
   * When a smaller height is found, pop from stack and calculate area.
   * Width = current_index - previous_stack_top - 1 (or current_index if stack is empty).

4. **Update Maximum:**
   * Track the maximum area found across all rows.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m), where n is the number of rows and m is the number of columns. For each row, we process the histogram in O(m) time using stack operations where each element is pushed and popped at most once.
* **Expected Auxiliary Space Complexity:** O(m), where m is the number of columns. We use O(m) space for the height array and O(m) space for the stack in the worst case.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> h(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                h[j] = mat[i][j] ? h[j] + 1 : 0;
            stack<int> st;
            for (int j = 0; j <= m; j++) {
                int cur = j == m ? 0 : h[j];
                while (!st.empty() && h[st.top()] > cur) {
                    int tp = st.top(); st.pop();
                    int w = st.empty() ? j : j - st.top() - 1;
                    res = max(res, h[tp] * w);
                }
                st.push(j);
            }
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dynamic Programming with Arrays**

### 💡 Algorithm Steps:

1. For each row, maintain left and right boundaries for each column
2. Track height of consecutive 1s ending at current row
3. Calculate width using left and right boundaries
4. Update maximum area for each position

```cpp
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> h(m, 0), l(m, 0), r(m, m);
        for (int i = 0; i < n; i++) {
            int cl = 0, cr = m;
            for (int j = 0; j < m; j++) {
                h[j] = mat[i][j] ? h[j] + 1 : 0;
                l[j] = mat[i][j] ? max(l[j], cl) : (cl = j + 1, 0);
            }
            for (int j = m - 1; j >= 0; j--) {
                r[j] = mat[i][j] ? min(r[j], cr) : (cr = j, m);
                res = max(res, h[j] * (r[j] - l[j]));
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m) - Single pass through matrix
* **Auxiliary Space:** 💾 O(m) - Three arrays for height, left, right

### ✅ **Why This Approach?**

* Linear time complexity without stack operations
* More predictable memory access patterns
* Easier to understand the boundary calculations

## 📊 **3️⃣ Divide and Conquer**

### 💡 Algorithm Steps:

1. For each row as base, find maximum rectangle in histogram
2. Use divide and conquer to split histogram at minimum height
3. Recursively solve left and right parts
4. Return maximum of left, right, and cross-section rectangles

```cpp
class Solution {
private:
    int divide(vector<int>& h, int l, int r) {
        if (l > r) return 0;
        int mid = l;
        for (int i = l + 1; i <= r; i++)
            if (h[i] < h[mid]) mid = i;
        return max({h[mid] * (r - l + 1), 
                   divide(h, l, mid - 1), 
                   divide(h, mid + 1, r)});
    }
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> h(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                h[j] = mat[i][j] ? h[j] + 1 : 0;
            res = max(res, divide(h, 0, m - 1));
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m²) - Worst case for divide and conquer
* **Auxiliary Space:** 💾 O(m) - Recursion stack and height array

### ✅ **Why This Approach?**

* Natural recursive structure
* Good for understanding problem decomposition
* Can be optimized with segment trees

## 📊 **4️⃣ Monotonic Deque Optimization**

### 💡 Algorithm Steps:

1. Use deque to maintain indices in increasing order of heights
2. For each position, pop elements that violate monotonic property
3. Calculate area using current height and width from deque
4. More efficient than stack for certain input patterns

```cpp
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> h(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                h[j] = mat[i][j] ? h[j] + 1 : 0;
            deque<int> dq;
            for (int j = 0; j <= m; j++) {
                int cur = j == m ? 0 : h[j];
                while (!dq.empty() && h[dq.back()] > cur) {
                    int tp = dq.back(); dq.pop_back();
                    int w = dq.empty() ? j : j - dq.back() - 1;
                    res = max(res, h[tp] * w);
                }
                dq.push_back(j);
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m) - Linear processing with deque
* **Auxiliary Space:** 💾 O(m) - Deque and height array

### ✅ **Why This Approach?**

* Flexible data structure for monotonic operations
* Better cache locality than stack in some cases
* Alternative implementation for histogram problem

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 📚 **Stack-Based Histogram**      | 🟢 O(n × m)            | 🟢 O(m)                 | 🚀 Optimal and intuitive         | 🔧 Stack operations overhead         |
| 🎯 **DP with Arrays**             | 🟢 O(n × m)            | 🟢 O(m)                 | 📖 No stack, linear scan         | 💭 Complex boundary logic            |
| 🌳 **Divide & Conquer**           | 🟡 O(n × m²)           | 🟢 O(m)                 | 🎓 Educational value              | 🐌 Worst case quadratic time         |
| 📊 **Monotonic Deque**            | 🟢 O(n × m)            | 🟢 O(m)                 | 🔄 Flexible structure            | 🔧 Similar to stack approach         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General optimal performance**                    | 🥇 **Stack-Based Histogram**         | ★★★★★                     |
| 📖 **Avoid stack operations**                         | 🥈 **DP with Arrays**               | ★★★★☆                     |
| 🎓 **Learning/Educational**                           | 🥉 **Divide & Conquer**             | ★★★☆☆                     |
| 🔧 **Alternative implementation**                      | 🏅 **Monotonic Deque**              | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    static int maxArea(int mat[][]) {
        int n = mat.length, m = mat[0].length, res = 0;
        int[] h = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                h[j] = mat[i][j] == 1 ? h[j] + 1 : 0;
            Stack<Integer> st = new Stack<>();
            for (int j = 0; j <= m; j++) {
                int cur = j == m ? 0 : h[j];
                while (!st.isEmpty() && h[st.peek()] > cur) {
                    int tp = st.pop();
                    int w = st.isEmpty() ? j : j - st.peek() - 1;
                    res = Math.max(res, h[tp] * w);
                }
                st.push(j);
            }
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxArea(self, mat):
        n, m, res = len(mat), len(mat[0]), 0
        h = [0] * m
        for i in range(n):
            for j in range(m):
                h[j] = h[j] + 1 if mat[i][j] else 0
            st = []
            for j in range(m + 1):
                cur = 0 if j == m else h[j]
                while st and h[st[-1]] > cur:
                    tp = st.pop()
                    w = j if not st else j - st[-1] - 1
                    res = max(res, h[tp] * w)
                st.append(j)
        return res
```

> **Note:** This Python approach sometimes results in **Time Limit Exceeded (TLE)** for large inputs _(fails ~1110 /1115 test cases due to time constraints)_.

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
