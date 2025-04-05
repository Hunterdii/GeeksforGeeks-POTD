# _23. Sum of Last N Nodes of Linked List_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-sum-of-last-n-nodes-of-the-linked-list/1)

### Problem Description

Given a singly linked list, calculate the sum of the last `n` nodes. It is guaranteed that `n <= number of nodes`.

- You are provided with a linked list and an integer `n`.
- The task is to calculate the sum of the last `n` nodes in the list.

#### Example 1:

Input:
Linked List: `5->9->6->3->4->10`, `n = 3`

Output:
`17`

Explanation: The sum of the last three nodes in the linked list is `3 + 4 + 10 = 17`.

#### Example 2:

Input:
Linked List: `1->2`, `n = 2`

Output:
`3`

Explanation: The sum of the last two nodes in the linked list is `2 + 1 = 3`.

### My Approach

1. **Two-Pointer Technique**:

   - We use two pointers: `fast` and `slow`. The `fast` pointer is moved `n` nodes ahead from the start.
   - After positioning the `fast` pointer, we move both `fast` and `slow` pointers simultaneously until the `fast` pointer reaches the end of the list. At this point, the `slow` pointer will be positioned at the beginning of the last `n` nodes.
   - Finally, traverse the remaining `n` nodes from the `slow` pointer and calculate their sum.

2. **Edge Cases**:
   - If `n <= 0`, return `0` as there are no nodes to sum.
   - If the list is empty (`head == NULL`), return `0`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(L), where `L` is the total number of nodes in the linked list. This is because we traverse the linked list only once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of extra space (two pointers).

### Code (C++)

```cpp
class Solution {
public:
    int sumOfLastN_Nodes(struct Node* head, int n) {
        if (n <= 0 || head == NULL) return 0;

        Node* fast = head;
        Node* slow = head;

        for (int i = 0; i < n; i++) {
            if (fast == NULL) return 0;
            fast = fast->next;
        }

        int sum = 0;
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        while (slow != NULL) {
            sum += slow->data;
            slow = slow->next;
        }

        return sum;
    }
};
```

### Code (Java)

```java
class Solution {
    public int sumOfLastN_Nodes(Node head, int n) {
        if (n <= 0 || head == null) return 0;

        Node fast = head;
        Node slow = head;

        for (int i = 0; i < n; i++) {
            if (fast == null) return 0;
            fast = fast.next;
        }

        int sum = 0;

        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        while (slow != null) {
            sum += slow.data;
            slow = slow.next;
        }

        return sum;
    }
}
```

### Code (Python)

```python
class Solution:
    def sumOfLastN_Nodes(self, head, n):
        if n <= 0 or head is None:
            return 0

        fast = head
        slow = head

        for _ in range(n):
            if fast is None:
                return 0
            fast = fast.next

        sum_last_n = 0

        while fast is not None:
            fast = fast.next
            slow = slow.next

        while slow is not None:
            sum_last_n += slow.data
            slow = slow.next

        return sum_last_n
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
