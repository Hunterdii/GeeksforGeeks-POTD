# _10. Non-overlapping Intervals_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/non-overlapping-intervals/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised in the poll, I’ve started solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My solutions for December are now live! Check out today's solution below:  
  [**2981. Find Longest Special Substring That Occurs Thrice I**](https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2981.Find%20Longest%20Special%20Substring%20That%20Occurs%20Thrice%20I.md)

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2981.Find%20Longest%20Special%20Substring%20That%20Occurs%20Thrice%20I.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/2981.Find%20Longest%20Special%20Substring%20That%20Occurs%20Thrice%20I.md">
    <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
  </a>
</div>

## Problem Description

Given a 2D array `intervals[][]` where `intervals[i] = [starti, endi]` represents an interval, return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

### Examples

**Input:**  
`intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]`  
**Output:**  
`1`

**Explanation:**  
Removing `[1, 3]` makes the rest of the intervals non-overlapping.

**Input:**  
`intervals[][] = [[1, 3], [1, 3], [1, 3]]`  
**Output:**  
`2`

**Explanation:**  
You need to remove two `[1, 3]` intervals to make the rest non-overlapping.

**Input:**  
`intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]`  
**Output:**  
`0`

**Explanation:**  
All intervals are already non-overlapping.

### Constraints

- `1 ≤ intervals.size() ≤ 10^5`
- `|intervals[i]| == 2`
- `0 ≤ starti < endi ≤ 5 × 10^4`

## My Approach

1. **Sort Intervals by Start Time**:

   - Sort the intervals by their start time to process them in order. This ensures that overlapping intervals can be easily identified.

2. **Iterate Through Intervals**:

   - Use a variable `prevEnd` to track the end of the last interval.
   - For each interval, check if the current interval's start time is less than `prevEnd`.
   - If overlapping, increment the removal count and update `prevEnd` to the smaller of the two end times (to minimize further overlaps).
   - Otherwise, update `prevEnd` to the current interval's end time.

3. **Return the Count of Removals**:
   - The final count will represent the minimum number of intervals to remove.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), where `n` is the size of the `intervals` array. Sorting the intervals dominates the computation.
- **Expected Auxiliary Space Complexity:** O(1), as only a constant amount of extra space is used for variables.

## Code (C)

```c
int compare(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return (intervalA->start - intervalB->start);
}
int minRemoval(Interval *intervals, int intervalsSize) {
    qsort(intervals, intervalsSize, sizeof(Interval), compare);
    int count = 0, prevEnd = intervals[0].end;

    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i].start < prevEnd) {
            count++;
            prevEnd = (prevEnd < intervals[i].end) ? prevEnd : intervals[i].end;
        } else {
            prevEnd = intervals[i].end;
        }
    }
    return count;
}
```

## Code (C++)

```cpp
class Solution {
public:
    int minRemoval(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0, prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                count++;
                prevEnd = min(prevEnd, intervals[i][1]);
            } else {
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
};
```

## Code (Java)

```java
class Solution {
    public int minRemoval(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        int count = 0, prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < prevEnd) {
                count++;
                prevEnd = Math.min(prevEnd, intervals[i][1]);
            } else {
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
}
```

## Code (Python)

```python
class Solution:
    def minRemoval(self, intervals):
        intervals.sort(key=lambda x: x[0])
        count, prevEnd = 0, intervals[0][1]

        for i in range(1, len(intervals)):
            if intervals[i][0] < prevEnd:
                count += 1
                prevEnd = min(prevEnd, intervals[i][1])
            else:
                prevEnd = intervals[i][1]

        return count
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
