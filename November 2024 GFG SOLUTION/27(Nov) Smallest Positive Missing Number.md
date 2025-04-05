# _27. Smallest Positive Missing Number_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised in the poll, I’ve started solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My latest solution is now live:  
  **[3243. Shortest Distance After Road Addition Queries I](https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/3243.Shortest%20Distance%20After%20Road%20Addition%20Queries%20I.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/3243.Shortest%20Distance%20After%20Road%20Addition%20Queries%20I.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/3243.Shortest%20Distance%20After%20Road%20Addition%20Queries%20I.md">
  <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
</div>

<br/>

## Problem Description

You are given an integer array `arr[]`. Your task is to find the smallest positive number missing from the array.

**Note:** Positive number starts from 1. The array can have negative integers too.

### Examples:

**Input:**  
`arr[] = [2, -3, 4, 1, 1, 7]`  
**Output:**  
`3`

**Explanation:**  
Smallest positive missing number is 3.

**Input:**  
`arr[] = [5, 3, 2, 5, 1]`  
**Output:**  
`4`

**Explanation:**  
Smallest positive missing number is 4.

**Input:**  
`arr[] = [-8, 0, -1, -4, -3]`  
**Output:**  
`1`

**Explanation:**  
Smallest positive missing number is 1.

### Constraints:

- $`1 <= arr.size() <= 10^5`$
- $`-10^6 <= arr[i] <= 10^6`$

## My Approach

1. **In-place Rearrangement**:

   - The problem can be solved using an in-place rearrangement technique that places elements at their correct indices.
   - The idea is to rearrange the elements such that for any element `arr[i]`, it should be placed at index `arr[i] - 1`.
   - After rearranging the elements, traverse the array again to find the smallest missing positive integer.

2. **Steps:**
   - Iterate through the array, and for each element that is within the valid range `[1, n]`, place it in its correct position.
   - Once the array is rearranged, traverse the array to identify the smallest index `i` where `arr[i] != i + 1`. This indicates the missing number.
   - If all elements are in place, the missing number is `n + 1`.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the size of the array. The algorithm requires two linear scans of the array, making it efficient.
- **Expected Auxiliary Space Complexity:** O(1), as we use only a constant amount of additional space.

## Code (C)

```c
int missingNumber(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
            int temp = arr[i];
            arr[i] = arr[arr[i] - 1];
            arr[temp - 1] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}
```

## Code (C++)

```cpp
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```

## Code (Java)

```java
class Solution {
    public int missingNumber(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
                int temp = arr[i];
                arr[i] = arr[arr[i] - 1];
                arr[temp - 1] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
}
```

## Code (Python)

```python
class Solution:
    def missingNumber(self, arr):
        n = len(arr)
        for i in range(n):
            while arr[i] > 0 and arr[i] <= n and arr[i] != arr[arr[i] - 1]:
                arr[arr[i] - 1], arr[i] = arr[i], arr[arr[i] - 1]
        for i in range(n):
            if arr[i] != i + 1:
                return i + 1
        return n + 1
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
