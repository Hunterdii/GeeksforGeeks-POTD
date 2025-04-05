# _29. Quick Sort on Linked List_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/quick-sort-on-linked-list/1)

## Problem Description

You are given a linked list. Sort the given linked list using quicksort.

#### Example:

- **Input:** Linked list: 1 -> 6 -> 2  
  **Output:** 1 -> 2 -> 6  
  **Explanation:** After sorting, we have 1, 2, and 6.

- **Input:** Linked list: 1 -> 9 -> 3 -> 8  
  **Output:** 1 -> 3 -> 8 -> 9  
  **Explanation:** After sorting, we have 1, 3, 8, and 9.

### Constraints:

- (1 leq text{size of linked list} leq 10^5)

## My Approach

1. **Divide and Conquer with Merge Function:**

   - This quicksort implementation relies on a recursive merge sort function, using the middle element as a pivot.
   - Split the list into two halves, sort each recursively, and merge the sorted halves.

2. **Splitting the List:**

   - Use the "fast-slow pointer" approach to find the middle node efficiently.
   - Adjust the pointers to break the list at the middle.

3. **Recursive Sorting:**

   - Each half of the list is sorted recursively until reaching the base case (a single node or empty list).

4. **Merge Function:**
   - After splitting, each half is merged based on data values, ensuring that each level of recursion returns a sorted sub-list.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** (O(n log n)) due to dividing the list and merging sorted sublists.
- **Expected Auxiliary Space Complexity:** (O(log n)), considering recursive call stack depth for the quicksort algorithm.

## Code (C++)

```cpp
class Solution {
  public:
    Node* split(Node* head) {
        Node* fast = head;
        Node* slow = head;
        Node* prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev) prev->next = nullptr;
        return slow;
    }

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        if (left->data < right->data) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;
        Node* mid = split(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);
        return merge(left, right);
    }

    Node* quickSort(Node* head) {
        return mergeSort(head);
    }
};
```

## Code (Java)

```java
class GfG {
    private Node split(Node head) {
        Node slow = head, fast = head, prev = null;

        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        if (prev != null) {
            prev.next = null;
        }

        return slow;
    }

    private Node merge(Node left, Node right) {
        if (left == null) return right;
        if (right == null) return left;

        if (left.data < right.data) {
            left.next = merge(left.next, right);
            return left;
        } else {
            right.next = merge(left, right.next);
            return right;
        }
    }

    private Node mergeSort(Node head) {
        if (head == null || head.next == null) return head;

        Node mid = split(head);
        Node left = mergeSort(head);
        Node right = mergeSort(mid);

        return merge(left, right);
    }

    public Node quickSort(Node head) {
        return mergeSort(head);
    }
}
```

## Code (Python)

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def split(self, head):
        slow, fast = head, head
        prev = None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        if prev:
            prev.next = None
        return slow

    def merge(self, left, right):
        if not left:
            return right
        if not right:
            return left
        if left.data < right.data:
            left.next = self.merge(left.next, right)
            return left
        else:
            right.next = self.merge(left, right.next)
            return right

    def mergeSort(self, head):
        if not head or not head.next:
            return head
        mid = self.split(head)
        left = self.mergeSort(head)
        right = self.mergeSort(mid)
        return self.merge(left, right)

    def quickSort(self, head):
        return self.mergeSort(head)
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
