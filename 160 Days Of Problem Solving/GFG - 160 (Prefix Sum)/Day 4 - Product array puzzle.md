---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - prefix-sum
  - Arrays
---

# 🚀 _Day 4. Product array puzzle_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/product-array-puzzle4525)

## 💡 **Problem Description:**

You are given an array `arr[]` of size `n`. Your task is to construct an array `res[]` such that `res[i]` is equal to the product of all the elements of `arr[]` except `arr[i]`. Return the resultant array `res[]`.  
**Note:** Each element in `res[]` lies within the 32-bit integer range.

## 🔍 **Example Walkthrough:**

**Input:**  
`arr[] = [10, 3, 5, 6, 2]`  
**Output:**  
`[180, 600, 360, 300, 900]`  
**Explanation:**  
For `i = 0`, `res[i] = 3 * 5 * 6 * 2 = 180`.  
For `i = 1`, `res[i] = 10 * 5 * 6 * 2 = 600`.  
For `i = 2`, `res[i] = 10 * 3 * 6 * 2 = 360`.  
For `i = 3`, `res[i] = 10 * 3 * 5 * 2 = 300`.  
For `i = 4`, `res[i] = 10 * 3 * 5 * 6 = 900`.

**Input:**  
`arr[] = [12, 0]`  
**Output:**  
`[0, 12]`  
**Explanation:**  
For `i = 0`, `res[i] = 0`.  
For `i = 1`, `res[i] = 12`.

### Constraints:

- $`2 <= arr.size() <= 10^5`$
- `-100 <= arr[i] <= 100`

## 🎯 **My Approach:**

1. **Handling Zeroes:**  
   If the array contains:

   - **More than one zero**: Every element in `res[]` will be `0`.
   - **Exactly one zero**: Only the position corresponding to the zero will have the product of all other non-zero elements, and the rest will be `0`.
   - **No zeroes**: Use the total product of all elements and divide by the current element for each position in the result array.

2. **Efficient Computation:**
   - Iterate through the array once to calculate the total product of non-zero elements and the count of zeroes.
   - Build the result array in a second pass.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), where `n` is the size of the array. The algorithm requires two linear traversals of the array.
- **Expected Auxiliary Space Complexity:** O(1), as the solution uses only a constant amount of additional space.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size(), product = 1, zeroCount = count(arr.begin(), arr.end(), 0);
        if (zeroCount > 1) return vector<int>(n, 0);
        for (int x : arr) if (x) product *= x;
        for (int i = 0; i < n; i++) arr[i] = zeroCount ? (arr[i] ? 0 : product) : product / arr[i];
        return arr;
    }
};
```

## Code (Java)

```java
class Solution {
    public static int[] productExceptSelf(int[] arr) {
        int n = arr.length, product = 1, zeroCount = 0;
        for (int x : arr) if (x == 0) zeroCount++; else product *= x;
        if (zeroCount > 1) return new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = zeroCount > 0 ? (arr[i] == 0 ? product : 0) : product / arr[i];
        return arr;
    }
}
```

## Code (Python)

```python
class Solution:
    def productExceptSelf(self, arr):
        product, zero_count = 1, arr.count(0)
        if zero_count > 1:
            return [0] * len(arr)
        for x in arr:
            if x != 0:
                product *= x
        return [product if x == 0 else 0 if zero_count else product // x for x in arr]
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
