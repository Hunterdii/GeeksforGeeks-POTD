## 30. String Subsequence

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1)

### Problem Description

Given two strings, `s1` and `s2`, count the number of subsequences of string `s1` equal to string `s2`. Return the total count modulo \(10^9 + 7\).

**Example 1:**

Input:

```
s1 = "geeksforgeeks"
s2 = "gks"
```

Output:

```
4
```

Explanation:
We can pick characters from `s1` as a subsequence from indices {0,3,4}, {0,3,12}, {0,11,12} and {8,11,12}. So total 4 subsequences of `s1` that are equal to `s2`.

### My Approach

1. **Initialization:**

   - Create a memoization table `memo` of size `(n+1) x (m+1)` initialized to -1, where `n` is the length of `s1` and `m` is the length of `s2`.
   - Define the modulo value `mod` as \(10^9 + 7\).

2. **Dynamic Programming Function:**

   - Use a recursive function `dp(i, j)` to calculate the number of ways to match the first `i` characters of `s1` with the first `j` characters of `s2`.
   - Base cases:
     - If `j == 0`, return 1 since an empty `s2` can be matched in one way.
     - If `i == 0`, return 0 since a non-empty `s2` cannot be matched with an empty `s1`.
   - Recursive cases:
     - If `s1[i-1] == s2[j-1]`, update `memo[i][j]` with the sum of `dp(i-1, j-1)` and `dp(i-1, j)` modulo `mod`.
     - Otherwise, set `memo[i][j]` to `dp(i-1, j)` modulo `mod`.

3. **Return:**
   - Return `dp(n, m)` where `n` is the length of `s1` and `m` is the length of `s2`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* m), where `n` and `m` are the lengths of the strings `s1` and `s2` respectively. This is due to the nested loops iterating over the lengths of the strings.
- **Expected Auxiliary Space Complexity:** O(n \* m), due to the memoization table storing results for each subproblem of sizes up to `n` and `m`.

### Code

#### C++

```cpp
class Solution {
public:
    int countWays(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<int> dp(m + 1, 0);
        int mod = 1e9 + 7;
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int prev = dp[0];
            for (int j = 1; j <= m; j++) {
                int temp = dp[j];
                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = (prev + dp[j]) % mod;
                }
                prev = temp;
            }
        }
        return dp[m] % mod;
    }
};
```

#### Java

```java
class Solution {
    public static int countWays(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int[][] memo = new int[n + 1][m + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        int mod = 1_000_000_007;

        return dp(n, m, s1, s2, memo, mod);
    }

    private static int dp(int i, int j, String s1, String s2, int[][] memo, int mod) {
        if (j == 0) return 1;
        if (i == 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
            memo[i][j] = (dp(i - 1, j - 1, s1, s2, memo, mod) + dp(i - 1, j, s1, s2, memo, mod)) % mod;
        } else {
            memo[i][j] = dp(i - 1, j, s1, s2, memo, mod) % mod;
        }

        return memo[i][j];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s1 = br.readLine();
            String s2 = br.readLine();
            Solution obj = new Solution();
            int res = obj.countWays(s1, s2);
            System.out.println(res);
        }
    }
}
```

#### Python

```python
class Solution:
    def countWays(self, s1: str, s2: str) -> int:
        n, m = len(s1), len(s2)
        memo = [[-1] * (m + 1) for _ in range(n + 1)]
        mod = 10**9 + 7

        def dp(i, j):
            if j == 0:
                return 1  # s2 is empty, one way to match
            if i == 0:
                return 0  # s1 is empty, no way to match
            if memo[i][j] != -1:
                return memo[i][j]

            if s1[i - 1] == s2[j - 1]:
                memo[i][j] = (dp(i - 1, j - 1) + dp(i - 1, j)) % mod
            else:
                memo[i][j] = dp(i - 1, j) % mod

            return memo[i][j]

        return dp(n, m)
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
