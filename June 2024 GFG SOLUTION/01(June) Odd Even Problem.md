## 01. Odd Even Problem

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/help-nobita0532/1)

### Problem Description

Given a string `s` of lowercase English characters, determine whether the summation of `x` and `y` is even or odd. Here, `x` is the count of distinct characters that occupy even positions in the English alphabet and have an even frequency, while `y` is the count of distinct characters that occupy odd positions in the English alphabet and have an odd frequency.

**Example 1:**

Input:

```
s = "abbbcc"
```

Output:

```
ODD
```

Explanation:

- `a` occupies 1st place (odd) in the English alphabet and its frequency is odd (1).
- `b` occupies 2nd place (even) but its frequency is odd (3), so it doesn't get counted.
- `c` occupies 3rd place (odd) but its frequency is even (2), so it also doesn't get counted.
  Thus, `x = 0` and `y = 1`, so the summation of `x` and `y` is `ODD`.

### My Approach

1. **Initialization:**

   - Initialize two counters `x` and `y` to zero.
   - Create a frequency array `count` of size 26 to store the frequency of each character in the string.

2. **Frequency Calculation:**

   - Iterate through the string and update the frequency array `count` for each character.

3. **Count Calculation:**

   - Iterate through the frequency array.
   - For each character frequency:
     - If the frequency is greater than zero:
       - If the frequency is even and the character position in the alphabet is even, increment `x`.
       - If the frequency is odd and the character position in the alphabet is odd, increment `y`.

4. **Summation and Result:**
   - Calculate the sum of `x` and `y`.
   - Return "ODD" if the sum is odd, otherwise return "EVEN".

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|s|), as we iterate through the string once and perform constant-time operations for each character.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a fixed amount of additional space for the frequency array and counters.

### Code Implementation

#### C++

```cpp
class Solution {
public:
    string oddEven(string s) {
        int x = 0, y = 0;
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                if (count[i] % 2 == 0 && (i + 1) % 2 == 0) {
                    x++;
                } else if (count[i] % 2 == 1 && (i + 1) % 2 == 1) {
                    y++;
                }
            }
        }
        int sum = x + y;
        return (sum % 2 == 1) ? "ODD" : "EVEN";
    }
};
```

#### Java

```java
class Solution {
    public String oddEven(String s) {
        int x = 0, y = 0;
        int[] count = new int[26];

        for (char c : s.toCharArray()) {
            count[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                if (count[i] % 2 == 0 && (i + 1) % 2 == 0) {
                    x++;
                } else if (count[i] % 2 == 1 && (i + 1) % 2 == 1) {
                    y++;
                }
            }
        }

        int sum = x + y;
        return (sum % 2 == 1) ? "ODD" : "EVEN";
    }
}
```

#### Python

```python
class Solution:
    def oddEven(self, s: str) -> str:
        x = 0
        y = 0
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1
        for i in range(26):
            if count[i] > 0:
                if count[i] % 2 == 0 and (i + 1) % 2 == 0:
                    x += 1
                elif count[i] % 2 == 1 and (i + 1) % 2 == 1:
                    y += 1

        sum_value = x + y
        return "ODD" if sum_value % 2 == 1 else "EVEN"
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
