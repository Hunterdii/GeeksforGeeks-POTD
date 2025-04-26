# *26. Is Binary Tree Heap*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1)


## **🧩 Problem Description**

Given a binary tree, determine whether it satisfies the properties of a **Max-Heap**.

A binary tree is a **Max-Heap** if:

1. **Completeness**: All levels of the tree are completely filled except possibly the last, which is filled from left to right.
2. **Heap Property**: The value of every node is **greater than or equal to** the values of its children.


## **📘 Examples**

### **Example 1:**

#### **Input:**
`root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]`

<img src="https://github.com/user-attachments/assets/4434aa7a-f2be-4fd1-ab29-dc853fdf2656" width="30%">


#### **Output:**
`true`

#### **Explanation:**
All levels are completely filled and the parent is always greater than or equal to children.


### **Example 2:**

#### **Input:**
`root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4]`

<img src="https://github.com/user-attachments/assets/65ccdea6-b13a-46de-b793-2e0576952872" width="30%">

#### **Output:**
`false`

#### **Explanation:**
The tree is not complete and violates the max-heap property.


## **🔒 Constraints**

- $1 \leq \text{Number of Nodes} \leq 10^3$
- $1 \leq \text{node->data} \leq 10^3$


## **✅ My Approach:**

### **Recursive Count + Position Check**

This approach combines:
- Counting the number of nodes in the tree.
- Verifying that the binary tree is **complete** and satisfies **heap order property** using a recursive index simulation.


### **Algorithm Steps:**

1. Recursively count the total number of nodes `n` in the tree.
2. Traverse the tree with a recursive function using the theoretical array index of a complete binary tree (`i`):
   - If any node is placed at an index `i >= n`, then it's not complete.
   - Also, check if each node’s value is greater than its children’s.
3. If all checks pass, return `true`.


## **🧮 Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the binary tree, as each node is visited once.
- **Expected Auxiliary Space Complexity:** O(h), where `h` is the height of the binary tree due to recursion stack usage.


## **💡 Code (C)**

```c
int c(struct Node* r){return r?1+c(r->left)+c(r->right):0;}
int p(struct Node* r,int i,int n){
    return !r
        || (i<n
            && (!r->left  || r->key   >= r->left->key)
            && (!r->right || r->key   >= r->right->key)
            &&  p(r->left,  2*i+1, n)
            &&  p(r->right, 2*i+2, n)
           );
}
bool isHeap(struct Node* root){
    return p(root,0,c(root));
}
```


## **🧠 Code (C++)**

```cpp
class Solution {
    int c(Node* r) { return r ? 1 + c(r->left) + c(r->right) : 0; }
    bool p(Node* r, int i, int n) {
        return !r
            || (i < n
                && (!r->left  || r->data >= r->left->data)
                && (!r->right || r->data >= r->right->data)
                && p(r->left,  2*i+1, n)
                && p(r->right, 2*i+2, n)
              );
    }
  public:
    bool isHeap(Node* tree) {
        return p(tree, 0, c(tree));
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ Level Order + Count + Index Simulation**

### **Algorithm Steps:**
1. Traverse the tree using level order traversal while assigning theoretical indices based on complete binary tree position (like heap array representation).
2. If any node is found at index `i` where `i ≥ n`, the tree is not complete.
3. At the same time, check whether each parent node is greater than its children (heap condition).

```cpp
class Solution {
  public:
    int count(Node* root) {
        return root ? 1 + count(root->left) + count(root->right) : 0;
    }
    bool isCompleteAndHeap(Node* root, int index, int total) {
        if (!root) return true;
        if (index >= total) return false;
        if ((root->left && root->data < root->left->data) ||
            (root->right && root->data < root->right->data)) return false;
        return isCompleteAndHeap(root->left, 2*index + 1, total) &&
               isCompleteAndHeap(root->right, 2*index + 2, total);
    }
    bool isHeap(Node* root) {
        int totalNodes = count(root);
        return isCompleteAndHeap(root, 0, totalNodes);
    }
};
```


### ✅ **Why This Approach?**
- It directly simulates how a heap would be structured in an array.
- Checks both completeness and heap properties together.


#### 📝 **Complexity Analysis:**
- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(h), where `h` is height of tree (for recursion stack)


## 📊 **3️⃣ Level Order Traversal + Flags**

### **Algorithm Steps:**
1. Use a queue to perform a level-order traversal.
2. Once a NULL child is found, set a flag.
3. After this point, if any non-NULL node is found → Not Complete.
4. Simultaneously check heap property: every node ≥ children.

```cpp
class Solution {
  public:
    bool isHeap(Node* root) {
        if (!root) return true;
        queue<Node*> q;
        q.push(root);
        bool nullSeen = false;
        while (!q.empty()) {
            Node* current = q.front(); q.pop();
            if (current->left) {
                if (nullSeen || current->data < current->left->data) return false;
                q.push(current->left);
            } else {
                nullSeen = true;
            }
            if (current->right) {
                if (nullSeen || current->data < current->right->data) return false;
                q.push(current->right);
            } else {
                nullSeen = true;
            }
        }
        return true;
    }
};
```


### ✅ **Why This Approach?**
- Efficiently checks completeness and heap property in a single pass.
- Uses a queue for level-order traversal, intuitive for BFS-minded devs.


#### 📝 **Complexity Analysis:**
- **Expected Time Complexity:** O(n)
- **Expected Auxiliary Space Complexity:** O(n) due to queue usage


### 🆚 **Comparison of Approaches**

| **Approach**                         | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                          | ⚠️ **Cons**                        |
|-------------------------------------|-------------|--------------|--------------------------------------|------------------------------------|
| Recursive index & count (main)      | 🟢 O(n)      | 🟢 O(h)       | Elegant and clean recursion          | Requires understanding index logic |
| Level Order + Index Simulation      | 🟢 O(n)      | 🟢 O(h)       | Direct simulation of heap index      | Slightly more complex implementation |
| Level Order Traversal + Flags       | 🟢 O(n)      | 🔴 O(n)       | Very intuitive BFS-based logic       | Queue space may grow for wide trees |


### ✅ **Best Choice?**

| **Scenario**                                     | **Recommended Approach**            |
|--------------------------------------------------|-------------------------------------|
| ✅ Concise and recursive                          | 🥇 Recursive Index & Count          |
| ✅ Array index-based reasoning                    | 🥈 Level Order + Index Simulation   |
| ✅ Prefer using queues and level traversal        | 🥉 Level Order + Flags              |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    int c(Node r){return r==null?0:1+c(r.left)+c(r.right);}
    boolean p(Node r,int i,int n){
        return r==null
            || (i<n
                && (r.left  ==null || r.data>=r.left.data)
                && (r.right ==null || r.data>=r.right.data)
                &&  p(r.left,  2*i+1, n)
                &&  p(r.right, 2*i+2, n)
               );
    }
    boolean isHeap(Node tree){
        return p(tree,0,c(tree));
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def c(self, r):
        return 1 + self.c(r.left) + self.c(r.right) if r else 0
    def p(self, r, i, n):
        return (not r) or (
            i < n
            and (not r.left  or r.data >= r.left.data)
            and (not r.right or r.data >= r.right.data)
            and self.p(r.left,  2*i+1, n)
            and self.p(r.right, 2*i+2, n)
        )
    def isHeap(self, root):
        return self.p(root, 0, self.c(root))
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>



