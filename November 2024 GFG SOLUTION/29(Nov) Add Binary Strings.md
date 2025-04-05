# _29. Add Binary Strings_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/add-binary-strings3805/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised in the poll, I’ve started solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My latest solution is now live:  
  **[2577. Minimum Time to Visit a Cell In a Grid](https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2577.Minimum%20Time%20to%20Visit%20a%20Cell%20In%20a%20Grid.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2577.Minimum%20Time%20to%20Visit%20a%20Cell%20In%20a%20Grid.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2577.Minimum%20Time%20to%20Visit%20a%20Cell%20In%20a%20Grid.md">
  <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
</div>

<br/>

## Problem Description

You are given two binary strings `s1` and `s2` consisting of only `0`s and `1`s. Find the resultant string after adding the two binary strings. The input strings may contain leading zeros, but the output string should not have any leading zeros.

### Examples:

**Input:**  
`s1 = "1101"`, `s2 = "111"`  
**Output:**  
`"10100"`

**Explanation:**

```
 1101
+ 111
—————
10100
```

**Input:**  
`s1 = "00100"`, `s2 = "010"`  
**Output:**  
`"110"`

**Explanation:**

```
 100
+ 10
 ———
 110
```

### Constraints:

- $`1 <= s1.size(), s2.size() <= 10^6`$

## My Approach

1. **Binary Addition Logic:**

   - The problem is a standard binary addition problem. We will iterate through the two strings from right to left, adding corresponding bits and considering a carry.
   - If both bits are `1`, we set the sum bit to `0` and carry `1`. If one bit is `1`, the sum bit is `1` with no carry, and if both bits are `0`, the sum bit is `0` with no carry.
   - The process continues until all digits are processed, and the carry is added if necessary.

2. **Steps:**
   - Start from the rightmost bit of both strings, keeping track of any carry from the previous step.
   - Add corresponding bits, including the carry, and append the result to a result string.
   - Continue the process until both strings are exhausted.
   - Reverse the result string (since we process from right to left) and remove any leading zeros.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the length of the longest string. We only perform a linear scan through the strings to perform the addition.
- **Expected Auxiliary Space Complexity:** O(n), as we store the result in a new string that may be of length up to the size of the input strings.

## Code (C++)

```cpp
class Solution {
public:
    string addBinary(const string& s1, const string& s2) {
        int i = s1.size() - 1, j = s2.size() - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        size_t first_non_zero = result.find_first_not_of('0');
        return (first_non_zero != string::npos) ? result.substr(first_non_zero) : "0";
    }
};
```

## Code (Java)

```java
class Solution {
    public String addBinary(String s1, String s2) {
        int n1 = s1.length(), n2 = s2.length();
        StringBuilder result = new StringBuilder();

        int carry = 0;
        int i = n1 - 1, j = n2 - 1;

        while (i >= 0 || j >= 0 || carry == 1) {
            int sum = carry;

            if (i >= 0) sum += s1.charAt(i--) - '0';
            if (j >= 0) sum += s2.charAt(j--) - '0';

            result.append(sum % 2);
            carry = sum / 2;
        }

        result.reverse();

        while (result.length() > 1 && result.charAt(0) == '0') {
            result.deleteCharAt(0);
        }

        return result.toString();
    }
}
```

## Code (Python)

```python
class Solution:
    def addBinary(self, s1, s2):
        i, j = len(s1) - 1, len(s2) - 1
        carry = 0
        result = []

        while i >= 0 or j >= 0 or carry > 0:
            sum_ = carry
            if i >= 0:
                sum_ += int(s1[i])
                i -= 1
            if j >= 0:
                sum_ += int(s2[j])
                j -= 1
            result.append(str(sum_ % 2))
            carry = sum_ // 2

        result.reverse()
        result_str = ''.join(result)
        first_non_zero = result_str.find('1')
        return result_str[first_non_zero:] if first_non_zero != -1 else "0"
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
