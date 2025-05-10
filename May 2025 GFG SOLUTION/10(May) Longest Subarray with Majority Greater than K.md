# *10. Longest Subarray With Majority Greater Than K*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1)

## **🧩 Problem Description**

Given an array `arr[]` of size `n` and an integer `k`, find the length of the **longest subarray** in which the count of elements **greater than** `k` is **strictly more** than the count of elements **less than or equal** to `k`.

## **📘 Examples**

### **Example 1:**

#### **Input:**

```
arr = [1, 2, 3, 4, 1], k = 2
```

#### **Output:**

```
3
```

#### **Explanation:**

Subarrays `[2, 3, 4]` or `[3, 4, 1]` both have 2 elements > 2 and 1 element ≤ 2.

### **Example 2:**

#### **Input:**

```
arr = [6, 5, 3, 4], k = 2
```

#### **Output:**

```
4
```

#### **Explanation:**

Full array has 4 elements > 2 and 0 elements ≤ 2, so length = 4.

## **🔒 Constraints**

* $`1 ≤ n = arr.size() ≤ 10^6`$
* $`0 ≤ k ≤ 10^6`$
* $`0 ≤ arr[i] ≤ 10^6`$


## **✅ My Approach**

### **Prefix‐Sum + Hash Map**
We transform each element into `+1` if it’s > k, or `−1` otherwise. Then the problem reduces to finding the **longest subarray** whose **sum** is **positive**.

### **Algorithm Steps:**

1. Initialize a prefix‐sum `s = 0` and an empty hash map `firstIdx` mapping each seen prefix‐sum to its **earliest** index.
2. Iterate through the array with index `i`:

   * Update `s += (arr[i] > k ? 1 : -1)`.
   * If `s > 0`, the subarray `[0…i]` has positive sum; update `res = i + 1`.
   * Else if `(s - 1)` exists in `firstIdx`, a subarray ending at `i` starting after `firstIdx[s - 1]` has positive sum; update `res = max(res, i - firstIdx[s - 1])`.
   * If `s` is not yet in `firstIdx`, store `firstIdx[s] = i`.
3. Return `res` (the maximum length found).


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** `O(n)`, since we make a single pass and each hash operation is amortized O(1).
* **Expected Auxiliary Space Complexity:** `O(n)`, for storing up to `n` distinct prefix‐sums in the hash map.


## **🧠 Code (C++)**

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> firstIdx;
        int s = 0, res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            s += (arr[i] > k ? 1 : -1);
            if (s > 0) {
                res = i + 1;
            } else {
                if (!firstIdx.count(s)) firstIdx[s] = i;
                if (firstIdx.count(s - 1))
                    res = max(res, i - firstIdx[s - 1]);
            }
        }
        return res;
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Monotonic Stack + Prefix Sum**

### **Algorithm Steps:**

1. Construct a prefix sum array `P` of length `n+1`, where `P[0] = 0`, and for each `i`, `P[i+1] = P[i] + (arr[i] > k ? 1 : -1)`.
2. Build a **monotonically decreasing stack** of indices where the corresponding `P[i]` values are strictly decreasing.
3. Traverse the array from the end (`i = n`) to the beginning (`i = 0`):

   * While the stack is not empty and `P[i] > P[stack.top()]`, pop from the stack and compute `res = max(res, i - idx)`.
4. Return `res`.

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), res = 0;
        vector<int> P(n + 1, 0), st;
        for (int i = 0; i < n; ++i)
            P[i + 1] = P[i] + (arr[i] > k ? 1 : -1);
        for (int i = 0; i <= n; ++i)
            if (st.empty() || P[i] < P[st.back()])
                st.push_back(i);
        for (int i = n; i >= 0; --i) {
            while (!st.empty() && P[i] > P[st.back()]) {
                res = max(res, i - st.back());
                st.pop_back();
            }
        }
        return res;
    }
};
```



### ✅ **Why This Approach?**

* Achieves **O(n)** time and **O(n)** space complexity.
* Avoids the use of hash maps, which can be beneficial in environments where hash map performance is unpredictable.

#### 📝 **Complexity Analysis:**

* **Time:** O(n)
* **Space:** O(n)


## 📊 **3️⃣ Balanced BST (Ordered Map)**

### **Algorithm Steps:**

1. Initialize a balanced binary search tree (e.g., `map<int, int>`) to store the earliest occurrence of each prefix sum.
2. Iterate through the array, updating the prefix sum `s` by adding `1` if `arr[i] > k`, else subtracting `1`.
3. If `s > 0`, update `res = i + 1`.
4. If `s` is not already in the map, insert it with the current index.
5. Check if `s - 1` exists in the map; if so, update `res = max(res, i - map[s - 1])`.
6. Return `res`.

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        map<int, int> firstIdx;
        int s = 0, res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            s += (arr[i] > k ? 1 : -1);
            if (s > 0) {
                res = i + 1;
            } else {
                if (!firstIdx.count(s)) firstIdx[s] = i;
                auto it = firstIdx.find(s - 1);
                if (it != firstIdx.end())
                    res = max(res, i - it->second);
            }
        }
        return res;
    }
};
```



### ✅ **Why This Approach?**

* Provides **O(n log n)** worst-case time complexity due to the balanced BST operations.
* Deterministic performance without relying on hash functions.

#### 📝 **Complexity Analysis:**

* **Time:** O(n log n)
* **Space:** O(n)


## 🆚 **Comparison of Approaches**

| **Approach**                 | ⏱️ **Time**   | 🗂️ **Space** | ✅ **Pros**                   | ⚠️ **Cons**                 |
| ---------------------------- | ------------- | ------------- | ---------------------------- | --------------------------- |
| Prefix Sum + Hash Map        | 🟢 O(n)       | 🟢 O(n)       | Simple, fastest average case | Potential hash collisions   |
| Monotonic Stack + Prefix Sum | 🟢 O(n)       | 🟢 O(n)       | No hash map needed           | Slightly more complex logic |
| Balanced BST (Ordered Map)   | 🔸 O(n log n) | 🟢 O(n)       | Deterministic performance    | Slower due to log n factor  |

### ✅ **Best Choice?**

| **Scenario**                    | **Recommended Approach**    |
| ------------------------------- | --------------------------- |
| Large `n` (up to 10^6), fastest | 🥇 Prefix Sum + Hash Map    |
| Avoid hashing, still linear     | 🥈 Monotonic Stack + Prefix |
| Guarantee tree-based lookup     | 🥉 Balanced BST             |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int longestSubarray(int[] arr, int k) {
        Map<Integer,Integer> firstIdx = new HashMap<>();
        int s = 0, res = 0;
        for (int i = 0; i < arr.length; i++) {
            s += arr[i] > k ? 1 : -1;
            if (s > 0) {
                res = i + 1;
            } else {
                firstIdx.putIfAbsent(s, i);
                if (firstIdx.containsKey(s - 1)) {
                    res = Math.max(res, i - firstIdx.get(s - 1));
                }
            }
        }
        return res;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def longestSubarray(self, arr, k):
        first_idx = {}
        s = res = 0
        for i, val in enumerate(arr):
            s += 1 if val > k else -1
            if s > 0:
                res = i + 1
            else:
                first_idx.setdefault(s, i)
                if (s - 1) in first_idx:
                    res = max(res, i - first_idx[s - 1])
        return res
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
