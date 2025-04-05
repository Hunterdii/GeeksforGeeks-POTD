## 16. Delete Node without Head Pointer

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1)

### My Approach

The given function takes in a reference to the node to be deleted. Since we do not have access to the head of the linked list, we cannot directly traverse the list to find the node before the given node. However, we can perform the following steps:

1. Copy the data and the next pointer of the node next to the `del_node` into the `del_node`.
2. Delete the next node of `del_node`.

This approach effectively removes the `del_node` from the linked list without actually having access to the head pointer.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1), as we perform a constant number of operations regardless of the size of the linked list.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

You are given a node `del_node` of a Singly Linked List where you have to delete a value of the given node from the linked list but you are not given the head of the list.
By deleting the node value, we do not mean removing it from memory. We mean:

- The value of the given node should not exist in the linked list.
- The number of nodes in the linked list should decrease by one.
- All the values before & after the `del_node` node should be in the same order.

**Example 1:**

Input:

```
Linked List = 10 -> 20 -> 4 -> 30
del_node = 20
```

Output:

```
10 4 30
```

Explanation:
After deleting 20 from the linked list,
we have remaining nodes as 10, 4, 30.

### Code (C++)

```cpp
class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
       Node* temp = del_node->next;
       del_node->data = temp->data;
       del_node->next = temp->next;
       delete(temp);
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
