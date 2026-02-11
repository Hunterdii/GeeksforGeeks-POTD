---
title: "🏗️ Equalize the Towers | GFG Solution 🔍"
keywords🏷️: ["🏗️ tower equalization", "🔍 weighted median", "📍 optimization", "📈 sorting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Equalize the Towers problem: find minimum cost to make all towers equal height using weighted median optimization technique. 🚀"
date: 📅 2025-02-11
---

# *11. Equalize the Towers*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/equalize-the-towers2804/1)

## **🧩 Problem Description**

You are given an array `heights[]` representing the heights of towers and another array `cost[]` where each element represents the cost of modifying the height of respective tower.

The goal is to make all towers of same height by either adding or removing blocks from each tower. Modifying the height of tower 'i' by 1 unit (add or remove) costs `cost[i]`. Return the **minimum cost** to equalize the heights of all the towers.

## **📘 Examples**

### Example 1

```cpp
Input: heights[] = [1, 2, 3], cost[] = [10, 100, 1000]
Output: 120
Explanation: The heights can be equalized by either "Removing one block from 3 and adding one in 1" 
or "Adding two blocks in 1 and adding one in 2". Since the cost of operation in tower 3 is 1000, 
the first process would yield 1010 while the second one yields 120.
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

The optimal approach uses the **Weighted Median** technique to find the target height that minimizes the total cost:

### **Weighted Median Optimization**

1. **Create Height-Cost Pairs:**
   * Combine heights and costs into pairs `(height, cost)`.
   * Sort these pairs by height in ascending order.

2. **Find Weighted Median:**
   * Calculate total sum of all costs.
   * Traverse sorted pairs and accumulate costs.
   * When accumulated cost reaches or exceeds half of total cost `(total + 1) / 2`, that height is the optimal target.

3. **Calculate Minimum Cost:**
   * For the target height found, calculate the total cost.
   * Sum up `|heights[i] - target| * cost[i]` for all towers.
   * This gives the minimum cost to equalize all towers to the target height.

4. **Mathematical Intuition:**
   * The weighted median minimizes the sum of weighted absolute deviations.
   * It balances the cost on both sides, ensuring optimal distribution.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the number of towers. The sorting step dominates the complexity, followed by a linear scan to find the weighted median and calculate the final cost.
* **Expected Auxiliary Space Complexity:** O(n), as we create additional space for storing height-cost pairs in the sorted array. This space is necessary for maintaining the pairing during sorting.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {heights[i], cost[i]};
        sort(v.begin(), v.end());
        long long total = 0;
        for (int x : cost) total += x;
        long long sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i].second;
            if (sum >= (total + 1) / 2) {
                for (int j = 0; j < n; j++) res += (long long)abs(heights[j] - v[i].first) * cost[j];
                return res;
            }
        }
        return 0;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Ternary Search Approach**

### 💡 Algorithm Steps:

1. Define search range as minimum to maximum height in array.
2. Divide range into three parts using mid1 and mid2 points.
3. Calculate total cost at both midpoints using cost function.
4. Eliminate one-third of search space based on cost comparison.
5. Continue until convergence to find optimal height.

```cpp
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int lo = *min_element(heights.begin(), heights.end());
        int hi = *max_element(heights.begin(), heights.end());
        long long res = LLONG_MAX;
        while (lo <= hi) {
            int m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3;
            long long c1 = 0, c2 = 0;
            for (int i = 0; i < heights.size(); i++) {
                c1 += (long long)abs(heights[i] - m1) * cost[i];
                c2 += (long long)abs(heights[i] - m2) * cost[i];
            }
            res = min({res, c1, c2});
            if (c1 < c2) hi = m2 - 1;
            else lo = m1 + 1;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log(max-min)) - Ternary search iterations with linear cost calculation at each step
* **Auxiliary Space:** 💾 O(1) - Constant extra space, no additional data structures needed

### ✅ **Why This Approach?**

* Works on continuous search space efficiently without sorting.
* No sorting required, preserves original array structure.
* Standard template for unimodal optimization problems.
* Excellent for scenarios where sorting overhead is undesirable.

## 📊 **3️⃣ Prefix Sum Optimization**

### 💡 Algorithm Steps:

1. Sort heights with their costs maintaining pair association.
2. Build prefix sums for costs and weighted heights.
3. For each position, calculate left and right side costs using prefix sums.
4. Find position with minimum total cost using mathematical formulation.
5. Update result incrementally as we move to next sorted height.

```cpp
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {heights[i], cost[i]};
        sort(v.begin(), v.end());
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + v[i].second;
        long long res = LLONG_MAX, curr = 0;
        for (int i = 0; i < n; i++) curr += (long long)abs(heights[i] - v[0].first) * cost[i];
        res = curr;
        for (int i = 1; i < n; i++) {
            long long diff = v[i].first - v[i - 1].first;
            curr += diff * (pre[i] - (pre[n] - pre[i]));
            res = min(res, curr);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Dominated by sorting operation, followed by linear prefix sum construction and traversal
* **Auxiliary Space:** 💾 O(n) - Additional arrays for pairs and prefix sums to optimize cost calculation

### ✅ **Why This Approach?**

* Avoids recalculating entire cost for each candidate height.
* Uses mathematical optimization with cumulative sums for efficiency.
* More efficient than brute force for large datasets.
* Incremental cost updates reduce redundant calculations.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Weighted Median**            | 🟢 O(n log n)          | 🟡 O(n)                 | 🎯 Direct mathematical solution   | 🔧 Requires sorting overhead         |
| 🔍 **Ternary Search**             | 🟡 O(n log R)          | 🟢 O(1)                 | 💾 Minimal space usage            | ⏱️ More iterations, multiple passes  |
| 🔄 **Prefix Sum**                 | 🟢 O(n log n)          | 🟡 O(n)                 | ⚡ Optimized cost calculation     | 🧠 Complex implementation logic      |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal time complexity**                        | 🥇 **Weighted Median**               | ★★★★★                     |
| 📖 **Memory constrained environments**                | 🥈 **Ternary Search**                | ★★★★☆                     |
| 🎯 **Production systems, large datasets**             | 🏅 **Prefix Sum**                    | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minCost(int[] heights, int[] cost) {
        int n = heights.length;
        int[][] v = new int[n][2];
        for (int i = 0; i < n; i++) {
            v[i][0] = heights[i];
            v[i][1] = cost[i];
        }
        Arrays.sort(v, (a, b) -> a[0] - b[0]);
        long total = 0;
        for (int x : cost) total += x;
        long sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i][1];
            if (sum >= (total + 1) / 2) {
                for (int j = 0; j < n; j++) res += (long)Math.abs(heights[j] - v[i][0]) * cost[j];
                return (int)res;
            }
        }
        return 0;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minCost(self, heights, cost):
        n = len(heights)
        v = sorted(zip(heights, cost))
        total = sum(cost)
        s, res = 0, 0
        for h, c in v:
            s += c
            if s >= (total + 1) // 2:
                for i in range(n):
                    res += abs(heights[i] - h) * cost[i]
                return res
        return 0
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

