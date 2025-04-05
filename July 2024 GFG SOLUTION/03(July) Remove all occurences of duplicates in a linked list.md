## 03. Remove All Occurrences of Duplicates in a Linked List

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-all-occurences-of-duplicates-in-a-linked-list/1)

### Problem Description

Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list.

**Examples:**

Input:

```
Linked List = 23->28->28->35->49->49->53->53
```

Output:

```
23 35
```

Explanation: The duplicate numbers are 28, 49, and 53, which are removed from the list.

### Approach

1. **Initialization:**

   - Create a dummy node that points to the head of the linked list to handle edge cases, such as when the head itself is a duplicate.
   - Initialize pointers `prev` and `current`, where `prev` points to the dummy node, and `current` points to the head.

2. **Iterate Through the List:**

   - Traverse the linked list with the `current` pointer.
   - Use a nested loop to check for consecutive nodes with the same value, marking them as duplicates.
   - If duplicates are found, skip all nodes with the duplicate value by adjusting the `next` pointer of `prev` to point to the node after `current`.
   - If no duplicates are found, move the `prev` pointer to the next node.
   - Move the `current` pointer to the next node in all cases.

3. **Return:**
   - Return the node after the dummy node, which is the new head of the modified linked list.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the linked list. This is because we traverse the list once.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    Node* removeAllDuplicates(Node* head) {
        if (!head) return nullptr;

        Node dummy(-1);
        dummy.next = head;
        Node* prev = &dummy;
        Node* current = head;

        while (current) {
            bool isDuplicate = false;
            while (current->next && current->data == current->next->data) {
                current = current->next;
                isDuplicate = true;
            }
            if (isDuplicate) {
                prev->next = current->next;
            } else {
                prev = prev->next;
            }
            current = current->next;
        }

        return dummy.next;
    }
};
```

### Code (Java)

```java
class Solution {
    public Node removeAllDuplicates(Node head) {
        if (head == null) return null;

        Node dummy = new Node(-1);
        dummy.next = head;
        Node prev = dummy;
        Node current = head;

        while (current != null) {
            boolean isDuplicate = false;
            while (current.next != null && current.data == current.next.data) {
                current = current.next;
                isDuplicate = true;
            }
            if (isDuplicate) {
                prev.next = current.next;
            } else {
                prev = prev.next;
            }
            current = current.next;
        }

        return dummy.next;
    }
}
```

### Code (Python)

```python
class Solution:
    def removeAllDuplicates(self, head):
        if not head:
            return None

        dummy = Node(-1)
        dummy.next = head
        prev = dummy
        current = head

        while current:
            is_duplicate = False
            while current.next and current.data == current.next.data:
                current = current.next
                is_duplicate = True
            if is_duplicate:
                prev.next = current.next
            else:
                prev = prev.next
            current = current.next

        return dummy.next
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
