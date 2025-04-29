# *29. Sort a Linked List of 0s, 1s, and 2s*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1)

## **🧩 Problem Description**

Given the head of a linked list where each node contains a value of either `0`, `1`, or `2`, your task is to rearrange the list such that all `0`s appear first, followed by all `1`s, and all `2`s appear at the end.

## **📘 Examples**

### **Example 1:**

#### **Input:**
`head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2`

<img src="https://github.com/user-attachments/assets/9d9f6ffc-7813-481c-b48f-68d155b4868b" width="60%">

#### **Output:**
`0 → 1 → 1 → 2 → 2 → 2 → 2 → 2`

<img src="https://github.com/user-attachments/assets/96d7ff8a-4101-4441-99eb-c5bc52e0ef52" width="60%">

#### **Explanation:**
After sorting, all the `0`s are at the beginning, followed by the `1`s, and all the `2`s appear at the end of the list.

### **Example 2:**

#### **Input:**
`head = 2 → 2 → 0 → 1`

<img src="https://github.com/user-attachments/assets/e54f02f9-c689-4679-912f-b831ad6d144d" width="40%">

#### **Output:**
`0 → 1 → 2 → 2`

<img src="https://github.com/user-attachments/assets/57c4683b-853d-482e-acf3-8069d06163fe" width="40%">

#### **Explanation:**
After sorting, the list is rearranged to have `0` at the beginning, followed by `1`, and all `2`s at the end.

### **🔒 Constraints**

- $\( 1 \leq \text{no. of nodes} \leq 10^6 \)$  
- $\( 0 \leq node->data \leq 2 \)$

## **✅ My Approach**

### **Optimized Approach (Dutch National Flag Problem)**

The problem can be solved using a modified version of the Dutch National Flag problem, which is known for sorting three distinct elements efficiently.

### **Algorithm Steps:**

1. **Three Pointers Approach:**
   - Initialize three pointers: `low`, `mid`, and `high`.
   - Traverse the list and:
     - If the current node’s value is `0`, move it to the beginning (increment `low`).
     - If the current node’s value is `1`, keep it in the middle (increment `mid`).
     - If the current node’s value is `2`, move it to the end (decrement `high`).

2. **Pointer Movement:**
   - The `low` pointer tracks the end of the 0s section.
   - The `mid` pointer tracks the current node.
   - The `high` pointer tracks the start of the 2s section.

3. **End Condition:**
   - The loop ends when `mid` crosses `high`.

## **🧮 Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the list. We only traverse the list once.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of extra space for the pointers.

## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    Node* segregate(Node* head) {
        int count[3] = {0};
        for (Node* curr = head; curr; curr = curr->next) count[curr->data]++;
        Node* curr = head;
        for (int i = 0; i < 3; i++)
            while (count[i]--) curr->data = i, curr = curr->next;
        return head;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Node Rearrangement with Dummy Nodes**

### **Algorithm Steps:**
1. Create three dummy nodes for sublists of 0s, 1s, and 2s.
2. Traverse the original list and attach nodes to respective lists.
3. Connect the three sublists in order and return the new head.

```cpp
class Solution {
  public:
    Node* segregate(Node* head) {
        Node *z = new Node(0), *o = new Node(0), *t = new Node(0);
        Node *zero = z, *one = o, *two = t, *curr = head;
        while (curr) {
            if (curr->data == 0) zero->next = curr, zero = curr;
            else if (curr->data == 1) one->next = curr, one = curr;
            else two->next = curr, two = curr;
            curr = curr->next;
        }
        zero->next = o->next ? o->next : t->next;
        one->next = t->next;
        two->next = nullptr;
        head = z->next;
        delete z, delete o, delete t;
        return head;
    }
};
```

### ✅ **Why This Approach?**
- Maintains original nodes — no value rewriting.
- Good for cases where mutating node values is not allowed.

#### 📝 **Complexity Analysis:**
- **Time Complexity:** O(n), where `n` is the number of nodes in the linked list. We traverse the list once.
- **Auxiliary Space Complexity:** O(1) as no extra data structures other than dummy nodes are used.


