## 13. Reverse Bits

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/reverse-bits3556/1)

### Problem Description

Given a number \( x \), reverse its binary form and return the answer in decimal.

**Example 1:**

Input:

```
x = 1
```

Output:

```
2147483648
```

Explanation:
Binary of 1 in 32 bits representation-

```
00000000000000000000000000000001
```

Reversing the binary form we get,

```
10000000000000000000000000000000
```

whose decimal value is 2147483648.

### My Approach

To reverse the bits of a number, we can iterate through each bit of the number from right to left (least significant bit to most significant bit) and build the reversed number bit by bit.

1. **Initialization:**

- Initialize a variable `ans` to store the reversed bits. Initially, set it to 0.

2. **Bit Reversal:**

- Iterate from `i = 0` to `31` (assuming a 32-bit integer).
- In each iteration:
  - Shift the `ans` left by 1 (multiply by 2) to make space for the next bit.
  - Take the least significant bit of `x` using the bitwise AND operation (`x & 1`), and OR it with `ans`.
  - Shift `x` right by 1 to process the next bit.

3. **Return:**

- Return the `ans` as the reversed binary form of `x` in decimal.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log \(x\)), as the number of iterations depends on the number of bits in \(x\).
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    long long reversedBits(long long x) {
        long long ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans = (ans << 1) | (x & 1); // Shift ans left by 1 and OR it with the least significant bit of x
            x >>= 1; // Shift x right by 1 to process the next bit
        }
        return ans;
    }
};
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
