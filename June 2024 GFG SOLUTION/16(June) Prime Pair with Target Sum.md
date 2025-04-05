## 16. Prime Pair with Target Sum

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-prime4751/1)

### Problem Description

Given a number \( n \), find out if \( n \) can be expressed as \( a + b \), where both \( a \) and \( b \) are prime numbers. If such a pair exists, return the values of \( a \) and \( b \). Otherwise, return \([-1, -1]\) as an array of size 2.

**Examples:**

Input:

```
n = 10
```

Output:

```
3 7
```

Explanation:
There are two possibilities: 3 + 7 and 5 + 5 are both prime pairs that sum to 10. We choose 3 and 7 because 3 < 5.

### My Approach

1. **Initialization:**

- Create a boolean array `isPrime` of size \( n+1 \) to mark the primality of numbers up to \( n \). Initialize all entries as true except for indices 0 and 1, which are false.

2. **Sieve of Eratosthenes:**

- Use the Sieve of Eratosthenes algorithm to find all prime numbers up to \( n \). For each prime number \( i \), mark all its multiples as non-prime.

3. **Find Prime Pair:**

- Iterate through the first half of the `isPrime` array. For each prime number \( i \), check if \( n - i \) is also prime. If such a pair \( (i, n-i) \) is found, return it.

4. **Return Default:**

- If no prime pair is found, return \([-1, -1]\).

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n\*loglog(n)), as the Sieve of Eratosthenes runs in this time complexity.
- **Expected Auxiliary Space Complexity:** O(n), as we use a boolean array of size \( n+1 \) to mark prime numbers.

### Code

#### C++

```cpp
class Solution {
public:
    vector<int> getPrimes(int n) {
        bool isPrime[n + 1];
        memset(isPrime, true, sizeof(isPrime));
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> result(2, -1);
        for (int i = 2; i <= n / 2; i++) {
            if (isPrime[i] && isPrime[n - i]) {
                result[0] = i;
                result[1] = n - i;
                break;
            }
        }
        return result;
    }
};
```

#### Java

```java
class Solution {
    public ArrayList<Integer> getPrimes(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        result.add(-1);
        result.add(-1);
        for (int i = 2; i <= n / 2; i++) {
            if (isPrime[i] && isPrime[n - i]) {
                result.set(0, i);
                result.set(1, n - i);
                break;
            }
        }

        return result;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def getPrimes(self, n: int) -> List[int]:
        if n <= 2:
            return [-1, -1]
        isPrime = [True] * (n + 1)
        isPrime[0] = isPrime[1] = False
        for i in range(2, int(n**0.5) + 1):
            if isPrime[i]:
                for j in range(i * i, n + 1, i):
                    isPrime[j] = False

        result = [-1, -1]
        for i in range(2, n // 2 + 1):
            if isPrime[i] and isPrime[n - i]:
                result[0] = i
                result[1] = n - i
                break

        return result
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
