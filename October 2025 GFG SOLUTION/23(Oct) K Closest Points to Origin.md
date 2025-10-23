---
title: "🎯 K Closest Points to Origin | GFG Solution 📍"
keywords🏷️: ["🎯 k closest points", "📍 distance calculation", "🔄 nth_element", "⚡ quickselect", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the K Closest Points to Origin problem: find k nearest points to origin using efficient selection algorithms like nth_element, sorting, and heaps. 🚀"
date: 📅 2025-10-23
---

# *23. K Closest Points to Origin*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1)

## **🧩 Problem Description**

Given an integer `k` and an array of points `points[][]`, where each point is represented as `points[i] = [xi, yi]` on the X-Y plane, return the **k closest points** to the origin `(0, 0)`.

The distance between two points on the X-Y plane is the **Euclidean distance**, defined as:

**distance = sqrt((x2 - x1)² + (y2 - y1)²)**

You can return the k closest points in any order. The driver code will print them in sorted order. Test cases are generated such that there will be a unique answer.

## **📘 Examples**

### Example 1

```cpp
Input: k = 2, points[] = [[1, 3], [-2, 2], [5, 8], [0, 1]]
Output: [[-2, 2], [0, 1]]
Explanation: The Euclidean distances from the origin are:
Point (1, 3) = sqrt(10)
Point (-2, 2) = sqrt(8)
Point (5, 8) = sqrt(89)
Point (0, 1) = sqrt(1)
The two closest points to the origin are [-2, 2] and [0, 1].
```

### Example 2

```cpp
Input: k = 1, points = [[2, 4], [-1, -1], [0, 0]]
Output: [[0, 0]]
Explanation: The Euclidean distances from the origin are:
Point (2, 4) = sqrt(20)
Point (-1, -1) = sqrt(2)
Point (0, 0) = sqrt(0)
The closest point to origin is (0, 0).
```

## **🔒 Constraints**

* $1 \le k \le \text{points.size()} \le 10^5$
* $-3 \times 10^4 \le x_i, y_i \le 3 \times 10^4$

## **✅ My Approach**

The optimal approach uses **STL's nth_element** algorithm for efficient partial sorting:

### **nth_element with Lambda Comparator**

1. **Calculate Distance:**
   * For each point, the squared Euclidean distance from origin is `x² + y²`.
   * We avoid computing square roots since comparing squared distances preserves ordering.

2. **Partial Sorting with nth_element:**
   * Use `nth_element` to partition the array such that the k smallest elements (by distance) are placed before position k.
   * The algorithm rearranges elements so that:
     - Elements before position k are ≤ the element at position k
     - Elements after position k are ≥ the element at position k
   * No full sorting is required, making it more efficient than complete sort.

3. **Custom Comparator:**
   * Lambda function compares squared distances: `a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1]`
   * This ensures points are ordered by their proximity to origin.

4. **Extract Result:**
   * Return the first k elements from the rearranged array.
   * These k elements are guaranteed to be the k closest points.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n) on average, where n is the number of points. The `nth_element` algorithm uses introselect (a hybrid of quickselect and heapselect), which has linear average-case performance. In the worst case, it can be O(n log n), but this is rare with good pivot selection.
* **Expected Auxiliary Space Complexity:** O(1), as `nth_element` performs in-place partitioning without requiring additional data structures. Only a constant amount of space is used for variables and the lambda function.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k, points.end(),
            [](auto& a, auto& b) { return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1]; });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Min Heap Approach**

### 💡 Algorithm Steps:

