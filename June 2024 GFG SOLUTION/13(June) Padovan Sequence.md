## 13. Padovan Sequence

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/padovan-sequence2855/1)

### Problem Description

Given a number `n`, find the `n`th number in the Padovan Sequence. The Padovan Sequence is defined by the recurrence relation:
\[ P(n) = P(n-2) + P(n-3) \]
with initial terms:
\[ P(0) = P(1) = P(2) = 1 \]

Since the output may be very large, return the result modulo \(10^9 + 7\).

**Examples:**

Input:

```
n = 3
```

Output:

```
2
```

Explanation:
\[ P(3) = P(1) + P(0) = 1 + 1 = 2 \]

### My Approach

1. **Initialization:**

   - If `n` is 0, 1, or 2, return 1 since these are the base cases of the Padovan sequence.
   - Initialize an array or variables to keep track of the previous three terms of the sequence.

2. **Padovan Calculation:**

   - Iterate from `i = 3` to `n`.
   - Calculate the `i`th term as the sum of the term two steps before and the term three steps before, modulo \(10^9 + 7\).

3. **Return:**
   - Return the `n`th term of the Padovan sequence.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the sequence up to the `n`th term.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to store the previous three terms of the sequence.

### Code

#### C++

```cpp
class Solution {
public:
    int padovanSequence(int n) {
        const int MOD = 1000000007;
        if (n == 0 || n == 1 || n == 2)
            return 1;

        int p[3] = {1, 1, 1};
        for (int i = 3; i <= n; ++i) {
            int p_next = (p[0] + p[1]) % MOD;
            p[0] = p[1];
            p[1] = p[2];
            p[2] = p_next;
        }
        return p[2];
    }
};
```

#### Java

```java
class Solution {
    public int padovanSequence(int n) {
        final int MOD = 1000000007;
        if (n == 0 || n == 1 || n == 2)
            return 1;

        int[] p = {1, 1, 1};
        for (int i = 3; i <= n; ++i) {
            int p_next = (p[0] + p[1]) % MOD;
            p[0] = p[1];
            p[1] = p[2];
            p[2] = p_next;
        }
        return p[2];
    }
}
```

#### Python

```python
class Solution:
    def padovanSequence(self, n):
        if n <= 2:
            return 1

        MOD = 1000000007
        pPrevPrev, pPrev, pCurr = 1, 1, 1
        for _ in range(3, n + 1):
            pNext = (pPrevPrev + pPrev) % MOD
            pPrevPrev, pPrev, pCurr = pPrev, pCurr, pNext

        return pCurr
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
