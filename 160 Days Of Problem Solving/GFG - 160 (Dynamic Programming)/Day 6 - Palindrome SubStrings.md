---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Dynamic Programming
  - Strings
  - palindrome
---

# 🚀 _Day 6. Palindrome SubStrings_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1)

## 💡 **Problem Description:**

Given a string **s**, count all **palindromic substrings** present in the string where the **length of each palindromic substring** is **greater than or equal to 2**.

## 🔍 **Example Walkthrough:**

### **Example 1**

**Input:**

```
s = "abaab"
```

**Output:**

```
3
```

**Explanation:**  
All palindromic substrings are: `"aba"`, `"aa"`, and `"baab"`.

### **Example 2**

**Input:**

```
s = "aaa"
```

**Output:**

```
3
```

**Explanation:**  
All palindromic substrings are: `"aa"`, `"aa"`, and `"aaa"`.

### **Example 3**

**Input:**

```
s = "abbaeae"
```

**Output:**

```
4
```

**Explanation:**  
All palindromic substrings are: `"bb"`, `"abba"`, `"aea"`, and `"eae"`.

## **Constraints**

- $\( 2 \leq \text{length}(s) \leq 10^3 \)$
- String contains only **lowercase English characters**.

## 🎯 **My Approach:**

### **Dynamic Programming (DP) (O(N²) Time, O(N²) Space)**

1. We use a **2D boolean DP array** `dp[i][j]` to indicate whether the substring `s[i..j]` is a palindrome.
2. **Base cases**: Every single character is trivially a palindrome (we won't count single-character palindromes as per problem statement).
3. We fill the DP table in a manner that checks if the **characters at both ends** match and if the **inside substring** is also a palindrome.
4. Whenever we find `dp[i][j] = true` and `(j - i + 1) >= 2`, we **increment** our palindrome count.
5. Return the final count of **palindromic substrings** of length >= 2.

### **Algorithm Steps**

1. Create a 2D array `dp[n][n]`, initialized to `false`, where `n` is the length of `s`.
2. Traverse the string **in reverse order** for the starting index `i` (from `n-1` down to `0`).
3. Set `dp[i][i] = true` for all `i` (single-character palindromes, though not counted, are needed to build multi-character palindromes).
4. For each `i`, iterate `j` from `i+1` to `n-1`:
   - If `s[i] == s[j]` and the substring in-between is a palindrome (or `j - i == 1` for adjacent chars), set `dp[i][j] = true`.
   - If `dp[i][j]` is `true`, **increment** the count.
5. The result is the total count of palindromic substrings of length ≥ 2.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** **O(N²)**, where N is the length of the string. We have nested loops iterating through the string to fill the DP table.
- **Expected Auxiliary Space Complexity:** **O(N²)**, for maintaining the 2D DP table.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    int countPS(string& s) {
        int n = s.size(), res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = true;
            for (int j = i + 1; j < n; ++j)
                if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]))
                    dp[i][j] = true, res++;
        }
        return res;
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **1️⃣ Expand Around Center (O(N²) Time, O(1) Space)**

**Idea:**

- Treat each index (and index gap) as a potential palindrome center.
- Expand outward while the characters match.
- Count palindromic substrings of length ≥ 2.

```cpp
class Solution {
public:
    int countPS(string& s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; --l, ++r) res++;
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; --l, ++r) res++;
        }
        return res - n;
    }
};
```

🔹 **No extra space needed**  
🔹 **Simple to implement**

## **Code (Java)**

```java
class Solution {
    public int countPS(String s) {
        int n = s.length(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int l = i, r = i; l >= 0 && r < n && s.charAt(l) == s.charAt(r); l--, r++) res++;
            for (int l = i, r = i + 1; l >= 0 && r < n && s.charAt(l) == s.charAt(r); l--, r++) res++;
        }
        return res - n;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def countPS(self, s):
        n, res = len(s), 0
        for i in range(n):
            l, r = i, i
            while l >= 0 and r < n and s[l] == s[r]: res += 1; l -= 1; r += 1
            l, r = i, i + 1
            while l >= 0 and r < n and s[l] == s[r]: res += 1; l -= 1; r += 1
        return res - n
```

## **2️⃣ Manacher’s Algorithm (O(N) Time, O(N) Space)**

**Idea:**

- Transform string into a format with separators (e.g., `#a#b#a#b#`).
- Use Manacher’s algorithm to find palindromes in `O(N)`.
- Count palindromes of length ≥ 2 from the computed radius array.

```cpp
class Solution {
public:
    int countPS(string s) {
        string t = "#";
        for (char c : s) t += c + string("#");
        int n = t.size(), res = 0;
        vector<int> p(n, 0);
        int c = 0, r = 0;

        for (int i = 1; i < n - 1; i++) {
            int mirr = 2 * c - i;
            if (i < r) p[i] = min(r - i, p[mirr]);

            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1])
                p[i]++;

            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }

            res += (p[i] / 2);
        }

        return res;
    }
};
```

🔹 **Fastest for large `N`**  
🔹 **Trickier to implement**

## **📊 Comparison of Approaches**

| **Approach**                 | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                           | ⚠️ **Cons**               |
| ---------------------------- | ---------------------- | ----------------------- | ------------------------------------- | ------------------------- |
| **Dynamic Programming (DP)** | 🟡 O(N²)               | 🟡 O(N²)                | Reliable and efficient for mid-size N | Requires 2D DP table      |
| **Expand Around Center**     | 🟡 O(N²)               | 🟢 O(1)                 | Simple and space-efficient            | Slower for very large `N` |
| **Manacher’s Algorithm**     | 🟢 O(N)                | 🟡 O(N)                 | Fastest for `N > 10⁵`                 | Complex to implement      |

## 💡 **Best Choice?**

- ✅ **For simplicity:** Use **Expand Around Center**.
- ✅ **For optimal runtime on large inputs:** Use **Manacher’s Algorithm**.
- ✅ **For learning DP concepts:** Use the **Dynamic Programming** approach.

</details>

## **Code (Java)**

```java
class Solution {
    public int countPS(String s) {
        int n = s.length(), res = 0;
        boolean[][] dp = new boolean[n][n];
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = true;
            for (int j = i + 1; j < n; j++)
                if (s.charAt(i) == s.charAt(j) && (j - i == 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    res++;
                }
        }
        return res;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def countPS(self, s):
        n, res = len(s), 0
        dp = [[False] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = True
            for j in range(i + 1, n):
                if s[i] == s[j] and (j - i == 1 or dp[i + 1][j - 1]):
                    dp[i][j] = True
                    res += 1
        return res
```

> **Note:** Single-character palindromes are not counted as per problem statement. All approaches shown ensure only palindromes of length **≥ 2** are incremented.

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
