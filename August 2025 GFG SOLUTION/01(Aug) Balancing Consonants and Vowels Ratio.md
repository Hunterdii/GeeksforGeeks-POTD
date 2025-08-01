---
title: "🔠 Balancing Consonants and Vowels Ratio | GFG Solution 🔍"
keywords🏷️: ["🔠 balanced strings", "🔍 prefix sum", "📍 hash map", "📈 subarray counting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Balancing Consonants and Vowels Ratio problem: count balanced substrings with equal vowels and consonants using prefix sum technique. 🚀"
date: 📅 2025-08-01
---

# *01. Balancing Consonants and Vowels Ratio*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/balancing-consonants-and-vowels-ratio/1)

## **🧩 Problem Description**

You are given an array of strings `arr[]`, where each `arr[i]` consists of lowercase English alphabets. Your task is to find the number of **balanced strings** in `arr[]` which can be formed by concatenating one or more contiguous strings of `arr[]`.

A **balanced string** contains an equal number of vowels and consonants.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = ["aeio", "aa", "bc", "ot", "cdbd"]
Output: 4
Explanation: arr[0..4], arr[1..2], arr[1..3], arr[3..3] are the balanced substrings 
with equal consonants and vowels.
```

### Example 2

```cpp
Input: arr[] = ["ab", "be"]
Output: 3
Explanation: arr[0..0], arr[0..1], arr[1..1] are the balanced substrings 
with equal consonants and vowels.
```

### Example 3

```cpp
Input: arr[] = ["tz", "gfg", "ae"]
Output: 0
Explanation: There is no such balanced substring present in arr[] 
with equal consonants and vowels.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i]\text{.size()} \le 10^5$
* Total number of lowercase English characters in `arr[]` is lesser than $10^5$

## **✅ My Approach**

The optimal approach uses the **Prefix Sum** technique with a **Hash Map** to efficiently count balanced substrings:

### **Prefix Sum + Hash Map**

1. **Core Insight:**
   * For a substring to be balanced, the number of vowels must equal the number of consonants.
   * We can represent this as: `vowels - consonants = 0`
   * Assign `+1` for vowels and `-1` for consonants, then find subarrays with sum = 0.

2. **Algorithm Steps:**
   * Initialize a hash map with `{0: 1}` to handle subarrays starting from index 0.
   * For each string in the array, calculate its score (vowels count - consonants count).
   * Maintain a running sum of scores as we process each string.
   * If the current sum has been seen before, it means there are subarrays ending at the current position that have a net balance of 0.
   * Add the frequency of the current sum to the result and increment its count in the hash map.

3. **Key Operations:**
   * Calculate score for each string: `+1` for each vowel, `-1` for each consonant.
   * Use prefix sum to track cumulative balance.
   * Count occurrences of each prefix sum to find balanced subarrays.

4. **Why This Works:**
   * If `prefixSum[j] == prefixSum[i]` for `j > i`, then the subarray from `i+1` to `j` has sum = 0.
   * This means equal vowels and consonants in that subarray.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n*m), where n is the number of strings and m is the average length of strings. We process each character exactly once to calculate string scores, then perform O(1) hash map operations for each string.
