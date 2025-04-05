## 07. Reverse Level Order Traversal

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/reverse-level-order-traversal/1)

### Problem Description

Given a binary tree, find its reverse level order traversal, starting from the last level.

**Example:**

Input:

```
        1
      /   \
     3     2
```

Output:

```
3 2 1
```

Explanation:
Traversing level 1: 3 2
Traversing level 0: 1

Input:

```
       10
      /  \
     20   30
    / \
   40  60
```

Output:

```
40 60 20 30 10
```

Explanation:
Traversing level 2: 40 60
Traversing level 1: 20 30
Traversing level 0: 10

### My Approach

1. **Initialization:**

- Initialize an empty vector `ans` to store the reverse level order traversal.

2. **BFS Traversal:**

- Perform a Breadth First Search (BFS) traversal of the binary tree.
- Use a queue to keep track of nodes at each level.
- Pop nodes from the queue and push their children (if any) into the queue.
- Record the data of popped nodes into the `ans` vector.

3. **Reverse the Result:**

- Reverse the `ans` vector to obtain the reverse level order traversal.

4. **Return:**

- Return the `ans` vector containing the reverse level order traversal.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where \(n\) is the number of nodes in the binary tree. We visit each node once during the BFS traversal.
- **Expected Auxiliary Space Complexity:** O(n), as the space required by the queue can be at most the number of nodes at the maximum level of the binary tree.

### Code (C++)

```cpp
vector<int> reverseLevelOrder(Node *root) {
    vector<int> ans;
    if (!root)
        return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();
            ans.push_back(current->data);

            if (current->right)
                q.push(current->right);
            if (current->left)
                q.push(current->left);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
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
