# _22. Longest Prefix Suffix_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1)

### Problem Description

Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

**Note:** Prefix and suffix can be overlapping but they should not be equal to the entire string.

### Examples:

Input: `str = "abab"`  
Output: `2`  
Explanation: "ab" is the longest proper prefix and suffix.

Input: `str = "aaaa"`  
Output: `3`  
Explanation: "aaa" is the longest proper prefix and suffix.

### My Approach

1. **LPS Array Construction:**

   - Use an array `lpsArr` where `lpsArr[i]` stores the length of the longest proper prefix which is also a proper suffix for the substring `str[0...i]`.

2. **Initialization:**

   - Start with the first character; the longest prefix suffix for a single character is always 0.

3. **Iterate through the String:**
   - For each character in the string, update the `lpsArr`:
     - If the current character matches the character at index `j`, increment `j` and set `lpsArr[i]` to `j`.
     - If there’s a mismatch and `j` is not zero, update `j` using the previously calculated values in `lpsArr`.
4. **Final Answer:**
   - The value at the last index of `lpsArr` will give the length of the longest proper prefix which is also a proper suffix.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|str|), where |str| is the length of the string, as we only iterate through the string once.
- **Expected Auxiliary Space Complexity:** O(|str|), due to the LPS array that stores prefix-suffix lengths for each substring.

### Code (C++)

```cpp
class Solution {
public:
    int lps(const string& str) {
        int n = str.size();
        if (n == 0) return 0;
        vector<int> lpsArr(n, 0);
        int j = 0;
        for (int i = 1; i < n; i++) {
            while (j > 0 && str[i] != str[j]) {
                j = lpsArr[j - 1];
            }
            if (str[i] == str[j]) {
                j++;
            }
            lpsArr[i] = j;
        }
        return lpsArr[n - 1];
    }
};
```

### Code (Java)

```java
class Solution {
    public int lps(String str) {
        int n = str.length();
        if (n == 0) return 0;

        int[] lpsArr = new int[n];
        int j = 0;

        for (int i = 1; i < n; i++) {
            while (j > 0 && str.charAt(i) != str.charAt(j)) {
                j = lpsArr[j - 1];
            }
            if (str.charAt(i) == str.charAt(j)) {
                j++;
            }
            lpsArr[i] = j;
        }
        return lpsArr[n - 1];
    }
}
```

### Code (Python)

```python
class Solution:
    def lps(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0

        lpsArr = [0] * n
        j = 0

        for i in range(1, n):
            while j > 0 and s[i] != s[j]:
                j = lpsArr[j - 1]
            if s[i] == s[j]:
                j += 1
            lpsArr[i] = j

        return lpsArr[n - 1]
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
