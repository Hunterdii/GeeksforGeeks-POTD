# _14. Count Linked List Nodes_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1)

### Problem Description

Given a singly linked list, the task is to count the number of nodes in the linked list, where the length is defined as the number of nodes.

_Examples:_

Input:  
LinkedList : `1->2->3->4->5`

Output:  
`5`

Explanation: The count of nodes in the linked list is `5`, which is its length.

Input:  
LinkedList : `2->4->6->7->5->1->0`

Output:  
`7`

Explanation: The count of nodes in the linked list is `7`. Hence, the output is `7`.

**Constraints:**

- 1 <= number of nodes <= 105
- 1 <= node->data <= 103

---

### My Approach

1. _Recursive Traversal:_  
   We traverse the entire linked list recursively, counting the nodes as we go. At each step, we move to the next node until we reach the end of the list (i.e., a null pointer). The base case of our recursion is when the head is `NULL`, indicating the end of the list.

2. _Iterative Traversal:_  
   An iterative approach can also be employed, where we start at the head node and increment a counter while moving to the next node. This continues until the end of the list is reached.

---

### Time and Auxiliary Space Complexity

- _Expected Time Complexity:_  
  \(O(n)\), where \(n\) is the number of nodes in the linked list. We visit each node exactly once during the traversal.

- _Expected Auxiliary Space Complexity:_  
  \(O(1)\) for the iterative solution, as we are only using a constant amount of additional space.  
  \(O(n)\) for the recursive solution, due to the call stack that builds up to a depth of \(n\).

---

### Code (C)

```c
int getCount(struct Node* head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + getCount(head->next);
}
```

### Code (C++)

```cpp
class Solution {
  public:
    int getCount(struct Node* head) {
        if (head == NULL)
            return 0;
        return 1 + getCount(head->next);
    }
};
```

### Code (Java)

```java
class Solution {
    public int getCount(Node head) {
        if (head == null) {
            return 0;
        }
        return 1 + getCount(head.next);
    }
}
```

### Code (Python)

```python
class Solution:
    def getCount(self, head):
        if head is None:
            return 0
        return 1 + self.getCount(head.next)
```

---

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's continue to create a collaborative learning environment!

⭐ Star this repository if you find it helpful! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
