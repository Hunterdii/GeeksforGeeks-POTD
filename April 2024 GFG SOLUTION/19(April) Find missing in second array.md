## 19. Find Missing in Second Array

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/in-first-but-second5423/1)

### Problem Description

Given two arrays `a` of size `n` and `b` of size `m`, the task is to find numbers which are present in the first array but not present in the second array.

**Example:**

Input:

```
n = 6, m = 5
a[] = {1, 2, 3, 4, 5, 10}
b[] = {2, 3, 1, 0, 5}
```

Output:

```
4 10
```

Explanation:
4 and 10 are present in the first array but not in the second array.

### My Approach

1. **Initialization:**

- Create an unordered set `s` from the elements of array `b`.

2. **Finding Missing Elements:**

- Iterate through array `a`.
- For each element `a[i]`, check if it exists in set `s`. If not, add it to the `ans` vector.

3. **Return:**

- Return the `ans` vector containing the missing elements.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + m), where `n` and `m` are the sizes of arrays `a` and `b` respectively. This complexity arises from iterating through both arrays once.
- **Expected Auxiliary Space Complexity:** O(m), where `m` is the size of array `b`, due to storing its elements in the unordered set.

### Code (C++)

```cpp
class Solution {
public:
    std::vector<int> findMissing(int a[], int b[], int n, int m) {
        std::unordered_set<int> s(b, b + m);
        std::vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (s.find(a[i]) == s.end()) {
                ans.push_back(a[i]);
            }
        }

        return ans;
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
