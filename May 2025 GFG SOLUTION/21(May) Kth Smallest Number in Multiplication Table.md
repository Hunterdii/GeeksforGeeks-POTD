# *21. Kth Smallest Number in Multiplication Table*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1)


## **🧩 Problem Description**

Given three integers `m`, `n`, and `k`, representing an `m × n` multiplication table (1-indexed), return the `k`th smallest element from it.
Each cell of the matrix is defined as:
    **`mat[i][j] = i × j`**

The multiplication table is filled in row-wise sorted and column-wise sorted order.


## **📘 Examples**

### **Example 1:**

**Input:** `m = 3`, `n = 3`, `k = 5`

**Output:** `3`

**Explanation:**

<img src="https://github.com/user-attachments/assets/0a356397-7709-4a6f-a554-aaa8a1178055" width="30%">


The elements in increasing order are: `[1, 2, 2, 3, 3, 4, 6, 6, 9]` → the 5<sup>th</sup> smallest is `3`.

### **Example 2:**

**Input:** `m = 2`, `n = 3`, `k = 6`

**Output:** `6`

**Explanation:** The multiplication table is:


```
[1, 2, 3]  
[2, 4, 6]  
```

Flattened and sorted: `[1, 2, 2, 3, 4, 6]` → the 6<sup>th</sup> smallest is `6`.


## **🔒 Constraints**

* \$1 \leq m, n \leq 3 \times 10^4\$
* \$1 \leq k \leq m \times n\$


## **✅ My Approach**

### **Binary Search on Value**

We are asked to find the `k`th smallest value in a virtual `m × n` multiplication table without building the table. Since values range from `1` to `m × n`, and the table is sorted row-wise and column-wise, we can **binary search** over the **value space**, not the index space.

At each step of binary search:

* We guess a value `mid`, and count how many numbers in the table are `≤ mid`.
* For each row `i` (1-based), the count of elements ≤ `mid` is `min(n, mid // i)`.
* If total count ≥ `k`, then `mid` might be the answer (go left).
  Else, go right.

### **Algorithm Steps:**

1. Initialize the binary search bounds: `l = 1`, `r = m * n`.
2. While `l < r`:

   * Compute `mid = (l + r) // 2`.
   * Count how many elements in the table are `≤ mid`.
   * If count < `k`, set `l = mid + 1`
     Else, set `r = mid`.
3. Return `l`.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(log(m × n) × min(m, n)), as we binary search over value space and count in each row up to `min(m, n)`.
* **Expected Auxiliary Space Complexity:** O(1), as we use only a constant amount of extra space.


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = (l + r) / 2, cnt = 0;
            for (int i = 1; i <= m; ++i) cnt += min(n, mid / i);
            cnt < k ? l = mid + 1 : r = mid;
        }
        return l;
    }
};
```


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int kthSmallest(int m, int n, int k) {
        int l = 1, r = m * n;
        while (l < r) {
            int mid = (l + r) / 2, cnt = 0;
            for (int i = 1; i <= m; i++) cnt += Math.min(n, mid / i);
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution(object):
    def kthSmallest(self, m, n, k):
        l, r = 1, m * n
        while l < r:
            mid = (l + r) // 2
            cnt = sum(min(n, mid // i) for i in range(1, m + 1))
            if cnt < k: l = mid + 1
            else: r = mid
        return l
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
