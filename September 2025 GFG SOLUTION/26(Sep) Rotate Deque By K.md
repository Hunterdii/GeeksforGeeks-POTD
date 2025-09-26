---
title: "🔄 Rotate Deque By K | GFG Solution 🚀"
keywords🏷️: ["🔄 deque rotation", "🔍 circular rotation", "📍 double-ended queue", "📈 two-pointer", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Rotate Deque By K problem: efficiently rotate deque left or right by k positions using optimized push/pop operations. 🚀"
date: 📅 2025-09-26
---

# *26. Rotate Deque By K*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/rotate-deque-by-k/1)

## **🧩 Problem Description**

You are given a deque `dq` (double-ended queue) containing non-negative integers, along with two positive integers `type` and `k`. The task is to rotate the deque circularly by `k` positions.

There are two types of rotation operations:

- **Right Rotation (Clockwise)**: If `type = 1`, rotate the deque to the right. This means moving the last element to the front, and repeating the process k times.
- **Left Rotation (Anti-Clockwise)**: If `type = 2`, rotate the deque to the left. This means moving the first element to the back, and repeating the process k times.

## **📘 Examples**

### Example 1

```cpp
Input: dq = [1, 2, 3, 4, 5, 6], type = 1, k = 2
Output: [5, 6, 1, 2, 3, 4]
Explanation: The type is 1 and k is 2. So, we need to right rotate deque by 2 times.
In first right rotation we get [6, 1, 2, 3, 4, 5].
In second right rotation we get [5, 6, 1, 2, 3, 4].
```

### Example 2

```cpp
Input: dq = [10, 20, 30, 40, 50], type = 2, k = 3
Output: [40, 50, 10, 20, 30]
Explanation: The type is 2 and k is 3. So, we need to left rotate deque by 3 times.
In first left rotation we get [20, 30, 40, 50, 10].
In second left rotation we get [30, 40, 50, 10, 20].
In third left rotation we get [40, 50, 10, 20, 30].
```

## **🔒 Constraints**

* $1 \le \text{dq.size()} \le 10^5$
* $1 \le k \le 10^5$
* $1 \le \text{type} \le 2$

## **✅ My Approach**

The optimal approach uses **Direct Push/Pop Operations** on the deque to achieve efficient rotation:

### **Push/Pop Operations Method**

1. **Handle Edge Cases:**
   * If deque is empty or k is 0, no rotation needed.
   * Use modulo operation `k %= n` to handle cases where k > n.

2. **Right Rotation (type = 1):**
   * Move the last element to the front k times.
   * Use `push_front(back())` and `pop_back()` operations.
   * This simulates clockwise rotation.

3. **Left Rotation (type = 2):**
   * Move the first element to the back k times.
   * Use `push_back(front())` and `pop_front()` operations.
   * This simulates anti-clockwise rotation.

4. **Optimization:**
   * Deque provides O(1) operations for both ends.
   * No need for additional data structures or complex algorithms.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(k), where k is the number of rotations after taking modulo with deque size. Each rotation involves O(1) push/pop operations.
* **Expected Auxiliary Space Complexity:** O(1), as we only use the existing deque without any additional space for temporary storage.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) {
            for (int i = 0; i < k; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        } else {
            for (int i = 0; i < k; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ STL Rotate Algorithm Approach**

### 💡 Algorithm Steps:

1. Use STL's rotate function for efficient in-place rotation.
2. Calculate appropriate iterator positions based on rotation type.
3. Single function call handles all rotation logic internally.
4. Optimal performance with library-optimized implementation.

```cpp
class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) 
            rotate(dq.begin(), dq.end() - k, dq.end());
        else 
            rotate(dq.begin(), dq.begin() + k, dq.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time with optimized swaps
* **Auxiliary Space:** 💾 O(1) - In-place rotation

### ✅ **Why This Approach?**

* Leverages highly optimized STL implementation.
* Clean and concise code.
* Handles edge cases internally.

## 📊 **3️⃣ Reverse-Based Approach**

### 💡 Algorithm Steps:

1. Use three reverse operations to achieve rotation effect.
2. Mathematical property: reverse(reverse(A) + reverse(B)) = rotation.
3. Apply different reverse sequences for left vs right rotation.
4. In-place operation with custom reverse implementation.

```cpp
class Solution {
public:
    void reverseDeque(deque<int>& dq, int start, int end) {
        while (start < end) {
            swap(dq[start], dq[end]);
            start++;
            end--;
        }
    }
    
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) {
            reverseDeque(dq, 0, n - 1);
            reverseDeque(dq, 0, k - 1);
            reverseDeque(dq, k, n - 1);
        } else {
            reverseDeque(dq, 0, k - 1);
            reverseDeque(dq, k, n - 1);
            reverseDeque(dq, 0, n - 1);
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Three passes through portions of array
* **Auxiliary Space:** 💾 O(1) - In-place with only swap operations

### ✅ **Why This Approach?**

* Classic algorithmic technique.
* No dependency on STL functions.
* Good for understanding rotation mechanics.

## 📊 **4️⃣ Two-Phase Copy Approach**

### 💡 Algorithm Steps:

1. Create temporary storage for elements to be moved.
2. Copy elements in two phases based on rotation direction.
3. Reconstruct deque with rotated order.
4. Handle both rotation types with unified logic.

```cpp
class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        vector<int> temp(dq.begin(), dq.end());
        dq.clear();
        
        if (type == 1) {
            for (int i = n - k; i < n; i++) dq.push_back(temp[i]);
            for (int i = 0; i < n - k; i++) dq.push_back(temp[i]);
        } else {
            for (int i = k; i < n; i++) dq.push_back(temp[i]);
            for (int i = 0; i < k; i++) dq.push_back(temp[i]);
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear copy operations
* **Auxiliary Space:** 💾 O(n) - Temporary vector storage

### ✅ **Why This Approach?**

* Simple logic with clear separation.
* Good for educational purposes.
* Easy to understand and debug.

## 📊 **5️⃣ Iterator-Based Splice Approach**

### 💡 Algorithm Steps:

1. Split deque into two parts at rotation point.
2. Use splice operation to rearrange parts efficiently.
3. Deque's splice provides O(1) operation for moving elements.
4. No actual element copying, just pointer manipulation.

```cpp
class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) k = n - k;
        
        list<int> temp(dq.begin(), dq.end());
        auto it = temp.begin();
        advance(it, k);
        temp.splice(temp.end(), temp, temp.begin(), it);
        dq.assign(temp.begin(), temp.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear for conversion operations
* **Auxiliary Space:** 💾 O(n) - Temporary list creation

### ✅ **Why This Approach?**

* Demonstrates splice technique
* Useful for linked-list based containers
* Educational value for understanding container operations

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Push/Pop Operations**         | 🟢 O(k)                | 🟢 O(1)                 | 🚀 Optimal for small k           | 🐌 Slower for large k                |
| 🔧 **STL Rotate**                 | 🟢 O(n)                | 🟢 O(1)                 | 📖 Clean and optimized           | 🔗 STL dependency                    |
| 🔄 **Reverse Operations**         | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Classic algorithm              | 🔧 More complex logic               |
| 📋 **Two-Phase Copy**             | 🟡 O(n)                | 🟡 O(n)                 | 🎯 Simple and clear               | 💾 Extra memory usage               |
| 🔗 **Splice Method**              | 🟡 O(n)                | 🟡 O(n)                 | 🎯 Demonstrates advanced technique| 💾 Extra memory usage               |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Small rotation values (k < n/2)**               | 🥇 **Push/Pop Operations**            | ★★★★★                     |
| 📖 **Production code, large k**                      | 🥈 **STL Rotate**                     | ★★★★★                     |
| 🔧 **Interview/Educational**                         | 🥉 **Reverse Operations**             | ★★★★☆                     |
| 🎯 **Simplicity over efficiency**                    | 🏅 **Two-Phase Copy**                 | ★★★☆☆                     |
| 🎯 **Advanced techniques**                           | 🎖️ **Splice Method**                  | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static void rotateDeque(Deque<Integer> dq, int type, int k) {
        int n = dq.size();
        if (n == 0 || (k %= n) == 0) return;
        
        if (type == 1) {
            for (int i = 0; i < k; i++) {
                dq.addFirst(dq.removeLast());
            }
        } else {
            for (int i = 0; i < k; i++) {
                dq.addLast(dq.removeFirst());
            }
        }
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:    
    def rotateDeque(self, dq, type, k):
        n = len(dq)
        if n == 0 or k % n == 0: return
        k %= n
        
        if type == 1:
            for _ in range(k):
                dq.appendleft(dq.pop())
        else:
            for _ in range(k):
                dq.append(dq.popleft())
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

