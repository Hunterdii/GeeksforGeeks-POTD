# **06. Kadane's Algorithm**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given an integer array `arr[]`, find the contiguous sub-array (containing at least one number) that has the maximum sum and return its sum.

**Examples:**

Input:

```
arr[] = [1, 2, 3, -2, 5]
```

Output:

```
9
```

Explanation: Max subarray sum is 9 for the elements `[1, 2, 3, -2, 5]`.

Input:

```
arr[] = [-1, -2, -3, -4]
```

Output:

```
-1
```

Explanation: Max subarray sum is -1 for the element `[-1]`.

### My Approach

1. **Kadane’s Algorithm:**

   - We maintain two variables: `maxh` for the maximum sum ending at the current index, and `maxf` for the global maximum sum across all subarrays.

2. **Logic:**

   - Initialize `maxh` to 0 and `maxf` to the smallest possible value.
   - For each element `arr[i]`, update `maxh` as the maximum of `arr[i]` and `maxh + arr[i]`. This ensures that we either start a new subarray at `arr[i]` or extend the previous subarray.
   - Update `maxf` to be the maximum of `maxf` and `maxh` after processing each element.

3. **Final Answer:**
   - Return `maxf`, which stores the maximum subarray sum.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the length of the array. We traverse the array once, performing constant-time operations at each step.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for storing `maxh` and `maxf`.

### Code (C++)

```cpp
class Solution {
public:
    long long maxSubarraySum(vector<int>& arr) {
        int n = arr.size();
        long long maxh = 0, maxf = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            maxh = max((long long)arr[i], maxh + arr[i]);
            maxf = max(maxf, maxh);
        }

        return maxf;
    }
};
```

### Code (Java)

```java
class Solution {
    long maxSubarraySum(int[] arr) {
        int n = arr.length;
        long maxh = 0, maxf = Long.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            maxh = Math.max(arr[i], maxh + arr[i]);
            maxf = Math.max(maxf, maxh);
        }

        return maxf;
    }
}
```

### Code (Python)

```python
class Solution:
    def maxSubArraySum(self, arr):
        maxh = 0
        maxf = float('-inf')

        for num in arr:
            maxh = max(num, maxh + num)
            maxf = max(maxf, maxh)

        return maxf
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
