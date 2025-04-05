## 08. Index of an Extra Element

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/index-of-an-extra-element/1)

### Problem Description

You are given two sorted arrays `arr1[]` and `arr2[]` of distinct elements. The first array has one extra element added in between. Return the index of the extra element.

Note: 0-based indexing is followed.

**Example:**

Input:

```
n = 7
arr1 = [2, 4, 6, 8, 9, 10, 12]
arr2 = [2, 4, 6, 8, 10, 12]
```

Output:

```
4
```

Explanation:
In the first array, 9 is extra added and its index is 4.

### My Approach

1. **Initialization:**

   - Set two pointers, `low` to 0 and `high` to `n - 1`.

2. **Binary Search:**

   - Use a binary search approach to find the index of the extra element.
   - Calculate the middle index `mid`.
   - Compare elements at index `mid` in both arrays:
     - If `arr1[mid]` equals `arr2[mid]`, move the `low` pointer to `mid + 1` because the extra element must be in the right half.
     - Otherwise, move the `high` pointer to `mid - 1` because the extra element is in the left half.

3. **Return:**
   - The `low` pointer will eventually point to the index of the extra element.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n), as we are using a binary search which divides the search space by half each time.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the pointers and index variables.

### Code

#### C++

```cpp
class Solution {
public:
    int findExtra(int n, int arr1[], int arr2[]) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr1[mid] == arr2[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
```

#### Java

```java
class Solution {
    public int findExtra(int n, int arr1[], int arr2[]) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid < arr2.length && arr1[mid] == arr2[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
}
```

#### Python

```python
class Solution:
    def findExtra(self, n, a, b):
        low, high = 0, n - 1
        while low <= high:
            mid = (low + high) // 2
            if mid < len(b) and a[mid] == b[mid]:
                low = mid + 1
            else:
                high = mid - 1
        return low
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
