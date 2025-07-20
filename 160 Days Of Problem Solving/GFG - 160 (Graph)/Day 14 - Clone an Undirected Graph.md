---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Graph
  - BFS
  - DFS
---

# 🚀 _Day 14. Clone an Undirected Graph_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/clone-graph)

## 💡 **Problem Description:**

Given a connected undirected graph represented by an adjacency list, `adjList[][]`, with **n** nodes (each node having a distinct label from `0` to `n-1`), your task is to create a **clone** (deep copy) of this graph. Each node in the graph has:

- An integer `val`
- A list `neighbors` containing references to its adjacent nodes

### **Structure**

```cpp
class Node {
    int val;
    List<Node> neighbors;
}
```

Return a reference to the cloned graph such that the cloned graph is identical to the original graph. The driver code will then print `true` if the clone is correct; otherwise it prints `false`.

> Note: Sorry for uploading late, my Final Sem exam is going on.

## 🔍 **Example Walkthrough:**

### **Example 1**

#### **Input:**

n = 4  
adjList = [[1, 2], [0, 2], [0, 1, 3], [2]]

#### **Output:**

true

#### **Explanation:**

<img src="https://github.com/user-attachments/assets/eae32789-2302-42bd-83b5-f58a871493ed" width="30%">

The cloned graph is structurally identical to the original. Driver code checks memory and structure integrity.

### **Example 2**

#### **Input:**

n = 3  
adjList = [[1, 2], [0], [0]]

#### **Output:**

true

#### **Explanation:**

<img src="https://github.com/user-attachments/assets/d248652e-0938-42d1-aad7-8711530cf356" width="30%">

The cloned graph is identical to the original one, hence driver code outputs true.

### **Constraints**

- $\( 1 \leq n \leq 10^4 \)$
- $\( 0 \leq \text{number of edges} \leq 10^5 \)$
- $\( 0 \leq \text{adjList[i][j]} < n \)$

## 🎯 **My Approach:**

### **BFS-Based Graph Clone using Queue**

### **Algorithm Steps:**

1. **Initialization:**

   - If the starting node is `null`, return `null`.
   - Create a hash map (or dictionary) to store mappings from each original node to its clone.
   - Initialize a queue and enqueue the starting node.

2. **BFS Traversal:**
   - While the queue is not empty:
     - Dequeue the front node.
     - For each neighbor of the dequeued node:
       - If the neighbor hasn't been cloned (i.e., not present in the map), create its clone, store it in the map, and enqueue the neighbor.
       - Append the clone of the neighbor to the `neighbors` list of the clone corresponding to the current node.
3. **Return:**
   - After processing all nodes, return the clone corresponding to the starting node.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N + M)`, where `N` is the number of nodes and `M` is the number of edges. We visit each node and edge exactly once during the clone.
- **Expected Auxiliary Space Complexity:** `O(N)`, used by the hash map and the queue.

## 📝 **Solution Code**

## Code (C++)

```cpp
// ✅ BFS-Based Graph Clone using Queue
class Solution {
  public:
    Node* cloneGraph(Node* node) {
        if (!node) return 0;
        unordered_map<Node*, Node*> m;
        m[node] = new Node(node->val);
        queue<Node*> q{{node}};
        while (!q.empty()) {
            for (auto n : q.front()->neighbors) {
                if (!m[n]) q.push(n), m[n] = new Node(n->val);
                m[q.front()]->neighbors.push_back(m[n]);
            }
            q.pop();
        }
        return m[node];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ DFS-Based Clone (Recursive)**

#### **Algorithm Steps:**

1. Use a `map<Node*, Node*>` to keep track of original → clone mappings.
2. Recursively visit each neighbor and clone them.
3. Return the cloned node after recursively linking its neighbors.

```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> m;
        return dfs(node, m);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& m) {
        if (m.count(node)) return m[node];
        Node* clone = new Node(node->val);
        m[node] = clone;
        for (Node* neighbor : node->neighbors)
            clone->neighbors.push_back(dfs(neighbor, m));
        return clone;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(N + M)` — Each node and edge visited once.
- **Space Complexity:** `O(N)` — For hashmap and recursion stack.

#### ✅ **Why This Approach?**

Very elegant and simple implementation that leverages recursion, suitable for medium-size graphs.

## 📊 **3️⃣ DFS-Based Clone (Iterative using Stack)**

#### **Algorithm Steps:**

1. Use a stack to simulate DFS traversal.
2. Maintain a `map<Node*, Node*>` for cloning references.
3. Clone each unvisited neighbor during traversal.
4. Append the neighbors to the corresponding clone.

```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> m;
        stack<Node*> st;
        st.push(node);
        m[node] = new Node(node->val);

        while (!st.empty()) {
            Node* curr = st.top(); st.pop();
            for (auto neighbor : curr->neighbors) {
                if (!m.count(neighbor)) {
                    m[neighbor] = new Node(neighbor->val);
                    st.push(neighbor);
                }
                m[curr]->neighbors.push_back(m[neighbor]);
            }
        }
        return m[node];
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(N + M)` — Visit every node and edge once.
- **Space Complexity:** `O(N)` — Hashmap and stack.

#### ✅ **Why This Approach?**

Avoids recursion and risk of stack overflow. Ideal when recursion depth is a limitation.

### 🆚 **Comparison of Approaches**

| **Approach**                    | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                | ⚠️ **Cons**                           |
| ------------------------------- | ---------------------- | ----------------------- | -------------------------- | ------------------------------------- |
| **BFS (Queue + Map)**           | 🟡 O(N + M)            | 🟢 O(N)                 | Iterative, clean traversal | Slightly more space for queue         |
| **DFS (Recursive)**             | 🟡 O(N + M)            | 🟢 O(N)                 | Concise and elegant        | Risk of stack overflow on deep graphs |
| **DFS (Iterative using Stack)** | 🟡 O(N + M)            | 🟢 O(N)                 | Avoids recursion limit     | More verbose and a bit complex        |

✅ **Best Choice?**

- Use **BFS** for queue-based iterative style and easier debugging.
- Prefer **Recursive DFS** for elegance, unless you're dealing with very deep or cyclic graphs.
- Choose **Iterative DFS** if recursion depth is a concern or restricted.

</details>

## Code (Java)

```java
class Solution {
    Node cloneGraph(Node node) {
        if (node == null) return null;
        Map<Node, Node> m = new HashMap<>();
        Queue<Node> q = new LinkedList<>();
        m.put(node, new Node(node.val));
        q.add(node);
        while (!q.isEmpty()) {
            for (Node n : q.peek().neighbors) {
                if (!m.containsKey(n)) {
                    m.put(n, new Node(n.val));
                    q.add(n);
                }
                m.get(q.peek()).neighbors.add(m.get(n));
            }
            q.poll();
        }
        return m.get(node);
    }
}
```

## Code (Python)

```python
class Solution:
    def cloneGraph(self, node):
        if not node: return None
        m, q = {node: Node(node.val)}, [node]
        while q:
            for n in q[0].neighbors:
                if n not in m:
                    m[n] = Node(n.val)
                    q.append(n)
                m[q[0]].neighbors.append(m[n])
            q.pop(0)
        return m[node]
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" />
</p>
