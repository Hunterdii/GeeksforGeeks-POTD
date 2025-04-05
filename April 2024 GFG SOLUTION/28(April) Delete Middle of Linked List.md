## 28. Delete Middle of Linked List

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1)

### Problem Description

Given a singly linked list, delete the middle of the linked list. If there are even nodes, delete the second middle element. If the input linked list has a single node, return NULL.

**Example:**

Input:

```
LinkedList: 1->2->3->4->5
```

Output:

```
1 2 4 5
```

Explanation:
After deleting the middle element (3), the modified linked list becomes 1->2->4->5.

**Your Task:**

The task is to complete the function `deleteMid()` which takes the head of the linked list and returns the head of the linked list with the middle element deleted. If the linked list is empty or contains a single element, it should return NULL.

**Expected Time Complexity:** O(n).
**Expected Auxiliary Space:** O(1).

### My Approach

1. **Corner Cases:**

   - If the linked list is empty or contains a single node, return NULL.

2. **Traversal:**

   - Initialize two pointers, `slow` and `fast`, both pointing to the head of the linked list.
   - Move `slow` one step at a time and `fast` two steps at a time until `fast` reaches the end of the list or the node just before the last node.

3. **Delete Middle Node:**

   - When `fast` reaches the middle (or just before the middle), `slow` will be at the node just before the middle node.
   - Delete the middle node by adjusting the next pointer of `slow` to skip the middle node.

4. **Return Head:**
   - Return the head of the modified linked list.

### Code (C++)

```cpp
class Solution {
public:
    Node* deleteMid(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr; // No middle node to delete
        }

        Node* slow = head;
        Node* fast = head->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* del = slow->next;
        slow->next = del->next;
        delete del;

        return head;
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
