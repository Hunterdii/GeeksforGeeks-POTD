## 06. Validate an IP Address

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/validate-an-ip-address-1587115621/1)

### Problem Description

You are given a string `str` in the form of an IPv4 address. Your task is to validate the IPv4 address. If it is valid, return `true`; otherwise, return `false`.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1.

A valid IPv4 address is of the form `x1.x2.x3.x4` where `0 <= x1, x2, x3, x4 <= 255`. Thus, we can write the generalized form of an IPv4 address as `(0-255).(0-255).(0-255).(0-255)`.

**Note:** Here we are considering numbers only from 0 to 255, and any additional leading zeroes will be considered invalid.

**Examples:**

Input:

```
str = "222.111.111.111"
```

Output:

```
true
```

Explanation:
The IPv4 address is as per the criteria mentioned, and all four decimal numbers lie in the specified range.

Input:

```
str = "5555..555"
```

Output:

```
false
```

Explanation:
"5555..555" is not a valid IPv4 address, as the middle two portions are missing.

### My Approach

1. **Initialization:**

- Define variables `segments`, `num`, and `length` to keep track of the number of segments, the current number, and the length of the current number, respectively.

2. **Validation Loop:**

- Iterate through each character in the string `str`.
- If the character is a dot (`.`):
  - Check if the `length` is between 1 and 3 and the `num` is between 0 and 255.
  - If any of these checks fail, return `false`.
  - Increment `segments`, reset `num`, and `length`.
- If the character is a digit:
  - Check if the current segment starts with '0' and is not followed by a dot.
  - Calculate the new `num` and increment `length`.
- If the character is neither a dot nor a digit, return `false`.

3. **Final Checks:**

- Ensure the last segment is valid by checking the `length` and `num`.
- Ensure there are exactly four segments.

4. **Return:**

- Return `true` if the IP address is valid, otherwise `false`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through each character in the string once.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int isValid(string str) {
        int n = str.size();
        int segments = 0;
        int num = 0;
        int length = 0;

        for (int i = 0; i < n; ++i) {
            if (str[i] == '.') {
                if (length == 0 || length > 3 || num > 255) return 0;
                segments++;
                num = 0;
                length = 0;
            } else if (isdigit(str[i])) {
                if (length == 0 && str[i] == '0' && (i + 1 < n && str[i + 1] != '.')) return 0;
                num = num * 10 + (str[i] - '0');
                length++;
            } else {
                return 0;
            }
        }

        if (length == 0 || length > 3 || num > 255) return 0;
        segments++;

        return segments == 4 ? 1 : 0;
    }
};
```

### Code (Java)

```java
class Solution {

    public boolean isValid(String str) {
        int n = str.length();
        int segments = 0;
        int num = 0;
        int length = 0;

        for (int i = 0; i < n; ++i) {
            if (str.charAt(i) == '.') {
                if (length == 0 || length > 3 || num > 255)
                    return false;
                segments++;
                num = 0;
                length = 0;
            } else if (Character.isDigit(str.charAt(i))) {
                if (length == 0 && str.charAt(i) == '0' && (i + 1 < n && str.charAt(i + 1) != '.'))
                    return false;
                num = num * 10 + (str.charAt(i) - '0');
                length++;
            } else {
                return false;
            }
        }

        if (length == 0 || length > 3 || num > 255)
            return false;
        segments++;

        return segments == 4;
    }
}
```

### Code (Python)

```python
class Solution:
    def isValid(self, str):
        n = len(str)
        segments = 0
        num = 0
        length = 0

        for i in range(n):
            if str[i] == '.':
                if length == 0 or length > 3 or num > 255:
                    return False
                segments += 1
                num = 0
                length = 0
            elif str[i].isdigit():
                if length == 0 and str[i] == '0' and (i + 1 < n and str[i + 1] != '.'):
                    return False
                num = num * 10 + int(str[i])
                length += 1
            else:
                return False

        if length == 0 or length > 3 or num > 255:
            return False
        segments += 1

        return segments == 4
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
