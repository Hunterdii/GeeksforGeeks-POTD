---
title: "🧺 Next Element with Greater Frequency | GFG Solution 🔍"
keywords🏷️: ["🧺 next greater element", "🔍 monotonic stack", "📍 frequency analysis", "📈 hash map", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Next Element with Greater Frequency problem: find the closest element to the right with higher frequency using monotonic stack technique. 🚀"
date: 📅 2025-07-08
---

# *08. Next Element with Greater Frequency*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/next-element-with-greater-frequency--170637/1)

## **🧩 Problem Description**

Given an array `arr[]` of integers, for each element, find the **closest** (distance wise) to its right that has a **higher frequency** than the current element. If no such element exists, return **-1** for that position.

The goal is to efficiently find the next element with greater frequency for each position in the array while maintaining optimal time and space complexity.

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

The optimal approach uses a **Monotonic Stack** combined with **Frequency Mapping** to efficiently find the next element with greater frequency:

### **Forward Stack + Map**

1. **Pre-compute Frequencies:**
   * Build a frequency map to store count of each element in the array.
   * This allows O(1) frequency lookup for any element.

2. **Initialize Data Structures:**
   * Use a stack to maintain indices of elements in decreasing order of their frequencies.
   * Initialize result array with -1 values.

3. **Process Elements Left to Right:**
   * For each element at index `i`, compare its frequency with elements in the stack.
   * While stack is not empty and current element's frequency > frequency of element at stack top:
     * Pop the index from stack and set result[popped_index] = current_element.
   * Push current index onto stack.

4. **Stack Invariant:**
   * Stack maintains indices in decreasing order of frequencies.
   * When we find an element with higher frequency, it becomes the answer for all elements in stack with lower frequencies.

5. **Final Result:**
   * Elements remaining in stack have no next greater frequency element (already -1 in result).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is pushed and popped from the stack at most once, and frequency lookup is O(1).
* **Expected Auxiliary Space Complexity:** O(n), where n is the size of the array. We use O(n) space for the frequency map, O(n) for the stack in worst case, and O(n) for the result array.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> findGreater(vector<int>& a) {
        unordered_map<int, int> f;
        for (int x : a) f[x]++;
        vector<int> r(a.size(), -1);
        stack<int> s;
        for (int i = 0; i < a.size(); i++) {
            while (!s.empty() && f[a[i]] > f[a[s.top()]]) {
                r[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
        return r;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Reverse Traversal Approach**

### 💡 Algorithm Steps:

1. Traverse array from right to left
2. Maintain stack of elements with their frequencies
3. For each element, pop smaller frequencies
4. Find next greater frequency element directly

```cpp
class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res(n, -1);
        stack<pair<int, int>> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top().second <= freq[arr[i]]) {
                s.pop();
            }
            if (!s.empty()) res[i] = s.top().first;
            s.push({arr[i], freq[arr[i]]});
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - for stack and frequency map

### ✅ **Why This Approach?**

* Direct computation of next greater element
* Cleaner logic for finding next element
* Better intuition for stack-based problems

## 📊 **3️⃣ Frequency Array Optimization**

### 💡 Algorithm Steps:

1. Use array for frequency when value range is small
2. Avoid hash map overhead for better performance
3. Maintain monotonic stack of indices
4. Process elements left to right

```cpp
class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<int> freq(maxVal - minVal + 1, 0);
        for (int x : arr) freq[x - minVal]++;
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && freq[arr[i] - minVal] > freq[arr[s.top()] - minVal]) {
                res[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(max - min) - for frequency array

### ✅ **Why This Approach?**

* Faster array access than hash map
* Better cache locality
* Optimal for constrained value ranges

## 📊 **4️⃣ Deque-based Sliding Window**

### 💡 Algorithm Steps:

1. Use deque to maintain elements in frequency order
2. Slide through array maintaining frequency invariant
3. Quick access to next greater frequency element
4. Efficient for specific input patterns

```cpp
class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res(n, -1);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && freq[arr[i]] > freq[arr[dq.back()]]) {
                res[dq.back()] = arr[i];
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - for deque and frequency map

### ✅ **Why This Approach?**

* Deque provides more flexibility than stack
* Can access both ends efficiently
* Alternative data structure approach

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Forward Stack + Map**     | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Standard monotonic stack       | 💾 Hash map overhead                 |
| 🔺 **Reverse Stack Traversal**     | 🟢 O(n)                | 🟡 O(n)                 | 🔧 Direct next element finding    | 💾 Stack stores value-frequency pairs |
| ⏰ **Frequency Array**             | 🟢 O(n)                | 🟡 O(range)             | 🚀 Fastest access, cache friendly | 🔄 Limited to small value ranges      |
| 📊 **Deque-based Approach**        | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Flexible data structure        | 🔧 Slight overhead vs stack           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **General purpose, all inputs**                 | 🥇 **Forward Stack + Map**       | ★★★★★                     |
| 📊 **Small value range (≤ 10⁵)**                  | 🥈 **Frequency Array**               | ★★★★☆                     |
| 🎯 **Educational, easier to understand**          | 🥉 **Reverse Stack Traversal**       | ★★★★☆                     |
| 🚀 **Competitive programming**                    | 🏅 **Forward Stack Traversal**       | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public ArrayList<Integer> findGreater(int[] a) {
        HashMap<Integer, Integer> f = new HashMap<>();
        for (int x : a) f.put(x, f.getOrDefault(x, 0) + 1);
        ArrayList<Integer> r = new ArrayList<>(Collections.nCopies(a.length, -1));
        Deque<Integer> s = new ArrayDeque<>();
        for (int i = 0; i < a.length; i++) {
            while (!s.isEmpty() && f.get(a[i]) > f.get(a[s.peekLast()]))
                r.set(s.pollLast(), a[i]);
            s.add(i);
        }
        return r;
    }
}
```

## **🐍 Code (Python)**

```python
from collections import Counter
class Solution:
    def findGreater(self, a):
        f = Counter(a)
        r, s = [-1]*len(a), []
        for i, v in enumerate(a):
            while s and f[v] > f[a[s[-1]]]:
                r[s.pop()] = v
            s.append(i)
        return r
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













