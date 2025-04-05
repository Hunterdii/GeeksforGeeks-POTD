# **11. Minimum Cost of Ropes**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1)

### Problem Description

Given an array `arr` containing the lengths of different ropes, we need to connect these ropes to form one rope. The cost to connect two ropes is equal to the sum of their lengths. The task is to connect all the ropes with the minimum cost.

### Example:

Input:

```
arr[] = [4, 3, 2, 6]
```

Output:

```
29
```

Explanation:

- First, connect ropes of lengths 2 and 3, resulting in [4, 5, 6]. The cost of this operation is `2 + 3 = 5`.
- Then, connect ropes of lengths 4 and 5, resulting in [9, 6]. The cost of this operation is `4 + 5 = 9`.
- Finally, connect the last two ropes. The cost is `9 + 6 = 15`.

The total cost for connecting all ropes is `5 + 9 + 15 = 29`.

### My Approach

1. **Using a Min-Heap:**

   - The key idea is to use a **min-heap** to always connect the two smallest ropes at each step to minimize the overall cost.
   - Convert the array `arr` into a min-heap.
   - Repeatedly pop the two smallest elements, calculate their sum, add this sum to the total cost, and push the sum back into the heap.

2. **Procedure:**

   - Initialize a min-heap with the array elements.
   - While there are more than one rope in the heap:
     - Extract the two smallest ropes.
     - Calculate the cost to connect them and add this to the total cost.
     - Push the combined rope back into the heap.
   - Repeat until only one rope remains.

3. **Final Answer:**
   - The total accumulated cost is the minimum cost to connect all ropes.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log n), where `n` is the number of ropes. Building the heap takes O(n), and each extraction and insertion operation takes O(log n), so the total complexity is O(n log n).
- **Expected Auxiliary Space Complexity:** O(n), since we use a heap to store the ropes.

### Code (C++)

```cpp
class Solution {
public:
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr.begin(), arr.end());
        long long totalCost = 0;
        while (minHeap.size() > 1) {
            long long first = minHeap.top(); minHeap.pop();
            long long second = minHeap.top(); minHeap.pop();
            long long cost = first + second;
            totalCost += cost;
            minHeap.push(cost);
        }
        return totalCost;
    }
};
```

### Code (Java)

```java
class Solution {
    public long minCost(long[] arr) {
        PriorityQueue<Long> minHeap = new PriorityQueue<>();
        for (long num : arr) {
            minHeap.add(num);
        }
        long totalCost = 0;
        while (minHeap.size() > 1) {
            long first = minHeap.poll();
            long second = minHeap.poll();
            long cost = first + second;
            totalCost += cost;
            minHeap.add(cost);
        }

        return totalCost;
    }
}
```

### Code (Python)

```python
import heapq

class Solution:
    def minCost(self, arr):
        heapq.heapify(arr)
        totalCost = 0
        while len(arr) > 1:
            first = heapq.heappop(arr)
            second = heapq.heappop(arr)
            cost = first + second
            totalCost += cost
            heapq.heappush(arr, cost)

        return totalCost
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
