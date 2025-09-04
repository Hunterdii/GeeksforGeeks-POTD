---
title: "🔗 Linked List Group Reverse | GFG Solution 🔄"
keywords🏷️: ["🔗 linked list", "🔄 group reversal", "📍 two pointers", "🔁 recursion", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Linked List Group Reverse problem: reverse every k nodes in a linked list including remaining nodes using recursive and iterative approaches. 🚀"
date: 📅 2025-09-04
---

# *04. Linked List Group Reverse*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1)

## **🧩 Problem Description**

You are given the head of a **Singly linked list**. Your task is to **reverse every k nodes** in the linked list and return the head of the modified list.

**Note:** If the number of nodes is not a multiple of k, then the left-out nodes at the end should be considered as a group and **must be reversed**.

A group reversal means that within each group of k consecutive nodes, the order should be completely reversed while maintaining the overall structure of the linked list.

## **📘 Examples**

### Example 1

```cpp
Input: k = 2,
Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 6
Output: 2 -> 1 -> 4 -> 3 -> 6 -> 5
Explanation: Linked List is reversed in groups of size k = 2.
Groups: [1,2] -> [2,1], [3,4] -> [4,3], [5,6] -> [6,5]
```

### Example 2

```cpp
Input: k = 4,
Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 6
Output: 4 -> 3 -> 2 -> 1 -> 6 -> 5
Explanation: Linked List is reversed in groups of size k = 4.
Groups: [1,2,3,4] -> [4,3,2,1], [5,6] -> [6,5] (remaining nodes also reversed)
```

### Example 3

```cpp
Input: k = 3,
Linked List: 1 -> 2 -> 3 -> 4 -> 5
Output: 3 -> 2 -> 1 -> 5 -> 4
Explanation: Groups: [1,2,3] -> [3,2,1], [4,5] -> [5,4]
```

## **🔒 Constraints**

* $1 \le \text{size of linked list} \le 10^5$
* $0 \le \text{node->data} \le 10^6$
* $1 \le k \le \text{size of linked list}$

## **✅ My Approach**

The optimal approach uses **Recursive Group Processing** with **Fast-Pointer Technique** to efficiently handle both complete and partial groups:

### **Recursive Group Processing + Fast-Pointer**

1. **Count Nodes in Current Group:**
   * Use a fast pointer to count exactly k nodes from current position.
   * If less than k nodes remain, treat remaining nodes as the final group.

2. **Handle Partial Groups:**
   * If current group has fewer than k nodes, reverse all remaining nodes.
   * This ensures the constraint that remaining nodes are also reversed.

3. **Recursive Processing:**
   * Recursively process the next group starting from the (k+1)th node.
   * This gives us the new head for the remaining processed list.

4. **Reverse Current Group:**
   * Reverse exactly k nodes (or remaining nodes if partial group).
   * Connect the reversed group to the already processed remaining list.

5. **Return New Head:**
   * Return the last node of the original group (which becomes the first after reversal).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the total number of nodes in the linked list. Each node is visited exactly once during the traversal and reversal process.
* **Expected Auxiliary Space Complexity:** O(n/k), where n is the total number of nodes and k is the group size. This space is used by the recursion stack, with maximum depth of n/k recursive calls.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        Node* cur = head; int cnt = 0;
        while (cur && cnt < k) { cur = cur->next; cnt++; }
        if (cnt < k) {
            Node* prev = nullptr;
            while (head) {
                Node* nxt = head->next; head->next = prev; prev = head; head = nxt;
            }
            return prev;
        }
        cur = reverseKGroup(cur, k);
        while (cnt--) {
            Node* nxt = head->next; head->next = cur; cur = head; head = nxt;
        }
        return cur;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Length-Based Iterative Approach**

### 💡 Algorithm Steps:

1. Calculate total length to determine complete and partial groups.
2. Use dummy node technique for simplified pointer management.
3. Process complete k-groups with standard three-pointer reversal.
4. Reverse remaining partial group as final step.

```cpp
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        int len = 0;
        for (Node* p = head; p; p = p->next) len++;
        
        Node dummy(0);
        dummy.next = head;
        Node* prev = &dummy;
        
        for (int i = 0; i <= len / k; i++) {
            int size = (i < len / k) ? k : len % k;
            if (size == 0) break;
            
            Node* start = prev->next;
            Node* end = start;
            for (int j = 1; j < size; j++) end = end->next;
            
            Node* next = end->next;
            end->next = nullptr;
            prev->next = reverse(start);
            start->next = next;
            prev = start;
        }
        
        return dummy.next;
    }
    
private:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        while (head) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass for length + reversal
* **Auxiliary Space:** 💾 O(1) - Only pointer variables

### ✅ **Why This Approach?**

* Explicit handling of partial groups
* No recursion stack overhead
* Clear separation of concerns

## 📊 **3️⃣ Vector Collection Approach**

### 💡 Algorithm Steps:

1. Collect all nodes into vector for easy access and manipulation.
2. Process nodes in groups of k using reverse iteration.
3. Handle partial groups naturally with vector indexing.
4. Rebuild linked list connections after processing.

```cpp
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        vector<Node*> nodes;
        for (Node* curr = head; curr; curr = curr->next) 
            nodes.push_back(curr);
        
        Node dummy(0);
        Node* tail = &dummy;
        
        for (int i = 0; i < nodes.size(); i += k) {
            int end = min(i + k, (int)nodes.size());
            for (int j = end - 1; j >= i; j--) {
                tail->next = nodes[j];
                tail = tail->next;
            }
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear collection and processing
* **Auxiliary Space:** 💾 O(n) - Vector storage for all nodes

### ✅ **Why This Approach?**

* Simplest logic implementation
* Natural handling of edge cases
* Easy to verify correctness

## 📊 **4️⃣ In-Place Group Detection**

### 💡 Algorithm Steps:

1. Use two-pointer technique to detect group boundaries.
2. Reverse nodes within detected groups using iterative approach.
3. Handle partial groups with same reversal logic.
4. Maintain connection between groups during processing.

```cpp
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        Node* node = head;
        for (int i = 0; i < k; i++) {
            if (!node) return reverseAll(head);
            node = node->next;
        }
        
        Node* prev = reverseKGroup(node, k);
        while (k--) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
private:
    Node* reverseAll(Node* head) {
        Node* prev = nullptr;
        while (head) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each node processed exactly once
* **Auxiliary Space:** 💾 O(n/k) - Recursion depth

### ✅ **Why This Approach?**

* Elegant recursive structure
* Early detection of partial groups
* Minimal code complexity

## 📊 **5️⃣ Stack-Based Group Reversal**

### 💡 Algorithm Steps:

1. Use a stack to collect nodes in groups of k.
2. Pop from stack to achieve reversal effect naturally.
3. Handle partial groups by processing remaining stack contents.
4. Maintain proper linking between reversed groups.

```cpp
class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        stack<Node*> st;
        Node dummy(0);
        Node* tail = &dummy;
        Node* cur = head;
        
        while (cur) {
            int count = 0;
            Node* temp = cur;
                while (temp && count < k) {
                st.push(temp);
                temp = temp->next;
                count++;
            }
                while (!st.empty()) {
                tail->next = st.top();
                tail = tail->next;
                st.pop();
            }
            tail->next = nullptr;
            cur = temp;
        }
        
        return dummy.next;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each node pushed and popped once
* **Auxiliary Space:** 💾 O(k) - Stack space for k elements

### ✅ **Why This Approach?**

* Intuitive reversal using stack properties
* Natural handling of partial groups
* Clear visualization of the reversal process

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Fast-Pointer Recursive**     | 🟢 O(n)                | 🟡 O(n/k)               | 🎯 Optimal runtime performance    | 📚 Recursion overhead                |
| 📊 **Length-Based Iterative**     | 🟢 O(n)                | 🟢 O(1)                 | 🏷️ No recursion needed           | 🔄 Two-pass processing               |
| 📦 **Vector Collection**          | 🟢 O(n)                | 🟡 O(n)                 | 📖 Simplest implementation       | 💾 Highest memory usage              |
| 🔍 **In-Place Detection**         | 🟢 O(n)                | 🟡 O(n/k)               | ⚡ Early partial group detection  | 🔧 Complex edge case handling        |
| 📚 **Stack-Based Reversal**       | 🟢 O(n)                | 🟡 O(k)                 | 🎯 Intuitive reversal logic      | 💾 Additional stack overhead         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Runtime optimization**                       | 🥇 **Fast-Pointer Recursive**        | ★★★★★                     |
| 📖 **Memory constrained**                         | 🥈 **Length-Based Iterative**        | ★★★★☆                     |
| 🔧 **Simplicity priority**                        | 🥉 **Vector Collection**             | ★★★★☆                     |
| 🎯 **Interview/Competitive**                       | 🏅 **Fast-Pointer Recursive**        | ★★★★★                     |
| 📚 **Learning/Educational**                        | 🎖️ **Stack-Based Reversal**          | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public Node reverseKGroup(Node head, int k) {
        Node cur = head; int cnt = 0;
        while (cur != null && cnt < k) { cur = cur.next; cnt++; }
        if (cnt < k) {
            Node prev = null;
            while (head != null) {
                Node nxt = head.next; head.next = prev; prev = head; head = nxt;
            }
            return prev;
        }
        cur = reverseKGroup(cur, k);
        while (cnt-- > 0) {
            Node nxt = head.next; head.next = cur; cur = head; head = nxt;
        }
        return cur;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def reverseKGroup(self, head, k):
        cur, cnt = head, 0
        while cur and cnt < k:
            cur = cur.next; cnt += 1
        if cnt < k:
            prev = None
            while head:
                nxt = head.next; head.next = prev; prev = head; head = nxt
            return prev
        cur = self.reverseKGroup(cur, k)
        while cnt:
            nxt = head.next; head.next = cur; cur = head; head = nxt; cnt -= 1
        return cur
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
