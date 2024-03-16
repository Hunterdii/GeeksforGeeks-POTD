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
    // Function to perform merge sort on a linked list
    Node* mergeSort(Node* head) {
        // Base case: If the list is empty or has only one node, it is already sorted
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Find the middle node of the list
        Node* mid = findMiddle(head);
        Node* nextToMid = mid->next;
        
        // Split the list into two halves and recursively sort each half
        mid->next = nullptr; // Break the list at the middle node
        Node* left = mergeSort(head); // Sort the left half
        Node* right = mergeSort(nextToMid); // Sort the right half
        
        // Merge the sorted halves and return the merged list
        return merge(left, right);
    }
    
    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        // Base cases: If either list is empty, return the other list
        if (left == nullptr) {
            return right;
        }
        if (right == nullptr) {
            return left;
        }
        
        // Compare the values of the nodes and merge the lists accordingly
        Node* result = nullptr;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        
        // Return the head of the merged list
        return result;
    }
    
    // Function to find the middle node of a linked list
    Node* findMiddle(Node* head) {
        // Base case: If the list is empty, return nullptr
        if (head == nullptr) {
            return nullptr;
        }
        
        // Use the slow and fast pointer technique to find the middle node
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Return the middle node
        return slow;
    }
    
    // Function to sort a linked list in non-decreasing order
    void sort(Node **head) {
        // Call the mergeSort function and update the head of the list
        *head = mergeSort(*head);
    }
};
```
## Contribution and Support
For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). 
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
