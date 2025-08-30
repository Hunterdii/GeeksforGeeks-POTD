---
title: "🌟 Celebrity Problem | GFG Solution 🔍"
keywords🏷️: ["🌟 celebrity problem", "🔍 linear search", "📍 two pointers", "📈 matrix traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Celebrity Problem: find the celebrity in a party using optimal linear elimination technique. 🚀"
date: 📅 2025-08-30
---

# *30. The Celebrity Problem*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/the-celebrity-problem/1)

## **🧩 Problem Description**

A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix `mat[][]` of size `n*n` is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. Your task is to return the **index of the celebrity** in the party, if the celebrity does not exist, return **-1**.

**Note:** Follow 0-based indexing.

## **📘 Examples**

### Example 1

```cpp
Input: mat[][] = [[1, 1, 0],
                  [0, 1, 0],
                  [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. 
Therefore, 1 is the celebrity person.
```

### Example 2

```cpp
Input: mat[][] = [[1, 1], 
                  [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.
```

### Example 3

```cpp
Input: mat[][] = [[1]]
Output: 0
Explanation: Single person is considered a celebrity as they satisfy the condition trivially.
```

## **🔒 Constraints**

* $1 \le \text{mat.size()} \le 1000$
* $0 \le \text{mat}[i][j] \le 1$
* $\text{mat}[i][i] = 1$

## **✅ My Approach**

The optimal approach uses **Linear Elimination** technique to find the celebrity candidate in O(n) time:

### **Linear Elimination Algorithm**

1. **Find Celebrity Candidate:**
   * Start with candidate `c = 0`.
   * For each person `i` from 1 to n-1:
     * If current candidate `c` knows person `i` (mat[c][i] == 1), then `c` cannot be celebrity.
     * Update candidate to `c = i`.
   * After this loop, we have a potential celebrity candidate.

2. **Verify Celebrity:**
   * Check if the candidate satisfies both conditions:
     * **Condition 1:** Celebrity should not know anyone (except themselves)
     * **Condition 2:** Everyone should know the celebrity
   * If any condition fails, return -1.

3. **Key Insight:**
   * In each iteration, we eliminate at least one person from being a celebrity.
   * If `mat[c][i] == 1`, then `c` cannot be celebrity (knows someone).
   * If `mat[c][i] == 0`, then `i` cannot be celebrity (not known by potential celebrity).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of people. We make two passes through the matrix: first to find candidate (O(n)) and second to verify (O(n)).
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables regardless of input size.

## **🔧 Code (C)**

```c
int celebrity(int **m, int n) {
    int c = 0;
    for (int i = 1; i < n; i++) if (m[c][i]) c = i;
    for (int i = 0; i < n; i++) if (i != c && (m[c][i] || !m[i][c])) return -1;
    return c;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int celebrity(vector<vector<int>>& m) {
        int n = m.size(), c = 0;
        for (int i = 1; i < n; i++) if (m[c][i]) c = i;
        for (int i = 0; i < n; i++) if (i != c && (m[c][i] || !m[i][c])) return -1;
        return c;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Stack-Based Elimination**

### 💡 Algorithm Steps:

1. Push all candidates onto a stack initially.
2. Pop two candidates and eliminate one based on mutual knowledge.
3. Continue until only one candidate remains on stack.
4. Verify the final candidate meets celebrity conditions.

```cpp
class Solution {
public:
    int celebrity(vector<vector<int>>& m) {
        int n = m.size();
        stack<int> st;
        for (int i = 0; i < n; i++) st.push(i);
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(m[a][b] ? b : a);
        }
        int c = st.top();
        for (int i = 0; i < n; i++) if (i != c && (m[c][i] || !m[i][c])) return -1;
        return c;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear elimination and verification
* **Auxiliary Space:** 💾 O(n) - Stack space for candidates

### ✅ **Why This Approach?**

* Clear elimination process visualization
* Natural stack-based candidate management
* Easy to understand elimination logic

## 📊 **3️⃣ Recursive Elimination**

### 💡 Algorithm Steps:

1. Use divide and conquer to eliminate candidates recursively.
2. In each recursive call, eliminate half the candidates.
3. Base case returns when only one candidate remains.
4. Verify the final candidate satisfies celebrity conditions.

```cpp
class Solution {
private:
    int findCelebrity(vector<vector<int>>& m, int l, int r) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        int left = findCelebrity(m, l, mid);
        int right = findCelebrity(m, mid + 1, r);
        if (left == -1) return right;
        if (right == -1) return left;
        return m[left][right] ? right : left;
    }
public:
    int celebrity(vector<vector<int>>& m) {
        int n = m.size();
        int c = findCelebrity(m, 0, n - 1);
        if (c == -1) return -1;
        for (int i = 0; i < n; i++) if (i != c && (m[c][i] || !m[i][c])) return -1;
        return c;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Logarithmic elimination with linear verification
* **Auxiliary Space:** 💾 O(log n) - Recursion stack space

### ✅ **Why This Approach?**

* Elegant divide and conquer strategy
* Reduces comparisons through smart elimination
* Good for recursive thinking practice

## 📊 **4️⃣ Two-Pass Verification**

### 💡 Algorithm Steps:

1. **First Pass:** Find potential celebrity by checking each person's row.
2. Count how many people each person knows (row sum).
3. Celebrity candidate should know only themselves (row sum = 1).
4. **Second Pass:** Verify everyone knows the candidate (column check).

```cpp
class Solution {
public:
    int celebrity(vector<vector<int>>& m) {
        int n = m.size();
        vector<int> rowSum(n, 0), colSum(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    rowSum[i] += m[i][j];
                    colSum[j] += m[i][j];
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (rowSum[i] == 0 && colSum[i] == n - 1) return i;
        }
        return -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Matrix traversal for sum calculation
* **Auxiliary Space:** 💾 O(n) - Arrays for row and column sums

### ✅ **Why This Approach?**

* Intuitive understanding of celebrity properties
* Clear separation of conditions checking
* Good for beginners to understand the problem

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Linear Elimination**         | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal time & space           | 🔧 Requires understanding logic      |
| 🔍 **Stack-Based**                | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear elimination process      | 💾 Extra stack space                 |
| 🔄 **Recursive Divide**           | 🟢 O(n)                | 🟡 O(log n)             | ⭐ Elegant divide-conquer         | 🔧 Complex recursive structure       |
| 📊 **Two-Pass Verification**      | 🔴 O(n²)               | 🟡 O(n)                 | 🎯 Intuitive, easy to understand | ⏱️ Quadratic time complexity        |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive programming, optimal performance**   | 🥇 **Linear Elimination**            | ★★★★★                     |
| 📖 **Learning/Educational purposes**                  | 🥈 **Stack-Based**                   | ★★★★☆                     |
| 🎯 **Interview/Advanced concepts**                    | 🥉 **Recursive Divide**              | ★★★★☆                     |
| 🎓 **Beginner-friendly understanding**               | 🏅 **Two-Pass Verification**         | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int celebrity(int m[][]) {
        int n = m.length, c = 0;
        for (int i = 1; i < n; i++) if (m[c][i] == 1) c = i;
        for (int i = 0; i < n; i++) if (i != c && (m[c][i] == 1 || m[i][c] == 0)) return -1;
        return c;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def celebrity(self, m):
        n, c = len(m), 0
        for i in range(1, n):
            if m[c][i]: c = i
        for i in range(n):
            if i != c and (m[c][i] or not m[i][c]): return -1
        return c
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
