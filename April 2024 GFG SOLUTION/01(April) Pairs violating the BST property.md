## 01. Pairs Violating BST Property

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1)

### Problem Description

Given a binary tree with \(n\) nodes, find the number of pairs violating the BST property.

BST has the following properties:

1. Every node is greater than its left child and less than its right child.
2. Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.
3. The maximum in the left sub-tree must be less than the minimum in the right subtree.

**Example:**

Input :

```
n = 5
```

Input tree:

```
          10
        /    \
       50      40
      / \     /
     20 30   60
```

Output :

```
5
```

Explanation :
Pairs violating BST property are:

- (10,50), 10 should be greater than its left child value.
- (40,30), 40 should be less than its right child value.
- (50,20), (50,30) and (50,40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.

### My Approach

1. **Inorder Traversal and Merge Sort:**

- Perform an inorder traversal of the binary tree to get the sorted values.
- Use merge sort to count the number of inversions in the sorted array, which represents the number of pairs violating the BST property.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n*logn), as we perform inorder traversal and merge sort, both of which have a time complexity of O(n*logn).
- **Expected Auxiliary Space Complexity:** O(n), as we use additional space for storing the inorder traversal and for the merge sort algorithm.

### Code (C++)

```cpp
class Solution {
public:
    int pairsViolatingBST(int n, Node *root) {
        vector<int> inorderTraversal;
        inorder(root, inorderTraversal);
        vector<int> temp(n);
        return mergeSort(0, n - 1, inorderTraversal, temp);
    }

private:
    void inorder(Node* root, vector<int>& inorderTraversal) {
        if (root) {
            inorder(root->left, inorderTraversal);
            inorderTraversal.push_back(root->data);
            inorder(root->right, inorderTraversal);
        }
    }

    int merge(int low, int mid, int high, vector<int>& arr, vector<int>& output) {
        int i = low, j = mid + 1;
        int k = low;
        int inversions = 0;

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j])
                output[k++] = arr[i++];
            else {
                output[k++] = arr[j++];
                inversions += (mid - i + 1);
            }
        }

        while (i <= mid)
            output[k++] = arr[i++];
        while (j <= high)
            output[k++] = arr[j++];

        for (int i = low; i <= high; ++i)
            arr[i] = output[i];

        return inversions;
    }

    int mergeSort(int low, int high, vector<int>& arr, vector<int>& output) {
        int inversions = 0;

        if (low < high) {
            int mid = (low + high) / 2;

            inversions += mergeSort(low, mid, arr, output);
            inversions += mergeSort(mid + 1, high, arr, output);
            inversions += merge(low, mid, high, arr, output);
        }

        return inversions;
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
