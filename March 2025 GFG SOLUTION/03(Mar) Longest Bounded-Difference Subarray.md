# _3. Longest Bounded-Difference Subarray_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1)

## **Problem Description**

Given an array of positive integers `arr[]` and a non-negative integer `x`, the task is to find the **longest sub-array** where the absolute difference between any two elements is not greater than `x`.

If multiple such subarrays exist, return the one that **starts at the smallest index**.

## **Examples**

### Example 1

#### Input

```
arr[] = [8, 4, 2, 6, 7]
x = 4
```

#### Output

```
[4, 2, 6]
```

#### Explanation

- The sub-array [4, 2, 6] has no pair of elements with absolute difference greater than 4.
- Other subarrays either don't meet the condition or are shorter.

### Example 2

#### Input

```
arr[] = [15, 10, 1, 2, 4, 7, 2]
x = 5
```

#### Output

```
[2, 4, 7, 2]
```

#### Explanation

- The sub-array described by indexes [3..6], i.e. [2, 4, 7, 2] contains no such difference of two elements which is greater than 5.

### **Constraints**

- $1 \leq N \leq 10^5$
- $1 \leq arr[i] \leq 10^9$
- $0 \leq x \leq 10^9$

## **My Approach**

### **Sliding Window with Deque**

This approach uses **two deques** to dynamically maintain the **minimum and maximum elements** within the sliding window.

- **minQ** tracks the **minimum values** in the current window.
- **maxQ** tracks the **maximum values** in the current window.
- If `maxQ.front() - minQ.front()` exceeds `x`, we shrink the window from the left.
- At every step, we check if the current window length is the longest valid window seen so far.

### **Steps:**

1. Initialize `start` pointer and two deques: `minQ` (for minimum) and `maxQ` (for maximum).
2. Expand the window by adding the current element to both deques.
3. If the difference between max and min exceeds `x`, shrink the window by incrementing `start`.
4. Track the **longest valid window** and its starting position.
5. Return the subarray corresponding to the longest valid window.

## **Time and Auxiliary Space Complexity**

| Complexity           | Analysis                                                                |
| -------------------- | ----------------------------------------------------------------------- |
| **Time Complexity**  | `O(N)` - Each element is pushed and popped from the deque at most once. |
| **Space Complexity** | `O(N)` - In the worst case, both deques can hold all indices.           |

## **Code (C++)**

```cpp
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> minQ, maxQ;
        int n = arr.size(), start = 0, resStart = 0, resEnd = 0;
        for (int end = 0; end < n; end++) {
            while (!minQ.empty() && arr[minQ.back()] > arr[end]) minQ.pop_back();
            while (!maxQ.empty() && arr[maxQ.back()] < arr[end]) maxQ.pop_back();
            minQ.push_back(end), maxQ.push_back(end);
            while (arr[maxQ.front()] - arr[minQ.front()] > x) {
                if (minQ.front() == start) minQ.pop_front();
                if (maxQ.front() == start) maxQ.pop_front();
                start++;
            }
            if (end - start > resEnd - resStart) resStart = start, resEnd = end;
        }
        return vector<int>(arr.begin() + resStart, arr.begin() + resEnd + 1);
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Using Ordered Set (O(N log N) Time, O(N) Space)**

### Key Idea

- Use a **`multiset`** to dynamically maintain the window elements.
- Get the **min** and **max** in constant time using `*begin()` and `*rbegin()`.
- Shrink the window if the max-min difference exceeds `x`.

```cpp
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        multiset<int> window;
        int start = 0, resStart = 0, resLen = 0;
        for (int end = 0; end < arr.size(); end++) {
            window.insert(arr[end]);
            while (*window.rbegin() - *window.begin() > x) window.erase(window.find(arr[start++]));
            if (end - start + 1 > resLen) resStart = start, resLen = end - start + 1;
        }
        return vector<int>(arr.begin() + resStart, arr.begin() + resStart + resLen);
    }
};
```

## **3️⃣ Brute Force (O(N²) Time, O(1) Space)**

### Key Idea

- For every subarray `arr[i..j]`, check the max and min values and verify the condition.
- This is only feasible for small arrays.

```cpp
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size(), maxLen = 0, resStart = 0;
        for (int i = 0; i < n; i++) {
            int minVal = arr[i], maxVal = arr[i];
            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]), maxVal = max(maxVal, arr[j]);
                if (maxVal - minVal > x) break;
                if (j - i + 1 > maxLen) resStart = i, maxLen = j - i + 1;
            }
        }
        return vector<int>(arr.begin() + resStart, arr.begin() + resStart + maxLen);
    }
};
```

## **📊 Comparison of Approaches**

| **Approach**                         | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**             | ⚠️ **Cons**                |
| ------------------------------------ | ---------------------- | ----------------------- | ----------------------- | -------------------------- |
| **Sliding Window + Deque (Optimal)** | 🟢 O(N)                | 🟢 O(N)                 | Fastest for all cases   | Slightly complex           |
| **Ordered Set (Multiset)**           | 🟡 O(N log N)          | 🟡 O(N)                 | Elegant window handling | Slower than deque          |
| **Brute Force**                      | 🔴 O(N²)               | 🟢 O(1)                 | Simple to implement     | Very slow for large arrays |

## 💡 **Best Choice?**

- ✅ **For optimal performance:** Sliding Window + Monotonic Deque (O(N) time, O(N) space).
- ✅ **For simpler code:** Ordered Set is easier than deques.
- ✅ **For small inputs:** Brute Force is acceptable for $N \leq 100$.

</details>

## **Code (Java)**

```java
class Solution {
    public ArrayList<Integer> longestSubarray(int[] arr, int x) {
        Deque<Integer> minQ = new ArrayDeque<>(), maxQ = new ArrayDeque<>();
        int n = arr.length, start = 0, resStart = 0, resLen = 0;
        for (int end = 0; end < n; end++) {
            while (!minQ.isEmpty() && arr[minQ.peekLast()] > arr[end]) minQ.pollLast();
            while (!maxQ.isEmpty() && arr[maxQ.peekLast()] < arr[end]) maxQ.pollLast();
            minQ.addLast(end);
            maxQ.addLast(end);
            while (arr[maxQ.peekFirst()] - arr[minQ.peekFirst()] > x) {
                if (minQ.peekFirst() == start) minQ.pollFirst();
                if (maxQ.peekFirst() == start) maxQ.pollFirst();
                start++;
            }
            if (end - start + 1 > resLen) {
                resStart = start;
                resLen = end - start + 1;
            }
        }
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = resStart; i < resStart + resLen; i++) res.add(arr[i]);
        return res;
    }
}
```

## **Code (Python)**

```python
from collections import deque

class Solution:
    def longestSubarray(self, arr, x):
        minQ, maxQ, start, resStart, resEnd = deque(), deque(), 0, 0, 0
        for end in range(len(arr)):
            while minQ and arr[minQ[-1]] > arr[end]: minQ.pop()
            while maxQ and arr[maxQ[-1]] < arr[end]: maxQ.pop()
            minQ.append(end), maxQ.append(end)
            while arr[maxQ[0]] - arr[minQ[0]] > x:
                if minQ[0] == start: minQ.popleft()
                if maxQ[0] == start: maxQ.popleft()
                start += 1
            if end - start > resEnd - resStart: resStart, resEnd = start, end
        return arr[resStart:resEnd + 1]
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
