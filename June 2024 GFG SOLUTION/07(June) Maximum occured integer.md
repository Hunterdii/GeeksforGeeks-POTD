## 07. Maximum Occurred Integer

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-occured-integer4602/1)

### Problem Description

Given `n` integer ranges, the task is to return the maximum occurring integer in the given ranges. If more than one such integer exists, return the smallest one. The ranges are provided in two arrays `l[]` and `r[]`. `l[i]` consists of the starting point of the range, and `r[i]` consists of the corresponding endpoint of the range. Additionally, there is a `maxx` which is the maximum value of `r[]`.

**Example:**

Input:

```
n = 4
l[] = {1, 4, 3, 1}
r[] = {15, 8, 5, 4}
maxx = 15
```

Output:

```
4
```

Explanation:
The given ranges are [1, 15], [4, 8], [3, 5], [1, 4]. The smallest number that is most common or appears most times in the ranges is 4.

### My Approach

1. **Initialization:**

   - Create an array `a` of size `maxx + 2` initialized to zero. This array will be used to keep track of the frequency of the occurrences of numbers within the ranges.

2. **Increment and Decrement:**
   - For each range `(l[i], r[i])`, increment the value at index `l[i]` and decrement the value at index `r[i] + 1` in the array `a`. This helps in marking the start and end of the range.
3. **Calculate Frequency:**
   - Traverse the array `a` and compute the prefix sum to get the frequency of each number in the ranges.
4. **Determine Maximum Occurrence:**

   - Track the maximum frequency and the corresponding number. If multiple numbers have the same maximum frequency, choose the smallest number.

5. **Return:**
   - Return the number with the highest frequency.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + maxx), as we iterate through the ranges to update the array and then traverse the array to compute the prefix sums.
- **Expected Auxiliary Space Complexity:** O(maxx), as we use an array of size `maxx + 2` to keep track of the frequency.

### Code

#### C++ Code

```cpp
class Solution {
public:
    int maxOccured(int n, int l[], int r[], int maxx) {
        int a[maxx + 2] = {};
        for (int i = 0; i < n; ++i) {
            a[l[i]]++;
            if (r[i] + 1 <= maxx) {
                a[r[i] + 1]--;
            }
        }
        int maxCount = a[0], result = 0;
        for (int i = 1; i <= maxx; ++i) {
            a[i] += a[i - 1];
            if (a[i] > maxCount) {
                maxCount = a[i];
                result = i;
            }
        }
        return result;
    }
};
```

#### Java Code

```java
class Solution {
    public static int maxOccured(int n, int l[], int r[], int maxx) {
        int[] a = new int[maxx + 2];
        for (int i = 0; i < n; ++i) {
            a[l[i]]++;
            if (r[i] + 1 <= maxx) {
                a[r[i] + 1]--;
            }
        }
        int maxCount = a[0], result = 0;
        for (int i = 1; i <= maxx; ++i) {
            a[i] += a[i - 1];
            if (a[i] > maxCount) {
                maxCount = a[i];
                result = i;
            }
        }
        return result;
    }
}
```

#### Python Code

```python
class Solution:
    def maxOccured(self, n, l, r, maxx):
        a = [0] * (maxx + 2)
        for i in range(n):
            a[l[i]] += 1
            if r[i] + 1 <= maxx:
                a[r[i] + 1] -= 1

        maxCount = a[0]
        result = 0
        for i in range(1, maxx + 1):
            a[i] += a[i - 1]
            if a[i] > maxCount:
                maxCount = a[i]
                result = i

        return result
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
