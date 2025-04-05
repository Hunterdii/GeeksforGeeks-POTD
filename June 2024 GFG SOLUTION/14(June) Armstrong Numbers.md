## 14. Armstrong Numbers

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1)

### Problem Description

You are given a 3-digit number `n`. Determine whether it is an Armstrong number or not.

An Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself. For example, 371 is an Armstrong number since \(3^3 + 7^3 + 1^3 = 371\).

**Example:**

Input:

```
n = 153
```

Output:

```
Yes
```

Explanation:
153 is an Armstrong number since \(1^3 + 5^3 + 3^3 = 153\). Hence, the answer is "Yes".

### My Approach

1. **Initialization:**

   - Convert the number to a string to easily access each digit.

2. **Sum Calculation:**

   - Calculate the sum of the cubes of each digit.

3. **Comparison:**
   - Compare the calculated sum with the original number.
   - If they are equal, return "Yes".
   - Otherwise, return "No".

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1), as we perform a constant number of operations regardless of the size of the input.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code

#### C++

```cpp
class Solution {
public:
    string armstrongNumber(int n) {
        string ans = to_string(n);
        if ((pow((ans[0]-'0'), 3) + pow((ans[1]-'0'), 3) + pow((ans[2]-'0'), 3)) == n) {
            return "true";
        }
        return "false";
    }
};
```

#### Java

```java
class Solution {
    static String armstrongNumber(int n) {
        int original = n;
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += Math.pow(digit, 3);
            n /= 10;
        }
        return sum == original ? "true" : "false";
    }
}
```

#### Python

```python
class Solution:
    def armstrongNumber(self, n):
        original = n
        sum = 0
        while n > 0:
            digit = n % 10
            sum += digit ** 3
            n //= 10
        return "true" if sum == original else "false"
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
