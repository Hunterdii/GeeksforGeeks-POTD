# _26. Occurrence of an Integer in a Linked List_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1)

_Note: My externals exams are currently ongoing, which is the reason for the delayed upload **Sorry** ._

## Problem Description

Given a singly linked list and an integer key, the task is to count the number of occurrences of the given key in the linked list.

- If the key is found in the list, return the number of occurrences.
- If the key is not present, return 0.

#### Examples:

**Input:**  
Linked List: `1->2->1->2->1->3->1`, Key = `1`  
**Output:**  
4  
**Explanation:** 1 appears 4 times.

**Input:**  
Linked List: `1->2->1->2->1`, Key = `3`  
**Output:**  
0  
**Explanation:** 3 appears 0 times.

## My Approach

1. **Traversal through the Linked List:**

   - Initialize a counter to zero.
   - Traverse each node in the list from the head to the end.
   - For each node, check if its data matches the key. If it does, increment the counter.

2. **Returning the Count:**
   - After traversing the entire list, return the count as the final result.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** (O(n)), where (n) is the number of nodes in the linked list, as we are traversing each node once.
- **Expected Auxiliary Space Complexity:** (O(1)), as we only use a constant amount of additional space to store the counter variable.

## Code (C++)

```cpp
class Solution {
public:
    int count(Node* head, int key) {
        int count = 0;
        for (Node* current = head; current != nullptr; current = current->next) {
            count += (current->data == key);
        }
        return count;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approachs </h2></summary>

_1)_

```cpp
class Solution {
public:
    int count(struct Node* head, int key) {
        int count = 0;
        while (head != NULL) {
            count += (head->data == key);
            head = head->next;
        }
        return count;
    }
};
```

_2)_

```cpp
class Solution {
  public:
    int count(Node* head, int key) {
        int count = 0;
        while (head) {
            if (head->data == key)
                ++count;
            head = head->next;
        }
        return count;
    }
};
```

_3)_

```cpp
 class Solution {
  public:
    int count(struct Node* head, int key) {
        struct Node* current = head;
        int count = 0;
        while (current != NULL) {
            if (current->data == key)
                count++;
            current = current->next;
        }
        return count;
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    public int count(Node head, int key) {
        int count = 0;
        Node current = head;
        while (current != null) {
            count += (current.data == key) ? 1 : 0;
            current = current.next;
        }
        return count;
    }
}
```

## Code (Python)

```python
class Solution:
    def count(self, head, key):
        count = 0
        current = head
        while current:
            count += 1 if current.data == key else 0
            current = current.next
        return count
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
