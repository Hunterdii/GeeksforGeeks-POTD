---
title: "🔍 Word Search in 2D Matrix | GFG Solution 🎯"
keywords🏷️: ["🔍 word search", "🔄 backtracking", "📍 DFS", "🎯 matrix traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Word Search problem: find if a word exists in a 2D character matrix using DFS backtracking technique. 🚀"
date: 📅 2025-01-27
---

# *27. Word Search*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/word-search/1)

## **🧩 Problem Description**

You are given a matrix `mat[][]` of size `n*m` containing English alphabets and a string `word`. Check if the `word` exists on the `mat[][]` or not. The word can be constructed by using letters from **adjacent cells**, either **horizontally or vertically**. The same cell cannot be used more than once.

A valid word path is formed by connecting adjacent cells where each cell can only be visited once during the search for a particular word.

## **📘 Examples**

**Input:**

```
mat[][] = [['T', 'E', 'E'],
           ['S', 'G', 'K'],
           ['T', 'E', 'L']]
word = "GEEK"
```

**Output:**  
`true`  
**Explanation:**

<img src="https://github.com/user-attachments/assets/93e597c2-f34a-418c-b5bf-9a945371ac55" width="30%">

The letters used to construct "GEEK" are found in the grid.

**Input:**

```
mat[][] = [['T', 'E', 'U'],
           ['S', 'G', 'K'],
           ['T', 'E', 'L']]
word = "GEEK"
```

**Output:**  
`false`  
**Explanation:**

<img src="https://github.com/user-attachments/assets/c90d723f-a1bd-4483-ba9d-e5903684b481" width="30%">

The word "GEEK" cannot be formed from the given grid.

**Input:**

```
mat[][] = [['A', 'B', 'A'],
           ['B', 'A', 'B']]
word = "AB"
```

**Output:**  
`true`  
**Explanation:**

<img src="https://github.com/user-attachments/assets/f8d9c68d-6447-4817-8646-7c1a1497ac5e" width="30%">

There are multiple ways to construct the word "AB".

## **🔒 Constraints**

* $1 \le n, m \le 6$
* $1 \le \text{word.size()} \le 15$
* `mat` and `word` consists of only lowercase and uppercase English letters.

## **✅ My Approach**

The optimal approach uses **DFS Backtracking** to explore all possible paths in the matrix:

### **DFS Backtracking Algorithm**

1. **Initialize Search:**
   * Iterate through each cell in the matrix as a potential starting point.
   * When the first character of the word matches a cell, start DFS from that position.

2. **DFS Exploration:**
   * Check if current position is valid (within bounds and matches current character).
   * Mark current cell as visited by replacing it with a special character (e.g., '*').
   * Recursively explore all 4 adjacent directions (up, down, left, right).

3. **Backtrack:**
   * After exploring all paths from current cell, restore the original character.
   * This allows the cell to be used in other potential word paths.

4. **Base Cases:**
   * If we've matched all characters in the word, return true.
   * If current position is invalid or character doesn't match, return false.

5. **Return Result:**
   * Return true if any starting position leads to a complete word match.
   * Return false if no valid path is found after checking all positions.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m × 4^L), where n and m are matrix dimensions and L is the word length. In worst case, we explore all cells as starting points and from each cell, we explore 4 directions recursively up to word length L.
