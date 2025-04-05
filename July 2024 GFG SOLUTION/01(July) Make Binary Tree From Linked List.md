## 01. Make Binary Tree From Linked List

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/make-binary-tree/1)

### Problem Description

Given a Linked List Representation of a Complete Binary Tree, the task is to construct the Binary Tree and print the level order traversal of the Binary Tree. Note that a complete binary tree is represented in a linked list where if the root node is at position (i), its left and right children are stored at positions \( 2i + 1 \) and \( 2i + 2 \) respectively. The height of the tree is \( H \), and the recursion stack implicitly uses this space.

_Example:_

Input:
n = 5,
k = 1->2->3->4->5

Output:
1 2 3 4 5

Explanation:
The tree would look like:

```
      1
    /   \
   2     3
 /  \
4   5
```

Now, the level order traversal of the above tree is `1 2 3 4 5`.

### My Approach

1. **Initialization:**

   - Convert the linked list into an array to simplify index-based access.
   - Create a helper function to build the tree recursively.

2. **Tree Construction:**

   - Use the helper function to construct the tree by assigning the left and right children using the complete binary tree properties.

3. **Return:**
   - Return the root of the constructed binary tree.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(n)\), as we iterate through the linked list once to build the array and then construct the tree.
- **Expected Auxiliary Space Complexity:** \(O(n)\), as we use an array of size \(n\) and the recursion stack space.

### Code

**C++:**

```cpp
TreeNode* fn(vector<int>&v,int ind) {
    if(ind >= v.size())
        return NULL;
    TreeNode* cur = new TreeNode(v[ind])  ;
    cur->left = fn(v, 2*ind+1);
    cur->right = fn(v, 2*ind+2);
    return cur;
}

void convert(Node *head, TreeNode *&root) {
    vector<int>v;
    while(head) {
        v.push_back(head->data);
        head=head->next;
    }
    root = fn(v,0);
    return;
}
```

**Java:**

```java
class GfG {
    public static Tree convert(Node head, Tree node) {
        if (head == null) {
            return null;
        }

        Tree root = new Tree(head.data);
        Queue<Tree> queue = new LinkedList<>();
        queue.add(root);
        head = head.next;

        while (head != null) {
            Tree parent = queue.poll();

            Tree leftChild = null, rightChild = null;
            leftChild = new Tree(head.data);
            queue.add(leftChild);
            head = head.next;

            if (head != null) {
                rightChild = new Tree(head.data);
                queue.add(rightChild);
                head = head.next;
            }

            parent.left = leftChild;
            parent.right = rightChild;
        }
        return root;
    }
}
```

**Python:**

```python
class ListNode:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

class TreeNode:
    def __init__(self, data=0, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

def convert(head):
    if head is None:
        return None

    root = TreeNode(head.data)
    queue = [root]
    head = head.next

    while head:
        parent = queue.pop(0)

        if head:
            left_child = TreeNode(head.data)
            parent.left = left_child
            queue.append(left_child)
            head = head.next

        if head:
            right_child = TreeNode(head.data)
            parent.right = right_child
            queue.append(right_child)
            head = head.next

    return root
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
