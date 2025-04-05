# _12. Two Smallest in Every Subarray_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-sum-of-smallest-and-second-smallest-in-an-array/1)

### Problem Description

Given an array of integers, the task is to find and return the maximum sum of the smallest and second smallest elements among all possible subarrays of size greater than one. If it is not possible, then return -1.

**Example:**

Input:  
`arr = [4, 3, 1, 5, 6]`

Output:  
`11`

**Explanation:**  
Subarrays with smallest and second smallest are:

- Subarray: [4, 3], smallest = 3, second smallest = 4, sum = 7
- Subarray: [4, 3, 1], smallest = 1, second smallest = 3, sum = 4
- Subarray: [4, 3, 1, 5], smallest = 1, second smallest = 3, sum = 4
- Subarray: [4, 3, 1, 5, 6], smallest = 1, second smallest = 3, sum = 4
- Subarray: [3, 1], smallest = 1, second smallest = 3, sum = 4
- Subarray: [3, 1, 5], smallest = 1, second smallest = 3, sum = 4
- Subarray: [3, 1, 5, 6], smallest = 1, second smallest = 3, sum = 4
- Subarray: [1, 5], smallest = 1, second smallest = 5, sum = 6
- Subarray: [1, 5, 6], smallest = 1, second smallest = 5, sum = 6
- Subarray: [5, 6], smallest = 5, second smallest = 6, sum = 11

Maximum sum among all above choices is, 5 + 6 = 11, hence the answer is 11.

Input:  
`arr = [1]`

Output:  
`-1`  
**Explanation:** Here the size of the array is 1, but we need a minimum of 2 elements. Hence, the answer is -1.

### My Approach

1. **Iterate through the array:** Loop through the array and examine each possible subarray of size greater than one.

2. **Find the two smallest elements:** For each subarray, determine the smallest and second smallest elements. This can be achieved by keeping track of the two smallest numbers while iterating through the subarray.

3. **Calculate the sum:** For each subarray, calculate the sum of the two smallest elements and keep track of the maximum sum encountered.

4. **Return the result:** If no valid subarray exists, return -1; otherwise, return the maximum sum found.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array only once, using constant time operations to find the two smallest elements.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables to store the two smallest elements and the maximum sum.

### Code (C++)

```cpp
class Solution {
public:
    int pairWithMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n < 2)
            return -1;
        int maxSum = arr[0] + arr[1];
        for (int i = 1; i < n - 1; ++i) {
            int currentSum = arr[i] + arr[i + 1];
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
```

### Code (Java)

```java
class Solution {
    public int pairWithMaxSum(int[] arr) {
        int n = arr.length;
        if (n < 2) return -1;
        int maxSum = arr[0] + arr[1];
        for (int i = 1; i < n - 1; i++) {
            maxSum = Math.max(maxSum, arr[i] + arr[i + 1]);
        }
        return maxSum;
    }
}
```

### Code (Python)

```python
class Solution:
    def pairWithMaxSum(self, arr):
        if len(arr) < 2:
            return -1
        return max(arr[i] + arr[i + 1] for i in range(len(arr) - 1))
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
