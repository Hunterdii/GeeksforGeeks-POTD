# _24. Detect Loop in Linked List_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1)

## Problem Description

You are given the head of a singly linked list. Your task is to determine if the linked list contains a loop. A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null.

### **Custom Input Format**

- **head**: The head of a singly linked list.
- **pos**: A 1-based index denoting the position of the node to which the last node points. If `pos = 0`, it means the last node points to `null`, indicating no loop exists.

## Examples:

#### Example 1:

**Input:**  
`head: 1 -> 3 -> 4, pos = 2`

**Output:**  
`true`

**Explanation:**  
There exists a loop as the last node points back to the second node.

![image](https://github.com/user-attachments/assets/0522f418-82c4-4391-b791-2d6d68a8f7c1)

#### Example 2:

**Input:**  
`head: 1 -> 8 -> 3 -> 4, pos = 0`

**Output:**  
`false`

**Explanation:**  
There exists no loop in the given linked list.

![image](https://github.com/user-attachments/assets/ce9a73b8-50ed-4695-867d-c283f2472c65)

#### Example 3:

**Input:**  
`head: 1 -> 2 -> 3 -> 4, pos = 1`

**Output:**  
`true`

**Explanation:**  
There exists a loop as the last node points back to the first node.

![image](https://github.com/user-attachments/assets/35e1dcf7-afc6-41f0-a60e-8b98b5a6cbf2)

### Constraints:

- 1 ≤ number of nodes ≤ $10^4$
- 1 ≤ node->data ≤ $10^3$
- `0 ≤ pos ≤ Number of nodes in Linked List`

## **My Approach**

To detect a loop in a linked list, we can use the **Floyd’s Cycle Detection Algorithm (Tortoise and Hare Algorithm)**. This algorithm uses two pointers (`slow` and `fast`) to traverse the list at different speeds. If there is a loop, the fast pointer will eventually meet the slow pointer.

### **Steps**:

1. **Initialize Two Pointers:**
   - Start with `slow` and `fast` pointers, both pointing to the head of the linked list.
2. **Traverse the List:**
   - Move `slow` one step at a time.
   - Move `fast` two steps at a time.
   - If the `fast` pointer reaches `null`, no loop exists.
   - If the `slow` pointer meets the `fast` pointer, a loop is detected.
3. **Return the Result:**
   - If `slow` equals `fast`, return `true`.
   - Otherwise, return `false`.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** **O(n)**, where `n` is the number of nodes in the linked list. Each node is visited at most twice during the traversal.
- **Expected Auxiliary Space Complexity:** **O(1)**, as the algorithm only uses two pointers (`slow` and `fast`) for detection.

## Code (C++)

```cpp
class Solution {
public:
    bool detectLoop(Node* head) {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            if ((slow = slow->next) == (fast = fast->next->next))
                return true;
        }
        return false;
    }
};
```

## Code (Java)

```java
class Solution {
    public static boolean detectLoop(Node head) {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            if ((slow = slow.next) == (fast = fast.next.next))
                return true;
        }
        return false;
    }
}
```

## Code (Python)

```python
class Solution:
    def detectLoop(self, head):
        slow, fast = head, head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                return True
        return False
```

## **Contribution and Support**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
