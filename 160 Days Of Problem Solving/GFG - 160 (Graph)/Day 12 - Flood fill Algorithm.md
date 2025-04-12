---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Graph
  - Recursion
  - DFS
  - Matrix
---

# 🚀 _Day 12. Flood fill Algorithm_ 🧠


The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/flood-fill-algorithm1856)

## 💡 **Problem Description:**

You are given a 2D grid `image[][]` of size n×m, where each `image[i][j]` represents the color of a pixel in the image. You are also provided with a coordinate `(sr, sc)` representing the starting pixel (row and column) and a new color value `newColor`.  

Your task is to perform a **flood fill** starting from the pixel `(sr, sc)`, changing its color to `newColor` and also changing the color of all connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and share the same original color.

> **Note:** Sorry for the late upload, my Final Sem exam is going on.

## 🔍 **Example Walkthrough:**

### **Example 1:**  

#### **Input:**  
```
image[][] = [
  [1, 1, 1, 0],
  [0, 1, 1, 1],
  [1, 0, 1, 1]
]
sr = 1, sc = 2, newColor = 2
```  

<img src="https://github.com/user-attachments/assets/56ccec2d-ab19-4eea-91a7-e49a097c502e" width="40%">


#### **Output:**  
```
[
  [2, 2, 2, 0],
  [0, 2, 2, 2],
  [1, 0, 2, 2]
]
```  

<img src="https://github.com/user-attachments/assets/a0f61ed8-0207-4b66-90c9-4607f4e18e5c" width="40%">


#### **Explanation:**  
Starting from pixel `(1, 2)` with value `1`, the algorithm updates every 4-directionally connected pixel that has a value of `1` to `2`.


### **Example 2:**  

#### **Input:**  
```
image[][] = [
  [1, 1, 1],
  [1, 1, 0],
  [1, 0, 1]
]
sr = 1, sc = 1, newColor = 2
```  

#### **Output:**  
```
[
  [2, 2, 2],
  [2, 2, 0],
  [2, 0, 1]
]
```  

#### **Explanation:**  
Starting from the center pixel `(1, 1)` (with value `1`), all pixels connected by a path of the same color are changed to `2`. Note that the bottom right corner remains unchanged because it is not 4-directionally connected.


### **Example 3:**  

#### **Input:**  
```
image[][] = [
  [0, 1, 0],
  [0, 1, 0]
]
sr = 0, sc = 1, newColor = 0
```  

#### **Output:**  
```
[
  [0, 0, 0],
  [0, 0, 0]
]
```  

#### **Explanation:**  
Starting from pixel `(0, 1)` with value `1`, all its 4-directionally connected pixels with value `1` are updated to `0`.

### **Constraints:**  
- `1 ≤ n ≤ m ≤ 500`
- `0 ≤ image[i][j] ≤ 10`
- `0 ≤ newColor ≤ 10`
- `0 ≤ sr ≤ (n-1)`
- `0 ≤ sc ≤ (m-1)`
 

## 🎯 **My Approach:**

### **Flood Fill using BFS/DFS**

### **Algorithm Steps:**

1. **Identify the original color:** Determine the color of the starting pixel `(sr, sc)`.  
2. **Edge Case Check:** If the original color is the same as `newColor`, no changes are needed.  
3. **Traversal:**  
   - **BFS Approach:** Use a queue to perform a level-order traversal and update the color for every 4-directionally connected pixel that matches the original color.  
   - **DFS Approach (Recursive):** Use recursion to update connected pixels.
4. **Update Process:**  
   - For each pixel meeting the criteria, update its color to `newColor` and add its valid neighbors (up, down, left, right) to be processed next.
5. **Return the Updated Image:** After processing every eligible pixel, return the modified grid.


## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(n * m)`, as in the worst-case scenario, every pixel in the image is visited exactly once.
- **Expected Auxiliary Space Complexity:** `O(n * m)`, in the worst case the recursion call stack (or BFS queue) may store a significant fraction of the pixels if they are all connected.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& A, int sr, int sc, int nc) {
        int m = A.size(), n = A[0].size(), oc = A[sr][sc];
        if (oc == nc) return A;
        queue<pair<int, int>> q; q.push({sr, sc});
        A[sr][sc] = nc;
        int d[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i], ny = y + d[i+1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && A[nx][ny] == oc) {
                    A[nx][ny] = nc;
                    q.push({nx, ny});
                }
            }
        }
        return A;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ DFS-Based Flood Fill (Recursive)**

#### **Algorithm Steps:**

1. If the original color equals the new color, return the image.
2. Use recursion to fill all neighboring cells with the same color.
3. For each valid 4-directional neighbor, apply the fill operation recursively.

```cpp
class Solution {
public:
    void dfs(vector<vector<int>>& A, int x, int y, int oc, int nc) {
        if (x < 0 || y < 0 || x >= A.size() || y >= A[0].size() || A[x][y] != oc) return;
        A[x][y] = nc;
        dfs(A, x+1, y, oc, nc);
        dfs(A, x-1, y, oc, nc);
        dfs(A, x, y+1, oc, nc);
        dfs(A, x, y-1, oc, nc);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& A, int sr, int sc, int nc) {
        int oc = A[sr][sc];
        if (oc != nc)
            dfs(A, sr, sc, oc, nc);
        return A;
    }
};
```

## 📊 Time and Space Complexity

| Metric             | Value        |
|--------------------|--------------|
| 🕒 Time Complexity  | `O(m * n)`   |
| 🧠 Space Complexity | `O(m * n)` (recursive call stack) |

#### ✅ **Why This Approach?**

Recursive DFS is intuitive and easy to implement for grid-based problems. It works well for small to medium-sized images.


### 🆚 **Comparison of Approaches**

| **Approach**                     | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                              | ⚠️ **Cons**                              |
|------------------------------------|-------------------------|--------------------------|----------------------------------------------|-----------------------------------------------|
| **BFS (Queue)**                | 🟢 O`O(m * n)`                | 🟡 `O(m * n)`                 | Iterative, avoids recursion depth issues	 | Slightly more verbose      |
| **DFS (Recursive)**                | 🟢 O`O(m * n)`                | 🟡 `O(m * n)`                 | Intuitive, concise implementation	 | Risk of stack overflow on large inputs	      |


✅ **Best Choice?**
- Use BFS as the main method for better safety on large inputs.
- Use **DFS (Recursive)** for simpler problems and shorter DAGs.

</details>


## **Code (Java)**

```java
class Solution {
    public int[][] floodFill(int[][] A, int sr, int sc, int nc) {
        int m = A.length, n = A[0].length, oc = A[sr][sc];
        if (oc == nc) return A;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{sr, sc});
        A[sr][sc] = nc;
        int[] d = {-1, 0, 1, 0, -1};
        while (!q.isEmpty()) {
            int[] p = q.poll();
            for (int i = 0; i < 4; i++) {
                int x = p[0] + d[i], y = p[1] + d[i+1];
                if (x >= 0 && y >= 0 && x < m && y < n && A[x][y] == oc) {
                    A[x][y] = nc;
                    q.add(new int[]{x, y});
                }
            }
        }
        return A;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def floodFill(self, A, sr, sc, nc):
        m, n, oc = len(A), len(A[0]), A[sr][sc]
        if oc == nc: return A
        q = [(sr, sc)]
        A[sr][sc] = nc
        d = [-1, 0, 1, 0, -1]
        while q:
            x, y = q.pop(0)
            for i in range(4):
                nx, ny = x + d[i], y + d[i+1]
                if 0 <= nx < m and 0 <= ny < n and A[nx][ny] == oc:
                    A[nx][ny] = nc
                    q.append((nx, ny))
        return A
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
