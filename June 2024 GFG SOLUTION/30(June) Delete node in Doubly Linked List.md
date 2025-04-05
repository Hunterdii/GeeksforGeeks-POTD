## 30. Delete Node in Doubly Linked List

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1)

### Problem Description

Given a doubly linked list and a position `x`, the task is to delete the node at the given position (position starts from 1) and return the head of the doubly linked list.

**Examples:**

Input:

```
LinkedList = 1 <--> 3 <--> 4, x = 3
```

Output:

```
1 3
```

Explanation:
After deleting the node at position 3, the linked list will be 1 <--> 3.

<p align="center">
  <img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/e52372d0-d5e5-428b-b953-7894ece5ac9a" alt="Image" width="270" />
</p>

### My Approach

1. **Edge Cases:**

   - If the head is `null`, return `null`.
   - If `x` is 1, update the head to the next node and adjust the pointers.

2. **Traversal:**

   - Traverse the list to reach the `x`th node.
   - If the `x`th node is the head, update the head and adjust pointers.
   - If the `x`th node is not the head, adjust the pointers of the previous and next nodes to bypass the `x`th node.

3. **Deletion:**
   - Delete the `x`th node.
   - Return the updated head of the list.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we might need to traverse up to the `n`th node.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code

#### C++

```cpp
class Solution {
public:
    Node* deleteNode(Node* head, int x) {
        if (head == nullptr) return nullptr;

        Node* current = head;
        for (int i = 1; i < x; ++i) {
            if (current->next == nullptr) return head;
            current = current->next;
        }
        if (current == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            delete current;
            return head;
        }
        Node* prev = current->prev;
        Node* next = current->next;

        if (prev != nullptr) prev->next = next;
        if (next != nullptr) next->prev = prev;

        delete current;
        return head;
    }
};
```

#### Java

```java
class Solution {
    public Node deleteNode(Node head, int x) {
        if (head == null) return null;

        Node current = head;
        for (int i = 1; i < x; ++i) {
            if (current.next == null) return head;
            current = current.next;
        }
        if (current == head) {
            head = head.next;
            if (head != null) head.prev = null;
            return head;
        }
        Node prev = current.prev;
        Node next = current.next;

        if (prev != null) prev.next = next;
        if (next != null) next.prev = prev;

        return head;
    }
}
```

#### Python

```python
class Solution:
    def delete_node(self, head, x):
        if not head:
            return None

        current = head

        for i in range(1, x):
            if not current.next:
                return head
            current = current.next
        if current == head:
            head = head.next
            if head:
                head.prev = None
            return head
        prev = current.prev
        next = current.next

        if prev:
            prev.next = next
        if next:
            next.prev = prev

        return head
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
