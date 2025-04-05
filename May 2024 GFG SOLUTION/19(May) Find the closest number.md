## 19. Find the Closest Number

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-closest-number5513/1)

### Problem Description

Given a sorted array `arr[]` of positive integers and a target number `k`, find the closest value in the array to the given number `k`. If the difference with `k` is the same for two values in the array, return the greater value.

**Example:**

Input:

```
n = 4
k = 4
arr[] = {1, 3, 6, 7}
```

Output:

```
3
```

Explanation:
The closest number to 4 in the array {1, 3, 6, 7} is 3.

### Approach

1. **Binary Search:**

   - Initialize two pointers, `left` and `right`, at the beginning and end of the array respectively.
   - Perform binary search to find the closest number to `k`.
   - While `left` is less than `right`, calculate the middle index `mid`.
   - If `arr[mid]` is less than `k`, update `left = mid + 1`, else update `right = mid`.
   - After the loop, check if the previous element of the found closest number has a smaller absolute difference with `k`. If so, return it; otherwise, return the found closest number.

2. **Return Closest Number:**

   - After finding the index of the closest number, check if the absolute difference of the previous element and `k` is smaller.
   - If it is smaller, return the previous element; otherwise, return the closest number found.

3. **Time Complexity:**

   - The binary search approach has a time complexity of O(log n) as it reduces the search space by half in each iteration.

4. **Space Complexity:**
   - The space complexity is O(1) as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int findClosest(int n, int k, int arr[]) {
        int left = 0, right = n - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        if (left > 0 && abs(arr[left - 1] - k) < abs(arr[left] - k)) {
            return arr[left - 1];
        } else {
            return arr[left];
        }
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
