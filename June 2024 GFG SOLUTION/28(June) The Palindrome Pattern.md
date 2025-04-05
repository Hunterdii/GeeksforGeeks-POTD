## 28. The Palindrome Pattern

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/the-palindrome-pattern3900/1)

### Problem Description

Given a two-dimensional integer array `arr` of dimensions `n x n`, consisting solely of zeros and ones, identify the row or column (using 0-based indexing) where all elements form a palindrome. If multiple palindromes are identified, prioritize the palindromes found in rows over those in columns. Within rows or columns, the palindrome with the smaller index takes precedence. The result should be represented by the index followed by either 'R' or 'C', indicating whether the palindrome was located in a row or column. The output should be space-separated. If no palindrome is found, return the string `-1`.

**Example:**

Input:

```
arr[][] =  [[1, 0, 0],
           [0, 1, 0],
           [1, 1, 0]]
```

Output:

```
1 R
```

Explanation:
In the first test case, 0-1-0 is a palindrome occurring in a row having index 1.

### My Approach

1. **Palindrome Check:**

   - Create a helper function `isPalindrome` that checks if a given vector is a palindrome.
   - Iterate through the vector from the start to the middle and check if the elements are the same when compared from the end to the middle.

2. **Row Check:**

   - Iterate through each row in the array.
   - Use the `isPalindrome` function to check if the current row is a palindrome.
   - If a palindrome is found, return the row index followed by 'R'.

3. **Column Check:**

   - Iterate through each column in the array.
   - Construct a vector for the current column and use the `isPalindrome` function to check if the column is a palindrome.
   - If a palindrome is found, return the column index followed by 'C'.

4. **Return:**
   - If no palindrome is found in either rows or columns, return `-1`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^2), as we need to check each element in the `n x n` array.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for our operations.

### Code (C++)

```cpp
class Solution {
public:
    bool isPalindrome(const vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n / 2; ++i) {
            if (arr[i] != arr[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    string pattern(vector<vector<int>>& arr) {
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            if (isPalindrome(arr[i])) {
                return to_string(i) + " R";
            }
        }

        for (int j = 0; j < n; ++j) {
            vector<int> col(n);
            for (int i = 0; i < n; ++i) {
                col[i] = arr[i][j];
            }
            if (isPalindrome(col)) {
                return to_string(j) + " C";
            }
        }

        return "-1";
    }
};
```

### Code (Java)

```java
class Solution {
    public boolean isPalindrome(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n / 2; ++i) {
            if (arr[i] != arr[n - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    public String pattern(int[][] arr) {
        int n = arr.length;

        for (int i = 0; i < n; ++i) {
            if (isPalindrome(arr[i])) {
                return i + " R";
            }
        }

        for (int j = 0; j < n; ++j) {
            int[] col = new int[n];
            for (int i = 0; i < n; ++i) {
                col[i] = arr[i][j];
            }
            if (isPalindrome(col)) {
                return j + " C";
            }
        }

        return "-1";
    }
}
```

### Code (Python)

```python
class Solution:
    def is_palindrome(self, arr):
        n = len(arr)
        for i in range(n // 2):
            if arr[i] != arr[n - 1 - i]:
                return False
        return True

    def pattern(self, arr):
        n = len(arr)

        for i in range(n):
            if self.is_palindrome(arr[i]):
                return "{} R".format(i)

        for j in range(n):
            col = [arr[i][j] for i in range(n)]
            if self.is_palindrome(col):
                return "{} C".format(j)

        return "-1"
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
