## 15. Count the Elements

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-the-elements1529/1)

### Problem Description

Given two arrays `a` and `b`, both of size `n`. Given `q` queries in an array `query` each having a positive integer `x` denoting an index of the array `a`. For each query, your task is to find all the elements less than or equal to `a[x]` in the array `b`.

**Example:**

Input:

```
n = 3
a[] = {4,1,2}
b[] = {1,7,3}
q = 2
query[] = {0,1}
```

Output:

```
2
1
```

Explanation:

- For the 1st query, the given index is 0, `a[0] = 4`. There are 2 elements (1 and 3) which are less than or equal to 4.
- For the 2nd query, the given index is 1, `a[1] = 1`. There exists only 1 element (1) which is less than or equal to 1.

### My Approach

1. **Sorting:** Sort the array `b` in non-decreasing order.
2. **Processing Queries:** For each query, find the count of elements in array `b` that are less than or equal to `a[x]`. This can be done using the `upper_bound` function in C++ to find the position of the first element greater than `a[x]`, and subtracting it from the beginning of the array `b`.
3. **Return:** Return the array containing the counts for all queries.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(nlogn), where n is the size of the array `b`. This is because we need to sort the array `b`.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        sort(b.begin(), b.end());
        vector<int> ans;
        ans.reserve(q); // Reserve memory for the result vector to avoid dynamic resizing

        for (int i = 0; i < q; ++i) {
            int count = upper_bound(b.begin(), b.end(), a[query[i]]) - b.begin();
            ans.push_back(count);
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
