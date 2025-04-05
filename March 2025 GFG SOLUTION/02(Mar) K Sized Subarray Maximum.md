# _2. K Sized Subarray Maximum_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1)

## **Problem Description**

Given an **array arr[]** of integers and an integer **k**, your task is to find the **maximum value for each contiguous subarray of size k**. The output should be an array of maximum values corresponding to each contiguous subarray.

## **Examples**

### **Example 1:**

#### **Input:**

`arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6]`  
`k = 3`

#### **Output:**

`[3, 3, 4, 5, 5, 5, 6]`

#### **Explanation:**

1st window: [1, 2, 3], max = 3  
2nd window: [2, 3, 1], max = 3  
3rd window: [3, 1, 4], max = 4  
4th window: [1, 4, 5], max = 5  
5th window: [4, 5, 2], max = 5  
6th window: [5, 2, 3], max = 5  
7th window: [2, 3, 6], max = 6

### **Example 2:**

#### **Input:**

`arr[] = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13]`  
`k = 4`

#### **Output:**

`[10, 10, 10, 15, 15, 90, 90]`

#### **Explanation:**

1st window: [8, 5, 10, 7], max = 10  
2nd window: [5, 10, 7, 9], max = 10  
3rd window: [10, 7, 9, 4], max = 10  
4th window: [7, 9, 4, 15], max = 15  
5th window: [9, 4, 15, 12], max = 15  
6th window: [4, 15, 12, 90], max = 90  
7th window: [15, 12, 90, 13], max = 90

### **Constraints**

- $\(1 \leq \text{arr.size()} \leq 10^6\)$
- $\(1 \leq k \leq \text{arr.size()}\)$
- $\(0 \leq arr[i] \leq 10^9\)$

## **My Approach**

### **Sliding Window Maximum using Deque**

- We maintain a **deque** where each element is an **index**, and the values at those indices are in decreasing order.
- As we iterate through the array, we **add new elements** to the deque and **remove elements that fall out of the current window.**
- The **maximum element of the current window** will always be at the front of the deque.
- This allows us to efficiently compute the maximum for each window in constant time on average.

### **Algorithm Steps:**

1. Initialize a **deque** to store indices.
2. Loop through the array.
3. **Remove elements from the front** of the deque if they are outside the window.
4. **Remove elements from the back** of the deque if they are smaller than the current element (ensuring decreasing order).
5. **Add the current index** to the deque.
6. Once the first window is complete, **append the front element (maximum)** to the result.
7. Continue until all windows are processed.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N)`, because each element is added and removed from the deque at most once.
- **Expected Auxiliary Space Complexity:** `O(K)`, the size of the deque.

## **Code (C++)**

```cpp
class Solution {
public:
    vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < arr.size(); ++i) {
            if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
            while (!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.push_back(arr[dq.front()]);
        }
        return res;
    }
};
```

<details>  
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Using Priority Queue (O(N log K) Time, O(K) Space)**

This approach uses a max-heap to maintain the maximum in each window.

```cpp
class Solution {
public:
    vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < arr.size(); ++i) {
            pq.emplace(arr[i], i);
            if (i >= k - 1) {
                while (pq.top().second <= i - k) pq.pop();
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};
```

🔹 **Pros:** Simpler logic using a priority queue.  
🔹 **Cons:** Slightly slower due to O(log K) insertion/deletion operations.

## **3️⃣ Using Multiset (O(N log K) Time, O(K) Space)**

This approach leverages `multiset` for ordered window maximum.

```cpp
class Solution {
public:
    vector<int> maxOfSubarrays(const vector<int>& arr, int k) {
        vector<int> res;
        multiset<int> window;
        for (int i = 0; i < arr.size(); ++i) {
            window.insert(arr[i]);
            if (i >= k - 1) {
                res.push_back(*window.rbegin());
                window.erase(window.find(arr[i - k + 1]));
            }
        }
        return res;
    }
};
```

🔹 **Pros:** Provides ordered elements inside the window.  
🔹 **Cons:** O(log K) insertion and deletion cause performance overhead.

## **📊 Comparison of Approaches**

| **Approach**        | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**             | ⚠️ **Cons**       |
| ------------------- | ---------------------- | ----------------------- | ----------------------- | ----------------- |
| **Deque (Optimal)** | 🟢 O(N)                | 🟢 O(K)                 | Fastest, minimal memory | None              |
| **Priority Queue**  | 🟡 O(N log K)          | 🟡 O(K)                 | Simple to implement     | Slower than deque |
| **Multiset**        | 🟡 O(N log K)          | 🟡 O(K)                 | Maintains order         | Slower than deque |

## 💡 **Best Choice?**

- ✅ **For optimal performance:** Deque-based approach (O(N) time, O(K) space).
- ✅ **For priority order requirement:** Multiset-based approach.
- ✅ **For easier implementation:** Priority queue approach.

</details>

## **Code (Java)**

```java
class Solution {
    public ArrayList<Integer> maxOfSubarrays(int[] arr, int k) {
        ArrayList<Integer> res = new ArrayList<>();
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 0; i < arr.length; i++) {
            if (!dq.isEmpty() && dq.peekFirst() <= i - k) dq.pollFirst();
            while (!dq.isEmpty() && arr[dq.peekLast()] < arr[i]) dq.pollLast();
            dq.offerLast(i);
            if (i >= k - 1) res.add(arr[dq.peekFirst()]);
        }
        return res;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def maxOfSubarrays(self, arr, k):
        res, dq = [], deque()
        for i in range(len(arr)):
            if dq and dq[0] <= i - k:
                dq.popleft()
            while dq and arr[dq[-1]] < arr[i]:
                dq.pop()
            dq.append(i)
            if i >= k - 1:
                res.append(arr[dq[0]])
        return res
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
