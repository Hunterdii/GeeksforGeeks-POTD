# <b>15. Add 1 to a Linked List Number</b>

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1)

### Problem Description

Given a linked list where each element in the list is a node with an integer data, you need to add 1 to the number formed by concatenating all the list node numbers together and return the head of the modified linked list.

**Examples:**

Input: LinkedList: `4 -> 5 -> 6`  
Output: `4 -> 5 -> 7`

Explanation: `4 -> 5 -> 6` represents 456, and when 1 is added, it becomes 457.

Input: LinkedList: `1 -> 2 -> 3`  
Output: `1 -> 2 -> 4`

Explanation: `1 -> 2 -> 3` represents 123, and when 1 is added, it becomes 124.

### Approach

1. **Reverse the Linked List:**

   - Reverse the given linked list to facilitate the addition from the least significant digit.
   - Initialize pointers `prev` as `nullptr`, `curr` as `head`, and `next` as `nullptr`.
   - Traverse the list, updating pointers to reverse the links between nodes.

2. **Add One to the Number:**

   - Start from the head of the reversed list and initialize `carry` as 1 (since we need to add 1).
   - Traverse the reversed list, adding the `carry` to each node's data.
   - Update `carry` to the value of `sum / 10` and set the node's data to `sum % 10`.
   - If there's a carry left after processing all nodes, create a new node with the carry value and append it to the end.

3. **Reverse the List Again:**
   - Reverse the modified list to restore the original order with the new number.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the linked list. This is because we traverse the list multiple times (to reverse it, add 1, and reverse it again).
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for pointers and carry.

### Code (C++)

```cpp
class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node* addOne(Node* head) {
        head = reverse(head);
        Node* curr = head;
        Node* prev = nullptr;
        int carry = 1;

        while (curr != nullptr) {
            int sum = curr->data + carry;
            carry = sum / 10;
            curr->data = sum % 10;

            prev = curr;
            curr = curr->next;
        }

        if (carry > 0) {
            prev->next = new Node(carry);
        }

        return reverse(head);
    }
};
```

### Code (Java)

```java
class Solution {
    private Node reverse(Node head) {
        Node prev = null;
        Node curr = head;
        Node next;

        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    public Node addOne(Node head) {
        head = reverse(head);

        Node curr = head;
        Node prev = null;
        int carry = 1;

        while (curr != null) {
            int sum = curr.data + carry;
            carry = sum / 10;
            curr.data = sum % 10;

            prev = curr;
            curr = curr.next;
        }

        if (carry > 0) {
            prev.next = new Node(carry);
        }

        return reverse(head);
    }
}
```

### Code (Python)

```python
class Solution:
    def reverse(self, head):
        prev = None
        curr = head

        while curr is not None:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node

        return prev

    def addOne(self, head):
        head = self.reverse(head)
        curr = head
        carry = 1

        while curr is not None:
            sum_val = curr.data + carry
            carry = sum_val // 10
            curr.data = sum_val % 10
            prev = curr
            curr = curr.next

        if carry > 0:
            prev.next = Node(carry)

        return self.reverse(head)
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
