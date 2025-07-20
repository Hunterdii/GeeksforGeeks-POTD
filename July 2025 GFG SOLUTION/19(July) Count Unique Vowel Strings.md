---
title: "🔤 Count Unique Vowel Strings | GFG Solution 🎯"
keywords🏷️:
  [
    "🔤 vowel strings",
    "🧮 combinatorics",
    "📊 frequency counting",
    "🔄 permutations",
    "📘 GFG",
    "🏁 competitive programming",
    "📚 DSA",
  ]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Count Unique Vowel Strings problem: calculate total distinct strings by selecting vowels and forming permutations using combinatorial mathematics. 🚀"
date: 📅 2025-07-19
---

# _19. Count Unique Vowel Strings_

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-unique-vowel-strings/1)

## **🧩 Problem Description**

You are given a lowercase string `s`, determine the total number of distinct strings that can be formed using the following rules:

1. **Identify** all unique vowels (a, e, i, o, u) present in the string.
2. **Select** exactly one occurrence of each distinct vowel from `s`. If a vowel appears multiple times, each occurrence represents a unique selection choice.
3. **Generate** all possible permutations of the selected vowels. Each unique arrangement counts as a distinct string.

Return the total number of such distinct strings.

## **📘 Examples**

### Example 1

```cpp
Input: s = "aeiou"
Output: 120
Explanation: Each vowel appears once, so the number of different strings can form is 5! = 120.
```

### Example 2

```cpp
Input: s = "ae"
Output: 2
Explanation: Pick a and e, make all orders → "ae", "ea".
```

### Example 3

```cpp
Input: s = "aacidf"
Output: 4
Explanation: Vowels in s are 'a' and 'i'. Pick each 'a' once with a single 'i',
make all orders → "ai", "ia", "ai", "ia".
Since 'a' appears twice, we have 2 ways to pick 'a' and 1 way to pick 'i'.
Total selections = 2 × 1 = 2. Permutations of 2 vowels = 2! = 2.
Total distinct strings = 2 × 2 = 4.
```

## **🔒 Constraints**

- $1 \le s.size() \le 100$

## **✅ My Approach**

The solution uses **Combinatorial Mathematics** with **Frequency Counting** to calculate the result efficiently:

### **Frequency Counting + Combinatorics**

1. **Count Vowel Frequencies:**

   - Iterate through the string and count occurrences of each vowel (a, e, i, o, u).
   - Store frequencies in an array or map.

2. **Calculate Selection Ways:**

   - For each vowel that appears in the string, the number of ways to select one occurrence equals its frequency.
   - Multiply frequencies of all present vowels to get total selection combinations.

3. **Calculate Permutations:**

   - Count the number of distinct vowel types present.
   - Calculate factorial of this count to get all possible arrangements.

4. **Final Result:**
   - Total distinct strings = (Product of frequencies) × (Factorial of distinct vowel count)

### **Mathematical Formula:**

```
Result = (∏ frequency[vowel]) × (distinct_vowels)!
```

Where:

- `∏ frequency[vowel]` = product of frequencies of all vowels present
- `distinct_vowels` = count of unique vowel types in the string

