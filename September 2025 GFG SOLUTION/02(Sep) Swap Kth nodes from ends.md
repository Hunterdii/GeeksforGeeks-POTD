---
title: "🔗 Swap Kth Nodes from Ends | GFG Solution 🔄"
keywords🏷️: ["🔗 linked list", "🔄 node swapping", "📍 two pointers", "🎯 kth element", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to swap kth nodes from beginning and end of a singly linked list: efficient pointer manipulation technique with optimal time complexity. 🚀"
date: 📅 2025-09-02
---

# *02. Swap Kth Nodes from Ends*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/swap-kth-node-from-beginning-and-kth-node-from-end-in-a-singly-linked-list/1)

## **🧩 Problem Description**

Given the head of a singly linked list and an integer `k`, swap the kth node (1-based index) from the beginning and the kth node from the end of the linked list. Return the head of the final formed list and if it's not possible to swap the nodes return the original list.

The task involves identifying two specific nodes based on their positions from opposite ends and performing a complete node swap while maintaining the integrity of the linked list structure.

## **📘 Examples**

### Example 1

```cpp
Input: k = 1, List: 1 -> 2 -> 3 -> 4 -> 5
Output: 5 -> 2 -> 3 -> 4 -> 1
Explanation: Here k = 1, hence after swapping the 1st node from the beginning 
and end the new list will be 5 -> 2 -> 3 -> 4 -> 1.
```

### Example 2

```cpp
Input: k = 2, List: 5 -> 7 -> 8 -> 5 -> 10 -> 3
Output: 5 -> 9 -> 8 -> 5 -> 10 -> 3
Explanation: Here k = 2, hence after swapping the 2nd node from the beginning 
and end the new list will be 5 -> 9 -> 8 -> 5 -> 10 -> 3.
```

### Example 3

```cpp
Input: k = 3, List: 1 -> 2 -> 3 -> 4 -> 5 -> 6
Output: 1 -> 2 -> 4 -> 3 -> 5 -> 6
Explanation: Swapping 3rd node from start (3) with 3rd node from end (4).
```

## **🔒 Constraints**

* $1 \le \text{list size} \le 10^4$
* $1 \le \text{node->data} \le 10^6$
* $1 \le k \le 10^4$

## **✅ My Approach**

The optimal approach uses **Two-Pointer Technique** with careful pointer manipulation to efficiently locate and swap the target nodes:

### **Optimized Single Pass Algorithm**

1. **Length Calculation:**
   * Traverse the entire list once to determine the total number of nodes `n`.
   * Handle edge cases: empty list, k > n, or when kth nodes from both ends are the same.

2. **Node Location:**
   * Find the kth node from the beginning (`x`) along with its previous node (`px`).
   * Find the kth node from the end (`y`) along with its previous node (`py`).
   * The kth node from end is at position `(n - k + 1)` from the beginning.

3. **Pointer Adjustment:**
   * Update previous node pointers to point to the swapped nodes.
   * Handle special cases when either node is the head of the list.

4. **Node Swapping:**
   * Swap the next pointers of both target nodes.
   * Update head pointer if necessary (when k = 1 or k = n).

5. **Edge Case Handling:**
   * Return original list if k > n or if both nodes are the same (middle node in odd-length list).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the linked list. We traverse the list a constant number of times (at most 3 passes) to count nodes, locate target nodes, and perform the swap.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for pointer variables regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;
        int n = 0;
        for (Node* t = head; t; t = t->next) n++;
        if (k > n || 2 * k - 1 == n) return head;
        
        Node *x = head, *y = head, *px = nullptr, *py = nullptr;
        for (int i = 1; i < k; i++) px = x, x = x->next;
        for (int i = 1; i < n - k + 1; i++) py = y, y = y->next;
        
        if (px) px->next = y; else head = y;
        if (py) py->next = x; else head = x;
        
        Node* temp = x->next;
        x->next = y->next;
        y->next = temp;
        
        return head;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pass Traversal Approach**

### 💡 Algorithm Steps:

1. First pass: Calculate the total length of the linked list
2. Second pass: Traverse again to locate both target nodes and their predecessors
3. Perform validation checks for edge cases
4. Execute the swap operation with proper pointer management

```cpp
class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head || k <= 0) return head;
        
        Node* curr = head;
        int len = 0;
        while (curr) len++, curr = curr->next;
        
        if (k > len || 2 * k - 1 == len) return head;
        
        Node* first = head, *second = head;
        Node* prevFirst = nullptr, *prevSecond = nullptr;
        
        for (int i = 1; i < k; i++) prevFirst = first, first = first->next;
        for (int i = 1; i < len - k + 1; i++) prevSecond = second, second = second->next;
        
        if (prevFirst) prevFirst->next = second;
        if (prevSecond) prevSecond->next = first;
        
        Node* temp = first->next;
        first->next = second->next;
        second->next = temp;
        
        return (k == 1) ? second : (k == len) ? first : head;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two linear passes through the list
* **Auxiliary Space:** 💾 O(1) - Only pointer variables used

### ✅ **Why This Approach?**

* Clear separation of length calculation and node finding
* Easier debugging with distinct phases
* More readable for educational purposes

## 📊 **3️⃣ Recursive Position Finding**

### 💡 Algorithm Steps:

1. Use recursion to traverse to the end while counting positions
2. During backtracking, identify nodes at target positions
3. Mark nodes for swapping when positions match k and (n-k+1)
4. Perform swap operation after recursive traversal completes

```cpp
class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;
        int n = getLength(head);
        if (k > n || 2 * k - 1 == n) return head;
        
        Node* first = nullptr, *second = nullptr;
        findNodes(head, k, n - k + 1, 1, first, second);
        
        if (first && second && first != second) {
            swapNodeData(first, second);
        }
        
        return head;
    }
    
