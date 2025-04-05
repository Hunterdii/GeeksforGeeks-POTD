## 23. Merge Two BSTs

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/merge-two-bst-s/1)

### Problem Description

Given two BSTs, return elements of merged BSTs in sorted form.

**Examples:**

**Input:**

```
BST1:
       5
     /   \
    3     6
   / \
  2   4

BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
```

**Output:**

```
1 2 2 3 3 4 5 6 6 7
```

**Explanation:**
After merging and sorting the two BSTs, we get 1 2 2 3 3 4 5 6 6 7.

### My Approach

1. **Inorder Traversal:**

   - Create a function `inorder` to perform an inorder traversal on a BST and store the elements in a vector (C++) or list (Java and Python).

2. **Merge BSTs:**

   - Create a function `merge` to merge two BSTs. Perform an inorder traversal on both BSTs to get the elements.
   - Sort the combined list of elements.

3. **Return:**
   - Return the sorted list of elements.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(m + n), as we perform an inorder traversal of both BSTs and sort the combined list.
- **Expected Auxiliary Space Complexity:** O(Height of BST1 + Height of BST2 + m + n), as we use additional space for the inorder traversal stack and the combined list of elements.

### Code (C++)

```cpp
class Solution {
public:
    void inorder(Node *root, vector<int> &arr) {
        if (!root)
            return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> merge(Node *root1, Node *root2) {
        vector<int> arr;
        inorder(root1, arr);
        inorder(root2, arr);
        sort(arr.begin(), arr.end());
        return arr;
    }
};
```

### Code (Java)

```java
class Solution {
    void inorder(Node root, List<Integer> arr) {
        if (root == null) return;
        inorder(root.left, arr);
        arr.add(root.data);
        inorder(root.right, arr);
    }

    public List<Integer> merge(Node root1, Node root2) {
        List<Integer> arr = new ArrayList<>();
        inorder(root1, arr);
        inorder(root2, arr);
        Collections.sort(arr);
        return arr;
    }
}
```

### Code (Python)

```python
class Solution:

    def inorder(self, root, arr):
        if not root:
            return
        self.inorder(root.left, arr)
        arr.append(root.data)
        self.inorder(root.right, arr)

    def merge(self, root1, root2):
        arr = []
        self.inorder(root1, arr)
        self.inorder(root2, arr)
        arr.sort()
        return arr
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
