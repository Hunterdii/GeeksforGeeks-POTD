---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Arrays
  - Greedy
  - Sorting
  - Binary Search
---

# 🚀 _Day 1. Minimum Platforms_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/minimum-platforms-1587115620)

## 💡 **Problem Description:**

You are given the arrival times `arr[]` and departure times `dep[]` of all trains that arrive at a railway station on the same day.

Your task is to determine the **minimum number of platforms** required at the station to ensure that no train is kept waiting.

At any given time, the same platform **cannot** be used for both the **arrival of one train and the departure of another**.

- If a new train arrives **before** another departs, additional platforms are required.
- If all trains are mutually exclusive in time, only **one platform** is needed.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```
arr[] = [900, 940, 950, 1100, 1500, 1800]
dep[] = [910, 1200, 1120, 1130, 1900, 2000]
```

#### **Output:**

```
3
```

#### **Explanation:**

Between **9:40 AM to 12:00 PM**, three trains are present at the station.  
Thus, **at least 3 platforms** are needed to avoid waiting.

### **Example 2:**

#### **Input:**

```
arr[] = [900, 1235, 1100]
dep[] = [1000, 1240, 1200]
```

#### **Output:**

```
1
```

#### **Explanation:**

All train times are **mutually exclusive**.  
Thus, **only one platform** is needed.

### **Example 3:**

#### **Input:**

```
arr[] = [1000, 935, 1100]
dep[] = [1200, 1240, 1130]
```

#### **Output:**

```
3
```

#### **Explanation:**

Between **11:00 AM to 11:30 AM**, all three trains are present at the station.  
Thus, **3 platforms** are required.

### **Constraints:**

- $\(1 \leq \text{Number of trains} \leq 50,000\)$
- $\(0000 \leq \text{arr}[i] \leq \text{dep}[i] \leq 2359\)$
- **Time is given in a 24-hour format (HHMM)**.
- The **first two digits represent the hour (00 to 23)**, and the **last two digits represent the minutes (00 to 59)**.

## 🎯 **My Approach:**

### **Two Pointers (Optimized Sorting)**

#### **Algorithm Steps:**

1. **Sort** both `arr[]` (arrival times) and `dep[]` (departure times).
2. Use **two pointers**:
   - `i` for arrival times, `j` for departure times.
   - **Increment `i` (new train arrives) → Increase platform count.**
   - **Increment `j` (train departs) → Decrease platform count.**
3. Track the **maximum platforms** needed at any time.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N log N)`, since sorting `arr[]` and `dep[]` dominates the time complexity.
- **Expected Auxiliary Space Complexity:** `O(1)`, as we only use a few integer variables for tracking.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    int findPlatform(vector<int>& a, vector<int>& d) {
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());
        int i = 0, j = 0, cnt = 0, ans = 0, n = a.size();
        while(i < n && j < n)
            a[i] <= d[j] ? (cnt++, ans = max(ans, cnt), i++) : (cnt--, j++);
        return ans;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Priority Queue (Min Heap) Approach**

### **Algorithm Steps:**

1. **Sort the arrival times**.
2. **Use a min-heap** to track the earliest departure.
3. **For each arrival:**
   - If it occurs **before the earliest departure**, **increase platform count**.
   - Else, **pop the heap** (a train leaves) and reuse the platform.

### **Code (C++)**

```cpp
class Solution {
public:
    int findPlatform(vector<int>& a, vector<int>& d) {
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int platforms = 0, maxPlatforms = 0;

        for (int i = 0; i < a.size(); i++) {
            while (!pq.empty() && pq.top() < a[i]) {
                pq.pop();
                platforms--;
            }
            pq.push(d[i]);
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
        }
        return maxPlatforms;
    }
};
```

✅ **Time Complexity:** `O(N log N)`  
✅ **Space Complexity:** `O(N)`

## **3️⃣ Difference Array Approach (Efficient Counting)**

### **Algorithm Steps:**

1. **Use a map to store events:**
   - `+1` at arrival time
   - `-1` at departure time + 1
2. **Compute prefix sum** to get the maximum platforms needed.

### **Code (C++)**

```cpp
class Solution {
public:
    int findPlatform(vector<int>& a, vector<int>& d) {
        map<int, int> timeline;

        for (int i = 0; i < a.size(); i++) {
            timeline[a[i]]++;
            timeline[d[i] + 1]--;
        }

        int platforms = 0, maxPlatforms = 0;
        for (auto it = timeline.begin(); it != timeline.end(); ++it) {
            platforms += it->second;
            maxPlatforms = max(maxPlatforms, platforms);
        }
        return maxPlatforms;
    }
};
```

✅ **Time Complexity:** `O(N log N)`  
✅ **Space Complexity:** `O(N)`

## **Comparison of Approaches**

| **Approach**                         | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                            | ⚠️ **Cons**                         |
| ------------------------------------ | ---------------------- | ----------------------- | -------------------------------------- | ----------------------------------- |
| **Two Pointers (Optimized Sorting)** | 🟢 O(N log N)          | 🟢 O(1)                 | Simple & efficient for most cases      | Requires sorted arrival & departure |
| **Priority Queue (Min Heap)**        | 🟢 O(N log N)          | 🔴 O(N)                 | Best for dynamically tracking events   | Uses extra space for heap storage   |
| **Difference Array (Map)**           | 🟢 O(N log N)          | 🟡 O(N)                 | Efficient counting for large timelines | Requires additional map storage     |

✅ **Best Choice?**

- **Two Pointers** → **Best overall** for most cases due to simplicity and efficiency.
- **Priority Queue** → Useful **when tracking active platforms dynamically**.
- **Difference Array** → Works well for **efficient timeline counting**.

</details>

## **Code (Java)**

```java
class Solution {
    static int findPlatform(int arr[], int dep[]) {
        Arrays.sort(arr);
        Arrays.sort(dep);
        int i = 0, j = 0, cnt = 0, ans = 0, n = arr.length;
        while(i < n && j < n)
            if(arr[i] <= dep[j]) { cnt++; ans = Math.max(ans, cnt); i++; }
            else { cnt--; j++; }
        return ans;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def minimumPlatform(self, arr, dep):
        arr.sort(); dep.sort()
        i = j = cnt = ans = 0
        n = len(arr)
        while i < n and j < n:
            if arr[i] <= dep[j]:
                cnt += 1; ans = max(ans, cnt); i += 1
            else:
                cnt -= 1; j += 1
        return ans
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
