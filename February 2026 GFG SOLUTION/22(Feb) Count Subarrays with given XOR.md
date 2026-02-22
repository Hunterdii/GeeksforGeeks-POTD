---
title: "⚡ Count Subarrays with given XOR | GFG Solution 🎯"
keywords🏷️: ["⚡ xor subarrays", "🔍 prefix xor", "📊 hash map", "📈 cumulative xor", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Count Subarrays with given XOR: count subarrays with specific XOR value using prefix XOR and hash map technique. 🚀"
date: 📅 2025-02-15
---

# *15. Count Subarrays with given XOR*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1)

## **🧩 Problem Description**

Given an array of integers `arr[]` and a number `k`, count the number of subarrays having **XOR of their elements as k**.

**Note:** It is guaranteed that the total count will fit within a 32-bit integer.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], 
[2, 2, 6], and [6]. Hence, the answer is 4.
```

### Example 2

```cpp
Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. 
Hence, the answer is 2.
```

### Example 3

```cpp
Input: arr[] = [1, 1, 1, 1], k = 0
Output: 4
Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^5$
* $0 \le k \le 10^5$

## **✅ My Approach**

The optimal solution uses **Prefix XOR with Hash Map**:

### **Prefix XOR Technique**

1. **Key Observation:**
   * For a subarray from index `i` to `j`, XOR equals `prefixXOR[j] ^ prefixXOR[i-1]`.
   * If this XOR equals `k`, then `prefixXOR[j] ^ prefixXOR[i-1] = k`.
   * Rearranging: `prefixXOR[i-1] = prefixXOR[j] ^ k`.

2. **Hash Map Strategy:**
   * Store frequency of each prefix XOR value encountered so far.
   * For current prefix XOR `curr`, check how many times `curr ^ k` appeared before.
   * Each occurrence represents a valid subarray ending at current position.

3. **Algorithm Steps:**
   * Initialize hash map and prefix XOR as 0.
   * Add initial state: map[0] = 1 (empty prefix).
   * For each element, update prefix XOR.
   * Count subarrays: add `map[prefixXOR ^ k]` to result.
   * Update map with current prefix XOR.

4. **Return Result:**
   * Total count of subarrays with XOR equal to k.

**Mathematical Insight:** XOR property: `a ^ b = c` implies `a = b ^ c`. This allows us to find required prefix XORs efficiently.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We make a single pass through the array, and each hash map operation (insert and lookup) takes O(1) average time.
* **Expected Auxiliary Space Complexity:** O(n), as in the worst case, all prefix XOR values could be distinct, requiring O(n) space in the hash map to store all unique prefix XORs.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        int xorSum = 0;
        long cnt = 0;
        mp[0] = 1;
        for (int x : arr) {
            xorSum ^= x;
            cnt += mp[xorSum ^ k];
            mp[xorSum]++;
        }
        return cnt;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Prefix XOR Array Approach**

### 💡 Algorithm Steps:

1. Build a prefix XOR array where prefixXOR[i] = XOR of elements from 0 to i.
2. For each pair (i, j), check if prefixXOR[j] ^ prefixXOR[i-1] equals k.
3. Use hash map to count occurrences efficiently.
4. Avoid explicit array by using running XOR.

```cpp
class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        long res = 0;
        int prefXOR = 0;
        for (int val : arr) {
            prefXOR ^= val;
            if (prefXOR == k) res++;
            res += freq[prefXOR ^ k];
            freq[prefXOR]++;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with hash map operations
* **Auxiliary Space:** 💾 O(n) - Hash map storage

### ✅ **Why This Approach?**

* Slightly different order of operations
* Checks current prefix XOR against k first
* Clear demonstration of prefix XOR concept

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Prefix XOR + HashMap**       | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Optimal linear time            | 💾 Extra space for hash map          |
| 📊 **Explicit Prefix Check**      | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Clear logic flow               | 🔧 Similar to main approach          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Prefix XOR + HashMap**          | ★★★★★                     |
| 🔧 **Production code**                                | 🥈 **Prefix XOR + HashMap**          | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public long subarrayXor(int arr[], int k) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int xorSum = 0;
        long cnt = 0;
        mp.put(0, 1);
        for (int x : arr) {
            xorSum ^= x;
            cnt += mp.getOrDefault(xorSum ^ k, 0);
            mp.put(xorSum, mp.getOrDefault(xorSum, 0) + 1);
        }
        return cnt;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def subarrayXor(self, arr, k):
        mp = {0: 1}
        xor_sum = cnt = 0
        for x in arr:
            xor_sum ^= x
            cnt += mp.get(xor_sum ^ k, 0)
            mp[xor_sum] = mp.get(xor_sum, 0) + 1
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
