---
title: "🐜 Last Moment Before All Ants Fall Out | GFG Solution 🚀"
keywords🏷️: ["🐜 ants problem", "🎯 simulation", "📐 physics", "⚡ optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Last Moment Before All Ants Fall Out problem: find when the last ant falls off the plank using optimal physics-based approach. 🚀"
date: 📅 2025-07-24
---

# *24. Last Moment Before All Ants Fall Out*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/last-moment-before-all-ants-fall-out-of-a-plank/1)

## **🧩 Problem Description**

You are given a wooden plank of length `n` units. Some ants are walking on the plank, some are walking left and some are walking right. Each ant moves with speed 1 unit per second.

When two ants moving in opposite directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time. When an ant reaches one end of the plank at time `t`, it falls out of the plank immediately.

Given an integer `n` and two integer arrays `left[]` and `right[]`, representing the positions of ants moving to the left and right respectively, return the time when the last ant(s) fall out of the plank.

## **📘 Examples**

### Example 1

```cpp
Input: n = 4, left[] = [2], right[] = [0, 1, 3]
Output: 4
Explanation: As seen in the problem, the last ant falls off the plank at t = 4.
```

### Example 2

```cpp
Input: n = 4, left[] = [], right[] = [0, 1, 2, 3, 4]
Output: 4
Explanation: All ants are going to the right, the ant at index 0 needs 4 seconds to fall.
```

### Example 3

```cpp
Input: n = 3, left[] = [0], right[] = [3]
Output: 0
Explanation: The ants will fall off the plank as they are already on the end of the plank.
```

## **🔒 Constraints**

* $1 \le n \le 10^5$
* $0 \le \text{left.length, right.length} \le n + 1$
* $0 \le \text{left}[i], \text{right}[i] \le n$
* $1 \le \text{left.length + right.length} \le n + 1$
* All values are unique and each value appears in only one array

## **✅ My Approach**

The key insight is that when two ants collide and change directions, we can think of them as **passing through each other** without changing direction. This is because the system behaves identically - the positions and movements remain the same, only the "identity" of ants changes.

### **Physics-Based Optimization**

1. **Key Insight:**
   * When ants collide, instead of tracking direction changes, we can imagine they pass through each other.
   * The time for the last ant to fall is simply the maximum time any ant needs to reach either end.

2. **Calculate Time for Each Ant:**
   * For ants moving **left**: Time = current position (distance to left edge = 0)
   * For ants moving **right**: Time = n - current position (distance to right edge = n)

3. **Find Maximum Time:**
   * The answer is the maximum of all individual times.
   * This represents when the last ant will fall off the plank.

4. **Why This Works:**
   * Collisions don't affect the overall system behavior.
   * Each ant will eventually fall off at the same time as if there were no collisions.
   * We only need to find the ant that takes the longest time to reach an edge.

## **📝 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(L + R), where L is the length of left array and R is the length of right array. We iterate through both arrays once to find the maximum values.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for storing the maximum value and loop variables.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int x : left) ans = max(ans, x);
        for (int x : right) ans = max(ans, n - x);
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass Maximum Calculation**

### 💡 Algorithm Steps:

1. Calculate maximum from left array in single iteration
2. Calculate maximum from transformed right array simultaneously
3. Return the overall maximum without intermediate storage

```cpp
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMax = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int rightMax = 0;
        for (int pos : right) rightMax = max(rightMax, n - pos);
        return max(leftMax, rightMax);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(L + R) where L, R are array sizes
* **Auxiliary Space:** 💾 O(1) - constant space

### ✅ **Why This Approach?**

* Uses STL max_element for left array optimization
* Minimal memory allocation
* Clear separation of left and right processing

## 📊 **3️⃣ Range-Based Iterator Approach**

### 💡 Algorithm Steps:

1. Use range-based loops for cleaner syntax
2. Combine both calculations in minimal code
3. Leverage modern C++ features for optimization

```cpp
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for (auto& pos : left) result = max(result, pos);
        for (auto& pos : right) result = max(result, n - pos);
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(L + R)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Modern C++11 syntax
* Reference-based iteration prevents copying
* Compiler-optimized range loops

## 📊 **4️⃣ Branch-Free Computation**

### 💡 Algorithm Steps:

1. Eliminate conditional branches for better CPU performance
2. Use arithmetic operations instead of max function
3. Better CPU pipeline utilization
4. Consistent execution time

```cpp
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for (int i = 0; i < left.size(); ++i) {
            result = result > left[i] ? result : left[i];
        }
        for (int i = 0; i < right.size(); ++i) {
            int val = n - right[i];
            result = result > val ? result : val;
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(L + R) - branch-free execution
* **Auxiliary Space:** 💾 O(1) - constant space

### ✅ **Why This Approach?**

* Eliminates branch mispredictions
* Better CPU cache utilization
* Consistent performance profile

## 📊 **5️⃣ Functional Programming Style**

### 💡 Algorithm Steps:

1. Use STL algorithms for both arrays
2. Combine results using max function
3. Leverage compiler optimizations for STL

```cpp
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMax = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int rightMax = 0;
        if (!right.empty()) {
            vector<int> rightTimes(right.size());
            transform(right.begin(), right.end(), rightTimes.begin(), 
                     [n](int pos) { return n - pos; });
            rightMax = *max_element(rightTimes.begin(), rightTimes.end());
        }
        return max(leftMax, rightMax);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(L + R)
* **Auxiliary Space:** 💾 O(R) - for transformed array

### ✅ **Why This Approach?**

* Functional programming paradigm
* STL algorithm optimization
* Clear separation of concerns

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Basic Two-Loop**             | 🟡 O(L + R)           | 🟢 O(1)                 | 🚀 Simple and direct              | 💾 Basic approach                     |
| 🔺 **Single Pass Maximum**        | 🟡 O(L + R)           | 🟢 O(1)                 | 🔧 STL optimization               | 💾 Slightly more complex             |
| ⏰ **Range-Based Iterator**        | 🟡 O(L + R)           | 🟢 O(1)                 | 🚀 Modern C++ syntax              | 🔄 Compiler dependent optimization   |
| 📊 **Branch-Free Computation**    | 🟡 O(L + R)           | 🟢 O(1)                 | ⚡ Better CPU utilization         | 🔧 More complex logic               |
| 🎯 **Functional Programming**      | 🟡 O(L + R)           | 🟡 O(R)                 | 🔧 Clear functional style         | 💾 Extra space usage                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Competitive Programming**                        | 🥇 **Basic Two-Loop**                | ★★★★★                     |
| 📊 **Production Code**                               | 🥈 **Range-Based Iterator**          | ★★★★☆                     |
| 🎯 **Performance Critical**                          | 🥉 **Branch-Free Computation**       | ★★★★☆                     |
| 🚀 **Interview Settings**                            | 🏅 **Basic Two-Loop**                | ★★★★★                     |
| 🔧 **Learning/Educational**                          | 🎖️ **Single Pass Maximum**          | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int getLastMoment(int n, int left[], int right[]) {
        int ans = 0;
        for (int x : left) ans = Math.max(ans, x);
        for (int x : right) ans = Math.max(ans, n - x);
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def getLastMoment(self, n, left, right):
        ans = 0
        for x in left: ans = max(ans, x)
        for x in right: ans = max(ans, n - x)
        return ans
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
