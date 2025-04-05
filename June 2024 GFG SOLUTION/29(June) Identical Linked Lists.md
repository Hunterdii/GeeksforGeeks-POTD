## 29. Identical Linked Lists

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/identical-linked-lists/1)

### Problem Description

Given two singly linked lists, determine if they are identical. Two linked lists are identical if they have the same data elements in the same order.

**Example:**

Input:

```
LinkedList1: 1->2->3->4->5->6
LinkedList2: 99->59->42->20
```

Output:

```
false
```

Explanation:
Both linked lists contain the same elements in the same order.

### My Approach

1. **Traversal and Comparison:**

   - Traverse both linked lists simultaneously.
   - Compare data elements of corresponding nodes.
   - If at any point, data elements differ, return `false`.
   - If one list ends before the other, return `false` (lists are of different lengths).
   - If both lists are traversed completely without differences, return `true`.

2. **Edge Cases:**

   - Handle cases where one or both lists are empty.

3. **Time and Space Complexity:**
   - **Expected Time Complexity:** O(n), where n is the number of nodes in the longer list.
   - **Expected Auxiliary Space Complexity:** O(1), as no extra space is used apart from a few variables for pointers.

### Code Snippets

### C++

```cpp
bool areIdentical(Node *head1, Node *head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == nullptr && head2 == nullptr);
}
```

### Java

```java
public class Solution {
    public boolean areIdentical(Node head1, Node head2) {
        while (head1 != null && head2 != null) {
            if (head1.data != head2.data)
                return false;
            head1 = head1.next;
            head2 = head2.next;
        }
        return (head1 == null && head2 == null);
    }
}
```

### Python

```python
def areIdentical(head1, head2):
    while head1 is not None and head2 is not None:
        if head1.data != head2.data:
            return False
        head1 = head1.next
        head2 = head2.next
    return head1 == head2
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
