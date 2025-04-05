## 15. Smallest Number

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/smallest-number5829/1)

### Problem Description

Given two integers `s` and `d`, the task is to find the smallest number such that the sum of its digits is `s` and the number of digits in the number are `d`. Return a string that is the smallest possible number. If it is not possible, then return `-1`.

**Example:**

Input:

```
s = 9, d = 2
```

Output:

```
18
```

Explanation:
18 is the smallest number possible with the sum of digits = 9 and total digits = 2.

### My Approach

1. **Check Feasibility:**

- If the sum `s` is greater than `9 * d`, it is not possible to create such a number. Return `-1` in this case.

2. **Initialization:**

- Create a string `result` with `d` zeros.
- Decrement `s` by 1 to handle the smallest non-zero digit scenario.

3. **Digit Assignment:**

- Iterate from the rightmost digit to the leftmost.
- Assign the maximum possible digit (9 or less) to each position until the sum `s` is exhausted.

4. **Adjust the First Digit:**

- Add 1 to the first digit to compensate for the initial decrement of `s`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(d), as we iterate through the digits up to `d`.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    string smallestNumber(int s, int d) {
        if (s > 9 * d) return "-1";

        string result(d, '0');
        s--;

        for (int i = d - 1; i >= 0; i--) {
            if (s > 9) {
                result[i] = '9';
                s -= 9;
            } else {
                result[i] = '0' + s;
                s = 0;
            }
        }
        result[0] = '1' + result[0] - '0';
        return result;
    }
};
```

### Code (Java)

```java
class Solution {
    public String smallestNumber(int s, int d) {
        if (s > 9 * d) return "-1";

        char[] result = new char[d];
        Arrays.fill(result, '0');
        s--;

        for (int i = d - 1; i >= 0; i--) {
            if (s > 9) {
                result[i] = '9';
                s -= 9;
            } else {
                result[i] = (char) ('0' + s);
                s = 0;
            }
        }
        result[0] = (char) (result[0] + 1);
        return new String(result);
    }
}
```

### Code (Python)

```python
class Solution:
    def smallestNumber(self, s, d):
        if s > 9 * d:
            return "-1"

        result = ['0'] * d
        s -= 1

        for i in range(d - 1, -1, -1):
            if s > 9:
                result[i] = '9'
                s -= 9
            else:
                result[i] = chr(ord('0') + s)
                s = 0

        result[0] = chr(ord(result[0]) + 1)
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
