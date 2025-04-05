## 31. Swap Two Nibbles in a Byte

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1)

### Problem Description

Given a number `n`, your task is to swap the two nibbles and find the resulting number.

A nibble is a four-bit aggregation, or half an octet. There are two nibbles in a byte. For example, the decimal number 150 is represented as 10010110 in an 8-bit byte. This byte can be divided into two nibbles: 1001 and 0110.

**Example:**

Input:

```
n = 100
```

Output:

```
70
```

Explanation:
100 in binary is 01100100, two nibbles are (0110) and (0100). If we swap the two nibbles, we get 01000110 which is 70 in decimal.

### Approach

To solve this problem, follow these steps:

1. **Masking and Shifting:**

   - Extract the right nibble (the last 4 bits) by performing a bitwise AND with `0x0F` and left shift it by 4 positions.
   - Extract the left nibble (the first 4 bits) by performing a bitwise AND with `0xF0` and right shift it by 4 positions.

2. **Combine Nibbles:**

   - Combine the two extracted nibbles using a bitwise OR operation.

3. **Return Result:**
   - Return the result of the combination which is the integer value after swapping the nibbles.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1), as we perform a constant number of operations regardless of the input size.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code

#### C++

```cpp
class Solution {
public:
    int swapNibbles(int n) {
        int rn = (n & 0xF0) >> 4;
        int ln = (n & 0x0F) << 4;
        return rn | ln;
    }
};
```

#### Java

```java
class Solution {
    static int swapNibbles(int n) {
        int rn = (n & 0xF0) >> 4;
        int ln = (n & 0x0F) << 4;
        return rn | ln;
    }
}
```

#### Python

```python
class Solution:
    def swapNibbles(self, n: int) -> int:
        rn = (n & 0xF0) >> 4
        ln = (n & 0x0F) << 4
        return rn | ln
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
