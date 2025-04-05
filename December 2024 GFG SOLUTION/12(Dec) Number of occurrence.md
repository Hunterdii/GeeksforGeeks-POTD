# _12. Number of Occurrences_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised in the poll, I’ve started solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My solutions for December are now live! Check out today's solution below:  
  [**2558. Take Gifts From the Richest Pile**](https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2558.Take%20Gifts%20From%20the%20Richest%20Pile.md)

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2558.Take%20Gifts%20From%20the%20Richest%20Pile.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2558.Take%20Gifts%20From%20the%20Richest%20Pile.md">
    <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
  </a>
</div>

## Problem Description

Given a sorted array `arr[]` and a number `target`, determine the number of occurrences of `target` in the array.

If the number does not exist in the array, return `0`.

### Examples:

**Input:**  
`arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2`  
**Output:**  
`4`

**Explanation:**  
`2` occurs 4 times in the array.

**Input:**  
`arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4`  
**Output:**  
`0`

**Explanation:**  
`4` is not present in the array.

**Input:**  
`arr[] = [8, 9, 10, 12, 12, 12], target = 12`  
**Output:**  
`3`

**Explanation:**  
`12` occurs 3 times in the array.

### Constraints:

- $`1 ≤ arr.size() ≤ 10^6`$
- $`1 ≤ arr[i] ≤ 10^6`$
- $`1 ≤ target ≤ 10^6`$

## My Approach

1. **Binary Search for Boundaries:**

   - Since the array is sorted, we can leverage binary search to efficiently locate the first and last occurrence of the target.
   - Two binary search calls are made: one to find the lower bound and another for the upper bound.
   - The difference between the indices of these two boundaries gives the count of occurrences.

2. **Steps:**
   - Perform a binary search to find the first occurrence of the target.
   - Perform another binary search to find the last occurrence of the target.
   - Subtract the indices of these two boundaries and add `1` to calculate the count.
   - If the target is not present, return `0`.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n), as binary search operates in logarithmic time.
- **Expected Auxiliary Space Complexity:** O(1), as only a constant amount of additional space is used.

## Code (C)

```c
int countFreq(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    if (arr[low] != target)
        return 0;

    int first = low;
    high = n - 1;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid;
    }

    int last = high;
    return last - first + 1;
}
```

## Code (C++)

```cpp
class Solution {
public:
    int countFreq(const vector<int>& arr, int target) {
        auto lower = lower_bound(arr.begin(), arr.end(), target);
        auto upper = upper_bound(lower, arr.end(), target);
        return (lower != arr.end() && *lower == target) ? (upper - lower) : 0;
    }
};
```

## Code (Java)

```java
class Solution {
    public int countFreq(int[] arr, int target) {
        int low = 0, high = arr.length - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }

        if (low >= arr.length || arr[low] != target)
            return 0;

        int first = low;
        high = arr.length - 1;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (arr[mid] > target)
                high = mid - 1;
            else
                low = mid;
        }

        int last = high;
        return last - first + 1;
    }
}
```

## Code (Python)

```python
class Solution:
    def countFreq(self, arr, target):
        import bisect
        lower = bisect.bisect_left(arr, target)
        upper = bisect.bisect_right(arr, target)
        return (upper - lower) if lower < len(arr) and arr[lower] == target else 0
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
