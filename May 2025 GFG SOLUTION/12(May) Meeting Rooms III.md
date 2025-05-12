# *12. Meeting Rooms III*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/meeting-rooms-iii/1)

## **🧩 Problem Description**

You are given an integer `n` representing the number of meeting rooms numbered from `0` to `n - 1`. You are also given a 2D integer array `meetings` where `meetings[i] = [start_i, end_i]` indicates that a meeting is scheduled during the half-open time interval `[start_i, end_i)`. All `start_i` values are unique.

**Meeting Allocation Rules:**

1. When a meeting starts, assign it to the available room with the smallest number.
2. If no rooms are free, delay the meeting until the earliest room becomes available. The delayed meeting retains its original duration.
3. When a room becomes free, assign it to the delayed meeting with the earliest original start time.

Return the room number that hosts the most meetings. If multiple rooms have the same highest number of meetings, return the smallest room number among them.


## **📘 Examples**

### **Example 1:**

#### **Input:**

```
n = 2  
meetings = [[0,6],[2,3],[3,7],[4,8],[6,8]]
```

#### **Output:**

```
1
```

#### **Explanation:**

* Time 0: Both rooms free. Meeting \[0,6) → room 0.
* Time 2: Room 0 busy, room 1 free. Meeting \[2,3) → room 1.
* Time 3: Room 1 frees. Meeting \[3,7) → room 1.
* Time 4: Both busy. Meeting \[4,8) delayed.
* Time 6: Room 0 frees; delayed \[4,8) starts in room 0 at \[6,10).
* Time 6: Meeting \[6,8) arrives; both busy → delayed.
* Time 7: Room 1 frees; delayed \[6,8) starts in room 1 at \[7,9).
  Counts → room 0 has 2, room 1 has 3.

### **Example 2:**

#### **Input:**

```
n = 4  
meetings = [[0,8],[1,4],[3,4],[2,3]]
```

#### **Output:**

```
2
```

#### **Explanation:**

* Time 0: All free. \[0,8) → room 0.
* Time 1: Rooms 1–3 free. \[1,4) → room 1.
* Time 2: Rooms 2–3 free. \[2,3) → room 2.
* Time 3: Room 2 frees. \[3,4) → room 2.
  Counts → \[1,1,2,0].


## **🔒 Constraints**

* $`1 ≤ n ≤ 10^4`$
* $`1 ≤ meetings.size() ≤ 10^4`$
* $`meetings[i].size() == 2`$
* $`0 ≤ start_i < end_i ≤ 10^4`$


## **✅ My Approach**

### **Two Min‐Heaps Simulation**

We simulate the process using two min‐heaps:

* **`avail`**: a min‐heap of available room indices.
* **`busy`**: a min‐heap of pairs `(free_time, room_index)` for rooms currently occupied.

**Key idea:** At each meeting arrival, first release all rooms whose `free_time ≤ start`. If there is an available room, assign the smallest index. Otherwise, take the room that frees the earliest, delay the meeting to that free time, and reassign accordingly.

### **Algorithm Steps:**

1. Sort `meetings` by start time.
2. Initialize `avail` with all room indices `0…n-1`.
3. Initialize empty `busy` heap and count array `cnt[n] = {0}`.
4. For each meeting `[s, e]` in sorted order:

   * While `busy` is nonempty and `busy.top().free_time ≤ s`, pop and push its `room_index` into `avail`.
   * If `avail` is not empty:

     1. Pop the smallest room `r` from `avail`.
     2. Push `(e, r)` into `busy`.
     3. Increment `cnt[r]`.
   * Else:

     1. Pop `(t, r)` from `busy` (earliest free).
     2. Push `(t + (e - s), r)` into `busy` (delayed end).
     3. Increment `cnt[r]`.
5. Return the index of the maximum in `cnt` (tie → smallest index).

## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** Each meeting does up to two heap‐operations on heaps of size ≤ n ⇒ **O(m log n)**, where *m* = number of meetings.
* **Expected Auxiliary Space Complexity:** Storing two heaps and the count array ⇒ **O(n + m)**.


## **🧠 Code (C++)**

