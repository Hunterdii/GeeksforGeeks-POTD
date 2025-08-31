---
title: "🌊 Container With Most Water | GFG Solution 💧"
keywords🏷️: ["🌊 container water", "🔍 two pointers", "📍 sliding window", "📈 greedy algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Container With Most Water problem: find maximum water area between two vertical lines using optimal two-pointer technique. 🚀"
date: 📅 2025-08-31
---

# *31. Container With Most Water*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/container-with-most-water0535/1)

## **🧩 Problem Description**

Given an array `arr[]` of non-negative integers, where each element `arr[i]` represents the height of vertical lines, find the **maximum amount of water** that can be contained between any two lines, together with the x-axis.

**Note:** In the case of a single vertical line, it will not be able to hold water.

The water area is calculated as: **Area = min(height[i], height[j]) × (j - i)** where i and j are indices of two lines.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 5, 4, 3]
Output: 6
Explanation: Lines at indices 1 and 3 with heights 5 and 3 are 2 distance apart. 
Base = 2, Height = min(5, 3) = 3. Total area = 3 × 2 = 6.
```

### Example 2

```cpp
Input: arr[] = [3, 1, 2, 4, 5]
Output: 12
Explanation: Lines at indices 0 and 4 with heights 3 and 5 are 4 distance apart.
Base = 4, Height = min(3, 5) = 3. Total area = 3 × 4 = 12.
```

### Example 3

```cpp
Input: arr[] = [2, 1, 8, 6, 4, 6, 5, 5]
Output: 25
Explanation: Lines at indices 2 and 7 with heights 8 and 5 are 5 distance apart.
Base = 5, Height = min(8, 5) = 5. Total area = 5 × 5 = 25.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses the **Two Pointers** technique with a **Greedy Strategy** to efficiently find the maximum water area:

### **Two Pointers + Greedy Algorithm**

1. **Initialize Pointers:**
   * Use two pointers: `left` at start (0) and `right` at end (n-1).
   * Initialize `maxArea` to track the maximum water area found.

2. **Calculate Current Area:**
   * For current pointers, calculate area = `min(h[left], h[right]) × (right - left)`.
   * Update `maxArea` if current area is larger.

3. **Greedy Pointer Movement:**
   * Move the pointer with the **smaller height** inward.
   * **Why?** Moving the pointer with larger height would only decrease the width while keeping the limiting height same or smaller, never improving the area.

4. **Convergence:**
   * Continue until `left >= right`.
   * The algorithm guarantees we won't miss the optimal solution due to the greedy property.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is visited at most once as we use two pointers moving towards each other.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like pointers and maxArea.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxWater(vector<int>& h) {
        int l = 0, r = h.size() - 1, ans = 0;
        while (l < r) {
            ans = max(ans, min(h[l], h[r]) * (r - l));
            h[l] < h[r] ? ++l : --r;
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized Pointer Movement**

### 💡 Algorithm Steps:

1. Use two pointers approach but optimize pointer movement logic.
2. Pre-calculate area only when we might find a better solution.
3. Skip unnecessary calculations by comparing heights first.
4. Move the pointer with smaller height to potentially find larger area.

```cpp
class Solution {
public:
    int maxWater(vector<int>& h) {
        int l = 0, r = h.size() - 1, maxArea = 0;
        while (l < r) {
            int width = r - l;
            if (h[l] < h[r]) {
                maxArea = max(maxArea, h[l] * width);
                ++l;
            } else {
                maxArea = max(maxArea, h[r] * width);
                --r;
            }
        }
        return maxArea;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through array
* **Auxiliary Space:** 💾 O(1) - Only constant variables

### ✅ **Why This Approach?**

* Slightly more readable with explicit height selection
* Avoids redundant min() calculations
* Better for understanding the logic flow

## 📊 **3️⃣ Bit Manipulation Optimization**

### 💡 Algorithm Steps:

1. Use bit operations for faster comparisons where possible.
2. Combine multiple operations into single expressions.
3. Utilize compiler optimizations through simpler arithmetic.
4. Minimize function calls and temporary variables.

```cpp
class Solution {
public:
    int maxWater(vector<int>& h) {
        int l = 0, r = h.size() - 1, area = 0;
        while (l < r) {
            area = max(area, (r - l) * (h[l] < h[r] ? h[l++] : h[r--]));
        }
        return area;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time with optimized operations
* **Auxiliary Space:** 💾 O(1) - Minimal variable usage

### ✅ **Why This Approach?**

* Most compact and optimized code
* Combines increment/decrement with ternary operator
* Minimal memory footprint and operations

## 📊 **4️⃣ Early Termination Optimization**

### 💡 Algorithm Steps:

1. Track the maximum possible area that can be achieved.
2. If current width × max_height cannot exceed current maxArea, terminate early.
3. Use preprocessing to find maximum height for optimization.
4. Skip iterations that cannot improve the result.

```cpp
class Solution {
public:
    int maxWater(vector<int>& h) {
        int n = h.size();
        int maxHeight = *max_element(h.begin(), h.end());
        int l = 0, r = n - 1, maxArea = 0;
        while (l < r) {
            int currentArea = min(h[l], h[r]) * (r - l);
            maxArea = max(maxArea, currentArea);
            if ((r - l - 1) * maxHeight <= maxArea) break;
            
            h[l] < h[r] ? ++l : --r;
        }
        return maxArea;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear with early termination potential
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Potential for early termination in favorable cases
* Maintains optimal complexity while adding optimization
* Good for large datasets with specific patterns


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Standard Two Pointer**       | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal and clean             | 🔧 Requires understanding greedy logic|
| 🔍 **Optimized Movement**          | 🟢 O(n)                | 🟢 O(1)                 | 📖 Better readability            | 💾 Slightly more operations           |
| 🔄 **Bit Manipulation**           | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Most compact                   | 🔧 Less readable for beginners       |
| ⚡ **Early Termination**          | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Potential speedup             | 💾 Extra preprocessing overhead       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production code, interviews**               | 🥇 **Standard Two Pointer**          | ★★★★★                     |
| 📖 **Learning purposes**                          | 🥈 **Optimized Movement**            | ★★★★☆                     |
| 🔧 **Competitive programming**                    | 🥉 **Bit Manipulation**              | ★★★★★                     |
| 🎯 **Large datasets with patterns**               | 🎖️ **Early Termination**             | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxWater(int[] h) {
        int l = 0, r = h.length - 1, max = 0;
        while (l < r) {
            max = Math.max(max, Math.min(h[l], h[r]) * (r - l));
            if (h[l] < h[r]) l++; else r--;
        }
        return max;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxWater(self, h):
        l, r, ans = 0, len(h) - 1, 0
        while l < r:
            ans = max(ans, min(h[l], h[r]) * (r - l))
            l, r = (l + 1, r) if h[l] < h[r] else (l, r - 1)
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
