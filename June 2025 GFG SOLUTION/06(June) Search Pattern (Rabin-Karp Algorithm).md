---
title: "🔍 Search Pattern (Rabin-Karp Algorithm) | GFG Solution 🧠"
keywords🏷️: ["🔍 string matching", "🧪 Rabin-Karp", "🧠 hashing", "📘 GFG", "🔢 pattern search", "💡 substring search", "📚 DSA", "🏁 competitive programming"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution for Rabin-Karp based substring search. Fast, efficient pattern matching using rolling hash! 🚀"
date: 📅 2025-06-06
---

# *06. Search Pattern (Rabin-Karp Algorithm)*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1)


## **🧩 Problem Description**

Given two strings:

* A **text** string in which to search.
* A **pattern** string to find.

Return **all starting positions** (1-based) where the pattern occurs in the text. Use the **Rabin-Karp Algorithm** (rolling hash-based pattern matching).


## **📘 Examples**

### Example 1

```
Input: text = "birthdayboy", pattern = "birth"
Output: [1]
```

### Example 2

```
Input: text = "geeksforgeeks", pattern = "geek"
Output: [1, 9]
```


## **🔒 Constraints**

* \$1 \leq \text{len(text)} \leq 5 \times 10^5\$
* \$1 \leq \text{len(pattern)} \leq \text{len(text)}\$
* All characters are lowercase English letters (`a-z`)


## **✅ My Approach**

The **Rabin-Karp Algorithm** uses hashing to match the pattern with substrings in the text.

### Hashing Basics

* Convert strings to numerical hash using a rolling hash formula.
* If two hashes match, perform a direct string comparison to confirm (to avoid false positives from collisions).

### Algorithm Steps:

1. **Hash Function**:
   Use a **prime modulus `q`** and **radix/base `d = 256`** (covers lowercase letters).

2. **Precompute Hashes**:

   * Compute the hash of the `pattern` and the initial window in `text`.
   * Use a rolling hash to update hash as the window slides by 1 character.

3. **Match Check**:

   * When hash matches, check characters one by one to confirm.


## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(N + M), where `N` is text length and `M` is pattern length. We compute hashes in linear time and only compare strings when hashes match.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a fixed number of variables for hashing.



## 🧑‍💻 **Code (C++)**

```cpp
class Solution {
  public:
    vector<int> search(string pat, string txt) {
        int d = 256, q = 101, m = pat.length(), n = txt.length();
        int ph = 0, th = 0, h = 1;
        vector<int> res;
        for (int i = 0; i < m - 1; i++) h = (h * d) % q;
        for (int i = 0; i < m; i++) {
            ph = (d * ph + pat[i]) % q;
            th = (d * th + txt[i]) % q;
        }
        for (int i = 0; i <= n - m; i++) {
            if (ph == th) {
                bool match = true;
                for (int j = 0; j < m; j++)
                    if (txt[i + j] != pat[j]) { match = false; break; }
                if (match) res.push_back(i + 1);
            }
            if (i < n - m) {
                th = (d * (th - txt[i] * h) + txt[i + m]) % q;
                if (th < 0) th += q;
            }
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


### 📊 **2️⃣ Naive Matching (Brute Force)**

#### 💡 Idea:

Try all substrings of `text` of length `m` and compare with the `pattern`.

```cpp
class Solution {
  public:
    vector<int> search(string pat, string txt) {
        int n = txt.size(), m = pat.size();
        vector<int> res;
        for (int i = 0; i <= n - m; i++) {
            if (txt.substr(i, m) == pat)
                res.push_back(i + 1);
        }
        return res;
    }
};
```

#### 📝 Complexity:

* **Time:** O(N × M)
* **Space:** O(1)

#### ✅ Pros:

* Easy to understand and implement

#### ⚠️ Cons:

* Slow for large inputs
  
### ⚠️ Warning: TLE on Large Inputs
#### ✅ Test Cases Passed: 1111 / 1115
##### ❌ Result: Time Limit Exceeded (TLE) 


### 🆚 **Comparison of Approaches**

| 🚀 **Approach**          | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**        | ⚠️ **Cons**            |
| ------------------------ | ---------------------- | ----------------------- | ----------------- | ---------------------- |
| 🔍 Rabin-Karp            | 🟢 O(N + M)            | 🟢 O(1)                 | Fast and scalable | Hash collisions (rare) |
| 🐢 Naive Substring Match (TLE) | 🔸 O(N × M)            | 🟢 O(1)                 | Very simple       | Slow for large strings |


### 🏆 Best Choice Recommendation

| 🎯 **Scenario**                             | 🎖️ **Recommended Approach** |
| ------------------------------------------- | ---------------------------- |
| 📈 Large strings and fast matching required | 🥇 **Rabin-Karp Algorithm**  |
| 📋 Simple brute-force acceptable            | 🥈 **Naive Substring Match** |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    ArrayList<Integer> search(String pat, String txt) {
        int d = 256, q = 101, m = pat.length(), n = txt.length();
        int ph = 0, th = 0, h = 1;
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < m - 1; i++) h = (h * d) % q;
        for (int i = 0; i < m; i++) {
            ph = (d * ph + pat.charAt(i)) % q;
            th = (d * th + txt.charAt(i)) % q;
        }
        for (int i = 0; i <= n - m; i++) {
            if (ph == th) {
                boolean match = true;
                for (int j = 0; j < m; j++) {
                    if (txt.charAt(i + j) != pat.charAt(j)) {
                        match = false;
                        break;
                    }
                }
                if (match) res.add(i + 1);
            }
            if (i < n - m) {
                th = (d * (th - txt.charAt(i) * h) + txt.charAt(i + m)) % q;
                if (th < 0) th += q;
            }
        }
        return res;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def search(self, pat, txt):
        d, q, m, n = 256, 101, len(pat), len(txt)
        ph = th = 0; h = 1; res = []
        for i in range(m - 1): h = (h * d) % q
        for i in range(m):
            ph = (d * ph + ord(pat[i])) % q
            th = (d * th + ord(txt[i])) % q
        for i in range(n - m + 1):
            if ph == th and txt[i:i + m] == pat:
                res.append(i + 1)
            if i < n - m:
                th = (d * (th - ord(txt[i]) * h) + ord(txt[i + m])) % q
                if th < 0: th += q
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
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
