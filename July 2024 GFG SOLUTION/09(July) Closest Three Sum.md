## 09. Closest Three Sum

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/three-sum-closest/1)

### Problem Description

Given an array `arr` of integers, and another number `target`, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

Note: If there are multiple solutions, return the maximum one.

**Example:**

Input:

```
arr = [-7, 9, 8, 3, 1, 1]
target = 2
```

Output:

```
2
```

Explanation:
There is only one triplet present in the array where elements are -7, 8, 1 whose sum is 2.

### My Approach

1. **Sorting:**

   - First, sort the array `arr`.

2. **Initialization:**

   - Initialize `closest_sum` to a very large value to store the closest sum to the target.
   - Get the size of the array `n`.

3. **Three Pointers Technique:**

   - Iterate through the array with the first pointer `i` from 0 to `n-3`.
   - For each element `arr[i]`, use two pointers `left` (starting from `i+1`) and `right` (starting from `n-1`) to find the triplet sum closest to the target.

4. **Finding the Closest Sum:**

   - Calculate the current sum as `arr[i] + arr[left] + arr[right]`.
   - If the current sum equals the target, return the current sum.
   - Update `closest_sum` if the current sum is closer to the target than the previous closest sum.
   - If the current sum is less than the target, move the `left` pointer to the right to increase the sum.
   - If the current sum is greater than the target, move the `right` pointer to the left to decrease the sum.

5. **Return:**
   - Return `closest_sum` after iterating through all possible triplets.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^2), as we sort the array and use two nested loops to iterate through the triplets.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int closest_sum = INT_MAX;
        int n = arr.size();

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int current_sum = arr[i] + arr[left] + arr[right];

                if (current_sum == target) {
                    return current_sum;
                }

                if (abs(current_sum - target) < abs(closest_sum - target) ||
                   (abs(current_sum - target) == abs(closest_sum - target) && current_sum > closest_sum)) {
                    closest_sum = current_sum;
                }

                if (current_sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return closest_sum;
    }
};
```

### Code (Java)

```java
class Solution {
    public int threeSumClosest(int[] arr, int target) {
        Arrays.sort(arr);
        int closest_sum = Integer.MAX_VALUE;
        int n = arr.length;

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;

            while (left < right) {
                int current_sum = arr[i] + arr[left] + arr[right];

                if (current_sum == target) {
                    return current_sum;
                }

                if (Math.abs(current_sum - target) < Math.abs(closest_sum - target) ||
                   (Math.abs(current_sum - target) == Math.abs(closest_sum - target) && current_sum > closest_sum)) {
                    closest_sum = current_sum;
                }

                if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return closest_sum;
    }
}
```

### Code (Python)

```python
class Solution:
    def threeSumClosest(self, arr, target):
        arr.sort()
        closest_sum = float('inf')
        n = len(arr)

        for i in range(n - 2):
            left, right = i + 1, n - 1

            while left < right:
                current_sum = arr[i] + arr[left] + arr[right]

                if current_sum == target:
                    return current_sum

                if abs(current_sum - target) < abs(closest_sum - target) or (
                    abs(current_sum - target) == abs(closest_sum - target) and current_sum > closest_sum):
                    closest_sum = current_sum

                if current_sum < target:
                    left += 1
                else:
                    right -= 1

        return closest_sum
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/).
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
