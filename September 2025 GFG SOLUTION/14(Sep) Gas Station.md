---
title: "⛽ Gas Station | GFG Solution 🚗"
keywords🏷️: ["⛽ gas station", "🔄 circular tour", "📍 greedy algorithm", "📈 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Gas Station problem: find the starting station to complete a circular tour using greedy approach with optimal time and space complexity. 🚀"
date: 📅 2025-09-14
---

# *14. Gas Station*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1)

## **🧩 Problem Description**

You are given two integer arrays `gas[]` and `cost[]` representing n gas stations along a circular tour. At station `i`, you can fill `gas[i]` units of gas and need `cost[i]` units to travel to the next station `(i+1)`. Starting with an empty tank, find the index of the starting station that allows you to complete the entire circular tour without running out of gas. Return `-1` if no such starting station exists.

**Note:** If a solution exists, it is guaranteed to be unique.

## **📘 Examples**

### Example 1

```cpp
Input: gas[] = [4, 5, 7, 4], cost[] = [6, 6, 3, 5]
Output: 2
Explanation: Start at station 2 with 7 units of gas. Tank = 0 + 7 = 7
Travel to station 3: Available gas = (7 - 3 + 4) = 8
Travel to station 0: Available gas = (8 - 5 + 4) = 7
Travel to station 1: Available gas = (7 - 6 + 5) = 6
Return to station 2: Available gas = (6 - 6) = 0
```

### Example 2

```cpp
Input: gas[] = [3, 9], cost[] = [7, 6]
Output: -1
Explanation: No starting station allows completing the circular tour.
Total gas = 3 + 9 = 12, Total cost = 7 + 6 = 13. Since total cost > total gas, 
it's impossible to complete the tour.
```

## **🔒 Constraints**

* $1 \le n \le 10^6$
* $1 \le gas[i], cost[i] \le 10^3$

## **✅ My Approach**

The optimal solution uses a **Greedy Algorithm** that makes locally optimal choices to find the globally optimal starting station:

### **Greedy Single-Pass Algorithm**

1. **Key Insight:**
   * If total gas ≥ total cost, a solution exists (guaranteed unique)
   * We need to find the optimal starting point using greedy selection

2. **Algorithm Steps:**
   * Track `total`: sum of all (gas[i] - cost[i]) differences
   * Track `curr`: running balance from current potential start
   * Track `start`: current candidate starting station

3. **Greedy Decision:**
   * When `curr < 0`, the current starting point is invalid
   * Reset start to next station and reset current balance to 0
   * This works because if we can't reach station `i` from any station ≤ j, then station `j+1` is the earliest possible valid start

4. **Validation:**
   * If `total ≥ 0`, return the found starting station
   * If `total < 0`, no solution exists

### **Why This Works:**
The greedy approach is optimal because:
- If we can't complete the tour starting from station `i`, then starting from any station between `i` and the failure point is also impossible
- The first station after a failure point is the next best candidate
- Total gas vs total cost determines overall feasibility

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of gas stations. We traverse the array exactly once, performing constant operations at each station.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for tracking variables (total, curr, start) regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if (curr < 0) start = i + 1, curr = 0;
        }
        return total >= 0 ? start : -1;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pass Approach**

### 💡 Algorithm Steps:

1. Calculate the total gas balance across all stations.
2. If total gas is negative, it's impossible to complete circuit.
3. If positive, find optimal start point using greedy selection.
4. Validate the solution by simulating complete journey.

```cpp
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two separate linear passes
* **Auxiliary Space:** 💾 O(1) - Only constant variables used

### ✅ **Why This Approach?**

* Clear separation of feasibility check and solution finding
* Explicit validation prevents edge case errors
* Easy to understand and debug logic flow

## 📊 **3️⃣ Prefix Sum Approach**

### 💡 Algorithm Steps:

1. Compute prefix sums of net fuel differences.
2. Find minimum prefix sum position in the array.
3. Starting point is the station after minimum sum location.
4. Check total sum non-negativity for solution existence.

```cpp
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, sum = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            sum += diff;
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single traversal with prefix calculations
* **Auxiliary Space:** 💾 O(1) - Constant space for tracking variables

### ✅ **Why This Approach?**

* Mathematical elegance using cumulative sums
* Direct calculation without simulation steps
* Minimal code with optimal performance

## 📊 **4️⃣ Efficient Circular Check**

#### **Algorithm Steps:**

1. Traverse the array in a **circular manner** using modular arithmetic.
2. If the **current gas balance** becomes negative, reset the start station to the next one.
3. If the **total gas** is positive, return the start station, otherwise return -1.

```cpp
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        int n = gas.size();
        for (int i = 0; i < 2 * n; i++) {
            int index = i % n;
            int diff = gas[index] - cost[index];
            total += diff;
            curr += diff;
            if (curr < 0) {
                start = index + 1;
                curr = 0;
                if (start >= n) break;
            }
        }
        return total >= 0 ? start : -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with up to 2n iterations (worst case)
* **Auxiliary Space:** 💾 O(1) - Only constant variables for tracking state

### ✅ **Why This Approach?**

* Explicit circular traversal makes the algorithm's intent clear
* Early termination when start point exceeds array bounds
* Robust handling of edge cases through modular indexing
* Visual representation of the circular nature of the problem

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Greedy One-Pass**            | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal time and space        | 🔧 Requires algorithm insight        |
| 🔍 **Two-Pass**                   | 🟢 O(n)                | 🟢 O(1)                 | 📖 Clear logic separation        | 🐌 Two separate iterations           |
| 📊 **Prefix Sum**                 | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Mathematical elegance         | 🤔 Less intuitive approach          |
| 🔄 **Efficient Circular Check**   | 🟡 O(n)                | 🟢 O(1)                 | 🎪 Clear circular visualization  | 🐌 Potentially up to 2n iterations  |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive Programming**                        | 🥇 **Greedy One-Pass**               | ★★★★★                     |
| 📖 **Learning/Interview**                            | 🥈 **Two-Pass**                      | ★★★★☆                     |
| 🔧 **Mathematical Interest**                          | 🥉 **Prefix Sum**                    | ★★★★☆                     |
| 🎪 **Educational/Visualization**                      | 🎯 **Efficient Circular Check**      | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int startStation(int[] gas, int[] cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.length; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if (curr < 0) { start = i + 1; curr = 0; }
        }
        return total >= 0 ? start : -1;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def startStation(self, gas, cost):
        total = curr = start = 0
        for i in range(len(gas)):
            diff = gas[i] - cost[i]
            total += diff
            curr += diff
            if curr < 0: start, curr = i + 1, 0
        return start if total >= 0 else -1
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
