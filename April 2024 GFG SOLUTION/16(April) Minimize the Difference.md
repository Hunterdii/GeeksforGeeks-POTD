## 16. Minimize the Difference

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimize-the-difference/1)

### Problem Description

Given an array `arr` of size `n` and an integer `k`, remove a subarray of size `k` such that the difference between the maximum and minimum values of the remaining array is minimized. Return the minimum value obtained after performing the operation of removing the subarray.

**Example:**

Input:

```
n = 5
k = 3
arr = [1, 2, 3, 4, 5]
```

Output:

```
1
```

Explanation:
We can remove the first subarray of length 3 (i.e., `[1, 2, 3]`). The remaining array will be `[4, 5]`, and the difference of the maximum and minimum elements will be 1, i.e., \(5 - 4 = 1\).

### My Approach

1. **Initialization:**

   - We'll initialize two pointers, `i` and `j`, to represent the start and end of the subarray to be removed.
   - Initialize `ans` to `INT_MAX` to store the minimum difference.

2. **Prefill Min-Max Arrays:**

   - We'll precalculate arrays `prefMini`, `suffMini`, `prefMaxi`, and `suffMaxi`, which store the minimum and maximum values of subarrays for prefixes and suffixes.

3. **Iteration:**

   - We'll iterate `i` and `j` over the array to find the minimum difference for all possible subarrays of size `k`.
   - For each pair `(i, j)`, we'll calculate the minimum and maximum values of the remaining array after removing the subarray `[i, j]`.

4. **Update Minimum Difference:**

   - We'll update `ans` with the minimum difference obtained for all pairs `(i, j)`.

5. **Return:**
   - Return `ans` as the minimum difference.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(n)\), as we iterate through the array once to calculate the prefill arrays and once to find the minimum difference.
- **Expected Auxiliary Space Complexity:** \(O(n)\), as we use four additional arrays of size \(n\) to store the prefill values.

### Code (C++)

```cpp
class Solution {
public:
    int minimizeDifference(int n, int k, std::vector<int>& arr) {
        std::vector<int> prefMini(n, INT_MAX), suffMaxi(n, INT_MIN);
        std::vector<int> suffMini(n, INT_MAX), prefMaxi(n, INT_MIN);

        prefMaxi[0] = prefMini[0] = arr[0];
        suffMaxi[n - 1] = suffMini[n - 1] = arr[n - 1];

        for (int i = 1; i < n; ++i) {
            prefMaxi[i] = std::max(arr[i], prefMaxi[i - 1]);
            prefMini[i] = std::min(arr[i], prefMini[i - 1]);
            suffMaxi[n - i - 1] = std::max(arr[n - i - 1], suffMaxi[n - i]);
            suffMini[n - i - 1] = std::min(arr[n - i - 1], suffMini[n - i]);
        }

        int ans = INT_MAX, i = 0, j = k - 1;

        while (j < n) {
            int mini = INT_MAX, maxi = INT_MIN;

            if (i > 0) {
                mini = std::min(mini, prefMini[i - 1]);
                maxi = std::max(maxi, prefMaxi[i - 1]);
            }
            if (j < n - 1) {
                mini = std::min(mini, suffMini[j + 1]);
                maxi = std::max(maxi, suffMaxi[j + 1]);
            }

            ans = std::min(ans, maxi - mini);
            ++j;
            ++i;
        }

        return ans;
    }
};
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
