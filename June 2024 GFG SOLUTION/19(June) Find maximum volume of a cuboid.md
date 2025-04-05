## 19. Find Maximum Volume of a Cuboid

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/magical-box5306/1)

### Problem Description

You are given the perimeter and the area of a cuboid. Your task is to return the maximum volume that can be formed with the given perimeter and surface area. Round off the result to 2 decimal places. For the given parameters, it is guaranteed that an answer always exists.

**Examples:**

Input:

```
perimeter = 22, area = 15
```

Output:

```
3.02
```

Explanation:
The maximum attainable volume of the cuboid is 3.02.

### My Approach

1. **Extracting Parameters:**

- Calculate the intermediate terms required to derive the dimensions of the cuboid using the provided formulas.
- Part 1: \((\text{{perimeter}} - \sqrt{\text{{perimeter}}^2 - 24 \times \text{{area}}}) / 12\)
- Part 2: \((\text{{perimeter}} / 4) - (2 \times \text{{part1}})\)

2. **Volume Calculation:**

- Compute the volume using the formula: \(\text{{part1}}^2 \times \text{{part2}}\).

3. **Return the Result:**

- Return the volume rounded to 2 decimal places.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1), as we perform a constant number of operations regardless of the input values.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code

**C++:**

```cpp
class Solution {
  public:
    double maxVolume(double p, double a) {
        double part1 = (p - sqrt(pow(p, 2) - (24 * a))) / 12;
        double part2 = (p / 4) - (2 * part1);
        double ans = pow(part1, 2) * part2;
        return round(ans * 100) / 100;
    }
};
```

**Java:**

```java
class Solution {
    double maxVolume(double perimeter, double area) {
        double part1 = (perimeter - Math.sqrt(Math.pow(perimeter, 2) - (24 * area))) / 12;
        double part2 = (perimeter / 4) - (2 * part1);
        double ans = Math.pow(part1, 2) * part2;
        return Math.round(ans * 100.0) / 100.0;
    }
}
```

**Python:**

```python
class Solution:
    def maxVolume(self, perimeter, area):
        part1 = (perimeter - (perimeter ** 2 - 24 * area) ** 0.5) / 12
        part2 = (perimeter / 4) - (2 * part1)
        ans = part1 ** 2 * part2
        return round(ans, 2)
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
