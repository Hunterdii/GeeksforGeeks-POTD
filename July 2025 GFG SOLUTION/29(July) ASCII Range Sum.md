---
title: "📝 ASCII Range Sum | GFG Solution 🔍"
keywords🏷️: ["📝 ascii sum", "🔍 string processing", "📍 character tracking", "📈 array iteration", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the ASCII Range Sum problem: find ASCII sum of characters between first and last occurrence of each character using efficient character tracking. 🚀"
date: 📅 2025-07-29
---

# *29. ASCII Range Sum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/ascii-range-sum/1)

## **🧩 Problem Description**

Given a string `s` consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.

Return all such **non-zero sums** (order does not matter).

## **📘 Examples**

### Example 1

```cpp
Input: s = "abacab"
Output: [293, 294]
Explanation: characters 'a' and 'b' appear more than once:
'a' : between positions 1 and 5 → characters are b, a, c and ascii sum is 98 + 97 + 99 = 294.
'b' : between positions 2 and 6 → characters are a, c, a and ascii sum is 97 + 99 + 97 = 293.
```

### Example 2

```cpp
Input: s = "acdac"
Output: [197, 199]
Explanation: characters 'a' and 'c' appear more than once:
'a' : between positions 1 and 4 → characters are c, d and ascii sum is 99 + 100 = 199.
'c' : between positions 2 and 5 → characters are d, a and ascii sum is 100 + 97 = 197.
```

## **🔒 Constraints**

* $1 \le s.size() \le 10^5$

## **✅ My Approach**

The optimal approach uses **Character Position Tracking** with **Array Iteration** to efficiently find first and last occurrences of each character and calculate ASCII sums:

### **Character Tracking + Range Sum Calculation**

1. **Initialize Variables:**
   * Use a result vector to store non-zero ASCII sums.
   * For each character in the alphabet (a-z), track first and last positions.

2. **Find Character Positions:**
   * For each of the 26 lowercase letters, scan the string to find:
     * First occurrence position (`first`)
     * Last occurrence position (`last`)

3. **Calculate Range Sum:**
   * If a character appears more than once (`last > first`):
     * Sum ASCII values of all characters between first and last positions (exclusive).
     * Add to result if sum is non-zero.

4. **Process All Characters:**
   * Repeat for all 26 letters to ensure no character is missed.

5. **Return Result:**
   * Return vector containing all non-zero ASCII sums.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(26 × n), where n is the length of the string. We iterate through the string 26 times (once for each letter) to find first and last occurrences, plus additional iterations for range sum calculations.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables and the result vector (not counting output space).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> asciirange(string& s) {
        vector<int> result;
        int n = s.size();
        for (int i = 0; i < 26; i++) {
            int first = -1, last = -1;
            for (int j = 0; j < n; j++) {
                if (s[j] - 'a' == i) {
                    if (first == -1) first = j;
                    last = j;
                }
            }
            if (first != -1 && last > first) {
                int sum = 0;
                for (int k = first + 1; k < last; k++) sum += s[k];
                if (sum) result.push_back(sum);
            }
        }
        return result;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass with Character Tracking**

### 💡 Algorithm Steps:

1. Use arrays to track first/last positions while iterating once through string.
2. Simultaneously build character frequency map for quick lookup.
3. Calculate ASCII sums only for characters with valid ranges.
4. Optimize by avoiding redundant iterations over the alphabet.

```cpp
class Solution {
public:
    vector<int> asciirange(string& s) {
        vector<int> first(26, -1), last(26, -1), result;
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && last[i] > first[i]) {
                int sum = 0;
                for (int j = first[i] + 1; j < last[i]; j++) sum += s[j];
                if (sum) result.push_back(sum);
            }
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + 26×k) where k is average range size
* **Auxiliary Space:** 💾 O(1) - Fixed size arrays for 26 characters

### ✅ **Why This Approach?**

* Clean separation of position tracking and sum calculation
* Predictable performance with minimal memory overhead
* Easy to debug and maintain

## 📊 **3️⃣ Prefix Sum Optimization**

### 💡 Algorithm Steps:

1. Build prefix sum array for O(1) range sum queries.
2. Track character positions in single pass through string.
3. Use prefix sums to calculate range sums instantly.
4. Avoid nested loops for sum calculation entirely.

```cpp
class Solution {
public:
    vector<int> asciirange(string& s) {
        int n = s.size();
        vector<int> prefix(n + 1, 0), first(26, -1), last(26, -1), result;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + s[i];
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && last[i] > first[i]) {
                int sum = prefix[last[i]] - prefix[first[i] + 1];
                if (sum) result.push_back(sum);
            }
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass plus constant alphabet iteration
* **Auxiliary Space:** 💾 O(n) - Prefix sum array storage

### ✅ **Why This Approach?**

* Optimal time complexity for large strings
* Constant time range sum queries
* Scalable for multiple range queries

## 📊 **4️⃣ Hash Map Based Approach**

### 💡 Algorithm Steps:

1. Use hash map to store character positions dynamically.
2. Only track characters that actually appear in string.
3. Process only relevant characters instead of full alphabet.
4. Memory efficient for sparse character distributions.

```cpp
class Solution {
public:
    vector<int> asciirange(string& s) {
        unordered_map<char, pair<int, int>> positions;
        vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            if (positions.find(s[i]) == positions.end()) {
                positions[s[i]] = {i, i};
            } else {
                positions[s[i]].second = i;
            }
        }
        for (auto& p : positions) {
            if (p.second.second > p.second.first) {
                int sum = 0;
                for (int j = p.second.first + 1; j < p.second.second; j++) {
                    sum += s[j];
                }
                if (sum) result.push_back(sum);
            }
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + c×k) where c is unique characters, k is average range
* **Auxiliary Space:** 💾 O(c) - Storage for unique characters only

### ✅ **Why This Approach?**

* Memory efficient for strings with few unique characters
* Dynamic allocation based on actual character usage
* Good for strings with limited alphabet subset

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Character Iteration**         | 🟡 O(26×n)            | 🟢 O(1)                 | 🎯 Simple logic                   | 🐌 Multiple string traversals        |
| 🏷️ **Single Pass Tracking**       | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal space & time           | 🔧 Still needs range sum loops       |
| ⚡ **Prefix Sum**                  | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Fastest range queries          | 💾 Extra space for prefix array      |
| 🗺️ **Hash Map**                   | 🟢 O(n)                | 🟢 O(c)                 | 📊 Adaptive memory usage          | 🔍 Hash map overhead                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General purpose**                            | 🥇 **Single Pass Tracking**          | ★★★★★                     |
| ⚡ **Multiple range queries**                      | 🥈 **Prefix Sum**                    | ★★★★★                     |
| 💾 **Memory constrained**                         | 🥉 **Hash Map**                      | ★★★★☆                     |
| 📖 **Simplicity priority**                        | 🏅 **Character Iteration**           | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> asciirange(String s) {
        ArrayList<Integer> result = new ArrayList<>();
        int n = s.length();
        for (int i = 0; i < 26; i++) {
            int first = -1, last = -1;
            for (int j = 0; j < n; j++) {
                if (s.charAt(j) - 'a' == i) {
                    if (first == -1) first = j;
                    last = j;
                }
            }
            if (first != -1 && last > first) {
                int sum = 0;
                for (int k = first + 1; k < last; k++)
                    sum += s.charAt(k);
                if (sum != 0) result.add(sum);
            }
        }
        return result;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def asciirange(self, s):
        result = []
        positions = {}
        
        for i, char in enumerate(s):
            if char not in positions:
                positions[char] = [i, i]
            else:
                positions[char][1] = i
        
        for char in sorted(positions.keys()):
            first, last = positions[char]
            if last > first:
                total = sum(ord(s[j]) for j in range(first + 1, last))
                if total:
                    result.append(total)
        
        return result
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
