# <b>17. Product Array Puzzle</b>

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1)

### Problem Description

Given an array `nums[]`, construct a Product Array `P[]` such that `P[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

**Example 1:**

Input:

```
nums[] = [10, 3, 5, 6, 2]
```

Output:

```
[180, 600, 360, 300, 900]
```

Explanation:

- For `i=0`, `P[0] = 3*5*6*2 = 180`.
- For `i=1`, `P[1] = 10*5*6*2 = 600`.
- For `i=2`, `P[2] = 10*3*6*2 = 360`.
- For `i=3`, `P[3] = 10*3*5*2 = 300`.
- For `i=4`, `P[4] = 10*3*5*6 = 900`.

### My Approach

1. **Initialization:**

   - Create two arrays, `leftProduct` and `rightProduct`, both initialized to `1`. These will store the cumulative product of elements to the left and right of each index, respectively.

2. **Left Product Calculation:**

   - Traverse the array from left to right to fill the `leftProduct` array. For each element, multiply the previous element in `leftProduct` by the previous element in `nums`.

3. **Right Product Calculation:**

   - Traverse the array from right to left to fill the `result` array. For each element, multiply the corresponding element in `leftProduct` by a running product accumulator from the right side.

4. **Return Result:**
   - The final `result` array will contain the desired product values for each index.

### Time and Auxiliary Space Complexity

**Expected Time Complexity:** O(n), as we are traversing the array twice, once for computing left products and once for computing right products.
**Expected Auxiliary Space Complexity:** O(n), due to the storage of the `leftProduct` and `result` arrays, which each require `O(n)` space.

### Code (C++)

```cpp
class Solution {
public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        vector<long long int> leftProduct(n, 1), rightProduct(n, 1), result(n);
        for (int i = 1; i < n; ++i) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }
        long long rightProductAcc = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] = leftProduct[i] * rightProductAcc;
            rightProductAcc *= nums[i];
        }

        return result;
    }
};
```

### Code (Java)

```java
class Solution {
    public long[] productExceptSelf(int[] nums) {
        int n = nums.length;
        long[] leftProduct = new long[n];
        long[] result = new long[n];

        leftProduct[0] = 1;
        for (int i = 1; i < n; i++) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }

        long rightProductAcc = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = leftProduct[i] * rightProductAcc;
            rightProductAcc *= nums[i];
        }

        return result;
    }
}
```

### Code (Python)

```python
class Solution:
    def productExceptSelf(self, nums):
        n = len(nums)
        left_product = [1] * n
        result = [1] * n
        for i in range(1, n):
            left_product[i] = left_product[i - 1] * nums[i - 1]
        right_product_acc = 1
        for i in range(n - 1, -1, -1):
            result[i] = left_product[i] * right_product_acc
            right_product_acc *= nums[i]

        return result
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
