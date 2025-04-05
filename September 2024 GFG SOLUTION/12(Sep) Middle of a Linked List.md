# **12. Middle of a Linked List**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/11)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given the head of a linked list, find the middle element. If the list has an odd number of nodes, return the exact middle. If the list has an even number of nodes, return the second middle.

**Examples:**

Input:

```
Linked list: 1->2->3->4->5
```

Output:

```
3
```

Explanation: The middle element of the linked list 1->2->3->4->5 is 3.

Input:

```
Linked list: 2->4->6->7->5->1
```

Output:

```
7
```

Explanation: The middle element of the linked list 2->4->6->7->5->1 is 7.

### My Approach

1. **Two Pointer Approach:**

   - Initialize two pointers, `slow` and `fast`. Both pointers start at the head of the linked list.
   - Move the `slow` pointer one step at a time, and the `fast` pointer two steps at a time.
   - When the `fast` pointer reaches the end of the linked list, the `slow` pointer will be at the middle.

2. **Edge Case:**
   - If the list is empty (`head == nullptr`), return `-1`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the linked list. Each node is visited once as we move the `slow` and `fast` pointers through the list.
- **Expected Auxiliary Space Complexity:** O(1), as no extra space is used other than a few pointers.

### Code (C++)

```cpp
class Solution {
public:
    int getMiddle(Node* head) {
        if (head == nullptr)
            return -1;
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};
```

### Code (Java)

```java
class Solution {
    int getMiddle(Node head) {
        if (head == null) {
            return -1;
        }
        Node slow = head;
        Node fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow.data;
    }
}
```

### Code (Python)

```python
class Solution:
    def findMid(self, head):
        if head is None:
            return -1

        slow = head
        fast = head

        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next

        return slow.data
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
