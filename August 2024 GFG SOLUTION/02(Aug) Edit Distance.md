## 02. Edit Distance

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/edit-distance3702/1)

### Problem Description

Given two strings `str1` and `str2`, return the minimum number of operations required to convert `str1` to `str2`. The possible operations are:

- Insert a character at any position of the string.
- Remove any character from the string.
- Replace any character from the string with any other character.

**Examples:**

Input:

```
str1 = "geek"
str2 = "gesek"
```

Output:

```
1
```

Explanation:
One operation is required, inserting 's' between two 'e'.

### My Approach

1. **Initialization:**

- Create a 2D vector `dp` of size `(m+1) x (n+1)`, where `m` is the length of `str1` and `n` is the length of `str2`.

2. **Base Case:**

- If `str1` is empty (`i == 0`), the cost is the length of `str2` (all insertions).
- If `str2` is empty (`j == 0`), the cost is the length of `str1` (all deletions).

3. **DP Transition:**

- If the current characters of `str1` and `str2` match (`str1[i-1] == str2[j-1]`), no new operation is needed. Hence, `dp[i][j] = dp[i-1][j-1]`.
- If the characters do not match, consider the cost of insertion, deletion, and replacement, and take the minimum:
  - Insertion: `dp[i][j-1] + 1`
  - Deletion: `dp[i-1][j] + 1`
  - Replacement: `dp[i-1][j-1] + 1`

4. **Return:**

- The value at `dp[m][n]` gives the minimum number of operations required to convert `str1` to `str2`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(m \* n), where `m` is the length of `str1` and `n` is the length of `str2`.
- **Expected Auxiliary Space Complexity:** O(m \* n), as we use a 2D vector of size `(m+1) x (n+1)`.

### Code (C++)

```cpp
class Solution {
public:
    int editDistance(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
            }
        }
        return dp[m][n];
    }
};
```

### Code (Java)

```java
class Solution {
    public int editDistance(String s, String t) {
        int m = s.length();
        int n = t.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (s.charAt(i - 1) == t.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + Math.min(dp[i][j - 1], Math.min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
        return dp[m][n];
    }
}
```

### Code (Python)

```python
class Solution:
    def editDistance(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0:
                    dp[i][j] = j
                elif j == 0:
                    dp[i][j] = i
                elif s[i - 1] == t[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])

        return dp[m][n]
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
