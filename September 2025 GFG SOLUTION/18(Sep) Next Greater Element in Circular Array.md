---
title: "🔄 Next Greater Element in Circular Array | GFG Solution 🔍"
keywords🏷️: ["🔄 circular array", "🔍 stack", "📍 next greater element", "📈 monotonic stack", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Next Greater Element in Circular Array problem: find next greater element for each position in circular array using monotonic stack technique. 🚀"
date: 📅 2025-09-18
---

# *18. Next Greater Element in Circular Array*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/next-greater-element/1)

## **🧩 Problem Description**

Given a circular integer array `arr[]`, the task is to determine the **next greater element (NGE)** for each element in the array.

The next greater element of an element `arr[i]` is the first element that is greater than `arr[i]` when traversing circularly. If no such element exists, return -1 for that position.

**Note:** Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation:
The next greater element for 1 is 3.
The next greater element for 3 is 4.
The next greater element for 2 is 4.
The next greater element for 4 does not exist, so return -1.
```

### Example 2

```cpp
Input: arr[] = [0, 2, 3, 1, 1]
Output: [2, 3, -1, 2, 2]
Explanation:
The next greater element for 0 is 2.
The next greater element for 2 is 3.
The next greater element for 3 does not exist, so return -1.
The next greater element for 1 is 2 (from circular traversal).
The next greater element for 1 is 2 (from circular traversal).
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^6$

## **✅ My Approach**

The optimal approach uses a **Monotonic Stack** technique with **circular array simulation** to efficiently find the next greater element:

### **Monotonic Stack + Circular Traversal**

1. **Initialize Variables:**
   * Use a stack to store indices of elements for which we haven't found the next greater element yet.
   * Create a result vector initialized with -1 for all positions.
   * Traverse the array twice (2*n iterations) to simulate circular behavior.

2. **Stack Operations:**
   * For each element, pop from stack all indices whose corresponding values are smaller than current element.
   * Set the next greater element for these popped indices as the current element.
   * Push current index to stack only in the first traversal (i < n).

3. **Circular Logic:**
   * Use modular arithmetic `i % n` to access array elements in circular manner.
   * The second traversal handles cases where next greater element is at the beginning of array.

4. **Monotonic Property:**
   * Stack maintains indices in decreasing order of their corresponding values.
   * This ensures O(1) amortized time for finding next greater elements.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is pushed and popped from the stack at most once, resulting in O(2n) operations which simplifies to O(n).
* **Expected Auxiliary Space Complexity:** O(n), where n is the size of the array. In the worst case (when array is in decreasing order), all indices are stored in the stack simultaneously.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 0; i < 2 * n; i++) {
            while (!stk.empty() && arr[stk.top()] < arr[i % n]) {
                res[stk.top()] = arr[i % n];
                stk.pop();
            }
            if (i < n) stk.push(i);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Reverse Traversal with Value Stack**

### 💡 Algorithm Steps:

1. Traverse array twice from right to left to simulate circular behavior.
2. Use stack to store actual values instead of indices for direct comparison.
3. Pop smaller elements and push current element to maintain decreasing stack.
4. Stack top gives the next greater element for current position.

```cpp
class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= arr[i % n]) stk.pop();
            if (i < n && !stk.empty()) res[i] = stk.top();
            stk.push(arr[i % n]);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each element pushed and popped once
* **Auxiliary Space:** 💾 O(n) - Stack space for storing values

### ✅ **Why This Approach?**

* Direct value comparison without index mapping
* Intuitive right-to-left processing
* Clean stack operations with values

## 📊 **3️⃣ Two-Pass Index Mapping**

### 💡 Algorithm Steps:

1. First pass: Process elements from left and store indices in stack.
2. Second pass: Continue processing remaining elements in circular manner.
3. Use index-based stack to track positions and map results efficiently.
4. Maintain monotonic decreasing stack for optimal performance.

```cpp
class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int pass = 0; pass < 2; pass++) {
            for (int i = 0; i < n; i++) {
                while (!stk.empty() && arr[stk.top()] < arr[i]) {
                    res[stk.top()] = arr[i];
                    stk.pop();
                }
                if (pass == 0) stk.push(i);
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two passes through the array
* **Auxiliary Space:** 💾 O(n) - Stack for indices

### ✅ **Why This Approach?**

* Clear separation of circular logic with two explicit passes
* Index-based tracking for precise result mapping
* Easy to understand and debug

## 📊 **4️⃣ Optimized Single Loop**

### 💡 Algorithm Steps:

1. Single loop with modular arithmetic for circular array simulation.
2. Process first n elements normally, then continue for circular behavior.
3. Optimize by avoiding redundant operations in second half.
4. Use early termination when all results are found.

```cpp
class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        int remaining = n;
        for (int i = 0; i < 2 * n && remaining > 0; i++) {
            while (!stk.empty() && arr[stk.top()] < arr[i % n]) {
                res[stk.top()] = arr[i % n];
                stk.pop();
                remaining--;
            }
            if (i < n) stk.push(i);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Early termination optimization
* **Auxiliary Space:** 💾 O(n) - Stack space

### ✅ **Why This Approach?**

* Early termination when all elements processed
* Counter-based optimization for performance
* Reduced iterations in best-case scenarios

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Forward Index Stack**        | 🟢 O(n)                | 🟢 O(n)                 | 🚀 Clean index mapping           | 🔧 Slightly more complex logic       |
| 🔍 **Reverse Value Stack**         | 🟢 O(n)                | 🟢 O(n)                 | 📖 Intuitive value comparison    | 💾 Stores values instead of indices  |
| 📊 **Two-Pass Method**             | 🟢 O(n)                | 🟢 O(n)                 | 🎯 Clear separation of logic     | 🐌 Always two full passes            |
| 🔄 **Optimized Single Loop**       | 🟢 O(n)                | 🟢 O(n)                 | ⭐ Early termination              | 🔧 Additional counter tracking       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Interview/Competitive**                      | 🥇 **Forward Index Stack**           | ★★★★★                     |
| 📖 **Learning/Understanding**                     | 🥈 **Reverse Value Stack**           | ★★★★☆                     |
| 🔧 **Code Clarity**                               | 🥉 **Two-Pass Method**               | ★★★★☆                     |
| 🎯 **Performance Critical**                       | 🏅 **Optimized Single Loop**         | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> nextGreater(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>(Collections.nCopies(n, -1));
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < 2 * n; i++) {
            while (!stk.isEmpty() && arr[stk.peek()] < arr[i % n]) {
                res.set(stk.pop(), arr[i % n]);
            }
            if (i < n) stk.push(i);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def nextGreater(self, arr):
        n = len(arr)
        res = [-1] * n
        stk = []
        for i in range(2 * n):
            while stk and arr[stk[-1]] < arr[i % n]:
                res[stk.pop()] = arr[i % n]
            if i < n:
                stk.append(i)
        return res
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