* **Expected Auxiliary Space Complexity:** O(L), where L is the length of the word. This space is used by the recursion stack, which can go as deep as the word length. We don't use any additional data structures apart from the recursion call stack.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool isWordExist(vector<vector<char>>& b, string w) {
        int m = b.size(), n = b[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (search(b, w, i, j, 0)) return true;
        return false;
    }
    
    bool search(vector<vector<char>>& b, string& w, int r, int c, int idx) {
        if (idx == w.size()) return true;
        if (r < 0 || c < 0 || r >= b.size() || c >= b[0].size() || b[r][c] != w[idx]) return false;
        char tmp = b[r][c];
        b[r][c] = '*';
        bool res = search(b, w, r + 1, c, idx + 1) || search(b, w, r - 1, c, idx + 1) ||
                   search(b, w, r, c + 1, idx + 1) || search(b, w, r, c - 1, idx + 1);
        b[r][c] = tmp;
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized Early Exit with Character Frequency**

### 💡 Algorithm Steps:

1. Build frequency map of characters in board and word before starting the search.
2. Perform early rejection if word contains characters not present in board or if frequency is insufficient.
3. Optimize search direction by starting from the less frequent character end.
4. Use standard DFS backtracking with the optimized starting point.

```cpp
class Solution {
public:
    bool isWordExist(vector<vector<char>>& b, string w) {
        unordered_map<char, int> boardFreq, wordFreq;
        for (auto& row : b)
            for (char c : row) boardFreq[c]++;
        for (char c : w) wordFreq[c]++;
        for (auto& [ch, cnt] : wordFreq)
            if (boardFreq[ch] < cnt) return false;
        if (boardFreq[w[0]] > boardFreq[w.back()]) {
            reverse(w.begin(), w.end());
        }
        for (int i = 0; i < b.size(); i++)
            for (int j = 0; j < b[0].size(); j++)
                if (b[i][j] == w[0] && dfs(b, w, i, j, 0)) return true;
        return false;
    }
    
    bool dfs(vector<vector<char>>& b, string& w, int i, int j, int k) {
        if (k == w.size()) return true;
        if (i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != w[k]) return false;
        char t = b[i][j];
        b[i][j] = '#';
        bool f = dfs(b, w, i + 1, j, k + 1) || dfs(b, w, i - 1, j, k + 1) ||
                 dfs(b, w, i, j + 1, k + 1) || dfs(b, w, i, j - 1, k + 1);
        b[i][j] = t;
        return f;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m) for preprocessing + O(n × m × 4^L) for DFS search
* **Auxiliary Space:** 💾 O(L + K) where L is recursion depth and K is number of unique characters in word

### ✅ **Why This Approach?**

* Early rejection saves time for impossible cases
* Character frequency optimization reduces search space
* Reversing word when needed minimizes starting points to explore

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **DFS Backtracking**           | 🟡 O(n×m×4^L)          | 🟢 O(L)                 | 🚀 Simple and clean               | 🔧 No early pruning                   |
| ⚡ **Frequency Optimized**        | 🟢 O(n×m×4^L)          | 🟡 O(L+K)               | 🎯 Early pruning, fewer searches  | 🔧 Extra preprocessing overhead       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Short words, small boards**                      | 🥇 **DFS Backtracking**              | ★★★★★                     |
| 🔧 **Large boards with impossible words**             | 🥈 **Frequency Optimized**           | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public boolean isWordExist(char[][] b, String w) {
        for (int i = 0; i < b.length; i++)
            for (int j = 0; j < b[0].length; j++)
                if (search(b, w, i, j, 0)) return true;
        return false;
    }
    
    boolean search(char[][] b, String w, int r, int c, int idx) {
        if (idx == w.length()) return true;
        if (r < 0 || c < 0 || r >= b.length || c >= b[0].length || b[r][c] != w.charAt(idx)) return false;
        char tmp = b[r][c];
        b[r][c] = '*';
        boolean res = search(b, w, r + 1, c, idx + 1) || search(b, w, r - 1, c, idx + 1) ||
                      search(b, w, r, c + 1, idx + 1) || search(b, w, r, c - 1, idx + 1);
        b[r][c] = tmp;
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def isWordExist(self, b, w):
        def search(r, c, idx):
            if idx == len(w): return True
            if r < 0 or c < 0 or r >= len(b) or c >= len(b[0]) or b[r][c] != w[idx]: return False
            tmp, b[r][c] = b[r][c], '*'
            res = search(r + 1, c, idx + 1) or search(r - 1, c, idx + 1) or search(r, c + 1, idx + 1) or search(r, c - 1, idx + 1)
            b[r][c] = tmp
            return res
        
        return any(search(i, j, 0) for i in range(len(b)) for j in range(len(b[0])))
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


