## 24. Partitions with Given Difference

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1)

### Problem Description

Given an array `arr`, partition it into two subsets (possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be `S1` and `S2`. Given a difference `d`, count the number of partitions in which the difference between `S1` and `S2` is equal to `d`. Since the answer may be large, return it modulo \(10^9 + 7\).

**Example:**

Input:

```
n = 4
d = 3
arr[] = {5, 2, 6, 4}
```

Output:

```
1
```

Explanation:
There is only one possible partition of this array. Partition: `{6, 4}`, `{5, 2}`. The subset difference between subset sums is: `(6 + 4) - (5 + 2) = 3`.

**Example:**

Input:

```
n = 4
d = 0
arr[] = {1, 1, 1, 1}
```

Output:

```
6
```

Explanation:
We can choose two `1`s from indices `{0,1}`, `{0,2}`, `{0,3}`, `{1,2}`, `{1,3}`, `{2,3}` and put them in `S1` and the remaining two `1`s in `S2`. Thus, there are a total of 6 ways to partition the array `arr`.

### Approach

1. **Initialization:**

   - Calculate the total sum of the array elements.
   - If the total sum is less than `d` or if `(total_sum - d) % 2` is not zero, return 0, as no valid partition is possible.
   - Define `target = (total_sum - d) / 2`, the sum we need to find in one subset.

2. **Dynamic Programming Table:**

   - Initialize a DP array `dp` of size `target + 1` with all zeros.
   - `dp[0]` is set to 1 as there is exactly one way to achieve a sum of 0, which is by not picking any elements.

3. **Filling the DP Table:**

   - Iterate through each element in the array.
   - For each element, update the DP table from `target` down to the element's value to count the number of ways to form each possible sum up to `target`.

4. **Return:**
   - The value `dp[target]` will give the number of ways to partition the array into two subsets with the required difference.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* sum(arr)), as we iterate through each element and for each element, we iterate through all possible sums up to `target`.
- **Expected Auxiliary Space Complexity:** O(sum(arr)), as we use a DP array of size `target + 1`.

### Code

#### C++

```cpp
class Solution {
public:
    const int MOD = 1000000007;

    int findWays(vector<int>& num, int tar) {
        int n = num.size();
        vector<int> dp(tar + 1, 0);

        dp[0] = 1; // Base case: there's one way to make sum 0

        for (int ind = 0; ind < n; ind++) {
            for (int target = tar; target >= num[ind]; target--) {
                dp[target] = (dp[target] + dp[target - num[ind]]) % MOD;
            }
        }
        return dp[tar];
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum < d || (sum - d) % 2 != 0) {
            return 0;
        }
        return findWays(arr, (sum - d) / 2);
    }
};
```

#### Java

```java
class Solution {
    private static final int MOD = 1000000007;

    public static int findWays(int[] num, int tar) {
        int n = num.length;
        int[] dp = new int[tar + 1];

        dp[0] = num[0] == 0 ? 2 : 1;

        if (num[0] != 0 && num[0] <= tar) {
            dp[num[0]] = 1;
        }

        for (int ind = 1; ind < n; ind++) {
            int[] newDp = new int[tar + 1];
            for (int target = 0; target <= tar; target++) {
                int notTaken = dp[target];
                int taken = (target >= num[ind]) ? dp[target - num[ind]] : 0;

                newDp[target] = (notTaken + taken) % MOD;
            }
            dp = newDp;
        }

        return dp[tar];
    }

    public int countPartitions(int n, int d, int[] arr) {
        int sum = Arrays.stream(arr).sum();
        if (sum < d || (sum - d) % 2 != 0) {
            return 0;
        }
        return findWays(arr, (sum - d) / 2);
    }

    public static void main(String[] args) {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int d = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            System.out.println(obj.countPartitions(n, d, arr));
        }
        sc.close();
    }
}
```

#### Python

```python
from typing import List

class Solution:
    MOD = 1000000007

    def findWays(self, num: List[int], tar: int) -> int:
        dp = [0] * (tar + 1)
        dp[0] = 2 if num[0] == 0 else 1

        if num[0] != 0 and num[0] <= tar:
            dp[num[0]] = 1

        for ind in range(1, len(num)):
            for target in range(tar, num[ind] - 1, -1):
                dp[target] = (dp[target] + dp[target - num[ind]]) % self.MOD

        return dp[tar]

    def countPartitions(self, n: int, d: int, arr: List[int]) -> int:
        total_sum = sum(arr)
        if total_sum < d or (total_sum - d) % 2 != 0:
            return 0
        return self.findWays(arr, (total_sum - d) // 2)
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
