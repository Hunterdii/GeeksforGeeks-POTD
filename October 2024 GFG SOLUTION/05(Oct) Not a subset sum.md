# _05. Not a subset sum_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/smallest-number-subset1220/1)

### Problem Description

Given a sorted array `arr[]` of positive integers, find the smallest positive integer that **cannot** be represented as the sum of elements of any subset of the given array.

_Example 1:_

Input:

```
arr = [1, 2, 3]
```

Output:

```
7
```

Explanation: 7 is the smallest positive number for which no subset exists with sum 7.

_Example 2:_

Input:

```
arr = [3, 6, 9, 10, 20, 28]
```

Output:

```
1
```

Explanation: 1 is the smallest positive number for which no subset exists with sum 1.

### Constraints

- \(1 \leq \text{arr.size()} \leq 10^6\)
- \(0 \leq \text{arr[i]} \leq 10^8\)

### My Approach

1. **Greedy Algorithm Approach:**
   - The problem can be solved using a greedy approach by iterating over the sorted array.
   - Start with `res = 1`, which is the smallest possible answer. Iterate through the array:
     - For every element `arr[i]` in the array, if `arr[i]` is greater than `res`, we found a gap, and `res` cannot be represented as the sum of any subset.
     - Otherwise, add `arr[i]` to `res` to increment the range of sums that can be represented.
2. **Example Walkthrough:**
   - Suppose `arr = [1, 2, 3]`:
     - Initially, `res = 1`. We can represent 1 because `arr[0] = 1`. Now, update `res = 1 + 1 = 2`.
     - Next, we check `arr[1] = 2`. We can represent sums up to `res = 2`. Add `arr[1]`, and now `res = 2 + 2 = 4`.
     - Similarly, `arr[2] = 3` lets us update `res = 4 + 3 = 7`. Therefore, the smallest positive integer not representable as a sum of subsets is `7`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the size of the input array. We iterate through the array only once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space, regardless of the input size.

### Code (C++)

```cpp
class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        int n = arr.size();
        long long res = 1;
        for (int i = 0; i < n && arr[i] <= res; i++) {
            res += arr[i];
        }
        return res;
    }
};
```

### Code (Java)

```java
class Solution {
    public long findSmallest(int[] arr) {
        long res = 1;
        for (int i = 0; i < arr.length && arr[i] <= res; i++) {
            res += arr[i];
        }
        return res;
    }
}
```

### Code (Python)

```python
class Solution:
    def findSmallest(self, arr):
        res = 1
        for i in range(len(arr)):
            if arr[i] <= res:
                res += arr[i]
            else:
                break
        return res
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
