---
Difficulty: Hard
Source: 160 Days of Problem Solving
Tags:
  - Heap
  - Design-Pattern
---

# 🚀 _Day 4. Find median in a stream_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/find-median-in-a-stream-1587115620)

## 💡 **Problem Description:**

Given a **data stream** `arr[]`, where integers are read sequentially, determine the **median** of the elements encountered **so far** after each new integer is read.

### **Rules for Median Calculation:**

1. If the number of elements is **odd**, the median is the **middle** element.
2. If the number of elements is **even**, the median is the **average** of the two middle elements.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```cpp
arr = [5, 15, 1, 3, 2, 8]
```

#### **Output:**

```cpp
[5.0, 10.0, 5.0, 4.0, 3.0, 4.0]
```

#### **Explanation:**

1. Read `5` → median = `5.0`
2. Read `15` → median = `(5 + 15) / 2 = 10.0`
3. Read `1` → median = `5.0`
4. Read `3` → median = `(3 + 5) / 2 = 4.0`
5. Read `2` → median = `3.0`
6. Read `8` → median = `(3 + 5) / 2 = 4.0`

### **Constraints:**

- $\(1 \leq \text{Number of elements} \leq 10^5\)$
- $\(1 \leq arr[i] \leq 10^6\)$

## 🎯 **My Approach:**

## **Min-Heap & Max-Heap**

### **Key Idea:**

- Use **two heaps** to maintain the **lower half** and **upper half** of elements efficiently.
- **Max-Heap (Left Half)** → Stores the **smaller half** of the elements.
- **Min-Heap (Right Half)** → Stores the **larger half** of the elements.
- The **median** is either:
  - **The max of the left half (if odd elements)**
  - **The average of max(left half) and min(right half) (if even elements)**

## **Algorithm Steps:**

1. **Insert each number** into either **max-heap** or **min-heap**:
   - If `maxHeap` is empty OR `num <= maxHeap.top()`, push into `maxHeap`.
   - Else, push into `minHeap`.
2. **Balance the heaps**:
   - If `maxHeap` is larger than `minHeap` by more than 1, move top of `maxHeap` to `minHeap`.
   - If `minHeap` is larger, move top of `minHeap` to `maxHeap`.
3. **Calculate the median**:
   - If `maxHeap` has more elements, return `maxHeap.top()`.
   - Else, return `(maxHeap.top() + minHeap.top()) / 2.0`.

## 🕒 **Time and Auxiliary Space Complexity**

- **Time Complexity:** \(O(N \log N)\) (heap insertions & balancing)
- **Auxiliary Space Complexity:** \(O(N)\) (for storing elements in heaps)

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
public:
    vector<double> getMedian(vector<int>& arr) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<double> res;

        for (int num : arr) {
            if (maxHeap.empty() || num <= maxHeap.top()) maxHeap.push(num);
            else minHeap.push(num);

            if (maxHeap.size() > minHeap.size() + 1) minHeap.push(maxHeap.top()), maxHeap.pop();
            else if (minHeap.size() > maxHeap.size()) maxHeap.push(minHeap.top()), minHeap.pop();

            res.push_back(maxHeap.size() > minHeap.size() ? maxHeap.top() : (maxHeap.top() + minHeap.top()) / 2.0);
        }
        return res;
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Balanced BST (O(N log N) Time, O(N) Space)**

1. Use **Balanced BST (TreeSet in Java, SortedList in Python)**.
2. Keep two halves of elements.
3. Median = **Middle Element (odd) / Average of Two (even).**

```cpp
class Solution {
public:
    multiset<int> left, right;

    void insert(int num) {
        if (left.empty() || num <= *left.rbegin()) left.insert(num);
        else right.insert(num);

        if (left.size() > right.size() + 1) right.insert(*left.rbegin()), left.erase(prev(left.end()));
        else if (right.size() > left.size()) left.insert(*right.begin()), right.erase(right.begin());
    }

    vector<double> getMedian(vector<int>& arr) {
        vector<double> res;
        for (int num : arr) {
            insert(num);
            res.push_back(left.size() > right.size() ? *left.rbegin() : (*left.rbegin() + *right.begin()) / 2.0);
        }
        return res;
    }
};
```

🔹 **Pros:** Balanced approach, works well for dynamic insertions.  
🔹 **Cons:** Slightly slower than heaps due to extra balancing.

## **3️⃣ Brute Force (O(N²) Time, O(N) Space)**

1. Sort list every time a new element arrives.
2. Find median from sorted list.

```cpp
class Solution {
public:
    vector<double> getMedian(vector<int>& arr) {
        vector<int> sorted;
        vector<double> res;

        for (int num : arr) {
            sorted.insert(lower_bound(sorted.begin(), sorted.end(), num), num);
            int n = sorted.size();
            res.push_back(n % 2 ? sorted[n / 2] : (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0);
        }
        return res;
    }
};
```

🔹 **Pros:** Simple and easy to understand.  
🔹 **Cons:** **Very slow (`O(N²)`)**, impractical for large data.

## **📊 Comparison of Approaches**

| **Approach**               | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**               |
| -------------------------- | ---------------------- | ----------------------- | ---------------------------------- | ------------------------- |
| **Heap (Priority Queue)**  | 🟢 `O(N log N)`        | 🟡 `O(N)`               | Best runtime & simple to implement | Uses extra space          |
| **Balanced BST (TreeSet)** | 🟡 `O(N log N)`        | 🟡 `O(N)`               | Balanced and good for dynamic data | Slightly slower           |
| **Brute Force (Sorting)**  | 🔴 `O(N²)`             | 🟡 `O(N)`               | Simple & easy to understand        | **Very slow for large N** |

## **💡 Best Choice?**

- ✅ **For best efficiency:** **Min-Heap (`O(N log N)`)**.
- ✅ **For handling dynamic updates:** **Balanced BST (`O(N log N)`)**.
- ✅ **For small input sizes:** **Brute Force (`O(N²)`)**.

</details>

## **Code (Java)**

```java
class Solution {
    public ArrayList<Double> getMedian(int[] arr) {
        PriorityQueue<Integer> maxH = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minH = new PriorityQueue<>();
        ArrayList<Double> res = new ArrayList<>();

        for (int n : arr) {
            maxH.add(n);
            minH.add(maxH.poll());
            if (maxH.size() < minH.size()) maxH.add(minH.poll());
            res.add(maxH.size() > minH.size() ? (double) maxH.peek() : (maxH.peek() + minH.peek()) / 2.0);
        }
        return res;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def getMedian(self, arr):
        maxHeap, minHeap = [], []
        res = []

        for num in arr:
            heapq.heappush(maxHeap, -num)
            heapq.heappush(minHeap, -heapq.heappop(maxHeap))

            if len(maxHeap) < len(minHeap):
                heapq.heappush(maxHeap, -heapq.heappop(minHeap))

            res.append(float(-maxHeap[0]) if len(maxHeap) > len(minHeap) else (-maxHeap[0] + minHeap[0]) / 2.0)

        return res
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
