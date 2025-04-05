# _3. Min Chars to Add for Palindrome_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Continued ✨</h2>
</div>

- Continuing with **LeetCode Problem of the Day (POTD)** solutions! 🎯
- Here's my latest addition:  
  **[2109. Adding Spaces to a String](https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2109.Adding%20Spaces%20to%20a%20String.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2109.Adding%20Spaces%20to%20a%20String.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2109.Adding%20Spaces%20to%20a%20String.md">
    <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
  </a>
</div>

## Problem Description

Given a string `s`, find the minimum number of characters to be added at the front of the string to make it a palindrome.

A palindrome string is a sequence of characters that reads the same forward and backward.

## Examples:

**Input:**  
`s = "abc"`  
**Output:**  
`2`

**Explanation:**  
Add `b` and `c` to the front to make the string a palindrome: `"cbabc"`

**Input:**  
`s = "aacecaaaa"`  
**Output:**  
`2`

**Explanation:**  
Add `aa` at the front to make the string a palindrome: `"aaaacecaaaa"`

### Constraints:

- `1 <= s.size() <= 10^6`

## My Approach

### Key Idea:

The solution relies on combining the given string with its reverse using a separator (e.g., `$`) and computing the **Longest Prefix Suffix (LPS)** array for this combined string.

The last value in the LPS array gives the length of the longest palindromic suffix in the original string. Subtracting this value from the length of the original string provides the minimum number of characters to be added.

### Steps:

1. **Compute the Reverse String**:  
   Reverse the input string to identify palindromic suffixes.

2. **Combine Strings**:  
   Concatenate the input string, a separator (`$`), and the reversed string to form the combined string.

3. **Build LPS Array**:  
   Use the **Knuth-Morris-Pratt (KMP)** algorithm to compute the LPS array for the combined string.

4. **Calculate the Result**:  
   The minimum characters to be added is equal to `n - lps[m-1]`, where `lps[m-1]` is the last value in the LPS array, `n` is the length of the original string, and `m` is the length of the combined string.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity**: O(n), where `n` is the length of the string. Calculating the LPS array takes linear time.
- **Expected Auxiliary Space Complexity**: O(n), as the LPS array and the combined string require space proportional to the input size.

## Code (C)

```c
void computeLPSArray(char* pat, int M, int* lps) {
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M) {
        if (pat[i] == pat[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int minChar(char str[]) {
    int n = strlen(str);
    char revStr[n + 1];
    for (int i = 0; i < n; i++) {
        revStr[i] = str[n - i - 1];
    }
    revStr[n] = '\0';

    char combined[2 * n + 2];
    snprintf(combined, sizeof(combined), "%s$%s", str, revStr);

    int lps[2 * n + 2];
    computeLPSArray(combined, strlen(combined), lps);

    return n - lps[strlen(combined) - 1];
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    int minChar(string& str) {
        int n = str.length();
        string revStr = str;
        reverse(revStr.begin(), revStr.end());

        string combined = str + "$" + revStr;
        int m = combined.length();

        vector<int> lps(m, 0);
        for (int i = 1; i < m; i++) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }

        return n - lps.back();
    }
};
```

## Code (Java)

```java
class Solution {
    public static int minChar(String s) {
        int n = s.length();

        String revStr = new StringBuilder(s).reverse().toString();

        String combined = s + "$" + revStr;

        int[] lps = new int[combined.length()];
        for (int i = 1; i < combined.length(); i++) {
            int j = lps[i - 1];
            while (j > 0 && combined.charAt(i) != combined.charAt(j)) {
                j = lps[j - 1];
            }
            if (combined.charAt(i) == combined.charAt(j)) {
                j++;
            }
            lps[i] = j;
        }

        return n - lps[combined.length() - 1];
    }
}
```

## Code (Python)

```python
class Solution:
    def minChar(self, s):
        n = len(s)

        rev_str = s[::-1]

        combined = s + "$" + rev_str

        lps = [0] * len(combined)
        for i in range(1, len(combined)):
            j = lps[i - 1]
            while j > 0 and combined[i] != combined[j]:
                j = lps[j - 1]
            if combined[i] == combined[j]:
                j += 1
            lps[i] = j

        return n - lps[-1]
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
