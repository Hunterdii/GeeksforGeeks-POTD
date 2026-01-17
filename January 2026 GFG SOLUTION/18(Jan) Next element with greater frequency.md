---
title: "🔢 Next Element with Greater Frequency | GFG Solution 🔍"
keywords🏷️: ["🔢 next greater frequency", "📚 stack", "📈 monotonic stack", "🗺️ hash map", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to find the next element with greater frequency using stack-based approach with frequency mapping for optimal performance. 🚀"
date: 📅 2025-01-18
---

# *18. Next Element with Greater Frequency*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1)

## **🧩 Problem Description**

Given an array `arr[]` of integers, for each element, find the first element to its right that has a higher frequency than the current element. If no such element exists, return `-1` for that position.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 1, 1, 3, 2, 1]
Output: [1, -1, -1, 2, 1, -1]
Explanation: Frequencies: 1 → 3 times, 2 → 2 times, 3 → 1 time.
For arr[0] = 2, the next element 1 has a higher frequency → 1.
For arr[1] and arr[2], no element to the right has a higher frequency → -1.
For arr[3] = 3, the next element 2 has a higher frequency → 2.
For arr[4] = 2, the next element 1 has a higher frequency → 1.
For arr[5] = 1, no elements to the right → -1.
```

### Example 2

```cpp
Input: arr[] = [5, 1, 5, 6, 6]
Output: [-1, 5, -1, -1, -1]
Explanation: Frequencies: 1 → 1 time, 5 → 2 times, 6 → 2 times.
For arr[0] and arr[2], no element to the right has a higher frequency → -1.
For arr[1] = 1, the next element 5 has a higher frequency → 5.
For arr[3] and arr[4], no element to the right has a higher frequency → -1.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach combines **Frequency Mapping** with a **Monotonic Stack** technique to efficiently find the next greater frequency element:

### **Frequency Map + Monotonic Stack (Backward Traversal)**

1. **Build Frequency Map:**
   * Traverse the entire array once to count frequency of each element.
   * Store frequencies in an unordered map for O(1) lookup.

2. **Initialize Result and Stack:**
   * Create result vector initialized with -1 for all positions.
   * Use stack to store indices in decreasing order of their frequencies.

3. **Backward Traversal:**
   * Traverse array from right to left (n-1 to 0).
   * For current index i, compare frequency of arr[i] with stack top frequencies.

4. **Stack Maintenance:**
   * Pop indices from stack while their frequency is less than or equal to current element's frequency.
   * If stack is not empty after popping, the top index gives the answer.
   * Push current index onto stack for future comparisons.

5. **Result Construction:**
   * When a valid next greater frequency element is found, store its value in result array.
   * Otherwise, -1 remains as the default value.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. The frequency map is built in O(n) time. Each element is pushed and popped from the stack at most once during the backward traversal, resulting in O(n) operations overall.
* **Expected Auxiliary Space Complexity:** O(n), as we use a hash map to store frequencies of up to n distinct elements, a stack that can hold up to n indices in the worst case, and a result vector of size n.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) st.pop();
            if (!st.empty()) res[i] = arr[st.top()];
            st.push(i);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Forward Traversal Stack**

### 💡 Algorithm Steps:

1. Build frequency map for all elements in the array.
2. Traverse array from left to right using stack to track indices.
3. For each element check if its frequency is greater than stack top frequency.
4. Pop stack and assign current element as next greater frequency element.

```cpp
class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res(arr.size(), -1);
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && freq[arr[i]] > freq[arr[st.top()]]) {
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with stack operations
* **Auxiliary Space:** 💾 O(n) - Stack and frequency map storage

### ✅ **Why This Approach?**

* Natural left to right processing
* Clear monotonic stack pattern
* Easy to understand and debug

## 📊 **3️⃣ Pair-Based Stack Tracking**

### 💡 Algorithm Steps:

1. Create frequency map and store element-frequency pairs in stack.
2. Process array from right to left maintaining decreasing frequency order.
3. Pop all elements with frequency less than or equal to current element.
4. Top of stack gives next greater frequency element for current position.

```cpp
class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res(arr.size(), -1);
        stack<pair<int, int>> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top().second <= freq[arr[i]]) st.pop();
            if (!st.empty()) res[i] = st.top().first;
            st.push({arr[i], freq[arr[i]]});
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time traversal
* **Auxiliary Space:** 💾 O(n) - Stack with pairs and map

### ✅ **Why This Approach?**

* Stores both element and frequency together
* Avoids repeated map lookups during comparison
* More cache-friendly for large datasets

## 📊 **4️⃣ Optimized Map Lookup**

### 💡 Algorithm Steps:

1. Precompute frequencies and store in map for quick access.
2. Use stack to maintain indices in order of processing.
3. Compare frequencies directly using array indices stored in stack.
4. Update result array when greater frequency element is found.

```cpp
class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && freq[arr[st.top()]] < freq[arr[i]]) {
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each element processed once
* **Auxiliary Space:** 💾 O(n) - Stack and map storage

### ✅ **Why This Approach?**

* Minimal code with optimal performance
* Standard monotonic stack implementation
* Efficient for competitive programming

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Backward Traversal**         | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Right to left intuition        | 🔧 Less common pattern                |
| 🔍 **Forward Traversal**          | 🟢 O(n)                | 🟡 O(n)                 | 📖 Standard stack approach        | 💾 Same space as others               |
| 📊 **Pair-Based Stack**           | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Reduces map lookups            | 🐌 Extra pair storage overhead        |
| 🔄 **Optimized Lookup**           | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Clean minimal code             | 🔧 Similar to forward traversal       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Backward Traversal**            | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Forward Traversal**             | ★★★★★                     |
| 🔧 **Cache optimization**                             | 🥉 **Pair-Based Stack**              | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Optimized Lookup**              | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> nextFreqGreater(int[] arr) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int x : arr) freq.put(x, freq.getOrDefault(x, 0) + 1);
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) res.add(-1);
        Stack<Integer> st = new Stack<>();
        for (int i = arr.length - 1; i >= 0; i--) {
            while (!st.isEmpty() && freq.get(arr[st.peek()]) <= freq.get(arr[i])) st.pop();
            if (!st.isEmpty()) res.set(i, arr[st.peek()]);
            st.push(i);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def nextFreqGreater(self, arr):
        freq = {}
        for x in arr: freq[x] = freq.get(x, 0) + 1
        res = [-1] * len(arr)
        st = []
        for i in range(len(arr) - 1, -1, -1):
            while st and freq[arr[st[-1]]] <= freq[arr[i]]: st.pop()
            if st: res[i] = arr[st[-1]]
            st.append(i)
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
