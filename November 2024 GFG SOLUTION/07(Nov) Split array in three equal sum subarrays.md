# _07. Split Array in Three Equal Sum Subarrays_

> **🚨 Note:** Apologies to previous visitors who may have encountered an incorrect solution. The solution has been fully resolved and updated according to the problem requirements.

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/split-array-in-three-equal-sum-subarrays/1)

## Problem Description

Given an array `arr[]`, determine if the array can be split into three consecutive parts such that the sum of each part is equal. If it’s possible, return any index pair `(i, j)` in the array such that the sum of the subarray `arr[0..i]` is equal to the sum of the subarray `arr[i+1..j]` and equal to the sum of the subarray `arr[j+1..n-1]`. Otherwise, return `{-1, -1}`.

Note: The driver code will print `true` if the array can be split into three equal sum subarrays; otherwise, it will print `false`.

### Examples:

**Input:**

```
arr[] = [1, 3, 4, 0, 4]
```

**Output:**

```
true
```

**Explanation:**
The pair `(1, 2)` is valid because the sum of subarrays `arr[0..1]`, `arr[2..3]`, and `arr[4..4]` are all equal to 4.

**Input:**

```
arr[] = [2, 3, 4]
```

**Output:**

```
false
```

**Explanation:**
No three subarrays exist which have equal sums.

**Input:**

```
arr[] = [0, 1, 1]
```

**Output:**

```
false
```

## My Approach

1. **Sum Calculation and Check:**

   - First, compute the total sum of the array.
   - If the total sum is not divisible by 3, return `{-1, -1}` because it’s impossible to split the array into three parts with equal sums.

2. **Iterative Approach to Find the Split:**
   - Traverse the array while maintaining the running sum of the elements.
   - Keep track of how many times we encounter a sum that equals `totalSum / 3` (the first partition), and then check for when the second partition reaches `2 * totalSum / 3`.
   - Once both conditions are met, return the indices that define the partitions.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of elements in the array. We perform a linear scan to compute the sum and then another scan to check the partition conditions.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space to track the running sum and indices.

## Code (C++)

```cpp
class Solution {
public:
    vector<int> findSplit(vector<int>& arr) {
        int total_sum = 0;
        for (int num : arr) {
            total_sum += num;
        }

        if (total_sum % 3 != 0) {
            return {-1, -1};
        }

        int target_sum = total_sum / 3;
        int current_sum = 0;
        int first_index = -1, second_index = -1;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            current_sum += arr[i];

            if (current_sum == target_sum && first_index == -1) {
                first_index = i;
            }

            if (current_sum == 2 * target_sum && first_index != -1) {
                second_index = i;
                break;
            }
        }

        if (first_index != -1 && second_index != -1) {
            int last_part_sum = 0;
            for (int i = second_index + 1; i < n; i++) {
                last_part_sum += arr[i];
            }
            if (last_part_sum == target_sum) {
                return {first_index, second_index};
            }
        }

        return {-1, -1};
    }
};
```

## Code (Java)

```java
class Solution {
    public List<Integer> findSplit(int[] arr) {
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        if (totalSum % 3 != 0) {
            return Arrays.asList(-1, -1);
        }

        int targetSum = totalSum / 3;
        int currentSum = 0;
        int firstIndex = -1, secondIndex = -1;

        for (int i = 0; i < arr.length; i++) {
            currentSum += arr[i];

            if (currentSum == targetSum && firstIndex == -1) {
                firstIndex = i;
            } else if (currentSum == 2 * targetSum && firstIndex != -1) {
                secondIndex = i;
                break;
            }
        }

        if (firstIndex != -1 && secondIndex != -1) {
            int lastPartSum = 0;
            for (int i = secondIndex + 1; i < arr.length; i++) {
                lastPartSum += arr[i];
            }
            if (lastPartSum == targetSum) {
                return Arrays.asList(firstIndex, secondIndex);
            }
        }

        return Arrays.asList(-1, -1);
    }
}
```

## Code (Python)

```python
class Solution:

    def findSplit(self, arr):
        total_sum = sum(arr)
        if total_sum % 3 != 0:
            return [-1, -1]

        target_sum = total_sum // 3
        current_sum = 0
        first_index, second_index = -1, -1

        for i in range(len(arr)):
            current_sum += arr[i]

            if current_sum == target_sum and first_index == -1:
                first_index = i
            elif current_sum == 2 * target_sum and first_index != -1:
                second_index = i
                break

        if first_index != -1 and second_index != -1:
            last_part_sum = sum(arr[second_index + 1:])
            if last_part_sum == target_sum:
                return [first_index, second_index]

        return [-1, -1]
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
