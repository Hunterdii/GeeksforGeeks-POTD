# **26. Wildcard Pattern Matching**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given two strings, `pattern` and `str`, which may be of different sizes, return `1` if the wildcard pattern matches `str`, else return `0`. The wildcard pattern can include the characters `?` and `*`.

- `?` matches any single character.
- `*` matches any sequence of characters (including the empty sequence).

**Note:** The matching should cover the entire string `str` (not partial matches).

**Example:**

Input:

```
pattern = "ba*a?"
str = "baaabab"
```

Output:

```
1
```

Explanation: Replace `*` with `"aab"` and `?` with `"b"`.

### My Approach

1. **Dynamic Programming (DP) Setup:**

   - Create a 2D DP array where `dp[i][j]` will be `1` if the first `i` characters in `pattern` match the first `j` characters in `str`, else `0`.

2. **Initialization:**

   - `dp[0][0] = 1` because an empty pattern matches an empty string.
   - If `pattern[j-1]` is `*`, then `dp[j]` can inherit the value from `dp[j-1]` since `*` can represent an empty sequence.

3. **DP Array Population:**

   - For each character in `str` and `pattern`, update the DP array:
     - If `pattern[j-1]` is `?` or `pattern[j-1]` matches `str[i-1]`, then set `newDp[j] = dp[j-1]`.
     - If `pattern[j-1]` is `*`, set `newDp[j] = dp[j] || newDp[j-1]`, allowing `*` to match multiple characters.

4. **Final Answer:**
   - The value of `dp[n]` will determine if the entire `str` matches the `pattern`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n\*m), where `n` is the length of `str` and `m` is the length of `pattern`, as we iterate over all possible pairs of characters.
- **Expected Auxiliary Space Complexity:** O(n\*m), due to the DP array that stores matching results for all substrings.

### Code (C++)

```cpp
class Solution {
public:
    int wildCard(string pattern, string str) {
        int m = str.length();
        int n = pattern.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int j = 1; j <= n; j++) {
            if (pattern[j - 1] == '*') {
                dp[j] = dp[j - 1];
            }
        }
        for (int i = 1; i <= m; i++) {
            vector<int> newDp(n + 1, 0);
            for (int j = 1; j <= n; j++) {
                if (pattern[j - 1] == '?' || pattern[j - 1] == str[i - 1]) {
                    newDp[j] = dp[j - 1];
                } else if (pattern[j - 1] == '*') {
                    newDp[j] = dp[j] || newDp[j - 1];
                }
            }
            dp.swap(newDp);
        }
        return dp[n];
    }
};
```

### Code (Java)

```java
class Solution {
    public int wildCard(String pattern, String str) {
        int m = str.length();
        int n = pattern.length();
        int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int j = 1; j <= n; j++) {
            if (pattern.charAt(j - 1) == '*') {
                dp[j] = dp[j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            int[] newDp = new int[n + 1];
            for (int j = 1; j <= n; j++) {
                if (pattern.charAt(j - 1) == '?' || pattern.charAt(j - 1) == str.charAt(i - 1)) {
                    newDp[j] = dp[j - 1];
                } else if (pattern.charAt(j - 1) == '*') {
                    newDp[j] = dp[j] | newDp[j - 1];
                }
            }
            dp = newDp;
        }

        return dp[n];
    }
}
```

### Code (Python)

```python
class Solution:
    def wildCard(self, pattern, string):
        m = len(string)
        n = len(pattern)
        dp = [0] * (n + 1)
        dp[0] = 1

        for j in range(1, n + 1):
            if pattern[j - 1] == '*':
                dp[j] = dp[j - 1]

        for i in range(1, m + 1):
            new_dp = [0] * (n + 1)
            for j in range(1, n + 1):
                if pattern[j - 1] == '?' or pattern[j - 1] == string[i - 1]:
                    new_dp[j] = dp[j - 1]
                elif pattern[j - 1] == '*':
                    new_dp[j] = dp[j] or new_dp[j - 1]
            dp = new_dp

        return dp[n]
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
