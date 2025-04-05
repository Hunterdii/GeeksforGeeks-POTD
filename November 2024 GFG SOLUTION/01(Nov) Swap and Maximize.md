# _01. Swap and Maximize_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/swap-and-maximize5859/1)

## Problem Description

Given an array `arr[]` of positive elements, consider it as a circular array where the element after the last element is the first element of the array. The task is to find the maximum sum of the absolute differences between consecutive elements with allowed shuffling of array elements. The goal is to rearrange the array elements to maximize the sum of absolute differences:

\[ |a*1 - a_2| + |a_2 - a_3| + \dots + |a*{n-1} - a_n| + |a_n - a_1| \]

### Example 1

**Input:**

```
arr[] = [4, 2, 1, 8]
```

**Output:**

```
18
```

**Explanation:**  
After shuffling, we get [1, 8, 2, 4]. The sum of absolute differences between consecutive elements becomes:  
\[ |1 - 8| + |8 - 2| + |2 - 4| + |4 - 1| = 7 + 6 + 2 + 3 = 18 \]

## Example 2

**Input:**

```
arr[] = [10, 12]
```

**Output:**

```
4
```

**Explanation:**  
No rearrangement needed. The sum of absolute differences between consecutive elements is:  
\[ |10 - 12| + |12 - 10| = 2 + 2 = 4 \]

## Constraints

- 2 ≤ arr.size()≤ 10^5
- 1 <= arr[i] <= 10^5

## My Approach

1. **Sort the Array:**

   - Begin by sorting the array to arrange elements in ascending order. Sorting helps in maximizing the absolute differences when rearranging elements from the smallest to the largest and then largest to the smallest.

2. **Calculate the Maximum Sum:**

   - Iterate over the first half of the sorted array and the second half (in reverse). Calculate the absolute differences for these arranged elements and add them to the total sum:
     - Add the absolute difference between the largest and smallest elements and continue this alternation for maximum effect.

3. **Optimal Shuffling:**
   - This approach works by alternating between the smallest and largest values in a sorted array, thus maximizing the difference between adjacent elements.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), due to the initial sorting of the array.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of extra space.

## Code (C++)

```cpp
class Solution {
public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        long long totalSum = 0;
        int n = arr.size();

        for (int i = 0; i < n / 2; ++i) {
            totalSum += abs(arr[n - i - 1] - arr[i]);
            totalSum += abs(arr[i] - arr[n - i - 1]);
        }

        return totalSum;
    }
};
```

## Code (Java)

```java
class Solution {
    public long maxSum(Long[] arr) {
        Arrays.sort(arr);

        long totalSum = 0;
        int n = arr.length;

        for (int i = 0; i < n / 2; ++i) {
            totalSum += Math.abs(arr[n - i - 1] - arr[i]);
            totalSum += Math.abs(arr[i] - arr[n - i - 1]);
        }

        return totalSum;
    }
}
```

## Code (Python)

```python
class Solution:
    def maxSum(self, arr):
        arr.sort()

        totalSum = 0
        n = len(arr)

        for i in range(n // 2):
            totalSum += abs(arr[n - i - 1] - arr[i])
            totalSum += abs(arr[i] - arr[n - i - 1])

        return totalSum
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
