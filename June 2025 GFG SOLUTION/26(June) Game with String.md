---
title: "🎮 Game with String | GFG Solution 🧠"
keywords🏷️: ["🧮 frequency reduction", "🧵 string manipulation", "🧊 bucket sort", "📦 max heap", "📘 GFG", "💻 DSA", "🏁 competitive programming"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Game with String problem: minimize string value after removing k characters using greedy strategies. 🚀"
date: 📅 2025-06-26
---
# *26. Game with String*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/game-with-string4100/1)

## **🧩 Problem Description**

You are given a string `s` consisting of lowercase alphabets and an integer `k`. You must remove exactly **k characters** from the string such that the **value of the string** is minimized.

The **value** of the string is defined as the **sum of squares of the frequencies** of all distinct characters.

Return the **minimum value** achievable after removing exactly `k` characters.

## **📘 Examples**

### Example 1

```cpp
Input: s = "abbccc", k = 2
Output: 6
Explanation: Remove two 'c' to get frequencies: a=1, b=2, c=1 → 1² + 2² + 1² = 6
```

### Example 2

```cpp
Input: s = "aaab", k = 2
Output: 2
Explanation: Remove two 'a' to get: a=1, b=1 → 1² + 1² = 2
```


## **🔒 Constraints**

* \$0 \leq k \leq \text{s.length()} \leq 10^5\$
* \$s\$ consists of lowercase English letters only


## **✅ My Approach**

### **Frequency Bucket Reduction + Greedy**

We aim to reduce the frequencies of the most common characters first, because squaring makes high frequencies dominate the total value. So, a greedy strategy works best.

### 💡 Algorithm Steps:

1. Count frequencies of each character using an array `f[26]`.
2. Find the maximum frequency `m` among characters.
3. Create a **bucket array** `b[m+1]` where `b[i]` stores how many characters have frequency `i`.
4. Starting from the largest frequency:

   * If we can remove all `b[i]` characters with frequency `i`, move them to frequency `i-1`.
   * Repeat until `k` becomes zero.
5. Finally, compute the total value: for all frequencies `i`, add `b[i] * i * i` to result.


## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + k), where n = size of input string, and frequency reduction takes at most O(k) operations.
* **Expected Auxiliary Space Complexity:** O(n), used for frequency and bucket arrays of size up to max frequency.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minValue(string &s, int k) {
        int f[26] = {}, m = 0;
        for (char c : s) m = max(m, ++f[c - 'a']);
        vector<int> b(m + 1);
        for (int x : f) if (x) b[x]++;
        while (k && m) {
            if (b[m] <= k) k -= b[m], b[m - 1] += b[m], b[m--] = 0;
            else b[m] -= k, b[m - 1] += k, k = 0;
        }
        int r = 0;
        for (int i = 1; i <= m; i++) r += i * i * b[i];
        return r;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Priority Queue Approach**

### 💡 Algorithm Steps:

1. Count character frequencies.
2. Push all frequencies into a **max heap**.
3. Repeat `k` times:

   * Extract the largest frequency.
   * Decrease it by 1 and push back if non-zero.
4. Finally, sum squares of remaining frequencies.

```cpp
class Solution {
public:
    int minValue(string &s, int k) {
        unordered_map<char, int> f;
        for (char c : s) f[c]++;
        priority_queue<int> pq;
        for (auto& p : f) pq.push(p.second);
        while (k-- && pq.top()) {
            int x = pq.top(); pq.pop();
            pq.push(x - 1);
        }
        int r = 0;
        while (!pq.empty()) r += pq.top() * pq.top(), pq.pop();
        return r;
    }
};
```

### 📝 Complexity Analysis:

* **Expected Time Complexity:** O(n + k log 26)
* **Expected Auxiliary Space Complexity:** O(26)

### ✅ Why This Approach?

* Easy to code and intuitive.
* Works well when `k` is small.


## 📊 **3️⃣ Greedy Frequency Array Approach**

### 💡 Algorithm Steps:

1. Count character frequencies in an array.
2. For each of `k` steps:

   * Find character with max frequency and reduce by 1.
3. Calculate the final sum of squares.

```cpp
class Solution {
public:
    int minValue(string &s, int k) {
        int f[26] = {};
        for (char c : s) f[c - 'a']++;
        while (k--) {
            int m = max_element(f, f + 26) - f;
            if (f[m]) f[m]--;
        }
        int r = 0;
        for (int i = 0; i < 26; i++) r += f[i] * f[i];
        return r;
    }
};
```

### 📝 Complexity Analysis:

* **Expected Time Complexity:** O(n + 26k)
* **Expected Auxiliary Space Complexity:** O(1)

### ✅ Why This Approach?

* Uses constant space.
* May be slow if `k` is large (due to repeated scans).


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**     | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                 | ⚠️ **Cons**                    |
| ------------------- | ---------------------- | ----------------------- | -------------------------- | ------------------------------ |
| 📊 Frequency Bucket | 🟢 O(n + k)            | 🟢 O(n)                 | 💨 Fastest, optimal greedy | Slightly complex logic         |
| 🧺 Priority Queue   | 🟡 O(n + k log 26)     | 🟢 O(26)                | 🔧 Clean & intuitive       | Heap overhead                  |
| 🔢 Greedy Array     | 🔴 O(n + 26k)          | 🟢 O(1)                 | 💾 Constant space          | Slow for large k (linear scan) |


### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                       | 🥇 **Recommended Approach** | 🔥 **Performance Rating** |
| ------------------------------------- | --------------------------- | ------------------------- |
| ⚡ Large input and large k             | ✅ **Frequency Bucket**      | ★★★★★                     |
| 🔧 Simpler implementation for small k | ✅ **Priority Queue**        | ★★★★☆                     |
| 💾 Space-constrained environment      | ✅ **Greedy Array**          | ★★★☆☆                     |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int minValue(String s, int k) {
        int[] f = new int[26]; int m = 0;
        for (char c : s.toCharArray()) m = Math.max(m, ++f[c - 'a']);
        int[] b = new int[m + 1];
        for (int x : f) if (x > 0) b[x]++;
        while (k > 0 && m > 0) {
            if (b[m] <= k) {
                k -= b[m]; 
                b[m - 1] += b[m]; 
                b[m--] = 0;
            } else {
                b[m] -= k; 
                b[m - 1] += k; 
                k = 0;
            }
        }
        int r = 0;
        for (int i = 1; i <= m; i++) r += i * i * b[i];
        return r;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def minValue(self, s, k):
        f = [0] * 26
        for c in s: f[ord(c) - 97] += 1
        m = max(f)
        b = [0] * (m + 1)
        for x in f: b[x] += x > 0
        while k and m:
            if b[m] <= k: k -= b[m]; b[m - 1] += b[m]; b[m] = 0; m -= 1
            else: b[m] -= k; b[m - 1] += k; k = 0
        return sum(i * i * b[i] for i in range(1, m + 1))
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
