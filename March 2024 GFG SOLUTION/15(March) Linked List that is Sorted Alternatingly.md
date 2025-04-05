## 15. Linked List Sorted Alternatingly

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1)

### Problem Description

You are given a Linked list of size n. The list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.

**Example:**

Input:

```
n = 6
LinkedList = 1->9->2->8->3->7
```

Output:

```
1 2 3 7 8 9

```

Explanation:
After sorting the given list will be 1->2->3->7->8->9.

**Your Task:**

You do not need to read input or print anything. The task is to complete the function `sort()` which should sort the linked list of size n in non-decreasing order.

Expected Time Complexity: O(n), where n is the number of nodes in the linked list.
Expected Auxiliary Space Complexity: O(1), where n is the number of nodes in the linked list, for the recursive stack space used by the merge sort algorithm.

**Constraints:**

- 1 <= Number of nodes <= 100
- 0 <= Values of the elements in linked list <= 10^3

### My Approach

Certainly! Here's your approach described in words:

1. **Merge Sort Implementation**:

   - We implement the merge sort algorithm for sorting the linked list in non-decreasing order.

2. **Base Cases**:

   - If the linked list is empty or has only one node, it is already considered sorted, so we return the head of the list.

3. **Finding the Middle Node**:

   - We find the middle node of the linked list using the slow and fast pointer technique. This allows us to split the list into two halves.

4. **Recursively Sorting Halves**:

   - We recursively sort each half of the list by calling the `mergeSort` function on each half.

5. **Merging Sorted Halves**:

   - We merge the sorted halves using the `merge` function. This involves comparing the values of nodes from both halves and merging them in non-decreasing order.

6. **Merging Process**:

   - We merge the sorted halves by comparing the values of nodes from both halves and merging them into a single sorted list.

7. **Updating Head**:
   - Finally, we update the head of the list to point to the merged and sorted list obtained from the `mergeSort` function.

### Code (C++)

```cpp
class Solution {
public:
    Node* mergeSort(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* mid = findMiddle(head);
        Node* nextToMid = mid->next;

        mid->next = nullptr;
        Node* left = mergeSort(head);
        Node* right = mergeSort(nextToMid);

        return merge(left, right);
    }

    Node* merge(Node* left, Node* right) {
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }

        Node* result = nullptr;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }

        return result;
    }

    Node* findMiddle(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    void sort(Node **head) {
        *head = mergeSort(*head);
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
