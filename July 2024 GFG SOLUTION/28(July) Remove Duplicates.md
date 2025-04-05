## 28. Remove Duplicates

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-duplicates3034/1)

### Problem Description

Given a string `str` without spaces, the task is to remove all duplicate characters from it, keeping only the first occurrence.

**Note:** The original order of characters must be kept the same.

**Examples:**

Input:

```
str = "zvvo"
```

Output:

```
zvo
```

Explanation: Only keep the first occurrence.

### My Approach

1. **Initialization:**

- Create an array `fre` of size 26 initialized to 0, which will store the frequency of each character.
- Create an empty string or list `result` to store the final result.

2. **Iterate through the string:**

- For each character `c` in the string `str`, check if it has been encountered before by using the `fre` array.
- If `fre[c - 'a']` is 0, append the character `c` to `result` and mark it as encountered by setting `fre[c - 'a']` to 1.

3. **Return:**

- Join the characters in `result` (if using a list) and return the final string.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through each character of the string once.
- **Expected Auxiliary Space Complexity:** O(1), as we use a fixed size array of 26 elements and a result string, which grows linearly with the input size.

### Code (C++)

```cpp
class Solution {
public:
    string removeDups(string str) {
        int fre[26] = {0};
        string result = "";

        for (char c : str) {
            if (fre[c - 'a'] == 0) {
                result += c;
                fre[c - 'a'] = 1;
            }
        }

        return result;
    }
};
```

### Code (Java)

```java
class Solution {
    public String removeDups(String str) {
        int[] fre = new int[26];
        StringBuilder result = new StringBuilder();

        for (char c : str.toCharArray()) {
            if (fre[c - 'a'] == 0) {
                result.append(c);
                fre[c - 'a'] = 1;
            }
        }

        return result.toString();
    }
}
```

### Code (Python)

```python
class Solution:
    def removeDups(self, str):
        fre = [0] * 26
        result = []

        for c in str:
            if fre[ord(c) - ord('a')] == 0:
                result.append(c)
                fre[ord(c) - ord('a')] = 1

        return ''.join(result)
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
