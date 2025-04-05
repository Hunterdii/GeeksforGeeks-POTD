# _8. Longest Palindrome in a String_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1)

## **Problem Description**

Given a string `s`, your task is to find the **longest palindromic substring** within `s`.

- A **substring** is a contiguous sequence of characters within the string (i.e., `s[i...j]` for `0 ≤ i ≤ j < len(s)`).
- A **palindrome** reads the same forwards and backwards, i.e., `reverse(s) == s`.
- If there are multiple palindromic substrings of the same maximum length, **return the first occurrence** from left to right.

## **Examples**

### **Example 1:**

#### **Input:**

```
s = "forgeeksskeegfor"
```

#### **Output:**

```
"geeksskeeg"
```

#### **Explanation:**

Possible palindromic substrings include `"kssk"`, `"ss"`, `"eeksskee"`, etc. However, **"geeksskeeg"** is the **longest** among them.

### **Example 2:**

#### **Input:**

```
s = "Geeks"
```

#### **Output:**

```
"ee"
```

#### **Explanation:**

The substring **"ee"** is the longest palindrome in `"Geeks"`.

### **Example 3:**

#### **Input:**

```
s = "abc"
```

#### **Output:**

```
"a"
```

#### **Explanation:**

All substrings `"a"`, `"b"`, and `"c"` have length 1, which is the maximum. Returning the first occurrence results in `"a"`.

### **Constraints:**

- $\(1 \leq s.\text{size()} \leq 10^3\)$
- `s` consists of only **lowercase English letters**.

## **My Approach**

### **Expand Around Center**

1. A **palindrome** can be expanded from its **center**.
2. For each index `i` in the string:
   - Consider two scenarios for the center:
     1. **Odd-length palindromes** (center at `i`).
     2. **Even-length palindromes** (center between `i` and `i+1`).
3. Expand outwards while **left and right characters match**.
4. **Track the maximum length palindrome** found and its start position.

This approach checks each possible center in `O(N)` and potentially expands in `O(N)`, leading to `O(N²)` overall time.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** **O(N²)**, because for each index we can expand in both directions.
- **Expected Auxiliary Space Complexity:** **O(1)**, since we use only a few extra variables for tracking indices and lengths.

## **Code (C++)**

```cpp
class Solution {
  public:
    string longestPalindrome(string &s) {
        int n = s.size(), start = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int l : {i, i + 1}) {
                int j = i;
                while (j >= 0 && l < n && s[j] == s[l]) j--, l++;
                if (l - j - 1 > maxLen) start = j + 1, maxLen = l - j - 1;
            }
        }
        return s.substr(start, maxLen);
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming Approach (O(N²) Time, O(N²) Space)**

#### **Algorithm Steps:**

1. Create a **2D DP table** `dp[i][j]`, where `dp[i][j]` is `true` if `s[i:j]` is a palindrome.
2. Set `dp[i][i] = true` (single-character substrings are palindromes).
3. If two adjacent characters are equal (`s[i] == s[i+1]`), set `dp[i][i+1] = true`.
4. For substrings of length 3 or more, use the formula:
   - `dp[i][j] = (s[i] == s[j] && dp[i+1][j-1])`
5. Keep track of the longest palindrome found and return it.

```cpp
class Solution {
public:
    string longestPalindrome(string &s) {
        string t = "#";
        for (char c : s) t += c, t += "#";
        int n = t.size(), center = 0, right = 0, maxLen = 0, start = 0;
        vector<int> p(n, 0);

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;
            if (i < right) p[i] = min(right - i, p[mirror]);
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
                p[i]++;
            if (i + p[i] > right) center = i, right = i + p[i];
            if (p[i] > maxLen) maxLen = p[i], start = (i - maxLen) / 2;
        }
        return s.substr(start, maxLen);
    }
};
```

🔹 **Easy to understand**  
🔹 **Uses O(N²) space** for the DP table

## **3️⃣ Manacher’s Algorithm (O(N) Time, O(N) Space)**

#### **Algorithm Steps:**

1. Transform the original string by inserting special characters (`#`) between characters to handle even-length palindromes.
   - Example: `"abc"` → `"#a#b#c#"`
2. Use a **palindrome radius array** `p[i]` to store the length of the longest palindrome centered at `i`.
3. Maintain a **center (`C`) and right boundary (`R`)**, representing the rightmost palindrome found.
4. If `i` is within `R`, mirror the value of `p[i]` from the symmetric point across `C`.
5. Expand the palindrome at `i` while characters match.
6. If the palindrome at `i` expands beyond `R`, update `C` and `R`.
7. Extract the longest palindrome from `p[i]`.

```cpp
class Solution {
public:
    string longestPalindrome(string &s) {
        if (s.empty()) return "";
        string t = "#";
        for (char c : s) t += c, t += "#";

        int n = t.size(), C = 0, R = 0, maxLen = 0, center = 0;
        vector<int> p(n, 0);

        for (int i = 0; i < n; i++) {
            int mirror = 2 * C - i;
            if (i < R) p[i] = min(R - i, p[mirror]);

            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1])
                p[i]++;

            if (i + p[i] > R) C = i, R = i + p[i];

            if (p[i] > maxLen) maxLen = p[i], center = i;
        }

        int start = (center - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};
```

🔹 **Fastest solution (O(N))**  
🔹 **Requires string transformation**

## **📊 Comparison of Approaches**

| **Approach**             | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                          | ⚠️ **Cons**                                 |
| ------------------------ | ---------------------- | ----------------------- | ------------------------------------ | ------------------------------------------- |
| **Expand Around Center** | 🟡 O(N²)               | 🟢 O(1)                 | Simple and uses constant extra space | Slower for larger strings                   |
| **Dynamic Programming**  | 🟡 O(N²)               | 🟡 O(N²)                | Straight-forward to implement        | High space usage (DP table)                 |
| **Manacher’s Algorithm** | 🟢 O(N)                | 🟢 O(N)                 | Fastest known approach               | String transformation can be tricky to code |

## 💡 **Best Choice?**

- ✅ **For best runtime performance:** Use **Manacher’s Algorithm (O(N))**.
- ✅ **For simplicity and minimal space usage:** Use **Expand Around Center (O(N²))**.
- ✅ **For detailed table-based logic understanding:** Use **Dynamic Programming (O(N²))**.

</details>

## **Code (Java)**

```java
class Solution {
    static String longestPalindrome(String s) {
        int n = s.length(), start = 0, maxLen = 0;
        for (int i = 0; i < n; i++)
            for (int l : new int[]{i, i + 1}) {
                int j = i;
                while (j >= 0 && l < n && s.charAt(j) == s.charAt(l)) {
                    j--;
                    l++;
                }
                if (l - j - 1 > maxLen) {
                    start = j + 1;
                    maxLen = l - j - 1;
                }
            }
        return s.substring(start, start + maxLen);
    }
}
```

## **Code (Python)**

```python
class Solution:
    def longestPalindrome(self, s):
        start, max_len = 0, 0
        for i in range(len(s)):
            for l in [i, i + 1]:
                j = i
                while j >= 0 and l < len(s) and s[j] == s[l]: j, l = j - 1, l + 1
                if l - j - 1 > max_len: start, max_len = j + 1, l - j - 1
        return s[start:start + max_len]
```

## **Contribution and Support**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
