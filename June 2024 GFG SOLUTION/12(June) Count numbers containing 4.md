## 12. Count Numbers Containing 4

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-numbers-containing-43022/1)

### Problem Description

You are given a number `n`. Return the count of total numbers from 1 to `n` containing 4 as a digit.

**Examples:**

Input:

```
n = 9
```

Output:

```
1
```

Explanation:
4 is the only number between 1 to 9 which contains 4 as a digit.

### My Approach

1. **Helper Function to Check Digit:**

- Implement a helper function `hasFour` to check if a number contains the digit 4.
- This function repeatedly checks the last digit of the number and then removes the last digit by dividing the number by 10 until all digits are checked.

2. **Counting Numbers with Digit 4:**

- Initialize a counter `ans` to zero.
- Iterate through all numbers from 1 to `n`.
- For each number, use the `hasFour` function to check if it contains the digit 4. If it does, increment the counter `ans`.

3. **Return:**

- Return the counter `ans` as the final count of numbers containing the digit 4.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \log n), since checking each number for the digit 4 involves logarithmic time in terms of the number of digits.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    bool hasFour(int n) {
        while (n) {
            if (n % 10 == 4) return true;
            n /= 10;
        }
        return false;
    }

    int countNumberswith4(int n) {
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (hasFour(i)) ++ans;
        }
        return ans;
    }
};
```

### Code (Java)

```java
class Solution {
    public static boolean hasFour(int n) {
        while (n > 0) {
            if (n % 10 == 4) return true;
            n /= 10;
        }
        return false;
    }

    public static int countNumberswith4(int n) {
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            if (hasFour(i)) ++ans;
        }
        return ans;
    }
}
```

### Code (Python)

```python
class Solution:
    def hasFour(self, n: int) -> bool:
        while n > 0:
            if n % 10 == 4:
                return True
            n //= 10
        return False

    def countNumberswith4(self, n: int) -> int:
        ans = 0
        for i in range(n + 1):
            if self.hasFour(i):
                ans += 1
        return ans
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
