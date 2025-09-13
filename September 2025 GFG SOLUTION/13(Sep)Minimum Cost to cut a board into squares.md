---
title: "🔢 Minimum Cost to Cut a Board into Squares | GFG Solution 🔍"
keywords🏷️: ["🔢 minimum cost cutting", "🎯 greedy algorithm", "📍 two pointers", "🔄 sorting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Cost to Cut a Board into Squares problem: find optimal cutting strategy using greedy approach with sorting. 🚀"
date: 📅 2025-09-13
---

# *13. Minimum Cost to Cut a Board into Squares*

> **Note:** The solution for this problem is being published today as I was engaged in a hackathon yesterday. Thank you for your understanding.
> 
The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1)

## **🧩 Problem Description**

Given a board of dimensions `n × m` that needs to be cut into `n*m` squares. The cost of making a cut along a horizontal or vertical edge is provided in two arrays:

- `x[]`: Cutting costs along the vertical edges (length-wise).
- `y[]`: Cutting costs along the horizontal edges (width-wise).

Find the minimum total cost required to cut the board into squares optimally.

## **📘 Examples**

### Example 1

```cpp
Input: n = 4, m = 6, x[] = [2, 1, 3, 1, 4], y[] = [4, 1, 2]
Output: 42
Explanation: 
Initially no. of horizontal segments = 1 & no. of vertical segments = 1.
Optimal way to cut into square is:
• Pick 4 (from x) -> vertical cut, Cost = 4 × horizontal segments = 4,
  Now, horizontal segments = 1, vertical segments = 2.
• Pick 4 (from y) -> horizontal cut, Cost = 4 × vertical segments = 8,
  Now, horizontal segments = 2, vertical segments = 2.
• Pick 3 (from x) -> vertical cut, Cost = 3 × horizontal segments = 6,
  Now, horizontal segments = 2, vertical segments = 3.
• Pick 2 (from x) -> vertical cut, Cost = 2 × horizontal segments = 4,
  Now, horizontal segments = 2, vertical segments = 4.
• Pick 2 (from y) -> horizontal cut, Cost = 2 × vertical segments = 8,
  Now, horizontal segments = 3, vertical segments = 4.
• Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 3,
  Now, horizontal segments = 3, vertical segments = 5.
• Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 3,
  Now, horizontal segments = 3, vertical segments = 6.
• Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 6,
  Now, horizontal segments = 4, vertical segments = 6.
So, the total cost = 4 + 8 + 6 + 4 + 8 + 3 + 3 + 6 = 42.
```

### Example 2

```cpp
Input: n = 4, m = 4, x[] = [1, 1, 1], y[] = [1, 1, 1]
Output: 15
Explanation:
Initially no. of horizontal segments = 1 & no. of vertical segments = 1.
Optimal way to cut into square is:
• Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 1,
  Now, horizontal segments = 2, vertical segments = 1.
• Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 1,
  Now, horizontal segments = 3, vertical segments = 1.
• Pick 1 (from y) -> horizontal cut, Cost = 1 × vertical segments = 1,
  Now, horizontal segments = 4, vertical segments = 1.
• Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 4,
  Now, horizontal segments = 4, vertical segments = 2.
• Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 4,
  Now, horizontal segments = 4, vertical segments = 3.
• Pick 1 (from x) -> vertical cut, Cost = 1 × horizontal segments = 4,
  Now, horizontal segments = 4, vertical segments = 4
So, the total cost = 1 + 1 + 1 + 4 + 4 + 4 = 15.
```

## **🔒 Constraints**

* $2 \le n, m \le 10^3$
* $1 \le x[i], y[j] \le 10^3$

## **✅ My Approach**

The optimal approach uses a **Greedy Strategy** with **Sorting** and **Two Pointers** technique:

### **Greedy Algorithm with Two Pointers**

1. **Key Insight:**
   * Always choose the cut with the highest cost first to minimize future multiplications.
   * When we make a vertical cut, it affects all current horizontal segments.
   * When we make a horizontal cut, it affects all current vertical segments.

2. **Initialize Variables:**
   * Sort both arrays `x[]` and `y[]` in descending order.
   * Use two pointers: `i` for x array and `j` for y array.
   * Track `h` (horizontal segments) and `v` (vertical segments), both starting at 1.
   * Maintain `cost` to accumulate the total cutting cost.

3. **Greedy Selection:**
   * Compare `x[i]` and `y[j]` and always pick the larger cost.
   * If `x[i] > y[j]`: Make vertical cut, cost += `x[i] * h`, increment `v`.
   * Else: Make horizontal cut, cost += `y[j] * v`, increment `h`.

4. **Complete Remaining Cuts:**
   * Process remaining cuts in the respective arrays.
   * Continue until all cuts are made.

5. **Why This Works:**
   * By choosing expensive cuts first, we minimize the number of segments they multiply with.
   * This ensures optimal cost distribution across all cuts.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n + m log m), where n and m are the sizes of arrays x[] and y[] respectively. The sorting dominates the time complexity as we need to sort both arrays in descending order, and the two-pointer traversal takes O(n + m) time.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like pointers, counters, and the result. The sorting is done in-place.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        int h = 1, v = 1, i = 0, j = 0, cost = 0;
        while (i < x.size() && j < y.size()) {
            if (x[i] > y[j]) cost += x[i++] * h, v++;
            else cost += y[j++] * v, h++;
        }
        while (i < x.size()) cost += x[i++] * h;
        while (j < y.size()) cost += y[j++] * v;
        return cost;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Priority Queue Approach**

