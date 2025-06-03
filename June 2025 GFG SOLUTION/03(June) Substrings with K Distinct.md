---
title: "🔡 Substrings with K Distinct | GFG Solution 🎯"
keywords📌: ["👉 substrings k distinct", "🤝 sliding window", "🔢 frequency count", "🧪 hashmap technique", "📈 string pattern", "📘 GFG", "🏁 competitive programming", "💪 string problems", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Substrings with K Distinct Characters problem using sliding window and optimized frequency count. 🚀"
date: 📅 2025-06-03
---

# *03. Substrings with K Distinct*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/count-number-of-substrings-with-exactly-k-distinct-characters/)

## **🧩 Problem Description**

Given a string consisting of lowercase characters and an integer `k`, the task is to count all possible substrings (not necessarily distinct) that have **exactly `k` distinct characters**.


## **📘 Examples**

### Example 1

```
Input: s = "abc", k = 2
Output: 2
Explanation: Possible substrings are ["ab", "bc"]
```

### Example 2

```
Input: s = "aba", k = 2
Output: 3
Explanation: Possible substrings are ["ab", "ba", "aba"]
```

### Example 3

```
Input: s = "aa", k = 1
Output: 3
Explanation: Possible substrings are ["a", "a", "aa"]
```

## **🔒 Constraints**

* \$1 \le |s| \le 10^6\$
* `s` contains only lowercase English letters
* \$1 \le k \le 26\$

## **✅ My Approach**

We use a **two-pass sliding window technique** to count the number of substrings with **exactly `k` distinct characters**. The idea is to leverage a helper function that counts substrings with **at most `k` distinct characters**, and then use the inclusion-exclusion principle to find the exact count.

### **💡 Idea:**

* Define a helper function `count(s, k)` that returns the number of substrings with **at most** `k` distinct characters.
* Use a **sliding window** with two pointers and a **frequency array of size 26** (since the string contains only lowercase letters).
* Expand the window by moving the right pointer, and keep track of the frequency of characters.
* If the number of distinct characters exceeds `k`, shrink the window from the left until the window contains at most `k` distinct characters.
* For each position `j`, add `(j - i + 1)` — the number of valid substrings ending at `j` — to the result.
* Finally, compute:

  ```
  substrings with exactly k distinct = count(s, k) - count(s, k - 1)
  ```

This subtraction removes substrings that have fewer than `k` distinct characters, leaving only those with exactly `k`.

### **⚙️ Algorithm Steps:**

1. Implement a helper function `count(s, k)`:

   * Initialize a frequency array `freq[26]` and two pointers `i = 0`, `j = 0`.
   * Iterate through the string with pointer `j`:

     * Increment frequency of `s[j]`.
     * If distinct characters exceed `k`, move `i` forward while updating frequencies until the window has at most `k` distinct characters.
     * Add `(j - i + 1)` to the result count for valid substrings ending at `j`.
2. Call `count(s, k)` and `count(s, k - 1)` and return their difference.


## **📝 Time and Auxiliary Space Complexity**

* **Time Complexity:**  O(n) — *Each character is processed at most twice (once when added to the window, once when removed).*
* **Auxiliary Space Complexity:**  O(1) — *Fixed-size frequency array of length 26 for lowercase English letters.*

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int count(string &s, int k) {
        int n = s.length(), ans = 0;
        vector<int> freq(26, 0);
        int i = 0, distinct = 0;
        for (int j = 0; j < n; ++j) {
            if (++freq[s[j] - 'a'] == 1) ++distinct;
            while (distinct > k)
                if (--freq[s[i++] - 'a'] == 0) --distinct;
            ans += j - i + 1;
        }
        return ans;
    }
    
    int countSubstr(string &s, int k) {
        return count(s, k) - count(s, k - 1);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ HashMap with Sliding Window**

Instead of a fixed-size array for lowercase, use an `unordered_map` for any character set (e.g., Unicode).

### 💡 Algorithm Steps:

1. Define helper `atMostK(string &s, int k)` that uses `unordered_map<char,int>` to count frequencies.
2. Maintain two pointers `i` and `j` over the string.
3. Increment `mp[s[j]]`; if it becomes 1, decrement `k`.
4. While `k < 0`, decrement `mp[s[i]]`; if it becomes 0, increment `k`, then increment `i`.
5. Accumulate `res += j - i + 1` for valid windows ending at `j`.
6. Return `atMostK(s, k) - atMostK(s, k - 1)`.

```cpp
class Solution {
  public:
    int atMostK(string &s, int k) {
        unordered_map<char, int> mp;
        int i = 0, res = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (++mp[s[j]] == 1) --k;
            while (k < 0)
                if (--mp[s[i++]] == 0) ++k;
            res += j - i + 1;
        }
        return res;
    }

    int countSubstr(string &s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(k)

### ✅ **Why This Approach?**

* Works with any character set (not just a–z).
* Maintains O(n) runtime with two-pointer sliding window.
* Slight overhead for hash operations but generalizes to Unicode or larger alphabets.

## 📊 **3️⃣ Brute Force (Nested Loops + Distinct Count)**

Enumerate every substring and count distinct characters directly.

### 💡 Algorithm Steps:

1. Initialize `ans = 0`.
2. For each start index `i` from 0 to n−1:

   1. Initialize a `vector<int> freq(26, 0)` or `unordered_set` to track seen characters.
   2. For each end index `j` from `i` to n−1:

      1. Increment frequency or insert `s[j]`.
      2. If distinct count equals `k`, increment `ans`.
      3. If distinct count exceeds `k`, break inner loop (further extensions only increase distinct).
3. Return `ans`.

```cpp
class Solution {
  public:
    int countSubstr(string &s, int k) {
        int n = s.length(), ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            int distinct = 0;
            for (int j = i; j < n; ++j) {
                if (++freq[s[j] - 'a'] == 1) ++distinct;
                if (distinct == k) ++ans;
                if (distinct > k) break;
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) in the best case (break early when `distinct > k`), up to O(n²) overall.
* **Auxiliary Space:** 💾 O(1) (or O(alphabet) for frequency).

### ✅ **Why This Approach?**

* Very straightforward: directly counts distinct for each substring.
* Useful for small strings or educational purposes.
* Not suitable for large inputs due to O(n²) scanning.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                     | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                                             | ⚠️ **Cons**                |
| ----------------------------------- | ---------------------- | ----------------------- | ------------------------------------------------------ | -------------------------- |
| 🔢 **Fixed Array + Sliding Window** | 🟢 O(n)                | 🟢 O(1)                 | Fastest for lowercase-a–z, minimal overhead            | Limited to fixed alphabet  |
| 🔁 **HashMap + Sliding Window**     | 🟢 O(n)                | 🟡 O(k)                 | Supports any character set (Unicode, larger alphabets) | Slight hash overhead       |
| 🧮 **Brute Force (Nested Loops)**   | 🔴 O(n²)               | 🟢 O(1)                 | Simple to implement and understand                     | Very slow on large strings |

### 🏆 **Best Choice by Scenario**

| 🎯 **Scenario**                                | 🥇 **Recommended Approach**     |
| ---------------------------------------------- | ------------------------------- |
| 🌐 Any character set (Unicode/large alphabets) | 🥇 HashMap + Sliding Window     |
| 🔥 Strictly lowercase English letters (a–z)    | 🥈 Fixed Array + Sliding Window |
| 📚 Educational or very small input size        | 🥉 Brute Force (Nested Loops)   |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    int count(String s, int k) {
        int[] freq = new int[26];
        int i = 0, ans = 0, distinct = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (++freq[s.charAt(j) - 'a'] == 1) ++distinct;
            while (distinct > k)
                if (--freq[s.charAt(i++) - 'a'] == 0) --distinct;
            ans += j - i + 1;
        }
        return ans;
    }

    int countSubstr(String s, int k) {
        return count(s, k) - count(s, k - 1);
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def count(self, s, k):
        freq = [0] * 26
        i = ans = distinct = 0
        for j in range(len(s)):
            if freq[ord(s[j]) - ord('a')] == 0:
                distinct += 1
            freq[ord(s[j]) - ord('a')] += 1
            while distinct > k:
                freq[ord(s[i]) - ord('a')] -= 1
                if freq[ord(s[i]) - ord('a')] == 0:
                    distinct -= 1
                i += 1
            ans += j - i + 1
        return ans

    def countSubstr(self, s, k):
        return self.count(s, k) - self.count(s, k - 1)
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
