# *16. Smallest Range in K Lists*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1)


## **🧩 Problem Description**

You are given a 2D integer array `arr[][]` of size `k × n`, where each row contains `n` sorted integers. Your task is to find the smallest range `[l, r]` that includes **at least one element from each of the `k` lists**.

If multiple such ranges exist, return the one that occurs first in the traversal.


## **📘 Examples**

### **Example 1:**

**Input:**
`n = 5, k = 3`

`arr = [[4, 7, 9, 12, 15], [0, 8, 10, 14, 20], [6, 12, 16, 30, 50]]`

**Output:** `[6, 8]`

**Explanation:**
One element from each list: 7 (1st list), 8 (2nd list), 6 (3rd list) → range = \[6, 8].


### **Example 2:**

**Input:**
`n = 5, k = 3`

`arr = [[1, 3, 5, 7, 9], [0, 2, 4, 6, 8], [2, 3, 5, 7, 11]]`

**Output:** `[1, 2]`

**Explanation:**
Range includes: 1 (list1), 2 (list2 and list3) → range = \[1, 2].


### **Example 3:**

**Input:**
`n = 2, k = 3`

`arr = [[2, 4], [1, 7], [20, 40]]`

**Output:** `[4, 20]`

**Explanation:**
Smallest range covering 3 lists: 4 (1st), 7 (2nd), 20 (3rd) → range = \[4, 20].


## **🔒 Constraints**

* \$1 \leq k, n \leq 500\$
* \$0 \leq arr\[i]\[j] \leq 10^5\$


## **✅ My Approach**

### **Min Heap + Sliding Maximum**

We maintain a **min heap** (priority queue) to always get the smallest current value among the heads of each list.
At the same time, we keep track of the **maximum** among the current elements, to compute the range.
We slide the window by popping the minimum element and inserting the next element from its respective list.


### **Algorithm Steps:**

1. Initialize a min heap with the first element of each row (along with row and col indices).
2. Keep track of the maximum of the current elements.
3. In each iteration:

   * Pop the minimum element from the heap.
   * Update the best range `[lo, hi]` if `(hi - min) < (r - l)`.
   * Push the next element from the same row into the heap.
   * If any row is exhausted, terminate.
4. Return the best `[lo, hi]`.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n \* k \* log k), since we insert and remove `n × k` elements into a heap of size `k` and heap operations cost `log k`.
* **Expected Auxiliary Space Complexity:** O(k), for the heap storing one element per list.


## **🧠 Code (C++)**

```cpp
class Solution {
public:
    struct Node {
        int v, r, c;
        bool operator>(const Node& o) const { return v > o.v; }
    };
    vector<int> findSmallestRange(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), hi = INT_MIN, lo = 0, r = 1e9;
        priority_queue<Node, vector<Node>, greater<Node>> q;
        for (int i = 0; i < n; i++) q.push({a[i][0], i, 0}), hi = max(hi, a[i][0]);
        while (1) {
            auto x = q.top(); q.pop();
            if (hi - x.v < r - lo) lo = x.v, r = hi;
            if (x.c + 1 == m) break;
            int y = a[x.r][x.c + 1];
            q.push({y, x.r, x.c + 1});
            hi = max(hi, y);
        }
        return {lo, r};
    }
};
```


## **🧑‍💻 Code (Java)**

```java
class Solution {
    static class Node {
        int v, r, c;
        Node(int v, int r, int c) { this.v = v; this.r = r; this.c = c; }
    }
    public ArrayList<Integer> findSmallestRange(int[][] a) {
        int n = a.length, m = a[0].length, hi = Integer.MIN_VALUE, lo = 0, r = Integer.MAX_VALUE;
        PriorityQueue<Node> q = new PriorityQueue<>((x, y) -> x.v - y.v);
        for (int i = 0; i < n; i++) {
            q.add(new Node(a[i][0], i, 0));
            hi = Math.max(hi, a[i][0]);
        }
        while (true) {
            Node x = q.poll();
            if (hi - x.v < r - lo) { lo = x.v; r = hi; }
            if (x.c + 1 == m) break;
            int y = a[x.r][x.c + 1];
            q.add(new Node(y, x.r, x.c + 1));
            hi = Math.max(hi, y);
        }
        return new ArrayList<>(Arrays.asList(lo, r));
    }
}
```

## **🐍 Code (Python)**

```python
import heapq

class Solution:
    def findSmallestRange(self, a):
        n, m = len(a), len(a[0])
        hi = max(row[0] for row in a)
        q = [(a[i][0], i, 0) for i in range(n)]
        heapq.heapify(q)
        lo, r = 0, float('inf')
        while True:
            x, i, j = heapq.heappop(q)
            if hi - x < r - lo: lo, r = x, hi
            if j + 1 == m: break
            y = a[i][j + 1]
            heapq.heappush(q, (y, i, j + 1))
            hi = max(hi, y)
        return [lo, r]
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
