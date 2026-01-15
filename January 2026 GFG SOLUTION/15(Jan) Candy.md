---
title: "🍬 Candy | GFG Solution 🔍"
keywords🏷️: ["🍬 candy distribution", "🔢 greedy", "📈 peak-valley", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution for minimum candies to distribute to children given ratings. Peak-valley & two-pass solutions with linear time guarantees and multi-language code. 🚀"
date: 📅 2026-01-15
---

# *15. Candy* 🍬

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/candy/1)

## **🧩 Problem Description**

You are given an array `arr[]` where each element represents a child's rating. You need to distribute candies to these children following these rules:

1. Each child must receive at least one candy.
2. Children with a higher rating than their neighbors must receive more candies than those neighbors.

Your task is to find the **minimum number of candies** needed to satisfy these conditions.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 0, 2]
Output: 5
Explanation: Child at index 1 has the lowest rating, so gets 1 candy. 
Child at index 0 has rating higher than index 1, so gets 2 candies.
Child at index 2 has rating higher than index 1, so gets 2 candies.
Total candies = 2 + 1 + 2 = 5.
```

### Example 2

```cpp
Input: arr[] = [1, 2, 2]
Output: 4
Explanation: Child at index 0 gets 1 candy.
Child at index 1 has higher rating than index 0, so gets 2 candies.
Child at index 2 has equal rating to index 1, so gets 1 candy (only needs to satisfy left neighbor).
Total candies = 1 + 2 + 1 = 4.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses the **Peak-Valley** technique to minimize candy distribution in a single pass with constant space:

### **Peak-Valley Single Pass Algorithm**

1. **Initialize Variables:**
   * Start with `total = n` (each child gets at least 1 candy).
   * Use pointer `i` starting at index 1 to traverse the array.

2. **Handle Equal Ratings:**
   * When `arr[i] == arr[i-1]`, no extra candies needed - just move to next child.

3. **Identify Peaks (Ascending Sequence):**
   * While ratings increase (`arr[i] > arr[i-1]`), we're climbing a peak.
   * Each step up requires one more candy than the previous child.
   * Track the peak height and add candies accordingly.

4. **Identify Valleys (Descending Sequence):**
   * While ratings decrease (`arr[i] < arr[i-1]`), we're descending into a valley.
   * Each step down requires one more candy than the next child (going backwards).
   * Track the valley depth and add candies accordingly.

5. **Optimize Overlap:**
   * At the transition point between peak and valley, one child is counted in both.
   * Subtract the minimum of peak and valley heights to avoid double-counting.
   * The taller sequence already satisfies the constraint for the transition child.

6. **Continue Until End:**
   * Repeat the process for all peaks and valleys until reaching the end of the array.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We traverse the array once, processing each element exactly once during peak and valley identification.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like `total`, `i`, `peak`, and `valley`, regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = arr.size(), total = n, i = 1;
        while (i < n) {
            if (arr[i] == arr[i - 1]) { i++; continue; }
            int peak = 0;
            while (i < n && arr[i] > arr[i - 1]) total += ++peak, i++;
            int valley = 0;
            while (i < n && arr[i] < arr[i - 1]) total += ++valley, i++;
            total -= min(peak, valley);
        }
        return total;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pass Approach**

### 💡 Algorithm Steps:

1. Create two arrays `left` and `right`, both initialized with 1 (minimum candy for each child).
2. **First Pass (Left to Right):** Traverse from index 1 to n-1. If `arr[i] > arr[i-1]`, set `left[i] = left[i-1] + 1` to ensure children with higher ratings than their left neighbor get more candies.
3. **Second Pass (Right to Left):** Traverse from index n-2 to 0. If `arr[i] > arr[i+1]`, set `right[i] = right[i+1] + 1` to ensure children with higher ratings than their right neighbor get more candies.
4. For each position, take the maximum of `left[i]` and `right[i]` to satisfy both neighbor constraints.
5. Sum all the candies to get the total minimum required.

```cpp
class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, 1), right(n, 1);
        for (int i = 1; i < n; i++)
            if (arr[i] > arr[i - 1]) left[i] = left[i - 1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (arr[i] > arr[i + 1]) right[i] = right[i + 1] + 1;
        int total = 0;
        for (int i = 0; i < n; i++) total += max(left[i], right[i]);
        return total;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Three linear passes through the array
* **Auxiliary Space:** 💾 O(n) - Two additional arrays for tracking left and right candy counts

### ✅ **Why This Approach?**

* Clear and intuitive logic with separate handling of left and right constraints
* Easy to understand and debug
* Handles all edge cases naturally with explicit left-right validation

## 📊 **3️⃣ Space-Optimized Single Array**

### 💡 Algorithm Steps:

1. Create a single array `candies` initialized to 1 for all children.
2. **Forward Pass:** Traverse left to right. If `arr[i] > arr[i-1]`, update `candies[i] = candies[i-1] + 1`.
3. **Backward Pass:** Traverse right to left. If `arr[i] > arr[i+1]`, update `candies[i] = max(candies[i], candies[i+1] + 1)` to maintain both constraints.
4. The backward pass ensures we don't violate the left constraint already satisfied.
5. Sum all values in the `candies` array to get the total minimum candies needed.

```cpp
class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++)
            if (arr[i] > arr[i - 1]) candies[i] = candies[i - 1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (arr[i] > arr[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
        int total = 0;
        for (int x : candies) total += x;
        return total;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Three linear passes through the array
* **Auxiliary Space:** 💾 O(n) - Single array for candy distribution tracking

### ✅ **Why This Approach?**

* More space efficient than the two-array approach
* Still maintains clear and readable logic
* Common pattern used in coding interviews

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏔️ **Peak-Valley (Main)**        | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal time & space           | 🧩 Complex logic, harder to visualize |
| ↔️ **Two-Pass**                   | 🟢 O(n)                | 🟡 O(n)                 | 📖 Very clear and intuitive       | 💾 Extra space for two arrays        |
| 📈 **Single Array**               | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Good balance of clarity & space | 💾 Still uses O(n) auxiliary space   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance, competitive programming**   | 🥇 **Peak-Valley**                   | ★★★★★                     |
| 📖 **Learning/interview, readability priority**       | 🥈 **Two-Pass**                      | ★★★★☆                     |
| 🔧 **Production code, easy debugging**                | 🥉 **Single Array**                  | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minCandy(int arr[]) {
        int n = arr.length, total = n, i = 1;
        while (i < n) {
            if (arr[i] == arr[i - 1]) { i++; continue; }
            int peak = 0;
            while (i < n && arr[i] > arr[i - 1]) { total += ++peak; i++; }
            int valley = 0;
            while (i < n && arr[i] < arr[i - 1]) { total += ++valley; i++; }
            total -= Math.min(peak, valley);
        }
        return total;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minCandy(self, arr):
        n, total, i = len(arr), len(arr), 1
        while i < n:
            if arr[i] == arr[i - 1]:
                i += 1
                continue
            peak = 0
            while i < n and arr[i] > arr[i - 1]:
                peak += 1
                total += peak
                i += 1
            valley = 0
            while i < n and arr[i] < arr[i - 1]:
                valley += 1
                total += valley
                i += 1
            total -= min(peak, valley)
        return total
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
