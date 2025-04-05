# _13. Sorted and Rotated Minimum_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Continued ✨</h2>
</div>

- Continuing the **LeetCode Problem of the Day (POTD)** journey! 🎯
- My next solution is now live:  
  **[2593. Find Score of an Array After Marking All Elements](https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2593.%20Find%20Score%20of%20an%20Array%20After%20Marking%20All%20Elements.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2593.%20Find%20Score%20of%20an%20Array%20After%20Marking%20All%20Elements.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2593.%20Find%20Score%20of%20an%20Array%20After%20Marking%20All%20Elements.md">
    <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
  </a>
</div>

<br/>

## Problem Description

You are given a sorted array `arr[]` which has been rotated at an unknown pivot. The array may contain duplicate elements. Your task is to find the **minimum element** in the array.

### Examples:

**Input:**  
`arr[] = [5, 6, 1, 2, 3, 4]`  
**Output:**  
`1`  
**Explanation:**  
The minimum element is `1`.

**Input:**  
`arr[] = [3, 2, 2, 2]`  
**Output:**  
`2`  
**Explanation:**  
The minimum element is `2`.

**Input:**  
`arr[] = [4, 4, 4]`  
**Output:**  
`4`  
**Explanation:**  
The minimum element is `4`.

### Constraints:

- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ 10^9`

## My Approach

1. **Binary Search in a Rotated Array:**

   - To find the minimum element in a rotated sorted array, we leverage **binary search** to reduce the search space efficiently.
   - Use two pointers, `lo` and `hi`, to represent the current range. Compare the middle element with the last element to determine the rotation point.

2. **Handling Duplicates:**

   - When duplicates are present, special handling is required to ensure correctness. In such cases, we adjust the `hi` pointer if `arr[mid]` equals `arr[hi]`.

3. **Steps:**
   - Initialize two pointers, `lo` and `hi`, to the start and end of the array.
   - If `arr[lo] < arr[hi]`, the array is not rotated, and `arr[lo]` is the minimum.
   - Compute the middle index `mid`.
   - Compare `arr[mid]` with `arr[hi]`:
     - If `arr[mid] > arr[hi]`, the minimum is in the right half (`lo = mid + 1`).
     - If `arr[mid] < arr[hi]`, the minimum is in the left half (`hi = mid`).
     - If `arr[mid] == arr[hi]`, decrement `hi` to handle duplicates.
   - Return `arr[lo]` as the minimum element.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n), as we reduce the search space by half in each iteration. In the case of duplicates, the complexity degrades to O(n).
- **Expected Auxiliary Space Complexity:** O(1), as we use only a constant amount of additional space.

## Code (C)

```c
int findMin(int* arr, int n) {
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        if (arr[lo] < arr[hi])
            return arr[lo];
        int mid = lo + ((hi - lo) >> 1);
        if (arr[mid] > arr[hi])
            lo = mid + 1;
        else
            hi = mid;
    }
    return arr[lo];
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    int findMin(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            if (arr[lo] < arr[hi])
                return arr[lo];
            int mid = lo + ((hi - lo) >> 1);
            if (arr[mid] > arr[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        return arr[lo];
    }
};
```

## Code (Java)

```java
class Solution {
    public int findMin(int[] arr) {
        int lo = 0, hi = arr.length - 1;
        while (lo < hi) {
            if (arr[lo] < arr[hi])
                return arr[lo];
            int mid = lo + ((hi - lo) >> 1);
            if (arr[mid] > arr[hi])
                lo = mid + 1;
            else
                hi = mid;
        }
        return arr[lo];
    }
}
```

## Code (Python)

```python
class Solution:
    def findMin(self, arr):
        lo, hi = 0, len(arr) - 1
        while lo < hi:
            if arr[lo] < arr[hi]:
                return arr[lo]
            mid = lo + ((hi - lo) // 2)
            if arr[mid] > arr[hi]:
                lo = mid + 1
            else:
                hi = mid
        return arr[lo]
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
