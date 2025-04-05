## 11. Job Sequencing Problem

The problem can be found at the following link: [Question Link](https://geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1)

### Problem Description

Given a set of `n` jobs where each job `i` has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with a job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

**Examples:**

Input:

```
Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
```

Output:

```
2 60
```

Explanation: Job1 and Job3 can be done with a maximum profit of 60 (20+40).

Input:

```
Jobs = [[1,2,100],[2,1,19],[3,2,27],[4,1,25],[5,1,15]]
```

Output:

```
2 127
```

Explanation: 2 jobs can be done with a maximum profit of 127 (100+27).

### Approach

1. **Sorting the Jobs:**

   - Sort the jobs in descending order of profit. This ensures that we try to complete jobs with higher profit first.

2. **Finding Maximum Deadline:**

   - Identify the maximum deadline among all jobs. This helps in determining the size of the scheduling slot array.

3. **Job Scheduling:**

   - Create a slot array initialized with `-1`, indicating empty slots.
   - Iterate through each job and try to schedule it in the latest possible time slot before its deadline.
   - If a slot is found, mark it as filled, count the job, and add the profit.

4. **Return the Results:**
   - Return the total number of jobs scheduled and the total profit earned.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), as sorting the jobs dominates the overall time complexity.
- **Expected Auxiliary Space Complexity:** O(n), as we use an additional array of size `n` to track the available slots for job scheduling.

### Code (C++)

```cpp
class Solution {
public:
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, cmp);
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i].dead > maxDeadline) {
                maxDeadline = arr[i].dead;
            }
        }
        vector<int> slot(maxDeadline + 1, -1);
        int jobCount = 0;
        int totalProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    jobCount++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {jobCount, totalProfit};
    }
};
```

### Code (Java)

```java
class Solution {
    public static boolean cmp(Job a, Job b) {
        return a.profit > b.profit;
    }
    int[] JobScheduling(Job[] arr, int n) {
        Arrays.sort(arr, (a, b) -> b.profit - a.profit);
        int maxDeadline = 0;
        for (Job job : arr) {
            maxDeadline = Math.max(maxDeadline, job.deadline);
        }
        int[] slot = new int[maxDeadline + 1];
        Arrays.fill(slot, -1);

        int jobCount = 0;
        int totalProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = arr[i].deadline; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    jobCount++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        return new int[]{jobCount, totalProfit};
    }
}
```

### Code (Python)

```python
class Solution:
    def JobScheduling(self, Jobs, n):
        Jobs.sort(key=lambda x: x.profit, reverse=True)
        maxDeadline = max(job.deadline for job in Jobs)
        slot = [-1] * (maxDeadline + 1)

        jobCount = 0
        totalProfit = 0

        for job in Jobs:
            for j in range(job.deadline, 0, -1):
                if slot[j] == -1:
                    slot[j] = job.id
                    jobCount += 1
                    totalProfit += job.profit
                    break
        return [jobCount, totalProfit]
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
