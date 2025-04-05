# _10. Edit Distance_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/edit-distance3702/1)

## **Problem Description**

Given two strings **s1** and **s2**, you need to find the minimum number of operations required to convert **s1** into **s2**. The valid operations are:

1. **Insert** a character at any position.
2. **Delete** any character from the string.
3. **Replace** any character with another character.

## **Examples**

### **Example 1:**

#### **Input:**

```
s1 = "geek"
s2 = "gesek"
```

#### **Output:**

```
1
```

#### **Explanation:**

We can insert `'s'` between the two `'e'` in **"geek"** to form **"gesek"**.

### **Example 2:**

#### **Input:**

```
s1 = "gfg"
s2 = "gfg"
```

#### **Output:**

```
0
```

#### **Explanation:**

The strings are already the same, so **0** operations are required.

### **Example 3:**

#### **Input:**

```
s1 = "abcd"
s2 = "bcfe"
```

#### **Output:**

```
3
```

#### **Explanation:**

- Remove `'a'` from **"abcd"** → **"bcd"**
- Replace `'d'` with `'f'` → **"bcf"**
- Insert `'e'` at the end → **"bcfe"**

### **Constraints:**

- $\(1 \leq s1.length(), s2.length() \leq 10^3\)$
- Both strings are in lowercase.

## **My Approach**

### **Space-Optimized Dynamic Programming**

1. We use **two 1D arrays** (`prev` and `curr`) of size \( n+1 \) (where \( n \) is the length of \( s2 \)).
2. **Initialize** the `prev` array such that `prev[j] = j`, meaning if \( s1 \) is empty, it takes `j` operations (all inserts) to match \( s2[0..j-1] \).
3. **Iterate** over each character in \( s1 \) (index `i`) and fill `curr`:
   - `curr[0] = i` (if \( s2 \) is empty, we need `i` deletions to match).
   - For each `j` in \( s2 \), compare `s1[i-1]` with `s2[j-1]`:
     - If they match, carry over `prev[j-1]`.
     - Otherwise, `curr[j] = 1 + min({ replace, delete, insert })`.
4. **Swap** `prev` and `curr` after each iteration to save space.
5. Finally, `prev[n]` holds the edit distance.

### **Algorithm Steps:**

1. Let $\( m = \text{length}(s1), n = \text{length}(s2) \)$.
2. Initialize `prev` array of size \( n+1 \) with `prev[j] = j`.
3. Loop `i` from `1` to `m`:
   - Set `curr[0] = i`.
   - For each `j` from `1` to `n`:
     - If `s1[i-1] == s2[j-1]`, then `curr[j] = prev[j-1]`.
     - Else `curr[j] = 1 + min( prev[j-1], prev[j], curr[j-1] )`.
   - Swap `prev` and `curr`.
4. Answer is `prev[n]`.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** $\( O(M \times N) \)$, as we iterate through each character of $\( s1 \)$ and $\( s2 \)$.
- **Expected Auxiliary Space Complexity:** $\( O(N) \)$, because we only keep two 1D arrays of size $\( n+1 \)$.

## **Code (C++)**

```cpp
class Solution {
public:
    int editDistance(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<int> prev(n + 1), curr(n + 1);
        iota(prev.begin(), prev.end(), 0);
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++)
                curr[j] = s1[i-1] == s2[j-1] ? prev[j-1] : 1 + min({prev[j-1], prev[j], curr[j-1]});
            swap(prev, curr);
        }
        return prev[n];
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming (O(M _ N) Time, O(M _ N) Space)**

**Idea:**

- Create a 2D DP array where `dp[i][j]` represents the minimum operations to convert `s1[0...i-1]` to `s2[0...j-1]`.
- If characters match, carry forward the diagonal value.
- Otherwise, consider the minimum of insert, delete, and replace.

```cpp
class Solution {
public:
    int editDistance(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
        return dp[m][n];
    }
};
```

🔹 **More intuitive for understanding**  
🔹 **Easier to debug**

## **📊 Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**              | ⚠️ **Cons**              |
| --------------------------- | ---------------------- | ----------------------- | ------------------------ | ------------------------ |
| **Space Optimized DP (1D)** | 🟡 O(M \* N)           | 🟢 O(N)                 | Efficient for large data | Slightly harder to debug |
| **DP (2D Table)**           | 🟡 O(M \* N)           | 🟡 O(M \* N)            | Easier to understand     | More memory-intensive    |

## 💡 **Best Choice?**

- ✅ **For learning concepts:** Use the **2D DP** approach.
- ✅ **For optimal performance:** Use the **Space Optimized DP** approach.

</details>

## **Code (Java)**

```java
class Solution {
    public int editDistance(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[] prev = new int[n + 1], curr = new int[n + 1];
        for (int i = 0; i <= n; i++) prev[i] = i;
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++)
                curr[j] = s1.charAt(i-1) == s2.charAt(j-1) ? prev[j-1] : 1 + Math.min(prev[j-1], Math.min(prev[j], curr[j-1]));
            int[] temp = prev;
            prev = curr;
            curr = temp;
        }
        return prev[n];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def editDistance(self, s1, s2):
        m, n = len(s1), len(s2)
        prev, curr = list(range(n + 1)), [0] * (n + 1)
        for i in range(1, m + 1):
            curr[0] = i
            for j in range(1, n + 1):
                curr[j] = prev[j-1] if s1[i-1] == s2[j-1] else 1 + min(prev[j-1], prev[j], curr[j-1])
            prev, curr = curr, prev
        return prev[n]
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
