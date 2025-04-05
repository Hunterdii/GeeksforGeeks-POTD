## 11. Maximum Tip Calculator

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-tip-calculator2631/1)

### Problem Description

In a restaurant, two waiters, A and B, receive `n` orders per day, earning tips as per arrays `arr[i]` and `brr[i]` respectively. If A takes the ith order, the tip is `arr[i]` rupees; if B takes it, the tip is `brr[i]` rupees.

To maximize total tips, they must distribute the orders such that:

- A can handle at most `x` orders
- B can handle at most `y` orders

Given that `x + y ≥ n`, all orders can be managed by either A or B. Return the maximum possible total tip after processing all the orders.

**Examples:**

Input:

```
n = 5, x = 3, y = 3
arr = {1, 2, 3, 4, 5}
brr = {5, 4, 3, 2, 1}
```

Output:

```
21
```

Explanation:
Person A will serve the 3rd, 4th, and 5th orders while person B will serve the rest. So, the total tip from A = 3 + 4 + 5 and from B = 5 + 4, which equals 21.

Input:

```
n = 8, x = 4, y = 4
arr = {1, 4, 3, 2, 7, 5, 9, 6}
brr = {1, 2, 3, 6, 5, 4, 9, 8}
```

Output:

```
43
```

Explanation:
Person A will serve the 1st, 2nd, 5th, and 6th orders while Person B will serve the rest, making the total tip 43.

Input:

```
n = 7, x = 3, y = 4
arr = {8, 7, 15, 19, 16, 16, 18}
brr = {1, 7, 15, 11, 12, 31, 9}
```

Output:

```
110
```

Explanation:
Person A will serve orders 8, 19, and 18, while person B will serve 7, 15, 12, and 31.

### Approach

1. **Initialization:**

   - Create a vector `diff` to store the absolute differences between `arr[i]` and `brr[i]` along with the index `i`.
   - Initialize a variable `ans` to store the maximum possible total tip.

2. **Sorting:**

   - Sort the vector `diff` in descending order based on the differences.

3. **Distribute Orders:**

   - Iterate through the sorted vector `diff`.
   - For each order:
     - Assign it to A if `arr[i] > brr[i]` and A can still take more orders, or if B cannot take any more orders.
     - Otherwise, assign it to B.

4. **Return:**
   - Return the total tip stored in `ans`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), as we need to sort the differences, which takes O(n log n) time.
- **Expected Auxiliary Space Complexity:** O(n), as we use a vector of size `n` to store the differences.

### Code

#### C++

```cpp
class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int> &a, vector<int> &b) {
        vector<pair<int, int>> diff(n);
        for (int i = 0; i < n; ++i)
            diff[i] = {abs(a[i] - b[i]), i};

        sort(diff.rbegin(), diff.rend());

        long long ans = 0;
        for (const auto &p : diff) {
            int i = p.second;
            if ((a[i] > b[i] && x > 0) || y == 0) {
                ans += a[i];
                --x;
            } else {
                ans += b[i];
                --y;
            }
        }
        return ans;
    }
};
```

#### Java

```java
class Solution {
    public static long maxTip(int n, int x, int y, int[] arr, int[] brr) {
        List<int[]> diff = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            diff.add(new int[]{Math.abs(arr[i] - brr[i]), i});
        }
        diff.sort((a, b) -> Integer.compare(b[0], a[0]));

        long ans = 0;
        for (int[] p : diff) {
            int i = p[1];
            if ((arr[i] > brr[i] && x > 0) || y == 0) {
                ans += arr[i];
                x--;
            } else {
                ans += brr[i];
                y--;
            }
        }
        return ans;
    }
}
```

#### Python

```python
from typing import List

class Solution:
    def maxTip(self, n: int, x: int, y: int, arr: List[int], brr: List[int]) -> int:
        diff = [(abs(arr[i] - brr[i]), i) for i in range(n)]
        diff.sort(reverse=True, key=lambda x: x[0])

        ans = 0
        for _, i in diff:
            if (arr[i] > brr[i] and x > 0) or y == 0:
                ans += arr[i]
                x -= 1
            else:
                ans += brr[i]
                y -= 1
        return ans
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
