## 16. Spirally Traversing a Matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/cutted-segments1642/1)

### Problem Description

Given an integer **n** denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either **x** , **y** or **z**. Here x, y, and z are integers.
After performing all the cut operations, your **total number of cut segments must be maximum**.

**Note**: if no segment can be cut then return 0.

**Examples**:
```
Input: n = 4, x = 2, y = 1, z = 1
Output: 4
Explanation: Total length is 4, and the cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.
```
```
Input: n = 5, x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can make two segments of lengths 3 and 2.
```

### My Approach

1.**DP Array Definition** :
- Create a DP array dp where dp[i] represents the maximum number of segments that can be obtained from a line of length i.

2.**Initialization** :
- Initialize dp[0] = 0 because no cuts can be made on a line of length 0.

3.**Transition Formula** : 
- For each length i, if a cut of length x, y, or z can be made, then update dp[i] as the maximum of its current value or dp[i - cut_length] + 1.

4.**Result** : 
- The answer will be stored in dp[n]. If no segments can be made, return 0

### Time and Auxiliary Space Complexity
- **Expected Time Complexity** : O(n)
- **Expected Auxiliary Space** : O(n)

### Code (C++)
```cpp
class Solution
{
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // DP array to store the maximum cuts
        vector<int> dp(n + 1, -1);

        // Base case: no cuts needed for length 0
        dp[0] = 0;

        // Fill the DP array
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

        // If no cuts were made, return 0, else return dp[n]
        return dp[n] == -1 ? 0 : dp[n];
    }
};

```
### Code (Java)
```java
class Solution {
    // Function to find the maximum number of cuts.
    public int maximizeCuts(int n, int x, int y, int z) {
        // Initialize a dp array of size n+1
        int[] dp = new int[n + 1];
        
        // Initialize the dp array to -1 for all lengths except 0
        for (int i = 1; i <= n; i++) {
            dp[i] = -1;
        }
        
        // Iterate through the dp array
        for (int i = 0; i <= n; i++) {
            // If current length i has a valid solution
            if (dp[i] != -1) {
                // Check if we can make a cut of length x, y, or z
                if (i + x <= n) dp[i + x] = Math.max(dp[i + x], dp[i] + 1);
                if (i + y <= n) dp[i + y] = Math.max(dp[i + y], dp[i] + 1);
                if (i + z <= n) dp[i + z] = Math.max(dp[i + z], dp[i] + 1);
            }
        }
        
        // If dp[n] is still -1, return 0, meaning no cuts could be made
        return dp[n] == -1 ? 0 : dp[n];
    }
}



```
### Code (Python)
```python
class Solution:
    
    # Function to find the maximum number of cuts.
    def maximizeTheCuts(self, n, x, y, z):
        # Initialize dp array with -1. dp[i] will store the maximum number of cuts for length i.
        dp = [-1] * (n + 1)
        
        # Base case: If the length of the line is 0, no cuts are needed.
        dp[0] = 0
        
        # Iterate over all lengths from 1 to n
        for i in range(1, n + 1):
            # Check if it's possible to make a cut of length x
            if i >= x and dp[i - x] != -1:
                dp[i] = max(dp[i], dp[i - x] + 1)
                
            # Check if it's possible to make a cut of length y
            if i >= y and dp[i - y] != -1:
                dp[i] = max(dp[i], dp[i - y] + 1)
                
            # Check if it's possible to make a cut of length z
            if i >= z and dp[i - z] != -1:
                dp[i] = max(dp[i], dp[i - z] + 1)
        
        # If no segments could be made, return 0. Otherwise, return dp[n].
        return max(dp[n], 0)

```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/-rushikeshmane/).
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
