---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Arrays
---

# 🚀 _Day 10. Kadane's Algorithm_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/kadanes-algorithm-1587115620)

## 💡 **Problem Description:**

Given an integer array `arr[]`, you need to find and return the maximum sum possible from all the subarrays.

## 🔍 **Example Walkthrough:**

**Input:**  
`arr[] = [2, 3, -8, 7, -1, 2, 3]`  
**Output:**  
`11`

**Explanation:**  
The subarray `{7, -1, 2, 3}` has the largest sum, which is `11`.

**Input:**  
`arr[] = [-2, -4]`  
**Output:**  
`-2`

**Explanation:**  
The subarray `{-2}` has the largest sum `-2`.

### Constraints:

- $`1 ≤ arr.size() ≤ 10^5`$
- $`-10^9 ≤ arr[i] ≤ 10^4`$

## 🎯 **My Approach:**

1. **Kadane's Algorithm:**

   - The core idea is to iterate through the array and maintain two variables:
     - `maxh`: the maximum sum of the subarray that ends at the current index.
     - `maxf`: the global maximum sum encountered so far.
   - For each element:
     - Update `maxh` to be either the current element alone (starting a new subarray) or the current element added to the sum of the previous subarray.
     - Update `maxf` to store the larger value between the current `maxf` and `maxh`.
   - The result is the global maximum sum of a subarray in the array.

2. **Steps:**
   - Initialize `maxh` to 0 and `maxf` to a very small value.
   - Traverse the array to calculate the maximum sum of the subarrays.
   - Return `maxf` as the result, which will hold the largest sum of any subarray.

## 🕒 **Time and Auxiliary Space Complexity** 📝

- **Expected Time Complexity:** O(n), where `n` is the size of the array. The algorithm performs a single linear scan of the array.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

## 📝 **Solution Code**

## Code (C)

```c
#include <limits.h>

long long maxSubarraySum(int arr[], int n) {
    long long maxh = 0, maxf = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        maxh = (maxh + arr[i] > arr[i]) ? maxh + arr[i] : arr[i];
        maxf = (maxf > maxh) ? maxf : maxh;
    }

    return maxf;
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    long long maxSubarraySum(vector<int>& arr) {
        long long maxh = 0, maxf = LLONG_MIN;

        for (auto num : arr) {
            maxh = std::max(num + maxh, (long long)num);
            maxf = std::max(maxf, maxh);
        }

        return maxf;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches </h2></summary>

1.

```cpp
class Solution {
public:
    long long maxSubarraySum(vector<int>& arr) {
        int n = arr.size();
        long long maxh = 0, maxf = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            maxh = max((long long)arr[i], maxh + arr[i]);
            maxf = max(maxf, maxh);
        }

        return maxf;
    }
};
```

2.

```cpp
class Solution {
public:
    long long maxSubarraySum(vector<int>& arr) {
        long long maxh = 0, maxf = LLONG_MIN;

        for (int num : arr) {
            maxh = max((long long)num, maxh + num);
            maxf = max(maxf, maxh);
        }

        return maxf;
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    public long maxSubarraySum(int[] arr) {
        long maxh = 0, maxf = Long.MIN_VALUE;

        for (int num : arr) {
            maxh = Math.max(num, maxh + num);
            maxf = Math.max(maxf, maxh);
        }

        return maxf;
    }
}
```

## Code (Python)

```python
class Solution:
    def maxSubArraySum(self, arr):
        maxh = 0
        maxf = float('-inf')

        for num in arr:
            maxh = max(num, maxh + num)
            maxf = max(maxf, maxh)

        return maxf
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
