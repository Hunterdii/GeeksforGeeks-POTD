# _24. Kadane's Algorithm_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised, I’ve continued solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My latest solution is now live:  
  **[1975. Maximum Matrix Sum](https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/1975.Maximum%20Matrix%20Sum.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/1975.Maximum%20Matrix%20Sum.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/1975.Maximum%20Matrix%20Sum.md">
    <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
  </a>
</div>

<br/>

## Problem Description

Given an integer array `arr[]`, you need to find and return the maximum sum possible from all the subarrays.

### Examples:

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

- `1 ≤ arr.size() ≤ 10^5`
- `-10^9 ≤ arr[i] ≤ 10^4`

## My Approach

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

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the size of the array. The algorithm performs a single linear scan of the array.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

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

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
