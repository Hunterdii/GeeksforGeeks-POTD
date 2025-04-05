## 17. Check If Two Line Segments Intersect

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-if-two-line-segments-intersect0017/1)

### Problem Description

Given the coordinates of the endpoints \((p1, q1)\) and \((p2, q2)\) of two line segments, check if they intersect or not. If the line segments intersect, return `true`; otherwise, return `false`.

**Example:**

Input:

```
p1 = (1, 1), q1 = (10, 1), p2 = (1, 2), q2 = (10, 2)
```

Output:

```
false
```

Explanation:
The two line segments formed by \(p1 - q1\) and \(p2 - q2\) do not intersect.

### My Approach

1. **Helper Functions:**

   - `onSegment(p, q, r)`: Checks if point `q` lies on line segment `pr`.
   - `orientation(p, q, r)`: Finds the orientation of the triplet (p, q, r).
     - 0 -> p, q, r are collinear
     - 1 -> Clockwise
     - 2 -> Counterclockwise

2. **Main Function:**
   - `doIntersect(p1, q1, p2, q2)`: Uses the orientation of the triplets to determine if the line segments intersect.
   - Check general and special cases:
     - General Case: Line segments \(p1 - q1\) and \(p2 - q2\) intersect if orientations of the points are different.
     - Special Case: If points are collinear, check if they lie on the segments.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1), as we perform a constant number of operations regardless of the input size.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    bool onSegment(int p[], int q[], int r[]) {
        if (q[0] <= max(p[0], r[0]) && q[0] >= min(p[0], r[0]) &&
            q[1] <= max(p[1], r[1]) && q[1] >= min(p[1], r[1])) {
            return true;
        }
        return false;
    }

    int orientation(int p[], int q[], int r[]) {
        long long val = 1LL * (q[1] - p[1]) * (r[0] - q[0]) - 1LL * (q[0] - p[0]) * (r[1] - q[1]);
        if (val == 0) return 0;
        return (val > 0) ? 1 : 2;
    }

    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        if (o1 != o2 && o3 != o4) return "true";

        if (o1 == 0 && onSegment(p1, p2, q1)) return "true";
        if (o2 == 0 && onSegment(p1, q2, q1)) return "true";
        if (o3 == 0 && onSegment(p2, p1, q2)) return "true";
        if (o4 == 0 && onSegment(p2, q1, q2)) return "true";

        return "false";
    }
};
```

### Code (Java)

```java
class Solution {
    public boolean onSegment(int p[], int q[], int r[]) {
        if (q[0] <= Math.max(p[0], r[0]) && q[0] >= Math.min(p[0], r[0]) &&
            q[1] <= Math.max(p[1], r[1]) && q[1] >= Math.min(p[1], r[1])) {
            return true;
        }
        return false;
    }

    public int orientation(int p[], int q[], int r[]) {
        long val = 1L * (q[1] - p[1]) * (r[0] - q[0]) - 1L * (q[0] - p[0]) * (r[1] - q[1]);
        if (val == 0) return 0;
        return (val > 0) ? 1 : 2;
    }

    public String doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        if (o1 != o2 && o3 != o4) return "true";

        if (o1 == 0 && onSegment(p1, p2, q1)) return "true";
        if (o2 == 0 && onSegment(p1, q2, q1)) return "true";
        if (o3 == 0 && onSegment(p2, p1, q2)) return "true";
        if (o4 == 0 && onSegment(p2, q1, q2)) return "true";

        return "false";
    }
}
```

### Code (Python)

```python
class Solution:
    def onSegment(self, p, q, r):
        if min(p[0], r[0]) <= q[0] <= max(p[0], r[0]) and min(p[1], r[1]) <= q[1] <= max(p[1], r[1]):
            return True
        return False

    def orientation(self, p, q, r):
        val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
        if val == 0:
            return 0
        elif val > 0:
            return 1
        else:
            return 2

    def doIntersect(self, p1, q1, p2, q2):
        o1 = self.orientation(p1, q1, p2)
        o2 = self.orientation(p1, q1, q2)
        o3 = self.orientation(p2, q2, p1)
        o4 = self.orientation(p2, q2, q1)

        if o1 != o2 and o3 != o4:
            return "true"

        if o1 == 0 and self.onSegment(p1, p2, q1):
            return "true"
        if o2 == 0 and self.onSegment(p1, q2, q1):
            return "true"
        if o3 == 0 and self.onSegment(p2, p1, q2):
            return "true"
        if o4 == 0 and self.onSegment(p2, q1, q2):
            return "true"

        return "false"
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
