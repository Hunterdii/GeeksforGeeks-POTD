## 25. Array to BST

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/array-to-bst4443/1)

### Problem Description

Given a sorted array, convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.

A height-balanced BST is a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Note: The driver code will check if the BST is height-balanced. If it is, the output will be true; otherwise, the output will be false.

**Example:**

Input:

```
nums = [1, 2, 3, 4]
```

Output:

```
true
```

Explanation:
The preorder traversal of the following BST formed is [2, 1, 3, 4]:

### My Approach

1. **Recursive Helper Function:**

   - Create a helper function `sortedArrayToBSTUtil` that takes the array and the current bounds (`left` and `right`) as arguments.
   - If `left` is greater than `right`, return `nullptr` (base case for recursion).

2. **Mid Calculation:**

   - Calculate the middle index of the current segment: `mid = left + (right - left) / 2`.

3. **Node Creation:**

   - Create a new node with the value at the middle index: `node = new Node(nums[mid])`.

4. **Recursive Calls:**

   - Recursively create the left and right subtrees using the helper function:
     - `node->left = sortedArrayToBSTUtil(nums, left, mid - 1)`
     - `node->right = sortedArrayToBSTUtil(nums, mid + 1, right)`

5. **Return:**
   - Return the created node.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as each element of the array is processed exactly once.
- **Expected Auxiliary Space Complexity:** O(n), as the recursion stack can go as deep as the number of elements in the array.

### Code (C++)

```cpp
class Solution {
public:
    Node* sortedArrayToBSTUtil(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        Node* node = new Node(nums[mid]);

        node->left = sortedArrayToBSTUtil(nums, left, mid - 1);
        node->right = sortedArrayToBSTUtil(nums, mid + 1, right);

        return node;
    }

    Node* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTUtil(nums, 0, nums.size() - 1);
    }
};
```

### Code (Java)

```java
class Solution {
    public Node sortedArrayToBST(int[] nums) {
        return sortedArrayToBSTUtil(nums, 0, nums.length - 1);
    }

    private Node sortedArrayToBSTUtil(int[] nums, int left, int right) {
        if (left > right)
            return null;

        int mid = left + (right - left) / 2;

        Node node = new Node(nums[mid]);

        node.left = sortedArrayToBSTUtil(nums, left, mid - 1);
        node.right = sortedArrayToBSTUtil(nums, mid + 1, right);

        return node;
    }
}
```

### Code (Python)

```python
class Solution:
    def sortedArrayToBST(self, nums):
        return self.sortedArrayToBSTUtil(nums, 0, len(nums) - 1)

    def sortedArrayToBSTUtil(self, nums, left, right):
        if left > right:
            return None

        mid = left + (right - left) // 2

        node = Node(nums[mid])

        node.left = self.sortedArrayToBSTUtil(nums, left, mid - 1)
        node.right = self.sortedArrayToBSTUtil(nums, mid + 1, right)

        return node
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
