---
title: "💧 Trapping Rain Water | GFG Solution 🎯"
keywords🏷️: ["💧 rain water", "🔍 two pointers", "📊 prefix suffix", "📈 dynamic programming", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Trapping Rain Water: calculate maximum water trapped between blocks using efficient two-pointer technique. 🚀"
date: 📅 2025-03-02
---

# *02. Trapping Rain Water*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1)

## **🧩 Problem Description**

Given an array `arr[]` with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much **water can be trapped** between the blocks during the rainy season.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [3, 0, 1, 0, 4, 0, 2]
Output: 10
Explanation: Total water trapped = 0 + 3 + 2 + 3 + 0 + 2 + 0 = 10 units.
```

### Example 2

```cpp
Input: arr[] = [3, 0, 2, 0, 4]
Output: 7
Explanation: Total water trapped = 0 + 3 + 1 + 3 + 0 = 7 units.
```

### Example 3

```cpp
Input: arr[] = [1, 2, 3, 4]
Output: 0
Explanation: We cannot trap water as there is no height bound on both sides.
```

### Example 4

```cpp
Input: arr[] = [2, 1, 5, 3, 1, 0, 4]
Output: 9
Explanation: Total water trapped = 0 + 1 + 0 + 1 + 3 + 4 + 0 = 9 units.
```

## **🔒 Constraints**

* $1 < \text{arr.size()} < 10^5$
* $0 < \text{arr}[i] < 10^3$

## **✅ My Approach**

The optimal solution uses **Two-Pointer Technique**:

### **Two-Pointer Strategy**

1. **Key Insight:**
   * Water trapped at any position depends on the minimum of maximum heights on its left and right.
   * Formula: `water[i] = min(leftMax, rightMax) - arr[i]` (if positive).

2. **Two-Pointer Logic:**
   * Start with pointers at both ends: `left = 0`, `right = n-1`.
   * Track `leftMax` and `rightMax` as we move inward.
   * Process the side with smaller height first.

3. **Water Calculation:**
   * If `arr[left] < arr[right]`: water at `left` is determined by `leftMax`.
     - Add `max(0, leftMax - arr[left])` to result.
     - Update `leftMax` and move `left` pointer right.
   * Otherwise: water at `right` is determined by `rightMax`.
     - Add `max(0, rightMax - arr[right])` to result.
     - Update `rightMax` and move `right` pointer left.

4. **Why This Works:**
   * When processing left, we know there exists a taller bar on the right.
   * When processing right, we know there exists a taller bar on the left.
   * This guarantees correct water calculation without needing full left/right max arrays.

**Mathematical Insight:** The smaller of the two boundaries determines how much water can be trapped at any position.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We make a single pass through the array using two pointers that move toward each other, processing each element exactly once.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for pointer variables and tracking maximum heights from both sides.

## **🧑‍💻 Code (C)**

```c
int maxWater(int* arr, int n) {
    int l = 0, r = n - 1, lmax = 0, rmax = 0, res = 0;
    while (l < r) {
        if (arr[l] < arr[r]) {
            lmax = lmax > arr[l] ? lmax : arr[l];
            res += lmax - arr[l++];
        } else {
            rmax = rmax > arr[r] ? rmax : arr[r];
            res += rmax - arr[r--];
        }
    }
    return res;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxWater(vector<int> &arr) {
        int l = 0, r = arr.size() - 1, lmax = 0, rmax = 0, res = 0;
        while (l < r) {
            if (arr[l] < arr[r]) {
                lmax = max(lmax, arr[l]);
                res += lmax - arr[l++];
            } else {
                rmax = max(rmax, arr[r]);
                res += rmax - arr[r--];
            }
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Prefix-Suffix Max Arrays**

### 💡 Algorithm Steps:

1. Compute prefix max array storing maximum height to the left of each position.
2. Compute suffix max array storing maximum height to the right of each position.
3. For each position, water trapped = min(prefixMax, suffixMax) - height.
4. Sum up water for all positions.

```cpp
class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n <= 2) return 0;
        vector<int> lmax(n), rmax(n);
        lmax[0] = arr[0];
        for (int i = 1; i < n; i++)
            lmax[i] = max(lmax[i - 1], arr[i]);
        rmax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rmax[i] = max(rmax[i + 1], arr[i]);
        int res = 0;
        for (int i = 0; i < n; i++)
            res += min(lmax[i], rmax[i]) - arr[i];
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Three linear passes
* **Auxiliary Space:** 💾 O(n) - Two auxiliary arrays

### ✅ **Why This Approach?**

* Intuitive and easy to understand
* Clear visualization of left and right maxima
* Good for explaining the concept

## 📊 **3️⃣ Stack-Based Approach**

### 💡 Algorithm Steps:

1. Use a stack to track indices of bars in decreasing height order.
2. When a taller bar is found, calculate trapped water with previous bars.
3. Water is trapped between current bar and bars in stack.
4. Process each bar once with stack operations.

```cpp
class Solution {
public:
    int maxWater(vector<int> &arr) {
        stack<int> st;
        int res = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int dist = i - st.top() - 1;
                int height = min(arr[i], arr[st.top()]) - arr[top];
                res += dist * height;
            }
            st.push(i);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each element pushed/popped once
* **Auxiliary Space:** 💾 O(n) - Stack storage

### ✅ **Why This Approach?**

* Calculates water layer by layer
* Single pass with stack
* Different perspective on the problem

## 📊 **4️⃣ Dynamic Programming Approach**

### 💡 Algorithm Steps:

1. Use DP to store maximum heights efficiently.
2. Build left max array in forward pass.
3. Process right max and calculate water in single backward pass.
4. Optimize space by reusing input array if modification allowed.

```cpp
class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n <= 2) return 0;
        vector<int> left(n);
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], arr[i]);
        int res = 0, rmax = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax = max(rmax, arr[i]);
            res += min(left[i], rmax) - arr[i];
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two passes through array
* **Auxiliary Space:** 💾 O(n) - Single auxiliary array

### ✅ **Why This Approach?**

* Space optimized compared to prefix-suffix
* Combines computation with water calculation
* Good balance of clarity and efficiency

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Two-Pointer**                | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal space, single pass     | 🔧 Slightly complex logic            |
| 📊 **Prefix-Suffix Arrays**       | 🟢 O(n)                | 🔴 O(n)                 | 📖 Very intuitive                 | 💾 Extra space required              |
| 🔄 **Stack-Based**                | 🟢 O(n)                | 🔴 O(n)                 | 🎯 Layer-by-layer calculation     | 🔧 More complex implementation       |
| 📈 **Dynamic Programming**        | 🟢 O(n)                | 🔴 O(n)                 | ⚡ Space optimized variant        | 💾 Still needs auxiliary space       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Two-Pointer**                   | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥈 **Prefix-Suffix Arrays**          | ★★★★★                     |
| 🎯 **Different perspective**                          | 🥉 **Stack-Based**                   | ★★★★☆                     |
| 💾 **Space optimization**                             | 🏅 **Dynamic Programming**           | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxWater(int arr[]) {
        int l = 0, r = arr.length - 1, lmax = 0, rmax = 0, res = 0;
        while (l < r) {
            if (arr[l] < arr[r]) {
                lmax = Math.max(lmax, arr[l]);
                res += lmax - arr[l++];
            } else {
                rmax = Math.max(rmax, arr[r]);
                res += rmax - arr[r--];
            }
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxWater(self, arr):
        l, r, lmax, rmax, res = 0, len(arr) - 1, 0, 0, 0
        while l < r:
            if arr[l] < arr[r]:
                lmax = max(lmax, arr[l])
                res += lmax - arr[l]
                l += 1
            else:
                rmax = max(rmax, arr[r])
                res += rmax - arr[r]
                r -= 1
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
