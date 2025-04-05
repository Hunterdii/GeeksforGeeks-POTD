---
Difficulty: Hard
Source: 160 Days of Problem Solving
Tags:
  - Linked-List
---

# 🚀 _Day 6. Clone List with Next and Random_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/clone-a-linked-list-with-next-and-random-pointer)

## 💡 **Problem Description:**

You are given a special linked list where each node has two pointers:

1. A `next` pointer pointing to the next node.
2. A `random` pointer pointing to any random node in the list or `NULL`.

Your task is to construct a deep copy of the linked list. The copied list should consist of the same number of nodes, and both the `next` and `random` pointers in the new list should be correctly set.

## 🔍 **Example Walkthrough:**

**Input:**  
`LinkedList: 1->2->3->4->5`  
`Pairs: [[1,3],[2,1],[3,5],[4,3],[5,2]]`

<img src="https://github.com/user-attachments/assets/d021f8fa-09eb-49bb-b9f3-a6437b8ca204" width="60%">

**Output:**  
`True`

**Explanation:**  
The copied linked list maintains the same structure:

- Node `1` points to `2` as its `next` and `3` as its `random`.
- Node `2` points to `3` as its `next` and `1` as its `random`.
- Node `3` points to `4` as its `next` and `5` as its `random`.
- Node `4` points to `5` as its `next` and `3` as its `random`.
- Node `5` points to `NULL` as its `next` and `2` as its `random`.

**Input:**  
`LinkedList: 1->3->5->9`  
`Pairs: [[1,1],[3,4]]`  
**Output:**  
`True`

**Explanation:**

- Node `1` points to itself as its `random`.
- Node `3` does not have a valid `random` mapping in the given pairs, so it remains `NULL`.

### Constraints:

- `1 <= number of random pointers <= number of nodes <= 100`
- `0 <= node->data <= 1000`
- `1 <= a, b <= 100`

## 🎯 **My Approach:**

### Steps:

1. **Clone Nodes:**

   - Insert cloned nodes between the original nodes. For example, if the list is `1 -> 2 -> 3`, after cloning it becomes `1 -> 1' -> 2 -> 2' -> 3 -> 3'`.

2. **Update Random Pointers:**

   - For each cloned node, set its `random` pointer to point to the cloned version of the `random` pointer of the original node.

3. **Separate the Cloned List:**
   - Extract the cloned nodes into a separate list while restoring the original list.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the linked list. We iterate through the list a constant number of times.
- **Expected Auxiliary Space Complexity:** O(1), as the algorithm uses no extra space apart from variables for iteration.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    Node* cloneLinkedList(Node* head) {
        if (!head) return nullptr;
        for (Node* t = head; t; t = t->next->next) {
            Node* n = new Node(t->data);
            n->next = t->next;
            t->next = n;
        }
        for (Node* t = head; t; t = t->next->next)
            if (t->random) t->next->random = t->random->next;
        Node* newHead = head->next;
        for (Node* t = head; t; t = t->next) {
            Node* temp = t->next;
            t->next = temp->next;
            if (temp->next) temp->next = temp->next->next;
        }
        return newHead;
    }
};
```

## Code (Java)

```java
class Solution {
    Node cloneLinkedList(Node head) {
        if (head == null) return null;

        for (Node t = head; t != null; t = t.next.next) {
            Node n = new Node(t.data);
            n.next = t.next;
            t.next = n;
        }
        for (Node t = head; t != null; t = t.next.next) {
            if (t.random != null) t.next.random = t.random.next;
        }
        Node newHead = head.next;
        for (Node t = head; t != null; t = t.next) {
            Node temp = t.next;
            t.next = temp.next;
            if (temp.next != null) temp.next = temp.next.next;
        }
        return newHead;
    }
}
```

## Code (Python)

```python
class Solution:
    def cloneLinkedList(self, head):
        if not head:
            return None

        d = {}
        ch = Node(head.data)
        chh = ch
        d[head] = ch

        h = head.next
        while h:
            nn = Node(h.data)
            chh.next = nn
            d[h] = nn
            h = h.next
            chh = nn

        h = head
        chh = ch
        while h:
            if h.random:
                chh.random = d[h.random]
            h = h.next
            chh = chh.next

        return ch
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
