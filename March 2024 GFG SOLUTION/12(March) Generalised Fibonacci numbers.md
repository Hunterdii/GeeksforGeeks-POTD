## 12. Generalised Fibonacci Numbers

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/generalised-fibonacci-numbers1820/1)

### Problem Statement

Given a generalized Fibonacci number g, which is dependent on `a`, `b`, and `c`, the recurrence relation is as follows:

- g(1) = 1
- g(2) = 1
- For any other number n, g(n) = a _ g(n-1) + b _ g(n-2) + c.

For a given value of `m`, determine g(n) % m.

### Example

**Example 1:**

Input:

- a = 3
- b = 3
- c = 3
- n = 3
- m = 5

Output:

- 4

Explanation:

- g(1) = 1 and g(2) = 1
- g(3) = 3*g(2) + 3*g(1) + 3 = 3*1 + 3*1 + 3 = 9
- We need to return answer modulo 5, so 9 % 5 = 4, is the answer.

**Example 2:**

Input:

- a = 2
- b = 2
- c = 2
- n = 4
- m = 100

Output:

- 16

Explanation:

- g(1) = 1 and g(2) = 1
- g(3) = 2*g(2) + 2*g(1) + 2 = 2*1 + 2*1 + 2 = 6
- g(4) = 2*g(3) + 2*g(2) + 2 = 2*6 + 2*1 + 2 = 16
- We need to return answer modulo 100, so 16 % 100 = 16, is the answer.

### My Approach

1. **Matrix Exponentiation**: We can solve this problem efficiently using matrix exponentiation.
2. **Create Matrices**: Create matrices to represent the recurrence relation. Matrix multiplication will allow us to compute g(n) efficiently.
3. **Modular Arithmetic**: Perform all calculations modulo m to handle large numbers efficiently.
4. **Exponentiation by Squaring**: To compute the matrix power efficiently, we use exponentiation by squaring algorithm.
5. **Return Result**: After computation, return g(n) % m as the result.

### Time and Space Complexity

- **Time Complexity**: O(log(n)). This is the complexity of matrix exponentiation.
- **Space Complexity**: O(1). We are not using any extra space that grows with the input size.

### Code (C++)

```cpp
#define ll long long

class Solution
{
public:
    vector<vector<ll>> multiply(const vector<vector<ll>> &A, const vector<vector<ll>> &B, ll m)
    {
        int size = A.size();
        vector<vector<ll>> result(size, vector<ll>(size, 0));
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                for (int k = 0; k < size; ++k)
                {
                    result[i][j] += (A[i][k] % m) * (B[k][j] % m);
                    result[i][j] %= m;
                }
            }
        }
        return result;
    }

    long long genFibNum(ll a, ll b, ll c, ll n, ll m)
    {
        if (n <= 2)
            return 1LL % m;
        vector<vector<ll>> mat = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
        vector<vector<ll>> res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        n -= 2;
        while (n > 0)
        {
            if (n & 1)
                res = multiply(res, mat, m);
            mat = multiply(mat, mat, m);
            n >>= 1;
        }
        return (res[0][0] + res[0][1] + c * res[0][2]) % m;
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
