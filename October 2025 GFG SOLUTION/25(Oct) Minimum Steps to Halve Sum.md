---
title: "⚖️ Minimum Steps to Halve Sum | GFG Solution 🔍"
keywords🏷️: ["⚖️ minimum operations", "🔍 greedy algorithm", "📍 priority queue", "📈 heap", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Steps to Halve Sum problem: find minimum operations to reduce array sum to half or less by repeatedly halving the largest element using greedy heap approach. 🚀"
date: 📅 2025-10-25
---

# *25. Minimum Steps to Halve Sum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-steps-to-halve-sum/1)

## **🧩 Problem Description**

You are given an array `arr[]` consisting of positive integers. Your task is to find the **minimum number of operations** required to make the sum of its elements **less than or equal to half** of the original sum. In one operation, you may replace any element with half of its value (with floating-point precision).

The goal is to minimize the number of operations needed to achieve this target sum by strategically choosing which elements to halve.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [8, 6, 2]
Output: 3
Explanation: Initial sum = (8 + 6 + 2) = 16, half = 8
Halve 8 → arr[] = [4, 6, 2], sum = 12 (still 12 > 8)
Halve 6 → arr[] = [4, 3, 2], sum = 9 (still 9 > 8)
Halve 4 → arr[] = [2, 3, 2], sum = 7 (now 7 < 8)
Hence, 3 operations are needed.
```

### Example 2

```cpp
Input: arr[] = [9, 1, 2]
Output: 2
Explanation: Initial sum = 12, half = 6
Halve 9 → arr[] = [4.5, 1, 2], sum = 7.5 (still > 6)
Halve 4.5 → arr[] = [2.25, 1, 2], sum = 5.25 ≤ 6
Hence, 2 operations are needed.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses a **Greedy Algorithm** with a **Max Heap (Priority Queue)** to efficiently achieve the minimum operations:

### **Greedy Heap Strategy**

1. **Calculate Target:**
   * Compute the total sum of all array elements.
   * Calculate target as half of the total sum.
   * Store the target value for comparison.

2. **Build Max Heap:**
   * Insert all array elements into a max heap (priority queue).
   * This allows efficient retrieval of the largest element in O(log n) time.

3. **Greedy Selection:**
   * Always select the largest element from the heap (greedy choice).
   * Halving the largest element gives maximum reduction in sum per operation.
   * This ensures minimum total operations needed.

4. **Iterative Halving:**
   * Extract the maximum element from heap.
   * Divide it by 2 and subtract half from current sum.
   * Push the halved value back into heap.
   * Increment operation counter.

5. **Termination Condition:**
   * Continue until current sum becomes less than or equal to target.
   * Return the total number of operations performed.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. Building the heap takes O(n) time, and each of the k operations (where k can be up to n in worst case) involves heap extraction and insertion, each taking O(log n) time. The total complexity is dominated by O(k log n) which is O(n log n) in the worst case.
* **Expected Auxiliary Space Complexity:** O(n), as we store all array elements in the priority queue (heap). The heap maintains at most n elements at any given time, requiring linear additional space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minOperations(vector<int>& arr) {
        double s = accumulate(arr.begin(), arr.end(), 0.0), t = s / 2;
        priority_queue<double> q(arr.begin(), arr.end());
        int ops = 0;
        while (s > t) {
            double x = q.top(); q.pop();
            s -= x / 2;
            q.push(x / 2);
            ops++;
        }
        return ops;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Manual Heap with Vector**

### 💡 Algorithm Steps:

1. Calculate total sum and target as half of total sum.
2. Build max heap manually using make_heap on vector.
3. Repeatedly extract maximum, halve it, and reinsert into heap.
4. Continue until current sum is less than or equal to target.

```cpp
class Solution {
public:
    int minOperations(vector<int>& arr) {
        double s = 0, t;
        vector<double> h;
        for (int x : arr) {
            s += x;
            h.push_back(x);
        }
        t = s / 2;
        make_heap(h.begin(), h.end());
        int ops = 0;
        while (s > t) {
            pop_heap(h.begin(), h.end());
            double x = h.back();
            h.pop_back();
            x /= 2;
            s -= x;
            h.push_back(x);
            push_heap(h.begin(), h.end());
            ops++;
        }
        return ops;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Heap operations for each halving
* **Auxiliary Space:** 💾 O(n) - Vector for heap storage

### ✅ **Why This Approach?**

* Direct control over heap operations
* Uses standard STL heap algorithms
* Flexible for custom comparators

## 📊 **3️⃣ Multiset Approach**

### 💡 Algorithm Steps:

1. Insert all elements into multiset for auto-sorting.
2. Extract largest element from end of multiset.
3. Halve and reinsert into multiset automatically maintaining order.
4. Count operations until sum is halved.

```cpp
class Solution {
public:
    int minOperations(vector<int>& arr) {
        double s = 0;
        multiset<double> ms;
        for (int x : arr) {
            s += x;
            ms.insert(x);
        }
        double t = s / 2;
        int ops = 0;
        while (s > t) {
            auto it = prev(ms.end());
            double x = *it;
            ms.erase(it);
            x /= 2;
            s -= x;
            ms.insert(x);
            ops++;
        }
        return ops;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Balanced tree operations
* **Auxiliary Space:** 💾 O(n) - Multiset storage

### ✅ **Why This Approach?**

* Self-balancing data structure
* Automatic ordering maintenance
* Clean and readable code

## 📊 **4️⃣ Greedy with Sorting**

### 💡 Algorithm Steps:

1. Sort array in descending order initially.
2. Keep halving the largest element until target is reached.
3. Use insertion to maintain sorted order after each halving.
4. Track operations count throughout the process.

```cpp
class Solution {
public:
    int minOperations(vector<int>& arr) {
        double s = 0;
        vector<double> v;
        for (int x : arr) {
            s += x;
            v.push_back(x);
        }
        double t = s / 2;
        sort(v.rbegin(), v.rend());
        int ops = 0;
        while (s > t) {
            double x = v[0];
            v.erase(v.begin());
            x /= 2;
            s -= x;
            v.insert(lower_bound(v.begin(), v.end(), x, greater<double>()), x);
            ops++;
        }
        return ops;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² log n) - Repeated insertions in sorted vector
* **Auxiliary Space:** 💾 O(n) - Vector storage

### ✅ **Why This Approach?**

* Straightforward greedy implementation
* Easy to debug and visualize
* Good for small input sizes

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1115 test cases due to time constraints).

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Priority Queue**              | 🟢 O(n log n)          | 🟡 O(n)                 | 🚀 Optimal for greedy             | 💾 Extra heap structure              |
| 🔧 **Manual Heap**                 | 🟢 O(n log n)          | 🟡 O(n)                 | 🎯 Fine-grained control           | 🔧 More verbose code                 |
| 🌳 **Multiset**                    | 🟢 O(n log n)          | 🟡 O(n)                 | ⭐ Clean implementation           | 🔧 Slower constant factors           |
| 📊 **Greedy Sorting (TLE)**        | 🔴 O(n² log n)         | 🟡 O(n)                 | 📖 Intuitive logic                | 🐌 Inefficient insertions            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Priority Queue**                | ★★★★★                     |
| 📖 **Code readability priority**                      | 🥈 **Multiset**                      | ★★★★☆                     |
| 🔧 **Learning heap operations**                       | 🥉 **Manual Heap**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minOperations(int[] arr) {
        double s = 0, t;
        PriorityQueue<Double> q = new PriorityQueue<>(Collections.reverseOrder());
        for (int x : arr) {
            s += x;
            q.offer((double) x);
        }
        t = s / 2;
        int ops = 0;
        while (s > t) {
            double x = q.poll();
            s -= x / 2;
            q.offer(x / 2);
            ops++;
        }
        return ops;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minOperations(self, arr):
        import heapq
        s = sum(arr)
        t = s / 2
        h = [-x for x in arr]
        heapq.heapify(h)
        ops = 0
        while s > t:
            x = -heapq.heappop(h)
            s -= x / 2
            heapq.heappush(h, -x / 2)
            ops += 1
        return ops
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
