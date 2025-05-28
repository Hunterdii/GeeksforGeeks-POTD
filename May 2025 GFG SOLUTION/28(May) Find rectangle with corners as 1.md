# *28. Find Rectangle with Corners as 1*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-rectangle-with-corners-as-1--141631/1)


## **🧩 Problem Description**

Given an `n × m` binary matrix `mat[][]` containing only `0`s and `1`s, determine if there exists a rectangle within the matrix such that all four corners of the rectangle are `1`. If such a rectangle exists, return `true`; otherwise, return `false`.


## **📘 Examples**

### **Example 1:**

#### **Input:**

```
mat = [
  [1, 0, 0, 1, 0],
  [0, 0, 1, 0, 1],
  [0, 0, 0, 1, 0], 
  [1, 0, 1, 0, 1]
]
```

#### **Output:**

`true`

#### **Explanation:**

Valid corners at `(1,2), (1,4), (3,2), (3,4)`.

### **Example 2:**

#### **Input:**

```
mat = [
  [0, 0, 0],
  [0, 0, 0],
  [0, 0, 0]
]
```

#### **Output:**

`false`

#### **Explanation:**

No four `1`s form the corners of a rectangle.


## **🔒 Constraints**

* `1 ≤ n, m ≤ 200`
* `mat[i][j] ∈ {0, 1}`
  


## **✅ My Approach**

### **Row Pair Comparison with Column Counting**

**Goal:**
Check if any two rows in the matrix have at least **two common columns** with value `1`. Such a pair would form the **top-left, top-right, bottom-left, and bottom-right corners** of a rectangle with 1s.

**Algorithm Steps:**

1. Let `n` be the number of rows and `m` be the number of columns in the matrix.
2. Iterate over all pairs of rows `(i, j)` where `i < j`:

   * For each column `k`, check if both `mat[i][k]` and `mat[j][k]` are `1`.
   * Count the number of such columns.
   * If the count exceeds 1, return `true` (a rectangle exists).
3. If no such pair of rows with 2 or more common 1s exists, return `false`.

This brute-force check across all row pairs is efficient enough for moderate matrix sizes due to `n(n-1)/2` row combinations and `m` column checks per combination.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n²·m), as we compare each pair of `n` rows and check `m` columns.
* **Expected Auxiliary Space Complexity:** O(1), as we use only constant extra variables.


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < m; ++k)
                    cnt += mat[i][k] & mat[j][k];
                if (cnt > 1) return true;
            }
        return false;
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ Bitset Intersection (Fast for Sparse Matrices)**

### **Algorithm Steps:**

1. Convert each row to a `bitset` of size `m`.
2. For each pair of rows, compute `bitset[i] & bitset[j]`.
3. If the result has `.count() > 1`, a rectangle exists.

```cpp
class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<bitset<1000>> bs(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (mat[i][j]) bs[i].set(j);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if ((bs[i] & bs[j]).count() > 1) return true;
        return false;
    }
};
```

### ✅ **Why This Works Well?**

* Uses hardware-optimized operations for fast intersection.
* Best when `m` is large and rows are sparse.

#### 📝 **Complexity Analysis:**

* **Time:** O(n²·(m/64))
* **Space:** O(n·m/64) for storing bitsets


## 📊 **3️⃣ Column-Pair Counting (Best for Dense Rows)**

### **Algorithm Steps:**

1. For each row, collect all `1`-column indices.
2. For every pair of columns `(a,b)` in that row, encode a 64-bit key: `(a<<32)|b`.
3. Use a map to count how often each column pair appears.
4. If any pair appears in more than 1 row → rectangle exists.

```cpp
class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int m = mat[0].size();
        unordered_map<long long, int> count;
        for (auto& row : mat) {
            vector<int> ones;
            for (int j = 0; j < m; ++j)
                if (row[j]) ones.push_back(j);
            for (int a = 0; a < ones.size(); ++a)
                for (int b = a + 1; b < ones.size(); ++b) {
                    long long key = ((long long)ones[a] << 32) | ones[b];
                    if (++count[key] > 1) return true;
                }
        }
        return false;
    }
};
```

### ✅ **Why This Works Well?**

* Converts the 2D problem to a 1D hash-detection task.
* Early exit when duplicate column-pairs found.

#### 📝 **Complexity Analysis:**

* **Time:** O(n·k²) where `k` is average number of 1s per row.
* **Space:** O(n·k²) for the map


## 🆚 **Comparison of Approaches**

| **Approach**            | ⏱️ **Time**     | 🗂️ **Space** | ✅ **Pros**                          | ⚠️ **Cons**                       |
| ----------------------- | --------------- | ------------- | ----------------------------------- | --------------------------------- |
| ▶️ Row Pair & Column Count | 🔸 O(n²·m)      | 🟢 O(1)       | Simple and intuitive                | Slow for large `n`                |
| 🧮 Bitset Intersection     | 🟢 O(n²·(m/64)) | 🟡 O(n·m/64)  | Fast with sparse rows, scalable     | Needs `bitset` and fixed size     |
| 🔗 Column Pair Map         | 🟢 O(n·k²)      | 🟡 O(n·k²)    | Best for sparse 1s, fast hash check | Costly if rows are densely filled |

### ✅ **Best Choice?**

| **Scenario**                | **Recommended Approach** |
| --------------------------- | ------------------------ |
| 🏆 Matrix is small or simple   | 🥇 Row Comparison        |
| 📏 Large `m` with sparse `1`s  | 🥈 Bitset Intersection   |
| ⚙️ Large matrix with many rows | 🥉 Column Pair Mapping   |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public boolean ValidCorner(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < m; k++)
                    cnt += mat[i][k] & mat[j][k];
                if (cnt > 1) return true;
            }
        return false;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def ValidCorner(self, mat):
        n, m = len(mat), len(mat[0])
        for i in range(n):
            for j in range(i + 1, n):
                if sum(mat[i][k] & mat[j][k] for k in range(m)) > 1:
                    return True
        return False
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
