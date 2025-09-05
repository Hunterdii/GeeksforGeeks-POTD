---
title: "🔗 Sort a Linked List of 0s, 1s and 2s | GFG Solution 🎯"
keywords🏷️: ["🔗 linked list sorting", "🎯 three-way partitioning", "📍 pointer manipulation", "🚀 node segregation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Sort a Linked List of 0s, 1s and 2s problem: segregate nodes containing 0s, 1s, and 2s using optimal pointer manipulation technique. 🚀"
date: 📅 2025-09-05
---

# *05. Sort a Linked List of 0s, 1s and 2s*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1)

## **🧩 Problem Description**

Given the head of a linked list where nodes can contain values **0s, 1s, and 2s only**. Your task is to rearrange the list so that all **0s appear at the beginning**, followed by all **1s**, and all **2s are placed at the end**.

A linked list is a linear data structure where elements are stored in nodes, and each node contains data and a reference to the next node. The goal is to segregate the nodes based on their data values while maintaining the relative order within each group.

## **📘 Examples**

### Example 1

```cpp
Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
```

### Example 2

```cpp
Input: head = 2 → 2 → 0 → 1
Output: 0 → 1 → 2 → 2
Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be sorted.
```

## **🔒 Constraints**

* $1 \le \text{no. of nodes} \le 10^6$
* $0 \le \text{node->data} \le 2$

## **✅ My Approach**

The optimal approach uses **Three-Way Partitioning** with **Pointer Manipulation** to efficiently segregate nodes without using extra space for new nodes:

### **Node Segregation with Tail Pointers**

1. **Initialize Pointers:**
   * Create separate head and tail pointers for each category: `zero`, `one`, `two` (heads) and `zeroTail`, `oneTail`, `twoTail` (tails).
   * All pointers initially set to `nullptr`.

2. **Traverse and Segregate:**
   * Iterate through the original list, breaking the `next` links to isolate each node.
   * Based on node data (0, 1, or 2), append the node to the respective category list.
   * Update both head and tail pointers for efficient O(1) appending.

3. **Link Categories:**
   * Connect the three segregated lists: `zeros → ones → twos`.
   * Handle edge cases where any category might be empty.
   * Determine the final head based on which categories exist.

4. **Return Result:**
   * Return the head of the newly constructed segregated list.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the linked list. We traverse each node exactly once to segregate them into three categories.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for pointer variables, regardless of the input size. No extra nodes are created.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    Node* segregate(Node* head) {
        if (!head) return head;
        Node* zero = nullptr, *one = nullptr, *two = nullptr;
        Node* zeroTail = nullptr, *oneTail = nullptr, *twoTail = nullptr;
        
        while (head) {
            Node* next = head->next;
            head->next = nullptr;
            
            if (head->data == 0) {
                if (!zero) zero = zeroTail = head;
                else zeroTail = zeroTail->next = head;
            } else if (head->data == 1) {
                if (!one) one = oneTail = head;
                else oneTail = oneTail->next = head;
            } else {
                if (!two) two = twoTail = head;
                else twoTail = twoTail->next = head;
            }
            head = next;
        }
        
        if (zeroTail) {
            head = zero;
            zeroTail->next = one ? one : two;
            if (oneTail) oneTail->next = two;
        } else if (oneTail) {
            head = one;
            oneTail->next = two;
        } else {
            head = two;
        }
        
        return head;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ In-Place Data Modification Approach**

### 💡 Algorithm Steps:

1. First pass: Count occurrences of 0s, 1s, and 2s while traversing the list.
2. Second pass: Overwrite node data values in order - first all 0s, then all 1s, finally all 2s.
3. Preserve the original node structure while only modifying data values.
4. Return the head of the modified list with sorted data.

```cpp
class Solution {
public:
    Node* segregate(Node* head) {
        vector<int> count(3, 0);
        for (Node* temp = head; temp; temp = temp->next)
            count[temp->data]++;
        
        Node* curr = head;
        for (int i = 0; i < 3; i++) {
            while (count[i]-- && curr) {
                curr->data = i;
                curr = curr->next;
            }
        }
        return head;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two passes through the list
* **Auxiliary Space:** 💾 O(1) - Only counter array of size 3

### ✅ **Why This Approach?**

* Simplest logic with counting approach
* Preserves original node addresses and structure
* Minimal memory overhead with fixed-size array

## 📊 **3️⃣ Single Pass with Tail Pointers**

### 💡 Algorithm Steps:

1. Use single pass with immediate node segregation and linking.
2. Maintain separate head and tail pointers for each of the three categories.
3. Break original connections and establish new ones during traversal.
4. Handle all edge cases with conditional linking at the end.

```cpp
class Solution {
public:
    Node* segregate(Node* head) {
        Node *zHead = nullptr, *zTail = nullptr;
        Node *oHead = nullptr, *oTail = nullptr;
        Node *tHead = nullptr, *tTail = nullptr;
        
        while (head) {
            if (head->data == 0) {
                if (!zHead) zHead = zTail = head;
                else zTail->next = head, zTail = head;
            } else if (head->data == 1) {
                if (!oHead) oHead = oTail = head;
                else oTail->next = head, oTail = head;
            } else {
                if (!tHead) tHead = tTail = head;
                else tTail->next = head, tTail = head;
            }
            Node* temp = head->next;
            head->next = nullptr;
            head = temp;
        }
        
        if (zTail) zTail->next = oHead ? oHead : tHead;
        if (oTail) oTail->next = tHead;
        
        return zHead ? zHead : (oHead ? oHead : tHead);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through list
* **Auxiliary Space:** 💾 O(1) - Only pointer variables

### ✅ **Why This Approach?**

* Optimal single-pass solution without extra traversals
* No dummy nodes required, direct manipulation
* Efficient node relinking with O(1) operations per node

## 📊 **4️⃣ Recursive Segregation**

### 💡 Algorithm Steps:

1. Use recursion to process nodes from head to tail systematically.
2. Maintain global pointers for each category to build segregated lists.
3. Process current node and recursively handle the rest of the list.
4. Link the three categories together during the base case return.

```cpp
class Solution {
    Node *zHead = nullptr, *oHead = nullptr, *tHead = nullptr;
    Node *zTail = nullptr, *oTail = nullptr, *tTail = nullptr;
    
    void processNode(Node* node) {
        if (!node) return;
        
        Node* next = node->next;
        node->next = nullptr;
        
        if (node->data == 0) {
            if (!zHead) zHead = zTail = node;
            else zTail->next = node, zTail = node;
        } else if (node->data == 1) {
            if (!oHead) oHead = oTail = node;
            else oTail->next = node, oTail = node;
        } else {
            if (!tHead) tHead = tTail = node;
            else tTail->next = node, tTail = node;
        }
        
        processNode(next);
    }
    
public:
    Node* segregate(Node* head) {
        zHead = oHead = tHead = zTail = oTail = tTail = nullptr;
        processNode(head);
        
        if (zTail) zTail->next = oHead ? oHead : tHead;
        if (oTail) oTail->next = tHead;
        
        return zHead ? zHead : (oHead ? oHead : tHead);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single recursive traversal
* **Auxiliary Space:** 💾 O(n) - Recursive call stack space

### ✅ **Why This Approach?**

* Elegant recursive solution with clear logic flow
* Good for educational purposes and functional programming
* Clear separation of processing and linking phases

## 📊 **5️⃣ Dutch National Flag Algorithm Adaptation**

### 💡 Algorithm Steps:

1. Adapt the classic Dutch National Flag algorithm for linked lists.
2. Use three pointers to mark boundaries of 0s, 1s, and 2s regions.
3. Swap node data values instead of array elements to maintain list structure.
4. Continue until all nodes are properly segregated into three regions.

```cpp
class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;
        
        Node* curr = head;
        int count0 = 0, count1 = 0, count2 = 0;
        
        while (curr) {
            if (curr->data == 0) count0++;
            else if (curr->data == 1) count1++;
            else count2++;
            curr = curr->next;
        }
        
        curr = head;
        while (count0 > 0) {
            curr->data = 0;
            curr = curr->next;
            count0--;
        }
        while (count1 > 0) {
            curr->data = 1;
            curr = curr->next;
            count1--;
        }
        while (count2 > 0) {
            curr->data = 2;
            curr = curr->next;
            count2--;
        }
        
        return head;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two passes through the list
* **Auxiliary Space:** 💾 O(1) - Only counting variables

### ✅ **Why This Approach?**

* Classic algorithm adaptation for linked list context
* Simple counting and reconstruction approach
* Maintains original node structure with data modification

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔗 **Node Relinking**              | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Preserves nodes, optimal space | 🔧 Complex pointer management        |
| 📊 **Data Modification**           | 🟢 O(n)                | 🟢 O(1)                 | 📖 Simplest logic                | 🔄 Modifies original data values      |
| 🎯 **Single Pass Linking**         | 🟢 O(n)                | 🟢 O(1)                 | ⭐ No dummy nodes, efficient      | 🔧 Multiple edge case handling        |
| 🔄 **Recursive**                   | 🟢 O(n)                | 🟡 O(n)                 | 🎨 Elegant and educational       | 📚 Extra stack space overhead        |
| 🏴 **Dutch Flag Adaptation**       | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Classic algorithm pattern     | 🔄 Two-pass approach                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Memory constrained environments**            | 🥇 **Data Modification**             | ★★★★★                     |
| 📖 **Production code, maintainability**           | 🥈 **Single Pass Linking**           | ★★★★☆                     |
| 🔧 **Node identity preservation required**        | 🥉 **Node Relinking**                | ★★★★★                     |
| 🎯 **Educational/Interview contexts**             | 🏅 **Recursive**                     | ★★★☆☆                     |
| 📚 **Algorithm pattern demonstration**            | 🎖️ **Dutch Flag Adaptation**         | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public Node segregate(Node head) {
        if (head == null) return head;
        
        Node zero = null, one = null, two = null;
        Node zTail = null, oTail = null, tTail = null;
        
        while (head != null) {
            Node next = head.next;
            head.next = null;
            
            if (head.data == 0) {
                if (zero == null) zero = zTail = head;
                else zTail = zTail.next = head;
            } else if (head.data == 1) {
                if (one == null) one = oTail = head;
                else oTail = oTail.next = head;
            } else {
                if (two == null) two = tTail = head;
                else tTail = tTail.next = head;
            }
            head = next;
        }
        
        if (zTail != null) {
            head = zero;
            zTail.next = (one != null) ? one : two;
            if (oTail != null) oTail.next = two;
        } else if (oTail != null) {
            head = one;
            oTail.next = two;
        } else {
            head = two;
        }
        
        return head;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def segregate(self, head):
        if not head:
            return head
            
        zero = one = two = None
        z_tail = o_tail = t_tail = None
        
        while head:
            next_node = head.next
            head.next = None
            
            if head.data == 0:
                if not zero:
                    zero = z_tail = head
                else:
                    z_tail.next = head
                    z_tail = head
            elif head.data == 1:
                if not one:
                    one = o_tail = head
                else:
                    o_tail.next = head
                    o_tail = head
            else:
                if not two:
                    two = t_tail = head
                else:
                    t_tail.next = head
                    t_tail = head
            head = next_node
        
        if z_tail:
            head = zero
            z_tail.next = one if one else two
            if o_tail:
                o_tail.next = two
        elif o_tail:
            head = one
            o_tail.next = two
        else:
            head = two
            
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