### 💡 Algorithm Steps:

1. Use max heap to always select the highest cost cut available.
2. Maintain separate counters for horizontal and vertical pieces.
3. Process cuts in descending order of cost to minimize future multiplications.
4. Calculate total cost by multiplying cut cost with current piece count.

```cpp
class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        priority_queue<pair<int,char>> pq;
        for (int cost : x) pq.push({cost, 'h'});
        for (int cost : y) pq.push({cost, 'v'});
        
        int h = 1, v = 1, total = 0;
        while (!pq.empty()) {
            auto [cost, type] = pq.top(); pq.pop();
            if (type == 'h') total += cost * h, v++;
            else total += cost * v, h++;
        }
        return total;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O((n+m) log(n+m)) - Heap operations
* **Auxiliary Space:** 💾 O(n+m) - Priority queue storage

### ✅ **Why This Approach?**

* Single data structure handles both cut types.
* Natural ordering with priority queue.
* Easy to extend for multiple cut types.

## 📊 **3️⃣ Merge-Based Approach**

### 💡 Algorithm Steps:

1. Sort both arrays in descending order separately.
2. Use two pointers to merge arrays while maintaining order.
3. Always choose the larger cost cut from remaining options.
4. Update piece counters and accumulate costs efficiently.

```cpp
class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        
        int cost = 0, pieces_h = 1, pieces_v = 1;
        int i = 0, j = 0;
        
        while (i < x.size() || j < y.size()) {
            bool take_horizontal = (j >= y.size()) || 
                                 (i < x.size() && x[i] >= y[j]);
            
            if (take_horizontal) {
                cost += x[i] * pieces_h;
                pieces_v++;
                i++;
            } else {
                cost += y[j] * pieces_v;
                pieces_h++;
                j++;
            }
        }
        return cost;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + m log m) - Sorting dominates
* **Auxiliary Space:** 💾 O(1) - Only constant extra space

### ✅ **Why This Approach?**

* Clean two-pointer merge technique.
* Optimal space usage with in-place processing.
* Clear separation of horizontal and vertical logic.

## 📊 **4️⃣ Greedy with Single Pass**

### 💡 Algorithm Steps:

1. Combine all cuts with type information into single array.
2. Sort by cost in descending order for greedy selection.
3. Process cuts sequentially, updating appropriate counters.
4. Multiply each cut cost by current number of pieces it affects.

```cpp
class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        vector<pair<int, bool>> cuts;
        for (int cost : x) cuts.push_back({cost, true});
        for (int cost : y) cuts.push_back({cost, false});
        
        sort(cuts.rbegin(), cuts.rend());
        
        int h_pieces = 1, v_pieces = 1, total = 0;
        for (auto [cost, is_horizontal] : cuts) {
            if (is_horizontal) {
                total += cost * h_pieces;
                v_pieces++;
            } else {
                total += cost * v_pieces;
                h_pieces++;
            }
        }
        return total;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O((n+m) log(n+m)) - Single sort operation
* **Auxiliary Space:** 💾 O(n+m) - Combined array storage

### ✅ **Why This Approach?**

* Unified processing of all cuts.
* Single sort operation instead of two.
* Clear greedy strategy implementation.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Two-Pointer Merge**          | 🟢 O(n log n + m log m)| 🟢 O(1)                 | 🚀 Optimal space usage           | 🔧 Requires careful pointer handling  |
| 🔍 **Priority Queue**              | 🟡 O((n+m) log(n+m))   | 🟡 O(n+m)               | 📖 Clean single structure        | 💾 Extra space for heap              |
| 📊 **Merge-Based**                 | 🟢 O(n log n + m log m)| 🟢 O(1)                 | 🎯 Clear merge logic             | 🔧 Complex boundary conditions        |
| 🔄 **Single Array**                | 🟡 O((n+m) log(n+m))   | 🟡 O(n+m)               | ⭐ Unified processing             | 💾 Additional array creation          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Memory-constrained systems**                     | 🥇 **Two-Pointer Merge**             | ★★★★★                     |
| 📖 **Code simplicity priority**                       | 🥈 **Priority Queue**                | ★★★★☆                     |
| 🔧 **Educational/Interview**                          | 🥉 **Merge-Based**                   | ★★★★☆                     |
| 🎯 **Competitive Programming**                        | 🏅 **Single Array**                  | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static int minCost(int n, int m, int[] x, int[] y) {
        Arrays.sort(x); Arrays.sort(y);
        int h = 1, v = 1, i = x.length - 1, j = y.length - 1, cost = 0;
        while (i >= 0 && j >= 0) {
            if (x[i] > y[j]) { cost += x[i--] * h; v++; }
            else { cost += y[j--] * v; h++; }
        }
        while (i >= 0) cost += x[i--] * h;
        while (j >= 0) cost += y[j--] * v;
        return cost;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minCost(self, n, m, x, y):
        x.sort(reverse=True); y.sort(reverse=True)
        h = v = i = j = cost = 0; h = v = 1
        while i < len(x) and j < len(y):
            if x[i] > y[j]: cost += x[i] * h; v += 1; i += 1
            else: cost += y[j] * v; h += 1; j += 1
        while i < len(x): cost += x[i] * h; i += 1
        while j < len(y): cost += y[j] * v; j += 1
        return cost
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
