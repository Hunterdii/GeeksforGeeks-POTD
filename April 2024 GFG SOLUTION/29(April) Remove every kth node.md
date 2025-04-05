## 28. Remove every kth node

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-every-kth-node/1)

### Problem Description

Given a singly linked list having \(n\) nodes, your task is to remove every \(k\)th node from the linked list.

**Example:**

Input:

```
n = 8
Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
k = 2
```

Output:

```
1 -> 3 -> 5 -> 7
```

Explanation:
After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 -> 7.

**Your Task:**

The task is to complete the function `deleteK()` which takes the head of the linked list and an integer \(k\) as input parameters and deletes every \(k\)th node from the linked list, returning its head.

**Expected Time Complexity:** O(n)
**Expected Auxiliary Space:** O(1)

### My Approach

1. **Initialization:**

- Traverse the linked list while keeping track of the current node and its previous node.
- Initialize an index variable to keep track of the position of the current node.

2. **Deletion Process:**

- Whenever the index becomes equal to \(k\), delete the current node by updating the next pointer of the previous node to skip the current node.
- Reset the index to 1 and continue traversing the linked list.

3. **Return:**

- Return the head of the modified linked list.

### Code (C++)

```cpp
class Solution {
public:
    Node* deleteK(Node* head, int K) {
        if (head == nullptr || K <= 0)
            return head;

        if (K == 1) {
            // Deleting entire list
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            return nullptr;
        }

        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;
        Node* curr = head;
        int index = 1;

        while (curr) {
            if (index == K) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                index = 1;
            } else {
                index++;
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
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
