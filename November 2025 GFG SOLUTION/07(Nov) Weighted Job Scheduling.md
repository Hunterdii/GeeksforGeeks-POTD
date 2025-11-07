---
title: "💼 Weighted Job Scheduling | GFG Solution 🔍"
keywords🏷️: ["💼 weighted job scheduling", "📊 dynamic programming", "🔍 binary search", "📈 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Weighted Job Scheduling problem: maximize profit by scheduling non-overlapping jobs using dynamic programming and binary search. 🚀"
date: 📅 2025-11-07
---

# *07. Weighted Job Scheduling*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/weighted-job-scheduling/1)

## **🧩 Problem Description**

You are given a 2D array `jobs[][]` of size `n × 3`, where each row represents a single job with the following details:

- `jobs[i][0]`: Start time of the job
- `jobs[i][1]`: End time of the job  
- `jobs[i][2]`: Profit earned by completing the job

Your task is to find the **maximum profit** you can earn by scheduling **non-overlapping jobs**.

**Note:** Two jobs are said to be non-overlapping if the end time of one job is less than or equal to the start time of the next job. If a job ends at time X, another job can start exactly at time X.

## **📘 Examples**

### Example 1

```cpp
Input: jobs[][] = [[1, 2, 50], 
                   [3, 5, 20],
                   [6, 19, 100],
                   [2, 100, 200]] 
Output: 250
Explanation: The first and fourth jobs with the time range [1, 2] and [2, 100] can be chosen 
to give maximum profit of 50 + 200 = 250.
```

### Example 2

```cpp
Input: jobs[][] = [[1, 3, 60], 
                   [2, 5, 50],
                   [4, 6, 70],
                   [5, 7, 30]] 
Output: 130
Explanation: The first and third jobs with the time range [1, 3] and [4, 6] can be chosen 
to give maximum profit of 60 + 70 = 130.
```

## **🔒 Constraints**

* $1 \le \text{jobs.size()} \le 10^5$
* $1 \le \text{jobs}[i][0] < \text{jobs}[i][1] \le 10^9$
* $1 \le \text{jobs}[i][2] \le 10^4$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming with Binary Search** to efficiently find the maximum profit by scheduling non-overlapping jobs:

### **Dynamic Programming + Binary Search**

1. **Sort Jobs by Start Time:**
   * First, sort all jobs by their start time. This allows us to process jobs in chronological order and makes binary search possible for finding compatible jobs.

2. **Initialize DP Array:**
   * Create a DP array `dp[i]` where `dp[i]` represents the maximum profit achievable from job index `i` to the end.
   * Initialize `dp[n] = 0` (base case: no profit after all jobs).

3. **Process Jobs Backwards:**
   * Iterate from the last job to the first (`i = n-1` to `0`).
   * For each job `i`, we have two choices:
     - **Take the job**: Earn `jobs[i][2]` profit and add profit from the next compatible job.
     - **Skip the job**: Take the profit from `dp[i+1]`.

4. **Find Next Compatible Job:**
   * Use **binary search** to find the earliest job that starts at or after the current job ends.
   * Search for the smallest index `nxt` where `jobs[nxt][0] >= jobs[i][1]`.

5. **Update DP Value:**
   * `dp[i] = max(jobs[i][2] + dp[nxt], dp[i+1])`
   * This represents choosing the maximum between taking and skipping the current job.

6. **Return Result:**
   * The answer is stored in `dp[0]`, which represents the maximum profit starting from the first job.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the number of jobs. Sorting takes O(n log n), and for each job, we perform a binary search which takes O(log n), resulting in O(n log n) overall.
* **Expected Auxiliary Space Complexity:** O(n), as we use a DP array of size n+1 to store the maximum profit for each position.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end());
        int n = jobs.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int l = i + 1, r = n - 1, nxt = n;
            while (l <= r) {
                int m = (l + r) / 2;
                if (jobs[m][0] >= jobs[i][1]) {
                    nxt = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            dp[i] = max(jobs[i][2] + dp[nxt], dp[i + 1]);
        }
        return dp[0];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Using STL Lower Bound**

### 💡 Algorithm Steps:

1. Sort jobs by start time for sequential processing.
2. Use STL lower_bound to find next compatible job efficiently.
3. Apply dynamic programming with tabulation from end to start.
4. Return maximum profit from the first job position.

```cpp
class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end());
        int n = jobs.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(jobs.begin() + i + 1, jobs.end(), jobs[i][1], 
                [](const vector<int>& job, int val) { return job[0] < val; });
            int nxt = it - jobs.begin();
            dp[i] = max(jobs[i][2] + dp[nxt], dp[i + 1]);
        }
        return dp[0];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting and binary search
* **Auxiliary Space:** 💾 O(n) - DP array storage

### ✅ **Why This Approach?**

* Cleaner code using STL utilities
* Less prone to indexing errors
* Standard library optimizations

## 📊 **3️⃣ Memoization Approach**

### 💡 Algorithm Steps:

1. Sort jobs by start time initially.
2. Use recursive function with memoization map.
3. For each position, choose to take or skip current job.
4. Cache results to avoid recomputation.

```cpp
class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end());
        vector<int> memo(jobs.size(), -1);
        return solve(jobs, 0, memo);
    }
    int solve(vector<vector<int>> &jobs, int i, vector<int> &memo) {
        if (i >= jobs.size()) return 0;
        if (memo[i] != -1) return memo[i];
        int l = i + 1, r = jobs.size() - 1, nxt = jobs.size();
        while (l <= r) {
            int m = (l + r) / 2;
            if (jobs[m][0] >= jobs[i][1]) {
                nxt = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return memo[i] = max(jobs[i][2] + solve(jobs, nxt, memo), solve(jobs, i + 1, memo));
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting and memoized recursion
* **Auxiliary Space:** 💾 O(n) - Recursion stack and memo array

### ✅ **Why This Approach?**

* Top-down intuitive thinking
* Easy to understand recursion flow
* Natural problem decomposition

## 📊 **4️⃣ Sort by End Time**

### 💡 Algorithm Steps:

1. Sort jobs by end time instead of start time.
2. Build DP array where each position stores max profit up to that job.
3. For each job, find last non-overlapping job using binary search.
4. Compute maximum profit by including or excluding current job.

```cpp
class Solution {
public:
    int maxProfit(vector<vector<int>> &jobs) {
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
        int n = jobs.size();
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; i++) {
            int profit = jobs[i][2];
            int l = 0, r = i - 1, last = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (jobs[m][1] <= jobs[i][0]) {
                    last = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (last != -1) profit += dp[last];
            dp[i] = max(dp[i - 1], profit);
        }
        return dp[n - 1];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting and binary search
* **Auxiliary Space:** 💾 O(n) - DP array

### ✅ **Why This Approach?**

* Different perspective on job scheduling
* Forward DP progression
* Classic weighted interval scheduling

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Manual Binary Search**       | 🟢 O(n log n)          | 🟢 O(n)                 | 🚀 Full control over logic        | 🔧 Index management needed           |
| 🔍 **STL Lower Bound**            | 🟢 O(n log n)          | 🟢 O(n)                 | 📖 Cleaner code                   | 🔧 Lambda syntax complexity          |
| 📊 **Memoization**                | 🟢 O(n log n)          | 🟡 O(n)                 | 🎯 Recursive intuition            | 🐌 Stack overhead                    |
| 🔄 **Sort by End Time**           | 🟢 O(n log n)          | 🟢 O(n)                 | ⭐ Forward DP                     | 🔧 Different sorting logic           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production code**                                | 🥇 **STL Lower Bound**               | ★★★★★                     |
| 📖 **Learning/Interview**                             | 🥈 **Manual Binary Search**          | ★★★★★                     |
| 🔧 **Recursive preference**                           | 🥉 **Memoization**                   | ★★★★☆                     |
| 🎯 **Classic scheduling**                             | 🏅 **Sort by End Time**              | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxProfit(int[][] jobs) {
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]);
        int n = jobs.length;
        int[] dp = new int[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            int l = i + 1, r = n - 1, nxt = n;
            while (l <= r) {
                int m = (l + r) / 2;
                if (jobs[m][0] >= jobs[i][1]) {
                    nxt = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            dp[i] = Math.max(jobs[i][2] + dp[nxt], dp[i + 1]);
        }
        return dp[0];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution: 
    def maxProfit(self, jobs):
        jobs.sort()
        n = len(jobs)
        dp = [0] * (n + 1)
        for i in range(n - 1, -1, -1):
            l, r, nxt = i + 1, n - 1, n
            while l <= r:
                m = (l + r) // 2
                if jobs[m][0] >= jobs[i][1]:
                    nxt = m
                    r = m - 1
                else:
                    l = m + 1
            dp[i] = max(jobs[i][2] + dp[nxt], dp[i + 1])
        return dp[0]
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
