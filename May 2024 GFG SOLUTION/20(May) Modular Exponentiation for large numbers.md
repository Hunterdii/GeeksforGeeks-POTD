## 20. Modular Exponentiation for Large Numbers

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1)

### Problem Description

Given three integers `x`, `n`, and `M`, implement a function `PowMod` to compute \( (x^n) \% M \).

**Example 1:**

Input:

```
x = 3, n = 2, m = 4
```

Output:

```
1
```

Explanation:
\( 3^2 = 9 \). \( 9 \% 4 = 1 \).

### My Approach

1. **Base Case:**

   - If \( n = 0 \), return 1 because any number raised to the power of 0 is 1.

2. **Recursive Calculation:**

   - Reduce the problem by dividing \( n \) by 2, and recursively calculate the result for half the exponent.
   - If \( n \) is even, the result is the square of the half result modulo \( M \).
   - If \( n \) is odd, multiply the base \( x \) with the square of the half result modulo \( M \).

3. **Modulo Operation:**
   - Ensure all intermediate results are taken modulo (M) to avoid overflow and to maintain the result within the bounds of (M).

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(\log n)\), as the problem size is halved in each recursive step.
- **Expected Auxiliary Space Complexity:** \(O(1)\), as the space used is constant and independent of the input size.

### Code

#### C++

```cpp
class Solution {
public:
    long long int PowMod(long long int a, long long int b, long long int m) {
        if (b == 0) return 1; // Base case: a^0 is 1

        a %= m;
        long long half = PowMod(a, b / 2, m);

        if (b % 2 == 0) {
            return (half * half) % m;
        } else {
            return (((half * half) % m) * a) % m;
        }
    }
};
```

#### Java

```java
class Solution {
    public long PowMod(long x, long n, long m) {
        if (n == 0) return 1; // Base case: x^0 is 1

        x %= m;
        long half = PowMod(x, n / 2, m);

        if (n % 2 == 0) {
            return (half * half) % m;
        } else {
            return (((half * half) % m) * x) % m;
        }
    }
}
```

#### Python

```python
class Solution:
    def PowMod(self, x, n, m):
        if n == 0:
            return 1  # Base case: x^0 is 1

        x %= m
        half = self.PowMod(x, n // 2, m)

        if n % 2 == 0:
            return (half * half) % m
        else:
            return (((half * half) % m) * x) % m
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
