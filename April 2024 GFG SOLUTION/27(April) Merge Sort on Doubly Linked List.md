## 27. Merge Sort on Doubly Linked List

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1)

### Problem Description

Given a pointer/reference to the head of a doubly linked list of \( n \) nodes, the task is to sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

**Example:**

Input:

```
n = 8
values = {7, 3, 5, 2, 6, 4, 1, 8}
```

Output:

```
Non-decreasing order: 1 2 3 4 5 6 7 8
Non-increasing order: 8 7 6 5 4 3 2 1
```

Explanation: After sorting the given linked list in both ways, the resultant matrix will be as given in the first two lines of output, where the first line is the output for non-decreasing order, and the next line is for non-increasing order.

### My Approach

1. **Merge Sort Algorithm:**
   - Implement the Merge Sort algorithm for doubly linked lists.
2. **Merge Function:**
   - Write a function to merge two sorted doubly linked lists into a single sorted list.
3. **Find Middle and Divide:**
   - Write a function to find the middle of the doubly linked list and divide it into two halves.
4. **Merge Sort Recursive:**
   - Implement the recursive Merge Sort algorithm for doubly linked lists by recursively dividing the list into sublists and merging them back together in sorted order.
5. **Sort Doubly Linked List:**
   - Write a function to initiate the Merge Sort process and return the sorted doubly linked list.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(n \log n) \), as Merge Sort has a time complexity of \( O(n \log n) \) for sorting \( n \) elements.
- **Expected Auxiliary Space Complexity:** \( O(\log n) \), as Merge Sort has a space complexity of \( O(\log n) \) due to recursive function calls.

### Code (C++)

```cpp
class Solution {
public:
    struct Node* mergeSort(struct Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        struct Node* mid = getMid(head);
        struct Node* nextToMid = mid->next;
        mid->next = nullptr;
        nextToMid->prev = nullptr;

        struct Node* left = mergeSort(head);
        struct Node* right = mergeSort(nextToMid);

        return merge(left, right);
    }

    struct Node* merge(struct Node* left, struct Node* right) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }

        struct Node* result = nullptr;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
            if (result->next) {
                result->next->prev = result;
            }
        } else {
            result = right;
            result->next = merge(left, right->next);
            if (result->next) {
                result->next->prev = result;
            }
        }

        return result;
    }

    struct Node* getMid(struct Node* head) {
        struct Node* slow = head;
        struct Node* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    struct Node* sortDoubly(struct Node* head) {
        return mergeSort(head);
    }
};
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
