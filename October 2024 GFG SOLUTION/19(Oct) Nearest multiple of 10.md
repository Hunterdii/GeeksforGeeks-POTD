# _19. Nearest Multiple of 10_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1)

### Problem Description

Given a string `str` representing a positive number, the task is to round `str` to the nearest multiple of 10. If two multiples are equally close to `str`, choose the smallest one.

### Example:

Input:  
`str = "29"`  
Output:  
`"30"`

**Explanation:** The close multiples are 20 and 30, and 30 is the nearest to 29.

Input:  
`str = "15"`  
Output:  
`"10"`

**Explanation:** 10 and 20 are equally distant from 15. The smallest of the two is 10.

### My Approach

1. **Check the Length of the Input String:**

   - If the string is empty, return it immediately.

2. **Extract the Last Digit:**

   - Convert the last character of the string to an integer to determine how to round.

3. **Round to the Nearest Multiple of 10:**

   - If the last digit is less than or equal to 5, change the last digit to '0'.
   - If the last digit is greater than 5, change the last digit to '0' and carry over the increment to the preceding digits, handling any cascading carries (e.g., from 9 to 0).

4. **Return the Result:**
   - If a carry occurs past the first digit, prepend '1' to the string.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the length of the input string, as we traverse the string to perform operations based on its length.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space for variables.

### Code (C++)

```cpp
class Solution {
public:
    string roundToNearest(string str) {
        int n = str.size();
        if (n == 0) return str;

        if (str[n - 1] - '0' <= 5) {
            str[n - 1] = '0';
            return str;
        } else {
            str[n - 1] = '0';
            int i = n - 2;

            while (i >= 0) {
                if (str[i] != '9') {
                    str[i] = (char)((str[i] - '0') + 1 + '0');
                    return str;
                }
                str[i] = '0';
                i--;
            }
            return "1" + str;
        }
    }
};
```

### Code (Java)

```java
class Solution {
    String roundToNearest(String str) {
        int n = str.length();
        if (n == 0) return str;

        int lastDigit = str.charAt(n - 1) - '0';

        if (lastDigit <= 5) {
            str = str.substring(0, n - 1) + '0';
        } else {
            str = str.substring(0, n - 1) + '0';
            int i = n - 2;

            while (i >= 0) {
                if (str.charAt(i) != '9') {
                    str = str.substring(0, i) + (char)(str.charAt(i) + 1) + str.substring(i + 1);
                    break;
                }
                str = str.substring(0, i) + '0' + str.substring(i + 1);
                i--;
            }
            if (i < 0) {
                str = '1' + str;
            }
        }
        return str;
    }
}
```

### Code (Python)

```python
class Solution:
    def roundToNearest(self, num_str: str) -> str:
        n = len(num_str)
        if n == 0:
            return num_str

        last_digit = int(num_str[-1])

        if last_digit <= 5:
            return num_str[:-1] + '0'
        else:
            num_str = num_str[:-1] + '0'
            i = n - 2

            while i >= 0:
                if num_str[i] != '9':
                    return num_str[:i] + chr(ord(num_str[i]) + 1) + num_str[i + 1:]
                num_str = num_str[:i] + '0' + num_str[i + 1:]
                i -= 1

            return '1' + num_str
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
