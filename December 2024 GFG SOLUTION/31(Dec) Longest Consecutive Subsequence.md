# _31. Longest Consecutive Subsequence_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1)

## Problem Description

Given an array `arr[]` of non-negative integers, find the length of the longest subsequence such that the elements in the subsequence are consecutive integers. The consecutive numbers can be in any order.

## Examples:

**Input:**  
`arr[] = [2, 6, 1, 9, 4, 5, 3]`  
**Output:**  
`6`  
**Explanation:**  
The consecutive numbers are `[1, 2, 3, 4, 5, 6]`. These 6 numbers form the longest consecutive subsequence.

**Input:**  
`arr[] = [1, 9, 3, 10, 4, 20, 2]`  
**Output:**  
`4`  
**Explanation:**  
The consecutive numbers are `[1, 2, 3, 4]`. These 4 numbers form the longest consecutive subsequence.

**Input:**  
`arr[] = [15, 13, 12, 14, 11, 10, 9]`  
**Output:**  
`7`  
**Explanation:**  
The consecutive numbers are `[9, 10, 11, 12, 13, 14, 15]`. These 7 numbers form the longest consecutive subsequence.

### Constraints:

- $`1 <= arr.size() <= 10^5`$
- $`0 <= arr[i] <= 10^5`$

## My Approach

1. **Set-based Consecutive Detection**:  
   The core idea is to leverage a hash set for fast lookups.

   - Insert all elements of the array into a set.
   - For each number in the set, check if it is the starting number of a sequence (i.e., `num - 1` is not in the set).
   - If it is a starting number, count how many consecutive numbers exist in the sequence.
   - Keep track of the maximum sequence length.

2. **Steps**:
   - Add all elements of the array to a hash set.
   - Traverse each number in the set.
   - If a number is the start of a sequence, calculate the length of the sequence.
   - Update the maximum sequence length as required.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse the array and perform O(1) operations for each element using a hash set.
- **Expected Auxiliary Space Complexity:** O(n), as the hash set requires additional space to store all elements of the array.

## Code (C++)

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (!numSet.count(num - 1)) {
                int current = num, count = 1;
                while (numSet.count(current + 1)) current++, count++;
                longest = max(longest, count);
            }
        }
        return longest;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

### Alternative Using Sorting

1. Sort the array and traverse to find consecutive elements.
2. Time Complexity: O(n log n) due to sorting.
3. Auxiliary Space Complexity: O(1) if sorting in place.

Code:

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int longest = 1;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;
            if (nums[i] == nums[i - 1] + 1) {
                count++;
            } else {
                longest = max(longest, count);
                count = 1;
            }
        }
        return max(longest, count);
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> numSet = new HashSet<>();
        for (int num : nums) numSet.add(num);

        int longest = 0;
        for (int num : numSet)
            if (!numSet.contains(num - 1)) {
                int count = 1;
                while (numSet.contains(++num)) count++;
                longest = Math.max(longest, count);
            }
        return longest;
    }
}
```

## Code (Python)

```python
class Solution:
    def longestConsecutive(self, arr):
        num_set = set(arr)
        longest = 0

        for num in num_set:
            if num - 1 not in num_set:
                current, count = num, 1
                while current + 1 in num_set:
                    current += 1
                    count += 1
                longest = max(longest, count)

        return longest
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
