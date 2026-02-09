---
title: "🔢 Maximum Product Subarray | GFG Solution 🔍"
keywords🏷️: ["🔢 maximum product", "🔍 dynamic programming", "📍 kadane's algorithm", "📈 subarray", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum Product Subarray problem: find the maximum product of any subarray using dynamic programming technique. 🚀"
date: 📅 2025-02-08
---

# *08. Maximum Product Subarray*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1)

## **🧩 Problem Description**

Given an array `arr[]` that contains positive and negative integers (may contain 0 as well). Find the **maximum product** that we can get in a subarray of `arr[]`.

A subarray is a contiguous sequence of elements within an array. The goal is to find the maximum possible product of elements in any such subarray.

**Note:** It is guaranteed that the answer fits in a 32-bit integer.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.
```

### Example 2

```cpp
Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.
```

### Example 3

```cpp
Input: arr[] = [2, 3, 4]
Output: 24
Explanation: For an array with all positive elements, the result is product of all elements.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $-10 \le \text{arr}[i] \le 10$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming with Max-Min Tracking** to efficiently handle both positive and negative numbers:

### **Max-Min Tracking (Modified Kadane's Algorithm)**

1. **Initialize Variables:**
   * `mx` = maximum product ending at current position (initialized to `arr[0]`)
   * `mn` = minimum product ending at current position (initialized to `arr[0]`)
   * `r` = global maximum product result (initialized to `arr[0]`)

2. **Key Insight:**
   * We need to track both maximum AND minimum products because:
     - A negative number can turn the minimum product into maximum
     - A negative number can turn the maximum product into minimum
   * Example: If `mn = -10` and current element is `-3`, then `-10 * -3 = 30` becomes the new maximum

3. **Iterate Through Array:**
   * For each element `arr[i]` (starting from index 1):
     - Calculate `a = mx * arr[i]` (product with previous max)
     - Calculate `b = mn * arr[i]` (product with previous min)
     - Update `mx = max(a, b, arr[i])` (either extend previous products or start fresh)
     - Update `mn = min(a, b, arr[i])` (track minimum for future negative multiplications)
     - Update global result: `r = max(r, mx)`

4. **Handle Edge Cases:**
   * **Zero elements**: When we encounter 0, both max and min reset to 0, and starting fresh from next element handles it naturally
   * **All negatives**: The min-max tracking ensures correct handling
   * **Mixed signs**: The dual tracking captures all possibilities

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We traverse the array exactly once, performing constant-time operations at each step.
* **Expected Auxiliary Space Complexity:** O(1), as we only use three variables (mx, mn, r) regardless of input size, requiring constant additional space.

## **🧑‍💻 Code (C)**

```c
int maxProduct(int arr[], int n) {
    int mx = arr[0], mn = arr[0], r = arr[0], a, b;
    for (int i = 1; i < n; i++) {
        a = mx * arr[i]; b = mn * arr[i];
        mx = a > b ? (a > arr[i] ? a : arr[i]) : (b > arr[i] ? b : arr[i]);
        mn = a < b ? (a < arr[i] ? a : arr[i]) : (b < arr[i] ? b : arr[i]);
        r = r > mx ? r : mx;
    }
    return r;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int mx = arr[0], mn = arr[0], r = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int a = mx * arr[i], b = mn * arr[i];
            mx = max({a, b, arr[i]});
            mn = min({a, b, arr[i]});
            r = max(r, mx);
        }
        return r;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pass Traversal**

### 💡 Algorithm Steps:

1. Traverse array left to right maintaining cumulative product.
2. Reset product to zero when product becomes zero.
3. Traverse array right to left with the same logic.
4. Track maximum product found in both directions.

```cpp
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size(), res = arr[0], prod = 0;
        for (int i = 0; i < n; i++) {
            prod = prod ? prod * arr[i] : arr[i];
            res = max(res, prod);
        }
        prod = 0;
        for (int i = n - 1; i >= 0; i--) {
            prod = prod ? prod * arr[i] : arr[i];
            res = max(res, prod);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two linear passes through the array
* **Auxiliary Space:** 💾 O(1) - Constant space complexity

### ✅ **Why This Approach?**

* Handles negative numbers naturally with bidirectional scan
* Simpler logic than tracking min and max simultaneously
* Auto-resets on encountering zeros

## 📊 **3️⃣ Prefix-Suffix Product**

### 💡 Algorithm Steps:

1. Calculate prefix product from left and suffix product from right simultaneously.
2. Reset prefix or suffix to 1 when encountering zero.
3. Track maximum value from both prefix and suffix at each step.
4. Return the maximum product found in single pass.

```cpp
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size(), pref = 1, suff = 1, res = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (!pref) pref = 1;
            if (!suff) suff = 1;
            pref *= arr[i];
            suff *= arr[n - 1 - i];
            res = max(res, max(pref, suff));
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with dual direction processing
* **Auxiliary Space:** 💾 O(1) - Only tracking prefix and suffix

### ✅ **Why This Approach?**

* Single pass efficiency
* Symmetric processing from both ends
* Clean zero handling with reset mechanism

## 📊 **4️⃣ Modified Kadane's Algorithm with Swap**

### 💡 Algorithm Steps:

1. Maintain three variables: current max, current min, and global max.
2. For each element, calculate new max as max of current element, max*element, min*element.
3. Calculate new min similarly to handle negative number transitions.
4. Update global maximum at each step.

```cpp
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int currMax = arr[0], currMin = arr[0], res = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < 0) swap(currMax, currMin);
            currMax = max(arr[i], currMax * arr[i]);
            currMin = min(arr[i], currMin * arr[i]);
            res = max(res, currMax);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with swap on negatives
* **Auxiliary Space:** 💾 O(1) - Three variables for tracking

### ✅ **Why This Approach?**

* Extension of classic Kadane's algorithm
* Explicit swap logic for negative numbers
* Clear state transitions

## 📊 **5️⃣ Division-Based Approach**

### 💡 Algorithm Steps:

1. Calculate product of all non-zero elements.
2. Split array by zeros into segments.
3. For segments with odd negative count, try excluding first or last negative.
4. Return maximum product across all valid segments.

```cpp
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size(), prod = 1, res = INT_MIN, cnt = 0;
        for (int i = 0; i < n; i++) {
            prod *= arr[i];
            res = max(res, prod);
            if (!arr[i]) {
                prod = 1;
                cnt = 0;
            } else if (arr[i] < 0) {
                cnt++;
            }
        }
        prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            prod *= arr[i];
            res = max(res, prod);
            if (!arr[i]) prod = 1;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two passes for forward and backward
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Handles zeros and negatives effectively
* Double pass ensures optimal subarray selection
* Good for arrays with multiple zero partitions

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Max-Min Tracking**           | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal single pass           | 🔧 Tracks both max and min           |
| 📊 **Two-Pass Traversal**          | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Intuitive bidirectional       | 🔄 Requires two complete passes      |
| 🔄 **Prefix-Suffix**               | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Single pass efficiency        | 🧠 Simultaneous tracking needed      |
| 🎨 **Modified Kadane's**           | 🟢 O(n)                | 🟢 O(1)                 | 📚 Classic algorithm pattern     | 🔄 Explicit swap on negatives        |
| ➗ **Division-Based**              | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Handles zeros naturally       | 🔧 More complex logic flow           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Max-Min Tracking**              | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Two-Pass Traversal**            | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🥉 **Prefix-Suffix**                 | ★★★★★                     |
| 📚 **Algorithm pattern practice**                     | 🎖️ **Modified Kadane's**             | ★★★★☆                     |
| 🔢 **Many zeros in array**                            | 🏅 **Division-Based**                | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int maxProduct(int[] arr) {
        int mx = arr[0], mn = arr[0], r = arr[0];
        for (int i = 1; i < arr.length; i++) {
            int a = mx * arr[i], b = mn * arr[i];
            mx = Math.max(Math.max(a, b), arr[i]);
            mn = Math.min(Math.min(a, b), arr[i]);
            r = Math.max(r, mx);
        }
        return r;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxProduct(self, arr):
        mx = mn = r = arr[0]
        for i in range(1, len(arr)):
            a, b = mx * arr[i], mn * arr[i]
            mx = max(a, b, arr[i])
            mn = min(a, b, arr[i])
            r = max(r, mx)
        return r
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
