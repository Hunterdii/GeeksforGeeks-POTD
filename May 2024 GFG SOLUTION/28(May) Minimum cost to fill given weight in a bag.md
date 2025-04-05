## 28. Minimum Cost to Fill Given Weight in a Bag

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1)

### Problem Description

Given an array `cost[]` of positive integers of size `n` and an integer `w`, where `cost[i]` represents the cost of an `i` kg packet of oranges, the task is to find the minimum cost to buy exactly `w` kg of oranges. The cost array has a 1-based indexing. If buying exactly `w` kg of oranges is impossible, then return -1.

**Note:**

1. `cost[i] = -1` means that `i` kg packet of orange is unavailable.
2. It may be assumed that there is an infinite supply of all available packet types.

### Example:

**Input:**

```
n = 5
cost[] = {20, 10, 4, 50, 100}
w = 5
```

**Output:**

```
14
```

**Explanation:**
Purchase the 2kg packet for 10 coins and the 3kg packet for 4 coins to buy 5kg of oranges for 14 coins.

### My Approach

1. **Initialization:**

   - Create a 2D vector `memo` of size `(n + 1) x (w + 1)` initialized to -1 to store the minimum cost to achieve a certain weight using available packets up to a certain index.
   - Define a helper function `findMinCost` that takes the current index, the cost array, the remaining weight, and the memoization table as parameters.

2. **Base Cases:**

   - If the weight is 0, return 0 (no cost required for 0 weight).
   - If the index exceeds the length of the cost array or the weight is less than the current packet size, return `INT_MAX` (indicating infeasibility).

3. **Recursive Calculation:**

   - If the current index cost is available and it does not exceed the remaining weight, consider including it and calculate the result recursively for the remaining weight.
   - Also, consider excluding the current index and moving to the next.
   - Store and return the minimum of these two choices in the memoization table.

4. **Return Result:**
   - Call the helper function starting from index 0 and the full weight `w`.
   - If the result is `INT_MAX`, return -1, otherwise return the result.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* w), as we compute the minimum cost for each possible combination of index and weight using memoization.
- **Expected Auxiliary Space Complexity:** O(n \* w), as we use a 2D vector of size `(n + 1) x (w + 1)` to store intermediate results.

### Code

#### C++

```cpp
class Solution {
public:
    int findMinCost(int index, vector<int>& cost, int weight, vector<vector<int>>& memo) {
        if (weight == 0) {
            return 0;
        }
        if (index >= cost.size() || index + 1 > weight) {
            return INT_MAX;
        }
        if (memo[index][weight] != -1) {
            return memo[index][weight];
        }

        int includeCurrent = INT_MAX;
        if (cost[index] != -1 && index + 1 <= weight) {
            int result = findMinCost(index, cost, weight - (index + 1), memo);
            if (result != INT_MAX) {
                includeCurrent = cost[index] + result;
            }
        }
        int excludeCurrent = findMinCost(index + 1, cost, weight, memo);

        memo[index][weight] = min(includeCurrent, excludeCurrent);
        return memo[index][weight];
    }

    int minimumCost(int n, int w, vector<int>& cost) {
        vector<vector<int>> memo(n + 1, vector<int>(w + 1, -1));
        int result = findMinCost(0, cost, w, memo);

        return result == INT_MAX ? -1 : result;
    }
};
```

#### Java

```java
class Solution {
    private int findMinCost(int index, int[] cost, int weight, int[][] memo) {
        if (weight == 0) {
            return 0;
        }
        if (index >= cost.length || index + 1 > weight) {
            return Integer.MAX_VALUE;
        }
        if (memo[index][weight] != -1) {
            return memo[index][weight];
        }

        int includeCurrent = Integer.MAX_VALUE;
        if (cost[index] != -1 && index + 1 <= weight) {
            int result = findMinCost(index, cost, weight - (index + 1), memo);
            if (result != Integer.MAX_VALUE) {
                includeCurrent = cost[index] + result;
            }
        }
        int excludeCurrent = findMinCost(index + 1, cost, weight, memo);

        memo[index][weight] = Math.min(includeCurrent, excludeCurrent);
        return memo[index][weight];
    }

    public int minimumCost(int n, int w, int[] cost) {
        int[][] memo = new int[n + 1][w + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        int result = findMinCost(0, cost, w, memo);
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def findMinCost(self, index: int, cost: List[int], weight: int, memo: List[List[int]]) -> int:
        if weight == 0:
            return 0
        if index >= len(cost) or index + 1 > weight:
            return float('inf')
        if memo[index][weight] != -1:
            return memo[index][weight]

        includeCurrent = float('inf')
        if cost[index] != -1 and index + 1 <= weight:
            result = self.findMinCost(index, cost, weight - (index + 1), memo)
            if result != float('inf'):
                includeCurrent = cost[index] + result

        excludeCurrent = self.findMinCost(index + 1, cost, weight, memo)

        memo[index][weight] = min(includeCurrent, excludeCurrent)
        return memo[index][weight]

    def minimumCost(self, n: int, w: int, cost: List[int]) -> int:
        memo = [[-1] * (w + 1) for _ in range(n + 1)]
        result = self.findMinCost(0, cost, w, memo)
        return -1 if result == float('inf') else result
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
