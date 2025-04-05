## 27. Longest Subsequence-1

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1)

### Problem Description

Given an integer array `a[]` of size `n`, find the length of the longest subsequence such that the absolute difference between adjacent elements is 1.

**Example:**

Input:

```
n = 7
a[] = {10, 9, 4, 5, 4, 8, 6}
```

Output:

```
3
```

Explanation:
The three possible subsequences of length 3 are {10, 9, 8}, {4, 5, 4}, and {4, 5, 6}, where adjacent elements have an absolute difference of 1. No valid subsequence of greater length could be formed.

### My Approach

1. **Initialization:**

   - Create a dictionary `dp` to store the length of the longest subsequence ending at each element.
   - Initialize a variable `ans` to keep track of the maximum subsequence length found.

2. **Dynamic Programming Calculation:**

   - Iterate through the array `a`.
   - For each element `x` in `a`:
     - Calculate the lengths of the subsequences ending at `x - 1` and `x + 1`.
     - Update `dp[x]` to the maximum length between its current value and the new lengths found.
     - Update `ans` with the maximum value of `dp[x]`.

3. **Return:**
   - Return the value of `ans`, which contains the length of the longest subsequence where the absolute difference of adjacent elements is 1.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^2), as we iterate through the array once and perform constant-time operations for each element.
- **Expected Auxiliary Space Complexity:** O(n), as we use a dictionary to store the lengths of the subsequences for each unique element in the array.

### Code

#### C++

```cpp
class Solution {
public:
    int longestSubseq(int n, std::vector<int> &a) {
        std::unordered_map<int, int> dp;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int x = a[i];
            int len1 = dp[x - 1] + 1;
            int len2 = dp[x + 1] + 1;
            dp[x] = std::max(dp[x], std::max(len1, len2));
            ans = std::max(ans, dp[x]);
        }

        return ans;
    }
};
```

#### Java

```java
class Solution {
    public int longestSubseq(int n, int[] a) {
        HashMap<Integer, Integer> dp = new HashMap<>();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int x = a[i];
            int len1 = dp.getOrDefault(x - 1, 0) + 1;
            int len2 = dp.getOrDefault(x + 1, 0) + 1;
            dp.put(x, Math.max(dp.getOrDefault(x, 0), Math.max(len1, len2)));
            ans = Math.max(ans, dp.get(x));
        }

        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def longestSubseq(self, n : int, a : List[int]) -> int:
        dp = {}
        ans = 0

        for x in a:
            len1 = dp.get(x - 1, 0) + 1
            len2 = dp.get(x + 1, 0) + 1
            dp[x] = max(dp.get(x, 0), len1, len2)
            ans = max(ans, dp[x])

        return ans
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
