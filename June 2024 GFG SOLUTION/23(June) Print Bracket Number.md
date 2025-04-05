## 23. Print Bracket Numbers

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-bracket-number4058/1)

### Problem Description

Given a string `str`, the task is to find the bracket numbers, i.e., for each bracket in `str`, return `i` if the bracket is the `i`th opening or closing bracket to appear in the string.

**Examples:**

Input:

```
str = "(aa(bdc))p(dee)"
```

Output:

```
1 2 2 1 3 3
```

Explanation:
The highlighted brackets in the given string (aa(bdc))p(dee) are assigned the numbers as: 1 2 2 1 3 3.

### My Approach

1. **Initialization:**

   - Use a counter `op` to keep track of the number of opening brackets encountered.
   - Use a vector `v` (or list in Python) to store the bracket numbers.
   - Use a stack `st` to maintain the sequence of opening brackets.

2. **Bracket Number Calculation:**

   - Iterate through each character in the string `str`.
   - If the character is an opening bracket `(`:
     - Increment the `op` counter.
     - Push the current value of `op` onto the stack.
     - Append the current value of `op` to the vector `v`.
   - If the character is a closing bracket `)`:
     - Append the top value of the stack (which corresponds to the matching opening bracket) to the vector `v`.
     - Pop the top value from the stack.

3. **Return:**
   - Return the vector `v` containing the bracket numbers.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|str|), as we iterate through each character of the string once.
- **Expected Auxiliary Space Complexity:** O(|str|), as we use a stack to store the opening brackets and a vector to store the results.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> bracketNumbers(string& str) {
        int op = 0;
        vector<int> v;
        vector<int> st;

        for (auto& c : str) {
            if (c == '(') {
                op++;
                st.push_back(op);
                v.push_back(op);
            } else if (c == ')') {
                v.push_back(st.back());
                st.pop_back();
            }
        }
        return v;
    }
};
```

### Code (Java)

```java
class Solution {
    ArrayList<Integer> bracketNumbers(String str) {
        int op = 0;
        ArrayList<Integer> result = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();

        for (char c : str.toCharArray()) {
            if (c == '(') {
                op++;
                stack.push(op);
                result.add(op);
            } else if (c == ')') {
                result.add(stack.pop());
            }
        }
        return result;
    }
}
```

### Code (Python)

```python
class Solution:
    def bracketNumbers(self, str):
        op = 0
        result = []
        stack = []

        for c in str:
            if c == '(':
                op += 1
                stack.append(op)
                result.append(op)
            elif c == ')':
                result.append(stack.pop())

        return result
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
