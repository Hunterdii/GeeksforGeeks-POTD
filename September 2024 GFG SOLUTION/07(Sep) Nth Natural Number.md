# **07. Nth Natural Number**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/nth-natural-number/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given a positive integer `n`, find the `n`th natural number after removing all the numbers that contain the digit `9`.

**Examples:**

Input:

```
n = 8
```

Output:

```
8
```

Explanation: The first 8 natural numbers without the digit 9 are: `1, 2, 3, 4, 5, 6, 7, 8`. Hence, the 8th number is `8`.

### My Approach

1. **Base-9 Representation:**

   - The key idea is to map the natural numbers that exclude the digit `9` onto a base-9 number system.
   - Numbers in base 10 that contain the digit `9` can be "removed" by converting the index `n` to a number in base-9.

2. **Step-by-Step Process:**

   - Convert the given `n` into a number in base-9. This ensures that the number does not contain the digit `9`, as base-9 numbers inherently do not have a digit `9`.
   - For example, the number `9` in base-10 maps to `10` in base-9, skipping the digit `9`.

3. **Conversion Algorithm:**

   - Initialize `base9num` as `0` and `pos` as `1` to keep track of the current place value.
   - Repeatedly extract the remainder when `n` is divided by `9`, multiply it by the current place value, and add it to `base9num`.
   - Divide `n` by `9` to shift to the next place in the base-9 number, and update the position multiplier (`pos`).

4. **Final Answer:**
   - After processing all digits of `n`, the resulting number in base-9 is the `n`th natural number after removing all numbers containing the digit `9`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log₉n), as the algorithm repeatedly divides the number by `9` in each step, taking logarithmic time in base 9.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for storing variables like `base9num` and `pos`.

### Code (C++)

```cpp
class Solution {
public:
    long long findNth(long long n) {
        long long base9num = 0;
        long long pos = 1;

        while (n > 0) {
            base9num += (n % 9) * pos;
            n /= 9;
            pos *= 10;
        }

        return base9num;
    }
};
```

### Code (Java)

```java
class Solution {
    long findNth(long n) {
        long base9num = 0;
        long pos = 1;

        while (n > 0) {
            base9num += (n % 9) * pos;
            n /= 9;
            pos *= 10;
        }

        return base9num;
    }
}
```

### Code (Python)

```python
class Solution:
    def findNth(self, n):
        base9num = 0
        pos = 1

        while n > 0:
            base9num += (n % 9) * pos
            n //= 9
            pos *= 10

        return base9num
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
