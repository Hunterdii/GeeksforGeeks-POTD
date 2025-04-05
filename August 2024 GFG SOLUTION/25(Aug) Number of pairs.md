# <b>25. Number of Pairs</b>

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/number-of-pairs-1587115620/1)

### Note: Sorry for the delay in uploading this. My exams are currently ongoing, which has affected the timeline.

### Problem Description

Given two positive integer arrays `arr` and `brr`, find the number of pairs such that `x^y > y^x` (raised to the power of) where `x` is an element from `arr` and `y` is an element from `brr`.

**Example:**

Input:

```
arr = [2, 1, 6]
brr = [1, 5]
```

Output:

```
3
```

Explanation: The pairs which follow `x^y > y^x` are: `2^1 > 1^2`, `2^5 > 5^2`, and `6^1 > 1^6`.

### My Approach

1. **Counting Occurrences of `y` Values Less Than 5:**

   - Create an array `NoOfY` to count the number of occurrences of each `y` value less than 5 in `brr`.

2. **Sorting Array `brr`:**

   - Sort `brr` to efficiently find the number of elements greater than `x` using binary search.

3. **Iterating Through Array `arr`:**

   - For each element `x` in `arr`, calculate the number of valid pairs by:
     - Adding the count of `y` values where `x^y > y^x`.
     - Subtracting special cases where `x` is 2 or 3.

4. **Binary Search for Finding the First Greater Element:**
   - Use binary search to find the first element in `brr` greater than `x` and count how many such elements exist.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O((N + M)log(N)), as sorting `brr` takes `O(N log N)` time, and for each element in `arr`, we perform a binary search, which takes `O(log N)` time.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like `NoOfY`.

### Code (C++)

```cpp
class Solution {
public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<int> K(W + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) {
                K[w] = max(K[w], val[i] + K[w - wt[i]]);
            }
        }
        return K[W];
    }
};
```

### Code (Java)

```java
class Solution {
    public long countPairs(int[] arr, int[] brr, int M, int N) {
        int[] NoOfY = new int[5];
        for (int i = 0; i < N; i++) {
            if (brr[i] < 5) NoOfY[brr[i]]++;
        }
        Arrays.sort(brr);
        long total_pairs = 0;

        for (int x : arr) {
            if (x == 0) continue;
            if (x == 1) {
                total_pairs += NoOfY[0];
                continue;
            }

            int idx = Arrays.binarySearch(brr, x);
            if (idx < 0) idx = -idx - 1;
            else while (idx < N && brr[idx] == x) idx++;

            long count = N - idx;
            count += (NoOfY[0] + NoOfY[1]);

            if (x == 2) count -= (NoOfY[3] + NoOfY[4]);
            if (x == 3) count += NoOfY[2];

            total_pairs += count;
        }

        return total_pairs;
    }
}
```

### Code (Python)

```python
class Solution:
    def countPairs(self, arr, brr):
        N = len(brr)
        NoOfY = [0] * 5

        for y in brr:
            if y < 5:
                NoOfY[y] += 1

        brr.sort()
        total_pairs = 0

        for x in arr:
            if x == 0:
                continue
            if x == 1:
                total_pairs += NoOfY[0]
                continue

            idx = self.upper_bound(brr, x)
            count = N - idx
            count += (NoOfY[0] + NoOfY[1])

            if x == 2:
                count -= (NoOfY[3] + NoOfY[4])
            if x == 3:
                count += NoOfY[2]

            total_pairs += count

        return total_pairs

    def upper_bound(self, arr, x):
        lo, hi = 0, len(arr)
        while lo < hi:
            mid = (lo + hi) // 2
            if arr[mid] <= x:
                lo = mid + 1
            else:
                hi = mid
        return lo
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
