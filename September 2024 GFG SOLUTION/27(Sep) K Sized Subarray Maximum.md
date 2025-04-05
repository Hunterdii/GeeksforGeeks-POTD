# _27. K Sized Subarray Maximum_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1)

### Problem Description

Given an array `arr[]` and an integer `k`, find the maximum for each and every contiguous subarray of size `k`.

#### Examples:

**Example 1:**

Input:  
`k = 3`, `arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6]`

Output:  
`[3, 3, 4, 5, 5, 5, 6]`

Explanation:

1. 1st contiguous subarray = [1, 2, 3], max = 3
2. 2nd contiguous subarray = [2, 3, 1], max = 3
3. 3rd contiguous subarray = [3, 1, 4], max = 4
4. 4th contiguous subarray = [1, 4, 5], max = 5
5. 5th contiguous subarray = [4, 5, 2], max = 5
6. 6th contiguous subarray = [5, 2, 3], max = 5
7. 7th contiguous subarray = [2, 3, 6], max = 6

### My Approach

1. **Max Heap Approach**:
   - We use a max heap to keep track of the maximum elements in the current window of size `k`.
   - For every element in the array, we push it into the heap along with its index. If the maximum element’s index is outside the current window, we remove it from the heap.
   - After the window reaches size `k`, we store the maximum element for that window.
2. **Efficiency**:
   - The sliding window moves from left to right over the array, ensuring we keep track of the maximum elements efficiently without recomputing the maximum for each new subarray.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* log k), where `n` is the length of the array and `k` is the window size. We insert and remove elements from the heap in logarithmic time.
- **Expected Auxiliary Space Complexity:** O(k), since we use a heap of size `k` to store elements from the current window.

### Code (C++)

```cpp
class Solution {
public:
    std::vector<int> max_of_subarrays(int k, const std::vector<int>& arr) {
        std::vector<int> res;
        std::priority_queue<std::pair<int, int>> maxHeap;

        for (int i = 0; i < arr.size(); ++i) {
            maxHeap.push({arr[i], i});
            while (maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }
            if (i >= k - 1) {
                res.push_back(maxHeap.top().first);
            }
        }

        return res;
    }
};
```

### Code (Java)

```java
class Solution {
    public ArrayList<Integer> max_of_subarrays(int k, int arr[]) {
        ArrayList<Integer> res = new ArrayList<>();
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return b[0] - a[0];
            }
        });

        for (int i = 0; i < arr.length; ++i) {
            maxHeap.offer(new int[]{arr[i], i});
            while (maxHeap.peek()[1] <= i - k) {
                maxHeap.poll();
            }
            if (i >= k - 1) {
                res.add(maxHeap.peek()[0]);
            }
        }

        return res;
    }
}
```

### Code (Python)

```python
import heapq

class Solution:
    def max_of_subarrays(self, k, arr):
        res = []
        maxHeap = []

        for i in range(len(arr)):
            heapq.heappush(maxHeap, (-arr[i], i))
            while maxHeap[0][1] <= i - k:
                heapq.heappop(maxHeap)
            if i >= k - 1:
                res.append(-maxHeap[0][0])

        return res
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
