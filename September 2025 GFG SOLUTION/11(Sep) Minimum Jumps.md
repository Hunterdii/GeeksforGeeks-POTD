---
title: "🚀 Minimum Jumps | GFG Solution 🎯"
keywords🏷️: ["🚀 minimum jumps", "🎯 greedy algorithm", "📍 two pointers", "🏃‍♂️ jump game", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Jumps problem: find minimum number of jumps to reach the end of array using greedy range-based approach. 🚀"
date: 📅 2025-09-11
---

# *11. Minimum Jumps*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1)

## **🧩 Problem Description**

You are given an array `arr[]` of non-negative numbers. Each number tells you the **maximum number of steps** you can jump forward from that position.

For example:
- If `arr[i] = 3`, you can jump to index `i + 1`, `i + 2`, or `i + 3` from position `i`.
- If `arr[i] = 0`, you cannot jump forward from that position.

Your task is to find the **minimum number of jumps** needed to move from the first position in the array to the last position.

**Note:** Return `-1` if you can't reach the end of the array.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
Output: 3
Explanation: First jump from 1st element to 2nd element with value 3. 
From here we jump to 5th element with value 9, and from here we will jump to the last.
```

### Example 2

```cpp
Input: arr[] = [1, 4, 3, 2, 6, 7]
Output: 2
Explanation: First we jump from the 1st to 2nd element and then jump to the last element.
```

### Example 3

```cpp
Input: arr[] = [0, 10, 20]
Output: -1
Explanation: We cannot go anywhere from the 1st element.
```

## **🔒 Constraints**

* $2 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses a **Greedy Range-Based Strategy** that processes the array in segments, where each segment represents positions reachable within the current number of jumps:

### **Greedy Range-Based Algorithm**

1. **Initialize Variables:**
   * `jumps` = 0 (number of jumps taken)
   * `far` = 0 (farthest position reachable with current jumps)
   * `end` = 0 (end of current reachable range)

2. **Process Each Position:**
   * For each position `i`, update `far = max(far, i + arr[i])` to find the farthest reachable position.
   * When we reach the end of current range (`i == end`), we must make a jump.
   * Increment `jumps` and update `end = far` to extend our reachable range.

3. **Early Termination:**
   * If `end >= n - 1`, we can reach the last position, return `jumps`.
   * If we exhaust all positions without reaching the end, return `-1`.

4. **Key Insight:**
   * We use a greedy strategy: within each reachable range, we find the position that allows us to jump the farthest in the next jump.
   * This ensures we make the minimum number of jumps.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We traverse the array once, and each element is processed exactly once.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables (jumps, far, end).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), jumps = 0, far = 0, end = 0;
        for (int i = 0; i < n - 1; i++) {
            far = max(far, i + arr[i]);
            if (i == end) jumps++, end = far;
            if (end >= n - 1) return jumps;
        }
        return -1;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pointer Range Update**

### 💡 Algorithm Steps:

1. Use two pointers to track current reachable range boundaries.
2. Expand the far pointer to maximum reachable position in current range.
3. When current range is exhausted, increment jumps and update range.
4. Continue until destination is within reachable range.

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), near = 0, far = 0, jumps = 0;
        while (far < n - 1) {
            int temp = far;
            for (int i = near; i <= far; i++) {
                temp = max(temp, i + arr[i]);
            }
            if (temp == far) return -1;
            near = far + 1;
            far = temp;
            jumps++;
        }
        return jumps;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each position visited at most twice
* **Auxiliary Space:** 💾 O(1) - Only constant extra variables

### ✅ **Why This Approach?**

* Explicit range-based processing
* Clear separation of reachable segments
* Easy to understand the jump boundaries

## 📊 **3️⃣ Segment-Based Greedy**

### 💡 Algorithm Steps:

1. Process array in segments where each segment represents positions reachable in current jumps.
2. For current segment, find the maximum reachable position for next jump.
3. Move to next segment when current segment is exhausted.
4. Count segments traversed as minimum jumps needed.

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;
        
        int jumps = 0, current_end = 0, farthest = 0;
        
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]);
            
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                
                if (current_end >= n - 1) break;
                if (current_end <= i) return -1;
            }
        }
        
        return jumps;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through the array
* **Auxiliary Space:** 💾 O(1) - Only constant extra variables

### ✅ **Why This Approach?**

* Explicit boundary checking for impossible cases
* Clear segment-based thinking
* Robust handling of edge cases

## 📊 **4️⃣ BFS-Style Level Processing**

### 💡 Algorithm Steps:

1. Treat each jump as a level in BFS traversal.
2. Process all positions reachable in current level.
3. Find all positions reachable in next level.
4. Continue until target position is reached.

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        
        int level = 0, currentMax = 0, nextMax = 0;
        
        for (int i = 0; i < n - 1; i++) {
            nextMax = max(nextMax, i + arr[i]);
            
            if (i == currentMax) {
                level++;
                currentMax = nextMax;
                
                if (currentMax >= n - 1) return level;
                if (currentMax <= i) return -1;
            }
        }
        
        return -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Process each element once
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* BFS-like level-order processing
* Clear conceptual model
* Natural jump counting mechanism

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Greedy Range**               | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal performance, clean     | 🧠 Requires greedy insight           |
| 🔄 **Two-Pointer Range**          | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Explicit range handling        | 🔧 More complex loop structure       |
| 📊 **Segment Greedy**             | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Robust edge case handling      | 🔧 More verbose implementation       |
| 🌊 **BFS-Style Level**            | 🟢 O(n)                | 🟢 O(1)                 | 🧠 Intuitive BFS-like thinking    | 🔄 Similar to greedy but less direct |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive Programming**                       | 🥇 **Greedy Range**                  | ★★★★★                     |
| 🎯 **Interview/Clean Code**                          | 🥈 **Segment Greedy**                | ★★★★★                     |
| 🧠 **Learning/Understanding**                        | 🥉 **BFS-Style Level**               | ★★★★☆                     |
| 🔧 **Explicit Range Control**                        | 🎖️ **Two-Pointer Range**             | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length, jumps = 0, far = 0, end = 0;
        for (int i = 0; i < n - 1; i++) {
            far = Math.max(far, i + arr[i]);
            if (i == end) { jumps++; end = far; }
            if (end >= n - 1) return jumps;
        }
        return -1;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minJumps(self, arr):
        n, jumps, far, end = len(arr), 0, 0, 0
        for i in range(n - 1):
            far = max(far, i + arr[i])
            if i == end:
                jumps += 1
                end = far
            if end >= n - 1:
                return jumps
        return -1
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

