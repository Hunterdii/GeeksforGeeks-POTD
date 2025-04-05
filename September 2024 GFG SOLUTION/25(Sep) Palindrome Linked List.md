# _25. Palindrome Linked List_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1)

### Problem Description

Given a singly linked list of integers, the task is to check if the given linked list is a palindrome or not.

- **Example 1:**

  Input: LinkedList: `1 -> 2 -> 1 -> 1 -> 2 -> 1`  
  Output: `true`  
  Explanation: The given linked list is `1 -> 2 -> 1 -> 1 -> 2 -> 1`, which is a palindrome.

- **Example 2:**

  Input: LinkedList: `1 -> 2 -> 3 -> 4`  
  Output: `false`  
  Explanation: The given linked list is `1 -> 2 -> 3 -> 4`, which is not a palindrome.

### My Approach

1. **Two Pointer Technique:**

   - Utilize the slow and fast pointer method to find the middle of the linked list. The slow pointer will move one step at a time, while the fast pointer will move two steps.

2. **Reversing the First Half:**

   - While traversing, reverse the first half of the linked list. This helps in comparing the first half and the second half in a single pass.

3. **Comparison:**

   - Compare the reversed first half with the second half of the linked list. If all corresponding nodes match, the linked list is a palindrome.

4. **Final Result:**
   - If all corresponding elements match, return `true`; otherwise, return `false`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the number of nodes in the linked list, as we traverse the list a constant number of times.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to store pointers.

### Code (C++)

```cpp
class Solution {
public:
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;
        Node *slow = head, *fast = head;
        Node* prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            Node* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        Node* secondHalf = slow;
        if (fast) {
            secondHalf = slow->next;
        }
        Node* firstHalf = prev;
        while (secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};
```

### Code (Java)

```java
class Solution {
    boolean isPalindrome(Node head) {
        if (head == null || head.next == null) return true;

        Node slow = head, fast = head, prev = null;

        while (fast != null && fast.next != null) {
            fast = fast.next.next;

            Node next = slow.next;
            slow.next = prev;
            prev = slow;
            slow = next;
        }

        Node secondHalf = slow;
        if (fast != null) {
            secondHalf = slow.next;
        }

        Node firstHalf = prev;
        while (secondHalf != null) {
            if (firstHalf.data != secondHalf.data) {
                return false;
            }
            firstHalf = firstHalf.next;
            secondHalf = secondHalf.next;
        }

        return true;
    }
}
```

### Code (Python)

```python
class Solution:
    def isPalindrome(self, head):
        if not head or not head.next:
            return True

        slow = head
        fast = head
        prev = None

        while fast and fast.next:
            fast = fast.next.next

            next_node = slow.next
            slow.next = prev
            prev = slow
            slow = next_node

        second_half = slow
        if fast:
            second_half = slow.next

        first_half = prev
        while second_half:
            if first_half.data != second_half.data:
                return False
            first_half = first_half.next
            second_half = second_half.next

        return True
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
