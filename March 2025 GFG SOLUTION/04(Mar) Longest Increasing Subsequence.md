# _4. Longest Increasing Subsequence_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1)

## **Problem Description**

Given an array **arr[]** of non-negative integers, the task is to find the length of the **Longest Strictly Increasing Subsequence (LIS)**.

A **subsequence** is strictly increasing if each element in the subsequence is strictly less than the next element.

## **Examples**

### **Example 1:**

#### **Input:**

`arr[] = [5, 8, 3, 7, 9, 1]`

#### **Output:**

`3`

#### **Explanation:**

The longest strictly increasing subsequence could be `[5, 7, 9]`, which has a length of `3`.

### **Example 2:**

#### **Input:**

`arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]`

#### **Output:**

`6`

#### **Explanation:**

One of the possible longest strictly increasing subsequences is `[0, 2, 6, 9, 13, 15]`, which has a length of `6`.

### **Example 3:**

#### **Input:**

`arr[] = [3, 10, 2, 1, 20]`

#### **Output:**

`3`

#### **Explanation:**

The longest strictly increasing subsequence could be `[3, 10, 20]`, which has a length of `3`.

### **Constraints:**

- $\(1 \leq arr.size() \leq 10^3\)$
- $\(0 \leq arr[i] \leq 10^6\)$

## **My Approach**

### **1️⃣ Optimized Binary Search Approach**

### **Algorithm Steps:**

1. Iterate through each element of the array.
2. Maintain a **list `ans` which tracks the smallest possible tail for increasing subsequences of different lengths.**
3. For each element, **find its correct position in `ans` using `lower_bound` (binary search)**.
4. If the element can extend the current LIS, append it to `ans`, else replace the element at the correct position in `ans` to keep `ans` optimized.
5. The size of `ans` at the end represents the **length of the longest increasing subsequence**.

### **Step-by-step Process**

1. Initialize an empty list `lis`.
2. For each element `num` in the array:
   - Use **binary search (`lower_bound`) to find the position where `num` can replace or extend the `lis` list.**
   - If `num` is larger than all elements in `lis`, append it.
   - Otherwise, replace the existing element at the correct position with `num`, maintaining the smallest possible value for subsequences of that length.
3. Return the **size of `lis`**, which is the length of the **Longest Increasing Subsequence**.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N log N), where `N` is the size of the array, as we perform binary search for each element.
- **Expected Auxiliary Space Complexity:** O(N), for storing the `ans` array.

## **Code (C++)**

```cpp
class Solution {
public:
    int lis(std::vector<int>& arr) {
        std::vector<int> ans;
        for (int num : arr) {
            auto it = std::lower_bound(ans.begin(), ans.end(), num);
            if (it == ans.end()) ans.push_back(num);
            else *it = num;
        }
        return ans.size();
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming Approach (O(N²) Time, O(N) Space)**

### **Algorithm Steps:**

1. Use an array `dp` where `dp[i]` stores the **length of the LIS ending at index `i`**.
2. For each element at index `i`, check all previous elements `j`.
3. If `arr[j] < arr[i]`, update `dp[i] = max(dp[i], dp[j] + 1)`.
4. Return the maximum value in `dp`.

```cpp
class Solution {
public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
```

## **3️⃣ Segment Tree with Coordinate Compression Approach (O(N log N) Time, O(N) Space)**

### **Algorithm Steps:**

1. **Coordinate compress the array values** to reduce range size.
2. Use a **segment tree** to store the longest subsequence length ending at each value.
3. For each element, query the segment tree for the **best LIS ending at a smaller value**.
4. Update the segment tree to reflect the LIS ending at the current element.

```cpp
class Solution {
public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> comp;
        vector<int> sortedArr(arr.begin(), arr.end());
        sort(sortedArr.begin(), sortedArr.end());
        for (int i = 0; i < n; i++) comp[sortedArr[i]] = i + 1;

        vector<int> segTree(n + 1, 0);

        auto query = [&](int idx) {
            int best = 0;
            while (idx > 0) {
                best = max(best, segTree[idx]);
                idx -= idx & -idx;
            }
            return best;
        };

        auto update = [&](int idx, int val) {
            while (idx <= n) {
                segTree[idx] = max(segTree[idx], val);
                idx += idx & -idx;
            }
        };

        int res = 0;
        for (int num : arr) {
            int index = comp[num];
            int best = query(index - 1) + 1;
            update(index, best);
            res = max(res, best);
        }
        return res;
    }
};
```

## **📊 Comparison of Approaches**

| **Approach**                 | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                  | ⚠️ **Cons**                    |
| ---------------------------- | ---------------------- | ----------------------- | ---------------------------- | ------------------------------ |
| **Binary Search + DP Array** | 🟢 O(N log N)          | 🟡 O(N)                 | Fast and optimal for large N | No LIS sequence reconstruction |
| **Dynamic Programming (DP)** | 🟡 O(N²)               | 🟡 O(N)                 | Simple to understand         | Slow for large arrays          |
| **Segment Tree**             | 🟢 O(N log N)          | 🟡 O(N)                 | Handles dynamic LIS queries  | Complex implementation         |

## 💡 **Best Choice?**

- ✅ **For large arrays:** Use **Binary Search (O(N log N))** for optimal performance.
- ✅ **For simplicity:** Use **Dynamic Programming (O(N²))** for small arrays (`N ≤ 1000`).
- ✅ **For dynamic updates:** Use **Segment Tree (O(N log N))**, especially if array values need frequent updates.

</details>

## **Code (Java)**

```java
class Solution {
    public int lis(int[] arr) {
        ArrayList<Integer> ans = new ArrayList<>();
        for (int num : arr) {
            int idx = Collections.binarySearch(ans, num);
            if (idx < 0) idx = -idx - 1;
            if (idx == ans.size()) ans.add(num);
            else ans.set(idx, num);
        }
        return ans.size();
    }
}
```

## **Code (Python)**

```python
import bisect

class Solution:
    def lis(self, arr):
        ans = []
        for num in arr:
            idx = bisect.bisect_left(ans, num)
            if idx == len(ans):
                ans.append(num)
            else:
                ans[idx] = num
        return len(ans)
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
