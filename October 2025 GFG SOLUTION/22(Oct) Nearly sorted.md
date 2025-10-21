---
title: "🔢 Nearly Sorted | GFG Solution 🔍"
keywords🏷️: ["🔢 nearly sorted", "🔍 min heap", "📍 priority queue", "📈 sorting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Nearly Sorted Array problem: efficiently sort an array where each element is at most k positions away from its target position using min heap. 🚀"
date: 📅 2025-10-22
---

# *22. Nearly Sorted*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1)

## **🧩 Problem Description**

You are given an array `arr[]`, where each element is at most `k` positions away from its correct position in the sorted order. Your task is to restore the sorted order of `arr[]` by rearranging the elements in place.

**Note:** Don't use any sort() method.

A nearly sorted array is one where each element is displaced by at most k positions from where it would be in a fully sorted array. The goal is to efficiently sort this array by leveraging this property.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 3, 1, 4], k = 2
Output: [1, 2, 3, 4]
Explanation: All elements are at most k = 2 positions away from their correct positions.
Element 1 moves from index 2 to 0
Element 2 moves from index 0 to 1
Element 3 moves from index 1 to 2
Element 4 stays at index 3
```

### Example 2

```cpp
Input: arr[] = [7, 9, 14], k = 1
Output: [7, 9, 14]
Explanation: All elements are already stored in the sorted order.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $0 \le k < \text{arr.size()}$
* $1 \le \text{arr}[i] \le 10^6$

## **✅ My Approach**

The optimal approach uses a **Min Heap (Priority Queue)** to efficiently sort the nearly sorted array by maintaining a window of k+1 elements:

### **Min Heap Approach**

1. **Initialize Min Heap:**
   * Create a min heap and insert the first k+1 elements from the array.
   * These k+1 elements contain the smallest element that should be placed at index 0.

2. **Process Remaining Elements:**
   * For each remaining element in the array:
     * Extract the minimum from the heap and place it at the current sorted position.
     * Insert the next element from the array into the heap.
     * This maintains a sliding window of k+1 elements.

3. **Empty the Heap:**
   * After processing all elements, extract remaining elements from the heap.
   * Place them in their correct sorted positions.

4. **Key Insight:**
   * Since each element is at most k positions away, the smallest element in any window of k+1 consecutive elements belongs at the start of that window.
   * Using a min heap ensures O(log k) insertion and extraction operations.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log k), where n is the size of the array. We perform n insertions and n deletions on a heap of maximum size k+1, each operation taking O(log k) time.
* **Expected Auxiliary Space Complexity:** O(k), as the min heap stores at most k+1 elements at any given time. This is constant relative to the array size when k is small.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    void nearlySorted(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + k);
        int idx = 0;
        for (int i = k; i < arr.size(); i++) {
            pq.push(arr[i]);
            arr[idx++] = pq.top();
            pq.pop();
        }
        while (!pq.empty()) {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Insertion Sort Optimized**

### 💡 Algorithm Steps:

1. Use insertion sort with limited backward search up to k positions.
2. Each element is compared with at most k previous elements.
3. Insert element at correct position within its k-range window.
4. Efficiently sorts the nearly sorted array in-place.

```cpp
class Solution {
public:
    void nearlySorted(vector<int> &arr, int k) {
        for (int i = 1; i < arr.size(); i++) {
            int key = arr[i], j = i - 1;
            while (j >= max(0, i - k - 1) && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*k) - Each element moves at most k positions
* **Auxiliary Space:** 💾 O(1) - In-place sorting

### ✅ **Why This Approach?**

* No extra space required for data structures
* Simple implementation without heap operations
* Works well when k is very small

## 📊 **3️⃣ STL Partial Sort**

### 💡 Algorithm Steps:

1. Divide array into overlapping chunks of size 2k+1.
2. Sort each chunk using STL sort function.
3. Elements settle into their correct positions due to overlap.
4. Handles the nearly sorted property efficiently.

```cpp
class Solution {
public:
    void nearlySorted(vector<int> &arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i += k + 1) {
            int end = min(i + 2 * k + 1, n);
            sort(arr.begin() + i, arr.begin() + end);
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*k*log(k)) - Sorting overlapping chunks
* **Auxiliary Space:** 💾 O(1) - In-place sorting

### ✅ **Why This Approach?**

* Leverages highly optimized STL sort
* Easy to implement and understand
* Good balance between simplicity and performance

## 📊 **4️⃣ Multiset Window Approach**

### 💡 Algorithm Steps:

1. Maintain a sliding window of k+1 elements using multiset.
2. Extract minimum from multiset and place in sorted position.
3. Add new element and remove oldest from window.
4. Balanced tree structure ensures efficient operations.

```cpp
class Solution {
public:
    void nearlySorted(vector<int> &arr, int k) {
        multiset<int> ms;
        int n = arr.size(), idx = 0;
        for (int i = 0; i <= min(k, n - 1); i++) ms.insert(arr[i]);
        for (int i = k + 1; i < n; i++) {
            arr[idx] = *ms.begin();
            ms.erase(ms.begin());
            ms.insert(arr[i]);
            idx++;
        }
        while (!ms.empty()) {
            arr[idx++] = *ms.begin();
            ms.erase(ms.begin());
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*log(k)) - Balanced tree operations
* **Auxiliary Space:** 💾 O(k) - Multiset storage

### ✅ **Why This Approach?**

* Maintains sorted order automatically
* Efficient insertion and deletion
* Good alternative to priority queue

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Min Heap**                   | 🟢 O(n*log(k))         | 🟡 O(k)                 | 🚀 Optimal for large arrays       | 💾 Extra space for heap              |
| 🔧 **Insertion Sort**             | 🟡 O(n*k)              | 🟢 O(1)                 | 📦 No extra space                 | 🐌 Slower for large k                |
| 📊 **Partial Sort**               | 🟡 O(n*k*log(k))       | 🟢 O(1)                 | 🎯 Simple implementation          | 🔧 Not optimal complexity            |
| 🌲 **Multiset**                   | 🟢 O(n*log(k))         | 🟡 O(k)                 | ⚖️ Self-balancing structure       | 💾 Similar space as heap             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General purpose optimal**                        | 🥇 **Min Heap**                      | ★★★★★                     |
| 📦 **Memory constrained**                             | 🥈 **Insertion Sort**                | ★★★★☆                     |
| 🎯 **Small k values**                                 | 🥉 **Insertion Sort**                | ★★★★★                     |
| 🔄 **Need sorted structure**                          | 🏅 **Multiset**                      | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public void nearlySorted(int[] arr, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int idx = 0, n = arr.length;
        for (int i = 0; i <= Math.min(k, n - 1); i++) pq.add(arr[i]);
        for (int i = k + 1; i < n; i++) {
            arr[idx++] = pq.poll();
            pq.add(arr[i]);
        }
        while (!pq.isEmpty()) arr[idx++] = pq.poll();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def nearlySorted(self, arr, k):
        import heapq
        h = arr[:min(k + 1, len(arr))]
        heapq.heapify(h)
        idx = 0
        for i in range(k + 1, len(arr)):
            arr[idx] = heapq.heappop(h)
            heapq.heappush(h, arr[i])
            idx += 1
        while h:
            arr[idx] = heapq.heappop(h)
            idx += 1
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
