## 12. Median of Two Sorted Arrays

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1)

### Problem Description

Given two sorted integer arrays `arr1` and `arr2`, find the sum of the middle elements of the two sorted arrays. Since the arrays are sorted, the sum will be the sum of the median elements.

**Example:**

Input:

```
arr1 = [1, 2, 4, 6, 10]
arr2 = [4, 5, 6, 9, 12]
```

Output:

```
11
```

Explanation:
The merged array looks like `[1, 2, 4, 4, 5, 6, 6, 9, 10, 12]`. The sum of the middle elements is `11` (5 + 6).

### My Approach

1. **Binary Search Method:**

   - The problem can be approached using binary search to find the correct partition in the two arrays such that the left half and right half of the merged array are balanced.
   - Initialize two pointers `low` and `high` to perform the binary search on `arr1`.
   - For each middle point in `arr1`, find the corresponding partition in `arr2` such that the elements on the left side of the partition are less than or equal to the elements on the right side.
   - Calculate the median elements by finding the maximum of the left-side elements and the minimum of the right-side elements.
   - Return the sum of these two median elements.

2. **Edge Cases:**
   - If the number of elements in `arr1` or `arr2` is zero, handle that scenario accordingly.
   - Ensure that the binary search handles cases where all elements of one array are larger or smaller than the other.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(log n), as we perform a binary search on one of the arrays to find the median elements.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int SumofMiddleElements(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int low = 0, high = n;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = n - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : arr2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2) + min(r1, r2);
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return 0;
    }
};
```

### Code (Java) - **Note: Not Working Code is Running in Normal Compiler**

## <i>⚠️ Issue with the Provided Code Some Problem From GFG Side. </i>

```java
class Solution {
    public int SumofMiddleElements(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int low = 0, high = n;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = n - cut1;

            int l1 = (cut1 == 0) ? Integer.MIN_VALUE : arr1[cut1 - 1];
            int l2 = (cut2 == 0) ? Integer.MIN_VALUE : arr2[cut2 - 1];
            int r1 = (cut1 == n) ? Integer.MAX_VALUE : arr1[cut1];
            int r2 = (cut2 == n) ? Integer.MAX_VALUE : arr2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                return Math.max(l1, l2) + Math.min(r1, r2);
            } else if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return 0;
    }
}
```

### Code (Python)

```python
class Solution:
    def sum_of_middle_elements(self, arr1, arr2):
        n = len(arr1)
        low, high = 0, n

        while low <= high:
            cut1 = low + (high - low) // 2
            cut2 = n - cut1

            l1 = float('-inf') if cut1 == 0 else arr1[cut1 - 1]
            l2 = float('-inf') if cut2 == 0 else arr2[cut2 - 1]
            r1 = float('inf') if cut1 == n else arr1[cut1]
            r2 = float('inf') if cut2 == n else arr2[cut2]

            if l1 <= r2 and l2 <= r1:
                return max(l1, l2) + min(r1, r2)
            elif l1 > r2:
                high = cut1 - 1
            else:
                low = cut1 + 1

        return 0
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
