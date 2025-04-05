## 18. Find the Highest Number

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-the-highest-number2259/1)

### Problem Description

Given an integer array `a[]` of size `n`, find the highest element of the array. The array will either be strictly increasing or strictly increasing and then strictly decreasing.

Note: `a[i]` != `a[i+1]`

**Example:**

Input:

```
11
1 2 3 4 5 6 5 4 3 2 1
```

Output:

```
6
```

Explanation:
Highest element of array `a[]` is 6.

### My Approach

1. **Initialization:**

- Use the standard library function `max_element` to find the maximum value in the array.

2. **Peak Element Search:**

- The function `max_element` scans through the array to identify the largest element.

3. **Return:**

- Return the value found by `max_element`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log(n)), as the `max_element` function iterates through the array exactly once to find the maximum element.
- **Expected Auxiliary Space Complexity:** O(1), as no additional space is required beyond the input array.

### Code (C++)

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& a)
    {
        return *max_element(a.begin(), a.end());
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
