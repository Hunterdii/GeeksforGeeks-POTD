---
title: "🚓 Police and Thieves | GFG Solution 🔍"
keywords🏷️: ["🚓 police and thieves", "🔍 two pointers", "📍 greedy", "📈 arrays", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution for the Police and Thieves problem using an optimized two pointers greedy approach to maximize caught thieves. 🚀"
date: 📅 2025-01-14
---


# *14. Police and Thieves*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1)

## **🧩 Problem Description**

Given an array `arr[]`, where each element contains either a **'P' for policeman** or a **'T' for thief**. Find the maximum number of thieves that can be caught by the police.

Keep in mind the following conditions:
- Each policeman can catch only one thief.
- A policeman cannot catch a thief who is more than **k units** away from him.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = ['P', 'T', 'T', 'P', 'T'], k = 1
Output: 2
Explanation: Maximum 2 thieves can be caught. First policeman catches first thief and second 
policeman can catch either second or third thief.
```

### Example 2

```cpp
Input: arr[] = ['T', 'T', 'P', 'P', 'T', 'P'], k = 2
Output: 3
Explanation: Maximum 3 thieves can be caught.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le k \le 1000$
* $\text{arr}[i] = \text{'P'}$ or $\text{'T'}$

## **✅ My Approach**

The optimal approach uses the **Two Pointers** technique to efficiently match police and thieves within the allowed distance:

### **Two Pointers Strategy**

1. **Initialize Pointers:**
   * Use two pointers: `p` for tracking policemen positions and `t` for tracking thief positions.
   * Both pointers start at index 0.
   * Maintain a counter `cnt` to track successful catches.

2. **Find Next Available Positions:**
   * Advance pointer `p` until it finds a policeman ('P').
   * Advance pointer `t` until it finds a thief ('T').

3. **Check Matching Condition:**
   * If both pointers are valid (within bounds) and the distance between them is ≤ k:
     - Increment the catch counter.
     - Move both pointers forward (match made).
   * If thief is before policeman but out of range, advance thief pointer.
   * If policeman is before thief but out of range, advance policeman pointer.

4. **Continue Until Exhausted:**
   * Repeat until either all police or all thieves have been processed.
   * Return the total count of successful catches.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is visited at most once by either the police pointer or the thief pointer, resulting in a linear scan through the array.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the pointers and counter variables, regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size(), p = 0, t = 0, cnt = 0;
        while (p < n && t < n) {
            while (p < n && arr[p] != 'P') p++;
            while (t < n && arr[t] != 'T') t++;
            if (p < n && t < n && abs(p - t) <= k) {
                cnt++;
                p++;
                t++;
            } else if (t < n && t < p) t++;
            else if (p < n && p < t) p++;
        }
        return cnt;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Separate Lists Approach**

### 💡 Algorithm Steps:

1. Store all police and thief positions in separate lists.
2. Use two pointers on both lists to find matching pairs.
3. Match each policeman with closest thief within distance k.
4. Advance pointers intelligently based on distance criteria.

```cpp
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        vector<int> p, t;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') p.push_back(i);
            else t.push_back(i);
        }
        int i = 0, j = 0, cnt = 0;
        while (i < p.size() && j < t.size()) {
            if (abs(p[i] - t[j]) <= k) {
                cnt++;
                i++;
                j++;
            } else if (p[i] < t[j]) i++;
            else j++;
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear scan plus linear matching
* **Auxiliary Space:** 💾 O(n) - Additional space for position lists

### ✅ **Why This Approach?**

* Clear separation of concerns with distinct lists
* Easy to understand matching logic
* Good for interview explanations

## 📊 **3️⃣ Queue-Based Approach**

### 💡 Algorithm Steps:

1. Use queues to store positions of police and thieves.
2. Process pairs from front of queues sequentially.
3. Match based on distance constraint k.
4. Remove matched pairs and advance appropriately.

```cpp
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        queue<int> tp, tt;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') tp.push(i);
            else tt.push(i);
        }
        int cnt = 0;
        while (!tp.empty() && !tt.empty()) {
            if (abs(tp.front() - tt.front()) <= k) {
                cnt++;
                tp.pop();
                tt.pop();
            } else if (tp.front() < tt.front()) tp.pop();
            else tt.pop();
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear processing with queue operations
* **Auxiliary Space:** 💾 O(n) - Queue storage for positions

### ✅ **Why This Approach?**

* Queue naturally maintains order for sequential matching
* Simple logic for processing pairs
* Useful pattern for similar problems

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Two Pointers**               | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal time & space           | 🔧 Requires careful pointer logic    |
| 📊 **Separate Lists**              | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear and readable             | 💾 Extra space needed                |
| 🔄 **Queue-Based**                 | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Natural FIFO processing         | 💾 Additional queue overhead         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Two Pointers**                  | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Separate Lists**                | ★★★★☆                     |
| 🔧 **Sequential processing**                          | 🥉 **Queue-Based**                   | ★★★★☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int catchThieves(char[] arr, int k) {
        int n = arr.length, p = 0, t = 0, cnt = 0;
        while (p < n && t < n) {
            while (p < n && arr[p] != 'P') p++;
            while (t < n && arr[t] != 'T') t++;
            if (p < n && t < n && Math.abs(p - t) <= k) {
                cnt++;
                p++;
                t++;
            } else if (t < n && t < p) t++;
            else if (p < n && p < t) p++;
        }
        return cnt;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def catchThieves(self, arr, k):
        n, p, t, cnt = len(arr), 0, 0, 0
        while p < n and t < n:
            while p < n and arr[p] != 'P': p += 1
            while t < n and arr[t] != 'T': t += 1
            if p < n and t < n and abs(p - t) <= k:
                cnt += 1
                p += 1
                t += 1
            elif t < n and t < p: t += 1
            elif p < n and p < t: p += 1
        return cnt
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
