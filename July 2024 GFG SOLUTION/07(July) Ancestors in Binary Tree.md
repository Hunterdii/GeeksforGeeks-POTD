## 07. Ancestors in Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1)

### Problem Description

Given a Binary Tree and an integer target, find all the ancestors of the given target.

**Note:**

- The ancestor of node x is node y, which is at the upper level of node x, and x is directly connected with node y.
- Consider multiple levels of ancestors to solve this problem.
- In case there are no ancestors available, return an empty list.

**Examples:**

Input:

```
         1
       /   \
      2     3
    /  \    /  \
   4   5  6   8
  /
 7
target = 7
```

Output:

```
[4, 2, 1]
```

Explanation:
The given target is 7. If we go above the level of node 7, then we find 4, 2, and 1. Hence the ancestors of node 7 are 4, 2, and 1.

### My Approach

1. **Helper Function:**

   - Define a helper function `findAncestors` to recursively find the ancestors.
   - If the current node is `None`, return `False`.
   - If the current node's data matches the target, return `True`.
   - Recursively call `findAncestors` for the left and right subtrees.
   - If the target is found in either the left or right subtree, add the current node's data to the ancestors list and return `True`.

2. **Main Function:**
   - Define the main function `Ancestors`.
   - Initialize an empty list `ancestors`.
   - Call the helper function with the root and target, passing the ancestors list.
   - Return the ancestors list.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the entire tree to find the target node and its ancestors.
- **Expected Auxiliary Space Complexity:** O(height of tree), as the recursive stack can go up to the height of the tree.

### Code

#### C++

```cpp
class Solution {
public:
    bool findAncestors(Node* root, int target, vector<int>& ancestors) {
        if (!root) return false;

        if (root->data == target) return true;

        if (findAncestors(root->left, target, ancestors) ||
            findAncestors(root->right, target, ancestors)) {
            ancestors.push_back(root->data);
            return true;
        }

        return false;
    }

    vector<int> Ancestors(Node* root, int target) {
        vector<int> ancestors;
        findAncestors(root, target, ancestors);
        return ancestors;
    }
};
```

#### Java

```java
class Solution {

    private boolean findAncestors(Node root, int target, ArrayList<Integer> ancestors) {
        if (root == null) return false;

        if (root.data == target) return true;

        if (findAncestors(root.left, target, ancestors) ||
            findAncestors(root.right, target, ancestors)) {
            ancestors.add(root.data);
            return true;
        }

        return false;
    }

    public ArrayList<Integer> Ancestors(Node root, int target) {
        ArrayList<Integer> ancestors = new ArrayList<>();
        findAncestors(root, target, ancestors);
        return ancestors;
    }
}
```

#### Python

```python
class Solution:
    def findAncestors(self, root, target, ancestors):
        if root is None:
            return False

        if root.data == target:
            return True

        if (self.findAncestors(root.left, target, ancestors) or
            self.findAncestors(root.right, target, ancestors)):
            ancestors.append(root.data)
            return True

        return False

    def Ancestors(self, root, target):
        ancestors = []
        self.findAncestors(root, target, ancestors)
        return ancestors
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
