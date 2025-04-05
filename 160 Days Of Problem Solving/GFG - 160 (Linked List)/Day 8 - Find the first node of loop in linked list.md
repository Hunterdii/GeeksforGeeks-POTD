---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Linked-List
  - two-pointer-algorithm
---

# 🚀 _Day 8. Find the First Node of Loop in Linked List_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/linked-list-gfg-160/problem/find-the-first-node-of-loop-in-linked-list--170645)

## 💡 **Problem Description:**

You are given the head of a singly linked list. If a loop exists in the list, return the first node of the loop; otherwise, return `NULL`.

### Input Format:

- A singly linked list `head`.
- An integer `pos` which denotes the 1-based index of the node where the last node points to create the loop.
- If `pos = 0`, there is no loop in the linked list.

### Output Format:

- Return the first node of the loop if it exists; otherwise, return `-1`.

## 🔍 **Example Walkthrough:**

**Input:**  
`Linked List = [1 -> 2 -> 3 -> 4 -> 5]`

![image](https://github.com/user-attachments/assets/5665433c-1636-4e86-b5ee-c2b220327255)

`pos = 3`

**Output:**  
`3`

**Explanation:**  
The last node points to the node with value `3`, creating a loop. Hence, the first node of the loop is `3`.

**Input:**  
`Linked List = [10 -> 20 -> 30]`

![image](https://github.com/user-attachments/assets/df0403ea-5b76-4d43-903f-4c71eea10d9f)

`pos = 0`

**Output:**  
`-1`

**Explanation:**  
There is no loop in the given linked list. Therefore, the output is `-1`.

### Constraints:

- $`1 <= no. of nodes <= 10^6`$
- $`1 <= node->data <= 10^6`$

## 🎯 **My Approach:**

1. **Detect the Loop (Floyd’s Cycle Detection Algorithm):**  
   Use two pointers (`slow` and `fast`) to detect the presence of a loop:

   - Move `slow` one step at a time.
   - Move `fast` two steps at a time.
   - If the two pointers meet, a loop exists in the linked list.

2. **Find the Start of the Loop:**  
   If a loop is detected:

   - Reset `slow` to the `head`.
   - Move both `slow` and `fast` one step at a time.
   - The point where they meet is the first node of the loop.

3. **Return Result:**
   - If a loop exists, return the first node of the loop.
   - Otherwise, return `-1`.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the linked list. The two-pointer technique ensures that each node is visited at most twice.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the two pointers.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    Node* findFirstNode(Node* head) {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            if ((slow = slow->next) == (fast = fast->next->next)) {
                for (slow = head; slow != fast; slow = slow->next, fast = fast->next);
                return slow;
            }
        }
        return nullptr;
    }
};
```

## Code (Java)

```java
class Solution {
    public static Node findFirstNode(Node head) {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            if ((slow = slow.next) == (fast = fast.next.next)) {
                for (slow = head; slow != fast; slow = slow.next, fast = fast.next);
                return slow;
            }
        }
        return null;
    }
}
```

## Code (Python)

```python
class Solution:
    def findFirstNode(self, head):
        slow, fast = head, head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                slow = head
                while slow != fast:
                    slow, fast = slow.next, fast.next
                return slow
        return None
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
