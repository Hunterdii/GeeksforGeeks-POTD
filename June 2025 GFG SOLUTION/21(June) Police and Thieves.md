---
title: "🚔 Police and Thieves | GFG Solution 👮‍♂️"
keywords🏷️: ["🚔 police thieves", "🎯 two pointers", "🔍 greedy algorithm", "📍 array traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Police and Thieves problem: find maximum number of thieves that can be caught using optimal two-pointer greedy approach. 🚀"
date: 📅 2025-06-21
---

# *21. Police and Thieves*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/police-and-thieves--141631/1)

## **🧩 Problem Description**

Given an array `arr[]`, where each element contains either a **'P'** for policeman or a **'T'** for thief. Find the **maximum number of thieves** that can be caught by the police.

Keep in mind the following conditions:
- Each policeman can catch only **one thief**
- A policeman cannot catch a thief who is more than **k units away** from him

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = ['P', 'T', 'T', 'P', 'T'], k = 1
Output: 2
Explanation: Maximum 2 thieves can be caught. 
First policeman catches first thief and second policeman 
can catch either second or third thief.
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
* $\text{arr}[i] = \text{'P'} \text{ or } \text{'T'}$

## **✅ My Approach**

The optimal approach uses a **Greedy Two-Pointer** technique to maximize the number of catches:

### **Two-Pointer Greedy Algorithm**

1. **Initialize Two Pointers:**
   * `i = 0` (searching for policemen)
   * `j = 0` (searching for thieves)
   * `count = 0` (number of successful catches)

2. **Find Next Valid Pair:**
   * Move pointer `i` to find the next policeman ('P')
   * Move pointer `j` to find the next thief ('T')

3. **Check Distance Constraint:**
   * If `|i - j| ≤ k`, both can be paired successfully
   * Increment both pointers and increase count
   * Otherwise, move the pointer that points to the earlier position

4. **Greedy Strategy:**
   * Always try to pair the earliest available policeman with the earliest reachable thief
   * This ensures optimal utilization of resources

### **Why This Approach Works:**

- **Greedy Choice:** Pairing the leftmost available policeman with the leftmost reachable thief is always optimal
- **No Backtracking Needed:** Once a pair is formed, we don't need to reconsider previous positions
- **Linear Scan:** Each element is visited at most twice (once by each pointer)

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is processed at most twice by the two pointers, resulting in linear time complexity.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the two pointers and counter variables.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size(), i = 0, j = 0, c = 0;
        while (i < n && j < n) {
            while (i < n && arr[i] != 'P') i++;
            while (j < n && arr[j] != 'T') j++;
            if (i < n && j < n && abs(i - j) <= k) i++, j++, c++;
            else if (j < i) j++;
            else i++;
        }
        return c;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Queue-Based Greedy Approach**

### 💡 Algorithm Steps:

1. Traverse the array and store indices of policemen and thieves in separate queues.
2. Compare the front elements of both queues.
3. If distance is within k, increment count and remove both.
4. Otherwise, remove the element that comes first.

```cpp
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        queue<int> police, thief;
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') police.push(i);
            else if (arr[i] == 'T') thief.push(i);
        }
        while (!police.empty() && !thief.empty()) {
            int p = police.front(), t = thief.front();
            if (abs(p - t) <= k) {
                count++;
                police.pop();
                thief.pop();
            } else if (t < p) thief.pop();
            else police.pop();
        }
        return count;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - For storing indices

### ✅ **Why This Approach?**

* Clear separation of roles using STL containers.
* Easier to debug and understand logic flow.

## 📊 **3️⃣ Vector-Based Greedy with Preprocessing**

### 💡 Algorithm Steps:

1. Store all police and thief positions in separate vectors.
2. Use two pointers on sorted position arrays.
3. Apply greedy matching strategy.

```cpp
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        vector<int> police, thieves;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') police.push_back(i);
            else if (arr[i] == 'T') thieves.push_back(i);
        }
        int i = 0, j = 0, count = 0;
        while (i < police.size() && j < thieves.size()) {
            if (abs(police[i] - thieves[j]) <= k) {
                count++;
                i++;
                j++;
            } else if (police[i] < thieves[j]) {
                i++;
            } else {
                j++;
            }
        }
        return count;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(p + t) where p = police count, t = thief count

### ✅ **Why This Approach?**

* Natural positions are already sorted.
* Clean implementation with vectors.

## 📊 **4️⃣ Binary Search Optimization**

### 💡 Algorithm Steps:

1. Store thief positions in sorted order.
2. For each police, use binary search to find valid range.
3. Greedily select closest available thief.

```cpp
class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        vector<int> thieves;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'T') thieves.push_back(i);
        }
        set<int> available(thieves.begin(), thieves.end());
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 'P') {
                auto it = available.lower_bound(i - k);
                if (it != available.end() && *it <= i + k) {
                    available.erase(it);
                    count++;
                }
            }
        }
        return count;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log t) where t = thief count
* **Auxiliary Space:** 💾 O(t)

### ✅ **Why This Approach?**

* Efficient for sparse thief distribution.
* Uses STL set for automatic sorting and removal.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Two Pointer**                | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Fastest runtime, optimal space | 🧮 Requires careful pointer management |
| 🔄 **Queue-Based Greedy**         | 🟢 O(n)                | 🟡 O(n)                 | 🔧 Clear logic, easy to debug     | 💾 Extra space for queues           |
| 🔺 **Vector-Based Greedy**        | 🟢 O(n)                | 🟡 O(p + t)             | 🚀 Natural sorting, clean code    | 💾 Space proportional to characters |
| 🔍 **Binary Search**              | 🟡 O(n log t)          | 🟡 O(t)                 | ⚡ Efficient for sparse thieves    | 🧮 Complex implementation           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ Maximum performance, competitive programming    | 🥇 **Two Pointer**             | ★★★★★                     |
| 🔧 Production code, readability important         | 🥈 **Queue-Based Greedy**      | ★★★★☆                     |
| 📊 Educational purposes, clear logic               | 🥉 **Vector-Based Greedy**     | ★★★★☆                     |
| 🎯 Sparse data, many thieves                      | 🎖️ **Binary Search**           | ★★★★☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int catchThieves(char[] arr, int k) {
        int i = 0, j = 0, n = arr.length, c = 0;
        while (i < n && j < n) {
            while (i < n && arr[i] != 'P') i++;
            while (j < n && arr[j] != 'T') j++;
            if (i < n && j < n && Math.abs(i - j) <= k) {
                i++; j++; c++;
            } else if (j < i) j++;
            else i++;
        }
        return c;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def catchThieves(self, arr, k):
        i = j = c = 0
        n = len(arr)
        while i < n and j < n:
            while i < n and arr[i] != 'P':
                i += 1
            while j < n and arr[j] != 'T':
                j += 1
            if i < n and j < n and abs(i - j) <= k:
                i += 1
                j += 1
                c += 1
            elif j < i:
                j += 1
            else:
                i += 1
        return c
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
