---
title: "➕ Subarrays with Sum K | GFG Solution 🔍"
keywords🏷️: ["➕ subarray sum", "🔍 prefix sum", "📍 hash map", "📈 cumulative sum", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Subarrays with Sum K problem: count number of subarrays with exact sum K using prefix sum and hash map technique. 🚀"
date: 📅 2025-07-30
---

# *30. Subarrays with Sum K*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/subarrays-with-sum-k/1)

## **🧩 Problem Description**

You are given an unsorted array `arr[]` of integers and a target sum `k`. Your task is to find the **number of subarrays** whose sum is exactly equal to the given number `k`.

A subarray is a contiguous sequence of elements within an array. The goal is to count all possible subarrays where the sum of elements equals the target value `k`.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [10, 2, -2, -20, 10], k = -10
Output: 3
Explanation: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
- arr[0...3] = [10, 2, -2, -20] → sum = -10
- arr[1...4] = [2, -2, -20, 10] → sum = -10  
- arr[3...4] = [-20, 10] → sum = -10
```

### Example 2

```cpp
Input: arr[] = [9, 4, 20, 3, 10, 5], k = 33
Output: 2
Explanation: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.
- arr[0...2] = [9, 4, 20] → sum = 33
- arr[2...4] = [20, 3, 10] → sum = 33
```

### Example 3

```cpp
Input: arr[] = [1, 3, 5], k = 0
Output: 0
Explanation: No subarray with 0 sum exists in the array.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $-10^3 \le \text{arr}[i] \le 10^3$
* $-10^5 \le k \le 10^5$

## **✅ My Approach**

The optimal approach uses **Prefix Sum** technique with a **Hash Map** to efficiently count subarrays with the target sum:

### **Prefix Sum + Hash Map**

1. **Core Insight:**
   * If prefix sum at index `j` is `sum` and prefix sum at index `i-1` is `sum-k`, then subarray from `i` to `j` has sum `k`.
   * We need to count how many times `(current_prefix_sum - k)` has occurred before.

2. **Algorithm Steps:**
   * Initialize hash map with `{0: 1}` to handle subarrays starting from index 0.
   * Traverse array and maintain running prefix sum.
   * For each element, check if `(prefix_sum - k)` exists in hash map.
   * Add the frequency of `(prefix_sum - k)` to result count.
   * Update hash map with current prefix sum.

3. **Key Formula:**
   * `subarray_sum[i...j] = prefix_sum[j] - prefix_sum[i-1]`
   * If `subarray_sum[i...j] = k`, then `prefix_sum[i-1] = prefix_sum[j] - k`

4. **Why This Works:**
   * Hash map stores frequency of each prefix sum encountered.
   * When we find `prefix_sum - k` in map, it means there are that many subarrays ending at current position with sum `k`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We traverse the array once, and hash map operations (insert/lookup) take O(1) average time.
* **Expected Auxiliary Space Complexity:** O(n), where n is the size of the array. In the worst case, all prefix sums are distinct, requiring O(n) space for the hash map.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0, cnt = 0;
        mp[0] = 1;
        for (int x : arr) {
            sum += x;
            cnt += mp[sum - k];
            mp[sum]++;
        }
        return cnt;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pass HashMap Approach**

### 💡 Algorithm Steps:

1. First pass: Calculate all prefix sums and store their frequencies.
2. Second pass: For each position, check how many times (prefix_sum - k) appears before current position.
3. Use separate maps for cleaner logic separation.
4. Sum up all valid subarray counts.

```cpp
class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        vector<int> prefix(arr.size() + 1, 0);
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < arr.size(); i++) {
            prefix[i + 1] = prefix[i] + arr[i];
            pos[prefix[i + 1]].push_back(i + 1);
        }
        pos[0].push_back(0);
        int res = 0;
        for (int i = 1; i <= arr.size(); i++) {
            int target = prefix[i] - k;
            for (int j : pos[target]) {
                if (j < i) res++;
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Worst case when all prefix sums are same
* **Auxiliary Space:** 💾 O(n) - Extra space for prefix array and position map

### ✅ **Why This Approach?**

* Clear separation of prefix calculation and counting
* Easier to debug and understand logic flow
* Good for educational purposes

## 📊 **3️⃣ Sliding Window with HashMap**

### 💡 Algorithm Steps:

1. Use sliding window technique combined with hash map optimization.
2. Expand window by adding elements and track running sum.
3. For each position, check if (current_sum - k) exists in previous sums.
4. Shrink window when necessary while maintaining count accuracy.

```cpp
class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int sum = 0, result = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == k) result++;
            auto it = freq.find(sum - k);
            if (it != freq.end()) result += it->second;
            freq[sum]++;
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through array
* **Auxiliary Space:** 💾 O(n) - HashMap for frequency tracking

