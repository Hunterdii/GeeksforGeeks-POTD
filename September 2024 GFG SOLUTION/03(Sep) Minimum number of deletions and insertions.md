# **03. Minimum Number of Deletions and Insertions**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given two strings, `str1` and `str2`, the task is to find the minimum number of operations required to transform `str1` into `str2`. The operations allowed are insertions and deletions of characters.

**Example:**

Input:

```
str1 = "heap"
str2 = "pea"
```

Output:

```
3
```

Explanation: Delete `'h'` and `'a'` from "heap", then insert `'p'` at the beginning.

### My Approach

1. **Dynamic Programming (DP) Setup:**

   - The problem can be reduced to finding the length of the longest common subsequence (LCS) between `str1` and `str2`.
   - The minimum number of deletions required to transform `str1` into `str2` will be the difference between the length of `str1` and the LCS.
   - The minimum number of insertions will be the difference between the length of `str2` and the LCS.

2. **Initialization:**

   - Create two arrays, `prev` and `curr`, of size `n + 1`, where `n` is the length of `str2`. These arrays will be used to store the LCS lengths for substrings of `str1` and `str2`.

3. **DP Array Population:**

   - Iterate through each character of `str1` and `str2`. If the characters match, update `curr[j]` to be `prev[j-1] + 1`.
   - If they don't match, update `curr[j]` to be the maximum of `prev[j]` and `curr[j-1]`.

4. **Final Answer:**
   - The final answer will be `m + n - 2 * LCS`, where `m` is the length of `str1` and `n` is the length of `str2`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|str1|\*|str2|), as we iterate over all possible pairs of characters.
- **Expected Auxiliary Space Complexity:** O(|str2|), as we only use a constant amount of additional space apart from the two arrays used for DP.

### Code (C++)

```cpp
class Solution {
public:
    int minOperations(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return m + n - 2 * curr[n];
    }
};
```

### Code (Java)

```java
class Solution {
    public int minOperations(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();

        int[] dp = new int[n + 1];

        for (int i = 1; i <= m; i++) {
            int prev = 0;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = Math.max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }

        return m + n - 2 * dp[n];
    }
}
```

### Code (Python)

```python
class Solution:
    def minOperations(self, str1: str, str2: str) -> int:
        m, n = len(str1), len(str2)

        dp = [0] * (n + 1)

        for i in range(1, m + 1):
            prev = 0
            for j in range(1, n + 1):
                temp = dp[j]
                if str1[i - 1] == str2[j - 1]:
                    dp[j] = prev + 1
                else:
                    dp[j] = max(dp[j], dp[j - 1])
                prev = temp

        return m + n - 2 * dp[n]
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
