# _14. Search in Rotated Sorted Array_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Continued ✨</h2>
</div>

- Continuing the **LeetCode Problem of the Day (POTD)** journey! 🎯
- My next solution is now live:  
  **[2762. Continuous Subarrays](https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2762.%20Continuous%20Subarrays.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2762.%20Continuous%20Subarrays.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2762.%20Continuous%20Subarrays.md">
    <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
  </a>
</div>

<br/>

## Problem Description

Given a sorted (in ascending order) and rotated array `arr` of distinct elements which may be rotated at some point and given an element `key`, the task is to find the index of the given element `key` in the array `arr`. The whole array `arr` is given as the range to search. Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.

**Note:** 0-based indexing is followed & returns -1 if the key is not present.

**Examples:**

Input:

```
arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 10
```

Output:

```
5
```

Explanation:
10 is found at index 5.

## My Approach

1. **Initialization:**

- Use a linear search approach to iterate through the array `arr`.

2. **Search for Key:**

- Iterate through each element in the array from `i = 0` to `n-1` (where `n` is the size of the array).
- Compare each element with the `key`.
- If a match is found, return the index `i`.
- If the end of the array is reached without finding the `key`, return -1.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array once to find the `key`.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

## Code (C++)

```cpp
class Solution {
public:
    int search(vector<int>& arr, int key) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i] == key) {
                return i;
            }
        }
        return -1;
    }
};
```

## Code (Java)

```java
class Solution {
    int search(int[] arr, int key) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1;
    }
}
```

## Code (Python)

```python
class Solution:
    def search(self, arr, key):
        n = len(arr)
        for i in range(n):
            if arr[i] == key:
                return i
        return -1
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" />
</p>
