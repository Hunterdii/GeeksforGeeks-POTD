---
title: "🎯 Happiest Triplet | GFG Solution 🔍"
keywords🏷️: ["🎯 triplet problem", "🔍 three pointers", "📊 sorting", "📈 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Happiest Triplet problem: find the triplet with minimum difference across three arrays using three-pointer technique. 🚀"
date: 📅 2025-02-06
---

# *06. Happiest Triplet*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/happiest-triplet2921/1)

## **🧩 Problem Description**

You are given three arrays `a[]`, `b[]`, `c[]` of the same size. Find a triplet such that **(maximum - minimum)** in that triplet is the **minimum** of all the triplets. A triplet should be selected so that it should have one number from each of the three given arrays. This triplet is the happiest among all the possible triplets. Print the triplet in **decreasing order**.

**Note:** If there are 2 or more smallest difference triplets, then the one with the **smallest sum** of its elements should be displayed.

## **📘 Examples**

### Example 1

```cpp
Input: a[] = [5, 2, 8], b[] = [10, 7, 12], c[] = [9, 14, 6]
Output: [7, 6, 5]
Explanation: The triplet [5, 7, 6] has difference (maximum - minimum) = (7 - 5) = 2 
which is minimum of all triplets.
```

### Example 2

```cpp
Input: a[] = [15, 12, 18, 9], b[] = [10, 17, 13, 8], c[] = [14, 16, 11, 5]
Output: [11, 10, 9]
Explanation: Multiple triplets have the same minimum difference, and among them 
[11, 10, 9] has the smallest sum, so it is chosen.
```

## **🔒 Constraints**

* $1 \le \text{a.size()}, \text{b.size()}, \text{c.size()} \le 10^5$
* $1 \le \text{a}[i], \text{b}[i], \text{c}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses the **Three Pointers + Sorting** technique to efficiently find the triplet with minimum difference:

### **Three Pointers Algorithm**

1. **Sort All Arrays:**
   * Sort arrays `a[]`, `b[]`, and `c[]` in ascending order.
   * This allows us to use greedy pointer movement strategy.

2. **Initialize Pointers:**
   * Use three pointers `i`, `j`, `k` starting at index 0 for arrays `a`, `b`, `c` respectively.
   * Track `minDiff` to store the minimum difference found.
   * Store result triplet in decreasing order.

3. **Calculate Triplet Difference:**
   * For current triplet `(a[i], b[j], c[k])`, find minimum and maximum values.
   * Calculate difference: `maxVal - minVal`.
   * Also calculate middle value: `sum - maxVal - minVal`.

4. **Update Result:**
   * If current difference is smaller than `minDiff`, update result.
   * Store triplet in decreasing order: `[maxVal, midVal, minVal]`.

5. **Move Pointer:**
   * To minimize difference, increment the pointer pointing to the smallest value.
   * This greedy approach brings the minimum closer to maximum.

6. **Continue Until End:**
   * Repeat until any pointer reaches the end of its array.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n + m log m + p log p), where n, m, p are the sizes of arrays a, b, c respectively. Sorting dominates the time complexity, while the three-pointer traversal takes O(n + m + p) time as each pointer moves at most once through its array.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables. The sorting operation may use O(log n) space for recursion stack, but this is not counted as auxiliary space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int i = 0, j = 0, k = 0, diff = INT_MAX;
        vector<int> res(3);
        while (i < a.size() && j < b.size() && k < c.size()) {
            int minVal = min({a[i], b[j], c[k]});
            int maxVal = max({a[i], b[j], c[k]});
            int midVal = a[i] + b[j] + c[k] - minVal - maxVal;
            if (maxVal - minVal < diff) {
                diff = maxVal - minVal;
                res = {maxVal, midVal, minVal};
            }
            if (minVal == a[i]) i++;
            else if (minVal == b[j]) j++;
            else k++;
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Sum-Aware Three Pointer Approach**

### 💡 Algorithm Steps:

1. Sort all three arrays to enable ordered traversal.
2. Use three pointers initialized at the start of each array.
3. For each triplet, calculate both difference and sum.
4. Update result if difference is smaller, or if difference is equal but sum is smaller.
5. Move the pointer pointing to minimum value forward.

```cpp
class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int i = 0, j = 0, k = 0, minDiff = INT_MAX, minSum = INT_MAX;
        vector<int> res(3);
        while (i < a.size() && j < b.size() && k < c.size()) {
            int minVal = min({a[i], b[j], c[k]});
            int maxVal = max({a[i], b[j], c[k]});
            int midVal = a[i] + b[j] + c[k] - minVal - maxVal;
            int currDiff = maxVal - minVal;
            int currSum = a[i] + b[j] + c[k];
            if (currDiff < minDiff || (currDiff == minDiff && currSum < minSum)) {
                minDiff = currDiff;
                minSum = currSum;
                res = {maxVal, midVal, minVal};
            }
            if (minVal == a[i]) i++;
            else if (minVal == b[j]) j++;
            else k++;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + m log m + p log p) - Sorting dominates
* **Auxiliary Space:** 💾 O(1) - Constant extra space

### ✅ **Why This Approach?**

* Handles tie-breaking by sum correctly
* Considers multiple criteria for optimization
* More accurate for edge cases with equal differences

## 📊 **3️⃣ Explicit Variable Tracking**

### 💡 Algorithm Steps:

1. Sort input arrays for efficient pointer movement.
2. Track best difference and corresponding triplet separately.
3. Calculate all three values (min, mid, max) explicitly.
4. Update result when better triplet is found.
5. Advance pointer of minimum element.

```cpp
class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int p = 0, q = 0, r = 0, best = INT_MAX;
        int resMax, resMid, resMin;
        while (p < a.size() && q < b.size() && r < c.size()) {
            int lo = min({a[p], b[q], c[r]});
            int hi = max({a[p], b[q], c[r]});
            int mid = a[p] + b[q] + c[r] - lo - hi;
            if (hi - lo < best) {
                best = hi - lo;
                resMax = hi;
                resMid = mid;
                resMin = lo;
            }
            if (a[p] == lo) p++;
            else if (b[q] == lo) q++;
            else r++;
        }
        return {resMax, resMid, resMin};
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + m log m + p log p) - Sorting dominates
* **Auxiliary Space:** 💾 O(1) - Only scalar variables

