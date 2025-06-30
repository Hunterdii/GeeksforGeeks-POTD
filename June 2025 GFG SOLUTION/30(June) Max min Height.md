---
title: "🌸 Max Min Height | GFG Solution 💧"
keywords🏷️: ["🌸 max min height", "💧 flower watering", "🔍 binary search", "📈 greedy algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Max Min Height problem: maximize minimum flower height after k days of watering using binary search and greedy strategy. 🚀"
date: 📅 2025-06-30
---

# *30. Max Min Height*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/max-min-height--170647/1)

## **🧩 Problem Description**

Given a garden with **n flowers** planted in a row, represented by an array `arr[]` where `arr[i]` denotes the height of the ith flower. You will water them for **k days**. In one day you can water **w continuous flowers**. Whenever you water a flower its height increases by **1 unit**. You have to **maximize the minimum height** of all flowers after k days of watering.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 3, 4, 5, 1], k = 2, w = 2
Output: 2
Explanation: The minimum height after watering is 2.
Day 1: Water the last two flowers -> arr becomes [2, 3, 4, 6, 2]
Day 2: Water the last two flowers -> arr becomes [2, 3, 4, 7, 3]
```

### Example 2

```cpp
Input: arr[] = [5, 8], k = 5, w = 1
Output: 9
Explanation: The minimum height after watering is 9.
Day 1 - Day 4: Water the first flower -> arr becomes [9, 8]
Day 5: Water the second flower -> arr becomes [9, 9]
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le w \le \text{arr.size()}$
* $1 \le k \le 10^5$
* $1 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses **Binary Search on Answer** combined with a **Greedy Watering Strategy**:

### **Binary Search + Greedy Validation**

1. **Binary Search Setup:**
   * Search space: `[min(arr), min(arr) + k]`
   * For each candidate minimum height, check if it's achievable with k days

2. **Greedy Validation Strategy:**
   * Use a sliding window approach to simulate watering effects
   * Track cumulative water added using a frequency array
   * When a flower's height is below target, greedily add water to achieve the target
   * Early termination if we exceed k days

3. **Sliding Window Optimization:**
   * Maintain running sum of water effects within window w
   * Efficiently calculate current height by adding/removing window effects
   * Use prefix sum technique for optimal performance

4. **Maximize the Answer:**
   * If current target is achievable, try a higher target
   * If not achievable, reduce the target
   * Return the maximum achievable minimum height

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log k), where n is the array size and k is the number of days. Binary search takes O(log k) iterations, and each validation takes O(n) time to simulate the watering process.
* **Expected Auxiliary Space Complexity:** O(n), as we use an auxiliary array to track the cumulative watering effects for each position in the garden.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool isPossible(vector<int> &arr, int k, int w, int maxHeight) {
        int n = arr.size();
        vector<int> water(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) water[i] = water[i - 1];
            int currHeight = arr[i] + water[i];
            if (i >= w) currHeight -= water[i - w];
            if (currHeight < maxHeight) {
                int add = maxHeight - currHeight;
                water[i] += add;
                k -= add;
                if (k < 0) return false;
            }
        }
        return true;
    }
    
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        int low = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < low) low = arr[i];
        }
        int high = low + k, ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, w, mid)) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized Space Approach with Sliding Window**

### 💡 Algorithm Steps:

1. Use sliding window technique to track watering effects efficiently.
2. Maintain running sum of water added within window.
3. Apply binary search on answer with optimized space usage.

