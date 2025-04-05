# _14. Nearly Sorted_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1)

> **Note:** I'm currently in the middle of my exams until November 19, so I’ll be uploading daily POTD solutions, but not at a fixed time. Apologies for any inconvenience, and thank you for your patience!

## Problem Description

Given an array `arr[]`, where each element is at most `k` positions away from its target position in a sorted array, sort the array in place.

You are expected to achieve this without using the built-in sorting functions.

### Examples:

**Input:**

```
arr[] = [6, 5, 3, 2, 8, 10, 9]
k = 3
```

**Output:**

```
[2, 3, 5, 6, 8, 9, 10]
```

**Explanation:**  
Since each element is at most 3 positions away from its target, sorting is achieved by rearranging the elements within this bound.

**Input:**

```
arr[] = [1, 4, 5, 2, 3, 6, 7, 8, 9, 10]
k = 2
```

**Output:**

```
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
```

**Explanation:**  
The sorted array will be `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]`.

## My Approach

1. **Using a Min-Heap for Efficient Sorting:**

   - As each element is at most `k` positions from its target, we can maintain a min-heap of size `k + 1` while iterating through the array. This ensures that the smallest of the `k+1` elements is always at the top of the heap and ready to be placed in its correct position.
   - Traverse the array and maintain the heap with the next `k + 1` elements. Once the heap is of size `k + 1`, pop the smallest element from the heap and place it at the current index.
   - After processing all elements, empty the heap into the array to complete the sorted order.

2. **Edge Cases:**
   - If `k` is 0, the array is already sorted.
   - If `k` is greater than or equal to the array size, perform a standard sort since elements may not be within close proximity.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n log k), where `n` is the size of the array and `k` is the given distance from the correct position. Sorting is optimized by using a heap of size `k + 1`, making each insertion and deletion O(log k).
- **Expected Auxiliary Space Complexity:** O(k), as we maintain a min-heap of size `k + 1` to sort elements within this distance constraint.

## Code (C++)

```cpp
class Solution {
public:
    void nearlySorted(std::vector<int>& arr, int k) {
        if (k == 0) return;

        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int i = 0; i <= k && i < arr.size(); ++i) {
            minHeap.push(arr[i]);
        }

        int index = 0;

        for (int i = k + 1; i < arr.size(); ++i) {
            arr[index++] = minHeap.top();
            minHeap.pop();
            minHeap.push(arr[i]);
        }

        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};
```

## Code (Java)

```java
class Solution {
    public void nearlySorted(int[] arr, int k) {
        if (k == 0) return;

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int i = 0; i <= k && i < arr.length; i++) {
            minHeap.add(arr[i]);
        }

        int index = 0;

        for (int i = k + 1; i < arr.length; i++) {
            arr[index++] = minHeap.poll();
            minHeap.add(arr[i]);
        }

        while (!minHeap.isEmpty()) {
            arr[index++] = minHeap.poll();
        }
    }
}
```

## Code (Python)

```python
import heapq

class Solution:
    def nearlySorted(self, arr, k):
        if k == 0:
            return
        minHeap = []
        for i in range(min(k + 1, len(arr))):
            heapq.heappush(minHeap, arr[i])

        index = 0
        for i in range(k + 1, len(arr)):
            arr[index] = heapq.heappop(minHeap)
            index += 1
            heapq.heappush(minHeap, arr[i])
        while minHeap:
            arr[index] = heapq.heappop(minHeap)
            index += 1
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
