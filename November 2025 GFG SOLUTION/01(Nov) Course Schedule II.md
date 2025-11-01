---
title: "🎓 Course Schedule II | GFG Solution 🔍"
keywords🏷️: ["🎓 course schedule", "📊 topological sort", "🔄 graph algorithms", "📍 kahn's algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Course Schedule II problem: find valid ordering of courses using topological sort with cycle detection. 🚀"
date: 📅 2025-11-01
---

# *01. Course Schedule II*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/course-schedule/1)

## **🧩 Problem Description**

You are given `n` courses, labeled from `0` to `n - 1` and a 2D array `prerequisites[][]` where `prerequisites[i] = [x, y]` indicates that we need to take course `y` first if we want to take course `x`.

Find the ordering of courses we should take to complete all the courses.

**Note:** There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. The Driver code will print `true` if you return any correct order of courses else it will print `false`.

## **📘 Examples**

### Example 1

```cpp
Input: n = 3, prerequisites[][] = [[1, 0], [2, 1]]
Output: true
Explanation: To take course 1, you must finish course 0. To take course 2, you must finish course 1. 
So the only valid order is [0, 1, 2].
```

### Example 2

```cpp
Input: n = 4, prerequisites[][] = [[2, 0], [2, 1], [3, 2]]
Output: true
Explanation: Course 2 requires both 0 and 1. Course 3 requires course 2. 
Hence, both [0, 1, 2, 3] and [1, 0, 2, 3] are valid.
```

## **🔒 Constraints**

* $1 \le n \le 10^4$
* $0 \le \text{prerequisites.size()} \le 10^5$
* $0 \le \text{prerequisites}[i][0], \text{prerequisites}[i][1] < n$
* All prerequisite pairs are unique
* $\text{prerequisites}[i][0] \ne \text{prerequisites}[i][1]$

## **✅ My Approach**

The optimal approach uses **Kahn's Algorithm** (BFS-based Topological Sort) to find a valid course ordering:

### **Kahn's Algorithm (BFS Topological Sort)**

1. **Build Graph:**
   * Create adjacency list representation where edge `[a, b]` means course `b` must be completed before course `a`.
   * Calculate in-degree (number of prerequisites) for each course.

2. **Initialize Queue:**
   * Add all courses with in-degree `0` (no prerequisites) to the queue.
   * These courses can be taken immediately.

3. **Process Courses:**
   * Remove a course from queue and add it to the result order.
   * For each dependent course, decrease its in-degree by 1.
   * If in-degree becomes 0, add it to the queue (all prerequisites satisfied).

4. **Cycle Detection:**
   * If the result contains all `n` courses, a valid ordering exists.
   * Otherwise, a cycle exists (impossible to complete all courses).

5. **Return Result:**
   * Return the complete ordering if valid, otherwise return an empty array.

## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(V + E), where V is the number of courses (vertices) and E is the number of prerequisite pairs (edges). Each course and prerequisite edge is processed exactly once during the BFS traversal.
* **Expected Auxiliary Space Complexity:** O(V + E), as we store the adjacency list (O(E) space for edges), in-degree array (O(V) space), queue (O(V) space in worst case), and result array (O(V) space).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for(auto& p : prerequisites) g[p[1]].push_back(p[0]), d[p[0]]++;
        queue<int> q;
        vector<int> r;
        for(int i = 0; i < n; i++) if(!d[i]) q.push(i);
        while(q.size()) {
            int u = q.front(); q.pop(); r.push_back(u);
            for(int v : g[u]) if(!--d[v]) q.push(v);
        }
        return r.size() == n ? r : vector<int>{};
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ DFS-Based Topological Sort**

### 💡 Algorithm Steps:

1. Build adjacency list from prerequisites for graph representation.
2. Use DFS with three states: unvisited (0), visiting (1), visited (2) to detect cycles.
3. Process nodes recursively and add to result after visiting all dependencies.
4. Reverse the result to get correct topological order.

```cpp
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        for(auto& p : prerequisites) g[p[1]].push_back(p[0]);
        vector<int> s(n), r;
        function<bool(int)> dfs = [&](int u) {
            if(s[u]) return s[u] == 2;
            s[u] = 1;
            for(int v : g[u]) if(!dfs(v)) return false;
            s[u] = 2; r.push_back(u);
            return true;
        };
        for(int i = 0; i < n; i++) if(!s[i] && !dfs(i)) return {};
        reverse(r.begin(), r.end());
        return r;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V + E) - Visit each vertex and edge once
* **Auxiliary Space:** 💾 O(V + E) - Recursion stack and adjacency list

### ✅ **Why This Approach?**

* Natural recursive structure for graph traversal
* Efficiently detects cycles during traversal
* Common pattern for topological sorting problems

## 📊 **3️⃣ Modified Kahn's with Priority Queue**

### 💡 Algorithm Steps:

1. Build graph and calculate in-degrees for all nodes.
2. Use priority queue to process nodes in lexicographically smallest order.
3. Remove nodes with zero in-degree and update neighbors.
4. Produce lexicographically smallest valid topological order.

```cpp
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for(auto& p : prerequisites) g[p[1]].push_back(p[0]), d[p[0]]++;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) if(!d[i]) pq.push(i);
        vector<int> r;
        while(!pq.empty()) {
            int u = pq.top(); pq.pop(); r.push_back(u);
            for(int v : g[u]) if(!--d[v]) pq.push(v);
        }
        return r.size() == n ? r : vector<int>{};
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V log V + E) - Priority queue operations add log factor
* **Auxiliary Space:** 💾 O(V + E) - Graph storage and priority queue