### ✅ **Why This Approach?**

* Clear variable naming for readability
* Explicit tracking of all three values
* Easy to debug and understand

## 📊 **4️⃣ Compact Implementation**

### 💡 Algorithm Steps:

1. Sort all arrays for ordered processing.
2. Use minimal variables for space efficiency.
3. Compute difference and update result in single pass.
4. Increment smallest element's pointer for convergence.

```cpp
class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        int i = 0, j = 0, k = 0, d = INT_MAX;
        int x, y, z;
        while (i < a.size() && j < b.size() && k < c.size()) {
            int mn = min({a[i], b[j], c[k]});
            int mx = max({a[i], b[j], c[k]});
            if (mx - mn < d) {
                d = mx - mn;
                x = mx;
                y = a[i] + b[j] + c[k] - mx - mn;
                z = mn;
            }
            if (a[i] == mn) i++;
            else if (b[j] == mn) j++;
            else k++;
        }
        return {x, y, z};
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + m log m + p log p) - Sorting operation dominates
* **Auxiliary Space:** 💾 O(1) - Minimal variable usage

### ✅ **Why This Approach?**

* Most compact code implementation
* Efficient memory usage
* Optimal for competitive programming

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Main Approach**              | 🟢 O(n log n)          | 🟢 O(1)                 | 🚀 Clean and optimal              | 🔧 Doesn't handle sum tie-breaking    |
| 🔍 **Sum-Aware**                  | 🟢 O(n log n)          | 🟢 O(1)                 | 📖 Handles all edge cases         | 🔄 Slightly more comparisons          |
| 📊 **Explicit Variables**         | 🟢 O(n log n)          | 🟢 O(1)                 | 🎯 Very readable                  | 🐌 More variable declarations         |
| 🔄 **Compact**                    | 🟢 O(n log n)          | 🟢 O(1)                 | ⭐ Minimal code size              | 🔧 Less readable variable names       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **All test cases including ties**                  | 🥇 **Sum-Aware**                     | ★★★★★                     |
| 📖 **Code readability priority**                      | 🥈 **Explicit Variables**            | ★★★★★                     |
| 🔧 **Competitive programming speed**                  | 🥉 **Compact**                       | ★★★★☆                     |
| 🎯 **Basic implementation**                           | 🏅 **Main Approach**                 | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int[] smallestDiff(int a[], int b[], int c[]) {
        Arrays.sort(a);
        Arrays.sort(b);
        Arrays.sort(c);
        int i = 0, j = 0, k = 0, diff = Integer.MAX_VALUE;
        int[] res = new int[3];
        while (i < a.length && j < b.length && k < c.length) {
            int minVal = Math.min(a[i], Math.min(b[j], c[k]));
            int maxVal = Math.max(a[i], Math.max(b[j], c[k]));
            int midVal = a[i] + b[j] + c[k] - minVal - maxVal;
            if (maxVal - minVal < diff) {
                diff = maxVal - minVal;
                res[0] = maxVal;
                res[1] = midVal;
                res[2] = minVal;
            }
            if (minVal == a[i]) i++;
            else if (minVal == b[j]) j++;
            else k++;
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def smallestDiff(self, a, b, c):
        a.sort()
        b.sort()
        c.sort()
        i = j = k = 0
        diff = float('inf')
        res = [0, 0, 0]
        while i < len(a) and j < len(b) and k < len(c):
            minVal = min(a[i], b[j], c[k])
            maxVal = max(a[i], b[j], c[k])
            midVal = a[i] + b[j] + c[k] - minVal - maxVal
            if maxVal - minVal < diff:
                diff = maxVal - minVal
                res = [maxVal, midVal, minVal]
            if minVal == a[i]: i += 1
            elif minVal == b[j]: j += 1
            else: k += 1
        return res
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


