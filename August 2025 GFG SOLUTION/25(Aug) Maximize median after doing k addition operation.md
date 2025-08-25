---
title: "🔢 Maximize Median After K Addition Operations | GFG Solution 🔍"
keywords🏷️: ["🔢 maximize median", "🔍 binary search", "📊 median optimization", "📈 greedy approach", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximize Median After K Addition Operations problem: find maximum possible median after performing at most k increment operations using binary search and greedy strategy. 🚀"
date: 📅 2025-08-25
---

# *25. Maximize Median After K Addition Operations*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximize-median-after-doing-k-addition-operation/1)

## **🧩 Problem Description**

You are given an array `arr[]` consisting of positive integers and an integer `k`. You are allowed to perform at most `k` operations, where in each operation, you can increment any one element of the array by 1. Determine the **maximum possible median** of the array that can be achieved after performing at most `k` such operations.

**Note:** The median of an array is defined as the middle element when the array (after sorting) has an odd size, or the average of the two middle elements when the array (after sorting) has an even size.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 3, 4, 5], k = 3
Output: 5
Explanation: We can add +2 to the second element and +1 to the third element to get the array [1, 5, 5, 5]. 
After sorting, the array remains [1, 5, 5, 5]. Since the length is even, the median is (5 + 5) / 2 = 5.
```

### Example 2

```cpp
Input: arr[] = [1, 3, 6, 4, 2], k = 10
Output: 7
Explanation: After applying operations optimally, we can transform the array to [1, 3, 7, 7, 7] (one possible way). 
Sorted array becomes [1, 3, 7, 7, 7]. Since the length is odd, the median is the middle element 7.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i], k \le 10^9$

## **✅ My Approach**

The optimal approach uses **Binary Search** on the answer combined with a **Greedy Strategy** to check if a target median is achievable:

### **Binary Search + Greedy Validation**

1. **Key Insight:**
   * To maximize the median, we need to focus on elements that contribute to the median calculation.
   * For odd-length arrays: median is the middle element after sorting.
   * For even-length arrays: median is the average of two middle elements.

2. **Strategy:**
   * Sort the array first to identify median positions.
   * Use binary search on possible median values.
   * For each candidate median, greedily check if it's achievable with at most `k` operations.

3. **Validation Logic:**
   * **Odd length (n):** Elements from position `n/2` onwards must be ≥ target median.
   * **Even length (n):** Both elements at positions `n/2-1` and `n/2` must contribute to achieve target median average.

4. **Greedy Check:**
   * Calculate minimum operations needed to achieve target median.
   * If operations ≤ k, the target is achievable.

5. **Binary Search Bounds:**
   * Lower bound: Current median value
   * Upper bound: Current median + k (maximum possible increase)

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n + n log k), where n is the size of the array. The sorting takes O(n log n) and binary search with validation takes O(n log k) as we perform at most O(log k) iterations, each requiring O(n) time for validation.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables, excluding the space used for sorting which is typically O(log n) for quicksort.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool canAchieve(vector<int>& arr, int target, int k) {
        int n = arr.size();
        long long ops = 0;
        
        if (n % 2 == 1) {
            for (int i = n/2; i < n; i++) {
                if (arr[i] < target) {
                    ops += target - arr[i];
                    if (ops > k) return false;
                }
            }
        } else {
            long long medianSum = arr[n/2-1] + arr[n/2];
            if (2LL * target > medianSum) {
                ops += 2LL * target - medianSum;
                if (ops > k) return false;
            }
            for (int i = n/2+1; i < n; i++) {
                if (arr[i] < target) {
                    ops += target - arr[i];
                    if (ops > k) return false;
                }
            }
        }
        return true;
    }
    
    int maximizeMedian(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int l = (n % 2 == 1) ? arr[n/2] : (arr[n/2-1] + arr[n/2]) / 2;
        int r = l + k;
        int ans = l;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canAchieve(arr, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Lambda Function Optimization**

### 💡 Algorithm Steps:

1. Use lambda function for cleaner code organization
2. Handle odd/even cases with proper median calculation logic
3. Early termination for efficiency in operations counting
4. Optimized binary search bounds

```cpp
class Solution {
public:
    int maximizeMedian(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        auto canAchieve = [&](int target) -> bool {
            long long ops = 0;
            if (n % 2 == 1) {
                for (int i = n/2; i < n; i++) {
                    ops += max(0, target - arr[i]);
                    if (ops > k) return false;
                }
            } else {
                ops += max(0LL, 2LL * target - (long long)arr[n/2-1] - arr[n/2]);
                if (ops > k) return false;
                for (int i = n/2+1; i < n; i++) {
                    ops += max(0, target - arr[i]);
                    if (ops > k) return false;
                }
            }
            return true;
        };
        
        int l = (n % 2 == 1) ? arr[n/2] : (arr[n/2-1] + arr[n/2]) / 2;
        int r = l + k;
        int ans = l;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canAchieve(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + n log k)
* **Auxiliary Space:** 💾 O(1) - Lambda function uses captured variables

### ✅ **Why This Approach?**

* Compact and modern C++ style
* Lambda function keeps validation logic contained
* Same time complexity with cleaner code structure

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Binary Search + Helper**     | 🟢 O(n log k)          | 🟢 O(1)                 | 🚀 Optimal, clear separation      | 🔧 Multiple function calls           |
| ⚡ **Lambda Optimization**        | 🟢 O(n log k)          | 🟢 O(1)                 | 📖 Compact, modern C++            | 🔄 Lambda complexity                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production Code, Large Inputs**                 | 🥇 **Binary Search + Helper**        | ★★★★★                     |
| ⚡ **Competitive Programming**                       | 🥈 **Lambda Optimization**           | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maximizeMedian(int[] arr, int k) {
        Arrays.sort(arr);
        int n = arr.length;
        int left = (n % 2 == 1) ? arr[n/2] : (arr[n/2-1] + arr[n/2]) / 2;
        int right = left + k;
        int result = left;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAchieve(arr, mid, k)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    private boolean canAchieve(int[] arr, int target, int k) {
        int n = arr.length;
        long ops = 0;
        
        if (n % 2 == 1) {
            for (int i = n/2; i < n; i++) {
                if (arr[i] < target) {
                    ops += target - arr[i];
                    if (ops > k) return false;
                }
            }
        } else {
            long medianSum = (long)arr[n/2-1] + arr[n/2];
            if (2L * target > medianSum) {
                ops += 2L * target - medianSum;
                if (ops > k) return false;
            }
            for (int i = n/2+1; i < n; i++) {
                if (arr[i] < target) {
                    ops += target - arr[i];
                    if (ops > k) return false;
                }
            }
        }
        return true;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maximizeMedian(self, arr, k):
        arr.sort()
        n = len(arr)
        left = arr[n//2] if n % 2 == 1 else (arr[n//2-1] + arr[n//2]) // 2
        right = left + k
        result = left
        
        while left <= right:
            mid = left + (right - left) // 2
            if self.canAchieve(arr, mid, k):
                result = mid
                left = mid + 1
            else:
                right = mid - 1
        return result
    
    def canAchieve(self, arr, target, k):
        n = len(arr)
        ops = 0
        
        if n % 2 == 1:
            for i in range(n//2, n):
                if arr[i] < target:
                    ops += target - arr[i]
                    if ops > k:
                        return False
        else:
            median_sum = arr[n//2-1] + arr[n//2]
            if 2 * target > median_sum:
                ops += 2 * target - median_sum
                if ops > k:
                    return False
            for i in range(n//2+1, n):
                if arr[i] < target:
                    ops += target - arr[i]
                    if ops > k:
                        return False
        return True
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


