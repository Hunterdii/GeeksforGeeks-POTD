---
title: "🚌 Bus Conductor | Minimum Moves to Seat Passengers | GFG Solution 🎯"  
keywords🏷️: ["🚌 bus conductor", "🔢 greedy algorithm", "📊 sorting", "🎯 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]  
author: "✍️ Het Patel (Hunterdii)"  
description: "✅ GFG solution to the Bus Conductor problem: find minimum moves to assign passengers to chairs using greedy sorting approach. 🚀"  
date: 📅 2025-12-19  
---

# *19. Bus Conductor*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/bus-conductor--170647/1)

## **🧩 Problem Description**

You are a conductor of a bus. You are given two arrays `chairs[]` and `passengers[]` of equal length, where `chairs[i]` is the position of the ith chair and `passengers[j]` is the position of the jth passenger. You may perform the following move any number of times:

* Increase or decrease the position of the ith passenger by 1 (i.e., moving the ith passenger from position x to x+1 or x-1)

Return the **minimum number of moves** required to move each passenger to get a chair.

**Note:** Although multiple chairs can occupy the same position, each passenger must be assigned to exactly one unique chair.

## **📘 Examples**

### Example 1

```cpp
Input: chairs[] = [3, 1, 5], passengers[] = [2, 7, 4]
Output: 4
Explanation: The passengers are moved as follows:
- The first passenger is moved from position 2 to position 1 using 1 move.
- The second passenger is moved from position 7 to position 5 using 2 moves.
- The third passenger is moved from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.
```

### Example 2

```cpp
Input: chairs[] = [2, 2, 6, 6], passengers[] = [1, 3, 2, 6]
Output: 4
Explanation: Note that there are two chairs at position 2 and two chairs at position 6.
The passengers are moved as follows:
- The first passenger is moved from position 1 to position 2 using 1 move.
- The second passenger is moved from position 3 to position 6 using 3 moves.
- The third passenger is not moved.
- The fourth passenger is not moved.
In total, 1 + 3 + 0 + 0 = 4 moves were used.
```

## **🔒 Constraints**

* $1 \le n \le 10^5$
* $1 \le \text{chairs}[i], \text{passengers}[j] \le 10^4$

## **✅ My Approach**

The optimal solution uses a **Greedy Sorting** strategy to minimize total moves:

### **Greedy Sorting Strategy**

1. **Key Insight:**
   * To minimize total distance, we should pair the smallest chair position with the smallest passenger position, second smallest with second smallest, and so on.
   * This greedy approach ensures optimal assignment without considering all possible permutations.

2. **Sort Both Arrays:**
   * Sort `chairs[]` in ascending order to arrange chair positions from smallest to largest.
   * Sort `passengers[]` in ascending order to arrange passenger positions from smallest to largest.

3. **Calculate Minimum Moves:**
   * After sorting, iterate through both arrays simultaneously.
   * For each index i, calculate the absolute difference: `|chairs[i] - passengers[i]|`.
   * This difference represents the minimum moves needed to move passenger i to chair i.

4. **Accumulate Total:**
   * Sum all individual move distances to get the total minimum moves required.

5. **Why This Works:**
   * Sorting ensures we're making locally optimal choices at each step.
   * Pairing nearest positions minimizes crossing paths and redundant movements.
   * The greedy choice property guarantees global optimality for this problem.

## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n log n), as we perform sorting on both arrays which dominates the complexity. The subsequent linear traversal to calculate moves takes O(n), but sorting is the bottleneck.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables (res, n, i). The sorting is typically done in-place or with O(log n) stack space for recursion, which is considered constant for practical purposes.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int findMoves(vector<int>& c, vector<int>& p) {
        sort(c.begin(), c.end());
        sort(p.begin(), p.end());
        int res = 0, n = c.size();
        for (int i = 0; i < n; i++) res += abs(c[i] - p[i]);
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Priority Queue Approach**

### 💡 Algorithm Steps:

1. Insert all chair positions into a min-heap.
2. Insert all passenger positions into another min-heap.
3. Pop smallest elements from both heaps simultaneously.
4. Calculate absolute difference and accumulate moves.

```cpp
class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        priority_queue<int, vector<int>, greater<int>> c(chairs.begin(), chairs.end());
        priority_queue<int, vector<int>, greater<int>> p(passengers.begin(), passengers.end());
        int moves = 0;
        while (!c.empty()) {
            moves += abs(c.top() - p.top());
            c.pop();
            p.pop();
        }
        return moves;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Heap construction and operations
* **Auxiliary Space:** 💾 O(n) - Two heaps storing all elements

### ✅ **Why This Approach?**

* Natural ordering through heap structure
* Flexible for streaming data scenarios
* Good for practicing heap operations

## 📊 **3️⃣ Index-Based Direct Mapping**

### 💡 Algorithm Steps:

1. Sort both arrays to establish optimal pairing.
2. Use transform function with iterators for functional style.
3. Accumulate differences using standard library algorithms.
4. Return total accumulated moves.

```cpp
class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        return accumulate(chairs.begin(), chairs.end(), 0, 
            [&, i = 0](int sum, int chair) mutable {
                return sum + abs(chair - passengers[i++]);
            });
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Dominated by sorting
* **Auxiliary Space:** 💾 O(1) - No extra data structures

### ✅ **Why This Approach?**

* Modern C++ functional programming style
* Compact and expressive code
* Efficient single-pass accumulation

## 📊 **4️⃣ Two Pointer Technique**

### 💡 Algorithm Steps:

1. Sort both arrays independently.
2. Use two pointers starting from beginning of each array.
3. Calculate distance for each matched pair.
4. Move both pointers forward synchronously.

```cpp
class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        int i = 0, j = 0, total = 0;
        while (i < chairs.size() && j < passengers.size()) {
            total += abs(chairs[i++] - passengers[j++]);
        }
        return total;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting dominates
* **Auxiliary Space:** 💾 O(1) - Only pointer variables

### ✅ **Why This Approach?**

* Clear two-pointer pattern demonstration
* Easy to trace and debug
* Extensible for constraint variations

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Greedy Sorting**            | 🟢 O(n log n)          | 🟢 O(1)                 | 🚀 Optimal space usage            | 🔧 Requires sorting                  |
| 🔍 **Priority Queue**             | 🟢 O(n log n)          | 🟡 O(n)                 | 📖 Natural ordering               | 💾 Extra heap space                  |
| 📊 **Functional STL**             | 🟢 O(n log n)          | 🟢 O(1)                 | 🎯 Modern C++ style               | 🧩 Lambda complexity                 |
| 🔄 **Two Pointer**                | 🟢 O(n log n)          | 🟢 O(1)                 | ⭐ Classic pattern                | 🔧 Similar to greedy                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Greedy Sorting**                | ★★★★★                     |
| 📖 **Learning heap structures**                       | 🥈 **Priority Queue**                | ★★★★☆                     |
| 🔧 **Modern C++ interview**                           | 🥉 **Functional STL**                | ★★★★☆                     |
| 🎯 **Two-pointer practice**                           | 🏅 **Two Pointer**                   | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int findMoves(int[] c, int[] p) {
        Arrays.sort(c);
        Arrays.sort(p);
        int res = 0;
        for (int i = 0; i < c.length; i++) res += Math.abs(c[i] - p[i]);
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findMoves(self, c, p):
        c.sort()
        p.sort()
        return sum(abs(x - y) for x, y in zip(c, p))
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





















