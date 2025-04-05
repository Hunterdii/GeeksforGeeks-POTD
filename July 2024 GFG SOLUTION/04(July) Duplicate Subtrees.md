## 04. Duplicate Subtrees

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/duplicate-subtrees/1)

### Problem Description

Given a binary tree, your task is to find all duplicate subtrees from the given binary tree.

**Duplicate Subtree:** Two trees are duplicates if they have the same structure with the same node values.

**Note:** Return the root of each duplicate subtree in the form of a list array. The driver code will print the tree in pre-order traversal in lexicographically increasing order.

**Examples:**

Input:

```
        5
       / \
      4   6
     / \
    3   4
       / \
      3   6
```

Output:

```
3
6
```

Explanation: In the above tree, there are two duplicate subtrees: 3 and 6.

### My Approach

1. **Helper Function:**

   - Define a helper function that serializes each subtree into a string format.
   - Use a map to count the occurrences of each serialized subtree.

2. **Traversal and Serialization:**

   - Traverse the tree using post-order traversal to serialize each subtree.
   - If a serialized subtree has been seen exactly once before, add the root of this subtree to the result list.

3. **Return:**
   - Return the list of roots of all duplicate subtrees.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the entire tree once.
- **Expected Auxiliary Space Complexity:** O(n), as we use a map to store the serialized subtrees and a list to store the result.

### Code (C++)

```cpp
class Solution {
public:
    string helper(Node* root, vector<Node*>& ans, unordered_map<string, int>& m) {
        if (!root) {
            return "#";
        }
        string left = helper(root->left, ans, m);
        string right = helper(root->right, ans, m);
        string node = to_string(root->data) + "," + left + "," + right;

        if (m[node] == 1) {
            ans.push_back(root);
        }
        m[node]++;
        return node;
    }

    vector<Node*> printAllDups(Node* root) {
        vector<Node*> ans;
        unordered_map<string, int> m;
        helper(root, ans, m);
        return ans;
    }
};
```

### Code (Java)

```java
class Solution {
    private String helper(Node root, List<Node> ans, Map<String, Integer> m) {
        if (root == null) {
            return "#";
        }
        String left = helper(root.left, ans, m);
        String right = helper(root.right, ans, m);
        String node = root.data + "," + left + "," + right;

        if (m.getOrDefault(node, 0) == 1) {
            ans.add(root);
        }
        m.put(node, m.getOrDefault(node, 0) + 1);
        return node;
    }

    public List<Node> printAllDups(Node root) {
        List<Node> ans = new ArrayList<>();
        Map<String, Integer> m = new HashMap<>();
        helper(root, ans, m);
        return ans;
    }
}
```

### Code (Python)

```python
class Solution:
    def __init__(self):
        self.map = defaultdict(int)
        self.result = []

    def helper(self, root):
        if not root:
            return ""
        left = self.helper(root.left)
        right = self.helper(root.right)
        curr = "{} {} {}".format(root.data, left, right)
        if self.map[curr] == 1:
            self.result.append(root)
        self.map[curr] += 1

        return curr

    def printAllDups(self, root):
        self.helper(root)
        self.result.sort(key=lambda node: node.data)
        return self.result
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
