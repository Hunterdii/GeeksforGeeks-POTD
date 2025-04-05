# _8. Overlapping Intervals_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/overlapping-intervals--170633/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised in the poll, I’ve started solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My solutions for December are now live! Check out today's solution below:  
  **[2054. Two Best Non-Overlapping Events](https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2054.Two%20Best%20Non-Overlapping%20Events.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2054.Two%20Best%20Non-Overlapping%20Events.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2054.Two%20Best%20Non-Overlapping%20Events.md">
  <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
</div>

<br/>

## Problem Description

Given an array of intervals `arr[][]`, where each interval `arr[i] = [starti, endi]` represents a range of integers, merge all overlapping intervals.

The output should return an array of the merged intervals sorted by their starting points.

### Examples:

**Input:**  
`arr = [[1,3],[2,4],[6,8],[9,10]]`  
**Output:**  
`[[1,4],[6,8],[9,10]]`

**Explanation:**

- `[1,3]` and `[2,4]` overlap, so they merge into `[1,4]`.

**Input:**  
`arr = [[6,8],[1,9],[2,4],[4,7]]`  
**Output:**  
`[[1,9]]`

**Explanation:**

- All intervals overlap with `[1,9]`, so they merge into `[1,9]`.

### Constraints:

- `1 ≤ arr.size() ≤ 10^5`
- `0 ≤ starti ≤ endi ≤ 10^5`

## My Approach

1. **Sorting Intervals**:

   - The first step is to sort the intervals by their starting points.
   - This ensures that we can linearly process intervals and merge overlapping ones efficiently.

2. **Merging Logic**:

   - Maintain a result list and iterate through the sorted intervals.
   - For each interval:
     - If it overlaps with the last interval in the result, merge them by updating the end point.
     - Otherwise, add the interval to the result as it doesn't overlap with any previous intervals.

3. **Final Output**:
   - The resulting intervals are guaranteed to be sorted and non-overlapping.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), where `n` is the size of the array. The sorting step dominates the time complexity.
- **Expected Auxiliary Space Complexity:** O(n), as we use additional space for storing the merged intervals.

## Code (C)

```c
int compare(const void* a, const void* b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int mergeOverlap(Interval arr[], int n, Interval result[]) {
    if (n == 0) return 0;

    qsort(arr, n, sizeof(Interval), compare);

    result[0] = arr[0];
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[index].end) {
            result[index].end = result[index].end > arr[i].end ? result[index].end : arr[i].end;
        } else {
            index++;
            result[index] = arr[i];
        }
    }
    return index + 1;
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            auto& last = merged.back();

            if (intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};
```

## Code (Java)

```java
class Solution {
    public List<int[]> mergeOverlap(int[][] intervals) {
        List<int[]> merged = new ArrayList<>();
        if (intervals.length == 0) return merged;

        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        int[] current = intervals[0];
        merged.add(current);

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= current[1]) {
                current[1] = Math.max(current[1], intervals[i][1]);
            } else {
                current = intervals[i];
                merged.add(current);
            }
        }

        return merged;
    }
}
```

## Code (Python)

```python
class Solution:
    def mergeOverlap(self, intervals):
        if not intervals:
            return []

        intervals.sort(key=lambda x: x[0])
        merged = [intervals[0]]

        for interval in intervals[1:]:
            last = merged[-1]
            if interval[0] <= last[1]:
                last[1] = max(last[1], interval[1])
            else:
                merged.append(interval)

        return merged
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
