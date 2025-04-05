# _20. Merge Two Sorted Linked Lists_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1)

## **Problem Description**

Given the heads of two sorted linked lists, the task is to merge the two lists into a single sorted linked list and return the head of the merged list.

### **Examples**

#### Example 1:

**Input:**  
`head1 = 5 -> 10 -> 15 -> 40`  
`head2 = 2 -> 3 -> 20`

**Output:**  
`2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40`  
**Explaination**:<br/>

<img src="https://github.com/user-attachments/assets/d1735740-3fe4-4432-9329-b377c5b6b25e" width="50%">

#### Example 2:

**Input:**  
`head1 = 1 -> 1`  
`head2 = 2 -> 4`

**Output:**  
`1 -> 1 -> 2 -> 4`

### **Constraints:**

- 1 <= no. of nodes<= $10^3$
- $`0 <= node->data <= 10^5`$

## **My Approach**

### **Iterative Approach:**

1. Create a dummy node to simplify the merging process and maintain a pointer `tail` starting at the dummy node.
2. Traverse both linked lists using two pointers, `head1` and `head2`.
   - Compare the data of the current nodes from both lists.
   - Attach the node with the smaller value to `tail` and move the pointer of the respective list.
3. Once one of the lists is completely traversed, attach the remaining nodes of the other list to `tail`.
4. Return the merged list starting from `dummy.next`.

### **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:**  
  O(n + m), where `n` and `m` are the lengths of the two linked lists. Each node is visited exactly once.
- **Expected Auxiliary Space Complexity:**  
  O(1), as no additional space is used except for a few variables.

## **Code (C)**

```c
struct Node* sortedMerge(struct Node* head1, struct Node* head2) {
    struct Node dummy = {0, NULL}, *tail = &dummy;
    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    tail->next = head1 ? head1 : head2;
    return dummy.next;
}
```

## **Code (C++)**

### **Iterative Approach (Tail Insertion Merge)**

```cpp
class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(0), *tail = &dummy;
        while (head1 && head2) {
            tail->next = (head1->data <= head2->data) ? head1 : head2;
            tail = tail->next;
            if (head1->data <= head2->data) head1 = head1->next;
            else head2 = head2->next;
        }
        tail->next = head1 ? head1 : head2;
        return dummy.next;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

### **Recursive Merge**

- This approach uses recursion to decide which node should be part of the merged list.

1. Compare the data of the nodes at `head1` and `head2`.
2. Recursively determine the `next` pointer of the smaller node by calling the function with the rest of the nodes.
3. Continue until one of the lists is empty, at which point return the other list.

```cpp
class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        if (head1->data <= head2->data) {
            head1->next = sortedMerge(head1->next, head2);
            return head1;
        }
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
};
```

### **Iterative Merge with Two Pointers**

This approach is the same as described above but focuses on using a pointer swapping technique.

```cpp
class Solution {
public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(0), *tail = &dummy;
        for (; head1 && head2; tail = tail->next)
            tail->next = (head1->data <= head2->data) ? std::exchange(head1, head1->next) : std::exchange(head2, head2->next);
        tail->next = head1 ? head1 : head2;
        return dummy.next;
    }
};
```

</details>

## **Code (Java)**

```java
class Solution {
    Node sortedMerge(Node head1, Node head2) {
        Node dummy = new Node(0), tail = dummy;
        while (head1 != null && head2 != null) {
            tail.next = (head1.data <= head2.data) ? head1 : head2;
            if (head1.data <= head2.data) head1 = head1.next;
            else head2 = head2.next;
            tail = tail.next;
        }
        tail.next = (head1 != null) ? head1 : head2;
        return dummy.next;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def sortedMerge(self, head1, head2):
        dummy = Node(0)
        tail = dummy
        while head1 and head2:
            if head1.data <= head2.data:
                tail.next = head1
                head1 = head1.next
            else:
                tail.next = head2
                head2 = head2.next
            tail = tail.next
        tail.next = head1 or head2
        return dummy.next
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
