## 17. Find Pair Given Difference

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-pair-given-difference1559/1)

### Problem Description

Given an array `arr[]` of size `n` and an integer `x`, return `1` if there exists a pair of elements in the array whose absolute difference is `x`, otherwise, return `-1`.

**Example:**

Input:

```
n = 6
x = 78
arr[] = {5, 20, 3, 2, 5, 80}
```

Output:

```
1
```

Explanation:
Pair (2, 80) has an absolute difference of 78.

### My Approach

1. **Initialization:**

- Initialize an unordered set `seen` to store the elements encountered while traversing the array.

2. **Pair Finding:**

- Iterate through the array.
- For each element `arr[i]`, check if `arr[i] - x` or `arr[i] + x` exists in the set `seen`. If yes, return `1` as a pair with the required absolute difference exists.
- If not found, insert the current element `arr[i]` into the set `seen`.

3. **Return:**

- If no such pair is found after traversing the array, return `-1`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* log(n)), as the insertion and lookup operations in an unordered set have an average time complexity of O(1), but the total time complexity would be dominated by the linear traversal of the array.
- **Expected Auxiliary Space Complexity:** O(n), as we use an unordered set to store the elements encountered while traversing the array.

### Code (C++)

```cpp
class Solution {
public:
    int findPair(int n, int x, vector<int> &arr) {
        unordered_set<int> seen;

        for (int i = 0; i < n; ++i) {

            if (seen.find(arr[i] - x) != seen.end() || seen.find(arr[i] + x) != seen.end()) {
                return 1;
            }
            seen.insert(arr[i]);
        }

        return -1;
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
