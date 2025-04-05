## 27. Form a Palindrome

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/form-a-palindrome1455/1)

### Problem Description

Given a string, find the minimum number of characters to be inserted to convert it to a palindrome.

**Examples:**

Input:

```
str = "abcd"
```

Output:

```
3
```

Explanation:
Inserted characters marked with bold characters in dcbabcd, here we need minimum three characters to make it palindrome.

### My Approach

1. **Initialization:**

   - Create a 2D table `table` of size `n x n` where `n` is the length of the string.
   - Initialize the table with 0, where `table[i][j]` will store the minimum number of insertions needed to convert the substring `str[i...j]` into a palindrome.

2. **Filling the Table:**

   - Iterate over the gap `gap` from 1 to `n-1`.
   - For each gap, iterate over the substring starting index `l` from 0 to `n-gap-1`, and calculate the ending index `h = l + gap`.
   - If the characters at `str[l]` and `str[h]` are the same, then `table[l][h] = table[l+1][h-1]`.
   - Otherwise, `table[l][h] = min(table[l][h-1], table[l+1][h]) + 1`.

3. **Return:**
   - The value at `table[0][n-1]` will be the minimum number of insertions needed to convert the entire string into a palindrome.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^2), as we fill an `n x n` table where each cell computation takes constant time.
- **Expected Auxiliary Space Complexity:** O(n^2), as we use a 2D table of size `n x n` to store the results of subproblems.

### Code (C++)

```cpp
class Solution {
public:
    int countMin(string str) {
        int n = str.length();
        vector<vector<int>> table(n, vector<int>(n, 0));

        for (int gap = 1; gap < n; ++gap) {
            for (int l = 0, h = gap; h < n; ++l, ++h) {
                table[l][h] = (str[l] == str[h]) ? table[l + 1][h - 1] : min(table[l][h - 1], table[l + 1][h]) + 1;
            }
        }

        return table[0][n - 1];
    }
};
```

### Code (Java)

```java
class Solution {
    static int countMin(String str) {
        int n = str.length();
        int[][] table = new int[n][n];

        for (int gap = 1; gap < n; gap++) {
            for (int l = 0, h = gap; h < n; l++, h++) {
                table[l][h] = (str.charAt(l) == str.charAt(h)) ?
                              table[l + 1][h - 1] :
                              Math.min(table[l][h - 1], table[l + 1][h]) + 1;
            }
        }

        return table[0][n - 1];
    }
}
```

### Code (Python)

```python
class Solution:
    def countMin(self, str):
        n = len(str)
        table = [[0] * n for _ in range(n)]

        for gap in range(1, n):
            for l in range(n - gap):
                h = l + gap
                if str[l] == str[h]:
                    table[l][h] = table[l + 1][h - 1]
                else:
                    table[l][h] = min(table[l][h - 1], table[l + 1][h]) + 1

        return table[0][n - 1]
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
