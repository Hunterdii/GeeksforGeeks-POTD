## 11. Gray to Binary Equivalent

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1)

### Problem Description

Given an integer number \( n \), which is a decimal representation of Gray Code. Find the binary equivalent of the Gray Code & return the decimal representation of the binary equivalent.

**Example:**

Input:

```
n = 4
```

Output:

```
7
```

Explanation:
Given \( 4 \), its gray code = \( 110 \).
Binary equivalent of the gray code \( 110 \) is \( 100 \).
Return \( 7 \) representing gray code \( 100 \).

### My Approach

1. **Gray to Binary Conversion:**
   - Initialize a variable `binary` as \( 0 \).
   - Iterate while \( n \neq 0 \):
     - Perform XOR operation between `binary` and \( n \).
     - Right shift \( n \) by 1.
   - Return the value of `binary` as the binary equivalent.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(\log n) \), as we iterate while \( n \) is not zero, and in each iteration, we right shift \( n \).
- **Expected Auxiliary Space Complexity:** \( O(1) \), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n) {
        int binary = 0;
        while (n != 0) {
            binary ^= n;
            n >>= 1;
        }
        return binary;
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
