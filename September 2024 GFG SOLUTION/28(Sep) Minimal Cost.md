# _28. Minimal Cost_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimal-cost/1)

### Problem Description

You are given an array `arr` of heights of stones and Geek is standing at the first stone. The task is to find the minimum possible cost for Geek to reach the last stone. Geek can jump to one of the following: Stone `i+1`, `i+2`, ..., `i+k` stone, where `k` is the maximum number of steps that can be jumped. The cost to jump from stone `i` to stone `j` is the absolute difference `|arr[i] - arr[j]|`.

_Example 1:_

Input:

```
k = 3
arr = [10, 30, 40, 50, 20]
```

Output:

```
30
```

Explanation: Geek will follow the path `1 -> 2 -> 5`, and the total cost would be `|10 - 30| + |30 - 20| = 30`.

### My Approach

1. _Dynamic Programming Setup:_

   - We use a DP array `dp[]` where `dp[i]` stores the minimum cost to reach the i-th stone.

2. _Initialization:_

   - `dp[0] = 0`, because the cost to reach the first stone is zero (starting point).
   - For each stone `i` (from the second stone onwards), calculate the minimum cost by checking all possible jumps from the previous stones within the jump limit `k`.

3. _Recurrence Relation:_

   - For each stone `i`, compute:
     \[
     dp[i] = \min(dp[i - j] + |arr[i] - arr[i - j]|) \quad \text{for all } j \in [1, k]
     \]
   - This means for each stone `i`, we find the optimal jump from any previous stone within the allowable range `[i-k, i-1]`.

4. _Final Answer:_
   - The final answer will be the value of `dp[n-1]` where `n` is the number of stones, representing the minimum cost to reach the last stone.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* k), where `n` is the number of stones and `k` is the maximum number of steps allowed for each jump. This is because for each stone, we check up to `k` previous stones to compute the minimum cost.
- **Expected Auxiliary Space Complexity:** O(n), as we only use a DP array of size `n` to store the minimum costs for each stone.

### Code (C++)

```cpp
class Solution {
public:
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int min_v = INT_MAX;
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int curr = dp[i - j] + abs(arr[i] - arr[i - j]);
                    min_v = min(curr, min_v);
                }
            }
            dp[i] = min_v;
        }
        return dp[n - 1];
    }
};
```

### Code (Java)

```java
class Solution {
    public int minimizeCost(int k, int[] arr) {
        int n = arr.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            int min_v = Integer.MAX_VALUE;
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int curr = dp[i - j] + Math.abs(arr[i] - arr[i - j]);
                    min_v = Math.min(curr, min_v);
                }
            }
            dp[i] = min_v;
        }

        return dp[n - 1];
    }
}
```

### Code (Python)

```python
class Solution:
    def minimizeCost(self, k, arr):
        n = len(arr)
        dp = [-1] * n
        dp[0] = 0

        for i in range(1, n):
            min_v = float('inf')
            for j in range(1, k+1):
                if i - j >= 0:
                    curr = dp[i - j] + abs(arr[i] - arr[i - j])
                    min_v = min(curr, min_v)
            dp[i] = min_v

        return dp[n - 1]
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
