# _25. Alternative Sorting_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/alternative-sorting1311/1)

_Note: My externals exams are currently ongoing, which is the reason for the delayed upload **Sorry** ._

## Problem Description

Given an array `arr` of distinct integers, rearrange the array such that:

- The first element is the largest,
- The second element is the smallest,
- The third element is the second largest,
- The fourth element is the second smallest, and so on.

This pattern continues until all elements are arranged accordingly.

**Examples:**

1. **Input:**  
   `arr = [7, 1, 2, 3, 4, 5, 6]`  
   **Output:**  
   `[7, 1, 6, 2, 5, 3, 4]`

2. **Input:**  
   `arr = [1, 6, 9, 4, 3, 7, 8, 2]`  
   **Output:**  
   `[9, 1, 8, 2, 7, 3, 6, 4]`

**Constraints:**

- `1 ≤ arr.size() ≤ 10^5`
- `1 ≤ arr[i] ≤ 10^5`

## My Approach

1. **Sorting:**

   - First, sort the array to arrange elements in ascending order.

2. **Two Pointers & Alternate Selection:**

   - Utilize two pointers to point to the largest (right) and smallest (left) elements in the sorted array.
   - Traverse the array in a manner that alternates between taking the largest element (decrementing the right pointer) and the smallest element (incrementing the left pointer).
   - This ensures a sequence of largest-smallest arrangements in the desired pattern.

3. **Implementation:**
   - Use a boolean `highTurn` to toggle between taking from the right or left end.
   - Append elements to the result list based on `highTurn`, ensuring the specified order.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** `O(n log n)`, due to the sorting step of the array.
- **Expected Auxiliary Space Complexity:** `O(n)`, as we use a separate array to store the rearranged elements.

## Code (C++)

```cpp
class Solution {
public:
    vector<int> alternateSort(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        vector<int> ans(n);

        int left = 0, right = n - 1;
        bool highTurn = true;

        for (int k = 0; k < n; ++k) {
            if (highTurn) {
                ans[k] = arr[right--];
            } else {
                ans[k] = arr[left++];
            }
            highTurn = !highTurn;
        }

        return ans;
    }
};
```

## Code (Java)

```java
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public static ArrayList<Integer> alternateSort(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>(n);

        int left = 0, right = n - 1;
        boolean highTurn = true;

        for (int i = 0; i < n; ++i) {
            if (highTurn) {
                ans.add(arr[right--]);
            } else {
                ans.add(arr[left++]);
            }
            highTurn = !highTurn;
        }

        return ans;
    }
}
```

## Code (Python)

```python
class Solution:
    def alternateSort(self, arr):
        arr.sort()
        n = len(arr)
        ans = []

        left, right = 0, n - 1
        highTurn = True

        for _ in range(n):
            if highTurn:
                ans.append(arr[right])
                right -= 1
            else:
                ans.append(arr[left])
                left += 1
            highTurn = not highTurn

        return ans
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