## 📊 **3️⃣ Extract, Sort & Reassign**

### **Algorithm Steps:**
1. Traverse the list and collect all node values into a `std::vector<int>`.
2. Sort the vector.
3. Traverse the list again, overwriting each node’s `data` with the corresponding sorted value.

```cpp
class Solution {
  public:
    Node* segregate(Node* head) {
        vector<int> A;
        for (Node* p = head; p; p = p->next) A.push_back(p->data);
        sort(A.begin(), A.end());
        Node* p = head; int i = 0;
        while (p) p->data = A[i++], p = p->next;
        return head;
    }
};
```

### ✅ **Why This Approach?**
- Simple to implement, leverages built-in sorting.
- Suitable for environments where the list can be temporarily transformed into an array for sorting.

#### 📝 **Complexity Analysis:**
- **Time Complexity:** O(n log n) due to the sorting step.
- **Auxiliary Space Complexity:** O(n) for the vector to store node values.


## 📊 **4️⃣ In‐Place Node Insertion**

### **Algorithm Steps:**
1. Maintain two pointers: `tail0` (end of 0s sublist) and `prev`/`curr`.
2. First pass: whenever `curr->data == 0`, detach `curr` and insert it **after** `tail0` (or at head if `tail0` is null), advance `tail0`.
3. Second pass (starting from `tail0->next`): similarly extract `1`s and insert after the end of the 1s sublist.
4. Remaining nodes are all 2s by default.

```cpp
class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head) return head;
        Node* zeroD = new Node(0);
        Node* oneD = new Node(0);
        Node* twoD = new Node(0);
        Node *zero = zeroD, *one = oneD, *two = twoD;
        Node* curr = head;
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }
        zero->next = (oneD->next) ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;
        Node* newHead = zeroD->next;
        delete zeroD;
        delete oneD;
        delete twoD;

        return newHead;
    }
};
```

### ✅ **Why This Approach?**
- No extra memory for node values (only pointer manipulation).
- Efficient for cases where you need to segregate nodes without rewriting data.

#### 📝 **Complexity Analysis:**
- **Time Complexity:** O(n), where `n` is the number of nodes in the list. We perform two passes over the list.
- **Auxiliary Space Complexity:** O(1), as the algorithm only uses a few pointer variables for manipulation.


### 🆚 **Comparison of Approaches**

| **Approach**                  | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                       | ⚠️ **Cons**                            |
|------------------------------|-------------|--------------|----------------------------------|----------------------------------------|
| Value Overwrite              | 🟢 O(n)      | 🟢 O(1)       | Short, fastest, easy to code     | Mutates values directly                |
| Node Rearrangement           | 🟢 O(n)      | 🟢 O(1)       | Does not change node data        | Slightly longer, uses extra dummy nodes|
| Extract & Sort               | 🔸 O(n log n) | 🔴 O(n)       | Very simple to implement         | Extra memory, slower due to sort      |
| In‐Place Node Insertion      | 🟢 O(n)      | 🟢 O(1)       | No extra allocations, preserves original nodes | Code is more intricate, careful pointer handling |

### ✅ **Best Choice?**

| **Scenario**                                | **Recommended Approach**     |
|---------------------------------------------|------------------------------|
| Minimal code and max speed                 | 🥇 Value Overwrite           |
| Cannot mutate node values                  | 🥈 Node Rearrangement        |
| Memory is abundant, simplicity preferred    | 🥉 Extract & Sort            |
| Strict no-allocation and O(1) overhead      | 🎖️ In‐Place Node Insertion   |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    static Node segregate(Node head) {
        int[] count = new int[3];
        for (Node curr = head; curr != null; curr = curr.next) count[curr.data]++;
        Node curr = head;
        for (int i = 0; i < 3; i++)
            while (count[i]-- > 0) { curr.data = i; curr = curr.next; }
        return head;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def segregate(self, head):
        count = [0, 0, 0]
        curr = head
        while curr:
            count[curr.data] += 1
            curr = curr.next
        curr = head
        for i in range(3):
            while count[i]:
                curr.data = i
                curr = curr.next
                count[i] -= 1
        return head
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>

