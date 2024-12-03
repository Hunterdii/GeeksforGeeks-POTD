# <b>13. Square Root of a Number</b>

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/square-root/1)

### Problem Description

Given an integer `n`, find the square root of `n`. If `n` is not a perfect square, return the floor value of the square root.

**Example:**

Input:
```
n = 5
```
Output:
```
2
```
Explanation: Since 5 is not a perfect square, the floor of the square root of 5 is 2.

### My Approach

1. **Initial Check:**
   - If `n` is 0 or 1, return `n` immediately as the square root of 0 is 0 and the square root of 1 is 1.

2. **Binary Search:**
   - Initialize `start` to 1 and `end` to `n`. This range will be used to perform a binary search to find the square root.
   - While `start` is less than or equal to `end`, calculate the midpoint `mid` and square it.
   - If the square of `mid` equals `n`, return `mid` as `n` is a perfect square.
   - If the square of `mid` is less than `n`, store `mid` as the current best guess for the square root and move the `start` pointer to `mid + 1`.
   - If the square of `mid` is greater than `n`, move the `end` pointer to `mid - 1`.
   - When the loop ends, return the last best guess stored in `ans`, which represents the floor value of the square root.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n), as we are performing a binary search over the range of possible square roots.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables.

### Code (C++)

```cpp
class Solution {
public:
    long long int floorSqrt(long long int n) {
        if (n == 0 || n == 1)
            return n;

        long long int start = 1, end = n, ans = 0;
        while (start <= end) {
            long long int mid = start + (end - start) / 2;
            long long int square = mid * mid;

            if (square == n)
                return mid;
            if (square < n) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
```

### Code (Java)

```java
class Solution {
    long floorSqrt(long n) {
        if (n == 0 || n == 1)
            return n;

        long start = 1, end = n, ans = 0;
        while (start <= end) {
            long mid = start + (end - start) / 2;
            long square = mid * mid;

            if (square == n)
                return mid;
            if (square < n) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
}
```

### Code (Python)

```python
class Solution:
    def floorSqrt(self, n): 
        if n == 0 or n == 1:
            return n

        start, end, ans = 1, n, 0
        while start <= end:
            mid = start + (end - start) // 2
            square = mid * mid

            if square == n:
                return mid
            if square < n:
                ans = mid
                start = mid + 1
            else:
                end = mid - 1

        return ans
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
