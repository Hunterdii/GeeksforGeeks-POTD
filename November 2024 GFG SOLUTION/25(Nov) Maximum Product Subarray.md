# _25. Maximum Product Subarray_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised in the poll, I’ve started solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My latest solution is now live:  
  **[773. Sliding Puzzle](https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/773.Sliding%20Puzzle.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/773.Sliding%20Puzzle.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/773.Sliding%20Puzzle.md">
  <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
</div>

<br/>

## Problem Description

Given an array `arr[]` that contains both positive and negative integers (and possibly zeros), find the maximum product of any subarray within the array.

**Note:** The result will always fit within the range of a 32-bit integer.

### Examples:

**Input:**  
`arr[] = [-2, 6, -3, -10, 0, 2]`  
**Output:**  
`180`

**Explanation:**  
The subarray with the maximum product is {6, -3, -10} with product = 6 _ (-3) _ (-10) = 180.

**Input:**  
`arr[] = [-1, -3, -10, 0, 60]`  
**Output:**  
`60`

**Explanation:**  
The subarray with the maximum product is {60}.

**Input:**  
`arr[] = [2, 3, 4]`  
**Output:**  
`24`

**Explanation:**  
For an array with all positive elements, the result is the product of all elements.

### Constraints:

- `1 ≤ arr.size() ≤ 10^6`
- `-10 ≤ arr[i] ≤ 10`

## My Approach

1. **Dynamic Programming with Two Variables (maxVal, minVal):**  
   The idea is to track the maximum and minimum product subarrays up to the current index. The minimum product may become the maximum product if multiplied by a negative number.

2. **Steps:**
   - Traverse the array, updating the `maxVal` and `minVal` at each step based on the current number.
   - If the current number is negative, we swap `maxVal` and `minVal`.
   - Update `maxProduct` after processing each element to keep track of the overall maximum product encountered.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the size of the array. The algorithm requires a single pass through the array, making it efficient.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of extra space.

## Code (C)

```c
int maxProduct(int arr[], int n) {
    int maxProduct = arr[0];
    int maxVal = arr[0], minVal = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < 0) {
            int temp = maxVal;
            maxVal = minVal;
            minVal = temp;
        }

        maxVal = (arr[i] > maxVal * arr[i]) ? arr[i] : maxVal * arr[i];
        minVal = (arr[i] < minVal * arr[i]) ? arr[i] : minVal * arr[i];

        maxProduct = (maxProduct > maxVal) ? maxProduct : maxVal;
    }

    return maxProduct;
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int maxVal = nums[0], minVal = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                std::swap(maxVal, minVal);
            }

            maxVal = std::max(nums[i], maxVal * nums[i]);
            minVal = std::min(nums[i], minVal * nums[i]);

            maxProduct = std::max(maxProduct, maxVal);
        }

        return maxProduct;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches </h2></summary>

1.

```cpp
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int maxProduct = arr[0], maxVal = arr[0], minVal = arr[0];

        for (int i = 1; i < n; ++i) {
            int current = arr[i];

            if (current < 0) swap(maxVal, minVal);

            maxVal = max(current, maxVal * current);
            minVal = min(current, minVal * current);

            maxProduct = max(maxProduct, maxVal);
        }

        return maxProduct;
    }
};
```

2.

```cpp
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int maxProduct = arr[0], maxVal = arr[0], minVal = arr[0];

        for (int i = 1; i < n; ++i) {
            int current = arr[i];

            if (current < 0) {
                int temp = maxVal;
                maxVal = minVal;
                minVal = temp;
            }

            maxVal = (current > maxVal * current) ? current : maxVal * current;
            minVal = (current < minVal * current) ? current : minVal * current;

            if (maxVal > maxProduct) {
                maxProduct = maxVal;
            }
        }

        return maxProduct;
    }
};
```

</details>

## Code (Java)

```java
class Solution {

    int maxProduct(int[] nums) {
        int maxProduct = nums[0];
        int maxVal = nums[0];
        int minVal = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < 0) {

                int temp = maxVal;
                maxVal = minVal;
                minVal = temp;
            }

            maxVal = Math.max(nums[i], maxVal * nums[i]);
            minVal = Math.min(nums[i], minVal * nums[i]);

            maxProduct = Math.max(maxProduct, maxVal);
        }

        return maxProduct;
    }
}
```

## Code (Python)

```python
class Solution:

    def maxProduct(self, arr):
        max_product = arr[0]
        max_val = arr[0]
        min_val = arr[0]

        for i in range(1, len(arr)):
            if arr[i] < 0:
                max_val, min_val = min_val, max_val

            max_val = max(arr[i], max_val * arr[i])
            min_val = min(arr[i], min_val * arr[i])

            max_product = max(max_product, max_val)

        return max_product
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
