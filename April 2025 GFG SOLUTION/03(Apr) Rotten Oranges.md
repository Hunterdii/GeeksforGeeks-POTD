# _3. Rotten Oranges_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/rotten-oranges2536/1)

## **Problem Statement**

Given a **matrix** `mat[][]` of size **n × m**, where each cell in the matrix can contain:

- **0** → Empty cell
- **1** → Fresh orange
- **2** → Rotten orange

A **rotten orange** at position `(i, j)` can rot adjacent fresh oranges **(up, down, left, right)** in **one unit of time**. The task is to find the **minimum time required** to rot all fresh oranges. If it's **impossible** to rot all oranges, return **-1**.

## **Examples**

### **Example 1:**

#### **Input:**

```
mat[][] = [
  [0, 1, 2],
  [0, 1, 2],
  [2, 1, 1]
]
```

#### **Output:**

```
1
```

#### **Explanation:**

Oranges at positions `(0,2)`, `(1,2)`, and `(2,0)` will rot adjacent oranges in **one unit of time**.

### **Example 2:**

#### **Input:**

```
mat[][] = [[2, 2, 0, 1]]
```

#### **Output:**

```
-1
```

#### **Explanation:**

Oranges at `(0,0)` and `(0,1)` **cannot** rot the orange at `(0,3)`, so it's **impossible**.

### **Example 3:**

#### **Input:**

```
mat[][] = [
  [2, 2, 2],
  [0, 2, 0]
]
```

#### **Output:**

```
0
```

#### **Explanation:**

There are **no fresh oranges**, so the answer is **0**.

## **Constraints**

- $1 \leq n, m \leq 500$
- $1 ≤ mat[0].size() ≤ 500$
- `mat[i][j]` ∈ {0, 1, 2}

## **My Approach:**

### **Single Queue (BFS)**

### **Algorithm Steps:**

1. **Multi-source BFS:**
   - Traverse the matrix to push all rotten orange coordinates into a queue.
   - Also, count the number of fresh oranges.
2. **Level-by-Level Processing:**
   - For each time unit, process all the oranges in the queue.
   - For each rotten orange, try to rot its adjacent fresh oranges (up, down, left, right).
   - If at least one orange is rotted during that level, increment the time counter.
3. **Termination:**
   - If after the BFS there are still fresh oranges left, return **-1**.
   - Otherwise, return the total time elapsed.

### **Rotten Oranges: Minimum Time to Rot All Oranges**

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** $\(O(n \times m)\)$, since each cell (orange) in the mat is processed at most once during the BFS traversal.
- **Expected Auxiliary Space Complexity:** $\(O(n \times m)\)$, as in the worst case, the queue may contain all the cells simultaneously.

## **Code (C++)**

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), t = 0, f = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j] == 2) q.push({i, j});
                else if(a[i][j] == 1) f++;
            }
        if(!f) return 0;
        int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int sz = q.size();
            bool ch = false;
            while(sz--){
                auto p = q.front(); q.pop();
                int i = p.first, j = p.second;
                for(auto &dir : d){
                    int x = i + dir[0], y = j + dir[1];
                    if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] != 1) continue;
                    a[x][y] = 2; q.push({x,y}); f--; ch = true;
                }
            }
            if(ch) t++;
        }
        return f ? -1 : t;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ BFS Using Two Queues (Level Separation) Approach**

#### **Algorithm Steps:**

1. Use **two queues**: one for the current level and one for the next level.
2. Process all rotten oranges from the current level, adding newly rotten oranges to the next level.
3. Swap the queues and increment the time until no fresh oranges remain.

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), t = 0, f = 0;
        queue<pair<int,int>> curr, next;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j] == 2) curr.push({i, j});
                else if(a[i][j] == 1) f++;
            }
        if(!f) return 0;
        int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!curr.empty()){
            bool changed = false;
            while(!curr.empty()){
                auto p = curr.front(); curr.pop();
                int i = p.first, j = p.second;
                for(auto &dir : d){
                    int x = i + dir[0], y = j + dir[1];
                    if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] != 1) continue;
                    a[x][y] = 2; next.push({x,y}); f--; changed = true;
                }
            }
            if(changed) t++;
            swap(curr, next);
        }
        return f ? -1 : t;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(n * m)`
- **Space Complexity:** `O(n * m)`

#### ✅ **Why This Approach?**

It clearly separates levels by using two queues, making the progression of time explicit.

## 🔄 **3️⃣ BFS In-Place Level Tracking Approach**

#### **Algorithm Steps:**

1. Use a single queue with a marker (e.g., `{-1, -1}`) to denote the end of a level.
2. Process elements until the marker is reached, then increment the time and add a new marker if the queue isn’t empty.

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), t = 0, f = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j] == 2) q.push({i, j});
                else if(a[i][j] == 1) f++;
            }
        if(!f) return 0;
        q.push({-1, -1});
        int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            auto p = q.front(); q.pop();
            if(p.first == -1) {
                if(q.empty()) break;
                t++;
                q.push({-1, -1});
                continue;
            }
            int i = p.first, j = p.second;
            for(auto &dir : d){
                int x = i + dir[0], y = j + dir[1];
                if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] != 1) continue;
                a[x][y] = 2; q.push({x,y}); f--;
            }
        }
        return f ? -1 : t;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(n * m)`
