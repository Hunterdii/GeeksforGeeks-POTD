---
title: "➕ Sum String | GFG Solution 🧮"
keywords🏷️: ["➕ string addition", "🧮 sum string", "🔄 recursion", "🧑‍💻 string manipulation", "📚 GFG", "🧑‍🏫 learning recursion", "🧑‍💻 manual addition"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Sum String problem: check if a numeric string follows a sum sequence using string addition and recursion. 🚀"
date: 📅 2025-06-08
---

# *08. Sum-String*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sum-string3151/1)



## 🧩 Problem Description

Given a digit string `s`, determine whether it can be split into more than two non-empty parts such that:

1. The rightmost part equals the integer sum of the two parts immediately before it.
2. This sum-rule applies recursively to the preceding parts.
3. No part may have leading zeros unless it is exactly `"0"`.



## 📘 Examples

### Example 1:
```

Input: s = "12243660"
Output: true
Explanation:
Split as ["12","24","36","60"]:
36 = 12 + 24
60 = 24 + 36

```

### Example 2:
```

Input: s = "1111112223"
Output: true
Explanation:
Split as ["1","111","112","223"]:
112 = 1 + 111
223 = 111 + 112

```

### Example 3:
```

Input: s = "123456"
Output: false
Explanation:
No valid recursive sum-split exists.

````



## 🔒 Constraints:

- `1 ≤ s.length() ≤ 100`  
- `s` consists only of digits `'0'–'9'`.



## **✅ My Approach**

### 💡 Idea

1. Try every possible pair of lengths for the first two numbers (`a`,`b`).
2. Skip any part that has a leading zero (length >1 and starts with `'0'`).
3. Recursively check that each subsequent substring equals the string-sum of the previous two:
   - Use a helper `addStrings(x,y)` to compute their sum as a string.
   - Compare with the next substring in `s`.
4. If we reach the end exactly, return `true`; otherwise backtrack.

### ⚙️ Algorithm Steps:

1. Let `n = s.length()`.  
2. For `len1` from `1` to `n-2`, and for `len2` from `1` to `n - len1 - 1`:
   - If `s[0..len1-1]` or `s[len1..len1+len2-1]` invalid (leading zero), continue.
   - Call `check(0, len1, len2)`. If it returns `true`, answer `true`.
3. If no split works, return `false`.

Helper `bool check(int idx, int l1, int l2)`:
- Extract `x = s.substr(idx, l1)`, `y = s.substr(idx+l1, l2)`.
- Compute `z = addStrings(x,y)`; let `l3 = z.length()`.
- If substring at `idx + l1 + l2` of length `l3` ≠ `z`, return `false`.
- If exactly reached end, return `true`.
- Else recurse with `(idx + l1, l2, l3)`.



## 📝 Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n³)  
  - Triple nested loops over `(len1, len2)` and recursive checks with string-addition/substr of O(n) each.
- **Expected Auxiliary Space Complexity:** O(n)  
  - Recursion depth and temporary strings up to length n.
 
## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    string addStrings(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        int carry = 0, n = a.size(), m = b.size();
        string res = "";
        for (int i = 0; i < m; ++i) {
            int s = (a[n - 1 - i] - '0') + (b[m - 1 - i] - '0') + carry;
            res = char(s % 10 + '0') + res;
            carry = s / 10;
        }
        for (int i = m; i < n; ++i) {
            int s = (a[n - 1 - i] - '0') + carry;
            res = char(s % 10 + '0') + res;
            carry = s / 10;
        }
        if (carry) res = char(carry + '0') + res;
        return res;
    }

    bool check(string &s, int i, int l1, int l2) {
        string x = s.substr(i, l1), y = s.substr(i + l1, l2);
        if ((x[0] == '0' && l1 > 1) || (y[0] == '0' && l2 > 1)) return false;
        string sum = addStrings(x, y);
        int l3 = sum.size();
        if (i + l1 + l2 + l3 > s.size()) return false;
        if (sum != s.substr(i + l1 + l2, l3)) return false;
        if (i + l1 + l2 + l3 == s.size()) return true;
        return check(s, i + l1, l2, l3);
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int l1 = 1; l1 < n; ++l1)
            for (int l2 = 1; l1 + l2 < n; ++l2)
                if (check(s, 0, l1, l2)) return true;
        return false;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Brute Force All Splits + Manual Addition**

### 💡 Algorithm Steps:

1. Try all possible pairs of substrings for the first two numbers (`a`, `b`) in the string.
2. For each pair:

   * Skip if either `a` or `b` starts with `'0'` and is longer than 1.
3. Use a helper `add()` function to simulate string-based addition.
4. Use DFS to check if the rest of the string follows the sum pattern:
   `a + b = c`, `b + c = d`, etc.

```cpp
class Solution {
  public:
    string add(string a, string b) {
        string res = "";
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res += sum % 10 + '0';
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(string &s, int i, string prev1, string prev2) {
        string sum = add(prev1, prev2);
        if (s.substr(i, sum.size()) != sum) return false;
        if (i + sum.size() == s.size()) return true;
        return dfs(s, i + sum.size(), prev2, sum);
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int l1 = 1; l1 < n; ++l1)
            for (int l2 = 1; l1 + l2 < n; ++l2) {
                string a = s.substr(0, l1), b = s.substr(l1, l2);
                if ((a[0] == '0' && a.size() > 1) || (b[0] == '0' && b.size() > 1)) continue;
                if (dfs(s, l1 + l2, a, b)) return true;
            }
        return false;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(N³) – due to triple nested traversal & substring checks
* **Auxiliary Space:** 💾 O(N) – for string recursion stack

### ✅ **Why This Approach?**

* Handles **string overflow** issues using manual addition.
* Good educational value to learn string manipulation + recursion.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                         | ⚠️ **Cons**                            |
| ------------------------------ | ---------------------- | ----------------------- | ---------------------------------- | -------------------------------------- |
| 🔁 Recursion + String Addition | 🟢 O(N³)               | 🟢 O(N)                 | Accurate, string-safe, recursive   | Slower due to overhead and deep calls  |
| 🔎 Brute Force + Manual Add    | 🔸 O(N³)               | 🔸 O(N)                 | Simpler logic, useful for learning | Redundant with recursion, less optimal |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                              | 🎖️ **Recommended Approach**    |
| -------------------------------------------- | ------------------------------- |
| 📏 Long strings or potential overflow issues | 🥇 **String Add + Recursion**   |
| 📘 Educational brute-force understanding     | 🥈 **Manual Brute Force (DFS)** |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public boolean isSumString(String s) {
        int n = s.length();
        for (int l1 = 1; l1 < n; l1++) {
            for (int l2 = 1; l1 + l2 < n; l2++) {
                if (check(s, 0, l1, l2)) return true;
            }
        }
        return false;
    }

    boolean check(String s, int i, int l1, int l2) {
        String x = s.substring(i, i + l1), y = s.substring(i + l1, i + l1 + l2);
        if ((x.length() > 1 && x.charAt(0) == '0') || (y.length() > 1 && y.charAt(0) == '0')) return false;
        String sum = add(x, y);
        int l3 = sum.length();
        if (i + l1 + l2 + l3 > s.length()) return false;
        String z = s.substring(i + l1 + l2, i + l1 + l2 + l3);
        if (!sum.equals(z)) return false;
        if (i + l1 + l2 + l3 == s.length()) return true;
        return check(s, i + l1, l2, l3);
    }

    String add(String a, String b) {
        if (a.length() < b.length()) return add(b, a);
        StringBuilder sb = new StringBuilder();
        int carry = 0, n = a.length(), m = b.length();
        for (int i = 0; i < m; i++) {
            int s = (a.charAt(n - 1 - i) - '0') + (b.charAt(m - 1 - i) - '0') + carry;
            sb.append(s % 10);
            carry = s / 10;
        }
        for (int i = m; i < n; i++) {
            int s = (a.charAt(n - 1 - i) - '0') + carry;
            sb.append(s % 10);
            carry = s / 10;
        }
        if (carry > 0) sb.append(carry);
        return sb.reverse().toString();
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def isSumString(self, s: str) -> bool:
        def add(a, b):
            return str(int(a) + int(b))
        
        def check(i, l1, l2):
            x, y = s[i:i + l1], s[i + l1:i + l1 + l2]
            if (len(x) > 1 and x[0] == '0') or (len(y) > 1 and y[0] == '0'):
                return False
            z = add(x, y)
            l3 = len(z)
            if i + l1 + l2 + l3 > len(s): return False
            if s[i + l1 + l2:i + l1 + l2 + l3] != z: return False
            if i + l1 + l2 + l3 == len(s): return True
            return check(i + l1, l2, l3)

        n = len(s)
        for l1 in range(1, n):
            for l2 in range(1, n - l1):
                if check(0, l1, l2): return True
        return False
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
