# **27. Maximum Difference**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-difference-1587115620/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given an integer array `arr`, the task is to find the maximum absolute difference between the nearest left smaller element and the nearest right smaller element of every element in `arr`. If for any element of the array, the nearest smaller element doesn't exist, consider it as `0`.

**Example:**

Input:

```
arr = [2, 1, 8]
```

Output:

```
1
```

Explanation: The left smaller array `ls` is `[0, 0, 1]`, and the right smaller array `rs` is `[1, 0, 0]`. The maximum difference of `abs(ls[i] - rs[i])` is `1`.

Input:

```
arr = [2, 4, 8, 7, 7, 9, 3]
```

Output:

```
4
```

Explanation: The left smaller array `ls` is `[0, 2, 4, 4, 4, 7, 2]`, and the right smaller array `rs` is `[0, 3, 7, 3, 3, 3, 0]`. The maximum difference of `abs(ls[i] - rs[i])` is `abs(7 - 3) = 4`.

### My Approach

1. **Use of Stacks:**

   - Create two stacks to store the indices of elements for left and right smaller elements.

2. **Left Smaller Array Calculation:**

   - Traverse the array from left to right and fill the `ls` array by popping elements from the stack until the top of the stack is smaller than the current element.

3. **Right Smaller Array Calculation:**

   - Traverse the array from right to left and fill the `rs` array similarly by using a stack to track the nearest smaller elements on the right.

4. **Calculate Maximum Difference:**
   - Iterate through the arrays `ls` and `rs` to find the maximum absolute difference between corresponding elements.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the array and manipulate the stack with a constant number of operations per element.
- **Expected Auxiliary Space Complexity:** O(n), due to the additional arrays and stack used for storing intermediate results.

### Code (C++)

```cpp
class Solution {
public:
    int findMaxDiff(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        int maxDiff = 0;
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            l[i] = s.empty() ? 0 : arr[s.top()];
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            r[i] = s.empty() ? 0 : arr[s.top()];
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(l[i] - r[i]));
        }

        return maxDiff;
    }
};
```

### Code (Java)

```java
class Solution {
    public int findMaxDiff(int[] arr) {
        int n = arr.length;
        Stack<Integer> s = new Stack<>();
        int maxDiff = 0;
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                s.pop();
            }
            l[i] = s.isEmpty() ? 0 : arr[s.peek()];
            s.push(i);
        }
        s.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && arr[s.peek()] >= arr[i]) {
                s.pop();
            }
            r[i] = s.isEmpty() ? 0 : arr[s.peek()];
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            maxDiff = Math.max(maxDiff, Math.abs(l[i] - r[i]));
        }

        return maxDiff;
    }
}
```

### Code (Python)

```python
class Solution:
    def findMaxDiff(self, arr):
        n = len(arr)
        s = []
        maxDiff = 0
        l = [0] * n
        r = [0] * n
        for i in range(n):
            while s and arr[s[-1]] >= arr[i]:
                s.pop()
            l[i] = 0 if not s else arr[s[-1]]
            s.append(i)
        s.clear()
        for i in range(n - 1, -1, -1):
            while s and arr[s[-1]] >= arr[i]:
                s.pop()
            r[i] = 0 if not s else arr[s[-1]]
            s.append(i)
        for i in range(n):
            maxDiff = max(maxDiff, abs(l[i] - r[i]))

        return maxDiff
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
