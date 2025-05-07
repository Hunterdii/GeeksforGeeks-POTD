# *7. Root to Leaf Paths*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1)

## **🧩 Problem Description**

Given a binary tree, find all the possible paths from the root node to all the leaf nodes.  
A leaf node is a node that does not have any children. The paths should be returned in such a way that the paths from the left subtree of any node are listed first, followed by paths from the right subtree.

### **Examples**

### **Example 1:**
#### **Input:**  
`root = [1, 2, 3, 4, 5, null, null]`

<img src="https://github.com/user-attachments/assets/4356f92f-1972-4974-a731-679e4edb5e54" width="30%">


#### **Output:**  
`[[1, 2, 4], [1, 2, 5], [1, 3]]`  
#### **Explanation:**  
All the possible paths from root node to leaf nodes are:  
- 1 → 2 → 4  
- 1 → 2 → 5  
- 1 → 3  

### **Example 2:**
#### **Input:**  
`root = [1, 2, 3]`  

<img src="https://github.com/user-attachments/assets/4ce0bea5-8f3f-45b1-b1c9-6e884ae65a5e" width="30%">


#### **Output:**  
`[[1, 2], [1, 3]]`  
#### **Explanation:**  
All the possible paths from root node to leaf nodes are:  
- 1 → 2  
- 1 → 3  

### **Example 3:**
#### **Input:**  
`root = [10, 20, 30, 40, 60, null, null]`  

<img src="https://github.com/user-attachments/assets/47c7bc9b-5884-4f34-9130-f9acda772b76" width="30%">


#### **Output:**  
`[[10, 20, 40], [10, 20, 60], [10, 30]]`  
#### **Explanation:**  
All the possible paths from root node to leaf nodes are:  
- 10 → 20 → 40  
- 10 → 20 → 60  
- 10 → 30  

## **🔒 Constraints**

- $1 \leq \text{number of nodes} \leq 10^4$
- $1 \leq \text{node->data} \leq 10^4$

## **✅ My Approach**

### **Depth-First Search (DFS)**

We can solve this problem using a Depth-First Search (DFS) approach. Starting from the root node, we traverse the tree recursively, maintaining the current path. If we reach a leaf node (a node with no left or right child), we add the current path to the result list.

### **Algorithm Steps:**

1. Initialize an empty list `res` to store the paths.
2. Define a recursive DFS function that:
   - Adds the current node's data to the current path.
   - If it's a leaf node (no left or right children), add the path to `res`.
   - Recursively call DFS on the left and right child.
   - Backtrack by removing the current node's data after exploring both subtrees.
3. Call the DFS function starting from the root.
4. Return `res`.

## **🧮 Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), where N is the total number of nodes in the tree. We visit each node once and perform constant-time operations (adding/removing from path) at each node.
- **Expected Auxiliary Space Complexity:** O(H) in the average case, where H is the height of the tree (stack space due to recursion). In the worst case (skewed tree), it can be O(N), where N is the number of nodes.

## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res, path;
        vector<int> curr;
        function<void(Node*)> dfs = [&](Node* n) {
            if (!n) return;
            curr.push_back(n->data);
            if (!n->left && !n->right) res.push_back(curr);
            else dfs(n->left), dfs(n->right);
            curr.pop_back();
        };
        dfs(root);
        return res;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ Iterative DFS using Stack**

### **Algorithm Steps:**
1. Use a stack storing tuples of (current node, current path).
2. On each iteration, if the node is a leaf, add the path to result.
3. Push right and left children with updated paths.

```cpp
class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        stack<pair<Node*, vector<int>>> st;
        st.push(make_pair(root, vector<int>{root->data}));
        while (!st.empty()) {
            pair<Node*, vector<int>> curr = st.top(); st.pop();
            Node* node = curr.first;
            vector<int> path = curr.second;
            if (!node->left && !node->right) {
                res.push_back(path);
            }
            if (node->right) {
                vector<int> rightPath = path;
                rightPath.push_back(node->right->data);
                st.push(make_pair(node->right, rightPath));
            }
            if (node->left) {
                vector<int> leftPath = path;
                leftPath.push_back(node->left->data);
                st.push(make_pair(node->left, leftPath));
            }
        }
        return res;
    }
};
```

### ✅ **Why This Approach?**
- Avoids recursion overhead.
- Handles deep trees better if stack size is a concern.

#### 📝 **Complexity Analysis:**
- **Expected Time Complexity:** O(N)
- **Expected Auxiliary Space Complexity:** O(H) in average case, O(N) worst case (stack and path copies)


### 🆚 **Comparison of Approaches**

| **Approach**             | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                              | ⚠️ **Cons**                         |
|--------------------------|-------------|--------------|------------------------------------------|-------------------------------------|
| Recursive DFS     | 🟢 O(N)      | 🟢 O(H)       | Clean, simple, tail-recursive friendly   | Recursion stack risk on deep trees  |
| Iterative DFS (stack)    | 🟢 O(N)      | 🟠 O(N)       | No recursion limit, depth control        | Slightly more verbose               |


### ✅ **Best Choice?**

| **Scenario**                            | **Recommended Approach**     |
|-----------------------------------------|------------------------------|
| ✅ Concise, clean implementation         | 🥇 Recursive DFS             |
| ✅ Avoid recursion stack                | 🥈 Iterative DFS (stack)     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public static ArrayList<ArrayList<Integer>> Paths(Node r) {
        var res = new ArrayList<ArrayList<Integer>>();
        var curr = new ArrayList<Integer>();
        dfs(r, res, curr);
        return res;
    }
    static void dfs(Node n, ArrayList<ArrayList<Integer>> res, ArrayList<Integer> curr) {
        if (n == null) return;
        curr.add(n.data);
        if (n.left == null && n.right == null) res.add(new ArrayList<>(curr));
        else {
            dfs(n.left, res, curr);
            dfs(n.right, res, curr);
        }
        curr.remove(curr.size() - 1);
    }
}
```


## 🐍 **Code (Python)**

```python
class Solution:
    def Paths(self, root):
        res, curr = [], []
        def dfs(n):
            if not n: return
            curr.append(n.data)
            if not n.left and not n.right:
                res.append(curr.copy())
            else:
                dfs(n.left); dfs(n.right)
            curr.pop()
        dfs(root)
        return res
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
