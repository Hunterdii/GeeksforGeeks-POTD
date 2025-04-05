# **31. Sorted Subsequence of Size 3**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

You are given an array `arr`, and you need to find any three elements in it such that `arr[i] < arr[j] < arr[k]` and `i < j < k`.

- If such a subsequence is found, return `1`.
- If no such subsequence exists, return an empty array.
- If the subsequence is not in the required format, the output will be `-1`.

**Example:**

Input:

```
arr = [1, 2, 1, 1, 3]
```

Output:

```
1
```

Explanation: A subsequence `1 2 3` exists.

### My Approach

1. **Initialization:**

   - We maintain two auxiliary arrays `smaller` and `greater` to store indices of elements that are smaller and greater than the current element, respectively.

2. **Traverse Array to Fill Smaller Array:**

   - Start from the left of the array and update `smaller[i]` with the index of the smallest element seen so far to the left of the current element.

3. **Traverse Array to Fill Greater Array:**

   - Start from the right of the array and update `greater[i]` with the index of the largest element seen so far to the right of the current element.

4. **Find the Required Subsequence:**

   - Scan through the array to find an element such that both `smaller[i]` and `greater[i]` are not `-1`. Return the elements at these indices as the result.

5. **Edge Cases:**
   - If the array has fewer than three elements, immediately return an empty array.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the array a constant number of times, where `n` is the length of the array.
- **Expected Auxiliary Space Complexity:** O(n), due to the additional space required for the `smaller` and `greater` arrays.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> find3Numbers(vector<int> arr) {
        int n = arr.size();
        if (n < 3) return {};

        vector<int> smaller(n, -1);
        vector<int> greater(n, -1);

        int min = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] <= arr[min]) {
                min = i;
            } else {
                smaller[i] = min;
            }
        }

        int max = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] >= arr[max]) {
                max = i;
            } else {
                greater[i] = max;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (smaller[i] != -1 && greater[i] != -1) {
                return {arr[smaller[i]], arr[i], arr[greater[i]]};
            }
        }

        return {};
    }
};
```

### Code (Java)

```java
class Solution {
    public List<Integer> find3Numbers(int[] arr) {
        int n = arr.length;
        if (n < 3) return new ArrayList<>();

        int[] smaller = new int[n];
        int[] greater = new int[n];
        Arrays.fill(smaller, -1);
        Arrays.fill(greater, -1);

        int min = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] <= arr[min]) {
                min = i;
            } else {
                smaller[i] = min;
            }
        }

        int max = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (arr[i] >= arr[max]) {
                max = i;
            } else {
                greater[i] = max;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (smaller[i] != -1 && greater[i] != -1) {
                return Arrays.asList(arr[smaller[i]], arr[i], arr[greater[i]]);
            }
        }

        return new ArrayList<>();
    }
}
```

### Code (Python)

```python
class Solution:
    def find3Numbers(self, arr):
        n = len(arr)
        if n < 3:
            return []

        smaller = [-1] * n
        greater = [-1] * n

        min_index = 0
        for i in range(1, n):
            if arr[i] <= arr[min_index]:
                min_index = i
            else:
                smaller[i] = min_index

        max_index = n - 1
        for i in range(n - 2, -1, -1):
            if arr[i] >= arr[max_index]:
                max_index = i
            else:
                greater[i] = max_index

        for i in range(n):
            if smaller[i] != -1 and greater[i] != -1:
                return [arr[smaller[i]], arr[i], arr[greater[i]]]

        return []
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
