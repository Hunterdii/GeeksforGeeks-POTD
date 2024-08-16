# <b>16. Maximize The Cut Segments</b>

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/cutted-segments1642/1)

### Problem Description

Given an integer `n` denoting the length of a line segment, the task is to cut the line segment into the maximum number of smaller segments such that the length of each segment is either `x`, `y`, or `z`. Here, `x`, `y`, and `z` are integers representing possible segment lengths.

If it is not possible to make any cuts, return 0.

**Example:**

Input:
```
n = 4, x = 2, y = 1, z = 1
```
Output:
```
4
```
Explanation: The total length is 4, and the cut lengths are 2, 1, and 1. We can make a maximum of 4 segments, each of length 1.

### My Approach

1. **Dynamic Programming (DP) Initialization:**
   - Create a DP array `dp` of size `n + 1` initialized to -1, except `dp[0]` which is set to 0. This array will store the maximum number of segments that can be made for each length from 0 to `n`.
   - Initialize an array `cuts` containing the values `x`, `y`, and `z`.

2. **Filling the DP Array:**
   - Iterate through each length `i` from 1 to `n`.
   - For each length `i`, iterate over the possible cuts in `cuts`. If the current length `i` is greater than or equal to the cut length and the previous length `i - cut` can be achieved (`dp[i - cut] != -1`), update `dp[i]` as the maximum of its current value and `dp[i - cut] + 1`.

3. **Final Result:**
   - The final result is stored in `dp[n]`. If `dp[n]` is -1, return 0, indicating no segments can be made. Otherwise, return `dp[n]`, which represents the maximum number of segments.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we are iterating through each possible length from 1 to `n` and checking up to three possible cuts for each length.
- **Expected Auxiliary Space Complexity:** O(n), as we are using a DP array of size `n + 1` to store the maximum number of segments for each length.

### Code (C++)
```cpp
class Solution
{
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i >= x && dp[i - x] != -1) {
                dp[i] = max(dp[i], dp[i - x] + 1);
            }
            if (i >= y && dp[i - y] != -1) {
                dp[i] = max(dp[i], dp[i - y] + 1);
            }
            if (i >= z && dp[i - z] != -1) {
                dp[i] = max(dp[i], dp[i - z] + 1);
            }
        }
        return dp[n] == -1 ? 0 : dp[n];
    }
};

```
### Code (Java)
```java
class Solution {
    public int maximizeCuts(int n, int x, int y, int z) {
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            dp[i] = -1;
        }
        for (int i = 0; i <= n; i++) {
            if (dp[i] != -1) {
                // Check if we can make a cut of length x, y, or z
                if (i + x <= n) dp[i + x] = Math.max(dp[i + x], dp[i] + 1);
                if (i + y <= n) dp[i + y] = Math.max(dp[i + y], dp[i] + 1);
                if (i + z <= n) dp[i + z] = Math.max(dp[i + z], dp[i] + 1);
            }
        }
        
        return dp[n] == -1 ? 0 : dp[n];
    }
}



```
### Code (Python)
```python
class Solution:
    
    def maximizeTheCuts(self, n, x, y, z):
        dp = [-1] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            if i >= x and dp[i - x] != -1:
                dp[i] = max(dp[i], dp[i - x] + 1)
                
            if i >= y and dp[i - y] != -1:
                dp[i] = max(dp[i], dp[i - y] + 1)
                
            if i >= z and dp[i - z] != -1:
                dp[i] = max(dp[i], dp[i - z] + 1)
        
        return max(dp[n], 0)

```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

### Code Credit : [Rushikesh Mane](https://www.linkedin.com/in/-rushikeshmane)
