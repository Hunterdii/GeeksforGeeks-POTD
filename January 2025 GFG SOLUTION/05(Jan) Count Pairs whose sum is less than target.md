# _05. Count Pairs Whose Sum is Less Than Target_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-less-than-target/1)

## Problem Description

You are given an array `arr[]` of integers and a target integer. Your task is to find the number of pairs in the array whose sum is strictly less than the given target.

## Examples:

**Input:**  
`arr[] = [7, 2, 5, 3]`, `target = 8`  
**Output:**  
`2`  
**Explanation:**  
There are 2 pairs with sum less than 8: `(2, 5)` and `(2, 3)`.

**Input:**  
`arr[] = [5, 2, 3, 2, 4, 1]`, `target = 5`  
**Output:**  
`4`  
**Explanation:**  
There are 4 pairs whose sum is less than 5: `(2, 2)`, `(2, 1)`, `(3, 1)`, and `(2, 1)`.

**Input:**  
`arr[] = [2, 1, 8, 3, 4, 7, 6, 5]`, `target = 7`  
**Output:**  
`6`  
**Explanation:**  
There are 6 pairs whose sum is less than 7: `(2, 1)`, `(2, 3)`, `(2, 4)`, `(1, 3)`, `(1, 4)`, and `(1, 5)`.

### Constraints:

- $`1 <= arr.size() <= 10^5`$
- $`0 <= arr[i] <= 10^4`$
- $`1 <= target <= 10^4`$

## My Approach

1. **Sorting and Two Pointers Technique**:  
   We can efficiently solve this problem using a two-pointer approach. By sorting the array first, we can use two pointers: one at the start of the array (`l`) and one at the end (`r`). We then check if the sum of the elements at these pointers is less than the target.

   - If the sum of `arr[l]` and `arr[r]` is less than the target, all pairs formed by `arr[l]` with any element between `l` and `r` will also be valid. Hence, we can add `(r - l)` to our result and move the left pointer (`l`) to the right.
   - If the sum is greater than or equal to the target, we move the right pointer (`r`) to the left.

2. **Steps:**
   - Sort the array.
   - Use two pointers: `l = 0` and `r = arr.size() - 1`.
   - Traverse the array while `l < r` and check if `arr[l] + arr[r] < target`.
   - Adjust the pointers accordingly and count the pairs.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), where `n` is the number of elements in the array. This comes from the sorting step, and the two-pointer traversal takes O(n) time.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of extra space (for the two pointers and the result variable).

## Code (C++)

```cpp
class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() - 1, ans = 0;
        while (l < r) (arr[l] + arr[r] < target) ? ans += (r - l), l++ : r--;
        return ans;
    }
};
```

## Code (Java)

```java
class Solution {
    int countPairs(int[] arr, int target) {
        Arrays.sort(arr);
        int l = 0, r = arr.length - 1, ans = 0;
        while (l < r) if (arr[l] + arr[r] < target) ans += (r - l++);
        else r--;
        return ans;
    }
}
```

## Code (Python)

```python
class Solution:
    def countPairs(self, arr, target):
        arr.sort()
        l, r, ans = 0, len(arr) - 1, 0
        while l < r:
            if arr[l] + arr[r] < target: ans += (r - l); l += 1
            else: r -= 1
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
