## 22. Row with Minimum Number of 1's

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1)

### Problem Description

Given a 2D binary matrix (1-based indexed) `a` of dimensions \(n \times m\), determine the row that contains the minimum number of 1's. If two or more rows contain the minimum number of 1's, the answer is the lowest of those indices.

**Example:**

Input:

```
n = 4, m = 4
a = [[1, 1, 1, 1],
     [1, 1, 0, 0],
     [0, 0, 1, 1],
     [1, 1, 1, 1]]
```

Output:

```
2
```

Explanation:
Rows 2 and 3 contain the minimum number of 1's (2 each). Since row 2 is less than row 3, the answer is 2.

### My Approach

1. **Initialization:**

   - Initialize a variable `res` to store the index of the row with the minimum number of 1's.
   - Initialize a variable `min` to store the minimum count of 1's encountered.
   - Start traversing each row of the matrix.

2. **Row Traversal:**

   - For each row, traverse through all the columns and count the number of 1's.
   - Update the `min` variable with the minimum count encountered so far.
   - Update the `res` variable with the index of the row containing the minimum count.

3. **Return:**
   - Return the value of `res` as the index of the row with the minimum number of 1's.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(n \times m)\), as we traverse through each element of the matrix once.
- **Expected Auxiliary Space Complexity:** \(O(1)\), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int res = 1;
        int min = INT_MAX;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1) {
                    count++;
                }
            }

            int minn = std::min(count, min);
            if(minn != min) {
                res = i + 1;
                min = minn;
            }
        }
        return res;
    }
};
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
