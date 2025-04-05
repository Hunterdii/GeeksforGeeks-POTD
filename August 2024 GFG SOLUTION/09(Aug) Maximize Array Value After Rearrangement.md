## 09. Maximize Array Value After Rearrangement

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1)

### Problem Description

Given an array `arr` of `n` integers, the task is to find the maximum value of the sum ∑arr[i] \* i for all `i` from `0` to `n-1`, where `i` is the index of the element in the array. The elements of the array can be rearranged to achieve the maximum possible sum. Since the result can be very large, return the answer modulo \(10^9 + 7\).

**Example 1:**

Input:

```
arr = [5, 3, 2, 4, 1]
```

Output:

```
40
```

Explanation:
Rearranging the array as [1, 2, 3, 4, 5] results in the sum 1\*0 + 2\*1 + 3\*2 + 4\*3 + 5\*4 = 40, which is the maximum possible sum.

**Example 2:**

Input:

```
arr = [1, 2, 3]
```

Output:

```
8
```

### My Approach

1. **Sorting:**

   - Start by sorting the array `arr` in ascending order. This ensures that the smallest elements are multiplied by the smallest indices, and the largest elements by the largest indices, maximizing the sum.

2. **Calculation:**

   - Initialize a variable `ans` to store the maximum sum.
   - Iterate through the sorted array, calculating the sum ∑arr[i] \* i for all indices `i` from `0` to `n-1`.
   - Since the sum can be large, take the modulo \(10^9 + 7\) during the calculation to avoid overflow.

3. **Return:**
   - Return the value of `ans`, which contains the maximum sum modulo \(10^9 + 7\).

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), because sorting the array takes O(n log n) time.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the calculation.

### Code (C++)

```cpp
class Solution {
public:
    int mod = 1e9 + 7;

    int Maximize(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unsigned long long ans = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            ans = (ans + arr[i] * 1ULL * i) % mod;
        }

        return ans;
    }
};
```

### Code (Java)

```java
class Solution {
    int mod = 1000000007;

    int Maximize(int[] arr) {
        Arrays.sort(arr);  // Sort the array
        long ans = 0;
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            ans = (ans + (long)arr[i] * i) % mod;
        }

        return (int) ans;
    }
}
```

### Code (Python)

```python
class Solution:
    def Maximize(self, arr):
        mod = 10**9 + 7
        arr.sort()  # Sort the array
        ans = 0
        n = len(arr)

        for i in range(n):
            ans = (ans + arr[i] * i) % mod

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
