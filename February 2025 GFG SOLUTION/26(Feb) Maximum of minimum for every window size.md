# _26. Maximum of Minimum for Every Window Size_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size/1)

## **Problem Description**

Given an array of integers **arr[]**, find the **maximum of the minimum element** for every window size **w** from **1 to N**.

## **Examples**

### **Example 1**

### **Input:**

```
arr[] = {10, 20, 30, 50, 10, 70, 30}
```

### **Output:**

```
70 30 20 10 10 10 10
```

### **Explanation:**

| **Window Size (k)** | **Subarrays of size k**                                                | **Minimum in each subarray** | **Maximum among these minimums** |
| ------------------- | ---------------------------------------------------------------------- | ---------------------------- | -------------------------------- |
| 1                   | {10}, {20}, {30}, {50}, {10}, {70}, {30}                               | 10, 20, 30, 50, 10, 70, 30   | 70                               |
| 2                   | {10, 20}, {20, 30}, {30, 50}, {50, 10}, {10, 70}, {70, 30}             | 10, 20, 30, 10, 10, 30       | 30                               |
| 3                   | {10, 20, 30}, {20, 30, 50}, {30, 50, 10}, {50, 10, 70}, {10, 70, 30}   | 10, 20, 10, 10, 10           | 20                               |
| 4                   | {10, 20, 30, 50}, {20, 30, 50, 10}, {30, 50, 10, 70}, {50, 10, 70, 30} | 10, 10, 10, 10               | 10                               |
| 5                   | {10, 20, 30, 50, 10}, {20, 30, 50, 10, 70}, {30, 50, 10, 70, 30}       | 10, 10, 10                   | 10                               |
| 6                   | {10, 20, 30, 50, 10, 70}, {20, 30, 50, 10, 70, 30}                     | 10, 10                       | 10                               |
| 7                   | {10, 20, 30, 50, 10, 70, 30}                                           | 10                           | 10                               |

## **Example 2**

### **Input:**

```
arr[] = {1, 3, 2, 4, 5}
```

### **Output:**

```
5 3 2 1 1
```

### **Explanation:**

| **Window Size (k)** | **Subarrays of size k**         | **Minimum in each subarray** | **Maximum among these minimums** |
| ------------------- | ------------------------------- | ---------------------------- | -------------------------------- |
| 1                   | {1}, {3}, {2}, {4}, {5}         | 1, 3, 2, 4, 5                | 5                                |
| 2                   | {1, 3}, {3, 2}, {2, 4}, {4, 5}  | 1, 2, 2, 4                   | 3                                |
| 3                   | {1, 3, 2}, {3, 2, 4}, {2, 4, 5} | 1, 2, 2                      | 2                                |
| 4                   | {1, 3, 2, 4}, {3, 2, 4, 5}      | 1, 2                         | 1                                |
| 5                   | {1, 3, 2, 4, 5}                 | 1                            | 1                                |

## **Constraints:**

- $\( 1 \leq N \leq 10^5 \)$
- $\( 1 \leq arr[i] \leq 10^6 \)$

## **My Approach**

### **Optimized Stack-Based Approach (O(N) Time, O(N) Space)**

To efficiently find the **maximum of the minimum for every window size**, we use a **monotonic stack** to determine the **window size for which each element is the minimum**.

### **Algorithm Steps:**

1. **Find the nearest smaller elements on both left and right sides**

   - Store the **left boundary** (`prevSmaller[i]`) where `arr[i]` is the minimum.
   - Store the **right boundary** (`nextSmaller[i]`) where `arr[i]` is the minimum.
   - Use **stacks** to efficiently compute these values.

2. **Calculate the window size where each element is the minimum**

   - The window size for `arr[i]` is `nextSmaller[i] - prevSmaller[i] - 1`.

3. **Store maximum values for each window size**

   - Use an array `res[]` to store the maximum of the minimums for each window size.

4. **Propagate the maximum values**
   - Ensure `res[i]` contains the maximum for all larger windows using **backward propagation**.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(N), since each element is processed once.
- **Expected Auxiliary Space Complexity:** O(N), for storing index boundaries and stack operations.

## **Code (C++)**

