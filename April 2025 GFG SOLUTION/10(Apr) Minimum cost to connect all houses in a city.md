# _10. Minimum cost to connect all houses in a city_ 

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-to-connect-all-houses-in-a-city/1)  


## **Problem Description:**

Given a **2D array `houses[][]`** of size `n`, where each subarray contains the `(x, y)` coordinates of a house, the goal is to **connect all houses** such that:

- Each house is connected to at least one other house.
- The **total cost of connecting all houses is minimized**.

The **cost** to connect two houses is the **Manhattan Distance**:
$\[
\text{Cost} = |x_1 - x_2| + |y_1 - y_2|
$\]

> **Note:** Sorry for uploading late, my Final Sem exam is going on.


## **Example:**

### **Example 1:**  

#### **Input:**  
```
n = 5  
houses[][] = [[0, 7], [0, 9], [20, 7], [30, 7], [40, 70]]
```

#### **Output:**  
```
105
```

#### **Explanation:**  
- Connect house 1 (0,7) and house 2 (0,9) with cost = 2  
- Connect house 1 (0,7) and house 3 (20,7) with cost = 20  
- Connect house 3 (20,7) and house 4 (30,7) with cost = 10  
- Connect house 4 (30,7) and house 5 (40,70) with cost = 73  
Overall minimum cost: 2 + 10 + 20 + 73 = 105.

<img src="https://github.com/user-attachments/assets/ef830f3f-5d6f-4300-ae9b-96681842dd2c" width="40%">

### **Example 2:**  

#### **Input:**  
```
n = 4  
houses[][] = [[0, 0], [1, 1], [1, 3], [3, 0]]
```

#### **Output:**  
```
7
```

#### **Explanation:**  
- Connect house 1 (0,0) and house 2 (1,1) with cost = 2  
- Connect house 2 (1,1) and house 3 (1,3) with cost = 2  
- Connect house 1 (0,0) and house 4 (3,0) with cost = 3  
Overall minimum cost: 2 + 2 + 3 = 7.

### **Constraints:**  
- $1 ≤ n ≤ 10^3$  
- $0 ≤ houses[i][j] ≤ 10^3$  

## **My Approach:**

### **Optimized Prim’s Algorithm**
1. **Overview:**  
   We use **Prim's algorithm** to compute the Minimum Spanning Tree (MST) of a complete graph where each node represents a house and the weight between two houses is their Manhattan distance.
   
2. **Algorithm Steps:**  
   - **Initialize:**  
     - Create an array `d` to store the minimum cost (distance) to connect each house; initialize with a large value (infinity), except for the first house set to 0.
     - Maintain an array `vis` to mark visited houses.
     
   - **Construct the MST:**  
     - Repeat for all houses:  
       - Select the house `u` not yet visited with the smallest cost `d[u]`.
       - Mark the house `u` as visited and add `d[u]` to the total cost.
       - Update the cost of reaching every other house `v` (not yet visited) as the minimum of its current cost and the Manhattan distance from house `u` to house `v`.
     
   - **Return the Total Cost:**  
     - After processing all houses, the total cost accumulated gives the minimum cost to connect all houses.

   
## **Time and Auxiliary Space Complexity**

   - **Expected Time Complexity:** O(n²), as for each of the n houses, we update distances for up to n houses.  
   - **Expected Auxiliary Space Complexity:** O(n), as we maintain two arrays (`d` and `vis`) of size n.


## **Code (C++)**

```cpp
class Solution {
  public:
    int minCost(vector<vector<int>>& a) {
        int n = a.size(), ans = 0, u = 0;
        vector<bool> vis(n);
        vector<int> d(n, 1e9);
        d[0] = 0;
        for (int i = 0; i < n; ++i) {
            int m = 1e9, idx = -1;
            for (int j = 0; j < n; ++j)
                if (!vis[j] && d[j] < m) m = d[j], idx = j;
            vis[idx] = 1;
            ans += m;
            for (int j = 0; j < n; ++j)
                if (!vis[j])
                    d[j] = min(d[j], abs(a[idx][0] - a[j][0]) + abs(a[idx][1] - a[j][1]));
        }
        return ans;
    }
};
```

## **Code (Java)**

```java
class Solution {
    public int minCost(int[][] a) {
        int n = a.length, ans = 0;
        boolean[] vis = new boolean[n];
        int[] d = new int[n];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[0] = 0;
        for (int i = 0; i < n; i++) {
            int m = Integer.MAX_VALUE, u = -1;
            for (int j = 0; j < n; j++)
                if (!vis[j] && d[j] < m) {
                    m = d[j];
                    u = j;
                }
            vis[u] = true;
            ans += m;
            for (int j = 0; j < n; j++)
                if (!vis[j])
                    d[j] = Math.min(d[j], Math.abs(a[u][0] - a[j][0]) + Math.abs(a[u][1] - a[j][1]));
        }
        return ans;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def minCost(self, a):
        n, ans = len(a), 0
        vis = [0]*n
        d = [float('inf')]*n
        d[0] = 0
        for _ in range(n):
            m, u = float('inf'), -1
            for i in range(n):
                if not vis[i] and d[i] < m:
                    m, u = d[i], i
            vis[u] = 1
            ans += m
            for v in range(n):
                if not vis[v]:
                    d[v] = min(d[v], abs(a[u][0] - a[v][0]) + abs(a[u][1] - a[v][1]))
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
