# _19. Reverse Words_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1)

### Problem Description

Given a string `str`, reverse the string without reversing its individual words. Words are separated by dots.

**Note:** The last character is not a dot.

_Examples:_

Input:  
`str = "i.like.this.program.very.much"`  
Output:  
`"much.very.program.this.like.i"`

Explanation: After reversing the whole string (not individual words), the input string becomes `"much.very.program.this.like.i"`.

Input:  
`str = "pqr.mno"`  
Output:  
`"mno.pqr"`

Explanation: After reversing the whole string, the input string becomes `"mno.pqr"`.

### My Approach

1. **Iterate Backwards:**

   - Traverse the string from the last character to the first.
   - Every time a dot (`.`) is encountered, extract the word from the position after the dot to the current position and append it to the result string.
   - Continue this process until all words are appended in reverse order.

2. **Final Touch:**
   - Add the last word, which doesn't have a preceding dot, after the loop ends.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|str|), where |str| is the length of the input string. This is because we are iterating over the string once to reverse the words.
- **Expected Auxiliary Space Complexity:** O(|str|), as we are using a new result string to store the reversed words.

### Code (C++)

```cpp
class Solution {
  public:
    string reverseWords(string str) {
        string result = "";
        int n = str.length();
        int end = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '.') {
                result.append(str.substr(i + 1, end - i)).append(".");
                end = i - 1;
            }
        }
        result.append(str.substr(0, end + 1));

        return result;
    }
};
```

### Code (Java)

```java
class Solution {
    String reverseWords(String str) {
        StringBuilder result = new StringBuilder();
        int n = str.length();
        int end = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (str.charAt(i) == '.') {
                result.append(str.substring(i + 1, end + 1)).append(".");
                end = i - 1;
            }
        }
        result.append(str.substring(0, end + 1));

        return result.toString();
    }
}
```

### Code (Python)

```python
class Solution:
    def reverseWords(self, str):
        result = []
        n = len(str)
        end = n - 1

        for i in range(n - 1, -1, -1):
            if str[i] == '.':
                result.append(str[i+1:end+1])
                result.append('.')
                end = i - 1
        result.append(str[:end+1])

        return ''.join(result)
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
