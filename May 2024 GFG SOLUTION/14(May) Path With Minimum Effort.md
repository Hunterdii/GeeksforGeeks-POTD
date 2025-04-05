## 14. Path With Minimum Effort

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1)

### Problem Description

You are a hiker preparing for an upcoming hike. You are given `heights[][]`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find the route with the minimum effort.

**Example:**

Input:

```
rows = 3
columns = 3
heights = [[1,2,2],[3,8,2],[5,3,5]]
```

Output:

```
2
```

Explanation:
The route 1->3->5->3->5 has a maximum absolute difference of 2 in consecutive cells. This is better than the route 1->2->2->2->5, where the maximum absolute difference is 3.

### My Approach

1. **Priority Queue for Dijkstra's Algorithm:**

- Use a priority queue to implement Dijkstra's algorithm for finding the shortest path.
- Each element in the priority queue represents a cell `(row, col)` along with the effort required to reach that cell.
- Initialize a 2D array `dist` to store the minimum effort required to reach each cell. Initialize all values to `INT_MAX`, except for the starting cell `(0, 0)` with value 0.
- Push the starting cell `(0, 0)` into the priority queue with an effort of 0.

2. **Dijkstra's Algorithm:**

- While the priority queue is not empty, pop the cell with the minimum effort.
- Iterate through the adjacent cells (up, down, left, right) and calculate the new effort required to reach each cell.
- If the new effort is less than the current minimum effort for that cell, update the minimum effort and push the cell into the priority queue.

3. **Return Minimum Effort:**

- Once the bottom-right cell is reached, return the minimum effort required to reach that cell.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(rows \* columns), as we visit each cell at most once in the worst case.
- **Expected Auxiliary Space Complexity:** O(rows \* columns), as we use a priority queue and a 2D array to store cell efforts.

### Code (C++)

```cpp
class Solution {
public:
    int MinimumEffort(int rows, int columns, std::vector<std::vector<int>>& heights) {
        std::priority_queue<std::pair<int,std::pair<int,int>>,
                            std::vector<std::pair<int,std::pair<int,int>>>,
                            std::greater<std::pair<int,std::pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == n - 1 && col == m - 1) {
                return diff;
            }

            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr < n && newr >= 0 && newc < m && newc >= 0) {
                    int neweffort = std::max(std::abs(heights[row][col] - heights[newr][newc]), diff);
                    if (neweffort < dist[newr][newc]) {
                        dist[newr][newc] = neweffort;
                        pq.push({dist[newr][newc], {newr, newc}});
                    }
                }
            }
        }
        return 0;
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
