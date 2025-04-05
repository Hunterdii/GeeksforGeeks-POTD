---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Binary
  - SearchArrays
---

# 🚀 _Day 8. Kth Missing Positive Number in a Sorted Array_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/searching-gfg-160/problem/kth-missing-positive-number-in-a-sorted-array/1)

## 💡 **Problem Description:**

Given a sorted array of distinct positive integers `arr[]` and an integer `k`, find the `k`th positive number that is missing from the array.

## 🔍 **Example Walkthrough:**

**Input:**

```
arr = [2, 3, 4, 7, 11]
k = 5
```

**Output:**

```
9
```

**Explanation:**  
The missing numbers are `1, 5, 6, 8, 9, 10, ...`. The `5th` missing number is `9`.

**Input:**

```
arr = [3, 5, 9, 10, 11, 12]
k = 2
```

**Output:**

```
2
```

**Explanation:**  
The missing numbers are `1, 2, 4, 6, 7...`. The `2nd` missing number is `2`.

#### Constraints:

- $`1 <= arr.size() <= 10^5`$
- $`1 <= k <= 10^5`$
- $`1 <= arr[i]<= 10^6`$

## 🎯 **My Approach:**

#### Binary Search

1. **Key Observations:**

   - For an index `i` in `arr`, the number of missing positive integers up to `arr[i]` is given by:
     $\[
     \text{Missing Numbers} = arr[i] - (i + 1)
     $\]
   - If this count is less than `k`, the `k`th missing number lies after `arr[i]`. Otherwise, it lies before `arr[i]`.

2. **Steps:**

   - Use binary search over the array to find the smallest index `i` such that the count of missing numbers is at least `k`.
   - Once located, calculate the `k`th missing number using:
     $\[
     \text{Result} = \text{Index} + k
    \]$

3. **Edge Case:**
   - If all missing numbers are after the largest element in `arr`, return:
     $\[
     arr[-1] + (k - \text{Missing Numbers till end})
     \]$

## 🕒 **Time and Auxiliary Space Complexity**

**Expected Time Complexity:**  
$\[
O(log n)
$\]  
where `n` is the size of the array, as binary search is used to locate the position.

**Expected Auxiliary Space Complexity:**  
$\[
O(1)
$\]  
since no additional data structures are used apart from a few variables.

## 📝 **Solution Code**

## Code (C)

```c
int kthMissing(int* arr, int n, int k) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] - (mid + 1) < k) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo + k;
}
```

## Code (C++)

```cpp
class Solution {
public:
    int kthMissing(vector<int>& arr, int k) {
        int lo = 0, hi = arr.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] - (mid + 1) < k)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo + k;
    }
};
```

## Code (Java)

```java
class Solution {
    public int kthMissing(int[] arr, int k) {
        int lo = 0, hi = arr.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] - (mid + 1) < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo + k;
    }
}
```

## Code (Python)

```python
class Solution:
    def kthMissing(self, arr, k):
        lo, hi = 0, len(arr)
        while lo < hi:
            mid = lo + (hi - lo) // 2
            if arr[mid] - (mid + 1) < k:
                lo = mid + 1
            else:
                hi = mid
        return lo + k
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
