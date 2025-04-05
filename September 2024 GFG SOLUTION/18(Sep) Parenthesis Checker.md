# **18. Parenthesis Checker**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1)

### Problem Description

Given an expression string `x`, examine whether the pairs and orders of `{}`, `()`, and `[]` are correct in the expression. Return `true` if the expression is balanced, and `false` otherwise.

For example:

- Input: `{([])}`
- Output: `true`

Explanation: All the opening brackets `{`, `[`, and `(` have corresponding closing brackets `}`, `]`, and `)` in the correct order.

- Input: `([)]`
- Output: `false`

Explanation: The square bracket is opened but closed in the wrong order, making the expression unbalanced.

### My Approach

1. **Stack Data Structure:**

   - Utilize a stack to keep track of opening brackets. Whenever we encounter a closing bracket, we check the stack to ensure that it matches the latest opening bracket.

2. **Bracket Matching Logic:**

   - For each character in the string:
     - If it’s an opening bracket (`{`, `(`, `[`), push it onto the stack.
     - If it’s a closing bracket (`}`, `)`, `]`), check if the stack is empty. If it is, return `false` because there’s no corresponding opening bracket.
     - Otherwise, pop the stack and ensure that the popped opening bracket matches the closing one.
   - If the stack is empty after processing the entire string, the expression is balanced.

3. **Edge Cases:**
   - If the string is empty, return `true`.
   - Handle mismatched or leftover opening brackets in the stack after iterating through the string.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the length of the input string `x`, since we process each character in the string once.
- **Expected Auxiliary Space Complexity:** O(n), because the stack can hold up to `n/2` opening brackets in the worst case.

### Code (C++)

```cpp
class Solution {
public:
    bool ispar(string x) {
        stack<char> s;
        for (char c : x) {
            switch(c) {
                case '(': case '{': case '[':
                    s.push(c);
                    break;
                case ')':
                    if (s.empty() || s.top() != '(') return false;
                    s.pop();
                    break;
                case '}':
                    if (s.empty() || s.top() != '{') return false;
                    s.pop();
                    break;
                case ']':
                    if (s.empty() || s.top() != '[') return false;
                    s.pop();
                    break;
            }
        }
        return s.empty();
    }
};
```

### Code (Java)

```java
class Solution {
    static boolean ispar(String x) {
        Stack<Character> s = new Stack<>();

        for (char c : x.toCharArray()) {
            switch(c) {
                case '(': case '{': case '[':
                    s.push(c);
                    break;
                case ')':
                    if (s.isEmpty() || s.pop() != '(') return false;
                    break;
                case '}':
                    if (s.isEmpty() || s.pop() != '{') return false;
                    break;
                case ']':
                    if (s.isEmpty() || s.pop() != '[') return false;
                    break;
            }
        }
        return s.isEmpty();
    }
}
```

### Code (Python)

```python
class Solution:
    def ispar(self, x):
        stack = []

        for c in x:
            if c in "({[":
                stack.append(c)
            elif c == ')':
                if not stack or stack.pop() != '(':
                    return False
            elif c == '}':
                if not stack or stack.pop() != '{':
                    return False
            elif c == ']':
                if not stack or stack.pop() != '[':
                    return False

        return not stack
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
