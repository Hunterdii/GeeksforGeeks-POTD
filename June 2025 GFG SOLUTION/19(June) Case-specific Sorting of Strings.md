---
title: "🔤 Case-specific Sorting of Strings | GFG Solution 🔍"
keywords🏷️: ["🔤 case sorting", "🔠 uppercase lowercase", "🔍 frequency counting", "📍 in-place sorting", "📈 string processing", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Case-specific Sorting of Strings problem: sort uppercase and lowercase characters separately while maintaining their original positions. 🚀"
date: 📅 2025-06-19
---

# *19. Case-specific Sorting of Strings*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1)

## **🧩 Problem Description**

Given a string `s` consisting of only uppercase and lowercase characters. The task is to **sort uppercase and lowercase letters separately** such that if the ith place in the original string had an **Uppercase character** then it should not have a **lowercase character** after being sorted and **vice versa**.

An element maintains its case but gets sorted within its case group while preserving the original case pattern of the string.

## **📘 Examples**

### Example 1

```cpp
Input: s = "GEekS"
Output: EGekS
Explanation: 
- Uppercase positions: 0(G), 1(E), 4(S) → sorted: E, G, S
- Lowercase positions: 2(e), 3(k) → sorted: e, k
- Result: EGekS (maintaining original case positions)
```

### Example 2

```cpp
Input: s = "XWMSPQ"
Output: MPQSWX
Explanation: Since all characters are of the same case, we can simply perform a sorting operation on the entire string.
```

## **🔒 Constraints**

* $1 \le s.length() \le 10^5$

## **✅ My Approach**

The optimal approach uses **Frequency Counting** with **Bitwise Operations** for ultra-fast case detection:

### **Bitwise Optimized Frequency Counting**

1. **Case Detection:**
   * Use bitwise operation `c & 32` to detect case instantly.
   * If `c & 32` is true, it's lowercase; otherwise uppercase.

2. **Frequency Counting:**
   * Count frequency of each character using separate arrays for lowercase and uppercase.
   * Use direct ASCII arithmetic: `c - 97` for lowercase, `c - 65` for uppercase.

3. **In-place Reconstruction:**
   * Iterate through original string maintaining case positions.
   * Replace each character with the next available sorted character of the same case.
   * Use pointer tracking to avoid redundant searches.

4. **Pointer Optimization:**
   * Maintain separate pointers for lowercase and uppercase arrays.
   * Skip zero-frequency positions efficiently.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. We make two passes through the string - one for counting frequencies and one for reconstruction, both taking O(n) time.
* **Expected Auxiliary Space Complexity:** O(1), as we only use fixed-size arrays of 26 elements each for lowercase and uppercase character frequencies, which is constant space regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string caseSort(string &s) {
        int l[26] = {0}, u[26] = {0};
        for (char c : s) (c & 32) ? l[c - 97]++ : u[c - 65]++;
        int i = 0, j = 0;
        for (char &c : s) {
            if (c & 32) {
                while (!l[i]) i++;
                c = i + 97;
                l[i]--;
            } else {
                while (!u[j]) j++;
                c = j + 65;
                u[j]--;
            }
        }
        return s;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Frequency Array with Position Tracking**

### 💡 Algorithm Steps:

1. Count frequency of each character using arrays.
2. Maintain separate pointers for lowercase and uppercase.
3. Replace characters in-place with sorted equivalents.

```cpp
class Solution {
public:
    string caseSort(string &s) {
        int lower[26] = {0}, upper[26] = {0};
        for (char ch : s) {
            if (islower(ch)) lower[ch - 'a']++;
            else upper[ch - 'A']++;
        }
        int l = 0, u = 0;
        for (int i = 0; i < s.length(); i++) {
            if (islower(s[i])) {
                while (lower[l] == 0) l++;
                s[i] = 'a' + l;
                lower[l]--;
            } else {
                while (upper[u] == 0) u++;
                s[i] = 'A' + u;
                upper[u]--;
            }
        }
        return s;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + 26) = O(n)
* **Auxiliary Space:** 💾 O(1) - Fixed size arrays

### ✅ **Why This Approach?**

* Standard readable implementation.
* Clear separation of concerns.

## 📊 **3️⃣ Two-Pass Sorting with Vectors**

### 💡 Algorithm Steps:

1. Separate lowercase and uppercase characters.
2. Sort both groups independently.
3. Merge back maintaining original positions.

```cpp
class Solution {
public:
    string caseSort(string &s) {
        vector<char> lower, upper;
        for (char c : s) {
            if (islower(c)) lower.push_back(c);
            else upper.push_back(c);
        }
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        int l = 0, u = 0;
        for (char &c : s) {
            if (islower(c)) c = lower[l++];
            else c = upper[u++];
        }
        return s;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Due to sorting
* **Auxiliary Space:** 💾 O(n) - For storing characters

### ✅ **Why This Approach?**

* Intuitive separation and sorting.
* Works with any character set.

## 📊 **4️⃣ Counting Sort with String Builder**

### 💡 Algorithm Steps:

1. Count frequency using counting sort technique.
2. Build result string character by character.
3. Use string builder for efficiency.

```cpp
class Solution {
public:
    string caseSort(string &s) {
        int freq[128] = {0};
        string result = s;
        for (char c : s) freq[c]++;
        
        for (int i = 0; i < s.length(); i++) {
            if (islower(s[i])) {
                for (int j = 'a'; j <= 'z'; j++) {
                    if (freq[j] > 0) {
                        result[i] = j;
                        freq[j]--;
                        break;
                    }
                }
            } else {
                for (int j = 'A'; j <= 'Z'; j++) {
                    if (freq[j] > 0) {
                        result[i] = j;
                        freq[j]--;
                        break;
                    }
                }
            }
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * 26) = O(n)
* **Auxiliary Space:** 💾 O(128) = O(1)

### ✅ **Why This Approach?**

* Works with extended ASCII.
* Flexible for different character ranges.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                    |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------ |
| 🔍 **Bitwise Optimized**          | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Ultra-fast, minimal operations | 🧮 Less readable              |
| 🔄 **Frequency Array**            | 🟢 O(n)                | 🟢 O(1)                 | 🔧 Clear and readable            | 🐢 More function calls        |
| 🔺 **Two-Pass Sorting**           | 🟡 O(n log n)          | 🟡 O(n)                 | 🚀 Intuitive logic               | 💾 Higher complexity          |
| 📊 **Counting Sort**              | 🟢 O(n)                | 🟢 O(1)                 | 🏎️ Flexible character support    | 🔄 More iterations per char    |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ Maximum performance, competitive programming    | 🥇 **Bitwise Optimized**       | ★★★★★                     |
| 🔧 Production code, readability important         | 🥈 **Frequency Array**         | ★★★★☆                     |
| 📊 Educational purposes, clear logic               | 🥉 **Two-Pass Sorting**        | ★★★☆☆                     |
| 🏎️ Extended character set support                 | 🏅 **Counting Sort**           | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static String caseSort(String s) {
        int[] l = new int[26], u = new int[26];
        char[] c = s.toCharArray();
        for (char ch : c) {
            if (ch >= 'a') l[ch - 97]++;
            else u[ch - 65]++;
        }
        int i = 0, j = 0;
        for (int k = 0; k < c.length; k++) {
            if (c[k] >= 'a') {
                while (l[i] == 0) i++;
                c[k] = (char)(i + 97);
                l[i]--;
            } else {
                while (u[j] == 0) j++;
                c[k] = (char)(j + 65);
                u[j]--;
            }
        }
        return new String(c);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def caseSort(self, s):
        l, u = [0] * 26, [0] * 26
        for c in s:
            if c.islower():
                l[ord(c) - 97] += 1
            else:
                u[ord(c) - 65] += 1
        r, i, j = list(s), 0, 0
        for k in range(len(s)):
            if s[k].islower():
                while l[i] == 0:
                    i += 1
                r[k] = chr(i + 97)
                l[i] -= 1
            else:
                while u[j] == 0:
                    j += 1
                r[k] = chr(j + 65)
                u[j] -= 1
        return ''.join(r)
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
