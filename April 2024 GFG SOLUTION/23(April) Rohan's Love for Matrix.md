## 23. Rohan's Love for Matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/rohans-love-for-matrix4723/1)

### Problem Description

Rohan has a special love for matrices, especially for the first element of the matrix. Being good at Mathematics, he also loves to solve different problems on matrices. So one day he started to multiply the matrix with the original matrix. The elements of the original matrix `a` are given by \( a*{00}=1 \), \( a*{01}=1 \), \( a*{10}=1 \), \( a*{11}=0 \).

Given the power of the matrix, \( n \), calculate \( a^n \) and return the \( a\_{10} \) element mod \( 10^9 + 7 \).

**Example 1:**

Input:

```
n = 3
```

Output:

```
2
```

Explanation: Take the cube of the original matrix, i.e., \( a^3 \), and the \( (a\_{10}) \)th element is 2.

**Example 2:**

Input:

```
n = 4
```

Output:

```
3
```

Explanation: Take the cube of the original matrix, i.e., \( a^4 \), and the \( (a\_{10}) \)th element is 3.

**Your Task:**

You don't need to read input or print anything. Complete the function `firstElement()` which takes \( n \) as input parameter and returns the \( a\_{10} \) element mod \( 10^9 + 7 \) of \( a^n \).

**Expected Time Complexity:** O(n)

**Expected Auxiliary Space:** O(1)

**Constraints:**

- \(1 \leq n \leq 10^6\)

### My Approach

1. **Initialization:**

   - Initialize variables `a` and `b` as 1 and 1 respectively, representing the first two elements of the original matrix.

2. **Matrix Multiplication:**

   - Iterate from \( i = 3 \) to \( n \).
   - Calculate the \( i \)th element of the matrix as the sum of the previous two elements: \( c = (a + b) \mod (10^9 + 7) \), where \( c \) is the current element, \( a \) is the second last element, and \( b \) is the last element.
   - Update \( a \) to be the current value of \( b \), and \( b \) to be the current value of \( c \).

3. **Return:**
   - Return the value of \( b \), which represents the \( a\_{10} \) element of \( a^n \).

### Code (C++)

```cpp
class Solution {
public:
    int firstElement(int n) {
        if (n <= 2) return 1;
        long long a = 1, b = 1, c;
        for (int i = 3; i <= n; ++i) {
            c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return static_cast<int>(b);
    }

private:
    const int MOD = 1000000007;
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
