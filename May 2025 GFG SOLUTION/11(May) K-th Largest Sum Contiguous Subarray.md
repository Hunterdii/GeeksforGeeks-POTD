# *11. K-th Largest Sum Contiguous Subarray*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1)

## **🧩 Problem Description**

Given an array `arr[]` of size `n`, find the **sum of the K-th largest** sum among all possible contiguous subarrays of `arr`. In other words, list all contiguous subarray sums, sort them in descending order, and return the K-th element.

## **📘 Examples**

### **Example 1:**

#### **Input:**

```
arr[] = [3, 2, 1],  k = 2
```

#### **Output:**

```
5
```

#### **Explanation:**

All contiguous subarray sums are `[6, 5, 3, 2, 1]`. The 2nd largest is `5`.

### **Example 2:**

#### **Input:**

```
arr[] = [2, 6, 4, 1],  k = 3
```

#### **Output:**

```
11
```

#### **Explanation:**

All sums are `[13, 12, 11, 10, 8, 6, 5, 4, 2, 1]`. The 3rd largest is `11`.

## **🔒 Constraints**

* \$1 \leq n \leq 1000\$
* \$1 \leq k \leq \dfrac{n(n+1)}{2}\$
* \$-10^5 \leq arr\[i] \leq 10^5\$

## **✅ My Approach**

### **Prefix Sums + Min-Heap**

1. **Compute prefix sums** array `P` of length `n+1`, where
   $P[0] = 0,\quad P[i] = P[i-1] + arr[i-1]\quad (1 \le i \le n).$
2. **Use a min-heap** (`priority_queue<int, vector<int>, greater<int>>`) of size up to `k` to keep track of the k largest sums seen so far.
3. **Enumerate all subarrays** by two loops `i` from `0` to `n-1`, `j` from `i+1` to `n`:

   * Compute current sum `S = P[j] - P[i]`.
   * **Push** `S` into the heap; if size exceeds `k`, **pop** the smallest.
4. After processing all, the **top** of the min-heap is the **K-th largest sum**.

## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** \$O(n^2 \log k)\$, due to the double loop over subarrays (\$O(n^2)\$) and heap operations (\$O(\log k)\$).
* **Expected Auxiliary Space Complexity:** \$O(k)\$, for storing at most k sums in the heap.

## **🧠 Code (C++)**

```cpp

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        vector<int> p(arr.size() + 1);
        for (int i = 0; i < arr.size(); ++i) p[i + 1] = p[i] + arr[i];
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j <= arr.size(); ++j) {
                q.push(p[j] - p[i]);
                if (q.size() > k) q.pop();
            }
        return q.top();
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Brute-Force + Sort**

1. **Generate all** \$n(n+1)/2\$ subarray sums using two loops and store them in a vector `V`.
2. **Sort** `V` in descending order.
3. **Return** `V[k-1]`.

```cpp
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> sums;
        sums.reserve(n*(n+1)/2);
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j)
                sums.push_back(accumulate(arr.begin()+i, arr.begin()+j+1, 0));
        sort(sums.begin(), sums.end(), greater<int>());
        return sums[k-1];
    }
};
```

* **Time:** \$O(n^2 + n^2\log n^2) = O(n^2 \log n)\$
* **Space:** \$O(n^2)\$

## 📊 **3️⃣ Max-Heap Extraction**

1. **Push** all subarray sums into a **max-heap**.
2. **Pop** the heap `k-1` times.
3. The next **top** is the answer.

```cpp
class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> P(n+1,0);
        for(int i=1;i<=n;++i) P[i]=P[i-1]+arr[i-1];
        priority_queue<int> maxHeap;
        for(int i=0;i<n;++i)
            for(int j=i+1;j<=n;++j)
                maxHeap.push(P[j]-P[i]);
        while(--k) maxHeap.pop();
        return maxHeap.top();
    }
};
```

* **Time:** \$O(n^2 + k\log(n^2))\$
* **Space:** \$O(n^2)\$

## 🆚 **Comparison of Approaches**

| **Approach**        | ⏱️ **Time**      | 🗂️ **Space** | ✅ **Pros**                   | ⚠️ **Cons**                        |
| ------------------- | ---------------- | ------------- | ---------------------------- | ---------------------------------- |
| Prefix + Min-Heap   | 🟢 O(n² log k)      | 🟢 O(k)          | Uses limited extra space     | Still \$O(n^2)\$ enumeration       |
| Brute-Force + Sort  | 🟡 O(n² log n)      | 🟡 O(n²)         | Simple to implement          | High memory for storing all sums   |
| Max-Heap Extraction | 🔸 O(n² + k log n²) | 🟡 O(n²)         | Conceptually straightforward | Uses large heap of size \$O(n^2)\$ |

### ✅ **Best Choice?**

| **Scenario**                          | **Recommended Approach** |
| ------------------------------------- | ------------------------ |
| Moderate n, small k (k ≪ n²)          | 🥇 Prefix + Min-Heap        |
| Very small n (store all sums cheaply) | 🥈 Brute-Force + Sort       |
| k close to n² (need many pops)        | 🥉 Max-Heap Extraction      |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public static int kthLargest(int[] arr, int k) {
        int[] p = new int[arr.length + 1];
        for (int i = 0; i < arr.length; ++i) p[i + 1] = p[i] + arr[i];
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (int i = 0; i < arr.length; ++i)
            for (int j = i + 1; j <= arr.length; ++j) {
                q.add(p[j] - p[i]);
                if (q.size() > k) q.poll();
            }
        return q.peek();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def kthLargest(self, arr, k) -> int:
        p = [0]
        for x in arr: p.append(p[-1] + x)
        q = []
        for i in range(len(arr)):
            for j in range(i + 1, len(arr) + 1):
                heapq.heappush(q, p[j] - p[i])
                if len(q) > k: heapq.heappop(q)
        return q[0]
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
