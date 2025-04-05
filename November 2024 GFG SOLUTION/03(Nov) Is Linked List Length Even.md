# _03. Is Linked List Length Even?_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1)

## Problem Description

Given a linked list, the task is to determine whether the length of the linked list is even or odd. You need to complete the function `isLengthEven()` which takes the head of the linked list as an argument and returns `true` if the length is even, otherwise `false`.

#### Examples:

**Input:**  
Linked List: `12->52->10->47->95->0`  
**Output:**  
true  
**Explanation:** The length of the linked list is 6, which is even.

**Input:**  
Linked List: `9->4->3`  
**Output:**  
false  
**Explanation:** The length of the linked list is 3, which is odd.

## My Approach

1. **Traversal Strategy with Fast Pointer:**

   - Use a fast pointer to traverse the linked list in steps of two nodes at a time.
   - If the fast pointer reaches the end of the list (`NULL`), the length is even.
   - If the fast pointer does not reach the end (i.e., it points to a node instead of `NULL`), the length is odd.

2. **Rationale Behind Using a Fast Pointer:**
   - By moving the pointer in steps of two, we can determine if the length is even without counting each node, making the approach efficient.
   - The final condition check is straightforward: if the fast pointer is `NULL`, the length is even; otherwise, it is odd.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the linked list, as we traverse the list at most once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

## Code (C++)

### Main Approach

```cpp
class Solution {
public:
    bool isLengthEven(struct Node** head) {
        Node* current = *head;
        int count = 0;

        while (current != NULL) {
            count++;
            current = current->next;
        }

        return (count % 2 == 0);
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approachs </h2></summary>

1. **Fast Pointer Technique:**

```cpp
class Solution {
public:
    bool isLengthEven(struct Node** head) {
        Node* fast = *head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
        }

        return (fast == NULL);
    }
};
```

2. **Simplified Fast Pointer Check:**

```cpp
class Solution {
public:
    bool isLengthEven(struct Node** head) {
        struct Node* curr = *head;
        while (curr && curr->next) {
            curr = curr->next->next;
        }
        return (curr == NULL);
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    public boolean isLengthEven(Node head) {
        Node fast = head;

        while (fast != null && fast.next != null) {
            fast = fast.next.next;
        }

        return fast == null;
    }
}
```

## Code (Python)

```python
class Solution:
    def isLengthEven(self, head):
        fast = head

        while fast is not None and fast.next is not None:
            fast = fast.next.next

        return fast is None
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
