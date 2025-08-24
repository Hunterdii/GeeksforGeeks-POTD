---
title: "🌸 Minimum Days to Make M Bouquets | GFG Solution 🔍"
keywords🏷️: ["🌸 minimum days", "🔍 binary search", "📈 greedy algorithm", "🌺 bouquets", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Days to Make M Bouquets problem: find minimum days required to create m bouquets using binary search optimization technique. 🚀"
date: 📅 2025-08-24
---

# *24. Minimum Days to Make M Bouquets*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1)

## **🧩 Problem Description**

You have a row of flowers, where each flower blooms after a specific day. The array `arr[]` represents the blooming schedule: `arr[i]` is the day the flower at position `i` will bloom. To create a bouquet, you need to collect **k adjacent bloomed flowers**. Each flower can only be used in one bouquet.

Your goal is to find the **minimum number of days** required to make exactly **m bouquets**. If it is not possible to make m bouquets with the given arrangement, return **-1**.

## **📘 Examples**

### Example 1

```cpp
Input: m = 3, k = 2, arr[] = [3, 4, 2, 7, 13, 8, 5]
Output: 8
Explanation: We need 3 bouquets and each bouquet should have 2 flowers. 
After day 8: [x, x, x, x, _, x, x], we can make first bouquet from the first 2 flowers, 
second bouquet from the next 2 flowers and the third bouquet from the last 2 flowers.
```

### Example 2

```cpp
Input: m = 2, k = 3, arr[] = [5, 5, 5, 5, 10, 5, 5]
Output: 10
Explanation: We need 2 bouquets and each bouquet should have 3 flowers, 
After day 5: [x, x, x, x, _, x, x], we can make one bouquet of the first three flowers 
that bloomed, but cannot make another bouquet. After day 10: [x, x, x, x, x, x, x], 
Now we can make two bouquets, taking 3 adjacent flowers in one bouquet.
```

### Example 3

```cpp
Input: m = 3, k = 2, arr[] = [1, 10, 3, 10, 2]
Output: -1
Explanation: As 3 bouquets each having 2 flowers are needed, that means we need 6 flowers. 
But there are only 5 flowers so it is impossible to get the needed bouquets therefore -1 will be returned.
```

## **🔒 Constraints**

* $1 \le k \le \text{arr.size()} \le 10^5$
* $1 \le m \le 10^5$
* $1 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses **Binary Search** on the answer combined with a **Greedy Algorithm** to check feasibility:

### **Binary Search + Greedy Validation**

1. **Check Impossibility:**
   * If `k × m > arr.size()`, it's impossible to make m bouquets, return -1.

2. **Set Search Range:**
   * `left` = minimum bloom day in array (earliest possible answer)
   * `right` = maximum bloom day in array (latest possible answer)

3. **Binary Search on Days:**
   * For each mid-day, check if we can make m bouquets by that day.
   * Use greedy approach: scan array left to right, count consecutive bloomed flowers.

4. **Greedy Bouquet Formation:**
   * Maintain `flowers` counter for consecutive bloomed flowers.
   * When `flowers == k`, we can form a bouquet, increment `bouquets` count.
   * Reset `flowers = 0` after forming a bouquet or encountering unbloomed flower.

5. **Update Search Range:**
   * If `bouquets >= m`: answer exists at mid or earlier, set `right = mid`.
   * Otherwise: need more days, set `left = mid + 1`.

6. **Return Result:**
   * Continue until `left >= right`, return `left` as minimum days needed.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × log(max(arr) - min(arr))), where n is the size of the array. Binary search runs for log(range) iterations, and each iteration requires O(n) time to validate bouquet formation.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional variables for tracking flowers, bouquets, and search boundaries.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        if ((long long)k * m > arr.size()) return -1;
        int l = *min_element(arr.begin(), arr.end());
        int r = *max_element(arr.begin(), arr.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            int flowers = 0, bouquets = 0;
            for (int bloom : arr) {
                if (bloom <= mid) {
                    if (++flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else flowers = 0;
            }
            if (bouquets >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Precomputation with Binary Search**

### 💡 Algorithm Steps:

1. Precompute consecutive bloom segments for different day thresholds.
2. Use binary search to find minimum days where segments can form required bouquets.
3. Cache intermediate results to avoid redundant calculations.
4. Return the optimal day value that satisfies the bouquet requirement.

```cpp
class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        if ((long long)k * m > arr.size()) return -1;
        auto canMake = [&](int days) {
            int consecutive = 0, made = 0;
            for (int x : arr) {
                consecutive = (x <= days) ? consecutive + 1 : 0;
                if (consecutive == k) {
                    made++;
                    consecutive = 0;
                }
            }
            return made >= m;
        };
        
        int lo = 1, hi = 1e9, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMake(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log max(arr)) - Binary search with linear validation
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Clean separation of concerns with lambda function
* Handles edge cases efficiently
* More readable binary search implementation

## 📊 **3️⃣ Sliding Window Optimization**

### 💡 Algorithm Steps:

1. For each potential day, use sliding window to count valid bouquets.
2. Maintain window of consecutive bloomed flowers.
3. Count complete bouquets when window size reaches k.
4. Reset window when encountering non-bloomed flower.

```cpp
class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n = arr.size();
        if ((long long)k * m > n) return -1;
        
        int left = 1, right = *max_element(arr.begin(), arr.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int bouquets = 0, consecutive = 0;
            
            for (int i = 0; i < n; i++) {
                if (arr[i] <= mid) {
                    consecutive++;
                    if (consecutive == k) {
                        bouquets++;
                        consecutive = 0;
                    }
                } else {
                    consecutive = 0;
                }
            }
            
            if (bouquets >= m) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log max(arr)) - Optimized binary search
* **Auxiliary Space:** 💾 O(1) - In-place computation

### ✅ **Why This Approach?**

* Efficient sliding window technique
* Minimizes redundant computations
* Clear logic flow for bouquet counting

## 📊 **4️⃣ Range-Based Binary Search**

### 💡 Algorithm Steps:

1. Set search range from minimum to maximum bloom day.
2. For each mid value, simulate bouquet formation process.
3. Use greedy approach to form bouquets from left to right.
4. Adjust search range based on feasibility of current mid value.

```cpp
class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n = arr.size();
        if (k > n || (long long)k * m > n) return -1;
        
        int minDay = *min_element(arr.begin(), arr.end());
        int maxDay = *max_element(arr.begin(), arr.end());
        
        while (minDay < maxDay) {
            int midDay = minDay + (maxDay - minDay) / 2;
            int bouquets = 0, flowers = 0;
            
            for (int day : arr) {
                if (day <= midDay) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }
            
            if (bouquets >= m) {
                maxDay = midDay;
            } else {
                minDay = midDay + 1;
            }
        }
        
        return minDay;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log(max-min)) - Optimized range binary search
* **Auxiliary Space:** 💾 O(1) - Constant extra space

### ✅ **Why This Approach?**

* Efficient range optimization
* Handles all edge cases properly
* Minimizes search iterations

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Inline Binary Search**       | 🟢 O(n log max)        | 🟢 O(1)                 | 🚀 Compact and efficient         | 🔧 Less readable                     |
| 🔍 **Lambda-Based**               | 🟢 O(n log max)        | 🟢 O(1)                 | 📖 Clean separation               | 💾 Function call overhead            |
| 📊 **Sliding Window**             | 🟢 O(n log max)        | 🟢 O(1)                 | 🎯 Clear logic flow               | 🐌 Similar performance               |
| 🔄 **Range Optimization**         | 🟢 O(n log(max-min))   | 🟢 O(1)                 | ⭐ Better range bounds            | 🔧 Complex edge handling             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive Programming**                        | 🥇 **Inline Binary Search**          | ★★★★★                     |
| 📖 **Code Readability**                              | 🥈 **Lambda-Based**                  | ★★★★☆                     |
| 🔧 **Interview Discussion**                          | 🥉 **Sliding Window**                | ★★★★☆                     |
| 🎯 **Large Range Optimization**                      | 🏅 **Range Optimization**            | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minDaysBloom(int[] arr, int k, int m) {
        if ((long) k * m > arr.length) return -1;
        int l = Arrays.stream(arr).min().getAsInt();
        int r = Arrays.stream(arr).max().getAsInt();
        while (l < r) {
            int mid = l + (r - l) / 2;
            int flowers = 0, bouquets = 0;
            for (int bloom : arr) {
                if (bloom <= mid) {
                    if (++flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else flowers = 0;
            }
            if (bouquets >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minDaysBloom(self, arr, k, m):
        if k * m > len(arr): return -1
        l, r = min(arr), max(arr)
        while l < r:
            mid = (l + r) // 2
            flowers = bouquets = 0
            for bloom in arr:
                if bloom <= mid:
                    flowers += 1
                    if flowers == k:
                        bouquets += 1
                        flowers = 0
                else:
                    flowers = 0
            if bouquets >= m:
                r = mid
            else:
                l = mid + 1
        return l
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
