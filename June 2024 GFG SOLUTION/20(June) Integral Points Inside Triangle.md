## 20. Integral Points Inside Triangle

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/integral-points-in-triangle5026/1)

### Problem Description

Given three non-collinear points whose coordinates are \( p(p1, p2) \), \( q(q1, q2) \), and \( r(r1, r2) \) in the X-Y plane, return the number of integral (lattice) points strictly inside the triangle formed by these points. A point in the X-Y plane is said to be an integral/lattice point if both its coordinates are integral.

**Examples:**

Input:

```
p = (0,0), q = (0,5), r = (5,0)
```

Output:

```
6
```

Explanation:
Points (1,1), (1,2), (1,3), (2,1), (2,2), and (3,1) are the integral points inside the triangle. So, there are 6 in total.

<p align="center">
  <img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/17f9ccf0-6c86-4eda-bf5e-4160acd11672" alt="Image" width="270" />
</p>

### My Approach

1. **GCD Calculation:**

- Create a function `gcd` to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm.

2. **Boundary Points Calculation:**

- Create a function `boundaryPoints` to calculate the number of lattice points on the line segment between two points. The formula used is `gcd(abs(x2 - x1), abs(y2 - y1)) + 1`.

3. **Internal Points Calculation:**

- Calculate the area of the triangle using the formula \( \text{area} = |p1(q2 - r2) + q1(r2 - p2) + r1(p2 - q2)| \).
- Calculate the number of boundary points on the triangle using the `boundaryPoints` function for each side and summing them up, then subtracting 3 to avoid double-counting the vertices.
- Use Pick's Theorem to find the number of internal lattice points: \( I = \frac{\text{area} - B + 2}{2} \), where \( I \) is the number of internal lattice points, \( \text{area} \) is the area of the triangle, and \( B \) is the number of boundary points.

4. **Return:**

- Return the number of internal lattice points.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(Log2 10^9), as we perform a constant number of GCD operations, which are logarithmic in nature.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long boundaryPoints(long long x1, long long y1, long long x2, long long y2) {
        return gcd(abs(x2 - x1), abs(y2 - y1)) + 1;
    }

    long long InternalCount(long long p[], long long q[], long long r[]) {
        long long area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]));

        long long B = boundaryPoints(p[0], p[1], q[0], q[1]) +
                      boundaryPoints(q[0], q[1], r[0], r[1]) +
                      boundaryPoints(r[0], r[1], p[0], p[1]) - 3;
        long long I = (area - B + 2) / 2;

        return I;
    }
};
```

### Code (Java)

```java
class Solution {
    long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long boundaryPoints(long x1, long y1, long x2, long y2) {
        return gcd(Math.abs(x2 - x1), Math.abs(y2 - y1)) + 1;
    }

    long InternalCount(long p[], long q[], long r[]) {
        long area = Math.abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]));

        long B = boundaryPoints(p[0], p[1], q[0], q[1]) +
                 boundaryPoints(q[0], q[1], r[0], r[1]) +
                 boundaryPoints(r[0], r[1], p[0], p[1]) - 3;

        long I = (area - B + 2) / 2;

        return I;
    }
}
```

### Code (Python)

```python
class Solution:
    def gcd(self, a, b):
        while b != 0:
            a, b = b, a % b
        return a

    def boundaryPoints(self, x1, y1, x2, y2):
        return self.gcd(abs(x2 - x1), abs(y2 - y1)) + 1

    def InternalCount(self, p, q, r):
        area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]))

        B = self.boundaryPoints(p[0], p[1], q[0], q[1]) + \
            self.boundaryPoints(q[0], q[1], r[0], r[1]) + \
            self.boundaryPoints(r[0], r[1], p[0], p[1]) - 3

        I = (area - B + 2) // 2

        return I
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
