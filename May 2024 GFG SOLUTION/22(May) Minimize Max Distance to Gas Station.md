## 22. Minimize Max Distance to Gas Station

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1)

### Problem Description

We have a horizontal number line. On that number line, we have gas stations at positions `stations[0], stations[1], ..., stations[N-1]`, where `n` is the size of the stations array. We can add `k` more gas stations so that `d`, the maximum distance between adjacent gas stations, is minimized. We need to find the smallest possible value of `d`. Find the answer exactly to 2 decimal places.

**Example 1:**

Input:

```
n = 10
stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9
```

Output:

```
0.50
```

Explanation:
Each of the 9 stations can be added midway between all the existing adjacent stations.

### My Approach

1. **Sort the Array:**

   - Ensure that the gas stations are in sorted order, which is already given in the problem constraints.

2. **Binary Search:**

   - Use binary search to find the smallest possible maximum distance `d`.
   - Set `l` (low) to a very small positive value (e.g., `1e-9`) to avoid division by zero.
   - Set `h` (high) to the difference between the first and last gas stations in the array.

3. **Counting Intervals:**

   - For each mid-point (`mid = (l + h) / 2.0`) in the binary search, calculate the number of additional gas stations needed if `mid` were the maximum distance.
   - If the number of additional gas stations required exceeds `k`, adjust the binary search bounds accordingly.

4. **Precision:**
   - Continue the binary search until the difference between `l` and `h` is sufficiently small (e.g., `1e-6`).

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log k), as the binary search iterates over possible values of `d` and each iteration requires counting intervals which takes O(n) time.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code

#### C++

```cpp
class Solution {
    int countIntervals(double x, const vector<int>& v) {
        int ret = 0;
        for (size_t i = 0; i < v.size() - 1; ++i)
            ret += static_cast<int>(ceil((v[i + 1] - v[i]) / x)) - 1;
        return ret;
    }

public:
    double findSmallestMaxDist(vector<int>& s, int k) {
        sort(s.begin(), s.end());
        int n = s.size();
        double l = 1e-9; // Start with a very small positive value to avoid division by zero
        double h = s[n - 1] - s[0];

        while ((h - l) > 1e-6) {
            double mid = l + (h - l) / 2.0;
            int intervals = countIntervals(mid, s);
            if (intervals > k)
                l = mid;
            else
                h = mid;
        }
        return h;
    }
};
```

#### Java

```java
class Solution {
    private int countIntervals(double x, int[] v) {
        int ret = 0;
        for (int i = 0; i < v.length - 1; i++)
            ret += (int)Math.ceil((v[i + 1] - v[i]) / x) - 1;
        return ret;
    }

    public double findSmallestMaxDist(int[] s, int k) {
        Arrays.sort(s);
        int n = s.length;
        double l = 1e-9;
        double h = s[n - 1] - s[0];

        while ((h - l) > 1e-6) {
            double mid = l + (h - l) / 2.0;
            int intervals = countIntervals(mid, s);
            if (intervals > k)
                l = mid;
            else
                h = mid;
        }
        return h;
    }
}
```

#### Python

```python
import math

class Solution:
    def countIntervals(self, x, v):
        ret = 0
        for i in range(len(v) - 1):
            ret += math.ceil((v[i + 1] - v[i]) / x) - 1
        return ret

    def findSmallestMaxDist(self, stations, K):
        stations.sort()
        n = len(stations)
        l = 1e-9
        h = stations[-1] - stations[0]

        while (h - l) > 1e-6:
            mid = l + (h - l) / 2.0
            intervals = self.countIntervals(mid, stations)
            if intervals > K:
                l = mid
            else:
                h = mid
        return h
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
