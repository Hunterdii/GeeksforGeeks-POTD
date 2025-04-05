# _13. Delete Alternate Nodes_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/delete-alternate-nodes/1)

### Problem Description

Given a Singly Linked List, delete all alternate nodes of the list, i.e., delete all the nodes present in even positions.

- For example, given the input linked list: `1 -> 2 -> 3 -> 4 -> 5 -> 6`, the output should be `1 -> 3 -> 5`.
- The nodes at even positions (2, 4, 6) are deleted.

### Example

**Input:**

LinkedList: `99 -> 59 -> 42 -> 20`

**Output:**

`99 -> 42`

### My Approach

1. **Initialization:**

   - Start with the head of the linked list and initialize a pointer to track the current node.

2. **Iteration:**

   - Loop through the linked list. For each node, skip the next node (delete it) and link the current node to the node after the next node.

3. **Node Deletion:**
   - After linking, move the current pointer two nodes ahead to continue the process until reaching the end of the list.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the number of nodes in the linked list, as we traverse each node only once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for pointers.

### Code (C++)

```cpp
class Solution {
public:
    void deleteAlt(struct Node* head) {
        if (!head) return;
        struct Node* current = head;
        while (current && current->next) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            current = current->next;
        }
    }
};
```

### Code (Java)

```java
class Solution {
    public void deleteAlt(Node head) {
        if (head == null) return;
        Node current = head;

        while (current != null && current.next != null) {
            Node temp = current.next;
            current.next = current.next.next;
            temp = null;
            current = current.next;
        }
    }
}
```

### Code (Python)

```python
class Solution:
    def deleteAlt(self, head):
        if not head:
            return

        current = head
        while current and current.next:
            temp = current.next
            current.next = current.next.next
            current = current.next
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
