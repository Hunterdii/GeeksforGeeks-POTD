## 12. Sum of Products

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-products5049/1)

### Problem Description

Given an array `arr[]` of size `n`, calculate the sum of Bitwise ANDs, i.e., calculate the sum of `arr[i] & arr[j]` for all the pairs in the given array `arr[]` where `i < j`.

**Example:**

Input:

```
n = 3
arr = {5, 10, 15}
```

Output:

```
15
```

Explanation:
The bitwise ANDs of all pairs where `i < j` are `(5 & 10) = 0`, `(5 & 15) = 5`, and `(10 & 15) = 10`.
Therefore, the total sum = `(0 + 5 + 10) = 15`.

### My Approach

1. **Iterative Bitwise AND Calculation:**

   - Initialize `ans` to 0.
   - Iterate over each bit position from 0 to 31.
   - For each bit position, count the number of elements in the array `arr[]` where the bit is set (`1`).
   - Calculate the sum of products for this bit position using the formula: `((count * (count - 1)) / 2) * (1 << i)`, and add it to `ans`.

2. **Return Result:**
   - Return the final value of `ans`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array once to calculate the sum of products.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    long long pairAndSum(int N, long long arr[]) {
        long long ans = 0;
        for (int i = 0; i < 32; ++i) {
            long long count = 0;
            for (int j = 0; j < N; ++j) {
                count += (arr[j] >> i) & 1LL;
            }
            ans += ((count * (count - 1)) / 2) * (1LL << i);
        }
        return ans;
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
