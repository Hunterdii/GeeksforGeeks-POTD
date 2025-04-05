# _08. Minimum Repeats to Make Substring_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1)

## Problem Description

Given two strings `s1` and `s2`, return the minimum number of times `s1` has to be repeated so that `s2` becomes a substring of the repeated `s1`. If `s2` cannot be a substring of any repeated version of `s1`, return `-1`.

### Examples:

**Input:**

```
s1 = "ww", s2 = "www"
```

**Output:**

```
2
```

**Explanation:** Repeating `s1` two times ("wwww"), `s2` is a substring of it.

**Input:**

```
s1 = "abcd", s2 = "cdabcdab"
```

**Output:**

```
3
```

**Explanation:** Repeating `s1` three times ("abcdabcdabcd"), `s2` is a substring. Less than 3 repeats would not contain `s2`.

**Input:**

```
s1 = "ab", s2 = "cab"
```

**Output:**

```
-1
```

**Explanation:** No matter how many times `s1` is repeated, `s2` can’t be a substring.

### Constraints:

1 ≤ |s1|, |s2| ≤ 10^5

## My Approach

1. **Repeated Concatenation Check:**
   - Initialize a repeated version of `s1` and keep appending `s1` to it until its length meets or exceeds `s2`’s length.
   - After each append, check if `s2` becomes a substring of this extended `s1`.
   - If it does, return the number of repetitions used.
2. **Pattern Matching with KMP Algorithm:**

   - Use the KMP (Knuth-Morris-Pratt) algorithm to efficiently search for `s2` within the extended repeated string of `s1`.
   - The `LPS` (Longest Prefix Suffix) array is computed for `s2` to enable efficient substring search.

3. **Edge Cases:**
   - If `s1` is already a substring of `s2`, return the number of repetitions found.
   - If no valid repetition count satisfies the substring condition, return `-1`.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + m), where `n` is the length of `s1` and `m` is the length of `s2`. This is because the KMP algorithm requires linear time to find a substring.
- **Expected Auxiliary Space Complexity:** O(m), as we need additional space to store the `LPS` array for `s2`.

## Code (C++)

```cpp
class Solution {
public:
    int minRepeats(string s1, string s2) {
        int repeat = 1;
        string repeatedStr = s1;

        while (repeatedStr.length() < s2.length()) {
            repeatedStr += s1;
            repeat++;
        }

        if (repeatedStr.find(s2) != string::npos)
            return repeat;

        repeatedStr += s1;
        repeat++;

        if (repeatedStr.find(s2) != string::npos)
            return repeat;

        return -1;
    }
};
```

## Code (Java)

```java
class Solution {

    static void computeLPSArray(String s, int[] lps) {
        int len = 0, idx = 1;
        lps[0] = 0;

        while (idx < s.length()) {
            if (s.charAt(idx) == s.charAt(len)) {
                len++;
                lps[idx] = len;
                idx++;
            } else {
                if (len == 0) {
                    lps[idx] = 0;
                    idx++;
                } else {
                    len = lps[len - 1];
                }
            }
        }
    }

    static boolean KMPSearch(String txt, String pat, int[] lps, int rep) {
        int n = txt.length(), m = pat.length();
        int i = 0, j = 0;

        while (i < n * rep) {
            if (txt.charAt(i % n) == pat.charAt(j)) {
                i++;
                j++;
                if (j == m) return true;
            } else {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return false;
    }

    static int minRepeats(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();
        int[] lps = new int[m];
        computeLPSArray(s2, lps);

        int x = (m + n - 1) / n;
        if (KMPSearch(s1, s2, lps, x)) return x;
        if (KMPSearch(s1, s2, lps, x + 1)) return x + 1;

        return -1;
    }
}
```

## Code (Python)

```python
class Solution:
    def computeLPSArray(self, s):
        lps = [0] * len(s)
        len_ = 0
        idx = 1

        while idx < len(s):
            if s[idx] == s[len_]:
                len_ += 1
                lps[idx] = len_
                idx += 1
            else:
                if len_ == 0:
                    lps[idx] = 0
                    idx += 1
                else:
                    len_ = lps[len_ - 1]
        return lps

    def KMPSearch(self, txt, pat, lps, rep):
        n, m = len(txt), len(pat)
        i = j = 0

        while i < n * rep:
            if txt[i % n] == pat[j]:
                i += 1
                j += 1
                if j == m:
                    return True
            else:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
        return False

    def minRepeats(self, s1, s2):
        n, m = len(s1), len(s2)
        lps = self.computeLPSArray(s2)
        x = (m + n - 1) // n
        if self.KMPSearch(s1, s2, lps, x):
            return x
        if self.KMPSearch(s1, s2, lps, x + 1):
            return x + 1
        return -1
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
