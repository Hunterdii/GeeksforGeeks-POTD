---
title: "🔗 Merge Sort for Linked List | GFG Solution 🔀"
keywords🏷️: ["🔗 linked list sorting", "🔀 merge sort", "📍 divide and conquer", "📈 recursion", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Merge Sort for Linked List problem: efficiently sort a linked list using divide and conquer approach with merge sort algorithm. 🚀"
date: 📅 2025-09-08
---

# *08. Merge Sort for Linked List*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sort-a-linked-list/1)

## **🧩 Problem Description**

You are given the head of a linked list. Your task is to sort the given linked list using **Merge Sort** algorithm.

Merge Sort is a divide-and-conquer algorithm that works by recursively dividing the list into smaller sublists, sorting them, and then merging them back together in sorted order.

## **📘 Examples**

### Example 1

```cpp
Input: 
Linked List: 40 -> 20 -> 60 -> 10 -> 50 -> 30
Output: 10 -> 20 -> 30 -> 40 -> 50 -> 60
Explanation: After sorting the given linked list, the resultant list will be in ascending order.
```

### Example 2

```cpp
Input: 
Linked List: 9 -> 5 -> 2 -> 8
Output: 2 -> 5 -> 8 -> 9
Explanation: After sorting the given linked list, the resultant list will be in ascending order.
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 10^5$
* $0 \le \text{node->data} \le 10^6$

## **✅ My Approach**

The optimal approach uses the **Divide and Conquer** strategy with **Merge Sort** algorithm specifically adapted for linked lists:

### **Recursive Divide and Conquer**

1. **Base Case:**
   * If the list is empty or has only one node, it's already sorted - return it.

2. **Divide Phase:**
   * Find the middle of the linked list using the **slow-fast pointer technique**.
   * Split the list into two halves at the middle point.
   * Break the connection between the two halves.

3. **Conquer Phase:**
   * Recursively sort the left half.
   * Recursively sort the right half.

4. **Merge Phase:**
   * Merge the two sorted halves into a single sorted list.
   * Compare elements from both lists and link them in ascending order.

5. **Return Result:**
   * Return the head of the merged sorted list.

### **Key Implementation Details:**

* **Finding Middle:** Use two pointers - slow moves one step, fast moves two steps. When fast reaches end, slow is at middle.
* **Merging:** Compare data of nodes from both lists and link smaller ones first, ensuring sorted order.
* **Memory Efficient:** No extra space needed for arrays - works directly with list nodes.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the number of nodes in the linked list. We divide the list into halves (log n levels) and at each level we traverse all n nodes for merging.
* **Expected Auxiliary Space Complexity:** O(log n), due to the recursion stack depth. In the worst case, we have log n recursive calls on the call stack simultaneously.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    Node *mergeSort(Node *h) {
        if (!h || !h->next) return h;
        Node *s = h, *f = h->next;
        while (f && f->next) s = s->next, f = f->next->next;
        Node *r = s->next;
        s->next = nullptr;
        return merge(mergeSort(h), mergeSort(r));
    }
    
    Node *merge(Node *a, Node *b) {
        if (!a) return b;
        if (!b) return a;
        if (a->data <= b->data) {
            a->next = merge(a->next, b);
            return a;
        }
        b->next = merge(a, b->next);
        return b;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative Bottom-Up Approach**

### 💡 Algorithm Steps:

1. Start with sublist size 1, then 2, 4, 8, etc.
2. Merge adjacent sublists of current size iteratively.
3. Double the sublist size in each iteration until it exceeds list length.
4. No recursion overhead, purely iterative solution.

```cpp
class Solution {
public:
    Node *mergeSort(Node *head) {
        if (!head || !head->next) return head;
        int len = getLength(head);
        Node dummy(0);
        dummy.next = head;
        
        for (int sz = 1; sz < len; sz *= 2) {
            Node *prev = &dummy;
            Node *curr = dummy.next;
            while (curr) {
                Node *left = curr;
                Node *right = split(left, sz);
                curr = split(right, sz);
                prev->next = merge(left, right);
                while (prev->next) prev = prev->next;
            }
        }
        return dummy.next;
    }

private:
    int getLength(Node *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    Node *split(Node *head, int n) {
        while (--n && head) head = head->next;
        Node *rest = head ? head->next : nullptr;
        if (head) head->next = nullptr;
        return rest;
    }
    
    Node *merge(Node *a, Node *b) {
        Node dummy(0);
        Node *tail = &dummy;
        while (a && b) {
            if (a->data <= b->data) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Same as recursive but no stack overhead
* **Auxiliary Space:** 💾 O(1) - Constant space, no recursion stack

### ✅ **Why This Approach?**

* No recursion stack overflow risk for large lists
* Constant space complexity
* Better for memory-constrained environments

## 📊 **3️⃣ Array Conversion Approach**

### 💡 Algorithm Steps:

1. Convert linked list to array for random access.
2. Apply standard merge sort on array with O(log n) space.
3. Reconstruct linked list from sorted array.
4. Leverage array's cache locality for better performance.

```cpp
class Solution {
public:
    Node *mergeSort(Node *head) {
        if (!head || !head->next) return head;
        vector<int> vals;
        Node *curr = head;
        while (curr) {
            vals.push_back(curr->data);
            curr = curr->next;
        }
        sort(vals.begin(), vals.end());
        curr = head;
        for (int val : vals) {
            curr->data = val;
            curr = curr->next;
        }
        return head;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Standard sorting time complexity
* **Auxiliary Space:** 💾 O(n) - Array storage for all elements

### ✅ **Why This Approach?**

* Simplest implementation using standard library
* Better cache performance due to array access
* Easy to understand and debug

## 📊 **4️⃣ Three-Way Split Approach**

### 💡 Algorithm Steps:

1. Split list into three parts instead of two for better balance.
2. Recursively sort each of the three sublists.
3. Merge three sorted sublists using a three-way merge.
4. Reduces recursion depth compared to binary splitting.

```cpp
class Solution {
public:
    Node *mergeSort(Node *head) {
        if (!head || !head->next) return head;
        if (!head->next->next) {
            if (head->data > head->next->data) {
                swap(head->data, head->next->data);
            }
            return head;
        }
        
        Node *mid1, *mid2;
        split3(head, &mid1, &mid2);
        head = mergeSort(head);
        mid1 = mergeSort(mid1);
        mid2 = mergeSort(mid2);
        return merge3(head, mid1, mid2);
    }

private:
    void split3(Node *head, Node **mid1, Node **mid2) {
        Node *slow = head, *fast = head;
        Node *prev = nullptr;
        
        while (fast && fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next->next;
        } 
        *mid1 = slow->next;
        if (*mid1) {
            *mid2 = (*mid1)->next;
            if (*mid2) (*mid1)->next = nullptr;
        }
        slow->next = nullptr;
    }
    
    Node *merge3(Node *a, Node *b, Node *c) {
        return merge(merge(a, b), c);
    }
    
    Node *merge(Node *a, Node *b) {
        if (!a) return b;
        if (!b) return a;
        if (a->data <= b->data) {
            a->next = merge(a->next, b);
            return a;
        }
        b->next = merge(a, b->next);
        return b;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log₃ n) - Slightly better than binary split
* **Auxiliary Space:** 💾 O(log₃ n) - Reduced recursion depth

### ✅ **Why This Approach?**

* Reduced recursion depth for very large lists
* More balanced splits in some cases
* Interesting algorithmic variation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Recursive Divide-Conquer**   | 🟢 O(n log n)          | 🟡 O(log n)             | 🚀 Simple and elegant            | 📚 Stack space usage                |
| 🔍 **Iterative Bottom-Up**        | 🟢 O(n log n)          | 🟢 O(1)                 | 💾 Constant space                | 📖 Complex implementation            |
| 📊 **Array Conversion**            | 🟢 O(n log n)          | 🟡 O(n)                 | 🎯 Simple using std::sort        | 💾 Extra space for array             |
| 🔄 **Three-Way Split**             | 🟢 O(n log₃ n)         | 🟡 O(log₃ n)            | ⭐ Reduced recursion depth       | 🔧 More complex merge logic          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General purpose/Interview**                  | 🥇 **Recursive Divide-Conquer**      | ★★★★★                     |
| 📖 **Memory constrained**                         | 🥈 **Iterative Bottom-Up**           | ★★★★☆                     |
| 🔧 **Quick implementation**                       | 🥉 **Array Conversion**              | ★★★☆☆                     |
| 🎯 **Very large lists**                           | 🏅 **Iterative Bottom-Up**           | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public Node mergeSort(Node h) {
        if (h == null || h.next == null) return h;
        Node s = h, f = h.next;
        while (f != null && f.next != null) {
            s = s.next;
            f = f.next.next;
        }
        Node r = s.next;
        s.next = null;
        return merge(mergeSort(h), mergeSort(r));
    }
    
    Node merge(Node a, Node b) {
        if (a == null) return b;
        if (b == null) return a;
        if (a.data <= b.data) {
            a.next = merge(a.next, b);
            return a;
        }
        b.next = merge(a, b.next);
        return b;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def mergeSort(self, h):
        if not h or not h.next: return h
        s, f = h, h.next
        while f and f.next:
            s, f = s.next, f.next.next
        r = s.next
        s.next = None
        return self.merge(self.mergeSort(h), self.mergeSort(r))
    
    def merge(self, a, b):
        if not a: return b
        if not b: return a
        if a.data <= b.data:
            a.next = self.merge(a.next, b)
            return a
        b.next = self.merge(a, b.next)
        return b
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



















## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    Node *mergeSort(Node *h) {
        if (!h || !h->next) return h;
        Node *s = h, *f = h->next;
        while (f && f->next) s = s->next, f = f->next->next;
        Node *r = s->next;
        s->next = nullptr;
        return merge(mergeSort(h), mergeSort(r));
    }
    
    Node *merge(Node *a, Node *b) {
        if (!a) return b;
        if (!b) return a;
        if (a->data <= b->data) {
            a->next = merge(a->next, b);
            return a;
        }
        b->next = merge(a, b->next);
        return b;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative Bottom-Up Approach**

### 💡 Algorithm Steps:

1. Start with sublist size 1, then 2, 4, 8, etc.
2. Merge adjacent sublists of current size iteratively.
3. Double the sublist size in each iteration until it exceeds list length.
4. No recursion overhead, purely iterative solution.

```cpp
class Solution {
public:
    Node *mergeSort(Node *head) {
        if (!head || !head->next) return head;
        int len = getLength(head);
        Node dummy(0);
        dummy.next = head;
        
        for (int sz = 1; sz < len; sz *= 2) {
            Node *prev = &dummy;
            Node *curr = dummy.next;
            while (curr) {
                Node *left = curr;
                Node *right = split(left, sz);
                curr = split(right, sz);
                prev->next = merge(left, right);
                while (prev->next) prev = prev->next;
            }
        }
        return dummy.next;
    }

private:
    int getLength(Node *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    Node *split(Node *head, int n) {
        while (--n && head) head = head->next;
        Node *rest = head ? head->next : nullptr;
        if (head) head->next = nullptr;
        return rest;
    }
    Node *merge(Node *a, Node *b) {
        Node dummy(0);
        Node *tail = &dummy;
        while (a && b) {
            if (a->data <= b->data) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return dummy.next;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Same as recursive but no stack overhead
* **Auxiliary Space:** 💾 O(1) - Constant space, no recursion stack

### ✅ **Why This Approach?**

* No recursion stack overflow risk for large lists
* Constant space complexity
* Better for memory-constrained environments

## 📊 **3️⃣ Array Conversion Approach**

### 💡 Algorithm Steps:

1. Convert linked list to array for random access.
2. Apply standard merge sort on array with O(log n) space.
3. Reconstruct linked list from sorted array.
4. Leverage array's cache locality for better performance.

```cpp
class Solution {
public:
    Node *mergeSort(Node *head) {
        if (!head || !head->next) return head;
        vector<int> vals;
        Node *curr = head;
        while (curr) {
            vals.push_back(curr->data);
            curr = curr->next;
        }
        sort(vals.begin(), vals.end());
        curr = head;
        for (int val : vals) {
            curr->data = val;
            curr = curr->next;
        }
        return head;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Standard sorting time complexity
* **Auxiliary Space:** 💾 O(n) - Array storage for all elements

### ✅ **Why This Approach?**

* Simplest implementation using standard library
* Better cache performance due to array access
* Easy to understand and debug

## 📊 **4️⃣ Three-Way Split Approach**

### 💡 Algorithm Steps:

1. Split list into three parts instead of two for better balance.
2. Recursively sort each of the three sublists.
3. Merge three sorted sublists using a three-way merge.
4. Reduces recursion depth compared to binary splitting.

```cpp
class Solution {
public:
    Node *mergeSort(Node *head) {
        if (!head || !head->next) return head;
        if (!head->next->next) {
            if (head->data > head->next->data) {
                swap(head->data, head->next->data);
            }
            return head;
        }
        
        Node *mid1, *mid2;
        split3(head, &mid1, &mid2);
        head = mergeSort(head);
        mid1 = mergeSort(mid1);
        mid2 = mergeSort(mid2);
        return merge3(head, mid1, mid2);
    }

private:
    void split3(Node *head, Node **mid1, Node **mid2) {
        Node *slow = head, *fast = head;
        Node *prev = nullptr;
        
        while (fast && fast->next && fast->next->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next->next;
        } 
        *mid1 = slow->next;
        if (*mid1) {
            *mid2 = (*mid1)->next;
            if (*mid2) (*mid1)->next = nullptr;
        }
        slow->next = nullptr;
    }
    Node *merge3(Node *a, Node *b, Node *c) {
        return merge(merge(a, b), c);
    }
    Node *merge(Node *a, Node *b) {
        if (!a) return b;
        if (!b) return a;
        if (a->data <= b->data) {
            a->next = merge(a->next, b);
            return a;
        }
        b->next = merge(a, b->next);
        return b;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log₃ n) - Slightly better than binary split
* **Auxiliary Space:** 💾 O(log₃ n) - Reduced recursion depth

### ✅ **Why This Approach?**

* Reduced recursion depth for very large lists
* More balanced splits in some cases
* Interesting algorithmic variation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Recursive Divide-Conquer**   | 🟢 O(n log n)          | 🟡 O(log n)             | 🚀 Simple and elegant            | 📚 Stack space usage                |
| 🔍 **Iterative Bottom-Up**        | 🟢 O(n log n)          | 🟢 O(1)                 | 💾 Constant space                | 📖 Complex implementation            |
| 📊 **Array Conversion**            | 🟢 O(n log n)          | 🟡 O(n)                 | 🎯 Simple using std::sort        | 💾 Extra space for array             |
| 🔄 **Three-Way Split**             | 🟢 O(n log₃ n)         | 🟡 O(log₃ n)            | ⭐ Reduced recursion depth       | 🔧 More complex merge logic          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General purpose/Interview**                  | 🥇 **Recursive Divide-Conquer**      | ★★★★★                     |
| 📖 **Memory constrained**                         | 🥈 **Iterative Bottom-Up**           | ★★★★☆                     |
| 🔧 **Quick implementation**                       | 🥉 **Array Conversion**              | ★★★☆☆                     |
| 🎯 **Very large lists**                           | 🏅 **Iterative Bottom-Up**           | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public Node mergeSort(Node h) {
        if (h == null || h.next == null) return h;
        Node s = h, f = h.next;
        while (f != null && f.next != null) {
            s = s.next;
            f = f.next.next;
        }
        Node r = s.next;
        s.next = null;
        return merge(mergeSort(h), mergeSort(r));
    }
    
    Node merge(Node a, Node b) {
        if (a == null) return b;
        if (b == null) return a;
        if (a.data <= b.data) {
            a.next = merge(a.next, b);
            return a;
        }
        b.next = merge(a, b.next);
        return b;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def mergeSort(self, h):
        if not h or not h.next: return h
        s, f = h, h.next
        while f and f.next:
            s, f = s.next, f.next.next
        r = s.next
        s.next = None
        return self.merge(self.mergeSort(h), self.mergeSort(r))
    
    def merge(self, a, b):
        if not a: return b
        if not b: return a
        if a.data <= b.data:
            a.next = self.merge(a.next, b)
            return a
        b.next = self.merge(a, b.next)
        return b
```
