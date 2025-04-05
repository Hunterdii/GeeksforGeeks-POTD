## 05. Strictly Increasing Array

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1)

### Problem Description

Given an array `nums` of \(n\) positive integers, find the minimum number of operations required to modify the array such that array elements are in strictly increasing order (\(nums[i] < nums[i+1]\)). Changing a number to greater or lesser than the original number is counted as one operation.

**Example:**

Input:

```
n = 6
nums = [1, 2, 3, 6, 5, 4]
```

Output:

```
2
```

Explanation:
By decreasing 6 by 2 and increasing 4 by 2, nums will be like [1, 2, 3, 4, 5, 6], which is strictly increasing.

### My Approach

1. **Dynamic Programming:**

- Initialize a dynamic programming array `dp` of size \(n\) with all elements set to 1.
- Iterate through the array `nums` and for each element `nums[i]`, compare it with all previous elements `nums[j]` (where \(j < i\)).
- If `nums[i] - nums[j] >= i - j`, update `dp[i]` as `max(dp[i], dp[j] + 1)` and update `maxi` as `max(maxi, dp[i])`.
- Finally, return \(n - \text{maxi}\), where \(n\) is the size of the array.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(n^2)\), as we iterate through the array and perform comparisons.
- **Expected Auxiliary Space Complexity:** \(O(n)\), as we use a dynamic programming array of size \(n\) to store intermediate results.

### Code (C++)

```cpp
class Solution {
public:
    int min_operations(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] - nums[j] >= i - j) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                    maxi = std::max(maxi, dp[i]);
                }
            }
        }

        return n - maxi;
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
