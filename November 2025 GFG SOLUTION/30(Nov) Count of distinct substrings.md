---
title: "🔤 Count of Distinct Substrings | GFG Solution 🔍"
keywords🏷️: ["🔤 count substrings", "🌲 trie data structure", "📊 string algorithms", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Count of Distinct Substrings problem: find total number of unique non-empty substrings using efficient trie-based approach. 🚀"
date: 📅 2025-11-30
---

# *30. Count of Distinct Substrings*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1)

## **🧩 Problem Description**

You are given a string `s` consisting of lowercase English characters. Your task is to determine the **total number of distinct non-empty substrings** present in the string.

A substring is defined as a contiguous block of characters within the string. Two substrings are considered distinct if their contents differ, even if they originate from different positions in the string.

**Note:** The empty substring is not counted.

## **📘 Examples**

### Example 1

```cpp
Input: s = "ababa"
Output: 9
Explanation: All distinct substrings of "ababa" are: "a", "b", "ab", "ba", "aba", "bab", "abab", "baba", "ababa".
```

### Example 2

```cpp
Input: s = "aaa"
Output: 3
Explanation: The distinct substrings of "aaa" are: "a", "aa", "aaa".
```

## **🔒 Constraints**

* $1 \le \text{s.size()} \le 3000$

## **✅ My Approach**

The optimal approach uses a **Trie (Prefix Tree)** data structure to efficiently count distinct substrings:

### **Trie-Based Substring Counting**

1. **Initialize Trie:**
   * Create a trie root node with 26 children (for each lowercase letter).
   * Maintain a counter to track newly created nodes.

2. **Generate All Suffixes:**
   * For each starting position `i` in the string, consider it as the beginning of a suffix.
   * Start from position `i` and traverse to the end of the string.

3. **Insert Characters into Trie:**
   * For each character in the current suffix, navigate through the trie.
   * If a child node doesn't exist for the current character, create it and increment the counter.
   * Each new node represents a new unique substring.

4. **Count Unique Substrings:**
   * The total count of new nodes created equals the number of distinct substrings.
   * Each path from root to any node represents a unique substring.

5. **Return Result:**
   * Return the final count of distinct substrings.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²), where n is the length of the string. We generate all possible substrings by iterating through each starting position and extending to the end, and each character insertion in the trie takes O(1) time.
* **Expected Auxiliary Space Complexity:** O(n²), as in the worst case (all characters are distinct), the trie will store all possible substrings, requiring space proportional to the total number of characters across all unique substrings.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countSubs(string& s) {
        int cnt = 0, n = s.length();
        struct Node { Node* c[26] = {}; };
        Node* root = new Node();
        for (int i = 0; i < n; i++) {
            Node* cur = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!cur->c[idx]) {
                    cur->c[idx] = new Node();
                    cnt++;
                }
                cur = cur->c[idx];
            }
        }
        return cnt;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Set-Based Approach**

### 💡 Algorithm Steps:

1. Use an unordered set to store all unique substrings.
2. Generate all possible substrings using nested loops.
3. Insert each substring into the set for automatic deduplication.
4. Return the size of the set as the count.

```cpp
class Solution {
public:
    int countSubs(string& s) {
        unordered_set<string> st;
        for (int i = 0; i < s.length(); i++)
            for (int j = i; j < s.length(); j++)
                st.insert(s.substr(i, j - i + 1));
        return st.size();
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n³) - Substring generation and insertion
* **Auxiliary Space:** 💾 O(n²) - Storage for all substrings

### ✅ **Why This Approach?**

* Simple and intuitive implementation
* Automatic handling of duplicates via set
* Easy to debug and verify

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1121 test cases due to time constraints).


## 📊 **3️⃣ Suffix Array Approach**

### 💡 Algorithm Steps:

1. Build a suffix array of all suffixes.
2. Sort the suffix array lexicographically.
3. Compute longest common prefix between consecutive suffixes.
4. Calculate unique substrings using formula: total substrings minus duplicate LCP counts.

```cpp
class Solution {
public:
    int countSubs(string& s) {
        int n = s.length();
        vector<string> suf;
        for (int i = 0; i < n; i++) suf.push_back(s.substr(i));
        sort(suf.begin(), suf.end());
        int cnt = n * (n + 1) / 2;
        for (int i = 1; i < n; i++) {
            int lcp = 0;
            while (lcp < min(suf[i].length(), suf[i - 1].length()) && 
                   suf[i][lcp] == suf[i - 1][lcp]) lcp++;
            cnt -= lcp;
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² log n) - Suffix sorting dominates
* **Auxiliary Space:** 💾 O(n²) - Storage for suffixes

### ✅ **Why This Approach?**

* Mathematical optimization reduces redundant checking
* Scales better for very large strings
* Classic string algorithm pattern

## 📊 **4️⃣ Optimized Trie with Inline Node**

### 💡 Algorithm Steps:

1. Create a compact trie structure with inline node definition.
2. Insert all suffixes starting from each position.
3. Count new nodes created during insertion.
4. Each new node represents a unique substring.

```cpp
class Solution {
public:
    int countSubs(string& s) {
        struct T { T* ch[26] = {}; };
        T* r = new T();
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            T* p = r;
            for (int j = i; j < s.size(); j++) {
                if (!p->ch[s[j] - 'a']) {
                    p->ch[s[j] - 'a'] = new T();
                    res++;
                }
                p = p->ch[s[j] - 'a'];
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Optimal for trie-based approach
* **Auxiliary Space:** 💾 O(n²) - Worst case trie storage

### ✅ **Why This Approach?**

* Most space-efficient trie implementation
* Compact code with inline struct
* Best balance of readability and performance

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🌲 **Trie Standard**              | 🟢 O(n²)               | 🟡 O(n²)                | 🚀 Optimal time complexity        | 💾 Moderate space usage              |
| 🔍 **Set-Based**                  | 🔴 O(n³)               | 🟡 O(n²)                | 📖 Simplest implementation        | 🐌 Slowest time complexity           |
| 📊 **Suffix Array**               | 🟡 O(n² log n)         | 🟡 O(n²)                | 🎯 Mathematical elegance          | 🔧 Complex to implement              |
| ⚡ **Optimized Trie**             | 🟢 O(n²)               | 🟢 O(n²)                | ⭐ Most compact code              | 🔧 Requires understanding tries      |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Optimized Trie**                | ★★★★★                     |
| 📖 **Learning/Prototyping**                           | 🥈 **Set-Based**                     | ★★★☆☆                     |
| 🔧 **Large strings (n > 10⁴)**                       | 🥉 **Suffix Array**                  | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Trie Standard**                 | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static int countSubs(String s) {
        class Node { Node[] c = new Node[26]; }
        Node root = new Node();
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            Node cur = root;
            for (int j = i; j < n; j++) {
                int idx = s.charAt(j) - 'a';
                if (cur.c[idx] == null) {
                    cur.c[idx] = new Node();
                    cnt++;
                }
                cur = cur.c[idx];
            }
        }
        return cnt;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countSubs(self, s):
        class Node:
            def __init__(self):
                self.c = [None] * 26
        root, cnt, n = Node(), 0, len(s)
        for i in range(n):
            cur = root
            for j in range(i, n):
                idx = ord(s[j]) - ord('a')
                if not cur.c[idx]:
                    cur.c[idx] = Node()
                    cnt += 1
                cur = cur.c[idx]
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
