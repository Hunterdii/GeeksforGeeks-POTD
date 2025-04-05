# _7. Count Inversions_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised in the poll, I’ve started solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My solutions for December are now live! Check out today's solution below:  
  **[1760. Minimum Limit of Balls in a Bag](https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/1760.Minimum%20Limit%20of%20Balls%20in%20a%20Bag.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/1760.Minimum%20Limit%20of%20Balls%20in%20a%20Bag.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/1760.Minimum%20Limit%20of%20Balls%20in%20a%20Bag.md">
  <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
</div>

<br/>

## Problem Description

Given an array of integers `arr[]`. Find the **Inversion Count** in the array.

Two elements `arr[i]` and `arr[j]` form an inversion if `arr[i] > arr[j]` and `i < j`.

Inversion Count indicates how far (or close) the array is from being sorted:

- If the array is already sorted, the inversion count is 0.
- If the array is sorted in reverse order, the inversion count is maximum.

### Examples:

**Input:**  
`arr[] = [2, 4, 1, 3, 5]`  
**Output:**  
`3`

**Explanation:**  
The sequence `2, 4, 1, 3, 5` has three inversions: (2, 1), (4, 1), (4, 3).

**Input:**  
`arr[] = [2, 3, 4, 5, 6]`  
**Output:**  
`0`

**Explanation:**  
The array is already sorted, so there are no inversions.

**Input:**  
`arr[] = [10, 10, 10]`  
**Output:**  
`0`

**Explanation:**  
All elements of the array are the same, so there are no inversions.

### Constraints:

- $`1 ≤ arr.size() ≤ 10^5`$
- $`1 ≤ arr[i] ≤ 10^4`$

## My Approach

1. **Merge Sort-Based Counting**:

   - The problem can be efficiently solved using a modified **Merge Sort** algorithm.
   - During the merge step, count the number of inversions based on the positions of elements in the two halves.

2. **Steps:**

   - **Divide:** Recursively divide the array into two halves.
   - **Merge:** Merge the two halves while counting inversions.
   - **Count Inversions:** For every pair `(i, j)` where `arr[i] > arr[j]` and `i < j`, increment the count.

3. **Advantages:**
   - This approach efficiently counts inversions with a time complexity of **O(n log n)**, compared to the naive **O(n^2)** method.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), as the algorithm performs a logarithmic number of merge steps, with each step taking linear time.
- **Expected Auxiliary Space Complexity:** O(n), as we use an additional array for temporary storage during the merge process.

## Code (C)

```c
int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, inversions = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inversions += (mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inversions;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inversions += mergeSortAndCount(arr, temp, left, mid);
        inversions += mergeSortAndCount(arr, temp, mid + 1, right);
        inversions += mergeAndCount(arr, temp, left, mid, right);
    }
    return inversions;
}
int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
        int i = left, j = mid + 1, k = 0, inversions = 0;
        vector<int> temp(right - left + 1);

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inversions += (mid - i + 1);
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];
        for (i = left, k = 0; i <= right; ++i, ++k) {
            arr[i] = temp[k];
        }

        return inversions;
    }

    int mergeSortAndCount(vector<int>& arr, int left, int right) {
        int inversions = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            inversions += mergeSortAndCount(arr, left, mid);
            inversions += mergeSortAndCount(arr, mid + 1, right);
            inversions += mergeAndCount(arr, left, mid, right);
        }
        return inversions;
    }

    int inversionCount(vector<int>& arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};
```

## Code (Java)

```java
class Solution {
    private int mergeAndCount(int[] arr, int[] temp, int left, int mid, int right) {
        int i = left, j = mid + 1, k = left, inversions = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inversions += (mid - i + 1);
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return inversions;
    }

    private int mergeSortAndCount(int[] arr, int[] temp, int left, int right) {
        int inversions = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            inversions += mergeSortAndCount(arr, temp, left, mid);
            inversions += mergeSortAndCount(arr, temp, mid + 1, right);
            inversions += mergeAndCount(arr, temp, left, mid, right);
        }
        return inversions;
    }

    public int inversionCount(int[] arr) {
        int[] temp = new int[arr.length];
        return mergeSortAndCount(arr, temp, 0, arr.length - 1);
    }
}
```

## Code (Python)

```python
class Solution:
    def mergeAndCount(self, arr, temp, left, mid, right):
        i, j, k = left, mid + 1, left
        inversions = 0

        while i <= mid and j <= right:
            if arr[i] <= arr[j]:
                temp[k] = arr[i]
                i += 1
            else:
                temp[k] = arr[j]
                j += 1
                inversions += (mid - i + 1)
            k += 1

        while i <= mid:
            temp[k] = arr[i]
            i += 1
            k += 1

        while j <= right:
            temp[k] = arr[j]
            j += 1
            k += 1

        for i in range(left, right + 1):
            arr[i] = temp[i]

        return inversions

    def mergeSortAndCount(self, arr, temp, left, right):
        inversions = 0
        if left < right:
            mid = left + (right - left) // 2

            inversions += self.mergeSortAndCount(arr, temp, left, mid)
            inversions += self.mergeSortAndCount(arr, temp, mid + 1, right)
            inversions += self.mergeAndCount(arr, temp, left, mid, right)
        return inversions

    def inversionCount(self, arr):
        n = len(arr)
        temp = [0] * n
        return self.mergeSortAndCount(arr, temp, 0, n - 1)
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
