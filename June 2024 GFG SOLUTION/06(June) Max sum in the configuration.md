## 06. Max Sum in the Configuration

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1)

### Problem Description

Given an integer array `a` of size `n`, your task is to return the maximum value of the sum of `i * a[i]` for all `0 <= i <= n-1`, where `a[i]` is the element at index `i` in the array. The only operation allowed is to rotate (clockwise or counterclockwise) the array any number of times.

**Example:**

Input:

```
n = 4, a[] = {8, 3, 1, 2}
```

Output:

```
29
```

Explanation:
All the configurations possible by rotating the elements are:

- 3 1 2 8 => sum is 3*0 + 1*1 + 2*2 + 8*3 = 29
- 1 2 8 3 => sum is 1*0 + 2*1 + 8*2 + 3*3 = 27
- 2 8 3 1 => sum is 2*0 + 8*1 + 3*2 + 1*3 = 17
- 8 3 1 2 => sum is 8*0 + 3*1 + 1*2 + 2*3 = 11

So, the maximum sum will be 29.

### My Approach

1. **Initialization:**

   - Calculate the sum of all elements in the array and store it in `sum`.
   - Compute the initial value of `currSum`, which is the sum of `i * a[i]` for the array in its original configuration.

2. **Rotation Calculation:**

   - Initialize `maxi` to store the maximum value of `currSum`.
   - Iterate through the array and calculate the value of `currSum` after each rotation. Update `maxi` if `currSum` after rotation is greater than the current `maxi`.

3. **Return:**
   - Return `maxi`, which contains the maximum sum for the given configurations.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array twice: once to compute the initial sums and once to calculate the rotated sums.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
#define ll unsigned long long

class Solution {
public:
    long long max_sum(int a[], int n) {
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        ll currSum = 0;
        for (int i = 0; i < n; ++i) {
            currSum += (ll)i * a[i];
        }
        ll maxi = currSum;
        for (int i = 1; i < n; ++i) {
            currSum = currSum + sum - (ll)n * a[n - i];
            maxi = max(maxi, currSum);
        }

        return maxi;
    }
};
```

### Code (Java)

```java
class Solution {
    long max_sum(int a[], int n) {
        long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }

        long currSum = 0;
        for (int i = 0; i < n; ++i) {
            currSum += (long)i * a[i];
        }

        long maxi = currSum;
        for (int i = 1; i < n; ++i) {
            currSum = currSum + sum - (long)n * a[n - i];
            maxi = Math.max(maxi, currSum);
        }

        return maxi;
    }
}
```

### Code (Python)

```python
def max_sum(a, n):
    total_sum = sum(a)

    curr_sum = 0
    for i in range(n):
        curr_sum += i * a[i]

    max_sum_value = curr_sum
    for i in range(1, n):
        curr_sum = curr_sum + total_sum - n * a[n - i]
        max_sum_value = max(max_sum_value, curr_sum)

    return max_sum_value
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
