## 07. K-th element of two Arrays

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1)

### Problem Description

Given two sorted arrays `arr1` and `arr2` and an integer `k`, find the element that would be at the `k`-th position in the combined sorted array of the two arrays.

**Example:**

Input:

```
k = 5
arr1 = [2, 3, 6, 7, 9]
arr2 = [1, 4, 8, 10]
```

Output:

```
6
```

Explanation:
The final combined sorted array is [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

### My Approach

1. **Initialization:**

- Define a helper function `kth` to find the k-th element in two sorted subarrays.
- The helper function takes arrays `arr1` and `arr2`, start and end indices of the subarrays, and the value `k`.

2. **Base Cases:**

- If the starting index of `arr1` exceeds its ending index, return the k-th element from `arr2`.
- If the starting index of `arr2` exceeds its ending index, return the k-th element from `arr1`.

3. **Recursive Case:**

- Calculate the midpoints of the subarrays.
- Compare the sum of the midpoints with `k`.
- Depending on the comparison:
  - Adjust the subarray bounds and `k` for the recursive call.

4. **Return:**

- Call the helper function `kth` with the initial bounds and `k-1`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log(n) + log(m)), as the search space is halved in each recursive call.
- **Expected Auxiliary Space Complexity:** O(log(n) + log(m)), due to the recursive stack space used for each subarray division.

### Code (C++)

```cpp
class Solution {
public:
    int kth(vector<int>& arr1, vector<int>& arr2, int s1, int e1, int s2, int e2, int k) {
        if (s1 >= e1) return arr2[s2 + k];
        if (s2 >= e2) return arr1[s1 + k];
        int mid1 = (e1 - s1) / 2;
        int mid2 = (e2 - s2) / 2;
        if (mid1 + mid2 < k) {
            if (arr1[s1 + mid1] > arr2[s2 + mid2]) {
                return kth(arr1, arr2, s1, e1, s2 + mid2 + 1, e2, k - mid2 - 1);
            } else {
                return kth(arr1, arr2, s1 + mid1 + 1, e1, s2, e2, k - mid1 - 1);
            }
        } else {
            if (arr1[s1 + mid1] > arr2[s2 + mid2]) {
                return kth(arr1, arr2, s1, s1 + mid1, s2, e2, k);
            } else {
                return kth(arr1, arr2, s1, e1, s2, s2 + mid2, k);
            }
        }
    }

    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        return kth(arr1, arr2, 0, n, 0, m, k - 1);
    }
};
```

### Code (Java)

```java
class Solution {
    public long kthElement(int k, int[] arr1, int[] arr2) {
        return kth(arr1, arr2, 0, arr1.length, 0, arr2.length, k - 1);
    }

    private long kth(int[] arr1, int[] arr2, int s1, int e1, int s2, int e2, int k) {
        if (s1 >= e1) return arr2[s2 + k];
        if (s2 >= e2) return arr1[s1 + k];

        int mid1 = (e1 - s1) / 2;
        int mid2 = (e2 - s2) / 2;

        if (mid1 + mid2 < k) {
            if (arr1[s1 + mid1] > arr2[s2 + mid2]) {
                return kth(arr1, arr2, s1, e1, s2 + mid2 + 1, e2, k - mid2 - 1);
            } else {
                return kth(arr1, arr2, s1 + mid1 + 1, e1, s2, e2, k - mid1 - 1);
            }
        } else {
            if (arr1[s1 + mid1] > arr2[s2 + mid2]) {
                return kth(arr1, arr2, s1, s1 + mid1, s2, e2, k);
            } else {
                return kth(arr1, arr2, s1, e1, s2, s2 + mid2, k);
            }
        }
    }
}
```

### Code (Python)

```python
class Solution:
    def kthElement(self, k, arr1, arr2):
        return self.kth(arr1, arr2, 0, len(arr1), 0, len(arr2), k - 1)

    def kth(self, arr1, arr2, s1, e1, s2, e2, k):
        if s1 >= e1:
            return arr2[s2 + k]
        if s2 >= e2:
            return arr1[s1 + k]

        mid1 = (e1 - s1) // 2
        mid2 = (e2 - s2) // 2

        if mid1 + mid2 < k:
            if arr1[s1 + mid1] > arr2[s2 + mid2]:
                return self.kth(arr1, arr2, s1, e1, s2 + mid2 + 1, e2, k - mid2 - 1)
            else:
                return self.kth(arr1, arr2, s1 + mid1 + 1, e1, s2, e2, k - mid1 - 1)
        else:
            if arr1[s1 + mid1] > arr2[s2 + mid2]:
                return self.kth(arr1, arr2, s1, s1 + mid1, s2, e2, k)
            else:
                return self.kth(arr1, arr2, s1, e1, s2, s2 + mid2, k)
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
