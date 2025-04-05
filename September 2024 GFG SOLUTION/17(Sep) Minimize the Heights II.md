# _17. Minimize the Heights II_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1)

### Problem Description

Given an array `arr[]` denoting the heights of `N` towers and a positive integer `K`, perform exactly one of the following operations for each tower:

1. Increase the height of the tower by `K`.
2. Decrease the height of the tower by `K`.

The goal is to find out the minimum possible difference between the height of the shortest and tallest towers after modifying each tower. The resultant array should not contain any negative integers.

_Example:_

- **Input:** `k = 2, arr[] = {1, 5, 8, 10}`
- **Output:** `5`

  Explanation: The array can be modified as `{1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}`. The difference between the largest and smallest values is `8 - 3 = 5`.

- **Input:** `k = 3, arr[] = {3, 9, 12, 16, 20}`
- **Output:** `11`

  Explanation: The array can be modified as `{3+k, 9+k, 12-k, 16-k, 20-k} = {6, 12, 9, 13, 17}`. The difference between the largest and smallest values is `17 - 6 = 11`.

### My Approach

1. **Sorting and Initialization:**

   - Start by sorting the array. This helps in efficiently calculating the minimum and maximum values after modifications.
   - Initialize the smallest and largest values after applying the increase and decrease operations.

2. **Calculating Minimum Difference:**

   - After sorting, iterate through the array to calculate the potential smallest and largest values after modifying each element.
   - For each tower, calculate:
     - The minimum value considering the increase operation on the first elements and decrease operation on the rest.
     - The maximum value considering the decrease operation on the first elements and increase operation on the rest.
   - Keep track of the minimum difference between the maximum and minimum values obtained.

3. **Final Answer:**
   - Return the smallest difference found from the above calculations.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), where `n` is the length of the array. This is due to the sorting step, and the subsequent operations are linear in complexity.
- **Expected Auxiliary Space Complexity:** O(1), as only a constant amount of additional space is used apart from the input array.

### Code (C++)

```cpp
class Solution {
public:
    int getMinDiff(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;
        sort(arr.begin(), arr.end());
        int ans = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        for (int i = 0; i < n - 1; i++) {
            int minVal = min(smallest, arr[i + 1] - k);
            int maxVal = max(largest, arr[i] + k);
            if (minVal < 0) continue;
            ans = min(ans, maxVal - minVal);
        }

        return ans;
    }
};
```

### Code (Java)

```java
class Solution {
    int getMinDiff(int[] arr, int k) {
        int n = arr.length;
        if (n == 1) return 0;
        Arrays.sort(arr);
        int ans = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        for (int i = 0; i < n - 1; i++) {
            int minVal = Math.min(smallest, arr[i + 1] - k);
            int maxVal = Math.max(largest, arr[i] + k);
            if (minVal < 0) continue;
            ans = Math.min(ans, maxVal - minVal);
        }

        return ans;
    }
}
```

### Code (Python)

```python
class Solution:
    def getMinDiff(self, arr, k):
        n = len(arr)
        if n == 1:
            return 0
        arr.sort()
        ans = arr[-1] - arr[0]
        smallest = arr[0] + k
        largest = arr[-1] - k
        for i in range(n - 1):
            minVal = min(smallest, arr[i + 1] - k)
            maxVal = max(largest, arr[i] + k)
            if minVal < 0:
                continue
            ans = min(ans, maxVal - minVal)

        return ans
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
