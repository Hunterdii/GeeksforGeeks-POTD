# _23. Minimize the Heights I_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Solutions ✨</h2>
</div>

- Continuing the **LeetCode Problem of the Day (POTD)** journey! 🎯
- Today's problem is live:  
  **[1861. Rotating the Box](https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/1861.Rotating%20the%20Box.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/1861.Rotating%20the%20Box.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/1861.Rotating%20the%20Box.md">
    <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
  </a>
</div>

<br/>

## Problem Description

Given a positive integer `k` and an array `arr[]` denoting the heights of towers, you are allowed to modify the height of each tower either by increasing or decreasing them by `k` only once. Your task is to find the possible minimum difference between the height of the shortest and the longest towers after modification.

**Note:** A slight modification of the problem can be found [here](https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1).

### Examples:

**Input:**  
`k = 2`, `arr[] = [1, 5, 8, 10]`  
**Output:**  
`5`  
**Explanation:**  
The array can be modified as `[3, 3, 6, 8]`. The difference between the largest and smallest heights is `8 - 3 = 5`.

**Input:**  
`k = 3`, `arr[] = [3, 9, 12, 16, 20]`  
**Output:**  
`11`  
**Explanation:**  
The array can be modified as `[6, 12, 9, 13, 17]`. The difference between the largest and smallest heights is `17 - 6 = 11`.

### Constraints:

- `1 ≤ k ≤ 10^4`
- `1 ≤ number of towers ≤ 10^5`
- `0 ≤ arr[i] ≤ 10^5`

## My Approach

1. **Sorting Approach:**  
   The idea is to first sort the array and then attempt to modify the heights in such a way that the difference between the tallest and shortest towers is minimized. By modifying the tallest and shortest towers with either an addition or subtraction of `k`, we minimize the range. The goal is to iterate through the modified array to find the minimum possible difference.

2. **Steps:**
   - Sort the array to bring the shortest and tallest towers together.
   - Adjust the smallest and largest elements with either addition or subtraction of `k`.
   - Use a sliding window approach to minimize the difference between the largest and smallest heights after modification.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), where `n` is the size of the array. Sorting the array takes O(n log n), and subsequent linear passes over the array take O(n).
- **Expected Auxiliary Space Complexity:** O(n), as we use additional space to store the modified tower heights and count arrays.

## Code (C++)

```cpp
class Solution {
public:
    int getMinDiff(int k, vector<int>& arr) {
        vector<pair<int, int>> v;
        int n = arr.size();
        vector<int> taken(n, 0);

        for (int i = 0; i < n; i++) {
            v.emplace_back(arr[i] - k, i);
            v.emplace_back(arr[i] + k, i);
        }

        sort(v.begin(), v.end());

        int elements_in_range = 0, left = 0, ans = INT_MAX;

        for (int right = 0; right < v.size(); right++) {
            if (taken[v[right].second]++ == 0) {
                elements_in_range++;
            }

            while (elements_in_range == n) {
                ans = min(ans, v[right].first - v[left].first);

                if (--taken[v[left].second] == 0) {
                    elements_in_range--;
                }
                left++;
            }
        }

        return ans;
    }
};
```

## Code (Java)

```java
class Solution {
    public int getMinDiff(int k, int[] arr) {
        List<int[]> modified = new ArrayList<>();
        int n = arr.length;
        int[] count = new int[n];

        for (int i = 0; i < n; i++) {
            modified.add(new int[]{arr[i] - k, i});
            modified.add(new int[]{arr[i] + k, i});
        }

        modified.sort((a, b) -> Integer.compare(a[0], b[0]));

        int left = 0, elementsInRange = 0, ans = Integer.MAX_VALUE;

        for (int right = 0; right < modified.size(); right++) {
            if (count[modified.get(right)[1]]++ == 0) {
                elementsInRange++;
            }

            while (elementsInRange == n) {
                ans = Math.min(ans, modified.get(right)[0] - modified.get(left)[0]);

                if (--count[modified.get(left)[1]] == 0) {
                    elementsInRange--;
                }
                left++;
            }
        }

        return ans;
    }
}
```

## Code (Python)

```python
class Solution:
    def getMinDiff(self, k: int, arr: list) -> int:
        n = len(arr)
        modified = []
        count = [0] * n

        for i in range(n):
            modified.append((arr[i] - k, i))
            modified.append((arr[i] + k, i))

        modified.sort()

        left = 0
        elements_in_range = 0
        ans = float('inf')

        for right in range(len(modified)):
            if count[modified[right][1]] == 0:
                elements_in_range += 1
            count[modified[right][1]] += 1

            while elements_in_range == n:
                ans = min(ans, modified[right][0] - modified[left][0])

                if count[modified[left][1]] == 1:
                    elements_in_range -= 1
                count[modified[left][1]] -= 1
                left += 1

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