```cpp
class Solution {
public:
    bool canAchieve(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> added(n, 0);
        int windowSum = 0;
        
        for (int i = 0; i < n; i++) {
            if (i >= w) windowSum -= added[i - w];
            
            int currentHeight = arr[i] + windowSum;
            if (currentHeight < target) {
                int need = target - currentHeight;
                added[i] = need;
                windowSum += need;
                k -= need;
                if (k < 0) return false;
            }
        }
        return true;
    }
    
    int maxMinHeight(vector<int>& arr, int k, int w) {
        int minVal = *min_element(arr.begin(), arr.end());
        int left = minVal, right = minVal + k, result = minVal;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAchieve(arr, k, w, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k)
* **Auxiliary Space:** 💾 O(n) - For tracking water added

### ✅ **Why This Approach?**

* Uses STL min_element for cleaner code.
* Optimized sliding window implementation.
* Better variable naming for clarity.

## 📊 **3️⃣ Greedy with Prefix Sum Optimization**

### 💡 Algorithm Steps:

1. Use prefix sum to efficiently calculate cumulative watering effects.
2. Apply greedy strategy with early termination.
3. Optimize binary search bounds.

```cpp
class Solution {
public:
    bool solve(vector<int>& heights, int days, int range, int minHeight) {
        int n = heights.size();
        vector<long long> water(n + range, 0);
        long long used = 0;
        
        for (int i = 0; i < n; i++) {
            long long current = heights[i] + water[i];
            if (current < minHeight) {
                long long need = minHeight - current;
                used += need;
                if (used > days) return false;
                water[i] += need;
                if (i + range < n + range) water[i + range] -= need;
            }
            if (i + 1 < n + range) water[i + 1] += water[i];
        }
        return true;
    }
    
    int maxMinHeight(vector<int>& arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int answer = low;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(arr, k, w, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k)
* **Auxiliary Space:** 💾 O(n + w)

### ✅ **Why This Approach?**

* Handles large numbers with long long.
* Efficient prefix sum technique.
* Optimized memory allocation.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                          | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Binary Search + Frequency Array**   | 🟢 O(n log k)          | 🟢 O(n)                 | ⚡ Simple implementation          | 🧮 Multiple array operations         |
| 🔄 **Sliding Window**                   | 🟢 O(n log k)          | 🟢 O(n)                 | 🔧 Optimized window tracking     | 💾 Similar space complexity         |
| 🔺 **Prefix Sum**                       | 🟢 O(n log k)          | 🟡 O(n + w)             | 🚀 Handles overflow, efficient   | 💾 Extra space for range           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**              | 🔥 **Performance Rating** |
| -------------------------------------------------- | ----------------------------------------- | ------------------------- |
| ⚡ Competitive programming, simple implementation  | 🥇 **Binary Search + Frequency Array**   | ★★★★★                     |
| 🔧 Production code, optimized window operations   | 🥈 **Sliding Window**                    | ★★★★☆                     |
| 📊 Large numbers, overflow concerns               | 🥉 **Prefix Sum**                        | ★★★★☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    boolean isPossible(int[] arr, int k, int w, int maxHeight) {
        int n = arr.length;
        int[] water = new int[n];
        for (int i = 0; i < n; i++) {
            if (i > 0) water[i] = water[i - 1];
            int currHeight = arr[i] + water[i];
            if (i >= w) currHeight -= water[i - w];
            if (currHeight < maxHeight) {
                int add = maxHeight - currHeight;
                water[i] += add;
                k -= add;
                if (k < 0) return false;
            }
        }
        return true;
    }
    
    public int maxMinHeight(int[] arr, int k, int w) {
        int n = arr.length;
        int low = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < low) low = arr[i];
        }
        int high = low + k, ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, w, mid)) {
                ans = Math.max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def isPossible(self, arr, k, w, maxHeight):
        n = len(arr)
        water = [0] * n
        for i in range(n):
            if i > 0:
                water[i] = water[i - 1]
            currHeight = arr[i] + water[i]
            if i >= w:
                currHeight -= water[i - w]
            if currHeight < maxHeight:
                add = maxHeight - currHeight
                water[i] += add
                k -= add
                if k < 0:
                    return False
        return True
    
    def maxMinHeight(self, arr, k, w):
        n = len(arr)
        low = min(arr)
        high = low + k
        ans = low
        while low <= high:
            mid = low + (high - low) // 2
            if self.isPossible(arr, k, w, mid):
                ans = max(ans, mid)
                low = mid + 1
            else:
                high = mid - 1
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
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
