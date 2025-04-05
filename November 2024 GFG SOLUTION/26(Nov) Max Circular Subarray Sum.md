# _26. Max Circular Subarray Sum_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised in the poll, I’ve started solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My latest solution is now live:  
  **[2924. Find Champion II](https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2924.Find%20Champion%20II.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2924.Find%20Champion%20II.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
    <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2924.Find%20Champion%20II.md">
  <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
</div>

<br/>

## Problem Description

Given an array of integers `arr[]` in a circular fashion, return the maximum sum of a subarray that can be obtained assuming the array is circular.

**Note:** The solution should account for both regular and circular subarrays.

### Examples:

**Input:**  
`arr[] = [8, -8, 9, -9, 10, -11, 12]`  
**Output:**  
`22`

**Explanation:**  
Starting from the last element of the array, i.e., `12`, and moving in a circular fashion, the maximum subarray is `[12, 8, -8, 9, -9, 10]`, which gives the maximum sum of `22`.

**Input:**  
`arr[] = [10, -3, -4, 7, 6, 5, -4, -1]`  
**Output:**  
`23`

**Explanation:**  
Maximum sum of the circular subarray is `23`. The subarray is `[7, 6, 5, -4, -1, 10]`.

### Constraints:

- $`1 <= arr.size() <= 10^5`$
- $`-10^4 <= arr[i] <= 10^4`$

## My Approach

1. **Kadane's Algorithm for Maximum Subarray Sum:**
   - First, use Kadane’s algorithm to find the maximum subarray sum in the non-circular array (normal subarray sum).
2. **Kadane’s Algorithm for Minimum Subarray Sum:**
   - Use Kadane’s algorithm to find the minimum subarray sum in the array. This helps in calculating the circular maximum subarray sum.
3. **Total Sum Calculation:**
   - Calculate the total sum of the array and subtract the minimum subarray sum from it. This will give us the maximum circular subarray sum.
4. **Final Answer:**
   - The answer is the maximum of:
     - The result from Kadane’s algorithm (non-circular subarray sum).
     - The result from the circular subarray sum calculation (total sum - minimum subarray sum).
5. **Handle All Negative Case:**
   - If the entire array consists of negative numbers, return the result from Kadane’s algorithm for the maximum subarray sum.

### <div align="center">_*or*_</div>

1. **Kadane’s Algorithm**:
   - The problem is split into two parts: finding the maximum sum of a normal subarray and finding the maximum sum of a circular subarray.
2. **Steps:**
   - First, use Kadane's algorithm to find the maximum sum of a regular subarray.
   - Then, calculate the total sum of the array and use Kadane’s algorithm again on the negated values of the array to find the minimum subarray sum.
   - The circular subarray sum is obtained by subtracting the minimum subarray sum from the total sum.
   - Return the maximum of the regular subarray sum and the circular subarray sum.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the size of the array. Kadane's algorithm runs in linear time, and we perform only two linear scans of the array.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

## Code (C)

```c
int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int circularSubarraySum(int arr[], int n) {
    int total_sum = 0, max_sum = INT_MIN, min_sum = INT_MAX;
    int curr_max = 0, curr_min = 0;
    int all_negative = 1;

    for (int i = 0; i < n; i++) {
        total_sum += arr[i];

        curr_max = max(arr[i], curr_max + arr[i]);
        max_sum = max(max_sum, curr_max);

        curr_min = min(arr[i], curr_min + arr[i]);
        min_sum = min(min_sum, curr_min);

        if (arr[i] > 0) all_negative = 0;
    }

    if (all_negative) return max_sum;

    return max(max_sum, total_sum - min_sum);
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    int circularSubarraySum(vector<int>& a) {
        int total_sum = 0, max_sum = INT_MIN, min_sum = INT_MAX;
        int curr_max = 0, curr_min = 0;
        bool all_negative = true;
        for (int num : a) {
            total_sum += num;
            curr_max = max(num, curr_max + num);
            max_sum = max(max_sum, curr_max);
            curr_min = min(num, curr_min + num);
            min_sum = min(min_sum, curr_min);
            if (num > 0) all_negative = false;
        }
        if (all_negative) return max_sum;
        return max(max_sum, total_sum - min_sum);
    }
};
```

## Code (Java)

```java
class Solution {
    public int circularSubarraySum(int[] arr) {
        int totalSum = 0, maxSum = Integer.MIN_VALUE, minSum = Integer.MAX_VALUE;
        int currMax = 0, currMin = 0;
        boolean allNegative = true;

        for (int num : arr) {
            totalSum += num;

            currMax = Math.max(num, currMax + num);
            maxSum = Math.max(maxSum, currMax);

            currMin = Math.min(num, currMin + num);
            minSum = Math.min(minSum, currMin);

            if (num > 0) allNegative = false;
        }

        if (allNegative) return maxSum;

        return Math.max(maxSum, totalSum - minSum);
    }
}
```

## Code (Python)

```python
def circularSubarraySum(arr):
    total_sum = 0
    max_sum = float('-inf')
    min_sum = float('inf')
    curr_max = 0
    curr_min = 0
    all_negative = True

    for num in arr:
        total_sum += num

        curr_max = max(num, curr_max + num)
        max_sum = max(max_sum, curr_max)

        curr_min = min(num, curr_min + num)
        min_sum = min(min_sum, curr_min)

        if num > 0:
            all_negative = False

    if all_negative:
        return max_sum

    return max(max_sum, total_sum - min_sum)
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
