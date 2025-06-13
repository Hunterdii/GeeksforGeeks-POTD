---
title: "🍌 Koko Eating Bananas | GFG Solution 🚀"
keywords🏷️: ["🍌 koko bananas", "🔍 binary search", "⏰ minimum speed", "📊 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA", "🐒 gfg bananas"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Koko Eating Bananas problem: find minimum eating speed to finish all banana piles within k hours using binary search. 🚀"
date: 📅 2025-06-13
---

# *13. Koko Eating Bananas*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/koko-eating-bananas/1)

## **🧩 Problem Description**

Koko is given an array `arr[]`, where each element represents a pile of bananas. She has exactly `k` hours to eat all the bananas.

Each hour, Koko can choose one pile and eat up to `s` bananas from it:
- If the pile has at least `s` bananas, she eats exactly `s` bananas
- If the pile has fewer than `s` bananas, she eats the entire pile in that hour
- Koko can only eat from one pile per hour

Your task is to find the **minimum value of s** (bananas per hour) such that Koko can finish all the piles within `k` hours.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [5, 10, 3], k = 4
Output: 5
Explanation: Koko eats at least 5 bananas per hour to finish all piles within 4 hours, 
as she can consume each pile in 1 + 2 + 1 = 4 hours.
```

### Example 2

```cpp
Input: arr[] = [5, 10, 15, 20], k = 7
Output: 10
Explanation: At 10 bananas per hour, Koko finishes in 6 hours (1+1+2+2), 
just within the limit 7.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^6$
* $\text{arr.size()} \le k \le 10^6$

## **✅ My Approach**

The optimal approach uses **Binary Search** on the answer space to find the minimum eating speed:

### **Binary Search on Speed**

1. **Define Search Space:**
   * Minimum speed: `1` banana per hour (lowest possible)
   * Maximum speed: `max(arr)` bananas per hour (eat largest pile in 1 hour)

2. **Binary Search Logic:**
   * For each mid speed, calculate total hours needed
   * If hours ≤ k, try smaller speed (search left half)
   * If hours > k, need faster speed (search right half)

3. **Calculate Hours for Given Speed:**
   * For each pile of size `pile`, hours needed = `⌈pile/speed⌉`
   * Use ceiling division: `(pile + speed - 1) / speed`

4. **Optimization:**
   * The answer is the minimum speed that allows finishing within k hours

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × log(max_pile)), where n is the array size. Binary search takes O(log(max_pile)) iterations, and each iteration calculates hours in O(n) time.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for variables (excluding the input array).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        int lo = 1, hi = *max_element(arr.begin(), arr.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int hours = 0;
            for (int pile : arr) {
                hours += (pile + mid - 1) / mid;
            }
            if (hours <= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Binary Search with Early Termination (Optimized Division)**

### 💡 Algorithm Steps:

1. Create a helper function to check if a given speed is valid.
2. Break early if the hour limit is crossed during calculation.
3. Use ceiling division formula directly for efficiency.

```cpp
class Solution {
  public:
    bool canEat(vector<int>& arr, int speed, int k) {
        long hours = 0;
        for (int pile : arr) {
            hours += (pile + speed - 1) / speed;
            if (hours > k) return false; 
        }
        return true;
    }

    int kokoEat(vector<int>& arr, int k) {
        int lo = 1, hi = *max_element(arr.begin(), arr.end());
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canEat(arr, mid, k)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × log(max_pile))
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Fast due to early stopping when hours exceed k.
* Clean separation of logic with `canEat` helper function.
* Optimal and practical for large input sizes.

## 📊 **3️⃣ Binary Search + Prefix Optimization**

### 💡 Algorithm Steps:

1. Sort the piles to improve data locality.
2. Enable early termination more effectively with sorted order.
3. Use the same binary search logic with optimized computation.

```cpp
class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int lo = 1, hi = arr.back();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long hours = 0;
            bool valid = true;

            for (int pile : arr) {
                hours += (pile + mid - 1) / mid;
                if (hours > k) {
                    valid = false;
                    break; 
                }
            }

            if (valid)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + n × log(max_pile))
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Sorting may reduce computation overhead via early skips.
* Useful when `k` is small or `arr` has large variance.
* Better cache locality for large arrays.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                | ⏱️ **Time Complexity**                  | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ------------------------------ | --------------------------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Basic Binary Search**     | 🟢 O(n × log(max_pile))                 | 🟢 O(1)                 | ⚡ Simple and reliable             | 🐢 No early exit on overflow         |
| 🚀 **Early Termination**       | 🟢 O(n × log(max_pile))                 | 🟢 O(1)                 | 🔥 Fastest due to early exit      | 📝 Slightly more verbose             |
| 📊 **Prefix Optimization**     | 🟡 O(n log n + n × log(max_pile))       | 🟢 O(1)                 | 🎯 Best for uneven distribution   | ⚠️ Sorting overhead                   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ Large inputs, performance critical              | 🥇 **Early Termination**        | ★★★★★                     |
| 🔧 Balanced input, predictable distribution       | 🥈 **Basic Binary Search**      | ★★★★☆                     |
| 📈 Data benefits from ordering                    | 🥉 **Prefix Optimization**      | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int kokoEat(int[] arr, int k) {
        int lo = 1, hi = 0;
        for (int pile : arr) hi = Math.max(hi, pile);
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int hours = 0;
            for (int pile : arr) {
                hours += (pile + mid - 1) / mid;
            }
            if (hours <= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def kokoEat(self, arr, k):
        lo, hi = 1, max(arr)
        while lo < hi:
            mid = (lo + hi) // 2
            hours = sum((pile + mid - 1) // mid for pile in arr)
            if hours <= k:
                hi = mid
            else:
                lo = mid + 1
        return lo
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
