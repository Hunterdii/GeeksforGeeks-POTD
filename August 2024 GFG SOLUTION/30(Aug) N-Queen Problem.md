# **30. N-Queen Problem**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/n-queen-problem0315/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

The n-queens puzzle is the problem of placing `n` queens on an `n×n` chessboard such that no two queens can attack each other. Given an integer `n`, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens placement, where the solutions are a permutation of `[1, 2, 3,..., n]` in increasing order. Here, the number in the `i-th` place denotes that the `i-th` column queen is placed in the row with that number.

**Examples:**

Input:

```
n = 1
```

Output:

```
[1]
```

Explanation: Only one queen can be placed in the single cell available.

Input:

```
n = 4
```

Output:

```
[[2, 4, 1, 3], [3, 1, 4, 2]]
```

Explanation: These are the 2 possible solutions.

### My Approach

1. **Backtracking Setup:**

   - We use a recursive backtracking approach to explore all possible positions for the queens on the board. The function `bt` is responsible for placing queens on the board, column by column.
   - An array `row[]` keeps track of the row positions of the queens in each column.

2. **Checking for Validity:**

   - The `place` function checks whether placing a queen at a specific row and column is valid. It ensures that no two queens can attack each other by checking for row and diagonal conflicts.

3. **Recursive Backtracking:**

   - The backtracking function tries to place a queen in each row of the current column and then recursively attempts to place queens in subsequent columns. If a valid configuration is found, it is stored in the result.

4. **Final Output:**
   - The result is a list of all valid configurations where no two queens can attack each other.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n!), as the problem involves generating all permutations of queen placements, and each placement requires checking validity, which takes linear time.
- **Expected Auxiliary Space Complexity:** O(n²), due to the recursion stack and the space used to store the solutions.

### Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> result;
    int row[10], k = 0;

    bool place(int r, int c) {
        for (int prev = 0; prev < c; prev++) {
            if (row[prev] == r || abs(row[prev] - r) == abs(prev - c)) {
                return false;
            }
        }
        return true;
    }
    void bt(int c, int n) {
        if (c == n) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                v.push_back(row[i] + 1);
            }
            result.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (place(i, c)) {
                row[c] = i;
                bt(c + 1, n);
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        result.clear();
        bt(0, n);
        return result;
    }
};
```

### Code (Java)

```java
class Solution {
    private ArrayList<ArrayList<Integer>> result;
    private int[] row;

    public Solution() {
        result = new ArrayList<>();
        row = new int[10];
    }

    private boolean place(int r, int c) {
        for (int prev = 0; prev < c; prev++) {
            if (row[prev] == r || Math.abs(row[prev] - r) == Math.abs(prev - c)) {
                return false;
            }
        }
        return true;
    }

    private void bt(int c, int n) {
        if (c == n) {
            ArrayList<Integer> v = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                v.add(row[i] + 1);
            }
            result.add(v);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (place(i, c)) {
                row[c] = i;
                bt(c + 1, n);
            }
        }
    }

    public ArrayList<ArrayList<Integer>> nQueen(int n) {
        result.clear();
        bt(0, n);
        return result;
    }
}
```

### Code (Python)

```python
class Solution:
    def __init__(self):
        self.result = []
        self.row = [0] * 10

    def place(self, r, c):
        for prev in range(c):
            if self.row[prev] == r or abs(self.row[prev] - r) == abs(prev - c):
                return False
        return True

    def bt(self, c, n):
        if c == n:
            self.result.append([self.row[i] + 1 for i in range(n)])
            return
        for i in range(n):
            if self.place(i, c):
                self.row[c] = i
                self.bt(c + 1, n)

    def nQueen(self, n):
        self.result = []
        self.bt(0, n)
        return self.result
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
