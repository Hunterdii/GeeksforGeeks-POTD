## 29. Row with Max 1s

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1)

### Problem Description

Given a boolean 2D array consisting of only 1's and 0's, where each row is sorted, find the 0-based index of the first row that has the maximum number of 1's. Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

**Example:**

Input:

```
arr[][] = [[0, 1, 1, 1],
           [0, 0, 1, 1],
           [1, 1, 1, 1],
           [0, 0, 0, 0]]
```

Output:

```
2
```

Explanation:
Row 2 contains 4 1's (0-based indexing).

### My Approach

1. **Initialization:**

   - Determine the dimensions of the 2D array: `n` (number of rows) and `m` (number of columns).
   - Initialize `max_row_index` as -1 to keep track of the row with the maximum number of 1's.

2. **Traversal:**

   - Start from the top-right corner of the matrix (`r = 0`, `c = m - 1`).
   - Move left if the current cell contains a 1 and update `max_row_index` to the current row index.
   - Move down if the current cell contains a 0.

3. **Return:**
   - Return `max_row_index`, which contains the index of the row with the maximum number of 1's.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + m), as we traverse the matrix starting from the top-right corner, moving left or down.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int rowWithMax1s(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int max_row_index = -1;

        int r = 0;
        int c = m - 1;

        while (r < n && c >= 0) {
            if (arr[r][c] == 1) {
                max_row_index = r;
                c--;
            } else {
                r++;
            }
        }

        return max_row_index;
    }
};
```

### Code (Java)

```java
class Solution {
    public int rowWithMax1s(int[][] arr) {
        int n = arr.length;
        int m = arr[0].length;
        int maxRowIndex = -1;

        int r = 0;
        int c = m - 1;

        while (r < n && c >= 0) {
            if (arr[r][c] == 1) {
                maxRowIndex = r;
                c--;
            } else {
                r++;
            }
        }

        return maxRowIndex;
    }
}
```

### Code (Python)

```python
class Solution:
    def rowWithMax1s(self, arr):
        n = len(arr)
        m = len(arr[0])
        max_row_index = -1

        r = 0
        c = m - 1

        while r < n and c >= 0:
            if arr[r][c] == 1:
                max_row_index = r
                c -= 1
            else:
                r += 1

        return max_row_index
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
