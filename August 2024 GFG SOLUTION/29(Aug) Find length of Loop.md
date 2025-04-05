# **29. Find Length of Loop**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-length-of-loop/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return `0`.

- **Input:**
  - A linked list represented by its head node.
  - An integer `c` representing the position of the node (1-based indexing) which is connected to the last node to form the loop. If `c` is `0`, there is no loop.
- **Output:**
  - The length of the loop if it exists, otherwise return `0`.

**Examples:**

Input:

```
LinkedList: 25->14->19->33->10->21->39->90->58->45, c = 4
```

Output:

```
7
```

Explanation: The loop is from 33 to 45. So the length of the loop is `33->10->21->39->90->58->45 = 7`.

Input:

```
LinkedList: 5->4, c = 0
```

Output:

```
0
```

Explanation: There is no loop.

### My Approach

1. **Two Pointers (Floyd's Cycle Detection):**

   - Use two pointers, `slow` and `fast`. Both start at the head of the linked list.
   - Move `slow` one step and `fast` two steps at a time. If there is a loop, `slow` and `fast` will meet at some point inside the loop.

2. **Detecting Loop Size:**

   - Once `slow` and `fast` meet, initialize a counter `loopSize` and start a new pointer from the meeting point.
   - Move this new pointer around the loop until it meets `slow` again, counting the number of steps taken. This gives the length of the loop.

3. **Edge Cases:**
   - If the linked list is empty or has only one node with no loop, return `0`.
   - If `c = 0`, return `0` since there is no loop.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the linked list. We traverse the linked list once to detect the loop and, if a loop is found, another traversal to calculate its length.
- **Expected Auxiliary Space Complexity:** O(1), since we only use a constant amount of extra space for the pointers.

### Code (C++)

```cpp
class Solution {
public:
    int countNodesinLoop(Node* head) {
        if (!head || !head->next) return 0;

        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                int loopSize = 1;
                Node* current = slow;
                while (current->next != slow) {
                    current = current->next;
                    loopSize++;
                }
                return loopSize;
            }
        }

        return 0;
    }
};
```

### Code (Java)

```java
class Solution {
    public int countNodesinLoop(Node head) {
        if (head == null || head.next == null) return 0;

        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                int loopSize = 1;
                Node current = slow;
                while (current.next != slow) {
                    current = current.next;
                    loopSize++;
                }
                return loopSize;
            }
        }

        return 0;
    }
}
```

### Code (Python)

```python
class Solution:
    def countNodesInLoop(self, head):
        if not head or not head.next:
            return 0

        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                loop_size = 1
                current = slow
                while current.next != slow:
                    current = current.next
                    loop_size += 1
                return loop_size

        return 0
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
