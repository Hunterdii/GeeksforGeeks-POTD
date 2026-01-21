---
title: "📊 Stock Span Problem | GFG Solution 🚀"
keywords🏷️: ["📊 stock span", "🔍 monotonic stack", "📈 next greater element", "📘 GFG", "🏁 competitive programming", "📚 DSA", "⏱️ time series"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Stock Span Problem: calculate consecutive days with stock prices less than or equal to current day using stack-based approach. 🚀"
date: 📅 2025-01-21
---

# *21. Stock Span Problem*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1)

## **🧩 Problem Description**

The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.

You are given an array `arr[]` representing daily stock prices. The **stock span** for the i-th day is the number of consecutive days up to day i (including day i itself) for which the price of the stock is less than or equal to the price on day i. Return the span of stock prices for each day in the given sequence.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [100, 80, 90, 120]
Output: [1, 1, 2, 4]
Explanation: Traversing the given input span 100 is greater than equal to 100 and there are no more days behind it so the span is 1, 80 is greater than equal to 80 and smaller than 100 so the span is 1, 90 is greater than equal to 90 and 80 so the span is 2, 120 is greater than 90, 80 and 100 so the span is 4. So the output will be [1, 1, 2, 4].
```

### Example 2

```cpp
Input: arr[] = [10, 4, 5, 90, 120, 80]
Output: [1, 1, 2, 4, 5, 1]
Explanation: Traversing the given input span 10 is greater than equal to 10 and there are no more days behind it so the span is 1, 4 is greater than equal to 4 and smaller than 10 so the span is 1, 5 is greater than equal to 4 and 5 and smaller than 10 so the span is 2, and so on. Hence the output will be [1, 1, 2, 4, 5, 1].
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses a **Monotonic Stack** technique to efficiently calculate the stock span in linear time:

### **Stack-Based Approach**

1. **Initialize Data Structures:**
   * Create a result vector to store span values for each day.
   * Use a stack to store indices of days (not prices directly).

2. **Process Each Day:**
   * For the current day `i`, pop elements from the stack while the stack is not empty and the price at stack's top index is less than or equal to current day's price.
   * This removes all consecutive previous days with lower or equal prices.

3. **Calculate Span:**
   * If stack becomes empty after popping, it means all previous days had lower or equal prices, so span = `i + 1`.
   * Otherwise, span = current index - index at stack's top (the last day with a higher price).

4. **Push Current Index:**
   * Push the current day's index onto the stack for future comparisons.

5. **Repeat:**
   * Continue this process for all days to build the complete span array.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is pushed and popped from the stack at most once, resulting in a total of 2n operations in the worst case, which simplifies to O(n).
* **Expected Auxiliary Space Complexity:** O(n), as we use a stack to store indices. In the worst case (when prices are in increasing order), the stack will contain all n indices.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();
            res[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pointer Backward Scan**

### 💡 Algorithm Steps:

1. For each day, initialize span as 1 (the current day itself).
2. Use a pointer to scan backwards from the previous day.
3. Jump to the previous greater element using previously computed spans.
4. Continue until finding a day with a higher price or reaching the start.

```cpp
class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        span[0] = 1;
        for (int i = 1; i < n; i++) {
            span[i] = 1;
            int j = i - 1;
            while (j >= 0 && arr[j] <= arr[i]) {
                span[i] += span[j];
                j -= span[j];
            }
        }
        return span;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each element processed once with efficient jumps
* **Auxiliary Space:** 💾 O(1) - Only result array, no extra structures

### ✅ **Why This Approach?**

* No stack overhead for memory management
* Efficient jumping using previously computed spans
* Good cache locality with backward traversal

## 📊 **3️⃣ Brute Force Nested Loop**

### 💡 Algorithm Steps:

1. For each day, start counting consecutive days backward.
2. Continue counting while the previous day's price is less than or equal to current.
3. Stop when a higher price is found or array start is reached.
4. Store the count as span for current day.

```cpp
class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n);
        for (int i = 0; i < n; i++) {
            span[i] = 1;
            for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--) 
                span[i]++;
        }
        return span;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested loops checking all previous elements
* **Auxiliary Space:** 💾 O(1) - Constant extra space

### ✅ **Why This Approach?**

* Simplest logic with straightforward implementation
* No additional data structures needed
* Best for very small input sizes

> **Note:** This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1115 test cases due to time constraints).

## 📊 **4️⃣ Dynamic Programming with Memoization**

### 💡 Algorithm Steps:

1. Store the index of the nearest greater element for each position.
2. Use memoization to avoid recalculating spans.
3. For each element, use the nearest greater index to compute span.
4. Build solution incrementally using previous results.

```cpp
class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> span(n), nge(n, -1);
        for (int i = 0; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && arr[j] <= arr[i]) j = nge[j];
            nge[i] = j;
            span[i] = i - j;
        }
        return span;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal with memoized jumps
* **Auxiliary Space:** 💾 O(n) - Extra array for nearest greater element

### ✅ **Why This Approach?**

* Efficient jumps using memoization
* Clear separation of concerns with NGE array
* Useful for problems requiring nearest greater element

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Stack-Based**                | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Optimal time, clean code       | 💾 Stack overhead                    |
| 🔍 **Two-Pointer Scan**           | 🟢 O(n)                | 🟢 O(1)                 | 📖 Space efficient                | 🔧 Complex jump logic                |
| 📊 **Brute Force**                | 🔴 O(n²)               | 🟢 O(1)                 | 🎯 Simple to understand           | 🐌 Slow for large inputs             |
| 🔄 **DP Memoization**             | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Educational approach           | 💾 Extra space for NGE array         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Overall best performance**                       | 🥇 **Stack-Based**                   | ★★★★★                     |
| 📖 **Memory constrained**                             | 🥈 **Two-Pointer Scan**              | ★★★★☆                     |
| 🔧 **Small input size**                               | 🥉 **Brute Force**                   | ★★★☆☆                     |
| 🎯 **Learning/Educational**                           | 🏅 **DP Memoization**                | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> calculateSpan(int[] arr) {
        int n = arr.length;
        ArrayList<Integer> res = new ArrayList<>();
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && arr[s.peek()] <= arr[i]) s.pop();
            res.add(s.isEmpty() ? i + 1 : i - s.peek());
            s.push(i);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def calculateSpan(self, arr):
        n = len(arr)
        res = []
        s = []
        for i in range(n):
            while s and arr[s[-1]] <= arr[i]: s.pop()
            res.append(i + 1 if not s else i - s[-1])
            s.append(i)
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
