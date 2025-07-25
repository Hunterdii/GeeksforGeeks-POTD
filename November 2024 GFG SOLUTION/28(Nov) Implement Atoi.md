# _28. Implement Atoi_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/implement-atoi/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised in the poll, I’ve started solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My latest solution is now live:  
  **[2290. Minimum Obstacle Removal to Reach Corner](https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2290.Minimum%20Obstacle%20Removal%20to%20Reach%20Corner.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2290.Minimum%20Obstacle%20Removal%20to%20Reach%20Corner.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2290.Minimum%20Obstacle%20Removal%20to%20Reach%20Corner.md">
  <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
</div>

<br/>

## Problem Description

You are given a string `s` that represents a potential integer value. Your task is to implement the **atoi()** function, which converts the string to an integer, following these steps:

1. Skip any leading whitespaces.
2. Check for a sign (`+` or `-`), default to positive if no sign is present.
3. Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
4. Handle overflow: If the result exceeds the 32-bit signed integer range (`[-2^31, 2^31 - 1]`), return the appropriate bound.

### Examples:

**Input:**  
`s = "-123"`  
**Output:**  
`-123`

**Explanation:**  
The string can be converted to the integer `-123`, which is within the 32-bit signed integer range.

**Input:**  
`s = "  -"`  
**Output:**  
`0`

**Explanation:**  
No digits are present after the sign, so the result is 0.

**Input:**  
`s = " 1231231231311133"`  
**Output:**  
`2147483647`

**Explanation:**  
The string exceeds the maximum 32-bit signed integer, so the result is clamped to `2147483647`.

**Input:**  
`s = "-999999999999"`  
**Output:**  
`-2147483648`

**Explanation:**  
The string is below the minimum 32-bit signed integer, so the result is clamped to `-2147483648`.

**Input:**  
`s = "  -0012gfg4"`  
**Output:**  
`-12`

**Explanation:**  
The string converts to `-12`, ignoring the non-digit character `g`.

### Constraints:

- `1 ≤ |s| ≤ 15`
- The string length will be between 1 and 15 characters.

## My Approach

1. **Skip Leading Whitespaces**:  
   We begin by skipping any leading whitespace characters to focus on the number.

2. **Handle Signs**:  
   If the next character is a sign (`+` or `-`), we determine whether the result should be positive or negative.

3. **Read Digits**:  
   As we read digits, we accumulate the result. If a non-digit character is encountered, we stop processing.

4. **Handle Overflow**:  
   If the result exceeds the limits of a 32-bit signed integer (`-2^31` to `2^31 - 1`), return the appropriate boundary value.

5. **Return the Result**:  
   The final integer is returned after handling potential overflow and sign.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the length of the string. We iterate through the string only twice: once to skip spaces and check the sign, and once to process the digits.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to store variables for the result and current index.

## Code (C)

```c
int myAtoi(char *s) {
    int idx = 0, sign = 1;
    long res = 0;

    while (s[idx] == ' ') idx++;

    if (s[idx] == '-' || s[idx] == '+') {
        sign = (s[idx++] == '-') ? -1 : 1;
    }

    while (s[idx] >= '0' && s[idx] <= '9') {
        res = res * 10 + (s[idx++] - '0');

        if (res * sign > INT_MAX) return INT_MAX;
        if (res * sign < INT_MIN) return INT_MIN;
    }

    return (int)(res * sign);
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    int myAtoi(char *s) {
        int idx = 0, sign = 1;
        long res = 0;

        while (s[idx] == ' ') idx++;

        if (s[idx] == '-' || s[idx] == '+') {
            sign = (s[idx++] == '-') ? -1 : 1;
        }

        while (s[idx] >= '0' && s[idx] <= '9') {
            res = res * 10 + (s[idx++] - '0');

            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
        }

        return static_cast<int>(res * sign);
    }
};
```

## Code (Java)

```java
class Solution {
    public int myAtoi(String s) {
        int idx = 0, sign = 1;
        long res = 0;

        while (idx < s.length() && s.charAt(idx) == ' ') idx++;

        if (idx < s.length() && (s.charAt(idx) == '-' || s.charAt(idx) == '+')) {
            sign = (s.charAt(idx++) == '-') ? -1 : 1;
        }

        while (idx < s.length() && s.charAt(idx) >= '0' && s.charAt(idx) <= '9') {
            res = res * 10 + (s.charAt(idx++) - '0');

            if (res * sign > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (res * sign < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        }

        return (int)(res * sign);
    }
}
```

## Code (Python)

```python
class Solution:
    def myAtoi(self, s: str) -> int:
        idx, sign, res = 0, 1, 0

        while idx < len(s) and s[idx] == ' ':
            idx += 1

        if idx < len(s) and (s[idx] == '-' or s[idx] == '+'):
            sign = -1 if s[idx] == '-' else 1
            idx += 1

        while idx < len(s) and '0' <= s[idx] <= '9':
            res = res * 10 + (ord(s[idx]) - ord('0'))
            idx += 1

            if res * sign > 2**31 - 1:
                return 2**31 - 1
            if res * sign < -2**31:
                return -2**31

        return sign * res
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" />
</p>
