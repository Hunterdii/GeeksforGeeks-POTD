---
title: "📈 Longest Subarray with Majority Greater than K | GFG Solution 🎯"
keywords🏷️: ["📈 majority subarray", "🔍 prefix sum", "➕ hash map", "🔢 transformation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Longest Subarray with Majority Greater than K: find longest subarray where count of elements > k exceeds count of elements ≤ k using prefix sum transformation. 🚀"
date: 📅 2025-02-25
---

# *25. Longest Subarray with Majority Greater than K*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1)

## **🧩 Problem Description**

Given an array `arr[]` and an integer `k`, find the length of **longest subarray** in which the count of elements **greater than k** is **more than** the count of elements **less than or equal to k**.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, 
and there is no subarray of length 4 or 5 which will hold the given condition, 
so the answer is 3.
```

### Example 2

```cpp
Input: arr[] = [6, 5, 3, 4], k = 2
Output: 4
Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, 
so it is the longest subarray.
```

### Example 3

```cpp
Input: arr[] = [1, 1, 1], k = 2
Output: 0
Explanation: No subarray exists where count of elements > 2 is more than count of elements <= 2.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $1 \le \text{arr}[i] \le 10^6$
* $0 \le k \le 10^6$

## **✅ My Approach**

The optimal solution uses **Prefix Sum Transformation with Hash Map**:

### **Transform and Conquer**

1. **Key Transformation:**
   * Transform the problem: treat elements `> k` as `+1` and elements `<= k` as `-1`.
   * We need subarrays where sum of transformed values `> 0`.
   * This means more `+1`s than `-1`s, i.e., count(elements > k) > count(elements <= k).

2. **Prefix Sum Strategy:**
   * Maintain running sum of transformed values.
   * If `sum > 0` at position `i`, entire prefix `[0, i]` is valid.
   * Otherwise, look for a previous position with `sum - 1`.

3. **Hash Map Logic:**
   * Store first occurrence of each prefix sum value.
   * For current position with sum `s`, if we find position with sum `s-1`:
     - Subarray from that position to current has sum = 1 > 0 ✓
   * Track maximum length found.

4. **Algorithm Steps:**
   * For each element, add +1 if `arr[i] > k`, else add -1.
   * If cumulative sum > 0, update answer to `i + 1`.
   * Else check if `sum - 1` exists in map, update answer accordingly.
   * Store first occurrence of current sum.

**Mathematical Insight:** If `prefixSum[j] - prefixSum[i] > 0`, then subarray `[i+1, j]` has more elements > k than elements <= k.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We make a single pass through the array, and each hash map operation (lookup and insert) takes O(1) average time.
* **Expected Auxiliary Space Complexity:** O(n), as in the worst case, all prefix sum values could be unique, requiring O(n) space in the hash map to store all distinct prefix sums.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += (arr[i] > k) ? 1 : -1;
            if (sum > 0) ans = i + 1;
            else if (mp.count(sum - 1)) ans = max(ans, i - mp[sum - 1]);
            if (!mp.count(sum)) mp[sum] = i;
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Explicit Prefix Sum Tracking**

### 💡 Algorithm Steps:

1. Maintain explicit transformation of array elements.
2. Store prefix sum at each position with hash map.
3. Check for sum > 0 and sum - 1 conditions separately.
4. Track maximum valid subarray length.

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) sum--;
            else sum++;
            if (sum > 0) ans = i + 1;
            else {
                if (mp.find(sum - 1) != mp.end())
                    ans = max(ans, i - mp[sum - 1]);
            }
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with hash operations
* **Auxiliary Space:** 💾 O(n) - Hash map storage

### ✅ **Why This Approach?**

* More explicit transformation logic
* Easier to understand the -1/+1 mapping
* Clear conditional structure

## 📊 **3️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. Generate all possible subarrays using nested loops.
2. For each subarray, count elements > k and elements <= k.
3. If count(> k) > count(<= k), update maximum length.
4. Return the maximum length found.

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int greater = 0, lessEqual = 0;
            for (int j = i; j < n; j++) {
                if (arr[j] > k) greater++;
                else lessEqual++;
                if (greater > lessEqual)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Two nested loops
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Simple and straightforward
* No complex data structures
* Good for understanding the problem

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1115 test cases due to time constraints).


## 📊 **4️⃣ Two-Pass with Transformation Array**

### 💡 Algorithm Steps:

1. Create transformed array where arr[i] = 1 if arr[i] > k, else -1.
2. Find longest subarray in transformed array with sum > 0.
3. Use hash map to track prefix sums efficiently.
4. Return maximum length found.

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> trans(n);
        for (int i = 0; i < n; i++)
            trans[i] = (arr[i] > k) ? 1 : -1;
        
        unordered_map<int, int> mp;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            sum += trans[i];
            if (sum > 0) maxLen = i + 1;
            else if (mp.count(sum - 1))
                maxLen = max(maxLen, i - mp[sum - 1]);
            if (!mp.count(sum)) mp[sum] = i;
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two linear passes
* **Auxiliary Space:** 💾 O(n) - Transformation array + hash map

### ✅ **Why This Approach?**

* Clear separation of transformation and processing
* Explicit intermediate representation
* Educational value in problem decomposition

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Prefix Sum Transform**       | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Optimal single pass            | 💾 Hash map overhead                 |
| 📊 **Explicit Transformation**    | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear logic flow               | 🔧 Similar to main approach          |
| 🔄 **Brute Force**                | 🔴 O(n²)               | 🟢 O(1)                 | 🎯 Simple to understand           | 🐌 Quadratic time                    |
| 📈 **Two-Pass Transform**         | 🟢 O(n)                | 🔴 O(n)                 | 🔍 Explicit array transformation  | 💾 Extra array space                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Prefix Sum Transform**          | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥈 **Explicit Transformation**       | ★★★★★                     |
| 💡 **Educational purposes**                           | 🥉 **Two-Pass Transform**            | ★★★★☆                     |
| 🎯 **Small input size**                               | 🏅 **Brute Force**                   | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int longestSubarray(int[] arr, int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int sum = 0, ans = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += (arr[i] > k) ? 1 : -1;
            if (sum > 0) ans = i + 1;
            else if (mp.containsKey(sum - 1)) ans = Math.max(ans, i - mp.get(sum - 1));
            if (!mp.containsKey(sum)) mp.put(sum, i);
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def longestSubarray(self, arr, k):
        mp = {}
        sum_val = ans = 0
        for i in range(len(arr)):
            sum_val += 1 if arr[i] > k else -1
            if sum_val > 0:
                ans = i + 1
            elif sum_val - 1 in mp:
                ans = max(ans, i - mp[sum_val - 1])
            if sum_val not in mp:
                mp[sum_val] = i
        return ans
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