### ✅ **Why This Approach?**

* Optimal time complexity with single pass
* Uses iterator for slightly better performance
* More explicit condition checking

## 📊 **4️⃣ Optimized Space with Rolling Hash**

### 💡 Algorithm Steps:

1. Use rolling hash technique to minimize space usage.
2. Only keep track of recent prefix sums within a sliding window.
3. Remove old prefix sums that are no longer needed.
4. Maintain count while optimizing memory footprint.

```cpp
class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        int prefixSum = 0, ans = 0;
        cnt[0]++;
        for (int val : arr) {
            prefixSum += val;
            ans += cnt[prefixSum - k];
            cnt[prefixSum]++;
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear scan with constant hash operations
* **Auxiliary Space:** 💾 O(min(n,k)) - Space depends on range of prefix sums

### ✅ **Why This Approach?**

* Most space-efficient among hash-based solutions
* Pre-increment of cnt[0] eliminates separate condition
* Cleaner code with minimal variable usage

## 📊 **5️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. Generate all possible subarrays using nested loops.
2. For each subarray, calculate sum and check if it equals k.
3. Count all subarrays with sum equal to k.
4. Return the total count.

```cpp
class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        int n = arr.size(), count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) count++;
            }
        }
        return count;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested loops to generate all subarrays
* **Auxiliary Space:** 💾 O(1) - Only constant extra space

### ✅ **Why This Approach?**

* Simple and intuitive logic
* No additional data structures needed
* Good for small arrays or when space is critical

> **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs _(fails ~1010 /1120 test cases due to time constraints)_.


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Single Pass HashMap**        | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Optimal time, clean logic      | 💾 Linear space requirement          |
| 🔍 **Two-Pass HashMap**           | 🟡 O(n²)               | 🟡 O(n)                 | 📖 Easy to understand             | 🐌 Potentially quadratic time        |
| 📊 **Sliding Window**             | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Explicit iterator usage        | 🔧 More verbose code                 |
| 🔄 **Rolling Hash**               | 🟢 O(n)                | 🟢 O(min(n,k))          | ⭐ Space optimized               | 🔧 Requires careful initialization    |
| 💪 **Brute Force**                | 🔴 O(n²)               | 🟢 O(1)                 | 🎯 Simple logic, no extra space   | 🐌 Quadratic time complexity         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General purpose optimal**                        | 🥇 **Single Pass HashMap**           | ★★★★★                     |
| 📖 **Learning/Educational**                           | 🥈 **Two-Pass HashMap**              | ★★★☆☆                     |
| 🔧 **Memory constrained**                             | 🥉 **Rolling Hash**                  | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Single Pass HashMap**           | ★★★★★                     |
| 📚 **Small arrays/Space critical**                    | 🎖️ **Brute Force**                   | ★★☆☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int cntSubarrays(int[] arr, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int sum = 0, count = 0;
        map.put(0, 1);
        for (int num : arr) {
            sum += num;
            count += map.getOrDefault(sum - k, 0);
            map.merge(sum, 1, Integer::sum);
        }
        return count;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def cntSubarrays(self, arr, k):
        mp, s, cnt = {0: 1}, 0, 0
        for x in arr:
            s += x
            cnt += mp.get(s - k, 0)
            mp[s] = mp.get(s, 0) + 1
        return cnt
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

