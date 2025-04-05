## 30. Rat in a Maze Problem - I

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)

### Problem Description

Consider a rat placed at (0, 0) in a square matrix `mat` of order `n * n`. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L'(left), 'R'(right). Value `0` at a cell in the matrix represents that it is blocked and the rat cannot move to it while value `1` at a cell in the matrix represents that the rat can travel through it.

Note: In a path, no cell can be visited more than one time. If the source cell is `0`, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

**Example:**

Input:

```
mat[][] = [[1, 0, 0, 0],
           [1, 1, 0, 1],
           [1, 1, 0, 0],
           [0, 1, 1, 1]]
```

Output:

```
DDRDRR DRDDRR
```

Explanation:
The rat can reach the destination at (3, 3) from (0, 0) by two paths - `DRDDRR` and `DDRDRR`. When printed in sorted order, we get `DDRDRR DRDDRR`.

### My Approach

1. **Initialization:**

   - Create a vector `visited` to keep track of visited cells in the matrix.
   - Initialize an empty list `result` to store all the valid paths.

2. **Path Finding:**

   - Use a recursive function `path` to explore all possible paths from the current cell `(x, y)` to the destination cell `(n-1, n-1)`.
   - For each move, check if it is valid (i.e., within matrix bounds, not blocked, and not visited).
   - If a valid path to the destination is found, add it to the `result` list.

3. **Return:**
   - Return the sorted list of all valid paths.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(3^(n^2)), as each cell can be visited in three possible directions except the one it came from, leading to exponential growth with respect to the size of the matrix.
- **Expected Auxiliary Space Complexity:** O(l \* x), where `l` is the length of a path and `x` is the number of paths, due to the recursive stack and the storage of paths.

### Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> visited;
    vector<string> result;

    void path(vector<vector<int>>& m, int x, int y, string dir, int n) {
        if (x == n - 1 && y == n - 1) {
            result.push_back(dir);
            return;
        }
        if (m[x][y] == 0 || visited[x][y] == 1)
            return;
        visited[x][y] = 1;
        if (x > 0)
            path(m, x - 1, y, dir + 'U', n);
        if (y > 0)
            path(m, x, y - 1, dir + 'L', n);
        if (x < n - 1)
            path(m, x + 1, y, dir + 'D', n);
        if (y < n - 1)
            path(m, x, y + 1, dir + 'R', n);
        visited[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        visited = vector<vector<int>>(n, vector<int>(n, 0));
        result.clear();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
            return result;
        path(mat, 0, 0, "", n);
        sort(result.begin(), result.end());
        return result;
    }
};
```

### Code (Java)

```java
import java.util.*;

class Solution {
    private boolean[][] visited;
    private ArrayList<String> result;

    private void path(int[][] m, int x, int y, String dir, int n) {
        if (x == n - 1 && y == n - 1) {
            result.add(dir);
            return;
        }
        if (m[x][y] == 0 || visited[x][y]) return;

        visited[x][y] = true;
        if (x > 0) path(m, x - 1, y, dir + 'U', n);
        if (y > 0) path(m, x, y - 1, dir + 'L', n);
        if (x < n - 1) path(m, x + 1, y, dir + 'D', n);
        if (y < n - 1) path(m, x, y + 1, dir + 'R', n);
        visited[x][y] = false;
    }

    public ArrayList<String> findPath(int[][] mat) {
        int n = mat.length;
        visited = new boolean[n][n];
        result = new ArrayList<>();

        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0) return result;

        path(mat, 0, 0, "", n);
        Collections.sort(result);
        return result;
    }
}
```

### Code (Python)

```python
from typing import List

class Solution:
    def __init__(self):
        self.visited = []
        self.result = []

    def path(self, m: List[List[int]], x: int, y: int, dir: str, n: int):
        if x == n - 1 and y == n - 1:
            self.result.append(dir)
            return
        if m[x][y] == 0 or self.visited[x][y]:
            return

        self.visited[x][y] = True
        if x > 0:
            self.path(m, x - 1, y, dir + 'U', n)
        if y > 0:
            self.path(m, x, y - 1, dir + 'L', n)
        if x < n - 1:
            self.path(m, x + 1, y, dir + 'D', n)
        if y < n - 1:
            self.path(m, x, y + 1, dir + 'R', n)
        self.visited[x][y] = False

    def findPath(self, m: List[List[int]]) -> List[str]:
        n = len(m)
        self.visited = [[False for _ in range(n)] for _ in range(n)]
        self.result = []

        if m[0][0] == 0 or m[n - 1][n - 1] == 0:
            return self.result

        self.path(m, 0, 0, "", n)
        self.result.sort()
        return self.result
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
