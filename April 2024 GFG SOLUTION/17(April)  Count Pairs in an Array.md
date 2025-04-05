## 17. Count Pairs in an Array

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1)

### Problem Description

Given an array `arr` of `n` integers, count all pairs `(arr[i], arr[j])` in it such that `i*arr[i] > j*arr[j]` and `0 ≤ i < j < n`. Note: 0-based Indexing is followed.

**Example:**

Input:

```
n = 4
arr[] = {8, 4, 2, 1}
```

Output:

```
2
```

Explanation:
If we see the array after operations `[0*8, 1*4, 2*2, 3*1] => [0, 4, 4, 3]`, pairs which hold the condition `i*arr[i] > j*arr[j]` are (4,1) and (2,1), so in total 2 pairs are available.

### My Approach

1. **Pairs Calculation:**

   - Iterate through the array `arr` and calculate `i*arr[i]` for each element `arr[i]`.
   - Store the calculated values in a vector `v`.

2. **Sorting:**

   - Create a copy vector `temp` of vector `v`.
   - Sort the vector `temp` in non-decreasing order.

3. **Counting Pairs:**

   - Iterate over the elements of the original array `arr` in reverse order.
   - For each element `v[i]`, find the count of elements greater than `v[i]` in the sorted vector `temp` using binary search.
   - Subtract this count from the total size of `temp` and add it to the answer.
   - Remove the element `v[i]` from the sorted vector `temp`.

4. **Return:**
   - Return the final count as the answer.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n\*log(n)), as it involves sorting the vector and binary search operations.
- **Expected Auxiliary Space Complexity:** O(n), as we use additional space to store the calculated values in vectors.

### Code (C++)

```cpp
class Solution {
public:
    int countPairs(int arr[], int n) {
        std::vector<int> v;
        for (int i = 0; i < n; i++) {
            v.push_back(i * arr[i]);
        }

        std::vector<int> temp = v;
        std::sort(temp.begin(), temp.end());

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int x = std::upper_bound(temp.begin(), temp.end(), v[i]) - temp.begin();
            int y = std::lower_bound(temp.begin(), temp.end(), v[i]) - temp.begin();

            ans = ans + (temp.size() - x);

            temp.erase(temp.begin() + y);
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
