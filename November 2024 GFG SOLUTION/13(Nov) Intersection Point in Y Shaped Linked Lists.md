# _13. Intersection Point in Y Shaped Linked Lists_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1)

> **Note:** I'm currently in the middle of my exams until November 19, so I’ll be uploading daily POTD solutions, but not at a fixed time. Apologies for any inconvenience, and thank you for your patience!

## Problem Description

Given two singly linked lists, return the point where the two linked lists intersect. If there is no intersection, return -1.

### Examples:

**Input:**

```
Linked list 1: 4 -> 1 -> 8 -> 4 -> 5
Linked list 2: 5 -> 6 -> 1 -> 8 -> 4 -> 5
```

**Output:**

```
8
```

**Explanation:**  
The linked lists merge at node with value 8, which is the starting point of the common part.

**Input:**

```
Linked list 1: 4 -> 4 -> 4 -> 4 -> 4
Linked list 2: 4 -> 4 -> 4
```

**Output:**

```
4
```

**Explanation:**  
Both lists start with the same values. The common part starts at node with value 4.

**Input:**

```
Linked list 1: 1 -> 2 -> 3
Linked list 2: 4 -> 5 -> 6
```

**Output:**

```
-1
```

**Explanation:**  
There is no common part, so the function returns -1.

## My Approach

1. **Two-Pointer Technique:**

   - Use two pointers, one starting at the head of each linked list.
   - Traverse both linked lists. When a pointer reaches the end of one list, redirect it to the head of the other list.
   - Continue until the two pointers either meet at the intersection point or reach the end without meeting.

2. **Why This Works:**

   - By switching pointers between the lists, both pointers traverse the same combined distance, effectively synchronizing their meeting point.

3. **Edge Cases:**
   - If either list is empty, return -1.
   - If there is no intersection, both pointers will reach the end of their respective lists and the function will return -1.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(m + n), where `m` and `n` are the lengths of the two linked lists. We perform a linear traversal over each list.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

## Code (C++)

```cpp
class Solution {
public:
    int intersectPoint(Node* head1, Node* head2) {
        if (!head1 || !head2) return -1;

        Node* ptr1 = head1;
        Node* ptr2 = head2;
        while (ptr1 != ptr2) {
            ptr1 = ptr1 ? ptr1->next : head2;
            ptr2 = ptr2 ? ptr2->next : head1;
        }
        return ptr1 ? ptr1->data : -1;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

### Alternative Approach (Using Hash Set)

```cpp
class Solution {
public:
    int intersectPoint(Node* head1, Node* head2) {
        unordered_set<Node*> nodes;
        while (head1) {
            nodes.insert(head1);
            head1 = head1->next;
        }
        while (head2) {
            if (nodes.count(head2)) return head2->data;
            head2 = head2->next;
        }
        return -1;
    }
};
```

</details>

## Code (Java)

```java
class Intersect {

    int intersectPoint(Node head1, Node head2) {
        if (head1 == null || head2 == null) return -1;

        Node ptr1 = head1;
        Node ptr2 = head2;

        while (ptr1 != ptr2) {
            ptr1 = (ptr1 != null) ? ptr1.next : head2;
            ptr2 = (ptr2 != null) ? ptr2.next : head1;
        }

        return (ptr1 != null) ? ptr1.data : -1;
    }
}
```

## Code (Python)

```python
def intersetPoint(head1, head2):
    if not head1 or not head2:
        return -1

    ptr1 = head1
    ptr2 = head2

    while ptr1 != ptr2:
        ptr1 = ptr1.next if ptr1 else head2
        ptr2 = ptr2.next if ptr2 else head1

    return ptr1.data if ptr1 else -1
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
