---
title: "🏗️ Equalize the Towers | GFG Solution 🎯"
keywords🏷️: ["🏗️ tower equalization", "🔍 binary search", "📈 optimization", "💰 minimum cost", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Equalize the Towers problem: find minimum cost to make all towers same height using binary search optimization. 🚀"
date: 📅 2025-06-16
---

# *16. Equalize the Towers*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1)

## **🧩 Problem Description**

You are given an array `heights[]` representing the heights of towers and another array `cost[]` where each element represents the cost of modifying the height of respective tower.

The goal is to make all towers of same height by either **adding or removing blocks** from each tower. Modifying the height of tower 'i' by 1 unit costs `cost[i]`.

Return the **minimum cost** to equalize the heights of all towers.

## **📘 Examples**

### Example 1

```cpp
Input: heights[] = [1, 2, 3], cost[] = [10, 100, 1000]
Output: 120
Explanation: The heights can be equalized by either "Removing one block from 3 and adding one in 1" or "Adding two blocks in 1 and adding one in 2". Since the cost of operation in tower 3 is 1000, the first process would yield 1010 while the second one yields 120.
```

### Example 2

```cpp
Input: heights[] = [7, 1, 5], cost[] = [1, 1, 1]
Output: 6
Explanation: The minimum cost to equalize the towers is 6, achieved by setting all towers to height 5.
```

## **🔒 Constraints**

* $1 \le \text{heights.size()} = \text{cost.size()} \le 10^5$
* $1 \le \text{heights}[i] \le 10^4$
* $1 \le \text{cost}[i] \le 10^3$

## **✅ My Approach**

The optimal approach uses **Binary Search on Answer** to find the target height that minimizes the total cost:

### **Binary Search on Target Height**

1. **Search Space Setup:**
   * The optimal target height lies between 0 and maximum height in the array.
   * We need to find the height that minimizes the total cost function.

2. **Cost Function Analysis:**
   * For any target height `h`, cost = Σ|heights[i] - h| × cost[i]
   * This creates a unimodal function (convex) with a single minimum.

3. **Binary Search Implementation:**
   * Compare costs at adjacent heights `m` and `m+1`.
   * If cost at `m` ≤ cost at `m+1`, optimal height is in left half (including m).
   * Otherwise, optimal height is in right half.

4. **Final Calculation:**
   * Once we find the optimal height, calculate the actual minimum cost.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × log(max_height)), where n is the number of towers and max_height is the maximum height in the array. Binary search takes O(log(max_height)) iterations, and each iteration requires O(n) time to calculate the cost.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for variables and calculations (excluding the input arrays).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int l = 0, h = *max_element(heights.begin(), heights.end());
        while (l < h) {
            int m = l + (h - l) / 2;
            long long c1 = 0, c2 = 0;
            for (int i = 0; i < heights.size(); ++i) {
                c1 += (long long)abs(heights[i] - m) * cost[i];
                c2 += (long long)abs(heights[i] - m - 1) * cost[i];
            }
            c1 <= c2 ? h = m : l = m + 1;
        }
        long long ans = 0;
        for (int i = 0; i < heights.size(); ++i)
            ans += (long long)abs(heights[i] - l) * cost[i];
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Ternary Search Approach**

### 💡 Algorithm Steps:

1. Use ternary search to find optimal height.
2. Compare costs at two mid points.
3. Eliminate one-third of search space each iteration.

```cpp
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int l = 0, h = *max_element(heights.begin(), heights.end());
        while (h - l > 2) {
            int m1 = l + (h - l) / 3, m2 = h - (h - l) / 3;
            long long c1 = 0, c2 = 0;
            for (int i = 0; i < heights.size(); ++i) {
                c1 += (long long)abs(heights[i] - m1) * cost[i];
                c2 += (long long)abs(heights[i] - m2) * cost[i];
            }
            c1 <= c2 ? h = m2 : l = m1;
        }
        long long ans = LLONG_MAX;
        for (int i = l; i <= h; ++i) {
            long long c = 0;
            for (int j = 0; j < heights.size(); ++j)
                c += (long long)abs(heights[j] - i) * cost[j];
            ans = min(ans, c);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × log₃(max_height))
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Faster theoretical convergence than binary search.
* Reduces search space by 1/3 each iteration.

## 📊 **3️⃣ Weighted Median Approach**

### 💡 Algorithm Steps:

1. Sort heights with their costs.
2. Find weighted median based on cumulative costs.
3. Direct calculation without search.

```cpp
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        vector<pair<int, int>> hc;
        long long total = 0;
        for (int i = 0; i < heights.size(); ++i) {
            hc.push_back({heights[i], cost[i]});
            total += cost[i];
        }
        sort(hc.begin(), hc.end());
        
        long long sum = 0, ans = 0;
        for (auto& p : hc) {
            sum += p.second;
            if (sum >= (total + 1) / 2) {
                for (int i = 0; i < heights.size(); ++i)
                    ans += (long long)abs(heights[i] - p.first) * cost[i];
                return ans;
            }
        }
        return 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Mathematically optimal solution.
* No iterative search required.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**           | ⏱️ **Time Complexity**           | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ------------------------- | -------------------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Binary Search**      | 🟢 O(n × log(max_height))        | 🟢 O(1)                 | ⚡ Fastest runtime, minimal ops    | 🧮 Requires understanding of convexity|
| 🔺 **Ternary Search**     | 🟢 O(n × log₃(max_height))       | 🟢 O(1)                 | 🚀 Faster theoretical convergence  | 🧮 More complex per iteration        |
| 📊 **Weighted Median**    | 🟡 O(n log n)                    | 🔸 O(n)                 | 🎯 Mathematically optimal          | 💾 Extra space, sorting overhead     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ Maximum performance, competitive programming    | 🥇 **Binary Search**            | ★★★★★                     |
| 🚀 Theoretical optimization                        | 🥈 **Ternary Search**           | ★★★★☆                     |
| 🎯 Mathematically guaranteed optimal               | 🥉 **Weighted Median**          | ★★★★☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int minCost(int[] heights, int[] cost) {
        int l = 0, h = Arrays.stream(heights).max().getAsInt();
        while (l < h) {
            int m = l + (h - l) / 2;
            long c1 = 0, c2 = 0;
            for (int i = 0; i < heights.length; ++i) {
                c1 += (long)Math.abs(heights[i] - m) * cost[i];
                c2 += (long)Math.abs(heights[i] - m - 1) * cost[i];
            }
            if (c1 <= c2) h = m;
            else l = m + 1;
        }
        long ans = 0;
        for (int i = 0; i < heights.length; ++i)
            ans += (long)Math.abs(heights[i] - l) * cost[i];
        return (int)ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minCost(self, heights, cost):
        l, h = 0, max(heights)
        while l < h:
            m = l + (h - l) // 2
            c1 = sum(abs(heights[i] - m) * cost[i] for i in range(len(heights)))
            c2 = sum(abs(heights[i] - m - 1) * cost[i] for i in range(len(heights)))
            if c1 <= c2:
                h = m
            else:
                l = m + 1
        return sum(abs(heights[i] - l) * cost[i] for i in range(len(heights)))
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
