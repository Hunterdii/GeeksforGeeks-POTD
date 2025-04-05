---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Binary Search
  - Arrays
  - Matrix
---

# 🚀 _Day 4. Search in a Row-Wise Sorted Matrix_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/search-in-a-row-wise-sorted-matrix)

## 💡 **Problem Description:**

Given a row-wise sorted 2D matrix `mat[][]` of size `n x m` and an integer `x`, determine whether the element `x` is present in the matrix.

**Note:** A row-wise sorted matrix implies that each row is sorted in non-decreasing order.

## 🔍 **Example Walkthrough:**

Input:

```
mat[][] = [[3, 4, 9], [2, 5, 6], [9, 25, 27]]
x = 9
```

Output:

```
true
```

Explanation: 9 is present in the matrix, so the output is true.

Input:

```
mat[][] = [[19, 22, 27, 38, 55, 67]]
x = 56
```

Output:

```
false
```

Explanation: 56 is not present in the matrix.

Input:

```
mat[][] = [[1, 2, 9], [65, 69, 75]]
x = 91
```

Output:

```
false
```

Explanation: 91 is not present in the matrix.

### Constraints

- $\(1 \leq n, m \leq 1000\)$
- $\(1 \leq \text{mat}[i][j] \leq 10^5\)$
- $\(1 \leq x \leq 10^5\)$

## 🎯 **My Approach:**

1. **Iterate Through Rows**:  
   Loop through each row of the matrix. Since each row is sorted, we can efficiently determine if the target `x` exists using binary search.

2. **Binary Search for Each Row**:  
   For each row:

   - Use the `binary_search` function (in C++) or equivalent methods in other languages to locate `x`.
   - The binary search divides the row into halves and compares the middle element with `x`:
     - If the middle element matches `x`, return `true`.
     - If the middle element is greater than `x`, continue searching in the left half of the row.
     - Otherwise, continue searching in the right half.

3. **Final Check**:  
   If no row contains `x` after checking all rows, return `false`.

## 🕒 **Time and Auxiliary Space Complexity**

**Expected Time Complexity:**

- $\(O(n \cdot \log m)\)$, where $\(n\)$ is the number of rows and $\(m\)$ is the number of columns. This is because for each row, a binary search runs in $\(O(\log m)\)$.

**Expected Auxiliary Space Complexity:**

- $\(O(1)\)$, as the binary search operates in constant space.

## 📝 **Solution Code**

## Code (Cpp)

```cpp
class Solution {
public:
    bool searchRowMatrix(vector<vector<int>>& mat, int x) {
        for (auto& row : mat) {
            if (binary_search(row.begin(), row.end(), x)) return true;
        }
        return false;
    }
};
```

## Code (Java)

```java
class Solution {
    public boolean searchRowMatrix(int[][] mat, int x) {
        for (int[] row : mat) {
            if (Arrays.binarySearch(row, x) >= 0) {
                return true;
            }
        }
        return false;
    }
}
```

## Code (Python)

```python
class Solution:
    def searchRowMatrix(self, mat, x):
        for row in mat:
            if x in row:
                return True
        return False
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
