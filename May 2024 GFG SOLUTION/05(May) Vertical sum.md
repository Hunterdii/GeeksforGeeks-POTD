## 05. Vertical Sum

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/vertical-sum/1)

### Problem Description

Given a binary tree with \( n \) nodes, find the vertical sum of the nodes that are in the same vertical line. Return all sums through different vertical lines starting from the left-most vertical line to the right-most vertical line.

**Example:**

Input:

```
       1
    /    \
  2      3
 /  \    /  \
4   5  6   7
```

Output:

```
4 2 12 3 7
```

Explanation:
The tree has 5 vertical lines:

- Line 1 has only one node 4 => vertical sum is 4.
- Line 2 has only one node 2 => vertical sum is 2.
- Line 3 has three nodes: 1, 5, 6 => vertical sum is \( 1 + 5 + 6 = 12 \).
- Line 4 has only one node 3 => vertical sum is 3.
- Line 5 has only one node 7 => vertical sum is 7.

### My Approach

1. **Traversal:**

- Traverse the binary tree in level order using a queue.
- Maintain a map to store the vertical sums, where the keys represent the vertical positions and the values represent the sum of nodes at that position.

2. **Sum Calculation:**

- For each node encountered during traversal, update the sum in the map corresponding to its vertical position.

3. **Extract Sums:**

- After traversal, extract the sums from the map in order and store them in a vector.

4. **Return:**

- Return the vector containing the vertical sums.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(n \log n) \), as we traverse the binary tree in level order, which takes \( O(n) \) time, and building the map takes \( O(n \log n) \) time due to the insertion and sorting of keys.
- **Expected Auxiliary Space Complexity:** \( O(n) \), as we use a queue for level order traversal and a map to store the vertical sums.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> verticalSum(Node *root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        map<int, int> map; // Using map instead of unordered_map for sorted output
        queue<pair<Node*, int>> queue;
        queue.push({root, 0});

        while (!queue.empty()) {
            auto nodePair = queue.front();
            queue.pop();
            Node* node = nodePair.first;
            int position = nodePair.second;

            map[position] += node->data;

            if (node->left) {
                queue.push({node->left, position - 1});
            }

            if (node->right) {
                queue.push({node->right, position + 1});
            }
        }

        // Extract the sums in order
        for (auto& pair : map) {
            ans.push_back(pair.second);
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