## 📝 Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the length of the string. We traverse the string once to count vowel frequencies, then perform constant operations for calculation.
- **Expected Auxiliary Space Complexity:** O(1), as we use a fixed-size array to store vowel frequencies (maximum 5 vowels) and a few variables for calculation.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int vowelCount(string& s) {
        int freq[26] = {}, cnt = 0, mul = 1;
        for (char c : s) if (strchr("aeiou", c)) freq[c - 'a']++;
        for (int v : {0, 4, 8, 14, 20}) if (freq[v]) mul *= freq[v], cnt++;
        return cnt ? mul * tgamma(cnt + 1) : 0;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized Counting with Map**

### 💡 Algorithm Steps:

1. Use unordered_map for vowel frequency tracking
2. Calculate factorial iteratively for better precision
3. Handle edge cases efficiently
4. Minimize memory footprint

```cpp
class Solution {
public:
    int vowelCount(string& s) {
        unordered_map<char, int> freq;
        for (char c : s)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                freq[c]++;
        int cnt = 0, mul = 1;
        for (auto& p : freq) {
            if (p.second > 0) {
                mul *= p.second;
                cnt++;
            }
        }
        for (int i = 2; i <= cnt; i++) mul *= i;
        return cnt ? mul : 0;
    }
};
```

### 📝 **Complexity Analysis:**

- **Time:** ⏱️ O(n) - single pass through string
- **Auxiliary Space:** 💾 O(1) - fixed vowel storage

### ✅ **Why This Approach?**

- Better precision than tgamma
- More readable code structure
- Handles large frequencies better

## 📊 **3️⃣ Switch-Case Optimization**

### 💡 Algorithm Steps:

1. Use switch-case for O(1) vowel detection
2. Avoid string operations entirely
3. Direct array indexing
4. Minimal branching

```cpp
class Solution {
public:
    int vowelCount(string& s) {
        int v[5] = {0}, res = 1, cnt = 0;
        for(char c : s) {
            switch(c) {
                case 'a': v[0]++; break;
                case 'e': v[1]++; break;
                case 'i': v[2]++; break;
                case 'o': v[3]++; break;
                case 'u': v[4]++; break;
            }
        }
        for(int i = 0; i < 5; i++) {
            if(v[i]) res *= v[i], cnt++;
        }
        int f[] = {1,1,2,6,24,120};
        return cnt ? res * f[cnt] : 0;
    }
};
```

### 📝 **Complexity Analysis:**

- **Time:** ⏱️ O(n) – single pass with O(1) checks per character
- **Auxiliary Space:** 💾 O(1) – fixed-size arrays only

### ✅ **Why This Approach?**

- Fastest character lookup via `switch`
- Compile-time branch resolution
- Branch-free vowel identification (no string searches)

## 📊 **4️⃣ String View Optimization**

### 💡 Algorithm Steps:

1. Use string_view for faster character access
2. Lookup table for vowel identification
3. Single pass with minimal operations
4. Compile-time optimizations

```cpp
class Solution {
public:
    int vowelCount(string& s) {
        static constexpr bool isVowel[26] = {
            1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0
        };
        int freq[5] = {0}, vowelMap[] = {0,-1,-1,-1,1,-1,-1,-1,2,-1,-1,-1,-1,-1,3,-1,-1,-1,-1,-1,4};
        for (char c : s) {
            if (isVowel[c - 'a']) {
                freq[vowelMap[c - 'a']]++;
            }
        }
        int cnt = 0, mul = 1;
        for (int f : freq) if (f) mul *= f, cnt++;
        for (int i = 2; i <= cnt; i++) mul *= i;
        return cnt ? mul : 0;
    }
};
```

### 📝 **Complexity Analysis:**

- **Time:** ⏱️ O(n) - optimized with lookup tables
- **Auxiliary Space:** 💾 O(1) - constant space arrays

### ✅ **Why This Approach?**

- Fastest character lookup
- Compile-time optimizations
- Branch-free vowel detection

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**           | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                 | ⚠️ **Cons**                   |
| ------------------------- | ---------------------- | ----------------------- | --------------------------- | ----------------------------- |
| 🔍 **Array + tgamma**     | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Compact and fast         | 💾 Potential precision issues |
| 🔺 **Map-based Counting** | 🟢 O(n)                | 🟢 O(1)                 | 🔧 Better precision         | 💾 Slightly more memory       |
| ⏰ **Switch-Case**        | 🟢 O(n)                | 🟢 O(1)                 | 🚀 O(1) character lookup    | 🔄 More lines of code         |
| 📊 **Lookup Table**       | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Fastest character lookup | 🔧 Larger code size           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                    | 🎖️ **Recommended Approach** | 🔥 **Performance Rating** |
| ---------------------------------- | --------------------------- | ------------------------- |
| ⚡ **Speed-critical applications** | 🥇 **Lookup Table**         | ★★★★★                     |
| 📊 **General purpose**             | 🥈 **Array + tgamma**       | ★★★★☆                     |
| 🎯 **High precision required**     | 🥉 **Map-based Counting**   | ★★★★☆                     |
| 🚀 **Memory-constrained**          | 🏅 **Switch-Case**          | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int vowelCount(String s) {
        int[] f = new int[5];
        for (char c : s.toCharArray())
            if ("aeiou".indexOf(c) >= 0) f["aeiou".indexOf(c)]++;
        int cnt = 0, prod = 1;
        for (int x : f) if (x > 0) { prod *= x; cnt++; }
        for (int i = 2; i <= cnt; i++) prod *= i;
        return cnt == 0 ? 0 : prod;
    }
}
```

## **🐍 Code (Python)**

```python
from math import prod, factorial
from collections import Counter
class Solution:
    def vowelCount(self, s):
        freq = Counter(c for c in s if c in 'aeiou')
        vals = list(freq.values())
        return prod(vals) * factorial(len(vals)) if vals else 0
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
