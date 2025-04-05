# _21. Clone a Linked List with Next and Random Pointer_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1)

### Problem Description

You are given a special linked list where each node has a `next` pointer pointing to its next node and a `random` pointer, which may point to any node in the list or be `null`. Construct a deep copy of the list where every node in the copy has the same value, next, and random pointers as the original list.

**Example:**

Input:  
LinkedList: 1 -> 2 -> 3 -> 4  
Pairs: {1, 2}, {2, 4}

Output:  
1 -> 2 -> 3 -> 4 (with corresponding random pointers copied)

Explanation: The copied list will have the same random pointers as the original list.

### My Approach

1. **Step 1: Clone Nodes:**

   - Traverse the original list, and for each node, create a clone of it. Insert each clone between the original node and its next node.

2. **Step 2: Assign Random Pointers:**

   - Traverse the list again and assign the correct `random` pointers for each clone node. The random pointer for a cloned node will be the original node's `random.next` node.

3. **Step 3: Separate the Cloned List:**
   - Finally, detach the cloned list from the original list by restoring the original `next` pointers and setting the `next` pointers for the cloned list.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the linked list. We make multiple passes over the list (clone, assign random pointers, and separate), but each pass is linear in time complexity.
- **Expected Auxiliary Space Complexity:** O(1), as the algorithm does not use any extra space except for a few temporary variables.

### Code (C++)

```cpp
class Solution {
public:
    Node *copyList(Node *head) {
        if (head == NULL) return NULL;

        Node *t = head;
        while (t != NULL) {
            Node *clone = new Node(t->data);
            clone->next = t->next;
            t->next = clone;
            t = clone->next;
        }

        t = head;
        while (t != NULL) {
            if (t->random != NULL) {
                t->next->random = t->random->next;
            }
            t = t->next->next;
        }

        t = head;
        Node *head2 = head->next;
        Node *clone = head2;

        while (t != NULL) {
            t->next = t->next->next;
            if (clone->next != NULL) {
                clone->next = clone->next->next;
            }
            t = t->next;
            clone = clone->next;
        }

        return head2;
    }
};
```

### Code (Java)

```java
class Solution {
    public Node copyList(Node head) {
        if (head == null) {
            return null;
        }

        Node t = head;
        while (t != null) {
            Node clone = new Node(t.data);
            clone.next = t.next;
            t.next = clone;
            t = clone.next;
        }

        t = head;
        while (t != null) {
            if (t.random != null) {
                t.next.random = t.random.next;
            }
            t = t.next.next;
        }

        t = head;
        Node head2 = head.next;
        Node clone = head2;

        while (t != null) {
            t.next = t.next.next;
            if (clone.next != null) {
                clone.next = clone.next.next;
            }
            t = t.next;
            clone = clone.next;
        }

        return head2;
    }
}
```

### Code (Python)

```python
class Solution:
    def copyList(self, head):
        if head is None:
            return None

        t = head
        while t is not None:
            clone = Node(t.data)
            clone.next = t.next
            t.next = clone
            t = clone.next

        t = head
        while t is not None:
            if t.random is not None:
                t.next.random = t.random.next
            t = t.next.next

        t = head
        head2 = head.next
        clone = head2

        while t is not None:
            t.next = t.next.next
            if clone.next is not None:
                clone.next = clone.next.next
            t = t.next
            clone = clone.next

        return head2
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Your input is valuable for improving the content, and together we can foster a community of learning.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
