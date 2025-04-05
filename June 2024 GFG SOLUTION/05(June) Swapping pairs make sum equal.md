## 05. Swapping Pairs to Make Sum Equal

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/swapping-pairs-make-sum-equal4142/1)

### Problem Description

Given two arrays of integers `a[]` and `b[]` of size `n` and `m`, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of the two arrays equal.

**Example:**

Input:

```
n = 6, m = 4
a[] = {4, 1, 2, 1, 1, 2}
b[] = {3, 6, 3, 3}
```

Output:

```
1
```

Explanation:
Sum of elements in `a[]` = 11, Sum of elements in `b[]` = 15. To get the same sum from both arrays, we can swap the following values: 1 from `a[]` and 3 from `b[]`.

### My Approach

1. **Calculate Sums:**

   - Compute the sum of elements in arrays `a[]` and `b[]`, denoted as `sumA` and `sumB`.

2. **Check for Even Difference:**

   - If the difference `(sumA - sumB)` is odd, return -1, as we cannot balance the sums by swapping integer values.

3. **Calculate Target Difference:**

   - The target difference for a successful swap is `(sumA - sumB) / 2`.

4. **Use a Set for Efficient Lookup:**

   - Store all elements of array `b[]` in a set for O(1) average-time complexity lookups.

5. **Find Swap Pair:**

   - Iterate through each element in array `a[]`. For each element, check if `element - target` exists in the set of `b[]`. If found, return 1 indicating a successful swap exists.

6. **Return Result:**
   - If no such pair is found after checking all elements, return -1.

### Time and Auxiliary Space Complexity

**Expected Time Complexity:** O(mlogm+nlogn), where \(n\) is the size of array `a[]` and \(m\) is the size of array `b[]`. This includes the time to compute sums, populate the set, and check for potential swaps.

**Expected Auxiliary Space Complexity:** O(1), as we store all elements of array `b[]` in a set for quick lookups.

### Code (C++)

```cpp
class Solution {
public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sumA = accumulate(a, a + n, 0);
        int sumB = accumulate(b, b + m, 0);

        if ((sumA - sumB) % 2 != 0) {
            return -1;
        }

        int target = (sumA - sumB) / 2;
        unordered_set<int> setB(b, b + m);

        for (int i = 0; i < n; ++i) {
            if (setB.find(a[i] - target) != setB.end()) {
                return 1;
            }
        }

        return -1;
    }
};
```

### Code (Java)

```java
class Solution {
    long findSwapValues(long[] a, int n, long[] b, int m) {
        long sumA = 0;
        for (long num : a) sumA += num;
        long sumB = 0;
        for (long num : b) sumB += num;

        if ((sumA - sumB) % 2 != 0) return -1;

        long target = (sumA - sumB) / 2;
        Set<Long> setB = new HashSet<>();
        for (long num : b) setB.add(num);

        for (long num : a) {
            if (setB.contains(num - target)) {
                return 1;
            }
        }

        return -1;
    }
}
```

### Code (Python)

```python
class Solution:
    def findSwapValues(self, a, n, b, m):
        sumA = sum(a)
        sumB = sum(b)

        if (sumA - sumB) % 2 != 0:
            return -1

        target = (sumA - sumB) // 2
        setB = set(b)

        for num in a:
            if (num - target) in setB:
                return 1

        return -1
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
