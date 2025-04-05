## 21. Compare Two Fractions

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/compare-two-fractions4438/1)

### Problem Description

You are given a string `str` containing two fractions `a/b` and `c/d`. Compare these fractions and return the greater. If they are equal, then return `"equal"`.

Note: The string `str` contains "a/b, c/d" (fractions are separated by a comma `,` and a space ` `).

**Examples:**

Input:

```
str = "5/6, 11/45"
```

Output:

```
5/6
```

Explanation:
5/6 = 0.8333 and 11/45 = 0.2444, so 5/6 is the greater fraction.

### My Approach

1. **Parse the Input String:**

   - Split the input string `str` into two parts using `", "` as the delimiter to separate the fractions.
   - Extract the numerator and denominator for each fraction by splitting each part using `'/'`.

2. **Compare the Fractions:**

   - Calculate the cross multiplication for comparison:
     - Compare `a * d` with `b * c`.
   - Based on the comparison:
     - Return the greater fraction as a string.
     - If they are equal, return `"equal"`.

3. **Return the Result:**
   - Return the greater fraction in string format or `"equal"` if both fractions are the same.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(len(str)), as we perform operations proportional to the length of the input string.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    string compareFrac(string& s) {
        int n = s.length();
        int a = 0, b = 0, c = 0, d = 0;
        int i = 0;
        while (i < n && s[i] != '/') {
            a = a * 10 + s[i] - '0';
            i++;
        }
        i++;
        while (i < n && s[i] != ',') {
            b = b * 10 + s[i] - '0';
            i++;
        }
        i += 2; // Skip ", "
        while (i < n && s[i] != '/') {
            c = c * 10 + s[i] - '0';
            i++;
        }
        i++;
        while (i < n) {
            d = d * 10 + s[i] - '0';
            i++;
        }
        if ((a * d) > (b * c)) {
            return to_string(a) + "/" + to_string(b);
        } else if ((a * d) < (b * c)) {
            return to_string(c) + "/" + to_string(d);
        }
        return "equal";
    }
};
```

### Code (Java)

```java
class Solution {
    String compareFrac(String str) {
        int n = str.length();
        int a = 0, b = 0, c = 0, d = 0;
        int i = 0;
        while (i < n && str.charAt(i) != '/') {
            a = a * 10 + str.charAt(i) - '0';
            i++;
        }
        i++;
        while (i < n && str.charAt(i) != ',') {
            b = b * 10 + str.charAt(i) - '0';
            i++;
        }
        i += 2; // Skip ", "
        while (i < n && str.charAt(i) != '/') {
            c = c * 10 + str.charAt(i) - '0';
            i++;
        }
        i++;
        while (i < n) {
            d = d * 10 + str.charAt(i) - '0';
            i++;
        }
        if ((a * d) > (b * c)) {
            return a + "/" + b;
        } else if ((a * d) < (b * c)) {
            return c + "/" + d;
        }
        return "equal";
    }
}
```

### Code (Python)

```python
class Solution:
    def compareFrac(self, s):
        parts = s.split(", ")
        a, b = map(int, parts[0].split('/'))
        c, d = map(int, parts[1].split('/'))

        if a * d > b * c:
            return "{}/{}".format(a, b)
        elif a * d < b * c:
            return "{}/{}".format(c, d)
        else:
            return "equal"
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
