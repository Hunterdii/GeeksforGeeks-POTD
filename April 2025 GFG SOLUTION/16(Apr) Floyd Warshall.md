# *16. Floyd Warshall*

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1)

## **Problem Description**

You are given a weighted directed graph represented by an adjacency matrix `dist[][]` of size `n x n`, where `dist[i][j]` represents the weight of the edge from node `i` to node `j`. If there is no direct edge, `dist[i][j]` is set to a large value (e.g., `10^8`) representing infinity.  
The graph may contain negative edge weights, but it does not contain any negative weight cycles.

Your task is to compute the shortest distance between every pair of nodes `(i, j)` by modifying the distances in-place.

> **Note:** Sorry for uploading late, my Final Sem exam is going on.

## **Examples**

### **Example 1:**



![image](https://github.com/user-attachments/assets/e750580e-9c59-4f63-ab48-83f07fa539dc)

#### **Output:**  
```
[
  [0, 4, 5, 5, 7],
  [3, 0, 1, 4, 6],
  [2, 6, 0, 3, 5],
  [3, 7, 1, 0, 2],
  [1, 5, 5, 4, 0]
]
```

![image](https://github.com/user-attachments/assets/825f4e9d-bcde-41ca-9bb9-4d90cb61b13f)

#### **Explanation:**  
Each cell `dist[i][j]` in the output shows the shortest distance from node `i` to node `j`, computed by considering all possible intermediate nodes.


### **Example 2:**

#### **Input:**  

![image](https://github.com/user-attachments/assets/7db4430b-778a-4af9-9575-c96e52ffbab3)


#### **Output:**  
```
[
  [0, -1, 2],
  [1,  0, 3],
  [2,  1, 0]
]
```

![image](https://github.com/user-attachments/assets/843da9c7-dc96-4603-bd44-4b670d8fb80f)

#### **Explanation:**  
- The shortest path from node `2` to node `0` is via node `1` (i.e., `2 -> 1 -> 0`), which gives a distance of `2`.  
- Similarly, the shortest path from node `1` to node `2` is `1 -> 0 -> 2`, with a total cost of `3`.


### **Constraints:**

- $\(1 \leq \text{dist.size()} \leq 100\)$
- $\(-1000 \leq \text{dist}[i][j] \leq 1000\)$
- If there is no edge between two nodes, the weight is given as a large value (e.g., `10^8`) representing infinity.


## **My Approach**

### **Floyd Warshall**
1. **Concept:**  
   - The algorithm considers every node as an intermediate vertex and updates the distance between every pair of nodes (i, j) if including an intermediate node \( k \) yields a smaller path.
   
2. **Algorithm Steps:**
   - For every intermediate node `k` from `0` to `n-1`:
     - For each source node `i` from `0` to `n-1`:
       - For each destination node `j` from `0` to `n-1`:
         - If the path from `i` to `j` can be minimized by passing through `k` (i.e., if `d[i][j] > d[i][k] + d[k][j]`), then update `d[i][j]`.
  
## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** **O(n³)**, due to the triple nested loop over \( n \) nodes.

- **Expected Auxiliary Space Complexity:** **O(1)**, as we update the matrix in-place and only use a few additional variables.




## **Code (C++)**

```cpp
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &d) {
        int n = d.size(), inf = 1e8;
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (d[i][k] < inf && d[k][j] < inf && d[i][j] > d[i][k] + d[k][j])
                        d[i][j] = d[i][k] + d[k][j];
    }
};
```

## **Code (Java)**

```java
class Solution {
    public void floydWarshall(int[][] d) {
        int n = d.length, inf = 100000000;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (d[i][k] < inf && d[k][j] < inf && d[i][j] > d[i][k] + d[k][j])
                        d[i][j] = d[i][k] + d[k][j];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def floydWarshall(self, d):
        n, inf = len(d), 100000000
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if d[i][k] < inf and d[k][j] < inf and d[i][j] > d[i][k] + d[k][j]:
                        d[i][j] = d[i][k] + d[k][j]
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
