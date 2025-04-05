## 18. Number of Rectangles in a Circle

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/rectangles-in-a-circle0457/1)

### Problem Description

Given a circular sheet of radius `r`, find the total number of rectangles with integral length and width that can be cut from the sheet and fit within the circle, one at a time.

**Examples:**

Input:

```
r = 1
```

Output:

```
1
```

Explanation: Only 1 rectangle of dimensions 1x1.

Input:

```
r = 2
```

Output:

```
8
```

Explanation: The 8 possible rectangles are:
(1x1), (1x2), (1x3), (2x1), (2x2), (2x3), (3x1), (3x2).

### My Approach

1. **Initialization:**

   - Initialize a variable `ans` to store the count of rectangles that can fit within the circle.
   - Define a `limit` variable as `4 * R * R` which represents the square of the diameter of the circle.

2. **Rectangle Calculation:**

   - Use nested loops to iterate over possible rectangle dimensions `(i, j)` where `i` and `j` range from 1 to `2 * R`.
   - For each pair `(i, j)`, check if the sum of their squared dimensions is less than or equal to `limit`.
   - If the condition is satisfied, increment `ans`.

3. **Return:**
   - Return the value of `ans` which contains the total count of rectangles that can fit within the circle.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(R^2), as we iterate through all possible rectangle dimensions within the given range.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int rectanglesInCircle(int R) {
        int ans = 0;
        int limit = 2 * R * 2 * R;
        for (int i = 1; i < 2 * R + 1; i++) {
            for (int j = 1; j < 2 * R + 1; j++) {
                if (i * i + j * j <= limit) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

### Code (Java)

```java
class Solution {
    int rectanglesInCircle(int R) {
        int ans = 0;
        int limit = 2 * R * 2 * R;
        for (int i = 1; i < 2 * R + 1; i++) {
            for (int j = 1; j < 2 * R + 1; j++) {
                if (i * i + j * j <= limit) {
                    ans++;
                }
            }
        }
        return ans;
    }
}
```

### Code (Python)

```python
class Solution:
    def rectanglesInCircle(self, R):
        ans = 0
        limit = 2 * R * 2 * R
        for i in range(1, 2 * R + 1):
            for j in range(1, 2 * R + 1):
                if i * i + j * j <= limit:
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
