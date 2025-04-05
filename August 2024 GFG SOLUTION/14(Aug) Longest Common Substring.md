# <b>14. Longest Common Substring</b>

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-common-substring1452/1)

## Problem Description

Given two strings, `str1` and `str2`, your task is to find the length of the longest common substring between the two given strings.

### Examples:

**Example 1:**

- **Input:**
  ```
  str1 = "ABCDGH"
  str2 = "ACDGHR"
  ```
- **Output:**
  ```
  4
  ```
- **Explanation:** The longest common substring is `"CDGH"`, which has a length of 4.

### Constraints:

- `1 <= str1.size(), str2.size() <= 1000`
- Both strings may contain upper and lower case alphabets.

### My Approach

1. **Dynamic Programming Table Initialization:**

   - Create two 1D arrays `prev` and `curr`, each of size `m + 1`, where `m` is the length of `str2`. These arrays will store the lengths of the longest common suffixes of substrings ending at different positions in `str1` and `str2`.

2. **Iterative Computation:**

   - Iterate through each character of `str1` and `str2`. If characters match, update the corresponding cell in the `curr` array to be `1 + prev[j - 1]`, where `j` is the current index in `str2`.
   - If characters do not match, set the current cell to `0` as no common substring ends here.
   - Track the maximum value in `curr` during the iterations, which represents the length of the longest common substring found so far.

3. **Final Result:**
   - After processing all characters, the maximum value stored represents the length of the longest common substring.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* m), where `n` and `m` are the lengths of `str1` and `str2` respectively. This is because we need to iterate through all pairs of characters from the two strings.
- **Expected Auxiliary Space Complexity:** O(m), where `m` is the length of `str2`. We use two 1D arrays of size `m + 1` to store the lengths of the common suffixes.

### Code (C++)

```cpp
class Solution {
public:
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int res = 0;

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    res = max(res, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return res;
    }
};
```

### Code (Java)

```java
class Solution {
    public int longestCommonSubstr(String str1, String str2) {
        int n = str1.length(), m = str2.length();
        int res = 0;

        int[] prev = new int[m + 1];
        int[] curr = new int[m + 1];

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    curr[j] = 1 + prev[j - 1];
                    res = Math.max(res, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr.clone();
        }
        return res;
    }
}
```

### Code (Python)

```python
class Solution:
    def longestCommonSubstr(self, str1, str2):
        n, m = len(str1), len(str2)
        res = 0

        prev = [0] * (m + 1)
        curr = [0] * (m + 1)

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if str1[i - 1] == str2[j - 1]:
                    curr[j] = 1 + prev[j - 1]
                    res = max(res, curr[j])
                else:
                    curr[j] = 0
            prev = curr[:]

        return res
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
