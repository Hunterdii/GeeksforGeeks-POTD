# _23. Total Decoding Messages_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1)

## **Problem Description**

A message containing letters **A-Z** is encoded using the following mapping:

```
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
```

Given a **numeric string `digits`**, return the total number of ways the message can be decoded.

## **Examples**

### **Example 1:**

#### **Input:**

```
digits = "123"
```

#### **Output:**

```
3
```

#### **Explanation:**

"123" can be decoded as:

- `"ABC"` (1, 2, 3)
- `"LC"` (12, 3)
- `"AW"` (1, 23)

### **Example 2:**

#### **Input:**

```
digits = "90"
```

#### **Output:**

```
0
```

#### **Explanation:**

"90" is not a valid encoding because '0' cannot be decoded.

### **Example 3:**

#### **Input:**

```
digits = "05"
```

#### **Output:**

```
0
```

#### **Explanation:**

"05" is not valid because leading zero makes it an invalid encoding.

### **Constraints:**

- $\(1 \leq \text{digits.length} \leq 10^3\)$

## **My Approach:**

## **Optimized Space Dynamic Programming**

### **Algorithm Steps:**

1. **Edge Case Handling**: If `digits[0] == '0'`, return 0 because it cannot be decoded.
2. **Use Two Variables (`prev2` and `prev1`)**:
   - `prev1`: Stores the number of ways to decode up to index `i-1`.
   - `prev2`: Stores the number of ways to decode up to index `i-2`.
3. **Iterate Over the String**:
   - If `digits[i]` is not `'0'`, add `prev1` to the current count.
   - If `digits[i-1]digits[i]` forms a valid number (10-26), add `prev2`.
4. **Update `prev2` and `prev1` for the next iteration**.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), as we iterate through the string once.
- **Expected Auxiliary Space Complexity:** O(1), since we use only two variables.

## **Code (C++)**

```cpp
class Solution {
public:
    int countWays(string &s) {
        if (s[0] == '0') return 0;
        int n = s.size(), prev2 = 1, prev1 = 1;
        for (int i = 1; i < n; i++) {
            int curr = 0;
            if (s[i] != '0') curr = prev1;
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26) curr += prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
```

<details>
  <summary><h2 align="center">🛠 Alternative Solutions</h2></summary>

## **2️⃣ Dynamic Programming with Array (O(N) Time, O(N) Space)**

### **Approach:**

- Instead of using **two variables (`prev1, prev2`)**, we maintain a **DP array `dp[i]`**, where `dp[i]` stores the number of ways to decode the string **up to index `i`**.
- Transition:
  - If `s[i]` is not `'0'`, add `dp[i-1]` to `dp[i]`.
  - If `s[i-1]s[i]` forms a valid two-digit number, add `dp[i-2]` to `dp[i]`.
- Return `dp[n]`.

```cpp
class Solution {
public:
    int countWays(string &s) {
        if (s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] != '0') dp[i + 1] = dp[i];
            int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (num >= 10 && num <= 26) dp[i + 1] += dp[i - 1];
        }
        return dp[n];
    }
};
```

## **3️⃣ Memoization (Top-Down DP, O(N) Time, O(N) Space)**

### **Approach:**

- Instead of iterative DP, use **recursion with memoization** to store results.
- Define `countWays(i)` as the number of ways to decode `s[i:]`.
- Base case: If `i == n`, return `1`.
- If `s[i]` is `'0'`, return `0` (invalid).
- Recursive cases:
  - Decode `s[i]` alone (`countWays(i+1)`).
  - Decode `s[i]s[i+1]` if valid (`countWays(i+2)`).

```cpp
class Solution {
public:
    int helper(string &s, int i, vector<int>& dp) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        if (dp[i] != -1) return dp[i];

        int ans = helper(s, i + 1, dp);
        if (i < s.size() - 1) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26) ans += helper(s, i + 2, dp);
        }
        return dp[i] = ans;
    }

    int countWays(string &s) {
        vector<int> dp(s.size(), -1);
        return helper(s, 0, dp);
    }
};
```

## **Comparison of Approaches**

| **Approach**                     | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**               | ⚠️ **Cons**                |
| -------------------------------- | ---------------------- | ----------------------- | ------------------------- | -------------------------- |
| **Optimized DP (Two Variables)** | 🟡 **O(N)**            | 🟢 **O(1)**             | Space efficient, fast     | Harder to understand       |
| **DP with Array**                | 🟡 **O(N)**            | 🟡 **O(N)**             | Easier to implement       | Extra space for `dp` array |
| **Memoization (Top-Down DP)**    | 🟡 **O(N)**            | 🔴 **O(N)**             | Good for recursion lovers | Higher memory consumption  |

## **💡 Best Choice?**

- ✅ **Optimized DP (O(1) Space)** is the best due to minimal space usage.
- ✅ **DP with Array** is useful for **educational purposes**, but not space efficient.
- ✅ **Memoization** is useful if you prefer recursion.

</details>

## **Code (Java)**

```java
class Solution {
    public int countWays(String s) {
        if (s.charAt(0) == '0') return 0;
        int prev2 = 1, prev1 = 1;
        for (int i = 1; i < s.length(); i++) {
            int curr = (s.charAt(i) != '0') ? prev1 : 0;
            if (s.charAt(i - 1) != '0' && Integer.parseInt(s.substring(i - 1, i + 1)) <= 26)
                curr += prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def countWays(self, s: str) -> int:
        if s[0] == '0': return 0
        prev2, prev1 = 1, 1
        for i in range(1, len(s)):
            curr = prev1 if s[i] != '0' else 0
            if s[i - 1] != '0' and int(s[i - 1:i + 1]) <= 26:
                curr += prev2
            prev2, prev1 = prev1, curr
        return prev1
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on **LinkedIn**: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a **star**! ⭐

---

<div align="center">
  <h3><b>📍 Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
