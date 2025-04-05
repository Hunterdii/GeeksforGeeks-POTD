# _04. Deletion and Reverse in Circular Linked List_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1)

### Problem Description

Given a Circular Linked List, the task is to delete a given node (key) from the circular linked list and then reverse the circular linked list. The key may or may not be present in the list.

**Note:**

- You don't have to print anything, just return the head of the modified list in each function.
- Nodes may consist of duplicate values.

**Examples:**

Input: Linked List: `2->5->7->8->10`, key = `8`  
Output: `10->7->5->2`  
Explanation: After deleting `8` from the given circular linked list, it has elements as `2, 5, 7, 10`. Now, reversing this list will result in `10, 7, 5, 2` & the resultant list is also circular.

Input: Linked List: `1->7->8->10`, key = `8`  
Output: `10->7->1`  
Explanation: After deleting `8` from the given circular linked list, it has elements as `1, 7, 10`. Now, reversing this list will result in `10, 7, 1` & the resultant list is also circular.

Input: Linked List: `3->6->4->10`, key = `9`  
Output: `10->4->6->3`  
Explanation: Since there is no key present in the list, simply reverse the list & the resultant list is also circular.

### My Approach

1. **Reverse the Circular Linked List:**

   - Use three pointers: `prev`, `current`, and `nextNode` to reverse the links in the circular linked list until `current` returns to the head.

2. **Delete the Node:**

   - Traverse the circular linked list using a pointer, comparing each node's data with the key.
   - If the key is found, adjust the pointers to remove the node. Handle special cases for the head and for when the list becomes empty.

3. **Return the Modified List:**
   - Ensure that the returned list remains circular after deletion and reversal.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the linked list once to delete the node and once to reverse it, where n is the number of nodes in the list.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    Node* reverse(Node* head) {
        if (head == NULL || head->next == head) {
            return head;
        }

        Node* prev = head;
        Node* current = head->next;
        Node* nextNode;

        while (current != head) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head->next = prev;
        return prev;
    }

    Node* deleteNode(Node* head, int key) {
        if (head == NULL) {
            return head;
        }

        Node *current = head, *prev = NULL;

        do {
            if (current->data == key) {
                if (current == head && current->next == head) {
                    return NULL;
                }

                if (current == head) {
                    Node* tail = head;
                    while (tail->next != head) {
                        tail = tail->next;
                    }
                    head = current->next;
                    tail->next = head;
                } else {
                    prev->next = current->next;
                }
                return head;
            }
            prev = current;
            current = current->next;
        } while (current != head);

        return head;
    }
};
```

### Code (Java)

```java
class Solution {
    Node reverse(Node head) {
        if (head == null || head.next == head) {
            return head;
        }

        Node prev = head;
        Node current = head.next;
        Node nextNode;

        while (current != head) {
            nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }

        head.next = prev;
        return prev;
    }

    Node deleteNode(Node head, int key) {
        if (head == null) {
            return head;
        }

        Node current = head, prev = null;

        do {
            if (current.data == key) {
                if (current == head && current.next == head) {
                    return null;
                }

                if (current == head) {
                    Node tail = head;
                    while (tail.next != head) {
                        tail = tail.next;
                    }
                    head = current.next;
                    tail.next = head;
                } else {
                    prev.next = current.next;
                }
                return head;
            }
            prev = current;
            current = current.next;
        } while (current != head);

        return head;
    }
}
```

### Code (Python)

```python
class Solution:
    def reverse(self, head):
        if head is None or head.next == head:
            return head

        prev = head
        current = head.next
        nextNode = None

        while current != head:
            nextNode = current.next
            current.next = prev
            prev = current
            current = nextNode

        head.next = prev
        return prev

    def deleteNode(self, head, key):
        if head is None:
            return head

        current = head
        prev = None

        while True:
            if current.data == key:
                if current == head and current.next == head:
                    return None

                if current == head:
                    tail = head
                    while tail.next != head:
                        tail = tail.next
                    head = current.next
                    tail.next = head
                else:
                    prev.next = current.next
                return head

            prev = current
            current = current.next

            if current == head:
                break

        return head
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
