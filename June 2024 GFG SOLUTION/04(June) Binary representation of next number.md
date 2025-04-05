## 04. Binary Representation of Next Number

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1)

### Problem Description

Given a binary representation in the form of a string `s` of a number `n`, the task is to find the binary representation of `n + 1`.

**Example:**

Input:

```
s = "10"
```

Output:

```
11
```

Explanation:
"10" is the binary representation of 2, and the binary representation of 3 is "11".

Input:

```
s = "111"
```

Output:

```
1000
```

Explanation:
"111" is the binary representation of 7, and the binary representation of 8 is "1000".

### Approach

1. **Initialization:**

   - Remove leading zeros from the string `s`.
   - If `s` becomes empty after removing leading zeros, set `s` to "0".

2. **Binary Addition:**

   - Convert the string `s` to a character array for easier manipulation.
   - Iterate from the last character to the first, simulating binary addition with a carry.
   - If a '0' is found, change it to '1' and stop the carry.
   - If a '1' is found, change it to '0' and continue the carry.
   - If the carry is still present after the loop, prepend '1' to the string.

3. **Return:**
   - Convert the character array back to a string and return it.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the length of the string `s`, as we iterate through the string once.
- **Expected Auxiliary Space Complexity:** O(n), as we store the resultant string in a character array of size `n`.

### Code

#### C++

```cpp
class Solution {
public:
    string binaryNextNumber(string s) {
        s.erase(0, s.find_first_not_of('0'));
        if (s.empty()) s = "0";
        int n = s.size();
        bool carry = true;
        for (int i = n - 1; i >= 0 && carry; --i) {
            if (s[i] == '0') {
                s[i] = '1';
                carry = false;
            } else {
                s[i] = '0';
            }
        }
        if (carry) {
            s = '1' + s;
        }
        return s;
    }
};
```

#### Java

```java
class Solution {
    String binaryNextNumber(String s) {
        s = s.replaceFirst("^0+(?!$)", "");
        if (s.isEmpty()) s = "0";

        int n = s.length();
        boolean carry = true;
        char[] charArray = s.toCharArray();
        for (int i = n - 1; i >= 0 && carry; --i) {
            if (charArray[i] == '0') {
                charArray[i] = '1';
                carry = false;
            } else {
                charArray[i] = '0';
            }
        }
        if (carry) {
            s = '1' + new String(charArray);
        } else {
            s = new String(charArray);
        }

        return s;
    }
}
```

#### Python

```python
class Solution:
    def binaryNextNumber(self, s):
        s = s.lstrip('0')
        if not s:
            s = '0'
        n = len(s)
        carry = True
        char_array = list(s)
        for i in range(n - 1, -1, -1):
            if char_array[i] == '0':
                char_array[i] = '1'
                carry = False
                break
            else:
                char_array[i] = '0'
        if carry:
            s = '1' + ''.join(char_array)
        else:
            s = ''.join(char_array)

        return s
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
