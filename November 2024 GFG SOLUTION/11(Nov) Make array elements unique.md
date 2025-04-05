# _11. Make Array Elements Unique_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/make-array-elements-unique--170645/1)

## Problem Description

Given an array `arr[]`, the goal is to make all elements unique with the minimum number of increment operations. In each operation, any element in the array can be incremented by 1.

### Examples:

**Input:**

```
arr[] = [1, 2, 2]
```

**Output:**

```
1
```

**Explanation:**  
Increasing `arr[2]` by 1 results in `[1, 2, 3]`, which makes all elements unique. The minimum number of operations required is 1.

**Input:**

```
arr[] = [1, 1, 2, 3]
```

**Output:**

```
3
```

**Explanation:**  
To make all elements unique, increase `arr[0]` by 3. Thus, the resulting array `[4, 1, 2, 3]` has all unique values. Hence, the answer is 3.

**Input:**

```
arr[] = [5, 4, 3, 2, 1]
```

**Output:**

```
0
```

**Explanation:**  
All elements are already unique, so no operations are needed.

### Constraints:

- `1 ≤ arr.size() ≤ 10^6`
- `0 ≤ arr[i] ≤ 10^6`

## My Approach

1. **Sorting and Increment Calculation**

   - First, sort the array to group identical elements together and handle them in order.
   - Traverse the sorted array from the second element onwards. If an element is not greater than the previous one, increment it to be `previous + 1` to maintain uniqueness.

2. **Increment Count**
   - For every adjustment made, keep a running count of the increments needed.
3. **Edge Cases**
   - If the array already has unique elements, no operations are needed.
   - If the array has all elements the same, each must be incremented to achieve uniqueness.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), due to sorting the array initially.
- **Expected Auxiliary Space Complexity:** O(1), as we perform the operations in place and use only a constant amount of additional space for the counters.

## Code (C++)

```cpp
class Solution {
public:
    int minIncrements(vector<int>& arr) {
        if (arr.empty()) return 0;

        int ans = 0;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] <= arr[i - 1]) {
                ans += arr[i - 1] - arr[i] + 1;
                arr[i] = arr[i - 1] + 1;
            }
        }
        return ans;
    }
};
```

## Code (Java)

```java
class Solution {
    public int minIncrements(int[] arr) {
        if (arr.length == 0) return 0;

        int ans = 0;
        Arrays.sort(arr);
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] <= arr[i - 1]) {
                ans += arr[i - 1] - arr[i] + 1;
                arr[i] = arr[i - 1] + 1;
            }
        }
        return ans;
    }
}
```

## Code (Python)

```python
class Solution:
    def minIncrements(self, arr):
        if not arr:
            return 0

        arr.sort()
        ans = 0

        for i in range(1, len(arr)):
            if arr[i] <= arr[i - 1]:
                ans += arr[i - 1] - arr[i] + 1
                arr[i] = arr[i - 1] + 1

        return ans
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
