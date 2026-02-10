---
title: "🍌 Koko Eating Bananas | GFG Solution 🔍"
keywords🏷️: ["🍌 koko eating bananas", "🔍 binary search", "📈 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Koko Eating Bananas problem: find minimum eating speed using binary search optimization technique. 🚀"
date: 📅 2025-02-10
---

# *10. Koko Eating Bananas*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/koko-eating-bananas/1)

## **🧩 Problem Description**

Koko is given an array `arr[]`, where each element represents a pile of bananas. She has exactly `k` hours to eat all the bananas.

Each hour, Koko can choose one pile and eat up to `s` bananas from it:
- If the pile has at least `s` bananas, she eats exactly `s` bananas.
- If the pile has fewer than `s` bananas, she eats the entire pile in that hour.
- Koko can only eat from one pile per hour.

Your task is to find the **minimum value of `s`** (bananas per hour) such that Koko can finish all the piles within `k` hours.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [5, 10, 3], k = 4
Output: 5
Explanation: If Koko eats at the rate of 5 bananas per hour:
- First pile of 5 bananas will be finished in 1 hour.
- Second pile of 10 bananas will be finished in 2 hours.
- Third pile of 3 bananas will be finished in 1 hour.
Therefore, Koko can finish all piles in 1 + 2 + 1 = 4 hours.
```

### Example 2

```cpp
Input: arr[] = [5, 10, 15, 20], k = 7
Output: 10
Explanation: If Koko eats at the rate of 10 bananas per hour, it will take 6 hours 
to finish all the piles: ⌈5/10⌉ + ⌈10/10⌉ + ⌈15/10⌉ + ⌈20/10⌉ = 1 + 1 + 2 + 2 = 6 hours.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le k \le 10^6$
* $1 \le \text{arr}[i] \le 10^6$

## **✅ My Approach**

The optimal approach uses **Binary Search** on the answer space to efficiently find the minimum eating speed:

### **Binary Search on Answer**

1. **Define Search Space:**
   * Minimum possible speed: `1` banana per hour (slowest)
   * Maximum possible speed: `max(arr)` bananas per hour (fastest - eating largest pile in 1 hour)

2. **Binary Search Logic:**
   * For each candidate speed `mid`, calculate total hours needed to eat all bananas
   * Hours for each pile = ⌈pile_size / mid⌉ = `(pile_size + mid - 1) / mid`
   * Sum up hours for all piles

3. **Decision Making:**
   * If total hours ≤ k: This speed works, but try to minimize further (search left half)
   * If total hours > k: Speed too slow, need faster speed (search right half)

4. **Update Answer:**
   * Whenever we find a valid speed, store it as potential answer
   * Continue searching for minimum valid speed

5. **Termination:**
   * When search space exhausted, return the minimum valid speed found

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n * log m), where n is the size of the array and m is the maximum element in the array. Binary search runs in O(log m) iterations, and for each iteration, we traverse the entire array in O(n) to calculate total hours needed.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like pointers, mid value, and hour counter.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        int l = 1, r = *max_element(arr.begin(), arr.end()), ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2, h = 0;
            for (int x : arr) h += (x + m - 1) / m;
            if (h <= k) ans = m, r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized Binary Search with Range**

### 💡 Algorithm Steps:

1. Calculate minimum possible speed using total bananas and hours: `⌈total_bananas / k⌉`
2. Set upper bound as maximum pile to narrow search space
3. Use binary search with optimized mid calculation
4. Track answer and minimize search range efficiently without storing intermediate answer

```cpp
class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        long long sum = 0;
        int mx = 0;
        for (int x : arr) sum += x, mx = max(mx, x);
        int l = (sum + k - 1) / k, r = mx;
        while (l < r) {
            int m = l + (r - l) / 2;
            long long h = 0;
            for (int x : arr) h += (x + m - 1) / m;
            if (h <= k) r = m;
            else l = m + 1;
        }
        return l;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * log m) - Binary search with optimized bounds
* **Auxiliary Space:** 💾 O(1) - Constant space for variables

### ✅ **Why This Approach?**

* Tighter lower bound reduces search iterations
* Avoids unnecessary checks in lower range
* Better average case performance
* Cleaner binary search template (no separate ans variable)

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Standard Binary Search**     | 🟢 O(n * log m)        | 🟢 O(1)                 | 🚀 Clean & straightforward        | 🔧 May check unnecessary lower values |
| ⚡ **Optimized Range**            | 🟢 O(n * log m)        | 🟢 O(1)                 | ⭐ Better lower bound, fewer iterations | 🔧 Extra calculation for sum needed   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Simplicity and readability**                     | 🥇 **Standard Binary Search**        | ★★★★★                     |
| 🎯 **Large datasets with tight time limits**          | 🥈 **Optimized Range**               | ★★★★★                     |
| ⚡ **Competitive programming**                        | 🥈 **Optimized Range**               | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int kokoEat(int[] arr, int k) {
        int l = 1, r = 0, ans = 0;
        for (int x : arr) r = Math.max(r, x);
        ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2, h = 0;
            for (int x : arr) h += (x + m - 1) / m;
            if (h <= k) { ans = m; r = m - 1; }
            else l = m + 1;
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def kokoEat(self, arr, k):
        l, r = 1, max(arr)
        ans = r
        while l <= r:
            m = (l + r) // 2
            h = sum((x + m - 1) // m for x in arr)
            if h <= k:
                ans = m
                r = m - 1
            else:
                l = m + 1
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

---
