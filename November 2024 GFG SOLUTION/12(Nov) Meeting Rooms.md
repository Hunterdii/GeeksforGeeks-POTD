# _12. Meeting Rooms_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/attend-all-meetings/1)

> **Note:** I'm currently in the middle of my exams until November 19, so I’ll be uploading daily POTD solutions, but not at a fixed time. Apologies for any inconvenience, and thank you for your patience!

## Problem Description

Given an array `arr[][]`, where `arr[i][0]` is the starting time of the i-th meeting and `arr[i][1]` is the ending time of the i-th meeting, determine if it is possible for a person to attend all the meetings. A person can only attend one meeting at a time, meaning each meeting must start after the previous one ends.

### Examples:

**Input:**

```
arr[][] = [[1, 4], [10, 15], [7, 10]]
```

**Output:**

```
true
```

**Explanation:**  
Since all the meetings are held at different times, it is possible to attend all the meetings.

**Input:**

```
arr[][] = [[2, 4], [9, 12], [6, 10]]
```

**Output:**

```
false
```

**Explanation:**  
The second and third meetings overlap, making it impossible to attend all of them.

## My Approach

1. **Sorting and Overlap Checking:**

   - First, sort the meetings based on their starting times.
   - Traverse through the sorted list, comparing the end time of the current meeting with the start time of the next meeting.
   - If any meeting starts before the previous one ends, return `false` as overlapping prevents attending all meetings.

2. **Edge Cases:**
   - If there are no meetings, return `true`.
   - If there is only one meeting, return `true` as no overlap can occur.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), where `n` is the number of meetings. Sorting the list of meetings takes O(n log n), while checking overlaps requires O(n).
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to store indices and temporary values.

## Code (C++)

```cpp
class Solution {
  public:
    bool canAttend(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; i++) {
            if (arr[i][1] > arr[i + 1][0])
                return false;
        }
        return true;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

### Alternative Approach (Using Lambda Comparator)

```cpp
class Solution {
public:
    bool canAttend(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i - 1][1] > intervals[i][0]) {
                return false;
            }
        }
        return true;
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    static boolean canAttend(int[][] arr) {
        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));

        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i][1] > arr[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
}
```

## Code (Python)

```python
class Solution:
    def canAttend(self, arr):
        arr.sort(key=lambda x: x[0])
        for i in range(len(arr) - 1):
            if arr[i][1] > arr[i + 1][0]:
                return False
        return True
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