```cpp
class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n), len(n);
        stack<int> s;
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || arr[s.top()] >= arr[i])) {
                int j = s.top();
                s.pop();
                len[j] = s.empty() ? i : i - s.top() - 1;
            }
            if (i < n) s.push(i);
        }
        for (int i = 0; i < n; i++) res[len[i] - 1] = max(res[len[i] - 1], arr[i]);
        for (int i = n - 2; i >= 0; i--) res[i] = max(res[i], res[i + 1]);
        return res;
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches (C++)</h2></summary>

## **2️⃣ Stack-Based Approach (Left-Right Boundaries)**

- Uses **two passes** to determine window lengths.
- More explicit calculation of **left and right limits**.

```cpp
class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n), len(n, n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            len[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        s = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            len[i] += s.empty() ? n - i - 1 : s.top() - i - 1;
            s.push(i);
        }
        for (int i = 0; i < n; i++) res[len[i] - 1] = max(res[len[i] - 1], arr[i]);
        for (int i = n - 2; i >= 0; i--) res[i] = max(res[i], res[i + 1]);
        return res;
    }
};
```

## **3️⃣ Deque-Based Approach (Sliding Window)**

- **Maintains a deque** to track minimums efficiently.
- Faster in practice for **large datasets**.

```cpp
class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, INT_MIN);
        vector<int> left(n), right(n);
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
            left[i] = dq.empty() ? i + 1 : i - dq.back();
            dq.push_back(i);
        }

        dq.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!dq.empty() && arr[dq.back()] > arr[i]) dq.pop_back();
            right[i] = dq.empty() ? n - i : dq.back() - i;
            dq.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            int len = left[i] + right[i] - 1;
            res[len - 1] = max(res[len - 1], arr[i]);
        }

        for (int i = n - 2; i >= 0; i--)
            res[i] = max(res[i], res[i + 1]);

        return res;
    }
};
```

## **📊 Comparison of Approaches**

| **Approach**                   | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ⚡ **Method** | ✅ **Pros**                     | ⚠️ **Cons**                 |
| ------------------------------ | ---------------------- | ----------------------- | ------------- | ------------------------------- | --------------------------- |
| **Optimized Stack**            | 🟢 `O(N)`              | 🟢 `O(N)`               | Stack-based   | Best runtime & space efficiency | None                        |
| **Left-Right Stack**           | 🟡 `O(N)`              | 🟡 `O(N)`               | Stack-based   | Explicit left-right boundaries  | Slightly more code          |
| **Deque-Based Sliding Window** | 🟡 `O(N)`              | 🟡 `O(N)`               | Deque-based   | Useful for sliding windows      | More complex implementation |

## **💡 Best Choice?**

- ✅ **For best efficiency:** **Stack-based (`O(N)`, `O(N)`)**.
- ✅ **For explicit left-right tracking:** **Left-Right Stack (`O(N)`, `O(N)`)**.
- ✅ **For sliding window problems:** **Deque-based (`O(N)`, `O(N)`)**.

</details>

## **Code (Java)**

```java
class Solution {
    public ArrayList<Integer> maxOfMins(int[] arr) {
        int n = arr.length;
        int[] res = new int[n], len = new int[n];
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i <= n; i++) {
            while (!s.isEmpty() && (i == n || arr[s.peek()] >= arr[i])) {
                int j = s.pop();
                len[j] = s.isEmpty() ? i : i - s.peek() - 1;
            }
            if (i < n) s.push(i);
        }
        for (int i = 0; i < n; i++) res[len[i] - 1] = Math.max(res[len[i] - 1], arr[i]);
        for (int i = n - 2; i >= 0; i--) res[i] = Math.max(res[i], res[i + 1]);
        ArrayList<Integer> ans = new ArrayList<>();
        for (int r : res) ans.add(r);
        return ans;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def maxOfMins(self, arr):
        n = len(arr)
        res, length, s = [0] * n, [0] * n, []
        for i in range(n + 1):
            while s and (i == n or arr[s[-1]] >= arr[i]):
                j = s.pop()
                length[j] = i if not s else i - s[-1] - 1
            if i < n:
                s.append(i)
        for i in range(n):
            res[length[i] - 1] = max(res[length[i] - 1], arr[i])
        for i in range(n - 2, -1, -1):
            res[i] = max(res[i], res[i + 1])
        return res
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
