# *8. Missing Element of Arithmetic Progression*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1)

## **🧩 Problem Description**

Given an array of `n` integers which forms an arithmetic progression (AP) except for one missing element, find the missing number in the array.

The given array is sorted in increasing order and follows the property:

**`arr[i+1] - arr[i] = constant`** for all valid `i`, *except where the number is missing*.


## **📘 Examples**

### **Example 1**

* **Input:**
  `arr = [2, 4, 8, 10, 12, 14]`
* **Output:**
  `6`
* **Explanation:**
  The intended AP is `2, 4, 6, 8, 10, 12, 14`. The missing element is `6`.

### **Example 2**

* **Input:**
  `arr = [1, 6, 11, 16, 21, 31]`
* **Output:**
  `26`
* **Explanation:**
  The intended AP is `1, 6, 11, 16, 21, 26, 31`. The missing element is `26`.

### **Example 3**

* **Input:**
  `arr = [4, 7, 10, 13, 16]`
* **Output:**
  `19`
* **Explanation:**
  Already a perfect AP with difference `3`. The next element is `16 + 3 = 19`.


## **🔒 Constraints**

* `2 ≤ arr.size() ≤ 10^5`
* `0 ≤ arr[i] ≤ 2×10^7`
* It is guaranteed that exactly one term is missing in the AP.


## **✅ My Approach**

### **Optimized Approach: Binary Search**

We use the formula of an AP:

> `arr[i] = arr[0] + i*d`

Let `d` be the common difference. Since one term is missing, we try to estimate `d` using the edges.
We use binary search to find the first position where the actual difference doesn’t match the expected difference.


### **Algorithm Steps:**

1. Let `n` be the size of the array.
2. Estimate `d` using a combination of:

   * `d1 = arr[1] - arr[0]`
   * `d2 = arr[n-1] - arr[n-2]`
   * `d3 = (arr[n-1] - arr[0]) / n`
3. Choose the most frequent/common value among `d1`, `d2`, and `d3` as `d`.
4. Use binary search:

   * At each step, compute `mid`.
   * If `arr[mid] - arr[0] == mid * d`, go right.
   * Otherwise, the missing number lies to the left.
5. After exiting loop, return `arr[0] + lo * d`.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(log n), using binary search to locate the break point in the AP.
* **Expected Auxiliary Space Complexity:** O(1), as only a constant number of variables are used.


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        int d1 = arr[1] - arr[0], 
            d2 = arr[n-1] - arr[n-2], 
            d3 = (arr[n-1] - arr[0]) / n;
        int d = (d1==d2 || d1==d3) ? d1 : d2;
        if (d == 0) return arr[0];
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if ((arr[mid] - arr[0]) / d == mid) lo = mid + 1;
            else hi = mid - 1;
        }
        return arr[0] + lo * d;
    }
};
```

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int findMissing(int[] a) {
        int n = a.length;
        int d1 = a[1] - a[0], d2 = a[n-1] - a[n-2], d3 = (a[n-1] - a[0]) / n;
        int d = (d1==d2 || d1==d3) ? d1 : d2;
        if (d == 0) return a[0];
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >>> 1;
            if ((a[mid] - a[0]) / d == mid) lo = mid + 1;
            else hi = mid - 1;
        }
        return a[0] + lo * d;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def findMissing(self, a):
        n = len(a)
        d1 = a[1] - a[0]; d2 = a[-1] - a[-2]; d3 = (a[-1] - a[0]) // n
        d = d1 if (d1==d2 or d1==d3) else d2
        if d == 0: return a[0]
        lo, hi = 0, n-1
        while lo <= hi:
            mid = (lo + hi) // 2
            if (a[mid]-a[0])//d == mid: lo = mid + 1
            else: hi = mid - 1
        return a[0] + lo * d
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
