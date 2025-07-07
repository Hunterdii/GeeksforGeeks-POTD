---
title: "🔄 Next Greater Element in Circular Array | GFG Solution 🔍"
keywords🏷️: ["🔄 circular array", "📚 stack", "🔍 next greater element", "📈 monotonic stack", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Next Greater Element in Circular Array problem: find the next greater element for each element in a circular array using monotonic stack technique. 🚀"
date: 📅 2025-07-07
---

# *07. Next Greater Element in Circular Array*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/next-greater-element/1)

## **🧩 Problem Description**

Given a circular integer array `arr[]`, the task is to determine the **next greater element (NGE)** for each element in the array.

The next greater element of an element `arr[i]` is the first element that is greater than `arr[i]` when traversing circularly. If no such element exists, return -1 for that position.

### **Circular Property:**
Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once.

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

## ✅ **My Approach**

The optimal solution leverages a **Monotonic Stack** combined with a **Circular Traversal** to efficiently compute the **Next Greater Element** for each position in the array:

### **Monotonic Stack with Circular Traversal**

1. **Problem Observation**:

   * We're asked to find the **next greater element** for every element in the array, considering the array as **circular**.
   * If no greater element exists, return `-1` for that position.

2. **Circular Traversal Strategy**:

   * To simulate a circular array, we **traverse the array twice** (from `2n-1` to `0`), using modulo (`% n`) to wrap around.
   * This ensures every element can “see” all others to its right and left (as per circular property).

3. **Stack Stores Candidates**:

   * Use a **monotonic decreasing stack** to keep track of potential "next greater" elements.
   * Elements in the stack are always **greater than the current value** for which we are finding the NGE.

4. **Processing Each Index (Right to Left)**:

   * For every index `i` from `2n-1` to `0`:

     * Discard all elements from the stack that are **less than or equal** to `arr[i % n]` (they can't be NGE).
     * If we're in the **first pass (i < n)**:

       * The top of the stack is the **next greater element** for this index.
       * If the stack is empty, it means no NGE exists; keep result as `-1`.
     * Push `arr[i % n]` into the stack for future comparisons.

5. **Result Accumulation**:

   * Maintain a `res[]` array initialized to `-1`.
   * Update the result during the first pass only, to avoid overwriting values from the second simulated pass.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is pushed and popped from the stack at most once during the 2*n traversal.
* **Expected Auxiliary Space Complexity:** O(n), for the stack that stores at most n elements in the worst case.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i % n]) st.pop();
            if (i < n && !st.empty()) res[i] = st.top();
            st.push(arr[i % n]);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass with Index Stack**

### 💡 Algorithm Steps:

1. Use stack to store indices instead of values
2. Single traversal with circular array simulation
3. Direct result assignment during traversal
4. Efficient memory usage

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
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

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - for stack

### ✅ **Why This Approach?**

* Forward traversal with index tracking
* Direct result assignment
* Better cache locality

## 📊 **3️⃣ Optimized Value Stack**

### 💡 Algorithm Steps:

1. Traverse array twice for circular behavior
2. Use value-based stack operations
3. Minimize stack operations
4. Early termination optimizations

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<pair<int, int>> stk;
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while (!stk.empty() && stk.top().first < arr[idx]) {
                res[stk.top().second] = arr[idx];
                stk.pop();
            }
            if (i < n) stk.push({arr[idx], idx});
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - for stack with pairs

### ✅ **Why This Approach?**

* Combined value and index tracking
* Efficient pair operations
* Reduced lookup overhead

## 📊 **4️⃣ Reverse Traversal Optimization**

### 💡 Algorithm Steps:

1. Reverse order traversal for efficiency
2. Maintain monotonic decreasing stack
3. Immediate result assignment
4. Optimal for sorted arrays

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!stk.empty() && stk.top() <= arr[idx]) {
                stk.pop();
            }
            if (i < n) res[idx] = stk.empty() ? -1 : stk.top();
            stk.push(arr[idx]);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - for stack

### ✅ **Why This Approach?**

* Efficient reverse processing
* Minimal conditional checks
* Optimal for decreasing sequences

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Circular Array + Monotonic Stack**        | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Simple implementation         | 💾 Reverse traversal overhead        |
| 🔺 **Index Stack Forward**        | 🟢 O(n)                | 🟡 O(n)                 | 🔧 Direct assignment             | 💾 Index management overhead         |
| ⏰ **Pair Stack Forward**         | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Combined tracking             | 🔄 Pair creation overhead            |
| 📊 **Optimized Reverse**          | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Minimal conditionals          | 🔧 Less intuitive flow               |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **General purpose**                                | 🥇 **Circular Array + Monotonic Stack**           | ★★★★★                     |
| 📊 **Memory constrained**                             | 🥈 **Optimized Reverse**             | ★★★★☆                     |
| 🎯 **Forward processing preference**                  | 🥉 **Index Stack Forward**           | ★★★★☆                     |
| 🚀 **Competitive programming**                        | 🏅 **Value Stack Reverse**           | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public ArrayList<Integer> nextLargerElement(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>(Collections.nCopies(n, -1));
        Deque<Integer> st = new ArrayDeque<>();
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.isEmpty() && st.peek() <= arr[i % n]) st.pop();
            if (i < n && !st.isEmpty()) res.set(i, st.peek());
            st.push(arr[i % n]);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def nextLargerElement(self, arr):
        n = len(arr)
        res = [-1] * n
        st = []
        for i in range(2 * n - 1, -1, -1):
            while st and st[-1] <= arr[i % n]:
                st.pop()
            if i < n and st:
                res[i] = st[-1]
            st.append(arr[i % n])
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
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
