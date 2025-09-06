---
title: "🔗 Find Length of Loop | GFG Solution 🎯"
keywords🏷️: ["🔗 linked list", "🔄 cycle detection", "🏃‍♂️ floyd's algorithm", "📍 two pointers", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Find Length of Loop problem: detect and count nodes in a linked list loop using Floyd's Cycle Detection Algorithm (Tortoise and Hare). 🚀"
date: 📅 2025-09-06
---

# *06. Find Length of Loop*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-length-of-loop/1)

## **🧩 Problem Description**

Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the **number of nodes in the loop**, otherwise return **0**.

**Note:** Internally, pos(1 based index) is used to denote the position of the node that tail's next pointer is connected to. If pos = 0, it means the last node points to null, indicating there is no loop. Note that pos is not passed as a parameter.

## **📘 Examples**

### Example 1

```cpp
Input: pos = 2
Output: 4
Explanation: There exists a loop in the linked list and the length of the loop is 4.
```

### Example 2

```cpp
Input: pos = 3
Output: 3
Explanation: The loop is from 19 to 10. So length of loop is 19 → 33 → 10 = 3.
```

### Example 3

```cpp
Input: pos = 0
Output: 0
Explanation: There is no loop.
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 10^5$
* $1 \le \text{node->data} \le 10^4$
* $0 \le \text{pos} < \text{number of nodes}$

## **✅ My Approach**

The optimal approach uses **Floyd's Cycle Detection Algorithm** (also known as the **Tortoise and Hare Algorithm**):

### **Floyd's Cycle Detection + Loop Length Calculation**

1. **Phase 1 - Loop Detection:**
   * Use two pointers: `slow` (moves 1 step) and `fast` (moves 2 steps).
   * If there's a loop, `slow` and `fast` will eventually meet inside the loop.
   * If `fast` reaches NULL, there's no loop.

2. **Phase 2 - Loop Length Calculation:**
   * Once loop is detected (when `slow == fast`), keep one pointer fixed.
   * Move the other pointer one step at a time until it completes one full cycle.
   * Count the steps taken - this gives the loop length.

3. **Edge Cases:**
   * If no loop exists, return 0.
   * Handle single node and empty list cases.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the linked list. In the worst case, we traverse the entire list once to detect the loop, and then traverse the loop once more to count its length.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the two pointers, regardless of the size of the linked list.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int lengthOfLoop(Node* head) {
        Node *s = head, *f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) {
                int cnt = 1;
                while (s->next != f) s = s->next, cnt++;
                return cnt;
            }
        }
        return 0;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Hash Set Approach**

### 💡 Algorithm Steps:

1. Traverse the linked list and store each node address in a hash set.
2. When we encounter a node that's already in the set, we've found the loop start.
3. Continue traversal from loop start, counting nodes until we return to the same node.
4. Return the count of nodes in the loop.

```cpp
class Solution {
public:
    int lengthOfLoop(Node* head) {
        unordered_set<Node*> visited;
        Node* curr = head;
        while (curr) {
            if (visited.count(curr)) {
                int len = 1;
                Node* start = curr->next;
                while (start != curr) start = start->next, len++;
                return len;
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single traversal with hash operations
* **Auxiliary Space:** 💾 O(n) - Hash set to store visited nodes

### ✅ **Why This Approach?**

* Straightforward logic with clear loop detection
* No complex pointer manipulation required
* Easy to debug and understand

## 📊 **3️⃣ Modified Floyd's with Distance Calculation**

### 💡 Algorithm Steps:

1. Use Floyd's algorithm to detect if a loop exists.
2. Once loop is detected, keep slow pointer at meeting point.
3. Move fast pointer to head and advance both pointers one step at a time.
4. When they meet again, that's the loop start, then count the loop length.

```cpp
class Solution {
public:
    int lengthOfLoop(Node* head) {
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return 0;
        
        fast = head;
        while (slow != fast) slow = slow->next, fast = fast->next;
        
        int length = 1;
        fast = slow->next;
        while (fast != slow) fast = fast->next, length++;
        return length;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Multiple passes but still linear
* **Auxiliary Space:** 💾 O(1) - Only pointer variables used

### ✅ **Why This Approach?**

* Finds exact loop start position
* Constant space complexity
* Classical two-phase Floyd's cycle detection

## 📊 **4️⃣ Single Pass Optimized Floyd's**

### 💡 Algorithm Steps:

1. Run standard Floyd's cycle detection algorithm.
2. As soon as slow and fast pointers meet, start counting from that position.
3. Move one pointer step by step until it completes one full loop cycle.
4. Return the count without needing separate loop start detection.

```cpp
class Solution {
public:
    int lengthOfLoop(Node* head) {
        if (!head || !head->next) return 0;
        
        Node *slow = head->next, *fast = head->next->next;
        while (fast && fast->next && slow != fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (!fast || !fast->next) return 0;
        
        int count = 1;
        fast = slow->next;
        while (fast != slow) {
            fast = fast->next;
            count++;
        }
        return count;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Optimized single detection phase
* **Auxiliary Space:** 💾 O(1) - Minimal pointer usage

### ✅ **Why This Approach?**

* Most optimized runtime performance
* Minimal pointer operations
* Direct loop length calculation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Direct Floyd's**              | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Fastest execution              | 🔧 Requires loop detection first     |
| 🔍 **Hash Set**                    | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clearest logic                | 💾 Extra memory overhead             |
| 📊 **Modified Floyd's**            | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Finds loop start               | 🐌 Multiple traversal phases         |
| 🔄 **Single Pass Floyd's**         | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Most optimized                 | 🔧 Slightly complex logic            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Maximum performance needed**                     | 🥇 **Direct Floyd's**                | ★★★★★                     |
| 📖 **Code clarity priority**                          | 🥈 **Hash Set**                      | ★★★★☆                     |
| 🔧 **Need loop start position**                       | 🥉 **Modified Floyd's**              | ★★★★☆                     |
| 🎯 **Competitive programming**                        | 🏅 **Single Pass Floyd's**           | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int lengthOfLoop(Node head) {
        Node s = head, f = head;
        while (f != null && f.next != null) {
            s = s.next;
            f = f.next.next;
            if (s == f) {
                int cnt = 1;
                while (s.next != f) {
                    s = s.next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def lengthOfLoop(self, head):
        s, f = head, head
        while f and f.next:
            s, f = s.next, f.next.next
            if s == f:
                cnt = 1
                while s.next != f:
                    s, cnt = s.next, cnt + 1
                return cnt
        return 0
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

