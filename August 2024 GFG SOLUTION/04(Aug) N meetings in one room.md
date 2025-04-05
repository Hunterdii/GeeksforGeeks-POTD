## 04. N Meetings in One Room

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1)

### Problem Description

You are given timings of `n` meetings in the form of `(start[i], end[i])` where `start[i]` is the start time of meeting `i` and `end[i]` is the finish time of meeting `i`. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. Note that the start time of one chosen meeting can't be equal to the end time of another chosen meeting.

**Example:**

Input:

```
n = 6
start[] = [1, 3, 0, 5, 8, 5]
end[] = [2, 4, 6, 7, 9, 9]
```

Output:

```
4
```

Explanation:
Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5, 7), and (8, 9).

### My Approach

1. **Initialization:**

   - Create a list of meetings where each meeting is represented as a tuple of `(start[i], end[i])`.
   - Sort the meetings based on their end times to prioritize the meeting that ends the earliest.

2. **Meeting Selection:**

   - Iterate through the sorted list of meetings.
   - Keep track of the end time of the last selected meeting.
   - For each meeting, if its start time is greater than the end time of the last selected meeting, include it in the count and update the end time.

3. **Return:**
   - Return the count of meetings that can be accommodated.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), as we sort the meetings by their end times, and then iterate through them.
- **Expected Auxiliary Space Complexity:** O(n), as we use a list to store the meetings and an additional variable for tracking the end time.

### Code

**C++**

```cpp
class Solution {
public:
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int, int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.emplace_back(end[i], start[i]);
        }

        sort(meetings.begin(), meetings.end());

        int lastEndTime = -1;
        int res = 0;

        for (const auto& meeting : meetings) {
            if (meeting.second > lastEndTime) {
                res++;
                lastEndTime = meeting.first;
            }
        }

        return res;
    }
};
```

**Java**

```java
class Solution {
    public int maxMeetings(int n, int[] start, int[] end) {
        List<int[]> meetings = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            meetings.add(new int[]{end[i], start[i]});
        }

        meetings.sort((a, b) -> {
            if (a[0] != b[0]) {
                return Integer.compare(a[0], b[0]);
            }
            return Integer.compare(a[1], b[1]);
        });

        int lastEndTime = -1;
        int res = 0;

        for (int[] meeting : meetings) {
            if (meeting[1] > lastEndTime) {
                res++;
                lastEndTime = meeting[0];
            }
        }

        return res;
    }
}
```

**Python**

```python
class Solution:
    def maximumMeetings(self, n, start, end):
        meetings = list(zip(start, end))
        meetings.sort(key=lambda x: x[1])

        count = 0
        last_end_time = 0
        for s, e in meetings:
            if s > last_end_time:
                count += 1
                last_end_time = e

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