```cpp
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<>> avail;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;
        vector<int> cnt(n);
        for(int i=0;i<n;i++) avail.push(i);
        for(auto &m:meetings){
            long long s=m[0], e=m[1];
            while(!busy.empty() && busy.top().first<=s){
                avail.push(busy.top().second);
                busy.pop();
            }
            int r = avail.empty() ? (busy.top().second) : avail.top();
            if(avail.empty()) {
                long long t=busy.top().first;
                busy.pop();
                busy.push({t+e-s, r});
            } else {
                avail.pop();
                busy.push({e, r});
            }
            cnt[r]++;
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Single `multiset` of (freeTime,room)**

Keep one `multiset<pair<long long,int>> rooms`, initially `(0,0),(0,1)…(0,n−1)`. For each sorted `[s,e]`:

1. Extract the **first** entry `(t,i)` from `rooms`.
2. If `t ≤ s`, schedule at `s`; else schedule at `t`.
3. Erase `(t,i)` and reinsert `(newEnd, i)` where
   `newEnd = max(t, s) + (e–s)`.
4. `cnt[i]++`.

```cpp
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        vector<int> count(n, 0); 
        for (int i = 0; i < n; ++i)
            available.push(i);
        for (const auto& m : meetings) {
            long long start = m[0], end = m[1];
            long long duration = end - start;
            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }
            int room;
            long long actualStart;
            if (!available.empty()) {
                room = available.top(); available.pop();
                actualStart = start;
            } else {
                auto next = busy.top(); busy.pop();
                room = next.second;
                actualStart = next.first;
            }
            long long actualEnd = actualStart + duration;
            busy.push({actualEnd, room});
            count[room]++;
        }
        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[maxRoom]) maxRoom = i;
        }
        return maxRoom;
    }
};
```

* **Time:** O(m log n)
* **Space:** O(n)

## 📊 **4️⃣ Event-Driven Sweep with Waiting Queue**

We build an **event list** of all meeting **start-events**, sorted by time. We also maintain:

* `freeRooms` (min-heap of indices),
* `waiting` (min-heap of delayed meetings by original start),
* `busy` (min-heap of `(end_time, room)`).

Process by **advancing** to the next event (either a meeting start or a room freeing):

1. At each time `T`, **free** all `(end_time ≤ T)` → push rooms to `freeRooms`.
2. **Enqueue** any meeting whose start = `T` into `waiting`.
3. While `freeRooms` & `waiting` both nonempty:

   * Pop `i` from `freeRooms` and meeting `m` from `waiting`,
   * Schedule it: push `(T + duration, i)` into `busy`, `cnt[i]++`.
4. Advance `T` to next event time.

```cpp


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        sort(meet.begin(), meet.end(),
             [](const vector<int>& A, const vector<int>& B){
                 return A[0] < B[0];
             });
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        priority_queue<pair<long long,int>,
                      vector<pair<long long,int>>,
                      greater<pair<long long,int>>> busy;
        priority_queue<pair<long long,long long>,
                      vector<pair<long long,long long>>,
                      greater<pair<long long,long long>>> waiting;
        vector<int> cnt(n, 0);
        int m = meet.size();
        for (int i = 0; i < n; ++i) freeRooms.push(i);

        int idx = 0;
        long long T = 0;
        while (idx < m || !busy.empty() || !waiting.empty()) {
            long long nxtT = LLONG_MAX;
            if (idx < m) {
                long long s = meet[idx][0];
                if (s < nxtT) nxtT = s;
            }
            if (!busy.empty() && busy.top().first < nxtT) {
                nxtT = busy.top().first;
            }
            T = nxtT;
            while (!busy.empty() && busy.top().first <= T) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }
            while (idx < m && meet[idx][0] == T) {
                long long orig = meet[idx][0];
                long long dur  = meet[idx][1] - meet[idx][0];
                waiting.push(make_pair(orig, dur));
                idx++;
            }
            while (!freeRooms.empty() && !waiting.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                pair<long long,long long> w = waiting.top();
                waiting.pop();
                long long dur = w.second;
                busy.push(make_pair(T + dur, room));
                cnt[room]++;
            }
        }
        int ans = 0;
        for (int i = 1; i < n; ++i)
            if (cnt[i] > cnt[ans]) ans = i;
        return ans;
    }
};
```

* **Time:** O((m + k) log n) where *k* = number of delayed assignments
* **Space:** O(n + m)


## 🆚 **Comparison of Approaches**

| **Approach**                 | ⏱️ **Time**       | 🗂️ **Space** | ✅ **Pros**            | ⚠️ **Cons**               |
| ---------------------------- | ----------------- | ------------- | --------------------- | ------------------------- |
| Two-Heap Simulation          | 🟢 O(m log n)     | 🟢 O(n + m)   | Fast, straightforward | Requires two heaps        |
| Single `multiset`            | 🟡 O(m log n)     | 🟢 O(n)       | Only one container    | Slightly more complex API |
| Event-Driven + Waiting Queue | 🟡 O((m+k) log n) | 🔴 O(n + m)   | Models delays exactly | More bookkeeping          |


### ✅ **Best Choice?**

| **Scenario**                     | **Recommended Approach**         |
| -------------------------------- | -------------------------------- |
| Large *m* and *n* (≤10⁴)         | 🥇 Two-Heap Simulation           |
| Want a single balanced container | 🥈 `multiset`-based              |
| Exact event modeling             | 🥉 Event-Driven + Waiting Queue |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int mostBooked(int n, int[][] A) {
        int[] cnt = new int[n];
        PriorityQueue<int[]> occ = new PriorityQueue<>((a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1]));
        PriorityQueue<Integer> avail = new PriorityQueue<>();
        for (int i = 0; i < n; i++) avail.offer(i);
        Arrays.sort(A, (a, b) -> a[0] != b[0] ? Integer.compare(a[0], b[0]) : Integer.compare(a[1], b[1]));

        for (int[] m : A) {
            int s = m[0], e = m[1];
            while (!occ.isEmpty() && occ.peek()[0] <= s) avail.offer(occ.poll()[1]);
            if (!avail.isEmpty()) {
                int r = avail.poll();
                occ.offer(new int[]{e, r});
                cnt[r]++;
            } else {
                int[] t = occ.poll();
                occ.offer(new int[]{t[0] + e - s, t[1]});
                cnt[t[1]]++;
            }
        }

        int res = 0;
        for (int i = 1; i < n; i++) if (cnt[i] > cnt[res]) res = i;
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def mostBooked(self, n, A):
        A.sort()
        free = list(range(n))
        heapq.heapify(free)
        used = []
        cnt = [0] * n
        for s, e in A:
            while used and used[0][0] <= s:
                _, i = heapq.heappop(used)
                heapq.heappush(free, i)
            if not free:
                t, i = heapq.heappop(used)
                heapq.heappush(used, (t + e - s, i))
                cnt[i] += 1
            else:
                i = heapq.heappop(free)
                heapq.heappush(used, (e, i))
                cnt[i] += 1
        return cnt.index(max(cnt))
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
