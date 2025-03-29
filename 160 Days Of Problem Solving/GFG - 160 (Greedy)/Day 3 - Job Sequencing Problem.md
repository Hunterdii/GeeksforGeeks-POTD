---
Difficulty: Medium  
Source: 160 Days of Problem Solving  
Tags:
  - Greedy
  - Dynamic Programming
---

# 🚀 _Day 3. Job Sequencing Problem_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/job-sequencing-problem-1587115620)  

> Note: Sorry for uploading late, my exam is going on.


## 💡 **Problem Description:** 

You are given two arrays: **deadline[]** and **profit[]**, which represent a set of jobs. Each job:  
- Has a **deadline** by which it must be completed.  
- Has a **profit** associated with it.  
- Takes **exactly one unit of time** to complete.  
- Only **one job** can be scheduled at a time.  

Your task is to determine:  
1. The **maximum number of jobs** that can be completed within their deadlines.  
2. The **maximum total profit** that can be earned by scheduling jobs optimally.  


## 🔍 **Example Walkthrough:**

### **Example 1:**  
#### **Input:**  
```plaintext
deadline = [4, 1, 1, 1]  
profit = [20, 10, 40, 30]
```
#### **Output:**  
```plaintext
[2, 60]
```
#### **Explanation:**  
Jobs **1 and 3** can be scheduled, maximizing profit **(20 + 40 = 60)**.  


### **Example 2:**  
#### **Input:**  
```plaintext
deadline = [2, 1, 2, 1, 1]  
profit = [100, 19, 27, 25, 15]
```
#### **Output:**  
```plaintext
[2, 127]
```
#### **Explanation:**  
Jobs **1 and 3** can be scheduled, maximizing profit **(100 + 27 = 127)**.  


### **Example 3:**  
#### **Input:**  
```plaintext
deadline = [3, 1, 2, 2]  
profit = [50, 10, 20, 30]
```
#### **Output:**  
```plaintext
[3, 100]
```
#### **Explanation:**  
Jobs **1, 3, and 4** can be scheduled, maximizing profit **(50 + 20 + 30 = 100)**.  


## **Constraints**  
- $\( 1 \leq \text{deadline.size()} == \text{profit.size()} \leq 10^5 \)$  
- $\( 1 \leq \text{deadline}[i] \leq \text{deadline.size()} \)$  
- $\( 1 \leq \text{profit}[i] \leq 500 \)$  

## 🎯 **My Approach:**

## **Greedy + Min Heap**

### **Algorithm Steps:**  
1. **Sort jobs** in **ascending order of deadlines** (if two jobs have the same deadline, sort by profit).  
2. Use a **min heap** to keep track of scheduled jobs based on their profits.  
3. **Iterate through jobs** and schedule them:  
   - If the number of scheduled jobs is **less than the current job's deadline**, add it to the heap.  
   - If a lower-profit job exists in the heap, replace it with the current job.  
4. **Return the total jobs scheduled and the sum of profits** from the heap.  


## 🕒 **Time and Auxiliary Space Complexity** 
- **Expected Time Complexity:** $\( O(N \log N) \)$, due to sorting and heap operations.  
- **Expected Auxiliary Space Complexity:** $\( O(N) \)$, due to storing jobs in a heap.  


## 📝 **Solution Code**

## **Code (C++)**  

```cpp
class Solution {
public:
    vector<int> jobSequencing(vector<int>& d, vector<int>& p) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < d.size(); ++i) jobs.emplace_back(d[i], p[i]);
        sort(jobs.begin(), jobs.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& job : jobs) {
            if (job.first > pq.size()) pq.push(job.second);
            else if (pq.top() < job.second) pq.pop(), pq.push(job.second);
        }

        int cnt = pq.size(), tot = 0;
        while (!pq.empty()) tot += pq.top(), pq.pop();
        return {cnt, tot};
    }
};
```


## **Code (Java)**  

```java
class Solution {
    public ArrayList<Integer> jobSequencing(int[] d, int[] p) {
        int n = d.length, cnt = 0, tot = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        List<int[]> jobs = new ArrayList<>();
        
        for (int i = 0; i < n; i++) jobs.add(new int[] {d[i], p[i]});
        jobs.sort(Comparator.comparingInt(a -> a[0]));

        for (int[] job : jobs) {
            if (job[0] > pq.size()) pq.add(job[1]);
            else if (pq.peek() < job[1]) { pq.poll(); pq.add(job[1]); }
        }
        
        cnt = pq.size();
        while (!pq.isEmpty()) tot += pq.poll();
        
        return new ArrayList<>(Arrays.asList(cnt, tot));
    }
}
```


## **Code (Python)**  

```python
from heapq import heappush, heappop

class Solution:
    def jobSequencing(self, d, p):
        jobs = sorted(zip(d, p))
        pq = []

        for deadline, profit in jobs:
            if len(pq) < deadline:
                heappush(pq, profit)
            elif pq and pq[0] < profit:
                heappop(pq)
                heappush(pq, profit)

        return [len(pq), sum(pq)]
```




## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!  

⭐ If you find this helpful, please give this repository a star! ⭐  

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
