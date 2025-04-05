## 27. Find shortest safe route in a matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-shortest-safe-route-in-a-matrix/1)

### Problem Description

Given a matrix `mat[][]` with \(r\) rows and \(c\) columns, where some cells are landmines (marked as 0) and others are safe to traverse. Your task is to find the shortest safe route from any cell in the leftmost column to any cell in the rightmost column of the matrix. You cannot move diagonally, and you must avoid both the landmines and their adjacent cells (up, down, left, right), as they are also unsafe.

**Example:**

Input:

```
mat = [1, 0, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 0, 1],
      [1, 1, 1, 1, 0]
```

Output:

```
6
```

Explanation:
We can see that the length of the shortest safe route is 6.

### My Approach

1. **Initialization:**
   - Initialize variables `n` and `m` to store the number of rows and columns in the matrix `mat`.
   - Define an array `d` to represent the four possible directions: right, left, down, and up.
2. **Marking Obstacles and Starting Points:**
   - Iterate through each cell in the matrix.
   - If a cell contains a landmine (0), mark all adjacent cells as unsafe by setting their value to 2.
3. **BFS Traversal:**
   - Start BFS traversal from the leftmost column.
   - Enqueue all cells in the leftmost column that contain a safe path (1) into a queue and mark them as visited.
4. **Performing BFS:**
   - While the queue is not empty, perform the following steps:
     - Dequeue a cell from the queue.
     - If the current cell is in the rightmost column, return the length of the shortest path found.
     - Otherwise, enqueue all adjacent safe cells into the queue and mark them as visited.
5. **Return Result:**
   - If no path is found, return -1.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(r \times c)\), as we perform BFS traversal on the entire matrix.
- **Expected Auxiliary Space Complexity:** \(O(r \times c)\), as we use a queue to perform BFS traversal.

### Code (C++)

```cpp
class Solution {
public:
    int findShortestPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), d[4] = {1, -1, 0, 0};

        // Marking obstacles and starting points
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!mat[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k], y = j + d[3 - k];
                        if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1)
                            mat[x][y] = 2;
                    }
                }

        // Starting BFS from the leftmost column
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            if (mat[i][0] == 1)
                mat[i][0] = 2, q.push({i, 0});

        int ans = 1;

        // Performing BFS
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                pair<int, int> current = q.front();
                q.pop();
                int i = current.first;
                int j = current.second;
                if (j == m - 1)
                    return ans; // Found shortest path
                for (int k = 0; k < 4; k++) {
                    int x = i + d[k], y = j + d[3 - k];
                    if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1)
                        mat[x][y] = 2, q.push({x, y});
                }
            }
            ans++;
        }
        return -1; // No path found
    }
};
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
