# _17. Split Linked List Alternatingly_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1)

### Problem Description

Given the head of a singly linked list, your task is to complete the function `alternatingSplitList()` that splits the given linked list into two smaller lists. The sublists should be made from alternating elements from the original list.

- The sublist should maintain the order with respect to the original list.
- You have to return an array containing both sub-linked lists.

**Examples:**

Input: `LinkedList = 0->1->0->1->0->1`  
Output: `0->0->0`, `1->1->1`  
**Explanation:** After forming two sublists from the original list, we have `0->0->0` and `1->1->1`.

**Constraints:**

- 1 ≤ number of nodes ≤ 100
- 1 ≤ node data ≤ 10^4

### My Approach

1. **Initialization:**

   - Create pointers for the heads and tails of both sublists (`a_head`, `b_head`, `a_tail`, `b_tail`).
   - Use a pointer `current` to iterate through the original list.

2. **Iterate through the list:**

   - In each iteration, add the current node to the first sublist (list A).
   - Move to the next node, and if it's available, add it to the second sublist (list B).
   - Continue this process until you reach the end of the original list.

3. **Return the sublists:**
   - Return an array containing both sublinked lists.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the number of nodes in the linked list, as we traverse the list once to create the two sublists.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for pointers.

### Code (C++)

```cpp
class Solution {
public:
    vector<Node*> alternatingSplitList(Node* head) {
        if (head == NULL) return {NULL, NULL};

        Node* a_head = nullptr;
        Node* b_head = nullptr;
        Node* a_tail = nullptr;
        Node* b_tail = nullptr;
        Node* current = head;

        while (current != NULL) {
            if (a_head == nullptr) {
                a_head = new Node(current->data);
                a_tail = a_head;
            } else {
                a_tail->next = new Node(current->data);
                a_tail = a_tail->next;
            }
            current = current->next;

            if (current != NULL) {
                if (b_head == nullptr) {
                    b_head = new Node(current->data);
                    b_tail = b_head;
                } else {
                    b_tail->next = new Node(current->data);
                    b_tail = b_tail->next;
                }
                current = current->next;
            }
        }
        return {a_head, b_head};
    }
};
```

### Code (Java)

```java
class Solution {
    Node[] alternatingSplitList(Node head) {
        if (head == null) return new Node[]{null, null};

        Node a_head = null;
        Node b_head = null;
        Node a_tail = null;
        Node b_tail = null;
        Node current = head;

        while (current != null) {
            if (a_head == null) {
                a_head = new Node(current.data);
                a_tail = a_head;
            } else {
                a_tail.next = new Node(current.data);
                a_tail = a_tail.next;
            }
            current = current.next;

            if (current != null) {
                if (b_head == null) {
                    b_head = new Node(current.data);
                    b_tail = b_head;
                } else {
                    b_tail.next = new Node(current.data);
                    b_tail = b_tail.next;
                }
                current = current.next;
            }
        }
        return new Node[]{a_head, b_head};
    }
}
```

### Code (Python)

```python
class Solution:
    def alternatingSplitList(self, head):
        if head is None:
            return None, None

        a_head = None
        b_head = None
        a_tail = None
        b_tail = None
        current = head

        while current is not None:
            if a_head is None:
                a_head = Node(current.data)
                a_tail = a_head
            else:
                a_tail.next = Node(current.data)
                a_tail = a_tail.next

            current = current.next
            if current is not None:
                if b_head is None:
                    b_head = Node(current.data)
                    b_tail = b_head
                else:
                    b_tail.next = Node(current.data)
                    b_tail = b_tail.next

                current = current.next

        return a_head, b_head
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
