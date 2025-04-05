## 16. Remaining String

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remaining-string3515/1)

### Problem Description

Given a string `s` without spaces, a character `ch`, and an integer `count`, return the substring that remains after the character `ch` has appeared `count` number of times. Assume upper case and lower case alphabets are different. Return an empty string if it is not possible or the remaining substring is empty.

**Example:**

Input:

```
s = "Thisisdemostring", ch = 'i', count = 3
```

Output:

```
ng
```

Explanation:
The remaining substring of `s` after the 3rd occurrence of 'i' is "ng", hence the output is "ng".

### My Approach

1. **Initialization:**

- Initialize a variable `occ` to count the occurrences of the character `ch` in the string `s`.

2. **Iteration through the string:**

- Iterate through each character in the string `s`.
- For each character, check if it matches `ch`.
- If it matches, increment the `occ` counter.
- When `occ` equals `count`, check if the next character exists in the string.
  - If it exists, return the substring starting from the next character.
  - If it does not exist, return an empty string.

3. **Return:**

- If the loop completes and `occ` is less than `count`, return an empty string.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|s|), as we iterate through the string `s` once.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    string printString(const string &str, char ch, int count) {
        int occ = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ch) {
                occ++;
            }
            if (occ == count) {
                if (i + 1 < str.size()) {
                    return str.substr(i + 1);
                } else {
                    return "";
                }
            }
        }
        return "";
    }
};
```

### Code (Java)

```java
class Solution {
    public String printString(String s, char ch, int count) {
        int occ = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ch) {
                occ++;
            }
            if (occ == count) {
                if (i + 1 < s.length()) {
                    return s.substring(i + 1);
                } else {
                    return "";
                }
            }
        }
        return "";
    }
}
```

### Code (Python)

```python
class Solution:
    def printString(self, s, ch, count):
        occ = 0

        for i in range(len(s)):
            if s[i] == ch:
                occ += 1
            if occ == count:
                if i + 1 < len(s):
                    return s[i + 1:]
                else:
                    return ""
        return ""
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
