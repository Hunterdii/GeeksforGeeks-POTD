---
title: "🏹 Tywin's War Strategy | GFG Solution 🎯"
keywords🏷️: ["🏹 tywin's war", "🎯 greedy algorithm", "📈 priority queue", "🔢 modular arithmetic", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Tywin's War Strategy problem: find minimum soldiers to add to make at least ⌈n/2⌉ troops lucky using greedy approach with priority queue. 🚀"
date: 📅 2025-08-13
---

# *13. Tywin's War Strategy*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/tywins-war-strategy0527/1)

## **🧩 Problem Description**

You are given an array `arr[]` of size `n`, where `arr[i]` represents the number of soldiers in the i-th troop. You are also given an integer `k`. A troop is considered **"lucky"** if its number of soldiers is a multiple of `k`. Find the minimum total number of soldiers to add across all troops so that at least **⌈n / 2⌉** troops become lucky.

## **📘 Examples**

### Example 1

```cpp
Input: arr = [5, 6, 3, 2, 1], k = 2
Output: 1
Explanation: By adding 1 soldier for the troop with 1 soldier, we get [5, 6, 3, 2, 2]. 
Now 3 out of 5 troops (6, 2, and 2) are multiples of 2 that satisfy the requirement.
```

### Example 2

```cpp
Input: arr = [3, 5, 6, 7, 9, 10], k = 4
Output: 4
Explanation: We need at least 3 lucky troops since ⌈6 / 2⌉ = 3. Currently, no troop is divisible by 4.
Add 1 soldier for troop 3 → 4,
Add 2 for troop 6 → 8,
Add 1 for troop 7 → 8.
New array: [4, 5, 8, 8, 9, 10] with 3 lucky troops (4, 8, 8).
Total soldiers added = 4.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le k \le 10^5$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses a **Greedy Algorithm** with **Priority Queue (Min-Heap)** to select the troops with minimum cost to make lucky:

### **Greedy + Priority Queue Algorithm**

1. **Calculate Cost for Each Troop:**
   * For each troop with `arr[i]` soldiers, calculate the cost to make it lucky.
   * If `arr[i] % k == 0`, cost = 0 (already lucky).
   * Otherwise, cost = `k - (arr[i] % k)` (soldiers needed to reach next multiple of k).

2. **Use Min-Heap:**
   * Store all costs in a priority queue (min-heap).
   * This allows us to always pick the troop with minimum cost to make lucky.

3. **Select Minimum Troops:**
   * We need at least `⌈n/2⌉` troops to be lucky.
   * Pop the smallest costs from the heap exactly `⌈n/2⌉` times.

4. **Return Total Cost:**
   * Sum all the popped costs to get the minimum total soldiers needed.

### **Key Insight:**
To minimize the total soldiers added, we should prioritize making troops lucky that require the fewest additional soldiers. This greedy approach guarantees the optimal solution.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. Building the priority queue takes O(n log n) time, and extracting ⌈n/2⌉ minimum elements takes O((n/2) log n) time.
* **Expected Auxiliary Space Complexity:** O(n), as we store all n cost values in the priority queue for efficient minimum extraction.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size(), need = (n + 1) / 2, total = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : arr) pq.push(x % k ? k - x % k : 0);
        while (need--) total += pq.top(), pq.pop();
        return total;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Vector Sort Approach**

### 💡 Algorithm Steps:

1. Calculate cost for each soldier to reach nearest multiple of k
2. Store all costs in a vector and sort in ascending order
3. Sum the smallest (n+1)/2 costs for minimum total cost
4. Return the accumulated sum as the final answer

```cpp
class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        vector<int> costs;
        int need = (arr.size() + 1) / 2;
        for (int x : arr) costs.push_back(x % k ? k - x % k : 0);
        nth_element(costs.begin(), costs.begin() + need - 1, costs.end());
        return accumulate(costs.begin(), costs.begin() + need, 0);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Using nth_element for partial sorting
* **Auxiliary Space:** 💾 O(n) - Additional vector for costs

### ✅ **Why This Approach?**

* Uses nth_element for better average performance
* More memory efficient than priority queue
* Cleaner code with STL algorithms

## 📊 **3️⃣ In-Place Modification**

### 💡 Algorithm Steps:

1. Modify the original array to store costs directly
2. Use partial_sort to get only the required smallest elements
3. Sum the first (n+1)/2 elements after partial sorting
4. Achieve space optimization by reusing input array

```cpp
class Solution {
public:
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size(), need = (n + 1) / 2;
        for (int& x : arr) x = x % k ? k - x % k : 0;
        partial_sort(arr.begin(), arr.begin() + need, arr.end());
        return accumulate(arr.begin(), arr.begin() + need, 0);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log need) - Partial sorting optimization
* **Auxiliary Space:** 💾 O(1) - In-place modification

### ✅ **Why This Approach?**

* Space optimal with O(1) auxiliary space
* Faster than full sorting for small need values
* Modifies input which may be acceptable in some contexts

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Priority Queue**             | 🟢 O(n log n)          | 🟡 O(n)                 | 🚀 Clean heap operations          | 💾 Extra space for queue             |
| 🔍 **Vector Sort**                 | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Optimal average time           | 💾 Additional vector storage         |
| 📊 **In-Place**                   | 🟢 O(n log need)       | 🟢 O(1)                 | 💾 Space efficient               | 🔧 Modifies input array              |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal time complexity**                        | 🥇 **Vector Sort (nth_element)**     | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Priority Queue**                | ★★★★☆                     |
| 🔧 **Memory constraints**                             | 🥉 **In-Place Modification**         | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minSoldiers(int[] arr, int k) {
        int need = (arr.length + 1) / 2, total = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int x : arr) pq.offer(x % k == 0 ? 0 : k - x % k);
        while (need-- > 0) total += pq.poll();
        return total;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minSoldiers(self, arr, k):
        import heapq
        need, costs = (len(arr) + 1) // 2, []
        for x in arr: heapq.heappush(costs, 0 if x % k == 0 else k - x % k)
        return sum(heapq.heappop(costs) for _ in range(need))
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
