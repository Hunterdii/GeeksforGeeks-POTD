## 20. Union of Two Sorted Arrays

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1)

### Problem Description

Given two sorted arrays of size \( n \) and \( m \) respectively, find their union. The Union of two arrays can be defined as the common and distinct elements in the two arrays.

**Example:**

Input:

```
n = 5, arr1[] = {1, 2, 3, 4, 5}
m = 5, arr2 [] = {1, 2, 3, 6, 7}
```

Output:

```
1 2 3 4 5 6 7
```

Explanation:
Distinct elements including both arrays are: 1 2 3 4 5 6 7.

### My Approach

1. **Initialization:**

- Create a vector `ans` to store the union of the two arrays.
- Sort both input arrays `arr1` and `arr2`.

2. **Union Calculation:**

- Initialize two pointers `i` and `j` to traverse `arr1` and `arr2` respectively.
- Compare elements at `arr1[i]` and `arr2[j]`.
  - If `arr1[i]` is less than `arr2[j]`, push `arr1[i]` to the `ans` vector and increment `i`.
  - If `arr1[i]` is greater than `arr2[j]`, push `arr2[j]` to the `ans` vector and increment `j`.
  - If both are equal, push either to the `ans` vector and increment both `i` and `j`.
- Continue this process until both arrays are completely traversed.

3. **Remove Duplicates:**

- After merging, there may be duplicate elements in the `ans` vector. Remove duplicates using the `unique` function.

4. **Return:**

- Return the `ans` vector containing the union of the two arrays.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + m), where \( n \) and \( m \) are the sizes of the two input arrays, as we traverse both arrays once.
- **Expected Auxiliary Space Complexity:** O(n + m), as we use a vector to store the union of the two arrays.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> ans;
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            } else if (arr1[i] > arr2[j]) {
                ans.push_back(arr2[j]);
                j++;
            } else {
                ans.push_back(arr1[i]);
                i++;
                j++;
            }
        }

        while (i < n) {
            ans.push_back(arr1[i]);
            i++;
        }

        while (j < m) {
            ans.push_back(arr2[j]);
            j++;
        }

        // Remove duplicates
        auto it = unique(ans.begin(), ans.end());
        ans.resize(distance(ans.begin(), it));

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
