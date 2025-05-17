
# *17. Sort the given array after applying the given equation*


The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1)


## **🧩 Problem Description**

Given a sorted array `arr[]` in ascending order and integers `A`, `B`, and `C`, apply the quadratic transformation `f(x) = A·x² + B·x + C` to each element of the array.
Then return the transformed array in sorted order.


## **📘 Examples**

### **Example 1:**

**Input:**

`arr = [-4, -2, 0, 2, 4]`, `A = 1`, `B = 3`, `C = 5`

**Output:**

`[3, 5, 9, 15, 33]`

**Explanation:**

Transformed values: `[9, 3, 5, 15, 33]`

Sorted: `[3, 5, 9, 15, 33]`


### **Example 2:**

**Input:**
`arr = [-3, -1, 2, 4]`, `A = -1`, `B = 0`, `C = 0`

**Output:**

`[-16, -9, -4, -1]`

**Explanation:**

Transformed values: `[-9, -1, -4, -16]`
Sorted: `[-16, -9, -4, -1]`


## **🔒 Constraints**

* \$1 \leq \text{arr.size()} \leq 10^6\$
* \$-10^3 \leq \text{arr}\[i], A, B, C \leq 10^3\$

## **✅ My Approach**

### **Two-Pointer Approach**

We take advantage of the original array being sorted and the fact that a quadratic function opens upwards (when `A > 0`) or downwards (when `A < 0`). The key observation is that:

* For `A >= 0`: Largest transformed values appear at both ends of the original array.
* For `A < 0`: Smallest transformed values appear at both ends.

We use two pointers from left and right, and fill the result from either start or end depending on the sign of `A`.

### **Algorithm Steps:**

1. Define the quadratic function `f(x) = A*x*x + B*x + C`.
2. Use two pointers: `l` at start and `r` at end of the array.
3. Maintain an index `i` that fills the result:

   * From end if `A >= 0` (placing larger values last).
   * From start if `A < 0` (placing smaller values first).
4. Compare `f(arr[l])` and `f(arr[r])`, and insert the appropriate value into result.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n), where n is the size of the array. We process each element once in a linear two-pointer sweep.
* **Expected Auxiliary Space Complexity:** O(n), as we use a new result array to store the transformed elements.

## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size(), l = 0, r = n - 1, i = A >= 0 ? n - 1 : 0;
        vector<int> res(n);
        auto f = [&](int x) { return A * x * x + B * x + C; };
        while (l <= r) {
            int lv = f(arr[l]), rv = f(arr[r]);
            if (A >= 0) res[i--] = lv > rv ? lv : rv, lv > rv ? ++l : --r;
            else res[i++] = lv < rv ? lv : rv, lv < rv ? ++l : --r;
        }
        return res;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approach</h2></summary>

## 📊 **2️⃣ Naïve Map-and-Sort**

### **Algorithm Steps**

1. Allocate `res` of size `n`.
2. For each index `k` in `[0..n-1]`, compute `res[k] = f(arr[k])`.
3. Sort `res`.
4. Return `res`.

```cpp
class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
            res[i] = A*arr[i]*arr[i] + B*arr[i] + C;
        sort(res.begin(), res.end());
        return res;
    }
};
```

### ✅ **Why This Approach?**

* Straightforward and easy to implement.

#### 📝 **Complexity Analysis**

* **Time:** 🔸 O(n log n) (due to sort)
* **Auxiliary Space:** 🟢 O(n)

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public ArrayList<Integer> sortArray(int[] arr, int A, int B, int C) {
        int n = arr.length, l = 0, r = n - 1, i = A >= 0 ? n - 1 : 0;
        ArrayList<Integer> res = new ArrayList<>(Collections.nCopies(n, 0));
        while (l <= r) {
            int lv = A * arr[l] * arr[l] + B * arr[l] + C;
            int rv = A * arr[r] * arr[r] + B * arr[r] + C;
            if (A >= 0) {
                res.set(i--, lv > rv ? lv : rv);
                if (lv > rv) l++; else r--;
            } else {
                res.set(i++, lv < rv ? lv : rv);
                if (lv < rv) l++; else r--;
            }
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def sortArray(self, arr, A, B, C):
        n, l, r, i = len(arr), 0, len(arr) - 1, len(arr) - 1 if A >= 0 else 0
        f = lambda x: A * x * x + B * x + C
        res = [0] * n
        while l <= r:
            lv, rv = f(arr[l]), f(arr[r])
            if A >= 0:
                res[i] = lv if lv > rv else rv
                i -= 1
                l += lv > rv
                r -= lv <= rv
            else:
                res[i] = lv if lv < rv else rv
                i += 1
                l += lv < rv
                r -= lv >= rv
        return res
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
