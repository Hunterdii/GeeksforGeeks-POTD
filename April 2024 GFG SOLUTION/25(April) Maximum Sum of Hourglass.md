## 25. Maximum Sum of Hourglass

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1)

### Problem Description

Given two integers \(n\) and \(m\) and a 2D matrix \(mat\) of dimensions \(n \times m\), the task is to find the maximum sum of an hourglass. An hourglass is defined as a part of the matrix with a specific form.

**Example:**

<br/>

<p align="center">
<img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/bde3ee29-900a-42ef-ba0e-9fbc72733332" alt="Image" width="250" />
</p>

Input:

```
n = 3, m = 3
mat = [[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]]
```

Output:

```
35
```

Explanation:
There is only one hourglass in the matrix:

```
1 2 3
  5
7 8 9
```

The sum of this hourglass is 35.

**Your Task:**

You don't need to read input or print anything. Your task is to complete the function `findMaxSum()` which takes the two integers \(n\) and \(m\), and the 2D matrix \(mat\) as input parameters, and returns the maximum sum of an hourglass in the matrix. If there are no hourglasses, it returns -1.

**Expected Time Complexity:** \(O(n \times m)\)
**Expected Auxillary Space:** \(O(1)\)

**Constraints:**

- \(1 \leq n \leq 150\)
- \(3 \leq m \leq 150\)
- \(0 \leq \text{mat}[i][j] \leq 10^6\)

### My Approach

1. **Initialization:**
   - Initialize a variable `ans` to store the maximum sum of the hourglass. Set it to the minimum integer value initially.
2. **Iterate Through Matrix:**
   - Iterate through the matrix using two nested loops to cover all possible hourglasses.
3. **Calculate Hourglass Sum:**
   - For each hourglass, calculate its sum by adding the values of all its elements.
4. **Update Maximum Sum:**
   - Update the maximum sum (`ans`) if the sum of the current hourglass is greater than the current maximum.
5. **Return Result:**
   - Return the maximum sum of the hourglass found.

### Code (C++)

```cpp
class Solution {
public:
    int findMaxSum(int N, int M, std::vector<std::vector<int>>& Mat) {
        if (N < 3 || M < 3) {
            return -1;
        }

        int ans = std::numeric_limits<int>::min();

        for (int i = 0; i < N - 2; ++i) {
            for (int j = 0; j < M - 2; ++j) {
                int sum = Mat[i][j] + Mat[i][j + 1] + Mat[i][j + 2] +
                          Mat[i + 1][j + 1] +
                          Mat[i + 2][j] + Mat[i + 2][j + 1] + Mat[i + 2][j + 2];

                ans = std::max(ans, sum);
            }
        }

        return ans;
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
