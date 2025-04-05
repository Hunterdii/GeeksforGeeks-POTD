## 11. Maximum Connected Group

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-connected-group/1)

### Problem Description

You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected 1's. Two cells are said to be connected if both are adjacent (top, bottom, left, right) to each other and both have the same value.

**Examples:**

**Example 1:**

Input:

```
grid = [
    [1, 1],
    [0, 1]
]
```

Output:

```
4
```

Explanation:
By changing cell (2, 1), we can obtain a connected group of 4 1's:

```
[1, 1]
[1, 1]
```

### My Approach

1. **Initialization:**

- Define direction vectors `dx` and `dy` for exploring the four possible adjacent cells.
- Initialize a counter `k` to label connected components in the grid.
- Use a map `mp` to store the size of each connected component.

2. **DFS to Find Connected Components:**

- Iterate through each cell of the grid.
- If a cell contains a 1, perform a DFS to find all connected 1's and label them with the counter `k`.
- Store the size of each connected component in the map `mp`.

3. **Calculate Potential Group Sizes:**

- Iterate through each cell of the grid.
- If a cell contains a 0, calculate the potential size of the connected group by changing this cell to 1 and considering the sizes of its neighboring components.
- Use a set to avoid counting the same component multiple times.

4. **Find the Maximum Group Size:**

- Track the maximum size of connected groups formed either by original or potential connections.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^2), as we perform DFS for each cell and evaluate each cell's potential group size.
- **Expected Auxiliary Space Complexity:** O(n^2), as we use additional space for the grid, map, and sets to track connected components and their sizes.

### Code (C++)

```cpp
class Solution {
public:
    int n;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int solve(int i, int j, vector<vector<int>>& grid, int k) {
        grid[i][j] = k;
        int count = 1;
        for (int l = 0; l < 4; ++l) {
            int x = i + dx[l];
            int y = j + dy[l];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                count += solve(x, y, grid, k);
            }
        }
        return count;
    }

    int MaxConnection(vector<vector<int>>& grid) {
        n = grid.size();
        int k = 2;
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int size = solve(i, j, grid, k);
                    mp[k] = size;
                    ans = max(ans, size);
                    ++k;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> unique_neighbors;
                    int potential_size = 1;
                    for (int l = 0; l < 4; ++l) {
                        int x = i + dx[l];
                        int y = j + dy[l];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
                            int neighbor_component = grid[x][y];
                            if (unique_neighbors.insert(neighbor_component).second) {
                                potential_size += mp[neighbor_component];
                            }
                        }
                    }
                    ans = max(ans, potential_size);
                }
            }
        }

        return ans;
    }
};
```

### Code (Java)

```java
class Solution {
    int n;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};

    public int solve(int i, int j, int[][] grid, int k) {
        grid[i][j] = k;
        int count = 1;
        for (int l = 0; l < 4; ++l) {
            int x = i + dx[l];
            int y = j + dy[l];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                count += solve(x, y, grid, k);
            }
        }
        return count;
    }

    public int MaxConnection(int[][] grid) {
        n = grid.length;
        int k = 2;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int size = solve(i, j, grid, k);
                    mp.put(k, size);
                    ans = Math.max(ans, size);
                    ++k;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    HashSet<Integer> unique_neighbors = new HashSet<>();
                    int potential_size = 1;
                    for (int l = 0; l < 4; ++l) {
                        int x = i + dx[l];
                        int y = j + dy[l];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
                            int neighbor_component = grid[x][y];
                            if (unique_neighbors.add(neighbor_component)) {
                                potential_size += mp.get(neighbor_component);
                            }
                        }
                    }
                    ans = Math.max(ans, potential_size);
                }
            }
        }

        return ans;
    }
}
```

### Code (Python)

```python
from typing import List, Set
from collections import defaultdict, deque

class Solution:
    def __init__(self):
        self.directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    def bfs(self, grid: List[List[int]], i: int, j: int, index: int) -> int:
        n = len(grid)
        queue = deque([(i, j)])
        grid[i][j] = index
        area_size = 0

        while queue:
            x, y = queue.popleft()
            area_size += 1
            for dx, dy in self.directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < n and grid[nx][ny] == 1:
                    grid[nx][ny] = index
                    queue.append((nx, ny))

        return area_size

    def findNeighbours(self, grid: List[List[int]], i: int, j: int) -> Set[int]:
        n = len(grid)
        neighbors = set()
        for dx, dy in self.directions:
            ni, nj = i + dx, j + dy
            if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] > 1:
                neighbors.add(grid[ni][nj])
        return neighbors

    def MaxConnection(self, grid: List[List[int]]) -> int:
        n = len(grid)
        index = 2
        area = defaultdict(int)
        max_area = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    area[index] = self.bfs(grid, i, j, index)
                    max_area = max(max_area, area[index])
                    index += 1
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    neighbors = self.findNeighbours(grid, i, j)
                    potential_area = 1 + sum(area[idx] for idx in neighbors)
                    max_area = max(max_area, potential_area)

        return max_area
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
