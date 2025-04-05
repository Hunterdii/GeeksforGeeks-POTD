# **8. Minimum Jumps**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given an array `arr[]` of non-negative integers, where each element represents the maximum length of the jumps that can be made forward from that element, find the minimum number of jumps to reach the end of the array starting from the first element.

If an element is `0`, then you cannot move through that element.

Return `-1` if you can't reach the end of the array.

### Example:

Input:

```
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
```

Output:

```
3
```

Explanation:

- First jump from the 1st element to the 2nd element (value 3).
- Then jump to the 5th element (value 9).
- Finally, jump to the last element.

### My Approach

1. **Edge Cases:**

   - If the array has only one element, we are already at the end, so the minimum jumps required is `0`.
   - If the first element is `0` and the size of the array is more than `1`, we cannot move forward, so return `-1`.

2. **Initialize Variables:**

   - `maxReach` keeps track of the farthest point we can reach at any given step.
   - `steps` keeps track of the remaining steps we can take within the current jump.
   - `jumps` counts the number of jumps required to reach the end.

3. **Iterating Through the Array:**

   - Iterate through the array, and for each element, update `maxReach` to reflect the farthest index that can be reached.
   - Decrease `steps` after each move.
   - If `steps` becomes `0`, increase `jumps`, and if the current index is beyond `maxReach`, return `-1`.

4. **Final Answer:**
   - If we reach the end of the array, return the number of jumps made to get there.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the size of the array, because we traverse the array once.
- **Expected Auxiliary Space Complexity:** O(1), as we are using a constant amount of additional space for variables like `maxReach`, `steps`, and `jumps`.

### Code (C++)

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;

        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;

            maxReach = max(maxReach, i + arr[i]);
            steps--;

            if (steps == 0) {
                jumps++;
                if (i >= maxReach) return -1;

                steps = maxReach - i;
            }
        }

        return -1;
    }
};
```

### Code (Java)

```java
class Solution {
    static int minJumps(int[] arr) {
        int n = arr.length;
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;

        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;

        for (int i = 1; i < n; i++) {
            if (i == n - 1) return jumps;

            maxReach = Math.max(maxReach, i + arr[i]);
            steps--;

            if (steps == 0) {
                jumps++;
                if (i >= maxReach) return -1;

                steps = maxReach - i;
            }
        }

        return -1;
    }
}
```

### Code (Python)

```python
class Solution:
    def minJumps(self, arr):
        n = len(arr)
        if n <= 1:
            return 0
        if arr[0] == 0:
            return -1

        maxReach = arr[0]
        steps = arr[0]
        jumps = 1

        for i in range(1, n):
            if i == n - 1:
                return jumps

            maxReach = max(maxReach, i + arr[i])
            steps -= 1

            if steps == 0:
                jumps += 1
                if i >= maxReach:
                    return -1

                steps = maxReach - i

        return -1
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
