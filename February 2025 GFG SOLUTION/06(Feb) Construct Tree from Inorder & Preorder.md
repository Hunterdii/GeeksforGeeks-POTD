# _6. Construct Tree from Inorder & Preorder_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/construct-tree-1/1)

## **Problem Description**

Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.  
**Note:** The output is written in postorder traversal.

### **Example 1:**

#### **Input:**

```
inorder[]  = [1, 6, 8, 7]
preorder[] = [1, 6, 7, 8]
```

#### **Output:**

```
[8, 7, 6, 1]
```

#### **Explanation:**

The constructed binary tree’s postorder traversal is `[8, 7, 6, 1]`.

<img src="https://github.com/user-attachments/assets/f4ac9162-3e2e-45f4-88e5-bde4219b38aa" width="30%">

### **Example 2:**

#### **Input:**

```
inorder[]  = [3, 1, 4, 0, 2, 5]
preorder[] = [0, 1, 3, 4, 2, 5]
```

#### **Output:**

```
[3, 4, 1, 5, 2, 0]
```

#### **Explanation:**

The constructed binary tree’s postorder traversal is `[3, 4, 1, 5, 2, 0]`.

<img src="https://github.com/user-attachments/assets/248efb33-8c80-4b61-ac8b-8e0f5c9cabce" width="30%">

### **Example 3:**

#### **Input:**

```
inorder[]  = [2, 5, 4, 1, 3]
preorder[] = [1, 4, 5, 2, 3]
```

#### **Output:**

```
[2, 5, 4, 3, 1]
```

#### **Explanation:**

The constructed binary tree’s postorder traversal is `[2, 5, 4, 3, 1]`.

<img src="https://github.com/user-attachments/assets/c65c7024-e460-45d8-bcf5-8f42d2ec4013" width="30%">

### **Constraints:**

- 1 ≤ number of nodes ≤ $10^3$
- 0 ≤ node->data ≤ $10^3$
- Both inorder and preorder arrays contain unique values.

## **My Approach**

### **Recursive Construction with Hash Map**

1. **Identify the Root:**
   - The first element in the `preorder` array is always the root of the tree.
2. **Index Lookup Using Hash Map:**
   - Build a hash map that stores the index of each element in the `inorder` array for O(1) lookups.
3. **Recursive Tree Construction:**
   - Using the current root from `preorder`, find its index in `inorder`.
   - Recursively construct the left subtree with the elements to the left of the root in `inorder`.
   - Recursively construct the right subtree with the elements to the right of the root in `inorder`.
4. **Output Generation:**
   - Once the tree is constructed, its postorder traversal represents the expected output.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N)`, as every node is processed exactly once.
- **Expected Auxiliary Space Complexity:** `O(N)`, mainly due to the recursion stack (in the worst-case scenario for a skewed tree) and the hash map used for index storage.

## **Code (C++)**

```cpp
class Solution {
public:
    int i = 0;
    unordered_map<int, int> m;
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        for (int j = 0; j < inorder.size(); j++) m[inorder[j]] = j;
        function<Node*(int, int)> f = [&](int l, int r) -> Node* {
            if (l > r) return nullptr;
            Node* root = new Node(preorder[i++]);
            root->left = f(l, m[root->data] - 1);
            root->right = f(m[root->data] + 1, r);
            return root;
        };
        return f(0, inorder.size() - 1);
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

## **2️⃣ Iterative (Using Stack)**

```cpp
class Solution {
public:
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        if(preorder.empty()) return nullptr;
        Node* root = new Node(preorder[0]);
        stack<Node*> s;
        s.push(root);
        int inIndex = 0;
        for (int i = 1; i < preorder.size(); i++) {
            Node* node = s.top();
            if (node->data != inorder[inIndex]) {
                node->left = new Node(preorder[i]);
                s.push(node->left);
            } else {
                while(!s.empty() && s.top()->data == inorder[inIndex]) {
                    node = s.top();
                    s.pop();
                    inIndex++;
                }
                node->right = new Node(preorder[i]);
                s.push(node->right);
            }
        }
        return root;
    }
};
```

## **3️⃣ Recursive (Traditional)**

```cpp
class Solution {
    unordered_map<int, int> m;
    int i;
    Node* f(vector<int>& pre, vector<int>& in, int l, int r) {
        if (l > r) return nullptr;
        Node* root = new Node(pre[i++]);
        int idx = m[root->data];
        root->left = f(pre, in, l, idx - 1);
        root->right = f(pre, in, idx + 1, r);
        return root;
    }
public:
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        i = 0;
        for (int j = 0; j < inorder.size(); j++) m[inorder[j]] = j;
        return f(preorder, inorder, 0, inorder.size() - 1);
    }
};
```

## **Comparison of Approaches**

| Approach                    | Time Complexity | Space Complexity | Method             | Pros                                            | Cons                                                 |
| --------------------------- | --------------- | ---------------- | ------------------ | ----------------------------------------------- | ---------------------------------------------------- |
| **Recursive (Lambda)**      | 🟢 **O(N)**     | 🟡 **O(N)**      | Recursion (Lambda) | Clean, concise, minimal code footprint          | May hit recursion limits on very deep trees          |
| **Iterative (Stack)**       | 🟢 **O(N)**     | 🟡 **O(N)**      | Stack-based        | Avoids recursion depth issues; explicit control | Slightly more complex to implement                   |
| **Recursive (Traditional)** | 🟢 **O(N)**     | 🟡 **O(N)**      | Recursion          | Straightforward and familiar recursive pattern  | Recursion stack may overflow in worst-case scenarios |

### **Best Choice?**

- **For balanced trees**, the **Recursive (Lambda)** approach is ideal.
- **For deep or skewed trees**, the **Iterative (Stack)** approach is recommended.
- **For general usage with simplicity**, the **Recursive (Traditional)** approach works well.

</details>

## **Code (Java)**

```java
class Solution {
    public static Node buildTree(int[] inorder, int[] preorder) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) m.put(inorder[i], i);
        int[] idx = new int[1];
        return build(0, inorder.length - 1, preorder, m, idx);
    }
    static Node build(int l, int r, int[] pre, HashMap<Integer, Integer> m, int[] idx) {
        if(l > r) return null;
        Node root = new Node(pre[idx[0]++]);
        root.left = build(l, m.get(root.data) - 1, pre, m, idx);
        root.right = build(m.get(root.data) + 1, r, pre, m, idx);
        return root;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def buildTree(self, inorder, preorder):
        m = {v: i for i, v in enumerate(inorder)}
        self.i = 0
        def f(l, r):
            if l > r:
                return None
            root = Node(preorder[self.i])
            self.i += 1
            pos = m[root.data]
            root.left = f(l, pos - 1)
            root.right = f(pos + 1, r)
            return root
        return f(0, len(inorder) - 1)
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
