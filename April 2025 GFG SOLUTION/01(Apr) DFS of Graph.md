# _1. DFS of Graph_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1)

## **Problem Description**

Given a **connected undirected graph** represented by a **2D adjacency list `adj[][]`**, where `adj[i]` represents the list of vertices connected to vertex `i`.  
Perform a **Depth First Search (DFS) traversal** starting from **vertex 0**, visiting vertices from left to right as per the given adjacency list.

Return a list containing the **DFS traversal** of the graph.

**Note:** Traverse nodes in the same order as given in the adjacency list.

> Note: Sorry for uploading late, my exam is going on.

## **Examples**

### **Example 1:**

#### **Input:**

```
adj = [[2, 3, 1],
       [0],
       [0, 4],
       [0],
       [2]]
```

<img src="https://github.com/user-attachments/assets/5ab8ff7f-c58c-4035-9993-4de191cf627b" width="40%">

#### **Output:**

```
[0, 2, 4, 3, 1]
```

#### **Explanation:**

The DFS traversal proceeds as follows:

- **Start at vertex `0`** → Output: `[0]`
- **Visit `2` (first neighbor of `0`)** → Output: `[0, 2]`
- **Visit `4` (first neighbor of `2`)** → Output: `[0, 2, 4]`
- **Backtrack to `2`, then backtrack to `0`, visit `3`** → Output: `[0, 2, 4, 3]`
- **Backtrack to `0` and visit `1`** → Final Output: `[0, 2, 4, 3, 1]`

### **Example 2:**

#### **Input:**

```
adj = [[1, 2],
       [0, 2],
       [0, 1, 3, 4],
       [2],
       [2]]
```

<img src="https://github.com/user-attachments/assets/ab16fb62-988e-4cf6-be87-6aacb50fe9c5" width="40%">

#### **Output:**

```
[0, 1, 2, 3, 4]
```

#### **Explanation:**

The DFS traversal proceeds as follows:

- **Start at vertex `0`** → Output: `[0]`
- **Visit `1` (first neighbor of `0`)** → Output: `[0, 1]`
- **Visit `2` (first neighbor of `1`)** → Output: `[0, 1, 2]`
- **Visit `3` (first neighbor of `2`)** → Output: `[0, 1, 2, 3]`
- **Backtrack to `2` and visit `4`** → Final Output: `[0, 1, 2, 3, 4]`

## **Constraints:**

- $1 \leq$ `adj.size()` $\leq 10^4$
- $1 \leq$ `adj[i][j]` $\leq 10^4$

## **My Approach**

### **Recursive DFS (Using Lambda Function)**

### **Algorithm Steps:**

1. Maintain a **visited array** to track visited nodes.
2. Implement **DFS using recursion** and a **lambda function**.
3. Start DFS traversal from node `0` and recursively visit neighbors in the given order.
4. If a node is **unvisited**, continue DFS.
5. Store the **DFS traversal sequence** in a list.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(V + E), since each vertex and edge is visited once.
- **Expected Auxiliary Space Complexity:** O(V), as we store the visited array and recursive function calls.

## **Code (C++)**

```cpp
class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res, vis(V, 0);
        function<void(int)> traverse = [&](int v) {
            vis[v] = 1;
            res.push_back(v);
            for (int u : adj[v])
                if (!vis[u]) traverse(u);
        };
        for (int i = 0; i < V; i++)
            if (!vis[i]) traverse(i);
        return res;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Iterative DFS Approach (Using Stack)**

#### **Algorithm Steps:**

1. Use a **stack** to perform Depth-First Search iteratively.
2. For each unvisited vertex, push it to the stack and mark it visited.
3. Process the top element and push its unvisited neighbors in reverse order to maintain DFS order.
4. Repeat the process until the stack is empty.

```cpp
class Solution {
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                stack<int> st;
                st.push(i);
                while (!st.empty()) {
                    int v = st.top();
                    st.pop();
                    if (!vis[v]) {
                        vis[v] = true;
                        res.push_back(v);
                        for (int j = adj[v].size() - 1; j >= 0; j--) {
                            int u = adj[v][j];
                            if (!vis[u])
                                st.push(u);
                        }
                    }
                }
            }
        }
        return res;
    }
};
```

#### 📝 **Complexity Analysis:**

- ✅ **Time Complexity:** O(V + E) - Each vertex and edge are processed once.
- ✅ **Space Complexity:** O(V) - Due to the stack used in the iterative approach.

#### ✅ **Why This Approach?**

It eliminates the risk of stack overflow due to recursion, making it suitable for graphs with a large depth.

## 🔄 **3️⃣ Recursive DFS without Lambda (Traditional Approach)**

#### **Algorithm Steps:**

1. Use a helper function for recursion.
2. Start from an unvisited vertex, mark it as visited, and add to the result.
3. Recursively call the function for each unvisited neighbor.

```cpp
class Solution {
public:
    void dfsUtil(int v, vector<vector<int>>& adj, vector<int>& res, vector<bool>& vis) {
        vis[v] = true;
        res.push_back(v);
        for (int u : adj[v]) {
            if (!vis[u])
                dfsUtil(u, adj, res, vis);
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfsUtil(i, adj, res, vis);
        }
        return res;
    }
};
```

#### 📝 **Complexity Analysis:**

- ✅ **Time Complexity:** O(V + E) - Each vertex and edge are processed once.
- ✅ **Space Complexity:** O(V) - Due to the recursive call stack.

#### ✅ **Why This Approach?**

The traditional recursive approach is simple and intuitive, but it risks stack overflow for deep recursion.

### 🆚 **Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                                | ⚠️ **Cons**                                 |
| --------------------------- | ---------------------- | ----------------------- | ------------------------------------------ | ------------------------------------------- |
| Recursive DFS (Lambda)      | 🟢 O(V + E)            | 🟡 O(V)                 | Compact code with lambda functions         | Potential stack overflow for deep recursion |
| Iterative DFS (Stack)       | 🟢 O(V + E)            | 🟡 O(V)                 | No recursion issues, avoids stack overflow | Slightly more complex than recursive        |
| Recursive DFS (Traditional) | 🟢 O(V + E)            | 🟡 O(V)                 | Simple and intuitive recursive approach    | Risk of stack overflow for large graphs     |

✅ **Best Choice?**

- Use **Recursive DFS with Lambda** for compact and readable code when graph depth is manageable.
- Use **Iterative DFS** to avoid recursion issues when the graph has a large depth.
- The **Traditional Recursive DFS** is good for simple cases but should be avoided for deep recursion.

</details>

## **Code (Java)**

```java
class Solution {
    public ArrayList<Integer> dfs(ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> r = new ArrayList<>();
        boolean[] v = new boolean[adj.size()];
        for (int i = 0; i < adj.size(); i++) if (!v[i]) go(i, adj, v, r);
        return r;
    }
    void go(int i, ArrayList<ArrayList<Integer>> a, boolean[] v, ArrayList<Integer> r) {
        v[i] = true;
        r.add(i);
        for (int j : a.get(i)) if (!v[j]) go(j, a, v, r);
    }
}
```

## **Code (Python)**

```python
class Solution:
    def dfs(self, adj):
        r, v = [], [False] * len(adj)
        def go(i):
            v[i] = True
            r.append(i)
            for j in adj[i]:
                if not v[j]:
                    go(j)
        for i in range(len(adj)):
            if not v[i]:
                go(i)
        return r

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
