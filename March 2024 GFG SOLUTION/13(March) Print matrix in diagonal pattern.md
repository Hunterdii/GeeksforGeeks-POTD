## 13. Print Matrix in Diagonal Pattern

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1)

### Problem Description

Given a square matrix `mat[][]` of size `n*n`, the task is to determine the diagonal pattern which is a linear arrangement of the elements of the matrix as depicted in the following example:
<br/>
<br/>
![matrix-6](https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/711ce360-6e07-4bfb-9ad3-d97ecba15427)

**Example:**

```
Input:
n = 3
mat[][] = {{1, 2, 3},
           {4, 5, 6},
           {7, 8, 9}}
Output: {1, 2, 4, 7, 5, 3, 6, 8, 9}
```

**Explaination:**

- Starting from (0, 0): 1,
- Move to the right to (0, 1): 2,
- Move diagonally down to (1, 0): 4,
- Move diagonally down to (2, 0): 7,
- Move diagonally up to (1, 1): 5,
- Move diagonally up to (1, 2): 3,
- Move to the right to (2, 1): 6,
- Move diagonally up to (0, 2): 8,
- Move diagonally up to (2, 2): 9

**Your Task:**

You only need to implement the given function `matrixDiagonally()` which takes a matrix `mat[][]` of size `n*n` as an input and returns a list of integers containing the matrix diagonally. Do not read input, instead use the arguments given in the function.

**Expected Time Complexity:** O(n\*n).
**Expected Auxiliary Space:** O(1).

**Constraints:**

- 1 <= n <= 100
- -100 <= elements of matrix <= 100

### My Approach

1. We iterate through the matrix and store the elements along with their positions in a vector of pairs.
2. We sort the vector of pairs based on the positions in such a way that elements with the same sum of indices (i+j) are sorted in ascending order.
3. Finally, we extract the elements from the sorted vector and return them as the diagonal pattern.

### Code (C++)

```cpp
class Solution{
public:
    static bool compare(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
        if (a.first.first == b.first.first) {
            return a.first.second < b.first.second;
        }
        return a.first.first < b.first.first;
    }

    vector<int> matrixDiagonally(vector<vector<int>>& mat) {
        vector<pair<pair<int, int>, int>> res;
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j) % 2 == 0) {
                    res.push_back({{i + j, j}, mat[i][j]});
                } else {
                    res.push_back({{i + j, i}, mat[i][j]});
                }
            }
        }

        sort(res.begin(), res.end(), compare);

        vector<int> diagonalOrder;
        for (auto& elem : res) {
            diagonalOrder.push_back(elem.second);
        }

        return diagonalOrder;
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