### ✅ **Why This Approach?**

* Produces lexicographically smallest ordering when multiple valid orders exist
* Useful when specific ordering preference is needed
* Extension of standard Kahn's algorithm

## 📊 **4️⃣ Post-Order DFS (Single Pass)**

### 💡 Algorithm Steps:

1. Create adjacency list representation of the graph.
2. Track visited nodes and detect cycles with color coding.
3. Use post-order traversal to naturally generate reverse topological order.
4. Return reversed result as final topological order.

```cpp
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        for(auto& p : prerequisites) g[p[1]].push_back(p[0]);
        vector<int> c(n), r;
        function<bool(int)> go = [&](int u) {
            c[u] = 1;
            for(int v : g[u]) 
                if(c[v] == 1 || (c[v] == 0 && !go(v))) return false;
            c[u] = 2; r.push_back(u);
            return true;
        };
        for(int i = 0; i < n; i++) if(!c[i] && !go(i)) return {};
        reverse(r.begin(), r.end());
        return r;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V + E) - Single pass through all vertices and edges
* **Auxiliary Space:** 💾 O(V + E) - Graph and recursion stack

### ✅ **Why This Approach?**

* Clean implementation with minimal state tracking
* Direct generation of topological order through post-order
* Elegant cycle detection integrated into traversal

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Kahn's (BFS)**              | 🟢 O(V + E)            | 🟢 O(V + E)             | 🚀 Iterative, easy to understand  | 💾 Queue overhead                    |
| 🌲 **DFS Topological**           | 🟢 O(V + E)            | 🟡 O(V + E)             | 📖 Natural recursive pattern      | 🔄 Requires reversing result         |
| 🎯 **Priority Queue BFS**        | 🟡 O(V log V + E)      | 🟢 O(V + E)             | ⭐ Lexicographic ordering         | 🐌 Slower due to heap operations     |
| 🔍 **Post-Order DFS**            | 🟢 O(V + E)            | 🟢 O(V + E)             | ✨ Clean cycle detection          | 🔧 Stack overflow on deep graphs     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Standard topological sort**                     | 🥇 **Kahn's BFS**                    | ★★★★★                     |
| 📖 **Recursive preference**                           | 🥈 **DFS Topological**               | ★★★★★                     |
| 🔧 **Specific ordering needed**                       | 🥉 **Priority Queue BFS**            | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Post-Order DFS**                | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> findOrder(int n, int[][] pre) {
        ArrayList<ArrayList<Integer>> g = new ArrayList<>();
        for (int i = 0; i < n; i++) g.add(new ArrayList<>());
        int[] d = new int[n];
        for (int[] p : pre) g.get(p[1]).add(p[0]); 
        for (int[] p : pre) d[p[0]]++;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) if (d[i] == 0) q.add(i);
        ArrayList<Integer> r = new ArrayList<>();
        while (!q.isEmpty()) {
            int u = q.poll(); r.add(u);
            for (int v : g.get(u)) if (--d[v] == 0) q.add(v);
        }
        return r.size() == n ? r : new ArrayList<>();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findOrder(self, n, prerequisites):
        g = [[] for _ in range(n)]
        d = [0] * n
        for a, b in prerequisites:
            g[b].append(a)
            d[a] += 1
        q = [i for i in range(n) if d[i] == 0]
        r = []
        while q:
            u = q.pop(0)
            r.append(u)
            for v in g[u]:
                d[v] -= 1
                if d[v] == 0: q.append(v)
        return r if len(r) == n else []
```

## 🧠 **Contribution and Support**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
