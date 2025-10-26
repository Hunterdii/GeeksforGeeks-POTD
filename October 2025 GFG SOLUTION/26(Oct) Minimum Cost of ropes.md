---
title: "🔗 Minimum Cost of Ropes | GFG Solution 🎯"
keywords🏷️: ["🔗 minimum cost", "🌳 min heap", "⚡ greedy algorithm", "📊 priority queue", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Cost of Ropes problem: find minimum total cost to connect all ropes using greedy approach with min-heap. 🚀"
date: 📅 2025-10-26
---

# *26. Minimum Cost of Ropes*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)

## **🧩 Problem Description**

You are given an array `arr[]` of rope lengths. Your task is to connect all ropes into a single rope with the **minimum total cost**. The cost to connect two ropes is equal to the sum of their lengths.

The goal is to find the optimal order of connecting ropes to minimize the total cost of all connections.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation: First connect 2 and 3 to get [4, 5, 6] with a cost of 5, then connect 4 and 5 
to get [9, 6] with a cost of 9, and finally connect 9 and 6 to get one rope with a cost of 15, 
giving a total minimum cost of 29.
```

### Example 2

```cpp
Input: arr[] = [4, 2, 7, 6, 9]
Output: 62
Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost = 6. 
Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost = 12. 
Then, add 7 and 9, which makes the array [12, 16]. Cost = 16. 
Finally, add these two which gives [28]. Cost = 28.
Total cost = 6 + 12 + 16 + 28 = 62.
```

### Example 3

```cpp
Input: arr[] = [10]
Output: 0
Explanation: Since there is only one rope, no connections are needed, so the cost is 0.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses a **Greedy Algorithm** with a **Min-Heap (Priority Queue)** to efficiently select and combine the smallest ropes:

### **Greedy Min-Heap Strategy**

1. **Initialize Min-Heap:**
   * Insert all rope lengths into a min-heap (priority queue).
   * This allows us to extract the two smallest ropes in O(log n) time.

2. **Greedy Selection:**
   * Always extract the two smallest ropes from the heap.
   * This ensures minimum cost at each step (greedy choice property).

3. **Combine and Update:**
   * Calculate cost as the sum of the two smallest ropes.
   * Add this cost to the total result.
   * Push the combined rope length back into the heap.

4. **Repeat Until One Rope:**
   * Continue the process until only one rope remains in the heap.
   * The accumulated cost represents the minimum total cost.

5. **Why Greedy Works:**
   * Combining smallest ropes first minimizes the number of times larger ropes are added.
   * Each rope contributes to the cost based on how many times it's involved in combinations.
   * This follows the optimal substructure property of Huffman coding.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the number of ropes. Building the heap takes O(n), and we perform n-1 extract-min and insert operations, each taking O(log n) time.
* **Expected Auxiliary Space Complexity:** O(n), as we store all rope lengths in the priority queue (min-heap).

## **🧑‍💻 Code (C)**

```c
void heapify(int arr[], int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapify(arr, n, smallest);
    }
}

int minCost(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    int res = 0, size = n;
    while (size > 1) {
        int first = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(arr, size, 0);
        int second = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(arr, size, 0);
        int sum = first + second;
        res += sum;
        arr[size] = sum;
        size++;
        heapify(arr, size, 0);
    }
    return res;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        int res = 0;
        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            res += first + second;
            pq.push(first + second);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Queue Greedy Approach**

### 💡 Algorithm Steps:

1. Sort the array initially to have elements in ascending order.
2. Use two queues: first queue holds original sorted elements, second queue holds computed sums.
3. At each step, pick the two minimum values from the front of both queues.
4. The sums are naturally sorted in the second queue, maintaining efficiency.
5. Continue until only one element remains across both queues.

```cpp
class Solution {
public:
    int minCost(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        queue<int> q1, q2;
        for (int x : arr) q1.push(x);
        int res = 0;
        while (q1.size() + q2.size() > 1) {
            int first = INT_MAX, second = INT_MAX;
            if (!q1.empty() && (q2.empty() || q1.front() <= q2.front())) {
                first = q1.front(); q1.pop();
            } else {
                first = q2.front(); q2.pop();
            }
            if (!q1.empty() && (q2.empty() || q1.front() <= q2.front())) {
                second = q1.front(); q1.pop();
            } else {
                second = q2.front(); q2.pop();
            }
            int sum = first + second;
            res += sum;
            q2.push(sum);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting once, then linear queue operations for n-1 merges
* **Auxiliary Space:** 💾 O(n) - Two queues to store elements

### ✅ **Why This Approach?**

* Elegant greedy solution without heap operations.
* Exploits the natural ordering property of computed sums.
* Linear-time operations after initial sorting.

## 📊 **3️⃣ Multiset Approach**

### 💡 Algorithm Steps:

1. Insert all rope lengths into a multiset for automatic sorting using balanced BST.
2. Extract the two smallest elements from the beginning of the multiset.
3. Calculate their sum, add to result, and insert back into the multiset.
4. The multiset automatically maintains sorted order after each insertion.
5. Continue until only one element remains in the structure.

```cpp
class Solution {
public:
    int minCost(vector<int>& arr) {
        multiset<int> ms(arr.begin(), arr.end());
        int res = 0;
        while (ms.size() > 1) {
            auto it = ms.begin();
            int first = *it;
            ms.erase(it);
            it = ms.begin();
            int second = *it;
            ms.erase(it);
            res += first + second;
            ms.insert(first + second);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Each insertion and deletion in balanced BST is O(log n)
* **Auxiliary Space:** 💾 O(n) - Multiset storage for all elements

### ✅ **Why This Approach?**

* Balanced BST provides automatic sorting after each operation.
* Clean and readable code structure.
* Good alternative when STL priority queue is not preferred.

## 📊 **4️⃣ Manual Min-Heap Implementation**

### 💡 Algorithm Steps:

1. Build a min-heap from the input array in-place using heapify operations.
2. Extract two minimum elements by swapping with the last element and reducing heap size.
3. Apply heapify after each extraction to maintain the min-heap property.
4. Calculate sum of extracted elements, add to result.
5. Insert the sum back into heap and heapify to restore heap structure.

```cpp
class Solution {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && arr[l] < arr[smallest]) smallest = l;
        if (r < n && arr[r] < arr[smallest]) smallest = r;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(arr, n, smallest);
        }
    }
    
    int minCost(vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
        int res = 0, size = n;
        while (size > 1) {
            int first = arr[0];
            arr[0] = arr[--size];
            heapify(arr, size, 0);
            int second = arr[0];
            arr[0] = arr[--size];
            heapify(arr, size, 0);
            int sum = first + second;
            res += sum;
            arr[size++] = sum;
            heapify(arr, size, 0);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Building heap is O(n), and n-1 extract-min and insert operations each take O(log n)
* **Auxiliary Space:** 💾 O(1) - In-place heap operations without extra data structures

### ✅ **Why This Approach?**

* No STL dependencies needed for heap operations.
* Space-efficient in-place solution.
* Excellent for understanding heap mechanics and low-level implementation.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Priority Queue**             | 🟢 O(n log n)          | 🟡 O(n)                 | 🚀 STL optimized, fastest         | 💾 Extra heap space                   |
| 🔍 **Two-Queue Greedy**           | 🟢 O(n log n)          | 🟡 O(n)                 | 📖 Elegant greedy pattern         | 🔧 More complex queue logic           |
| 📊 **Multiset**                   | 🟢 O(n log n)          | 🟡 O(n)                 | 🎯 Clean BST solution             | 🐌 Slightly slower than heap          |
| 🔄 **Manual Min-Heap**            | 🟢 O(n log n)          | 🟢 O(1)                 | ⭐ Space optimal                  | 🔧 More code to maintain              |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Best overall performance**                       | 🥇 **Priority Queue**                | ★★★★★                     |
| 📖 **Creative greedy solution**                       | 🥈 **Two-Queue Greedy**              | ★★★★☆                     |
| 🔧 **BST-based alternative**                          | 🥉 **Multiset**                      | ★★★★☆                     |
| 🎯 **Memory constrained environments**                | 🏅 **Manual Min-Heap**               | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static int minCost(int[] arr) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : arr) pq.add(x);
        int res = 0;
        while (pq.size() > 1) {
            int sum = pq.poll() + pq.poll();
            res += sum;
            pq.add(sum);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
import heapq

class Solution:
    def minCost(self, arr):
        heapq.heapify(arr)
        res = 0
        while len(arr) > 1:
            sum_val = heapq.heappop(arr) + heapq.heappop(arr)
            res += sum_val
            heapq.heappush(arr, sum_val)
        return res
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
