## 21. Zigzag Tree Traversal

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1)

### Problem Description

Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

**Example:**

Input:

```
        1
      /   \
     2    3
    / \    /   \
   4   5 6   7
```

Output:

```
1 3 2 4 5 6 7
```

### My Approach

1. **Initialization:**

   - Start with an empty vector `ans` to store the zig-zag level order traversal.
   - Check if the given binary tree is empty, if so, return the empty vector.

2. **Traversal Process:**

   - Use a queue to perform level-order traversal of the binary tree.
   - Maintain a boolean variable `leftToRight` to keep track of the direction of traversal.

3. **Level-wise Traversal:**

   - While traversing each level:
     - Initialize a vector `res` to store the node values at the current level.
     - For each node in the current level:
       - Pop the front node from the queue.
       - Depending on the value of `leftToRight`, insert the node value at the appropriate index in `res`.
       - Enqueue the left and right child nodes of the current node if they exist.

4. **Direction Reversal:**

   - After processing each level, toggle the value of `leftToRight` to reverse the traversal direction.

5. **Append to Result:**

   - After processing all levels, append the elements of `res` to the `ans` vector.

6. **Return Result:**
   - Finally, return the `ans` vector containing the zig-zag level order traversal.

**Constraints:**

- 1 <= n <= 10^5

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we visit each node once during the level-order traversal.
- **Expected Auxiliary Space Complexity:** O(n), where n is the number of nodes in the binary tree, for storing the queue and the result.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;

        if (root == nullptr) {
            return ans;
        }

        bool leftToRight = true;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> res(size);

            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                res[index] = frontNode->data;

                if (frontNode->left) {
                    q.push(frontNode->left);
                }

                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            leftToRight = !leftToRight;

            for (int val : res) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
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
