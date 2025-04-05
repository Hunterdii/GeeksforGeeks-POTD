# _15. Second Largest_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/second-largest3735/1)

> **Note:** I'm currently in the middle of my exams until November 19, so I’ll be uploading daily POTD solutions, but not at a fixed time. Apologies for any inconvenience, and thank you for your patience!

## Problem Description

Given an array of positive integers `arr[]`, return the second largest element from the array. If the second largest element doesn't exist, return `-1`.

**Note:** The second largest element should not be equal to the largest element.

### Examples:

**Input:**

```
arr[] = [12, 35, 1, 10, 34, 1]
```

**Output:**

```
34
```

**Explanation:**  
The largest element of the array is 35, and the second largest element is 34.

**Input:**

```
arr[] = [10, 5, 10]
```

**Output:**

```
5
```

**Explanation:**  
The largest element of the array is 10, and the second largest element is 5.

**Input:**

```
arr[] = [10, 10, 10]
```

**Output:**

```
-1
```

**Explanation:**  
The largest element of the array is 10, and there is no distinct second largest element.

### Constraints:

- $\(2 \leq \text{arr.size()} \leq 10^5\)$
- $\(1 \leq \text{arr[i]} \leq 10^5\)$

## My Approach

1. **Tracking Largest and Second Largest:**

   - Initialize two variables, `first` and `second`, to the smallest possible values.
   - Traverse through the array:
     - If the current element is greater than `first`, update `second` to `first`, and then set `first` to the current element.
     - If the current element is less than `first` but greater than `second`, update `second`.
   - If no valid second largest element is found, return `-1`.

2. **Edge Cases:**
   - If all elements are the same, return `-1`.
   - If the array has only two distinct elements, return the smaller of the two if it’s not equal to the largest.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of elements in the array. The algorithm makes a single pass through the array to determine the largest and second largest elements.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to store `first` and `second`.

## Code (C++)

```cpp
class Solution {
public:
    int getSecondLargest(const std::vector<int>& arr) {
        int first = INT_MIN, second = INT_MIN;

        for (int num : arr) {
            if (num > first) {
                second = first;
                first = num;
            } else if (num > second && num < first) {
                second = num;
            }
        }

        return second == INT_MIN ? -1 : second;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

### Alternative Approach (Using Sorting)

```cpp
class Solution {
public:
    int getSecondLargest(std::vector<int>& arr) {
        std::sort(arr.rbegin(), arr.rend());
        int first = arr[0];
        for (int num : arr) {
            if (num < first) return num;
        }
        return -1;
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    public int getSecondLargest(int[] arr) {
        int first = Integer.MIN_VALUE;
        int second = Integer.MIN_VALUE;

        for (int num : arr) {
            if (num > first) {
                second = first;
                first = num;
            } else if (num > second && num < first) {
                second = num;
            }
        }

        return second == Integer.MIN_VALUE ? -1 : second;
    }
}
```

## Code (Python)

```python
class Solution:
    def getSecondLargest(self, arr):
        first = float('-inf')
        second = float('-inf')

        for num in arr:
            if num > first:
                second = first
                first = num
            elif num > second and num < first:
                second = num

        return -1 if second == float('-inf') else second
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
