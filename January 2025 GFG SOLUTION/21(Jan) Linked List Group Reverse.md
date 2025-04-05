# _21. Linked List Group Reverse_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1)

## Problem Description

Given the head of a linked list, the task is to reverse every `k` nodes in the linked list. If the number of nodes is not a multiple of `k`, the left-out nodes at the end should be treated as a group and must also be reversed.

## Examples:

**Input:**  
`head = 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4`  
**Output:**  
`4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5`

![image](https://github.com/user-attachments/assets/388056dd-b4a9-461f-87cf-02fa693672fd)

**Explanation:**  
The first 4 nodes (1, 2, 3, 4) are reversed to become 4, 3, 2, 1.  
The next 4 nodes (5, 6, 7, 8) are reversed to become 8, 7, 6, 5.  
Hence, the resultant linked list is `4 -> 3 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5`.

**Input:**  
`head = 1 -> 2 -> 3 -> 4 -> 5, k = 3`  
**Output:**  
`3 -> 2 -> 1 -> 5 -> 4`

![image](https://github.com/user-attachments/assets/06bf17ba-f494-4b56-9fae-8d69e4b800a1)

**Explanation:**  
The first 3 nodes (1, 2, 3) are reversed to become 3, 2, 1.  
The last 2 nodes (4, 5) are reversed to become 5, 4.  
Hence, the resultant linked list is `3 -> 2 -> 1 -> 5 -> 4`.

### Constraints:

- 1 <= size of linked list <= $10^5$
- 1 <= data of nodes <= $10^6$
- $1 <= k <=$ size of linked list

## My Approach

1. **Reverse Nodes in Groups of Size `k`:**

   - Reverse the first `k` nodes of the list iteratively.
   - Keep track of the current group's head and tail to link the groups appropriately.
   - Repeat the process until all nodes are traversed.

2. **Handling Edge Cases:**

   - If `k = 1`, the list remains unchanged.
   - If the number of remaining nodes is less than `k`, treat them as a single group and reverse them.

3. **Steps:**
   - Start with the head of the linked list and reverse the first `k` nodes.
   - Use three pointers (`prev`, `curr`, `next`) to reverse the nodes within each group.
   - Update the `next` pointer of the previous group's tail to point to the reversed group's head.
   - Repeat the process until all nodes are processed.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the linked list. Each node is visited exactly once during the reversal process.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for pointer manipulation.

## Code (C++)

```cpp
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head || k <= 1) return head;

        Node* curr = head;
        Node* newHead = nullptr;
        Node* tail = nullptr;

        while (curr) {
            Node* groupPrev = nullptr;
            Node* groupCurr = curr;
            int count = 0;

            while (curr && count < k) {
                Node* next = curr->next;
                curr->next = groupPrev;
                groupPrev = curr;
                curr = next;
                count++;
            }

            if (!newHead) newHead = groupPrev;
            if (tail) tail->next = groupPrev;
            tail = groupCurr;
        }

        return newHead;
    }
};
```

## Code (Java)

```java
class Solution {
    public static Node reverseKGroup(Node head, int k) {
        if (head == null || k <= 1) return head;

        Node curr = head, newHead = null, tail = null;

        while (curr != null) {
            Node groupPrev = null, groupCurr = curr;
            int count = 0;

            while (curr != null && count < k) {
                Node next = curr.next;
                curr.next = groupPrev;
                groupPrev = curr;
                curr = next;
                count++;
            }

            if (newHead == null) newHead = groupPrev;
            if (tail != null) tail.next = groupPrev;
            tail = groupCurr;
        }

        return newHead;
    }
}
```

## Code (Python)

```python
class Solution:
    def reverseKGroup(self, head, k):
        if not head or k <= 1:
            return head
        current = head
        new_head = None
        tail = None
        while current:
            group_prev = None
            group_curr = current
            count = 0
            while current and count < k:
                next_node = current.next
                current.next = group_prev
                group_prev = current
                current = next_node
                count += 1
            if not new_head:
                new_head = group_prev
            if tail:
                tail.next = group_prev
            tail = group_curr
        return new_head
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
