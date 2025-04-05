## 09. Convert Array into Zig-Zag Fashion

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion1638/1)

### Problem Description

Given an array `arr` of distinct elements of size `n`, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the form:

```
arr[0] < arr[1] > arr[2] < arr[3] > arr[4] < ... < arr[n-2] > arr[n-1]
```

Note: Modify the given array `arr[]` only. If your transformation is correct, the output will be 1, else the output will be 0.

**Example:**

Input:

```
n = 7
arr = [4, 3, 7, 8, 6, 2, 1]
```

Output:

```
3 7 4 8 2 6 1
```

Explanation:
3 < 7 > 4 < 8 > 2 < 6 > 1

### My Approach

1. **Initialization:**

   - Iterate through the array using a loop from `0` to `n-2`.

2. **Condition Check and Swap:**

   - For each index `i`, check:
     - If `i` is even, ensure `arr[i] < arr[i + 1]`. If not, swap `arr[i]` and `arr[i + 1]`.
     - If `i` is odd, ensure `arr[i] > arr[i + 1]`. If not, swap `arr[i]` and `arr[i + 1]`.

3. **Return:**
   - The array `arr` is modified in place to satisfy the zig-zag pattern.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the array only once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code

#### C++

```cpp
class Solution {
public:
    void zigZag(int n, vector<int> &arr) {
        for (int i = 0; i < n - 1; ++i) {
            if ((i % 2 == 0 && arr[i] > arr[i + 1]) || (i % 2 == 1 && arr[i] < arr[i + 1])) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
};
```

#### Java

```java
class Solution {
    public static void zigZag(int n, int[] arr) {
        for (int i = 0; i < n - 1; ++i) {
            if ((i % 2 == 0 && arr[i] > arr[i + 1]) || (i % 2 == 1 && arr[i] < arr[i + 1])) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def zigZag(self, n: int, arr: List[int]) -> None:
        for i in range(n - 1):
            if (i % 2 == 0 and arr[i] > arr[i + 1]) or (i % 2 == 1 and arr[i] < arr[i + 1]):
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
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