* **Expected Auxiliary Space Complexity:** O(n), where n is the number of strings. In the worst case, we store one entry per string in the hash map when all prefix sums are distinct.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countBalanced(vector<string>& arr) {
        int res = 0, sum = 0;
        unordered_map<int, int> mp{{0, 1}};
        for (string& s : arr) {
            int score = 0;
            for (char c : s) score += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : -1;
            res += mp[sum += score]++;
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Bit Manipulation Approach**

### 💡 Algorithm Steps:

1. Use bitwise operations to check vowels faster using lookup table.
2. Pre-compute vowel mask for O(1) vowel checking.
3. Single pass with optimized character classification.
4. Accumulate prefix sums with direct map access.

```cpp
class Solution {
public:
    int countBalanced(vector<string>& arr) {
        int vowels = (1 << ('a' - 'a')) | (1 << ('e' - 'a')) | (1 << ('i' - 'a')) | (1 << ('o' - 'a')) | (1 << ('u' - 'a'));
        int res = 0, sum = 0;
        unordered_map<int, int> mp{{0, 1}};
        for (auto& s : arr) {
            for (char c : s) sum += (vowels & (1 << (c - 'a'))) ? 1 : -1;
            res += mp[sum]++;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m) - n strings, m average length
* **Auxiliary Space:** 💾 O(n) - HashMap for prefix sums

### ✅ **Why This Approach?**

* Faster vowel checking using bit operations.
* Eliminates multiple character comparisons.
* Cache-friendly single bit operation.

## 📊 **3️⃣ Array-Based Frequency**

### 💡 Algorithm Steps:

1. Use array instead of hash map for better cache performance.
2. Offset negative indices to handle negative prefix sums.
3. Direct array access for frequency counting.
4. Optimized memory access pattern.

```cpp
class Solution {
public:
    int countBalanced(vector<string>& arr) {
        vector<int> freq(200001, 0);
        int offset = 100000, res = 0, sum = offset;
        freq[offset] = 1;
        for (auto& s : arr) {
            for (char c : s) sum += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : -1;
            res += freq[sum]++;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m) - Linear traversal
* **Auxiliary Space:** 💾 O(1) - Fixed size array

### ✅ **Why This Approach?**

* Better cache performance than hash map.
* Constant time array access.
* No hash collision overhead.

## 📊 **4️⃣ Lambda-Based Compact**

### 💡 Algorithm Steps:

1. Use lambda for inline vowel checking.
2. Range-based loops for cleaner syntax.
3. Minimal variable declarations.
4. Compact single-expression logic.

```cpp
class Solution {
public:
    int countBalanced(vector<string>& arr) {
        auto isVowel = [](char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
        unordered_map<int, int> mp{{0, 1}};
        int res = 0, sum = 0;
        for (auto& s : arr) {
            for (char c : s) sum += isVowel(c) ? 1 : -1;
            res += mp[sum]++;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m) - Standard traversal
* **Auxiliary Space:** 💾 O(n) - HashMap storage

### ✅ **Why This Approach?**

* Modern C++ style with lambdas.
* Clean and readable code.
* Compiler optimization friendly.

## 📊 **5️⃣ String Set-Based Vowel Check**

### 💡 Algorithm Steps:

1. Use string set "aeiou" for vowel checking.
2. Utilize string's find method for character lookup.
3. Cleaner vowel identification logic.
4. Standard library optimized operations.

```cpp
class Solution {
public:
    int countBalanced(vector<string>& arr) {
        string vowels = "aeiou";
        unordered_map<int, int> mp{{0, 1}};
        int res = 0, sum = 0;
        for (auto& s : arr) {
            for (char c : s) sum += (vowels.find(c) != string::npos) ? 1 : -1;
            res += mp[sum]++;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m) - Linear with constant vowel check
* **Auxiliary Space:** 💾 O(n) - HashMap storage

### ✅ **Why This Approach?**

* Intuitive vowel checking method.
* Standard library string operations.
* Easy to understand and maintain.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Prefix Sum Hash Map**        | 🟢 O(n*m)              | 🟡 O(n)                 | 🚀 Clean and intuitive            | 🔧 Hash map overhead                 |
| 🔍 **Bit Manipulation**           | 🟢 O(n*m)              | 🟡 O(n)                 | 📖 Faster vowel check             | 💾 Complex bit operations            |
| 📊 **Array-Based**                | 🟢 O(n*m)              | 🟢 O(1)                 | 🎯 Better cache performance       | 🐌 Fixed memory allocation           |
| 🔄 **Lambda Compact**             | 🟢 O(n*m)              | 🟡 O(n)                 | ⭐ Modern C++ style               | 🔧 Compiler-dependent optimization   |
| 🔤 **String Set-Based**           | 🟢 O(n*m)              | 🟡 O(n)                 | 📝 Intuitive and readable         | 🔧 String find overhead              |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ **Maximum performance, competitive programming**    | 🥇 **Bit Manipulation**        | ★★★★★                     |
| 🔧 **Production code, readability important**         | 🥈 **Prefix Sum Hash Map**     | ★★★★☆                     |
| 📊 **Memory constrained environments**                | 🥉 **Array-Based**             | ★★★★☆                     |
| 🎯 **Educational purposes, clear logic**               | 🎖️ **String Set-Based**        | ★★★☆☆                     |
| 📚 **Modern C++ practices**                           | 🏅 **Lambda Compact**          | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int countBalanced(String[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(0, 1);
        int sum = 0, res = 0;
        for (String s : arr) {
            for (char c : s.toCharArray()) 
                sum += "aeiou".indexOf(c) >= 0 ? 1 : -1;
            res += mp.getOrDefault(sum, 0);
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countBalanced(self, arr):
        mp, s, res = {0: 1}, 0, 0
        for string in arr:
            s += sum(1 if c in 'aeiou' else -1 for c in string)
            res += mp.get(s, 0)
            mp[s] = mp.get(s, 0) + 1
        return res
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

