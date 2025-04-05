## 22. Diagonal Sum in Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1)

### Problem Description

Consider Red lines of slope -1 passing between nodes (in following diagram). The diagonal sum in a binary tree is the sum of all node datas lying between these lines. Given a Binary Tree of size n, print all diagonal sums.

For the following input tree, output should be 9, 19, 42.

- 9 is the sum of 1, 3, and 5.
- 19 is the sum of 2, 6, 4, and 7.
- 42 is the sum of 9, 10, 11, and 12.<br/>

![image](https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/e428bbff-72bd-4d27-806f-e26b429d70bb)

**Example 1:**

Input:

```
           10
         /    \
        8      2
       / \    /
      3   5  2
```

Output:

```
12 15 3
```

### My Approach

1. We traverse the binary tree using a level order traversal (BFS).
2. During traversal, we maintain a queue to keep track of nodes at each level.
3. For each node, we traverse its right children while adding their data to the sum of the diagonal.
4. We repeat this process for each level until the queue becomes empty.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(nlogn), where n is the number of nodes in the binary tree. This complexity arises from the level order traversal.
- **Expected Auxiliary Space Complexity:** O(n), where n is the number of nodes in the binary tree, for maintaining the queue during traversal.

### Code (C++)

```cpp
class Solution {
public:
    std::vector<int> diagonalSum(Node* root) {
        std::vector<int> result;
        if (root == nullptr) return result;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sum = 0;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();

                while (node) {
                    if (node->left) q.push(node->left);
                    sum += node->data;
                    node = node->right;
                }
            }
            result.push_back(sum);
        }

        return result;
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
