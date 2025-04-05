## 10. Rotate a Linked List

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1)

### Problem Description

Given the head of a singly linked list, the task is to rotate the linked list clockwise by `k` nodes, i.e., left-shift the linked list by `k` nodes, where `k` is a given positive integer smaller than or equal to the length of the linked list.

**Example 1:**

Input:

```
linkedlist: 2->4->7->8->9
k = 3
```

Output:

```
8->9->2->4->7
```

Explanation:

- Rotate 1: 4 -> 7 -> 8 -> 9 -> 2
- Rotate 2: 7 -> 8 -> 9 -> 2 -> 4
- Rotate 3: 8 -> 9 -> 2 -> 4 -> 7

**Example 2:**

Input:

```
linkedlist: 1->2->3->4->5->6->7->8
k = 4
```

Output:

```
5->6->7->8->1->2->3->4
```

### My Approach

1. **Initialization:**

   - Traverse the linked list to find the last node and establish a pointer `p` to it.
   - Iterate through the list `k` times, detaching the first node each time and appending it to the end.

2. **Rotation Logic:**

   - In each rotation, update the head pointer to point to the next node, detach the current head, and attach it to the end by updating `p->next`. Update `p` to point to the newly added node.

3. **Return:**
   - After performing `k` rotations, return the new head of the rotated linked list.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + k), where `n` is the number of nodes in the linked list and `k` is the number of rotations. We traverse the list once to find the tail and perform `k` rotations.
- **Expected Auxiliary Space Complexity:** O(1), as we are only using a constant amount of extra space for pointers.

### Code (C++)

```cpp
class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        Node* p= head;
        while(p->next != NULL){
            p = p->next;
        }
        for(int i=1; i<=k; i++){
            Node* t = head;
            head = head->next;
            t->next = NULL;
            p->next = t;
            p = t;
        }
        return head;
    }
};
```

### Code (Java)

```java
class Solution {
    public Node rotate(Node head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }
        Node p = head;
        while (p.next != null) {
            p = p.next;
        }
        for (int i = 1; i <= k; i++) {
            Node t = head;
            head = head.next;
            t.next = null;
            p.next = t;
            p = t;
        }
        return head;
    }
}
```

### Code (Python)

```python
class Solution:
    def rotate(self, head, k):
        if not head or not head.next or k == 0:
            return head
        p = head
        while p.next:
            p = p.next
        for i in range(k):
            t = head
            head = head.next
            t.next = None
            p.next = t
            p = t

        return head
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
