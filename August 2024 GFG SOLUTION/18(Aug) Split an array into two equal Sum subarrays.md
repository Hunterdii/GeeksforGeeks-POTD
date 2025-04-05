# <b>18. Split an Array into Two Equal Sum Subarrays</b>

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/split-an-array-into-two-equal-sum-subarrays/1)

### Problem Description

Given an array of integers `arr`, determine if it is possible to split the array into two subarrays (without reordering the elements) such that the sum of the two subarrays is equal. If it is possible, return `true`; otherwise, return `false`.

**Examples:**

Input:

```
arr = [1, 2, 3, 4, 5, 5]
```

Output:

```
true
```

Explanation: The array can be split into two subarrays `[1, 2, 3, 4]` and `[5, 5]` both with a sum of 10.

Input:

```
arr = [4, 3, 2, 1]
```

Output:

```
false
```

Explanation: The array cannot be split into two subarrays with equal sum.

### My Approach

1. **Initial Sum Calculation:**

   - Calculate the total sum of the array. This will be used to determine if a valid split is possible.

2. **Iterating from the End:**
   - Initialize `rightSum` to 0 and iterate over the array from the last element to the first.
   - In each iteration, add the current element to `rightSum`.
   - Check if `rightSum` multiplied by 2 equals the `totalSum`. If so, it means the array can be split into two equal sum subarrays.
   - If such a condition is met, return `true`.
   - If the loop completes without finding a valid split, return `false`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array once to compute the sums.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables.

### Code (C++)

```cpp
class Solution {
public:
    bool canSplit(vector<int>& arr) {
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        int rightSum = 0;
        for (int i = arr.size() - 1; i >= 0; --i) {
            rightSum += arr[i];
            if (rightSum * 2 == totalSum) {
                return true;
            }
        }
        return false;
    }
};
```

### Code (Java)

```java
class Solution {
    public boolean canSplit(int[] arr) {
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        int rightSum = 0;
        for (int i = arr.length - 1; i >= 0; --i) {
            rightSum += arr[i];
            if (rightSum * 2 == totalSum) {
                return true;
            }
        }

        return false;
    }
}
```

### Code (Python)

```python
class Solution:
    def canSplit(self, arr):
        total_sum = sum(arr)
        right_sum = 0
        for i in range(len(arr) - 1, -1, -1):
            right_sum += arr[i]
            if right_sum * 2 == total_sum:
                return True

        return False
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
