## 15. Mobile Numeric Keypad

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1)

### Problem Description

There is a standard numeric keypad on a mobile phone. You can only press the current button or buttons that are directly up, left, right, or down from it. Diagonal movements and pressing the bottom row corner buttons (\* and #) are prohibited.

<p align="center">
  <img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/a8e13f20-65da-4a5a-9458-dc8422bef9a9" alt="Image" width="270" />
</p>

Given a number `n`, find the number of possible unique sequences of length `n` that you can create by pressing buttons. You can start from any digit.

**Example:**

Input:

```
n = 1
```

Output:

```
10
```

Explanation:
Number of possible numbers are 10 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)

### My Approach

1. **Initialization:**

   - Define a 2D vector `a` representing the keypad, where `-1` represents invalid keys (\* and #).
   - Create a 3D array `dp` where `dp[i][j][k]` stores the number of unique sequences of length `k` starting at key `(i, j)` on the keypad.

2. **Base Case:**

   - Initialize `dp[i][j][1]` to 1 for all valid keys `(i, j)` since any key by itself is a valid sequence of length 1.

3. **Dynamic Programming Transition:**

   - For each length from 2 to `n`, and for each key `(i, j)`:
     - Update `dp[i][j][len]` by adding the number of sequences of length `len-1` from the current key and its valid neighbors (up, down, left, right).

4. **Result Calculation:**
   - Sum up the values in `dp[i][j][n]` for all valid keys `(i, j)` to get the total number of unique sequences of length `n`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the length of sequences up to `n` and update the `dp` array.
- **Expected Auxiliary Space Complexity:** O(n), as the `dp` array stores values up to length `n`.

### Code (C++)

```cpp
class Solution {
    vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
    long long dp[4][3][26];
public:
    long long getCount(int n) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (a[i][j] != -1) {
                    dp[i][j][1] = 1;
                }
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (a[i][j] != -1) {
                        dp[i][j][len] = dp[i][j][len - 1];
                        if (j + 1 < 3 && a[i][j + 1] != -1) {
                            dp[i][j][len] += dp[i][j + 1][len - 1];
                        }
                        if (j - 1 >= 0 && a[i][j - 1] != -1) {
                            dp[i][j][len] += dp[i][j - 1][len - 1];
                        }
                        if (i + 1 < 4 && a[i + 1][j] != -1) {
                            dp[i][j][len] += dp[i + 1][j][len - 1];
                        }
                        if (i - 1 >= 0 && a[i - 1][j] != -1) {
                            dp[i][j][len] += dp[i - 1][j][len - 1];
                        }
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (a[i][j] != -1) {
                    ans += dp[i][j][n];
                }
            }
        }
        return ans;
    }
};
```

### Code (Java)

```java
class Solution {
    int[][] a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
    long[][][] dp = new long[4][3][26];

    public long getCount(int n) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                Arrays.fill(dp[i][j], 0);
                if (a[i][j] != -1) {
                    dp[i][j][1] = 1;
                }
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (a[i][j] != -1) {
                        dp[i][j][len] = dp[i][j][len - 1];
                        if (j + 1 < 3 && a[i][j + 1] != -1) {
                            dp[i][j][len] += dp[i][j + 1][len - 1];
                        }
                        if (j - 1 >= 0 && a[i][j - 1] != -1) {
                            dp[i][j][len] += dp[i][j - 1][len - 1];
                        }
                        if (i + 1 < 4 && a[i + 1][j] != -1) {
                            dp[i][j][len] += dp[i + 1][j][len - 1];
                        }
                        if (i - 1 >= 0 && a[i - 1][j] != -1) {
                            dp[i][j][len] += dp[i - 1][j][len - 1];
                        }
                    }
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i][j] != -1) {
                    ans += dp[i][j][n];
                }
            }
        }
        return ans;
    }
}
```

### Code (Python)

```python
class Solution:
    def __init__(self):
        self.a = [[1, 2, 3], [4, 5, 6], [7, 8, 9], [-1, 0, -1]]
        self.dp = [[[0 for _ in range(26)] for _ in range(3)] for _ in range(4)]

    def getCount(self, n):
        for i in range(4):
            for j in range(3):
                if self.a[i][j] != -1:
                    self.dp[i][j][1] = 1

        for length in range(2, n + 1):
            for i in range(4):
                for j in range(3):
                    if self.a[i][j] != -1:
                        self.dp[i][j][length] = self.dp[i][j][length - 1]
                        if j + 1 < 3 and self.a[i][j + 1] != -1:
                            self.dp[i][j][length] += self.dp[i][j + 1][length - 1]
                        if j - 1 >= 0 and self.a[i][j - 1] != -1:
                            self.dp[i][j][length] += self.dp[i][j - 1][length - 1]
                        if i + 1 < 4 and self.a[i + 1][j] != -1:
                            self.dp[i][j][length] += self.dp[i + 1][j][length - 1]
                        if i - 1 >= 0 and self.a[i - 1][j] != -1:
                            self.dp[i][j][length] += self.dp[i - 1][j][length - 1]

        ans = 0
        for i in range(4):
            for j in range(3):
                if self.a[i][j] != -1:
                    ans += self.dp[i][j][n]

        return ans
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
