## 11. Count Pairs with Given Sum in Two Sorted Matrices

The problem statement can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices4332/1)

### Approach Explanation

1. **Initialization:**

   - Initialize `count` to 0 to keep track of the number of pairs found.
   - Initialize `r1`, `c1`, `r2`, and `c2` to appropriate indices for traversing both matrices.

2. **Pair Sum Calculation:**

   - Traverse both matrices using pointers `r1`, `c1`, `r2`, and `c2`.
   - Calculate the sum of the elements at indices `(r1, c1)` from `mat1` and `(r2, c2)` from `mat2`.

3. **Sum Comparison and Increment:**

   - If the sum equals the target value 'x', increment the `count` and adjust pointers `c1` and `c2`.
   - If the sum is less than 'x', move the pointer `c1` to the right to increase the sum.
   - If the sum is greater than 'x', move the pointer `c2` to the left to decrease the sum.

4. **Boundary Handling:**

   - Handle boundary conditions within the loop to ensure pointers stay within bounds.

5. **Return Count:**
   - Return the `count` representing the total number of pairs found.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(n^2), where n is the size of the matrices.
- **Auxiliary Space Complexity**: O(1), since no extra space is used except for a few variables.

### Code (C++)

```cpp
class Solution {
public:
  int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x) {
    int count = 0;
    int r1 = 0, c1 = 0;
    int r2 = n - 1, c2 = n - 1;

    while ((r1 < n) && (r2 >= 0)) {  // Ensure r2 doesn't become negative
      int val = mat1[r1][c1] + mat2[r2][c2];

      if (val == x) {
        count++;
        c1++;
        c2--;
      } else if (val < x) {
        c1++;
      } else {
        c2--;
      }

      // Handle boundary conditions within the loop
      if (c1 == n) {
        c1 = 0;
        r1++;
      }
      if (c2 == -1) {  // Avoid negative index
        c2 = n - 1;
        r2--;
      }
    }

    return count;
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
