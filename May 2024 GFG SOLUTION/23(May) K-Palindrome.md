## 23. K-Palindrome

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not1923/1)

### Problem Description

Given a string `str` of length `n`, determine if the string is a K-Palindrome. A K-Palindrome string is one that can be transformed into a palindrome by removing at most `k` characters from it.

**Examples:**

Example 1:

```
Input:
str = "abcdecba"
n = 8, k = 1
Output: 1
Explanation: By removing 'd' or 'e' we can make it a palindrome.
```

Example 2:

```
Input:
str = "abcdefcba"
n = 9, k = 1
Output: 0
Explanation: By removing a single character we cannot make it a palindrome.
```

### My Approach

1. **Initialization:**

   - Create two vectors `prev` and `curr` of size `n+1` initialized to 0, which will help store the length of the longest palindromic subsequence (LPS) dynamically.

2. **Dynamic Programming Table Calculation:**

   - Iterate through the string with two nested loops to fill the `curr` vector based on the previous results stored in `prev`.
   - If characters `str[i-1]` and `str[n-j]` are the same, update `curr[j]` to `prev[j-1] + 1`.
   - Otherwise, set `curr[j]` to the maximum of `prev[j]` and `curr[j-1]`.
   - Swap `prev` and `curr` for the next iteration.

3. **Determine Minimum Deletions:**
   - The length of the longest palindromic subsequence (LPS) is stored in `prev[n]` after the loops.
   - Calculate the minimum deletions needed to transform the string into a palindrome as `minDeletions = n - lps`.
   - If `minDeletions` is less than or equal to `k`, return 1, indicating the string is a K-Palindrome; otherwise, return 0.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n\*n), as we iterate through the string with two nested loops up to length `n`.
- **Expected Auxiliary Space Complexity:** O(n), as we use two vectors of size `n+1` for storing intermediate results.

## Code

#### C++

```cpp
class Solution {
public:
    int kPalindrome(string str, int n, int k) {
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str[i - 1] == str[n - j]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            swap(prev, curr);
        }

        int lps = prev[n];
        int minDeletions = n - lps;
        return minDeletions <= k ? 1 : 0;
    }
};
```

#### Java

```java
class Solution {
    public int kPalindrome(String str, int n, int k) {
        int[] prev = new int[n + 1];
        int[] curr = new int[n + 1];

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str.charAt(i - 1) == str.charAt(n - j)) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = Math.max(prev[j], curr[j - 1]);
                }
            }
            int[] temp = prev;
            prev = curr;
            curr = temp;
        }

        int lps = prev[n];
        int minDeletions = n - lps;
        return minDeletions <= k ? 1 : 0;
    }
}
```

#### Python

```python
class Solution:
    def kPalindrome(self, str, n, k):
        prev = [0] * (n + 1)
        curr = [0] * (n + 1)

        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if str[i - 1] == str[n - j]:
                    curr[j] = prev[j - 1] + 1
                else:
                    curr[j] = max(prev[j], curr[j - 1])
            prev, curr = curr, prev

        lps = prev[n]
        minDeletions = n - lps
        return 1 if minDeletions <= k else 0
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
