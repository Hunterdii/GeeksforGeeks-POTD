# _5. Find the Number of Islands_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1)

## **Problem Description**

Given a grid of size **n × m** consisting of `'W'` (Water) and `'L'` (Land), find the number of islands. An island is formed by connecting adjacent lands in any of the 8 directions (horizontally, vertically, or diagonally) and is surrounded by water or the grid boundary.

## **Examples**

#### **Example 1:**

**Input:**

```
grid[][] = [['L', 'L', 'W', 'W', 'W'],
            ['W', 'L', 'W', 'W', 'L'],
            ['L', 'W', 'W', 'L', 'L'],
            ['W', 'W', 'W', 'W', 'W'],
            ['L', 'W', 'L', 'L', 'W']]
```

**Output:**

```
4
```

**Explanation:**  
There are 4 distinct islands in the grid.

<img src="https://github.com/user-attachments/assets/c9f855fc-e60f-445b-845b-c18ce878613b" width="40%">

#### **Example 2:**

**Input:**

```
grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'],
            ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
```

**Output:**

```
2
```

**Explanation:**  
There are 2 islands in the grid.

<img src="https://github.com/user-attachments/assets/066b82cd-21a1-4403-9b2c-0025cd47bc30" width="40%">

### **Constraints:**

- $\(1 \leq n, m \leq 500\)$
- `grid[i][j]` ∈ {`'L'`, `'W'`}

## **My Approach**

### **DFS (Recursive Flood Fill – 8 Directions)**

We traverse the grid and whenever we find a land cell `'L'`, we start a **DFS flood fill** marking all connected lands.  
Each such initiation counts as **one island**.

### **Algorithm Steps:**

1. Traverse every cell in the grid.
2. If it's land ('L'), call a recursive DFS function to **flood fill all connected lands** in 8 directions.
3. Mark each visited land as `'W'`.
4. Count each DFS initiation as a distinct island.

### **Time and Auxiliary Space Complexity:**

- **Expected Time Complexity:** O(n × m), as each cell is processed once.
- **Expected Auxiliary Space Complexity:** O(n × m) in the worst-case scenario (e.g., when the grid is completely filled with land) due to the recursion stack or BFS/stack storage.

## **Code (C++)**

```cpp
class Solution{
public:
    int countIslands(vector<vector<char>>& g){
        int n = g.size(), m = g[0].size(), ans = 0;
        function<void(int,int)> f = [&](int i, int j){
            if(i < 0 || i >= n || j < 0 || j >= m || g[i][j] == 'W') return;
            g[i][j] = 'W';
            for(int a = -1; a <= 1; a++)
                for(int b = -1; b <= 1; b++)
                    f(i + a, j + b);
        };
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j] == 'L') { ans++; f(i, j); }
        return ans;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **1️⃣ BFS (Queue-based Flood Fill)**

#### **Algorithm Steps:**

1. Traverse each cell in the grid.
2. If the cell is land ('L'), initiate **Breadth-First Search (BFS)** from it.
3. Use a queue to explore connected land cells in 8 directions.
4. Mark all connected lands as visited by converting them to 'W'.
5. Count each BFS initiation as one island.

```cpp
class Solution {
public:
    int countIslands(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size(), ans = 0;
        vector<pair<int,int>> d = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 'L') {
                    ans++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i, j));
                    g[i][j] = 'W';
                    while(!q.empty()) {
                        pair<int,int> curr = q.front(); q.pop();
                        int x = curr.first, y = curr.second;
                        for(int k = 0; k < 8; k++) {
                            int nx = x + d[k].first, ny = y + d[k].second;
                            if(nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == 'L') {
                                g[nx][ny] = 'W';
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(N × M)`
- **Space Complexity:** `O(N × M)`

#### ✅ **Why This Approach?**

Efficient for large grids without risk of recursion stack overflow. It uses level-order traversal via queue, making it safer and iterative.

## 📊 **2️⃣ DFS (Iterative using Stack)**

#### **Algorithm Steps:**

1. Traverse the grid.
2. On encountering land ('L'), push it to a stack and start an iterative DFS.
3. Visit all adjacent lands, mark them visited.
4. Count each DFS initiation as an island.

```cpp
class Solution {
public:
    int countIslands(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size(), ans = 0;
        vector<pair<int,int>> d = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 'L') {
                    ans++;
                    stack<pair<int,int>> stk;
                    stk.push(make_pair(i, j));
                    g[i][j] = 'W';
                    while(!stk.empty()) {
                        pair<int,int> curr = stk.top(); stk.pop();
                        int x = curr.first, y = curr.second;
                        for(int k = 0; k < 8; k++) {
                            int nx = x + d[k].first, ny = y + d[k].second;
                            if(nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == 'L') {
                                g[nx][ny] = 'W';
                                stk.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(N × M)`
- **Space Complexity:** `O(N × M)`

#### ✅ **Why This Approach?**

Avoids recursion stack limit, yet still follows depth-first behavior. Useful when recursion is not feasible.

### 🆚 **Comparison of Approaches**

| **Approach**                     | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                              | ⚠️ **Cons**                              |
| -------------------------------- | ---------------------- | ----------------------- | ---------------------------------------- | ---------------------------------------- |
| **DFS (Recursive)**              | 🟢 O(N × M)            | 🟡 O(N × M)             | Short, clean, and expressive             | Risk of stack overflow on deep recursion |
| **BFS (Queue-based Flood Fill)** | 🟢 O(N × M)            | 🟡 O(N × M)             | No recursion issues, handles large grids | Slightly verbose code                    |
| **DFS (Iterative using Stack)**  | 🟢 O(N × M)            | 🟡 O(N × M)             | Avoids recursion limits, efficient       | Less elegant than recursive approach     |

✅ **Best Choice?**

- **Small to Medium Grid:** Prefer **DFS (Recursive)** for simplicity and elegance.
- **Large Grid:** Go for **BFS** or **Iterative DFS** to avoid recursion limits.

</details>

## **Code (Java)**

```java
class Solution{
    public int countIslands(char[][] g){
        int n = g.length, m = g[0].length, ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j]=='L'){ ans++; dfs(g, i, j, n, m); }
        return ans;
    }
    void dfs(char[][] g, int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || g[i][j]=='W') return;
        g[i][j] = 'W';
        for(int a = -1; a <= 1; a++)
            for(int b = -1; b <= 1; b++)
                dfs(g, i + a, j + b, n, m);
    }
}
```

## **Code (Python)**

```python
class Solution:
    def numIslands(self, g):
        n, m, ans = len(g), len(g[0]), 0
        def dfs(i, j):
            if i < 0 or j < 0 or i >= n or j >= m or g[i][j]=='W': return
            g[i][j] = 'W'
            for a in (-1,0,1):
                for b in (-1,0,1):
                    dfs(i+a, j+b)
        for i in range(n):
            for j in range(m):
                if g[i][j]=='L':
                    ans += 1
                    dfs(i, j)
        return ans
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
