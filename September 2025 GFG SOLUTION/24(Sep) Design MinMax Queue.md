---
title: "🔢 Design MinMax Queue | GFG Solution 🔍"
keywords🏷️: ["🔢 min max queue", "🔍 deque", "📍 monotonic queue", "📈 data structure", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Design MinMax Queue problem: implement a queue with O(1) min/max operations using monotonic deques. 🚀"
date: 📅 2025-09-24
---

# *24. Design MinMax Queue*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/design-minmax-queue/1)

## **🧩 Problem Description**

Design a **SpecialQueue** data structure that functions like a normal queue but with additional support for retrieving the minimum and maximum element efficiently.

The SpecialQueue must support the following operations:
- **enqueue(x)**: Insert an element x at the rear of the queue.
- **dequeue()**: Remove the element from the front of the queue.
- **getFront()**: Return the front element without removing.
- **getMin()**: Return the minimum element in the queue in **O(1) time**.
- **getMax()**: Return the maximum element in the queue in **O(1) time**.

The queries are represented in numeric form:
- `1 x`: Call enqueue(x)
- `2`: Call dequeue()
- `3`: Call getFront()
- `4`: Call getMin()
- `5`: Call getMax()

## **📘 Examples**

### Example 1

```cpp
Input: q = 6, queries[][] = [[1, 4], [1, 2], [3], [4], [2], [5]]
Output: [4, 2, 2]
Explanation: 
enqueue(4): Insert 4 at the rear of the queue.
enqueue(2): Insert 2 at the rear of the queue.
getFront(): return the front element i.e 4
getMin(): return minimum element from the queue i.e 2
dequeue(): Remove the front element 4 from the queue
getMax(): return maximum element from the queue i.e 2
```

### Example 2

```cpp
Input: q = 4, queries[][] = [[1, 3], [4], [1, 5], [5]]
Output: [3, 5]
Explanation: 
enqueue(3): Insert 3 at the rear of the queue.
getMin(): return minimum element from the queue i.e 3
enqueue(5): Insert 5 at the rear of the queue.
getMax(): return maximum element from the queue i.e 5
```

## **🔒 Constraints**

* $1 \le \text{queries.size()} \le 10^5$
* $0 \le \text{values in the queue} \le 10^9$

## **✅ My Approach**

The optimal approach uses **Monotonic Deques** alongside a regular queue to maintain minimum and maximum elements efficiently:

### **Monotonic Deque Technique**

1. **Main Queue**: Use a standard queue to maintain FIFO order for normal queue operations.

2. **Minimum Deque**: Maintain a monotonic increasing deque where:
   - Front element is always the minimum in the current queue
   - Remove elements from back if they are greater than the new element
   - This ensures the deque is always sorted in increasing order

3. **Maximum Deque**: Maintain a monotonic decreasing deque where:
   - Front element is always the maximum in the current queue
   - Remove elements from back if they are smaller than the new element
   - This ensures the deque is always sorted in decreasing order

4. **Enqueue Operation**:
   - Add element to main queue
   - Remove larger elements from minimum deque's back and add current element
   - Remove smaller elements from maximum deque's back and add current element

5. **Dequeue Operation**:
   - Remove front element from main queue
   - If this element is at front of min deque, remove it
   - If this element is at front of max deque, remove it

6. **Query Operations**:
   - getFront(): Return front of main queue
   - getMin(): Return front of minimum deque
   - getMax(): Return front of maximum deque

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(1) amortized for all operations. Each element is added and removed from deques at most once, making the amortized time complexity constant.
* **Expected Auxiliary Space Complexity:** O(n), where n is the number of elements in the queue. We use additional space for the monotonic deques to track min/max elements.

## **🧑‍💻 Code (C++)**

```cpp
class SpecialQueue {
    queue<int> q;
    deque<int> mn, mx;
public:
    void enqueue(int x) {
        q.push(x);
        while (!mn.empty() && mn.back() > x) mn.pop_back();
        mn.push_back(x);
        while (!mx.empty() && mx.back() < x) mx.pop_back();
        mx.push_back(x);
    }
    void dequeue() {
        int f = q.front(); q.pop();
        if (f == mn.front()) mn.pop_front();
        if (f == mx.front()) mx.pop_front();
    }
    int getFront() { return q.front(); }
    int getMin() { return mn.front(); }
    int getMax() { return mx.front(); }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Stack-Based Approach**

### 💡 Algorithm Steps:

1. Use two stacks to simulate queue behavior (input and output stacks).
2. Maintain separate min/max stacks for each input/output stack.
3. Transfer elements between stacks when needed for dequeue operations.
4. Track min/max across both stacks during operations.

```cpp
class SpecialQueue {
    stack<int> in, out, minIn, maxIn, minOut, maxOut;
    void transfer() {
        while (!in.empty()) {
            int x = in.top(); in.pop();
            out.push(x);
            minOut.push(minOut.empty() ? x : min(x, minOut.top()));
            maxOut.push(maxOut.empty() ? x : max(x, maxOut.top()));
        }
        while (!minIn.empty()) minIn.pop();
        while (!maxIn.empty()) maxIn.pop();
    }
public:
    void enqueue(int x) {
        in.push(x);
        minIn.push(minIn.empty() ? x : min(x, minIn.top()));
        maxIn.push(maxIn.empty() ? x : max(x, maxIn.top()));
    }
    void dequeue() {
        if (out.empty()) transfer();
        out.pop(); minOut.pop(); maxOut.pop();
    }
    int getFront() {
        if (out.empty()) transfer();
        return out.top();
    }
    int getMin() {
        int mn = INT_MAX;
        if (!minIn.empty()) mn = min(mn, minIn.top());
        if (!minOut.empty()) mn = min(mn, minOut.top());
        return mn;
    }
    int getMax() {
        int mx = INT_MIN;
        if (!maxIn.empty()) mx = max(mx, maxIn.top());
        if (!maxOut.empty()) mx = max(mx, maxOut.top());
        return mx;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(1) amortized - Each element transferred at most once
* **Auxiliary Space:** 💾 O(n) - Multiple stacks for tracking

### ✅ **Why This Approach?**

* Pure stack-based implementation without deque
* Amortized O(1) for all operations
* Good for environments where deque is not available

## 📊 **3️⃣ Timestamped Monotonic Queue**

### 💡 Algorithm Steps:

1. Use timestamps to handle element removal correctly.
2. Maintain increasing deque for minimum with timestamps.
3. Maintain decreasing deque for maximum with timestamps.
4. Use timestamps to identify which elements to remove during dequeue.

```cpp
class SpecialQueue {
    queue<pair<int,int>> q;
    deque<pair<int,int>> minQ, maxQ;
    int timestamp;
public:
    SpecialQueue() : timestamp(0) {}
    
    void enqueue(int x) {
        q.push({x, timestamp});
        while (!minQ.empty() && minQ.back().first > x) minQ.pop_back();
        minQ.push_back({x, timestamp});
        while (!maxQ.empty() && maxQ.back().first < x) maxQ.pop_back();
        maxQ.push_back({x, timestamp});
        timestamp++;
    }
    
    void dequeue() {
        auto front = q.front(); q.pop();
        if (minQ.front().second == front.second) minQ.pop_front();
        if (maxQ.front().second == front.second) maxQ.pop_front();
    }
    
    int getFront() { return q.front().first; }
    int getMin() { return minQ.front().first; }
    int getMax() { return maxQ.front().first; }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(1) amortized - Each element processed once
* **Auxiliary Space:** 💾 O(n) - Timestamp tracking

### ✅ **Why This Approach?**

* Handles duplicate values correctly with timestamps
* Maintains strict ordering for identical elements
* Robust against edge cases with repeated values

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Deque-Based**               | 🟢 O(1) amortized      | 🟢 O(n)                 | 🚀 Simple and efficient          | 🔧 Requires deque support            |
| 🔍 **Stack-Based**               | 🟢 O(1) amortized      | 🟡 O(n)                 | 📖 Pure stack implementation     | 💾 Higher space overhead             |
| 🔄 **Timestamped**               | 🟢 O(1) amortized      | 🟡 O(n)                 | ⭐ Handles duplicates well       | 🔧 Extra timestamp overhead          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General use case**                              | 🥇 **Deque-Based**                   | ★★★★★                     |
| 📖 **No deque available**                            | 🥈 **Stack-Based**                   | ★★★★☆                     |
| 🎯 **Many duplicates**                               | 🥉 **Timestamped**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class SpecialQueue {
    Queue<Integer> q = new LinkedList<>();
    Deque<Integer> mn = new ArrayDeque<>(), mx = new ArrayDeque<>();
    
    public void enqueue(int x) {
        q.offer(x);
        while (!mn.isEmpty() && mn.peekLast() > x) mn.pollLast();
        mn.offerLast(x);
        while (!mx.isEmpty() && mx.peekLast() < x) mx.pollLast();
        mx.offerLast(x);
    }
    
    public void dequeue() {
        int f = q.poll();
        if (f == mn.peekFirst()) mn.pollFirst();
        if (f == mx.peekFirst()) mx.pollFirst();
    }
    
    public int getFront() { return q.peek(); }
    public int getMin() { return mn.peekFirst(); }
    public int getMax() { return mx.peekFirst(); }
}
```

## **🐍 Code (Python)**

```python
from collections import deque

class SpecialQueue:
    def __init__(self):
        self.q = deque()
        self.mn = deque()
        self.mx = deque()
    
    def enqueue(self, x):
        self.q.append(x)
        while self.mn and self.mn[-1] > x: self.mn.pop()
        self.mn.append(x)
        while self.mx and self.mx[-1] < x: self.mx.pop()
        self.mx.append(x)
    
    def dequeue(self):
        f = self.q.popleft()
        if f == self.mn[0]: self.mn.popleft()
        if f == self.mx[0]: self.mx.popleft()
    
    def getFront(self): return self.q[0]
    def getMin(self): return self.mn[0]
    def getMax(self): return self.mx[0]
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
