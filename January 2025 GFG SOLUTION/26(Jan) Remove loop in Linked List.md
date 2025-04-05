# _26. Remove Loop in Linked List_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1)

## Problem Description

You are given the head of a linked list that may contain a loop. A loop exists when the last node in the linked list connects back to a node in the same list. Your task is to remove the loop from the linked list (if it exists), ensuring the linked list remains intact.

### Custom Input Format:

The input consists of:

1. A `head` node pointing to the start of a singly linked list.
2. A `pos` value (1-based index) denoting the position of the node to which the last node points:
   - If `pos = 0`, it means the last node points to `null`, indicating there is no loop.

### Output:

The function returns `true` if:

1. No loop exists in the list, or
2. The loop is successfully removed, and the linked list is restored.

Otherwise, it returns `false`.

## Examples:

**Input:**  
`head = 1 -> 3 -> 4, pos = 2`  
**Output:**  
`true`  
**Explanation:**  
The linked list looks like this before removing the loop:

![image](https://github.com/user-attachments/assets/47c0bb4b-72ec-4cc2-911e-32061fdc05d1)

After removing the loop, the list becomes:

**Input:**  
`head = 1 -> 8 -> 3 -> 4, pos = 0`  
**Output:**  
`true`  
**Explanation:**

![image](https://github.com/user-attachments/assets/8fab7fdb-e10e-4415-8edf-871794eb5eb8)

The linked list has no loop and remains unchanged.

**Input:**  
`head = 1 -> 2 -> 3 -> 4, pos = 1`  
**Output:**  
`true`  
**Explanation:**  
The linked list looks like this before removing the loop:

![image](https://github.com/user-attachments/assets/98d857f2-fad0-4f50-af27-16c4e651d583)

After removing the loop, the list becomes:

## Constraints:

- 1 ≤ size of linked list ≤ $10^5$

## My Approach

1. **Detect Loop in the Linked List**:

   - Use Floyd’s Cycle-Finding Algorithm (Tortoise and Hare) to detect a loop in the linked list.
   - If the `slow` and `fast` pointers meet, a loop is confirmed.

2. **Find the Starting Node of the Loop**:

   - Move one pointer back to the `head` and traverse both pointers (slow and fast) one step at a time.
   - The node where they meet is the starting point of the loop.

3. **Break the Loop**:
   - Traverse the loop to find the node whose `next` pointer points to the starting node of the loop.
   - Set this node’s `next` pointer to `null`, breaking the loop.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(N), where `N` is the size of the linked list. We traverse the linked list once to detect the loop and another time to remove it.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of space (two pointers).

## Code (C++)

```cpp
class Solution {
public:
    void removeLoop(Node* head) {
        Node *slow = head, *fast = head;
        while (fast && fast->next && (slow = slow->next) != (fast = fast->next->next));
        if (!fast || !fast->next) return;
        for (slow = head; slow != fast; slow = slow->next, fast = fast->next);
        while (fast->next != slow) fast = fast->next;
        fast->next = nullptr;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

## Using Hashing

### Approach:

1. Use a hash table (or a set in Python) to keep track of visited nodes.
2. Traverse the linked list:
   - If a node is revisited (i.e., it's already in the hash table), then a loop exists.
   - Break the loop by setting the `next` pointer of the previous node to `null`.
3. If the end of the list is reached without revisiting any node, there is no loop.

**Drawback:** This method uses additional space and is less efficient.

### Complexity:

- **Expected Time Complexity:** O(n), as we traverse each node once and perform constant-time operations to check for presence in the hash table.
- **Expected Auxiliary Space Complexity:** O(n), as we use a hash table to store visited nodes.

## Code (C++)

```cpp
class Solution {
public:
    void removeLoop(Node* head) {
        std::unordered_set<Node*> visited;
        Node* prev = nullptr;
        while (head) {
            // If the node is already visited, break the loop
            if (visited.find(head) != visited.end()) {
                prev->next = nullptr;
                break;
            }
            visited.insert(head);  // Mark the current node as visited
            prev = head;
            head = head->next;
        }
    }
};
```

## Code (Java)

```java
import java.util.HashSet;

class Solution {
    public static void removeLoop(Node head) {
        HashSet<Node> visited = new HashSet<>();
        Node prev = null;

        while (head != null) {
            // If the node is already visited, break the loop
            if (visited.contains(head)) {
                prev.next = null;
                break;
            }
            visited.add(head);  // Mark the current node as visited
            prev = head;
            head = head.next;
        }
    }
}
```

## Code (Python)

```python
class Solution:
    def removeLoop(self, head):
        visited = set()
        prev = None

        while head:
            # If the node is already visited, break the loop
            if head in visited:
                prev.next = None
                break
            visited.add(head)  # Mark the current node as visited
            prev = head
            head = head.next
```

This **hashing-based approach** is simple to implement but less space-efficient compared to the Floyd’s cycle detection method.

</details>

## Code (Java)

```java
class Solution {
    public static void removeLoop(Node head) {
        Node slow = head, fast = head;
        while (fast != null && fast.next != null && (slow = slow.next) != (fast = fast.next.next));
        if (fast == null || fast.next == null) return;
        for (slow = head; slow != fast; slow = slow.next, fast = fast.next);
        while (fast.next != slow) fast = fast.next;
        fast.next = null;
    }
}
```

## Code (Python)

```python
class Solution:
    def removeLoop(self, head):
        slow, fast = head, head
        while fast and fast.next and (slow := slow.next) != (fast := fast.next.next): pass
        if not fast or not fast.next: return
        slow = head
        while slow != fast: slow, fast = slow.next, fast.next
        while fast.next != slow: fast = fast.next
        fast.next = None
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
