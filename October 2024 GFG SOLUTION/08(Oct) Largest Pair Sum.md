# _8. Largest Pair Sum_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/pair-sum--120604/1)

---

### Problem Description

Given an array of distinct integers, find the largest pair sum in the array.

- The array may contain positive numbers, negative numbers, or both.
- The array will have at least two elements.

**Examples**:

1. **Input:**

   - arr[] = [12, 34, 10, 6, 40]
   - **Output:** 74
   - **Explanation:** The largest pair sum is 34 + 40 = 74.

2. **Input:**
   - arr[] = [10, 20, 30]
   - **Output:** 50
   - **Explanation:** The largest pair sum is 20 + 30 = 50.

---

### My Approach

To find the largest pair sum, we follow these steps:

1. **Edge Case Handling:**

   - If the array has less than two elements, the sum cannot be computed, and we return an error value (e.g., -1).

2. **Tracking Largest Values:**
   - Traverse the array and keep track of the two largest distinct values. Let `first` and `second` store the largest and second-largest elements respectively.
3. **Final Pair Sum:**
   - The sum of `first` and `second` will give the largest pair sum.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of elements in the array. We traverse the array once to find the two largest elements.
- **Expected Auxiliary Space Complexity:** O(1), as we are using a constant amount of space to store the largest two values.

---

### Code (C++)

```cpp
class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) {

            return -1;
        }

        int first = INT_MIN, second = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (arr[i] > first) {
                second = first;
                first = arr[i];
            } else if (arr[i] > second) {
                second = arr[i];
            }
        }

        return first + second;
    }
};
```

---

### Code (Java)

```java
class Solution {
    public static int pairsum(int[] arr) {
        int n = arr.length;
        if (n < 2) {
            return -1;
        }

        int first = Integer.MIN_VALUE, second = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            if (arr[i] > first) {
                second = first;
                first = arr[i];
            } else if (arr[i] > second) {
                second = arr[i];
            }
        }

        return first + second;
    }
}
```

---

### Code (Python)

```python
from typing import List

class Solution:
    def pairsum(self, arr: List[int]) -> int:
        n = len(arr)
        if n < 2:
            return -1

        first, second = float('-inf'), float('-inf')

        for num in arr:
            if num > first:
                second = first
                first = num
            elif num > second:
                second = num

        return first + second
```

---

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
