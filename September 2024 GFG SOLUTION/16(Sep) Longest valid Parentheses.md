# 16. Longest Valid Parentheses

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1)

### Problem Description

Given a string `str` consisting of opening and closing parentheses `'('` and `')'`, find the length of the longest valid parentheses substring.

A valid parentheses substring is defined as:

1. For every opening parenthesis `'('`, there is a corresponding closing parenthesis `')'`.
2. Parentheses must be closed in the correct order.

**Examples:**

- Input: `str = "((()"`

  - Output: `2`
  - Explanation: The longest valid parenthesis substring is `"()"`.

- Input: `str = ")()())"`
  - Output: `4`
  - Explanation: The longest valid parenthesis substring is `"()()"`.

### My Approach

The problem can be solved by traversing the string twice—once from left to right and once from right to left—counting the number of opening and closing parentheses.

1. **Two-pass traversal:**

   - _First pass (Left to Right)_:

     - Traverse the string from left to right.
     - Count `left` for opening parentheses `'('` and `right` for closing parentheses `')'`.
     - If `left == right`, we have a valid substring, and we update the maximum length.
     - If `right > left`, reset the counters to zero because an excess of closing parentheses breaks the balance.

   - _Second pass (Right to Left)_:
     - Traverse the string from right to left, applying the same logic but reversing the roles of `left` and `right` counters. This helps catch cases where there are unmatched opening parentheses at the end of the string.

2. **Reset and Compare:**

   - Whenever we encounter an imbalance (`right > left` or `left > right`), we reset the counters and move on. This ensures we only count balanced subsequences of parentheses.

3. **Final Answer:**
   - The maximum length encountered during both passes is the length of the longest valid parentheses substring.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|str|), since we traverse the string twice (left to right and right to left).
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space for the left and right counters.

### Code (C++)

```cpp
class Solution {
public:
    int maxLength(string& str) {
        int left = 0, right = 0, maxi = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                maxi = max(maxi, 2 * right);
            else if (right > left)
                left = right = 0;
        }
        left = right = 0;
        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                maxi = max(maxi, 2 * left);
            else if (left > right)
                left = right = 0;
        }

        return maxi;
    }
};
```

### Code (Java)

```java
class Solution{
    static int maxLength(String S){
        int left = 0, right = 0, maxi = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == '(')
                left++;
            else
                right++;

            if (left == right)
                maxi = Math.max(maxi, 2 * right);
            else if (right > left)
                left = right = 0;
        }
        left = right = 0;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S.charAt(i) == '(')
                left++;
            else
                right++;

            if (left == right)
                maxi = Math.max(maxi, 2 * left);
            else if (left > right)
                left = right = 0;
        }

        return maxi;
    }
}
```

### Code (Python)

```python
class Solution:
    def maxLength(self, s):
        left, right, maxi = 0, 0, 0
        for char in s:
            if char == '(':
                left += 1
            else:
                right += 1

            if left == right:
                maxi = max(maxi, 2 * right)
            elif right > left:
                left = right = 0
        left = right = 0
        for char in reversed(s):
            if char == '(':
                left += 1
            else:
                right += 1

            if left == right:
                maxi = max(maxi, 2 * left)
            elif left > right:
                left = right = 0

        return maxi
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
