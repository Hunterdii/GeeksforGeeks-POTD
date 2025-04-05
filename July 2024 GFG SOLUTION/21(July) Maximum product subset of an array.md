## 21. Maximum Product Subset of an Array

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-product-subset-of-an-array/1)

### Problem Description

Given an array `arr`, the task is to find and return the maximum product possible with the subset of elements present in the array. Note that the maximum product can be a single element also. Since the product can be large, return it modulo \(10^9 + 7\).

**Examples:**

Input:

```
arr = [-1, 0, -2, 4, 3]
```

Output:

```
24
```

Explanation:
The maximum product is \((-1) \times (-2) \times 4 \times 3 = 24\).

### My Approach

1. **Initialization:**

   - Define variables to count negative numbers (`negCount`), track the maximum negative number (`maxNeg`), and compute the product of positive numbers (`posProduct`) and the product of negative numbers (`negProduct`). Initialize `posProduct` and `negProduct` to 1.
   - A boolean variable `hasNonZero` is used to check if there is any non-zero positive number.

2. **Counting Negatives and Finding Maximum Negative:**

   - Iterate through the array to count the number of negative numbers and find the maximum negative number.

3. **Calculating the Maximum Product:**
   - If the count of negative numbers is odd, skip the maximum negative number in the product calculation.
   - Compute the product of all positive numbers and negative numbers (excluding the maximum negative number if needed).
   - If there are no non-zero numbers and there are one or fewer negative numbers, return 0.
   - Otherwise, return the product of `posProduct` and `negProduct` modulo \(10^9 + 7\).

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array twice (once for counting and once for product calculation).
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space regardless of the size of the input array.

### Code (C++)

```cpp
class Solution {
public:
    int mod = 1e9 + 7;
    long long int findMaxProduct(vector<int>& arr) {
        int negCount = 0;
        int maxNeg = INT_MIN;
        long long posProduct = 1;
        long long negProduct = 1;
        bool hasNonZero = false;

        for (int num : arr) {
            if (num < 0) {
                negCount++;
                maxNeg = max(maxNeg, num);
            }
        }
        bool skipMaxNeg = (negCount % 2 == 1);

        for (int num : arr) {
            if (num < 0) {
                if (skipMaxNeg && num == maxNeg) {
                    skipMaxNeg = false;
                    continue;
                }
                negProduct = (negProduct * abs(num)) % mod;
            } else if (num > 0) {
                posProduct = (posProduct * num) % mod;
                hasNonZero = true;
            }
        }
        if (!hasNonZero && negCount <= 1) return 0;
        return (negProduct * posProduct) % mod;
    }
};
```

### Code (Java)

```java
class Solution {
    private final int mod = (int) 1e9 + 7;

    public long findMaxProduct(List<Integer> arr) {
        int negCount = 0;
        int maxNeg = Integer.MIN_VALUE;
        long posProduct = 1;
        long negProduct = 1;
        boolean hasNonZero = false;

        for (int num : arr) {
            if (num < 0) {
                negCount++;
                maxNeg = Math.max(maxNeg, num);
            }
        }

        boolean skipMaxNeg = (negCount % 2 == 1);

        for (int num : arr) {
            if (num < 0) {
                if (skipMaxNeg && num == maxNeg) {
                    skipMaxNeg = false;
                    continue;
                }
                negProduct = (negProduct * Math.abs(num)) % mod;
            } else if (num > 0) {
                posProduct = (posProduct * num) % mod;
                hasNonZero = true;
            }
        }

        if (!hasNonZero && negCount <= 1) return 0;
        return (negProduct * posProduct) % mod;
    }
}
```

### Code (Python)

```python
class Solution:
    def findMaxProduct(self, arr):
        mod = int(1e9 + 7)
        neg_count = 0
        max_neg = float('-inf')
        pos_product = 1
        neg_product = 1
        has_non_zero = False

        for num in arr:
            if num < 0:
                neg_count += 1
                max_neg = max(max_neg, num)

        skip_max_neg = (neg_count % 2 == 1)

        for num in arr:
            if num < 0:
                if skip_max_neg and num == max_neg:
                    skip_max_neg = False
                    continue
                neg_product = (neg_product * abs(num)) % mod
            elif num > 0:
                pos_product = (pos_product * num) % mod
                has_non_zero = True

        if not has_non_zero and neg_count <= 1:
            return 0
        return (neg_product * pos_product) % mod
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