- **Space Complexity:** `O(n * m)`

#### ✅ **Why This Approach?**

It avoids extra queues by using a marker to track levels, keeping the implementation concise while still tracking time accurately.

## 🚀 **4️⃣ BFS with Time Matrix Approach**

#### **Algorithm Steps:**

1. Use multi-source BFS from all rotten oranges simultaneously.
2. Maintain a separate **time matrix** that records the time at which each fresh orange becomes rotten.
3. Update the time matrix as you process each cell and track the maximum time required.

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), f = 0;
        vector<vector<int>> time(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if(a[i][j] == 2)
                    q.push({i, j});
                else if(a[i][j] == 1)
                    f++;
            }
        if(!f) return 0;
        int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}, ans = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            for(auto &dir : d){
                int x = i + dir[0], y = j + dir[1];
                if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] != 1) continue;
                a[x][y] = 2;
                time[x][y] = time[i][j] + 1;
                ans = max(ans, time[x][y]);
                q.push({x,y});
                f--;
            }
        }
        return f ? -1 : ans;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(n * m)`
- **Space Complexity:** `O(n * m)`

#### ✅ **Why This Approach?**

It records the exact time at which each orange becomes rotten, which can be beneficial for debugging or extended analysis.

### 🆚 **Comparison of Approaches**

| **Approach**                         | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                                                                               | ⚠️ **Cons**                                                    |
| ------------------------------------ | ---------------------- | ----------------------- | ----------------------------------------------------------------------------------------- | -------------------------------------------------------------- |
| **Main Approach (Single Queue BFS)** | 🟢 O(n \* m)           | 🟡 O(n \* m)            | Simple, optimal runtime; processes all rotten oranges simultaneously.                     | Level tracking is less explicit compared to some alternatives. |
| **BFS Using Two Queues**             | 🟢 O(n \* m)           | 🟡 O(n \* m)            | Clear separation of levels; intuitive time progression.                                   | Requires managing two separate queues.                         |
| **BFS In-Place Level Tracking**      | 🟢 O(n \* m)           | 🟡 O(n \* m)            | Uses a single queue with a marker; concise and space-efficient.                           | Marker-based approach might be less intuitive for beginners.   |
| **BFS with Time Matrix**             | 🟢 O(n \* m)           | 🟡 O(n \* m)            | Provides explicit time records for each cell; useful for detailed analysis and debugging. | Additional space is required for the time matrix.              |

✅ **Best Choice?**

- The **Main Approach (Single Queue BFS)** is optimal in runtime and is widely used due to its simplicity and efficiency.
- **BFS Using Two Queues** and **BFS In-Place Level Tracking** are both excellent alternatives that provide clear level separation and concise implementations, respectively.
- **BFS with Time Matrix** is ideal when detailed timing information per cell is required.

</details>

## **Code (Java)**

```java
class Solution {
    public int orangesRotting(int[][] a) {
        int n = a.length, m = a[0].length, f = 0, t = 0;
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 2)
                    q.add(new int[]{i, j});
                else if (a[i][j] == 1)
                    f++;
            }
        if (f == 0) return 0;
        int[][] d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.isEmpty()) {
            int sz = q.size();
            boolean ch = false;
            for (int k = 0; k < sz; k++) {
                int[] p = q.poll();
                int i = p[0], j = p[1];
                for (int[] dir : d) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] != 1)
                        continue;
                    a[x][y] = 2;
                    q.add(new int[]{x, y});
                    f--;
                    ch = true;
                }
            }
            if (ch) t++;
        }
        return f == 0 ? t : -1;
    }
}
```

## **Code (Python)**

```python
from collections import deque
class Solution:
    def orangesRotting(self, a):
        n, m, f, t = len(a), len(a[0]), 0, 0
        q = deque()
        for i in range(n):
            for j in range(m):
                if a[i][j] == 2:
                    q.append((i, j))
                elif a[i][j] == 1:
                    f += 1
        if not f: return 0
        d = [(1,0),(-1,0),(0,1),(0,-1)]
        while q:
            sz, ch = len(q), False
            for _ in range(sz):
                i, j = q.popleft()
                for di, dj in d:
                    x, y = i + di, j + dj
                    if x < 0 or y < 0 or x >= n or y >= m or a[x][y] != 1:
                        continue
                    a[x][y] = 2
                    q.append((x, y))
                    f -= 1
                    ch = True
            if ch: t += 1
        return t if f == 0 else -1
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
