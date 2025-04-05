## 02. Serialize and Deserialize a Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1)

### Problem Description

Serialize a binary tree means to store the tree in an array so that it can be later restored, and deserialize is the process of reconstructing the tree from the array. Implement the functions:

- `serialize()`: Stores the tree into an array and returns the array.
- `deserialize()`: Deserializes the array to the original tree and returns the root of it.

**Example:**

Input:

```
     1
   /   \
  2     3
```

Output:

```
2 1 3
```

Explanation: In-order traversal of the tree.

### My Approach

1. **Serialization:**

- Use a queue for level order traversal.
- Push each node's data into the array.
- If a node is NULL, push INT_MIN to indicate a NULL node.

2. **Deserialization:**

- Read data from the array and create nodes.
- Use a queue for level order traversal.
- Link nodes properly based on array values.

3. **Return:**

- Return the serialized or deserialized tree.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(N), where N is the number of nodes, as both serialization and deserialization traverse all nodes.
- **Expected Auxiliary Space Complexity:** O(N), as both serialization and deserialization use a queue for level order traversal and an array to store node values.

### Code (C++)

```cpp
class Solution {
public:
    //Function to serialize a tree and return an array containing nodes.
    void serializeUtil(Node *root, vector<int> &arr) {
        if (!root) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (curr) {
                arr.push_back(curr->data);
                q.push(curr->left);
                q.push(curr->right);
            } else {
                arr.push_back(INT_MIN);
            }
        }
    }

    vector<int> serialize(Node *root) {
        vector<int> arr;
        serializeUtil(root, arr);
        return arr;
    }

    //Function to deserialize an array and construct the tree.
    Node* deSerialize(vector<int> &A) {
        if (A.empty() || A[0] == INT_MIN) return NULL;

        Node* root = new Node(A[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < A.size()) {
            Node* curr = q.front();
            q.pop();

            if (i < A.size() && A[i] != INT_MIN) {
                curr->left = new Node(A[i]);
                q.push(curr->left);
            }
            i++;

            if (i < A.size() && A[i] != INT_MIN) {
                curr->right = new Node(A[i]);
                q.push(curr->right);
            }
            i++;
        }

        return root;
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