private:
    int getLength(Node* head) {
        return head ? 1 + getLength(head->next) : 0;
    }
    
    void findNodes(Node* curr, int pos1, int pos2, int index, Node*& first, Node*& second) {
        if (!curr) return;
        if (index == pos1) first = curr;
        if (index == pos2) second = curr;
        findNodes(curr->next, pos1, pos2, index + 1, first, second);
    }
    
    void swapNodeData(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single recursive traversal
* **Auxiliary Space:** 💾 O(n) - Recursion stack space

### ✅ **Why This Approach?**

* Elegant recursive pattern for position tracking
* Simplifies node identification logic
* Good for understanding recursive list processing

## 📊 **4️⃣ Array-Based Node Storage**

### 💡 Algorithm Steps:

1. Store all node pointers in a vector during single traversal
2. Use direct indexing to access kth nodes from both ends
3. Locate predecessor nodes efficiently using array indices
4. Perform swap with O(1) node access and pointer updates

```cpp
class Solution {
public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;
        
        vector<Node*> nodes;
        for (Node* curr = head; curr; curr = curr->next) 
            nodes.push_back(curr);
        
        int n = nodes.size();
        if (k > n || 2 * k - 1 == n) return head;
        
        int idx1 = k - 1, idx2 = n - k;
        Node* first = nodes[idx1], *second = nodes[idx2];
        
        Node* prevFirst = (idx1 > 0) ? nodes[idx1 - 1] : nullptr;
        Node* prevSecond = (idx2 > 0) ? nodes[idx2 - 1] : nullptr;
        
        if (prevFirst) prevFirst->next = second;
        if (prevSecond) prevSecond->next = first;
        
        Node* temp = first->next;
        first->next = second->next;
        second->next = temp;
        
        return (k == 1) ? second : (k == n) ? first : head;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with additional O(1) operations
* **Auxiliary Space:** 💾 O(n) - Vector storage for all node pointers

### ✅ **Why This Approach?**

* Direct random access to any node position
* Simplified predecessor node identification
* Useful for multiple swap operations on the same list

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Optimized Single Pass**      | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal time & space           | 🔧 Complex pointer logic              |
| 🔍 **Two-Pass Traversal**         | 🟢 O(n)                | 🟢 O(1)                 | 📖 Clear phase separation         | 🐌 Multiple list traversals           |
| 📊 **Recursive Position Finding**  | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Elegant recursive pattern      | 💾 Stack space overhead              |
| 🔄 **Array-Based Storage**        | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Random access capability       | 💾 Extra memory for storage          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Optimized Single Pass**         | ★★★★★                     |
| 📖 **Learning/Educational purposes**                  | 🥈 **Two-Pass Traversal**            | ★★★★☆                     |
| 🔧 **Multiple operations on same list**               | 🥉 **Array-Based Storage**           | ★★★☆☆                     |
| 🎯 **Understanding recursion**                        | 🏅 **Recursive Position Finding**    | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public Node swapKth(Node head, int k) {
        if (head == null) return head;
        int n = 0;
        for (Node t = head; t != null; t = t.next) n++;
        if (k > n || 2 * k - 1 == n) return head;
        
        Node x = head, y = head, px = null, py = null;
        for (int i = 1; i < k; i++) { px = x; x = x.next; }
        for (int i = 1; i < n - k + 1; i++) { py = y; y = y.next; }
        
        if (px != null) px.next = y; else head = y;
        if (py != null) py.next = x; else head = x;
        
        Node temp = x.next;
        x.next = y.next;
        y.next = temp;
        
        return head;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def swapKth(self, head, k):
        if not head: return head
        n, t = 0, head
        while t: n, t = n + 1, t.next
        if k > n or 2 * k - 1 == n: return head
        
        x, y, px, py = head, head, None, None
        for _ in range(k - 1): px, x = x, x.next
        for _ in range(n - k): py, y = y, y.next
        
        if px: px.next = y
        else: head = y
        if py: py.next = x  
        else: head = x
        
        x.next, y.next = y.next, x.next
        return head
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
