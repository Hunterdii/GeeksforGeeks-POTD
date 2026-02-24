---
title: "🔗 Longest Span in two Binary Arrays | GFG Solution 🎯"
keywords🏷️: ["🔗 binary arrays", "🔍 prefix sum", "📊 hash map", "📈 equal sum", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Longest Span in two Binary Arrays: find longest span with equal sums using prefix difference and hash map technique. 🚀"
date: 📅 2025-02-24
---

# *24. Longest Span in two Binary Arrays*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1)

## **🧩 Problem Description**

Given two binary arrays, `a1[]` and `a2[]` of equal length, find the length of **longest common span (i, j)**, where `i <= j` such that:

**a1[i] + a1[i+1] + ... + a1[j] = a2[i] + a2[i+1] + ... + a2[j]**

## **📘 Examples**

### Example 1

```cpp
Input: a1[] = [0, 1, 0, 0, 0, 0], a2[] = [1, 0, 1, 0, 0, 1]
Output: 4
Explanation: The longest span with same sum is from index 1 to 4 (0-based indexing).
Sum in a1[1:4] = 1+0+0+0 = 1, Sum in a2[1:4] = 0+1+0+0 = 1
```

### Example 2

```cpp
Input: a1[] = [0, 1, 0, 1, 1, 1, 1], a2[] = [1, 1, 1, 1, 1, 0, 1]
Output: 6
Explanation: The longest span with same sum is from index 1 to 6 (0-based indexing).
```

### Example 3

```cpp
Input: a1[] = [0, 0, 0], a2[] = [1, 1, 1]
Output: 0
Explanation: There is no span where the sum of the elements in a1[] and a2[] is equal.
```

## **🔒 Constraints**

* $1 \le \text{a1.size()} = \text{a2.size()} \le 10^6$
* $0 \le \text{a1}[i], \text{a2}[i] \le 1$

## **✅ My Approach**

The optimal solution uses **Difference Array with Hash Map**:

### **Prefix Difference Technique**

1. **Key Transformation:**
   * Instead of tracking two separate prefix sums, track their **difference**.
   * Let `diff = prefixSum(a1) - prefixSum(a2)`.
   * If `diff[i] == diff[j]`, then sum from `i+1` to `j` is equal in both arrays.

2. **Hash Map Strategy:**
   * Store first occurrence of each difference value.
   * Initialize with `map[0] = -1` to handle spans starting from index 0.
   * For each position, calculate cumulative difference.

3. **Algorithm Steps:**
   * Iterate through both arrays simultaneously.
   * Update running difference: `diff += a1[i] - a2[i]`.
   * If this difference seen before, calculate span length: `i - map[diff]`.
   * If not seen, store first occurrence: `map[diff] = i`.

4. **Return Result:**
   * Maximum span length found during traversal.

**Mathematical Insight:** If `prefixSum1[j] - prefixSum2[j] = prefixSum1[i] - prefixSum2[i]`, then `sum(a1[i+1:j+1]) = sum(a2[i+1:j+1])`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the arrays. We make a single pass through both arrays, and each hash map operation (lookup and insert) takes O(1) average time.
* **Expected Auxiliary Space Complexity:** O(n), as in the worst case, all cumulative differences could be unique, requiring O(n) space in the hash map to store all distinct difference values.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int diff = 0, maxLen = 0;
        for (int i = 0; i < a1.size(); i++) {
            diff += a1[i] - a2[i];
            if (mp.count(diff)) maxLen = max(maxLen, i - mp[diff]);
            else mp[diff] = i;
        }
        return maxLen;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Separate Prefix Sum Arrays**

### 💡 Algorithm Steps:

1. Maintain two separate prefix sum arrays for a1 and a2.
2. Use hash map to store first occurrence of each difference.
3. Calculate difference at each position and check for previous occurrences.
4. Track maximum span length throughout the process.

```cpp
class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size(), maxLen = 0;
        unordered_map<int, int> diffMap;
        int prefixSum1 = 0, prefixSum2 = 0;
        for (int i = 0; i < n; i++) {
            prefixSum1 += a1[i];
            prefixSum2 += a2[i];
            int currentDiff = prefixSum1 - prefixSum2;
            if (currentDiff == 0) maxLen = max(maxLen, i + 1);
            else if (diffMap.find(currentDiff) != diffMap.end())
                maxLen = max(maxLen, i - diffMap[currentDiff]);
            else diffMap[currentDiff] = i;
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with hash operations
* **Auxiliary Space:** 💾 O(n) - Hash map storage

### ✅ **Why This Approach?**

* Clear separation of prefix sum calculation
* Explicit handling of zero difference case
* More verbose but easier to understand

## 📊 **3️⃣ Difference Array Approach**

### 💡 Algorithm Steps:

1. Create a difference array: diff[i] = a1[i] - a2[i].
2. Find longest subarray in diff with sum = 0.
3. Use hash map to track prefix sums of difference array.
4. Apply same technique as longest subarray with sum K.

```cpp
class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) diff[i] = a1[i] - a2[i];
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (mp.count(sum)) maxLen = max(maxLen, i - mp[sum]);
            else mp[sum] = i;
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear pass with hash operations
* **Auxiliary Space:** 💾 O(n) - Difference array and hash map

### ✅ **Why This Approach?**

* Transforms problem to classic longest zero-sum subarray
* Explicit difference array for clarity
* Educational value in problem transformation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Prefix Difference**          | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Optimal, single pass           | 💾 Hash map overhead                 |
| 📊 **Separate Prefix Sums**       | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear logic flow               | 🔧 More verbose                      |
| 📈 **Difference Array**           | 🟢 O(n)                | 🟡 O(n)                 | 🔍 Problem transformation         | 💾 Extra array space                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Prefix Difference**             | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥈 **Separate Prefix Sums**          | ★★★★★                     |
| 🎯 **Educational purposes**                           | 🥉 **Difference Array**              | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int equalSumSpan(int[] a1, int[] a2) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, -1);
        int diff = 0, maxLen = 0;
        for (int i = 0; i < a1.length; i++) {
            diff += a1[i] - a2[i];
            if (mp.containsKey(diff)) maxLen = Math.max(maxLen, i - mp.get(diff));
            else mp.put(diff, i);
        }
        return maxLen;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def equalSumSpan(self, a1, a2):
        mp = {0: -1}
        diff = maxLen = 0
        for i in range(len(a1)):
            diff += a1[i] - a2[i]
            if diff in mp:
                maxLen = max(maxLen, i - mp[diff])
            else:
                mp[diff] = i
        return maxLen
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
