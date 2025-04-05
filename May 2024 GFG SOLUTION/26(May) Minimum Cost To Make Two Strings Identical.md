## 26. Minimum Cost To Make Two Strings Identical

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-to-make-two-strings-identical1107/1)

### Problem Description

Given two strings `x` and `y`, and two values `costX` and `costY`, the task is to find the minimum cost required to make the given two strings identical. You can delete characters from both strings. The cost of deleting a character from string `x` is `costX` and from `y` is `costY`.

**Example:**

Input:

```
x = "abcd", y = "acdb", costX = 10, costY = 20
```

Output:

```
30
```

Explanation:
For making both strings identical, we have to delete the character 'b' from both strings, hence the cost will be = 10 + 20 = 30.

Input:

```
x = "ef", y = "gh", costX = 10, costY = 20
```

Output:

```
60
```

Explanation:
For making both strings identical, we have to delete 2 characters from both strings, hence the cost will be = 10 + 10 + 20 + 20 = 60.

### Approach

1. **Longest Common Subsequence (LCS):**

   - Calculate the longest common subsequence (LCS) between the two strings `x` and `y`.
   - The LCS helps in identifying the characters that need to be retained in both strings.

2. **Minimum Cost Calculation:**
   - The cost to make both strings identical is determined by the characters that are not part of the LCS.
   - For each character in `x` that is not in the LCS, the cost is `costX`.
   - For each character in `y` that is not in the LCS, the cost is `costY`.
   - Total cost is calculated as: `(length of x - LCS length) * costX + (length of y - LCS length) * costY`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|x| \* |y|), as we need to compute the LCS which involves filling a table of size `|x|` by `|y|`.
- **Expected Auxiliary Space Complexity:** O(min(|x|, |y|)), since we use two arrays to store the current and previous row during the LCS computation.

### Code

**C++:**

```cpp
class Solution {
public:
    int lcs(string &x, string &y) {
        int n = x.length(), m = y.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (x[i - 1] == y[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            swap(prev, curr);
        }
        return prev[m];
    }

    int findMinCost(string x, string y, int costX, int costY) {
        int length = lcs(x, y);
        return costX * (x.length() - length) + costY * (y.length() - length);
    }
};
```

**Java:**

```java
class Solution {
    private int lcs(String x, String y) {
        int n = x.length(), m = y.length();
        int[] prev = new int[m + 1];
        int[] curr = new int[m + 1];

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (x.charAt(i - 1) == y.charAt(j - 1)) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = Math.max(prev[j], curr[j - 1]);
                }
            }
            int[] temp = prev;
            prev = curr;
            curr = temp;
        }
        return prev[m];
    }

    public int findMinCost(String x, String y, int costX, int costY) {
        int length = lcs(x, y);
        return costX * (x.length() - length) + costY * (y.length() - length);
    }
}
```

**Python:**

```python
class Solution:
    def lcs(self, x, y):
        n, m = len(x), len(y)
        prev = [0] * (m + 1)
        curr = [0] * (m + 1)

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if x[i - 1] == y[j - 1]:
                    curr[j] = prev[j - 1] + 1
                else:
                    curr[j] = max(prev[j], curr[j - 1])
            prev, curr = curr, prev
        return prev[m]

    def findMinCost(self, x, y, costX, costY):
        length = self.lcs(x, y)
        return costX * (len(x) - length) + costY * (len(y) - length)
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
