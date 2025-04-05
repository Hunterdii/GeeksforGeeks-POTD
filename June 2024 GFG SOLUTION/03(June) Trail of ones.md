## 03. Trail of Ones

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/trail-of-ones3242/1)

### Problem Description

Given a number `n`, find the number of binary strings of length `n` that contain consecutive 1's in them. Since the number can be very large, return the answer modulo \(10^9 + 7\).

**Example:**

Input:

```
n = 2
```

Output:

```
1
```

Explanation:
There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.

### My Approach

1. **Initialization:**

   - Define a constant `MOD` as \(10^9 + 7\).
   - Initialize variables `a` and `b` to 1, representing the first two Fibonacci numbers.
   - Initialize `res` to 1 to store the number of binary strings with consecutive 1's.

2. **Fibonacci Calculation:**

   - Iterate from `i = 3` to `n`.
   - Calculate the next Fibonacci number `c` as the sum of the previous two terms: `c = (a + b) % MOD`.
   - Update `a` to `b` and `b` to `c`.
   - Update `res` to `res * 2 + a` and take modulo `MOD`.

3. **Return:**
   - Return `res` as the number of binary strings containing consecutive 1's.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the series up to the \(n\)th term.
- **Expected Auxiliary Space Complexity:** O(n), as we use a constant amount of additional space regardless of the input size.

### Code

#### C++

```cpp
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        const long long MOD = 1'000'000'007;
        if (n == 1 || n == 2) {
            return 1;
        }
        long long a = 1, b = 1;
        long long res = 1;
        for (int i = 3; i <= n; i++) {
            long long c = (a + b) % MOD;
            a = b;
            b = c;
            res = (res * 2 + a) % MOD;
        }
        return (int)res;
    }
};
```

#### Java

```java
class Solution {
    static int numberOfConsecutiveOnes(int n) {
        final long MOD = 1_000_000_007;
        if (n == 1 || n == 2) {
            return 1;
        }
        long a = 1, b = 1;
        long res = 1;
        for (int i = 3; i <= n; i++) {
            long c = (a + b) % MOD;
            a = b;
            b = c;
            res = (res * 2 + a) % MOD;
        }
        return (int) res;
    }
}
```

#### Python

```python
class Solution:
    def numberOfConsecutiveOnes(self, n):
        MOD = 1000000007
        if n == 1 or n == 2:
            return 1
        a, b = 1, 1
        res = 1
        for i in range(3, n + 1):
            c = (a + b) % MOD
            a, b = b, c
            res = (res * 2 + a) % MOD
        return res
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
