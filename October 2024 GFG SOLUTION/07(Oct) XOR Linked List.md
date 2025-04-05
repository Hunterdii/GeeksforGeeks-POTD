# _7. XOR Linked List_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/xor-linked-list/1)

### Problem Description

An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes. A memory-efficient version of the Doubly Linked List can be created using only one space for the address field with every node. This memory-efficient Doubly Linked List is called XOR Linked List or Memory Efficient as the list uses bitwise XOR operation to save space for one address.

Given a stream of data of size N for the linked list, your task is to complete the function `insert()` and `getList()`. The `insert()` function pushes (or inserts at the beginning) the given data in the linked list, and the `getList()` function returns the linked list as a list.

**Note:**
A utility function `XOR()` takes two Node pointers to get the bitwise XOR of the two Node pointers. Use this function to get the XOR of the two pointers.

**Examples**:

1. **Input:**  
   LinkedList: 9<->5<->4<->7<->3<->10  
   **Output:**  
   10 3 7 4 5 9  
   9 5 4 7 3 10

2. **Input:**  
   LinkedList: 58<->96<->31  
   **Output:**  
   31 96 58  
   58 96 31

---

### My Approach

1. **Node Structure:**  
   Define a `Node` structure that contains:

   - An integer data field.
   - A pointer `npx`, which will store the XOR of the previous and next node addresses.

2. **Insert Function:**

   - Create a new node with the given data.
   - Update the `npx` of the new node to point to the current head.
   - If the list is not empty, update the `npx` of the old head to point to the new node using the XOR operation.

3. **GetList Function:**

   - Traverse the list starting from the head.
   - Use the `XOR` of the previous node and the current node's `npx` to find the next node in the list.
   - Collect data from each node and return it as a list.

4. **Utility Function:**
   - Implement the `XOR` function that takes two Node pointers and returns their XOR.

---

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the linked list to insert nodes and retrieve their values, where n is the number of nodes.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the new node and pointers during traversal.

---

### Code (C++)

```cpp
struct Node* insert(struct Node* head, int data) {
    struct Node* new_node = new Node(data);
    new_node->npx = head;
    if (head != NULL) {
        head->npx = XOR(new_node, head->npx);
    }
    return new_node;
}
vector<int> getList(struct Node* head) {
    vector<int> result;
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next;
    while (curr != NULL) {
        result.push_back(curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    return result;
}
```

### Code (Java)

```java
class Solution {
    static Node insert(Node head, int data) {
        Node temp = new Node(data);
        temp.npx = head;
        head = temp;
        return head;
    }

    static ArrayList<Integer> getList(Node head) {
        ArrayList<Integer> ans = new ArrayList<>();
        Node temp = head;
        while (temp != null) {
            ans.add(temp.data);
            temp = temp.npx;
        }
        return ans;
    }
}
```

### Code (Python)

```python
def insert(head, data):
    new_node = Node(data)
    new_node.npx = head
    return new_node


def getList(head):
    result = []
    current = head
    while current is not None:
        result.append(current.data)
        current = current.npx
    return result

```

---

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
