## 14. Largest Subsquare Surrounded by X

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-subsquare-surrounded-by-x0558/1)

### Problem Description

Given a square matrix `a` of size `n x n`, where each cell can be either 'X' or 'O', you need to find the size of the largest square subgrid that is completely surrounded by 'X'. More formally, you need to find the largest square within the grid where all its border cells are 'X'.

**Example:**

```
Input:
n = 2
a = [[X,X],
     [X,X]]
Output:
2
Explanation:
The largest square submatrix
surrounded by X is the whole
input matrix.
```

- **Expected Time Complexity:** O(n^2), where n is the size of the input square matrix.
- **Expected Auxiliary Space Complexity:** O(n^2), where n is the size of the input square matrix, for storing the dynamic programming array.

**Constraints:**

- 1 <= n <= 1000
- `a[i][j]` belongs to {'X','O'}

### My Approach

1. **Preprocessing:**

   - Convert the given matrix `a` into a binary matrix where 'X' is represented as 1 and 'O' is represented as 0.

2. **Dynamic Programming:**
   - Create a 2D array `dp` of the same size as the input matrix, initialized with all zeros.
   - Iterate over each cell of the matrix and fill the `dp` array as follows:
     - If the cell is 'X', set `dp[i][j]` to the minimum of the values of `dp[i-1][j]`, `dp[i][j-1]`, and `dp[i-1][j-1]` plus 1.
     - Otherwise, set `dp[i][j]` to 0.
   - The maximum value in the `dp` array gives the size of the largest subsquare surrounded by 'X'.

### Code (Python)

```cpp
class Solution {
    public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<int>> v1(n,vector<int>(n,0));
        vector<vector<int>> v2(n,vector<int>(n,0));

        // col
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=n-1;j>=0;j--)
            {
                if(a[i][j]=='O')
                {
                    sum=0;
                    v1[i][j]=0;
                }
                else
                {
                    sum++;
                    v1[i][j]=sum;
                }
            }
        }

        // rows
        int maxi=10002;
        for(int j=0;j<n;j++)
        {
            int sum=0;
            for(int i=n-1;i>=0;i--)
            {
                if(a[i][j]=='O')
                sum=0;
                else
                {
                    sum++;
                    v2[i][j]=sum;
                }
            }
        }


        //finding max submatrix
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='O')
                continue;

                int size=min(v1[i][j],v2[i][j]);

                while(size>ans)
                {
                    if((v1[i+size-1][j])>=size and (v2[i][j+size-1])>=size)
                    ans=size;

                    size--;
                }
            }
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
