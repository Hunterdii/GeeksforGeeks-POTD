# _6. Find the Number of Islands_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1)

### Problem Description

Given a grid of size `n*m` (where `n` is the number of rows and `m` is the number of columns in the grid) consisting of `'0'`s (Water) and `'1'`s (Land), find the number of islands. An island is a group of connected `'1'`s that are surrounded by water or the grid boundary. The connection can be vertical, horizontal, or diagonal.

**Note:**

- Islands are connected in all 8 possible directions: left, right, up, down, and the 4 diagonal directions.
- The entire grid is traversed, and the number of distinct islands is counted.

### Example:

**Input 1:**

```
grid = [[0, 1],
        [1, 0],
        [1, 1],
        [1, 0]]
```

**Output 1:** `1`

**Explanation:**  
All land cells are connected to form a single island.

---

**Input 2:**

```
grid = [[0, 1, 1, 1, 0, 0, 0],
        [0, 0, 1, 1, 0, 1, 0]]
```

**Output 2:** `2`

**Explanation:**  
There are two islands, one formed by the group of `'1'`s in the first three columns and another formed by the group of `'1'`s in the sixth column.

---

### My Approach

1. **Depth-First Search (DFS):**

   - We treat the grid as a graph and explore all connected cells containing `'1'` using DFS.
   - For each unvisited land cell, we perform a DFS to mark all connected land cells as visited. This entire DFS traversal is considered as one island.
   - Repeat the process for each unvisited land cell until all cells are checked.

2. **Checking Boundaries:**

   - The `isValid()` function ensures that the current cell lies within the grid boundaries and contains a `'1'` before proceeding with DFS.

3. **DFS Traversal:**
   - For each unvisited land cell, mark it as visited by setting it to `'0'`. Then, explore all 8 neighboring cells (horizontal, vertical, diagonal). If a neighboring cell is also land, continue the DFS from that cell.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n\*m), where `n` is the number of rows and `m` is the number of columns in the grid. This is because we visit each cell once and traverse its neighbors.
- **Expected Auxiliary Space Complexity:** O(n\*m), as the DFS call stack can grow up to the total number of cells in the grid in the worst case.

---

### Code (C++)

```cpp
class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0, 1, -1, -1, 1};
    vector<int> dy = {0, -1, 0, 1, 1, 1, -1, -1};

    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    void dfs(int x, int y, vector<vector<char>>& grid, int n, int m) {
        grid[x][y] = '0';

        for (int k = 0; k < 8; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];

            if (isValid(newX, newY, n, m) && grid[newX][newY] == '1') {
                dfs(newX, newY, grid, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        return ans;
    }
};
```

---

### Code (Java)

```java
class Solution {

    private int[] dx = {-1, 0, 1, 0, 1, -1, -1, 1};
    private int[] dy = {0, -1, 0, 1, 1, 1, -1, -1};

    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        return ans;
    }

    private void dfs(int x, int y, char[][] grid, int n, int m) {
        grid[x][y] = '0';  // Mark the current cell as visited

        for (int k = 0; k < 8; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];

            if (isValid(newX, newY, n, m) && grid[newX][newY] == '1') {
                dfs(newX, newY, grid, n, m);
            }
        }
    }

    private boolean isValid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
}
```

---

### Code (Python)

```python
class Solution:
    def numIslands(self, grid):
        n = len(grid)
        m = len(grid[0])
        ans = 0

        dx = [-1, 0, 1, 0, 1, -1, -1, 1]
        dy = [0, -1, 0, 1, 1, 1, -1, -1]

        def dfs(x, y):
            grid[x][y] = 0
            for k in range(8):
                newX = x + dx[k]
                newY = y + dy[k]
                if is_valid(newX, newY) and grid[newX][newY] == 1:
                    dfs(newX, newY)

        def is_valid(x, y):
            return 0 <= x < n and 0 <= y < m

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    ans += 1
                    dfs(i, j)

        return ans
```

---

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