1. Push all points with their squared distances into a min heap.
2. Extract the first k elements from the heap.
3. These k elements are the closest points to the origin.
4. Return the result vector containing these k points.

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        for(int i = 0; i < points.size(); i++)
            minHeap.push({points[i][0]*points[i][0]+points[i][1]*points[i][1], i});
        vector<vector<int>> res;
        while(k--) {
            res.push_back(points[minHeap.top().second]);
            minHeap.pop();
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Building heap and extracting k elements
* **Auxiliary Space:** 💾 O(n) - Space for heap storage

### ✅ **Why This Approach?**

* Straightforward heap-based solution
* Natural ordering of elements by distance
* Good when k is close to n

## 📊 **3️⃣ Sorting Approach**

### 💡 Algorithm Steps:

1. Calculate squared distance for each point.
2. Sort all points based on their distance from origin.
3. Take the first k points from the sorted array.
4. Return these k points as the result.

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting operation dominates
* **Auxiliary Space:** 💾 O(1) - In-place sorting

### ✅ **Why This Approach?**

* Clean and simple implementation
* Modifies input array in-place
* Easy to understand logic

## 📊 **4️⃣ Quickselect Partition**

### 💡 Algorithm Steps:

1. Use quickselect algorithm to partition array around kth element.
2. Recursively partition until k closest elements are on the left side.
3. No need to fully sort the array, just partition correctly.
4. Return the first k elements after partitioning.

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        function<void(int,int)> quickselect = [&](int l, int r) {
            if(l >= r) return;
            int p = l, i = l;
            for(int j = l; j < r; j++)
                if(points[j][0]*points[j][0]+points[j][1]*points[j][1] < points[r][0]*points[r][0]+points[r][1]*points[r][1])
                    swap(points[i++], points[j]);
            swap(points[i], points[r]);
            if(i < k) quickselect(i+1, r);
            else if(i > k) quickselect(l, i-1);
        };
        quickselect(0, points.size()-1);
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) average, O(n²) worst - Quickselect partitioning
* **Auxiliary Space:** 💾 O(log n) - Recursion stack space

### ✅ **Why This Approach?**

* Better average time complexity than sorting
* Efficient for large datasets with small k
* Classic selection algorithm pattern

## 📊 **5️⃣ Max Heap (Original Approach)**

### 💡 Algorithm Steps:

1. Maintain a max heap of size k to store the k closest points.
2. For each point, calculate its squared distance.
3. If heap size is less than k, insert the point directly.
4. Otherwise, compare with the farthest point in heap (top element) and replace if current point is closer.

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        for(auto& p : points) {
            int dist = p[0]*p[0] + p[1]*p[1];
            if(maxHeap.size() < k) maxHeap.push({dist, p});
            else if(dist < maxHeap.top().first) {
                maxHeap.pop();
                maxHeap.push({dist, p});
            }
        }
        vector<vector<int>> res;
        while(!maxHeap.empty()) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k) - Each insertion/deletion in heap of size k takes log k time
* **Auxiliary Space:** 💾 O(k) - Heap stores at most k elements

### ✅ **Why This Approach?**

* Space-efficient when k is small compared to n
* Optimal for streaming data or when n is very large
* Maintains only k elements at any time

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **nth_element**                | 🟢 O(n) avg            | 🟢 O(1)                 | 🚀 Optimal average performance    | 🔧 Modifies input array              |
| 🔺 **Min Heap**                   | 🟡 O(n log n)          | 🟡 O(n)                 | 📖 Clear heap semantics           | 💾 Extra space for heap              |
| 📊 **Sorting**                    | 🟡 O(n log n)          | 🟢 O(1)                 | 🎯 Simple and clean               | 🐌 Overkill for partial sorting      |
| ⚡ **Quickselect**                | 🟢 O(n) avg            | 🟢 O(log n)             | ⭐ Good average performance       | 🔧 Complex implementation            |
| 🏔️ **Max Heap**                   | 🟢 O(n log k)          | 🟢 O(k)                 | 💾 Space-efficient for small k    | 🐌 Slower when k ≈ n                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **nth_element**                   | ★★★★★                     |
| 📖 **Need all sorted**                                | 🥈 **Sorting**                       | ★★★★☆                     |
| 🔧 **Cannot modify input**                            | 🥉 **Min Heap**                      | ★★★☆☆                     |
| 🎯 **Large n, small k**                               | 🏅 **Max Heap**                      | ★★★★★                     |
| 💡 **Interview/Competitive**                          | 🎖️ **Quickselect**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<ArrayList<Integer>> kClosest(int[][] points, int k) {
        Arrays.sort(points, (a, b) -> (a[0]*a[0] + a[1]*a[1]) - (b[0]*b[0] + b[1]*b[1]));
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        for (int i = 0; i < k; i++)
            res.add(new ArrayList<>(Arrays.asList(points[i][0], points[i][1])));
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def kClosest(self, points, k):
        points.sort(key=lambda x: x[0]**2 + x[1]**2)
        return points[:k]
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
