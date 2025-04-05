# _16. Move All Zeroes to End_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1)

> **Note:** I'm currently in the middle of my exams until November 19, so I’ll be uploading daily POTD solutions, but not at a fixed time. Apologies for any inconvenience, and thank you for your patience!

## Problem Description

Given an array `arr[]`, move all the zeros in the array to the end while maintaining the relative order of non-zero elements. The modification should be done **in-place**.

### Examples:

**Input:**

```
arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
```

**Output:**

```
[1, 2, 4, 3, 5, 0, 0, 0]
```

**Explanation:**  
The three zeros are moved to the end while the relative order of non-zero elements is maintained.

**Input:**

```
arr[] = [10, 20, 30]
```

**Output:**

```
[10, 20, 30]
```

**Explanation:**  
No change in the array as there are no zeros.

**Input:**

```
arr[] = [0, 0]
```

**Output:**

```
[0, 0]
```

**Explanation:**  
No change in the array as all elements are zeros.

## My Approach

1. **Two-Pointer Technique:**

   - Use a pointer `nonZeroIndex` to track the position where the next non-zero element should be placed.
   - Traverse the array, and whenever a non-zero element is encountered, swap it with the element at the `nonZeroIndex` and increment the pointer.
   - This ensures all non-zero elements are shifted to the front, and zeros naturally move to the end.

2. **Edge Cases:**
   - If the array contains no zeros, return the array as is.
   - If the array contains only zeros, no changes are needed.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of elements in the array. Each element is traversed once to determine its position.
- **Expected Auxiliary Space Complexity:** O(1), as no additional space is used apart from a few variables.

## Code (C++)

```cpp
class Solution {
public:
    void pushZerosToEnd(std::vector<int>& arr) {
        int n = arr.size();
        int nonZeroIndex = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                std::swap(arr[nonZeroIndex++], arr[i]);
            }
        }
    }
};
```

## Code (Java)

```java
class Solution {
    void pushZerosToEnd(int[] arr) {
        int n = arr.length;
        int nonZeroIndex = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                int temp = arr[nonZeroIndex];
                arr[nonZeroIndex] = arr[i];
                arr[i] = temp;
                nonZeroIndex++;
            }
        }
    }
}
```

## Code (Python)

```python
class Solution:
    def pushZerosToEnd(self, arr):
        n = len(arr)
        nonZeroIndex = 0

        for i in range(n):
            if arr[i] != 0:
                arr[nonZeroIndex], arr[i] = arr[i], arr[nonZeroIndex]
                nonZeroIndex += 1
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
