---
title: "🌸 Max min Height | GFG Solution 🎯"
keywords🏷️: ["🌸 flower watering", "🔍 binary search", "📊 greedy algorithm", "📈 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Maximize Minimum Height of Flowers: find the maximum possible minimum height using binary search and greedy watering strategy. 🚀"
date: 📅 2025-02-12
---

# *12. Max Min Height*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/max-min-height--170647/1)

## **🧩 Problem Description**

You are given an array `arr[]` representing the initial heights of flowers in a garden. You have `k` days to water the flowers. When you water a flower at position `i`, it also waters all flowers in the range `[i-w, i+w]` (where `w` is the watering window). Each watering increases the height of the affected flowers by 1.

Your task is to **maximize the minimum height** among all flowers after optimally using the `k` watering days.

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
* $1 \le \text{arr}[i] \le 10^9$
* $1 \le k \le 10^5$
* $0 \le w < \text{arr.size()}$

## **✅ My Approach**

The optimal solution uses **Binary Search on Answer** combined with a **Greedy Validation Strategy**:

### **Binary Search + Greedy Checking**

1. **Define Search Space:**
   * `low` = minimum value in the array (best we can guarantee without watering)
   * `high` = minimum value + k (if we water the shortest flower k times)

2. **Binary Search Logic:**
   * For each mid value, check if it's possible to make every flower at least `mid` height using k waterings.
   * If possible, try for a higher answer (move `low` up)
   * If not possible, reduce the target (move `high` down)

3. **Greedy Validation (isPossible):**
   * Iterate through each flower left to right
   * For each flower, if its current height (including previous waterings in range) is less than target:
     - Water it enough times to reach the target
     - This watering also affects flowers within window `w`
   * Track remaining days; if we run out (k < 0), return false

4. **Optimization Trick:**
   * Maintain cumulative watering effects to avoid recalculating window sums
   * Subtract waterings that fall outside the current window range

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log(k)), where n is the size of the array. The binary search runs in O(log k) iterations, and each validation check takes O(n) time to process all flowers.
* **Expected Auxiliary Space Complexity:** O(n), as we use an auxiliary array to track cumulative watering effects during the validation check.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool check(vector<int> &a, int k, int w, int h) {
        int n = a.size();
        vector<int> add(n);
        for (int i = 0; i < n; i++) {
            int cur = a[i] + (i > 0 ? add[i - 1] : 0);
            if (i >= w) cur -= add[i - w];
            if (cur < h) {
                int need = h - cur;
                if (need > k) return false;
                k -= need;
                add[i] = (i > 0 ? add[i - 1] : 0) + need;
            } else {
                add[i] = i > 0 ? add[i - 1] : 0;
            }
        }
        return true;
    }
    
    int maxMinHeight(vector<int> &a, int k, int w) {
        int lo = *min_element(a.begin(), a.end());
        int hi = lo + k, ans = lo;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(a, k, w, mid)) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Prefix Sum Optimization**

### 💡 Algorithm Steps:

1. Use binary search on the answer range as main approach.
2. In validation, maintain a running prefix sum of water additions.
3. Calculate current height by adding prefix effects and subtracting out-of-window effects.
4. Greedily water each flower that falls below target height.

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
        for (int i = 1; i < n; i++) low = min(low, arr[i]);
        int high = low + k, ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, w, mid)) ans = max(ans, mid), low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k) - Binary search with linear validation
* **Auxiliary Space:** 💾 O(n) - Water tracking array

### ✅ **Why This Approach?**

* Clear prefix sum semantics
* Explicit window boundary handling
* Easy to debug and verify correctness

## 📊 **3️⃣ Simplified Greedy Approach**

### 💡 Algorithm Steps:

1. Binary search on answer with streamlined bounds.
2. For validation, track cumulative water effect in single variable.
3. Process flowers sequentially, adding water as needed.
4. Subtract window-expired water effects on the fly.

```cpp
class Solution {
public:
    int maxMinHeight(vector<int> &a, int k, int w) {
        int n = a.size(), minVal = a[0];
        for (int x : a) minVal = min(minVal, x);
        int l = minVal, r = minVal + k, ans = minVal;
        while (l <= r) {
            int m = (l + r) / 2;
            vector<long long> wtr(n);
            long long used = 0, sum = 0;
            bool ok = true;
            for (int i = 0; i < n && ok; i++) {
                if (i >= w) sum -= wtr[i - w];
                long long need = max(0LL, m - a[i] - sum);
                if (used + need > k) ok = false;
                else {
                    wtr[i] = need;
                    sum += need;
                    used += need;
                }
            }
            if (ok) ans = m, l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k) - Standard binary search complexity
* **Auxiliary Space:** 💾 O(n) - Water tracking array

### ✅ **Why This Approach?**

* Single-pass validation per binary search iteration
* Direct calculation without recursion
* Handles large values with long long

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Binary Search + Greedy**     | 🟢 O(n log k)          | 🟡 O(n)                 | 🚀 Optimal and clean              | 💾 Requires auxiliary array          |
| 🔄 **Prefix Sum Optimization**    | 🟢 O(n log k)          | 🟡 O(n)                 | 📊 Clear prefix semantics         | 🔧 Similar to main approach          |
| 🎨 **Simplified Greedy**          | 🟢 O(n log k)          | 🟡 O(n)                 | 📖 Easy to understand             | 🔧 Handles overflow with long long   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive programming**                        | 🥇 **Binary Search + Greedy**        | ★★★★★                     |
| 📖 **Interview clarity**                              | 🥈 **Prefix Sum Optimization**       | ★★★★★                     |
| 🎯 **Learning purposes**                              | 🏅 **Simplified Greedy**             | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    boolean check(int[] a, int k, int w, int h) {
        int n = a.length;
        int[] add = new int[n];
        for (int i = 0; i < n; i++) {
            int cur = a[i] + (i > 0 ? add[i - 1] : 0);
            if (i >= w) cur -= add[i - w];
            if (cur < h) {
                int need = h - cur;
                if (need > k) return false;
                k -= need;
                add[i] = (i > 0 ? add[i - 1] : 0) + need;
            } else {
                add[i] = i > 0 ? add[i - 1] : 0;
            }
        }
        return true;
    }
    
    public int maxMinHeight(int[] a, int k, int w) {
        int lo = a[0];
        for (int x : a) lo = Math.min(lo, x);
        int hi = lo + k, ans = lo;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(a, k, w, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxMinHeight(self, a, k, w):
        def check(h):
            water, add = k, [0] * len(a)
            for i in range(len(a)):
                cur = a[i] + (add[i - 1] if i > 0 else 0)
                if i >= w:
                    cur -= add[i - w]
                if cur < h:
                    need = h - cur
                    if need > water:
                        return False
                    water -= need
                    add[i] = (add[i - 1] if i > 0 else 0) + need
                else:
                    add[i] = add[i - 1] if i > 0 else 0
            return True
        
        lo, hi = min(a), min(a) + k
        ans = lo
        while lo <= hi:
            mid = (lo + hi) // 2
            if check(mid):
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1
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
