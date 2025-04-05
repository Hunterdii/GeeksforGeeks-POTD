# **09. Linked List Matrix**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/linked-list-matrix/1)

---

### Problem Description

You are given a matrix `mat` of size `n*n`. Your task is to construct a 2D linked list representation of the given matrix.

Each node in the linked list contains:

- A value from the matrix.
- A pointer to the right neighbor (i.e., the node that is next in the same row).
- A pointer to the down neighbor (i.e., the node that is in the next row but the same column).

The goal is to convert the matrix into a linked list where each node is linked to its right and down neighbors (if they exist).

**Examples**:

- **Input:**

  ```
  mat = [[1, 2, 3],
         [4, 5, 6],
         [7, 8, 9]]
  ```

  **Output:**  
  Linked List with nodes having pointers to their right and down neighbors.

- **Input:**
  ```
  mat = [[23, 28],
         [23, 28]]
  ```
  **Output:**  
  Linked List with nodes linked similarly to the above example.

---

### My Approach

1. **Node Structure Setup:**

   - Each element of the matrix is converted into a node.
   - The node contains three fields: the value of the element, a pointer to the right neighbor, and a pointer to the down neighbor.

2. **Matrix Traversal:**

   - Traverse through the matrix. For each element, create a node.
   - Link the node to its right neighbor if it exists.
   - Link the node to its down neighbor if it exists.

3. **Constructing the Linked Matrix:**

   - Create a 2D array of nodes for each matrix element.
   - First, create all nodes corresponding to the matrix elements.
   - Then, for each node, assign its `right` and `down` pointers to the respective nodes, ensuring the linked list structure is established.

4. **Final Linked List:**
   - The linked list starts from the first element of the matrix, and each node has pointers to its right and down neighbors.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n²), where `n` is the size of the matrix, as we need to process all elements and link them accordingly.
- **Expected Auxiliary Space Complexity:** O(n²), since we store the matrix elements as linked nodes.

---

### Code (C++)

```cpp
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<Node*>> nodeMatrix(m, vector<Node*>(n, NULL));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nodeMatrix[i][j] = new Node(mat[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j < n - 1) {
                    nodeMatrix[i][j]->right = nodeMatrix[i][j + 1];
                }
                if (i < m - 1) {
                    nodeMatrix[i][j]->down = nodeMatrix[i + 1][j];
                }
            }
        }
        return nodeMatrix[0][0];
    }
};
```

---

### Code (Java)

```java
class Solution {
    static Node construct(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        Node[][] nodeMatrix = new Node[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nodeMatrix[i][j] = new Node(mat[i][j]);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j < n - 1) {
                    nodeMatrix[i][j].right = nodeMatrix[i][j + 1];
                }
                if (i < m - 1) {
                    nodeMatrix[i][j].down = nodeMatrix[i + 1][j];
                }
            }
        }

        return nodeMatrix[0][0];
    }
}
```

---

### Code (Python)

```python
class Solution:
    def constructLinkedMatrix(self, mat):
        m = len(mat)
        n = len(mat[0])
        nodeMatrix = [[None for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                nodeMatrix[i][j] = Node(mat[i][j])

        for i in range(m):
            for j in range(n):
                if j < n - 1:
                    nodeMatrix[i][j].right = nodeMatrix[i][j + 1]
                if i < m - 1:
                    nodeMatrix[i][j].down = nodeMatrix[i + 1][j]

        return nodeMatrix[0][0]
```

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
