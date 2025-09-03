---
title: "🔗 Reverse a Doubly Linked List | GFG Solution 🔄"
keywords🏷️: ["🔗 doubly linked list", "🔄 reverse", "📍 two pointers", "📚 linked list", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Reverse a Doubly Linked List problem: efficiently reverse a doubly linked list by swapping next and prev pointers. 🚀"
date: 📅 2025-09-03
---

# *03. Reverse a Doubly Linked List*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1)

## **🧩 Problem Description**

You are given the head of a doubly linked list. Your task is to **reverse** the doubly linked list and return its head.

A doubly linked list is a data structure where each node contains data and two pointers: one pointing to the next node and another pointing to the previous node. To reverse it, we need to swap these pointer directions for every node.

## **📘 Examples**

### Example 1

```cpp
Input: 3 <-> 4 <-> 5
Output: 5 <-> 4 <-> 3
Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.
```

### Example 2

```cpp
Input: 75 <-> 122 <-> 59 <-> 196
Output: 196 <-> 59 <-> 122 <-> 75
Explanation: After reversing the given doubly linked list the new list will be 196 <-> 59 <-> 122 <-> 75.
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 10^6$
* $0 \le \text{node->data} \le 10^4$

## **✅ My Approach**

The optimal approach involves **iterating through the doubly linked list** and **swapping the next and prev pointers** for each node:

### **Iterative Pointer Swapping**

1. **Handle Edge Cases:**
   * If the list is empty or has only one node, return the head as is.

2. **Traverse and Swap:**
   * Start from the head node.
   * For each node, swap its `next` and `prev` pointers.
   * Store the original `next` pointer in a temporary variable before swapping.
   * Move to the next node using the stored reference.

3. **Find New Head:**
   * Continue until we reach the end of the original list.
   * The last node we process becomes the new head of the reversed list.

4. **Return Result:**
   * Return the new head of the reversed doubly linked list.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the doubly linked list. We need to visit each node exactly once to swap its pointers.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for temporary variables regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    Node *reverse(Node *head) {
        if (!head || !head->next) return head;
        Node *curr = head, *temp;
        while (curr) {
            temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            if (!temp) return curr;
            curr = temp;
        }
        return head;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pointer Approach**

### 💡 Algorithm Steps:

1. Use two pointers - one for current node and one for tracking previous
2. Keep the original next pointer in a temporary variable
3. Swap pointers and move to next node using stored reference
4. Continue until entire list is processed

```cpp
class Solution {
public:
    Node *reverse(Node *head) {
        Node *current = head, *prev = nullptr;
        while (current) {
            Node *nextNode = current->next;
            current->next = current->prev;
            current->prev = nextNode;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through the list
* **Auxiliary Space:** 💾 O(1) - Only constant extra space

### ✅ **Why This Approach?**

* Clear pointer manipulation logic
* Easy to debug and trace execution
* Standard iterative pattern for linked lists

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Iterative Standard**          | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Fast and space efficient      | 🔧 Multiple variables needed         |
| 👥 **Two-Pointer**                 | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Clear logic flow               | 🐌 Slightly more operations          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🎯 **General purpose, production code**           | 🥇 **Iterative Standard**            | ★★★★★                     |
| 📖 **Learning/Teaching**                          | 🥈 **Two-Pointer**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public Node reverse(Node head) {
        if (head == null || head.next == null) return head;
        Node curr = head, temp;
        while (curr != null) {
            temp = curr.next;
            curr.next = curr.prev;
            curr.prev = temp;
            if (temp == null) return curr;
            curr = temp;
        }
        return head;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def reverse(self, head):
        if not head or not head.next: 
            return head
        curr = head
        while curr:
            curr.next, curr.prev = curr.prev, curr.next
            if not curr.prev: 
                return curr
            curr = curr.prev
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
