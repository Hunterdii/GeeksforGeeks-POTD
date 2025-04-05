# **02. Minimum Cost Path**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given a square grid of size `N`, each cell of which contains an integer cost representing the cost to traverse through that cell, we need to find a path from the top-left cell to the bottom-right cell such that the total cost incurred is minimized. From the cell `(i,j)`, you can move to `(i,j-1)`, `(i,j+1)`, `(i-1,j)`, or `(i+1,j)`.

#### Example:

Input:

```
grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
```

Output:

```
43
```

Explanation: The minimum cost path is `9 -> 4 -> 7 -> 3 -> 3 -> 7 -> 10`.

Input:

```
grid = {{4,4},{3,7}}
```

Output:

```
14
```

Explanation: The minimum cost path is `4 -> 3 -> 7`.

### My Approach

1. **Dijkstra's Algorithm:**

   - This problem can be visualized as a graph traversal problem where each cell is a node, and each move from a cell to its adjacent cell is an edge with a weight equal to the cost of the destination cell.

2. **Priority Queue for Optimality:**

   - A priority queue (min-heap) is used to explore paths with the lowest cost first. The priority queue stores cells along with their current cumulative cost.

3. **Dynamic Programming for Storing Minimum Costs:**

   - A 2D DP array `dp` is used where `dp[i][j]` holds the minimum cost to reach cell `(i, j)` from the starting cell `(0, 0)`.

4. **Exploration of Adjacent Cells:**

   - For each cell `(i, j)` dequeued from the priority queue, the algorithm checks its adjacent cells. If moving to an adjacent cell offers a lower cost than previously recorded, the DP array is updated, and the adjacent cell is enqueued with the new cumulative cost.

5. **Final Answer:**
   - The minimum cost to reach the bottom-right cell `(n-1, m-1)` is stored in `dp[n-1][m-1]`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n² \* log(n)), as we are using Dijkstra's algorithm with a priority queue, which takes `O(log(n))` time for each operation, and there are `n²` nodes.
- **Expected Auxiliary Space Complexity:** O(n²), for storing the DP array and the priority queue.

### Code (C++)

```cpp
class Solution {
public:
    struct cell {
        int x, y, distance;
        bool operator>(const cell& other) const {
            return distance > other.distance;
        }
    };
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<cell, vector<cell>, greater<cell>> pq;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        dp[0][0] = grid[0][0];
        pq.push({0, 0, dp[0][0]});
        while (!pq.empty()) {
            cell cur = pq.top();
            pq.pop();
            int x = cur.x;
            int y = cur.y;
            int dist = cur.distance;
            if (dist > dp[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newDist = dp[x][y] + grid[nx][ny];
                    if (newDist < dp[nx][ny]) {
                        dp[nx][ny] = newDist;
                        pq.push({nx, ny, newDist});
                    }
                }
            }
        }

        return dp[n-1][m-1];
    }
};
```

### Code (Java)

```java
class Solution {
    static class Cell implements Comparable<Cell> {
        int x, y, distance;

        Cell(int x, int y, int distance) {
            this.x = x;
            this.y = y;
            this.distance = distance;
        }

        public int compareTo(Cell other) {
            return Integer.compare(this.distance, other.distance);
        }
    }

    public int minimumCostPath(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] dp = new int[n][m];
        for (int[] row : dp) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        PriorityQueue<Cell> pq = new PriorityQueue<>();
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        dp[0][0] = grid[0][0];
        pq.offer(new Cell(0, 0, dp[0][0]));

        while (!pq.isEmpty()) {
            Cell cur = pq.poll();
            int x = cur.x;
            int y = cur.y;
            int dist = cur.distance;

            if (dist > dp[x][y]) continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newDist = dp[x][y] + grid[nx][ny];
                    if (newDist < dp[nx][ny]) {
                        dp[nx][ny] = newDist;
                        pq.offer(new Cell(nx, ny, newDist));
                    }
                }
            }
        }

        return dp[n-1][m-1];
    }
}
```

_Sometime Its Not Running Python(Code) But I've Tried Its Prefectly Running_

### Code (Python)

```python
import heapq

class Solution:
    def minimumCostPath(self, grid):
        n = len(grid)
        m = len(grid[0])
        dp = [[float('inf')] * m for _ in range(n)]
        pq = []
        dx = [-1, 1, 0, 0]
        dy = [0, 0, -1, 1]

        dp[0][0] = grid[0][0]
        heapq.heappush(pq, (dp[0][0], 0, 0))

        while pq:
            dist, x, y = heapq.heappop(pq)

            if dist > dp[x][y]:
                continue

            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]

                if 0 <= nx < n and 0 <= ny < m:
                    newDist = dp[x][y] + grid[nx][ny]
                    if newDist < dp[nx][ny]:
                        dp[nx][ny] = newDist
                        heapq.heappush(pq, (newDist, nx, ny))

        return dp[n-1][m-1]
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
