---
title: "🔄 Queue Reversal | GFG Solution 🚀"
keywords🏷️: ["🔄 queue reversal", "🔁 recursion", "📦 stack", "🗂️ data structures", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Queue Reversal problem: reverse all elements in a queue using recursion, stack, or auxiliary data structures. 🚀"
date: 📅 2025-09-23
---

# *23. Queue Reversal*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/queue-reversal/1)

## **🧩 Problem Description**

Given a queue `q` containing integer elements, your task is to **reverse the queue**. The queue should be modified in-place such that the first element becomes the last, the second element becomes the second last, and so on.

A queue follows the FIFO (First In First Out) principle, but after reversal, the elements should appear in LIFO (Last In First Out) order when dequeued.

## **📘 Examples**

### Example 1

```cpp
Input: q[] = [5, 10, 15, 20, 25]
Output: [25, 20, 15, 10, 5]
Explanation: After reversing the given elements of the queue, the resultant queue will be 25 20 15 10 5.
```

### Example 2

```cpp
Input: q[] = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
Explanation: After reversing the given elements of the queue, the resultant queue will be 5 4 3 2 1.
```

### Example 3

```cpp
Input: q[] = [42]
Output: [42]
Explanation: A single element queue remains unchanged after reversal.
```

## **🔒 Constraints**

* $1 \le \text{q.size()} \le 10^3$
* $0 \le \text{q}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses **Recursion** to elegantly reverse the queue without requiring additional data structures for storage:

### **Recursive Approach**

1. **Base Case:**
   * If the queue is empty, return immediately (nothing to reverse).

2. **Recursive Step:**
   * Remove the front element and store it temporarily.
   * Recursively reverse the remaining queue.
   * Add the stored element back to the queue (it will now be at the rear).

3. **Stack Behavior:**
   * The recursion call stack naturally provides LIFO behavior.
   * Elements are removed in FIFO order but added back in LIFO order.

4. **In-Place Modification:**
   * The original queue is modified without creating additional queues.
   * Uses only the implicit call stack for temporary storage.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of elements in the queue. Each element is processed exactly once during the recursive calls.
* **Expected Auxiliary Space Complexity:** O(n), due to the recursion call stack. In the worst case, we have n recursive calls on the call stack simultaneously.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    void reverseQueue(queue<int>& q) {
        if (q.empty()) return;
        int x = q.front();
        q.pop();
        reverseQueue(q);
        q.push(x);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Stack-Based Approach**

### 💡 Algorithm Steps:

1. Push all queue elements to a stack for LIFO ordering.
2. Pop elements from stack and push back to queue.
3. Stack's LIFO nature automatically reverses the order.
4. Simple auxiliary data structure approach.

```cpp
class Solution {
public:
    void reverseQueue(queue<int>& q) {
        stack<int> s;
        while (!q.empty()) s.push(q.front()), q.pop();
        while (!s.empty()) q.push(s.top()), s.pop();
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal of all elements
* **Auxiliary Space:** 💾 O(n) - Stack space for all elements

### ✅ **Why This Approach?**

* Intuitive stack-based reversal pattern
* Easy to implement and debug
* Clear separation of operations

## 📊 **3️⃣ Vector-Based Approach**

### 💡 Algorithm Steps:

1. Transfer all queue elements to a vector container.
2. Use vector's reverse iterator to iterate backwards.
3. Push elements back to queue in reversed order.
4. Leverages STL container's efficient random access.

```cpp
class Solution {
public:
    void reverseQueue(queue<int>& q) {
        vector<int> v;
        while (!q.empty()) v.push_back(q.front()), q.pop();
        for (auto it = v.rbegin(); it != v.rend(); ++it) q.push(*it);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear operations on vector
* **Auxiliary Space:** 💾 O(n) - Vector storage space

### ✅ **Why This Approach?**

* Utilizes STL reverse iterators efficiently
* Clean and readable implementation
* Good performance with vector operations

## 📊 **4️⃣ Array-Based Approach**

### 💡 Algorithm Steps:

1. Store queue elements in a fixed or dynamic array.
2. Use two pointers from end to beginning for reversal.
3. Push elements back to queue in reverse order.
4. Memory efficient with direct array access.

```cpp
class Solution {
public:
    void reverseQueue(queue<int>& q) {
        int n = q.size(), arr[n], i = 0;
        while (!q.empty()) arr[i++] = q.front(), q.pop();
        while (--i >= 0) q.push(arr[i]);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through elements
* **Auxiliary Space:** 💾 O(n) - Array storage requirement

### ✅ **Why This Approach?**

* Direct array manipulation for efficiency
* Minimal overhead compared to containers
* Simple indexing logic

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Recursive**                  | 🟢 O(n)                | 🟡 O(n)                 | 🚀 No auxiliary data structure    | 📚 Call stack space usage            |
| 📦 **Stack-Based**                | 🟢 O(n)                | 🟡 O(n)                 | 📖 Intuitive reversal logic      | 💾 Extra stack space                 |
| 🗂️ **Vector-Based**               | 🟢 O(n)                | 🟡 O(n)                 | 🎯 STL reverse iterator support   | 🔧 Container overhead                 |
| 📊 **Array-Based**                | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Direct memory access           | 🔢 Fixed size limitation              |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Space efficient recursion**                     | 🥇 **Recursive**                     | ★★★★★                     |
| 📖 **Clear logic flow**                              | 🥈 **Stack-Based**                   | ★★★★☆                     |
| 🔧 **STL integration**                               | 🥉 **Vector-Based**                  | ★★★★☆                     |
| 🎯 **Performance critical**                          | 🏅 **Array-Based**                   | ★★★★★                     |

</details>


## **☕ Code (Java)**

```java
class Solution {
    public void reverseQueue(Queue<Integer> q) {
        if (q.isEmpty()) return;
        int x = q.poll();
        reverseQueue(q);
        q.offer(x);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def reverseQueue(self, q):
        s = []
        while q:
            s.append(q.popleft())
        while s:
            q.append(s.pop())
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


