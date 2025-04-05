---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Sorting
  - Heap
  - Mathematical
  - priority-queue
  - Divide and Conquer
  - Geometric
  - Arrays
---

# 🚀 _Day 2. K Closest Points to Origin_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/k-closest-points-to-origin--172242)

## 💡 **Problem Description:**

Given an array of points where each point is represented as **points[i] = [xi, yi]** on the **X-Y plane** and an integer **k**, return the **k closest points** to the origin **(0, 0)**.

The distance between two points on the **X-Y plane** is defined as:  
$\text{distance} = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2}$  
You may return the **k closest points in any order**. The driver code will sort them before printing.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

k = 2, points[] = **[[1, 3], [-2, 2], [5, 8], [0, 1]]**

#### **Output:**

**[[-2, 2], [0, 1]]**

#### **Explanation:**

The Euclidean distances from the origin **(0,0)** are:

- Point (1,3) = **√10**
- Point (-2,2) = **√8**
- Point (5,8) = **√89**
- Point (0,1) = **√1**

The **two closest points** to the origin are **[-2,2]** and **[0,1]**.

### **Example 2:**

#### **Input:**

k = 1, points = **[[2, 4], [-1, -1], [0, 0]]**

#### **Output:**

**[[0, 0]]**

#### **Explanation:**

The Euclidean distances from the origin **(0,0)** are:

- Point (2,4) = **√20**
- Point (-1,-1) = **√2**
- Point (0,0) = **√0**

The **closest point** to the origin is **(0,0)**.

### **Constraints:**

- $\( 1 \leq k \leq \text{points.size()} \leq 10^5 \)$
- $\( -10^4 \leq x_i, y_i \leq 10^4 \)$

## 🎯 **My Approach:**

### **Partial Sort using `nth_element` (O(N + K log K) Time, O(1) Space)**

1. We need to **find the k closest points** to the origin based on their **Euclidean distance**.
2. Instead of sorting the entire array (which takes **O(N log N)**), we can use **`nth_element`** which partially sorts the array in **O(N + K log K)** time.
3. The **first k elements** in the sorted range will be the k closest points.
4. Since **we don’t need exact sorting**, `nth_element` is much more efficient than a full sort.

### **Algorithm Steps:**

1. **Use `nth_element`** to place the k closest points at the beginning of the array.
2. **Extract the first k points** and return them as the result.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** **O(N + K log K)**, since `nth_element` partially sorts the array.
- **Expected Auxiliary Space Complexity:** **O(1)**, as sorting is done in place without extra memory.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        nth_element(p.begin(), p.begin() + k, p.end(), [](auto&a, auto&b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        });
        return {p.begin(), p.begin()+k};
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches (C++)</h2></summary>

## **2️⃣ Min-Heap Approach (O(N log K) Time, O(K) Space)**

1. Use a **max-heap** of size **k** to store the k closest points.
2. **Iterate through all points**, pushing them into the heap.
3. If the heap size exceeds k, remove the **farthest point**.
4. At the end, the heap contains the k closest points.

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (auto& a : p) {
            int d = a[0] * a[0] + a[1] * a[1];
            pq.push({d, a});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()) res.push_back(pq.top().second), pq.pop();
        return res;
    }
};
```

🔹 **Pros:** Efficient for streaming data.  
🔹 **Cons:** Uses extra space (`O(K)`).

## **3️⃣ Sorting Approach (O(N log N) Time, O(1) Space)**

1. **Sort all points** based on their **Euclidean distance**.
2. **Pick the first k points**.

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        sort(p.begin(), p.end(), [](auto& a, auto& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(p.begin(), p.begin() + k);
    }
};
```

🔹 **Pros:** Simple to implement.  
🔹 **Cons:** Inefficient for large `N`.

## **📊 Comparison of Approaches**

| **Approach**                  | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ⚡ **Method** | ✅ **Pros**                     | ⚠️ **Cons**        |
| ----------------------------- | ---------------------- | ----------------------- | ------------- | ------------------------------- | ------------------ |
| **Optimized Partial Sort**    | 🟢 `O(N + K log K)`    | 🟢 `O(1)`               | `nth_element` | Best runtime & space efficiency | None               |
| **Min-Heap (Priority Queue)** | 🟡 `O(N log K)`        | 🟡 `O(K)`               | Heap-based    | Good for streaming data         | Extra space usage  |
| **Sorting Approach**          | 🔴 `O(N log N)`        | 🟢 `O(1)`               | Sorting       | Simple & easy to implement      | Slow for large `N` |

## **💡 Best Choice?**

- ✅ **For best efficiency:** **Partial Sort (`O(N + K log K)`, `O(1)`)**.
- ✅ **For real-time data processing:** **Min-Heap (`O(N log K)`, `O(K)`)**.
- ✅ **For simplicity:** **Sorting Approach (`O(N log N)`, `O(1)`)**.

</details>

## **Code (Java)**

```java
class Solution {
    public int[][] kClosest(int[][] p, int k) {
        Arrays.sort(p, Comparator.comparingInt(a -> a[0] * a[0] + a[1] * a[1]));
        return Arrays.copyOfRange(p, 0, k);
    }
}
```

## **Code (Python)**

```python
class Solution:
    def kClosest(self, p: list[list[int]], k: int) -> list[list[int]]:
        return sorted(p, key=lambda a: a[0]**2 + a[1]**2)[:k]
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
