---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Recursion
  - DFS
  - Graph
  - Backtracking
---

# 🚀 _Day 5. Word Search_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/word-search)

## 💡 **Problem Description:**

You are given a two-dimensional `mat[][]` of size `n × m` containing English alphabets and a string `word`.  
Check if the `word` exists in the `mat`. The word can be constructed by using letters from adjacent cells,  
either **horizontally** or **vertically**. The **same cell cannot be used more than once**.

## 🔍 **Example Walkthrough:**

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

### Constraints:

- `1 ≤ n, m ≤ 100`
- `1 ≤ L ≤ n * m`  
  (where `L` is the length of the word)

## 🎯 **My Approach:**

1. **Start from Each Cell**

   - Iterate over the matrix to find the first letter of the word.
   - If a match is found, perform **DFS** from that position.

2. **Recursive DFS Traversal**

   - Check the four possible directions: **up, down, left, right**.
   - If the next character in the word is found, move to that cell.
   - Temporarily mark the cell as visited (`'#'`) to prevent reusing it in the same search path.

3. **Backtracking**

   - Restore the cell's original value after exploring all paths from that cell.
   - If the complete word is found, return `true`.

4. **Optimization**
   - If the first letter of `word` is not found in `mat[][]`, return `false` immediately.
   - Stop searching as soon as the word is found.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(n * m * 4^L)`, where `n × m` is the size of the matrix and `L` is the length of the word.

  - We perform DFS from every cell (`O(n * m)`).
  - Each DFS call explores up to **4 directions**, leading to a worst-case exponential growth (`O(4^L)`).

- **Expected Auxiliary Space Complexity:** `O(L)`, due to the recursive call stack of depth **L** (length of the word).
  - We modify the grid temporarily (`O(n * m)`) but revert it back (constant space usage).

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    bool dfs(vector<vector<char>> &b, string &w, int i, int j, int k) {
        if(k == w.size()) return true;
        if(i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != w[k]) return false;
        char t = b[i][j];
        b[i][j] = '#';
        bool f = dfs(b, w, i-1, j, k+1) || dfs(b, w, i+1, j, k+1) ||
                 dfs(b, w, i, j-1, k+1) || dfs(b, w, i, j+1, k+1);
        b[i][j] = t;
        return f;
    }

    bool isWordExist(vector<vector<char>> &b, string w) {
        for(int i = 0; i < b.size(); i++)
            for(int j = 0; j < b[0].size(); j++)
                if(b[i][j] == w[0] && dfs(b, w, i, j, 0))
                    return true;
        return false;
    }
};
```

## Code (Java)

```java
class Solution {
    public boolean isWordExist(char[][] b, String w) {
        for (int i = 0; i < b.length; i++)
            for (int j = 0; j < b[0].length; j++)
                if (b[i][j] == w.charAt(0) && dfs(b, w, i, j, 0))
                    return true;
        return false;
    }

    private boolean dfs(char[][] b, String w, int i, int j, int k) {
        if (k == w.length()) return true;
        if (i < 0 || j < 0 || i >= b.length || j >= b[0].length || b[i][j] != w.charAt(k)) return false;
        char t = b[i][j];
        b[i][j] = '#';
        boolean f = dfs(b, w, i - 1, j, k + 1) || dfs(b, w, i + 1, j, k + 1) ||
                   dfs(b, w, i, j - 1, k + 1) || dfs(b, w, i, j + 1, k + 1);
        b[i][j] = t;
        return f;
    }
}
```

## Code (Python)

```python
class Solution:
    def isWordExist(self, b, w):
        def dfs(i, j, k):
            if k == len(w): return True
            if i < 0 or j < 0 or i >= len(b) or j >= len(b[0]) or b[i][j] != w[k]: return False
            t, b[i][j] = b[i][j], '#'
            f = any(dfs(i + dx, j + dy, k + 1) for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)])
            b[i][j] = t
            return f

        return any(dfs(i, j, 0) for i in range(len(b)) for j in range(len(b[0])) if b[i][j] == w[0])
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
