---
title: "🎯 Maximise String Score | GFG Solution 🚀"
keywords🏷️: ["🎯 string score", "🔍 dynamic programming", "📍 prefix sum", "📈 graph traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximise String Score problem: find maximum score by performing valid character jumps using dynamic programming and prefix sum optimization. 🚀"
date: 📅 2025-12-02
---

# *02. Maximise String Score*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximise-string-score--172902/1)

## **🧩 Problem Description**

You are given a string `s`, and a list of `jumps[][]` of size n, where each `jumps[i] = [s1, s2]` denotes that you are allowed to jump from character `s1` to `s2` in the forward direction.

Additionally, you are allowed to jump forward from a character to any other occurrence of the same character within the string.

You start at index 0 of the string. After every valid jump from index i to index j, where `s[i] = s1` and `s[j] = s2`, you earn a score equal to the sum of ASCII values of all characters between the jump except for the characters equals `s2`, i.e.

**score(i, j) = sum(ascii(s[k]) for i ≤ k < j and s[k] != s[j]).**

Determine the maximum score that can be achieved by performing a sequence of valid jumps starting from index 0.

## **📘 Examples**

### Example 1

```cpp
Input: s = "forgfg", jumps[][] = [['f', 'r'], ['r', 'g']]
Output: 429
Explanation: We can jump from 'f' to 'r' at index 2, this will give a score equals to sum of ASCII value of 'f', 'o' i.e. 213.
Now we can jump from 'r' to 'g' at index 5, this will give a score equals to sum of ASCII value of 'r', 'f' i.e. 216.
Hence maximum total score obtained will be 429.
```

### Example 2

```cpp
Input: s = "abcda", jumps[][] = [['b', 'd']]
Output: 297
Explanation: We can jump from 'a' to 'a' (as both are same character) at index 4, this will give a score equals to sum of ASCII value of 'b', 'c', 'd' i.e. 297.
Hence maximum total score obtained will be 297.
```

## **🔒 Constraints**

* $1 \le |s| \le 2 \times 10^5$
* $1 \le \text{jumps.size()} \le 676$
* There are at least two distinct characters in s.

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** with **Prefix Sum Optimization** and **Precomputed Next Character Positions**:

### **Dynamic Programming + Prefix Sum**

1. **Initialize Jump Graph:**
   * Add self-loops for all characters (a-z) to allow jumping to same character.
   * Build adjacency list storing which characters can be jumped to from each character.

2. **Precompute Next Character Positions:**
   * Create a 2D array `nxt[i][c]` storing the next occurrence index of character `c` after position `i`.
   * Process string from right to left, maintaining last seen position of each character.

3. **Compute Prefix Sums:**
   * Build prefix sum array of ASCII values for O(1) range sum queries.
   * `pre[i]` stores sum of ASCII values from index 0 to i-1.

4. **Dynamic Programming:**
   * `dp[i]` represents maximum score achievable starting from index `i`.
   * Process positions from right to left (n-2 to 0).
   * For each position, try all valid jumps from current character.
   * Calculate score: `pre[j] - pre[i + offset] + dp[j]`, where offset is 1 if jumping to same character.

5. **Return Result:**
   * Maximum score starting from index 0 is stored in `dp[0]`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m), where n is the length of the string and m is the average number of valid jumps per character. Each position is processed once, and for each position we iterate through all possible jumps (at most 26 + additional custom jumps). The precomputation of next positions takes O(n × 26) = O(n) time.
* **Expected Auxiliary Space Complexity:** O(n + m), where n is used for storing DP array, prefix sum array, and next position matrix (n × 26), and m is for storing the jump graph adjacency list. The space is dominated by the O(n × 26) matrix for next positions.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();
        for (char c = 'a'; c <= 'z'; c++) jumps.push_back({c, c});
        vector<vector<int>> nxt(n, vector<int>(26, -1));
        vector<int> last(26, -1);
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = last;
            last[s[i] - 'a'] = i;
        }
        vector<vector<int>> ch(26);
        for (auto &j : jumps) ch[j[0] - 'a'].push_back(j[1]);
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + s[i];
        vector<int> dp(n);
        for (int i = n - 2; i >= 0; i--) {
            for (int c : ch[s[i] - 'a']) {
                int j = nxt[i][c - 'a'];
                if (j != -1) dp[i] = max(dp[i], pre[j] - pre[i + (c == s[i])] + dp[j]);
            }
        }
        return dp[0];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ HashMap-Based Next Position Lookup**

### 💡 Algorithm Steps:

1. Build a map storing all positions of each character in the string.
2. Use binary search to find the next occurrence of target characters efficiently.
3. Compute prefix sums for ASCII values to calculate substring scores in O(1).
4. Apply dynamic programming from end to start, tracking maximum achievable score.

```cpp
class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();
        map<char, vector<int>> pos;
        for (int i = 0; i < n; i++) pos[s[i]].push_back(i);
        for (char c = 'a'; c <= 'z'; c++) jumps.push_back({c, c});
        unordered_map<char, vector<char>> g;
        for (auto &j : jumps) g[j[0]].push_back(j[1]);
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + s[i];
        vector<int> dp(n);
        for (int i = n - 2; i >= 0; i--) {
            for (char c : g[s[i]]) {
                auto &v = pos[c];
                auto it = upper_bound(v.begin(), v.end(), i);
                if (it != v.end()) {
                    int j = *it;
                    dp[i] = max(dp[i], sum[j] - sum[i + (c == s[i])] + dp[j]);
                }
            }
        }
        return dp[0];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m × log n) - m is average jumps per character, binary search adds log factor
* **Auxiliary Space:** 💾 O(n) - Maps store character positions

### ✅ **Why This Approach?**

* Cleaner lookup logic using STL containers
* Binary search provides efficient next position finding
* Easy to understand and maintain

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1115 test cases due to time constraints).


## 📊 **3️⃣ Memoized Recursion with Top-Down DP**

### 💡 Algorithm Steps:

1. Build adjacency list for valid character jumps including self-loops.
2. Precompute all next character indices for fast traversal.
3. Use recursive function with memoization to explore all paths.
4. Cache results at each position to avoid redundant calculations.

```cpp
class Solution {
    vector<int> memo;
    vector<vector<int>> nxt, graph;
    vector<int> sum;
    string str;
    
    int solve(int i) {
        if (i >= str.size() - 1) return 0;
        if (memo[i] != -1) return memo[i];
        int res = 0;
        for (int c : graph[str[i] - 'a']) {
            int j = nxt[i][c - 'a'];
            if (j != -1) res = max(res, sum[j] - sum[i + (c == str[i])] + solve(j));
        }
        return memo[i] = res;
    }
    
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        str = s;
        int n = s.size();
        for (char c = 'a'; c <= 'z'; c++) jumps.push_back({c, c});
        nxt.assign(n, vector<int>(26, -1));
        vector<int> last(26, -1);
        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = last;
            last[s[i] - 'a'] = i;
        }
        graph.resize(26);
        for (auto &j : jumps) graph[j[0] - 'a'].push_back(j[1]);
        sum.resize(n + 1);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + s[i];
        memo.assign(n, -1);
        return solve(0);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m) - Each state computed once with memoization
* **Auxiliary Space:** 💾 O(n) - Recursion stack and memoization array

### ✅ **Why This Approach?**

* Natural recursive structure matches problem definition
* Memoization ensures each state computed only once
* Easier to debug and trace execution path

## 📊 **4️⃣ Space-Optimized Iterative DP**

### 💡 Algorithm Steps:

1. Process string in reverse without storing full DP array.
2. Maintain only necessary state for current computation.
3. Compute next indices on-the-fly to reduce memory footprint.
4. Update maximum score incrementally as we process each position.

```cpp
class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        int n = s.size();
        for (char c = 'a'; c <= 'z'; c++) jumps.push_back({c, c});
        unordered_map<char, vector<char>> adj;
        for (auto &j : jumps) adj[j[0]].push_back(j[1]);
        vector<int> sum(n + 1), dp(n);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + s[i];
        for (int i = n - 2; i >= 0; i--) {
            int mx = 0;
            for (char c : adj[s[i]]) {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == c) {
                        mx = max(mx, sum[j] - sum[i + (c == s[i])] + dp[j]);
                        break;
                    }
                }
            }
            dp[i] = mx;
        }
        return dp[0];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² × m) - Linear search for next occurrence
* **Auxiliary Space:** 💾 O(n) - Only DP and prefix sum arrays

### ✅ **Why This Approach?**

* Minimal preprocessing required
* Simpler data structures
* Good for small input sizes or when memory is constrained

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Precomputed Next Array**    | 🟢 O(n × m)            | 🟢 O(n)                 | 🚀 Fastest lookup                 | 🔧 More preprocessing                |
| 🔍 **HashMap + Binary Search**    | 🟡 O(n × m × log n)    | 🟢 O(n)                 | 📖 Clean code structure           | 🐌 Slower than direct array          |
| 📊 **Top-Down Recursion**         | 🟢 O(n × m)            | 🟡 O(n)                 | 🎯 Natural problem flow           | 💾 Recursion stack overhead          |
| 🔄 **Space-Optimized**            | 🔴 O(n² × m)           | 🟢 O(n)                 | ⭐ Minimal preprocessing          | 🐌 Slower time complexity            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Precomputed Next Array**        | ★★★★★                     |
| 📖 **Code clarity priority**                          | 🥈 **HashMap + Binary Search**       | ★★★★☆                     |
| 🔧 **Easy debugging needed**                          | 🥉 **Top-Down Recursion**            | ★★★★☆                     |
| 🎯 **Memory constrained**                             | 🏅 **Space-Optimized**               | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxScore(String s, char[][] jumps) {
        int n = s.length();
        List<char[]> j = new ArrayList<>();
        for (char[] x : jumps) j.add(x);
        for (char c = 'a'; c <= 'z'; c++) j.add(new char[]{c, c});
        int[][] nxt = new int[n][26];
        int[] last = new int[26];
        Arrays.fill(last, -1);
        for (int i = n - 1; i >= 0; i--) {
            System.arraycopy(last, 0, nxt[i], 0, 26);
            last[s.charAt(i) - 'a'] = i;
        }
        List<List<Integer>> ch = new ArrayList<>();
        for (int i = 0; i < 26; i++) ch.add(new ArrayList<>());
        for (char[] x : j) ch.get(x[0] - 'a').add((int)x[1]);
        int[] pre = new int[n + 1];
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + s.charAt(i);
        int[] dp = new int[n];
        for (int i = n - 2; i >= 0; i--) {
            for (int c : ch.get(s.charAt(i) - 'a')) {
                int k = nxt[i][c - 'a'];
                if (k != -1) dp[i] = Math.max(dp[i], pre[k] - pre[i + (c == s.charAt(i) ? 1 : 0)] + dp[k]);
            }
        }
        return dp[0];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxScore(self, s, jumps):
        n = len(s)
        jumps += [[chr(c), chr(c)] for c in range(97, 123)]
        nxt = [[-1] * 26 for _ in range(n)]
        last = [-1] * 26
        for i in range(n - 1, -1, -1):
            nxt[i] = last[:]
            last[ord(s[i]) - 97] = i
        ch = [[] for _ in range(26)]
        for u, v in jumps:
            ch[ord(u) - 97].append(ord(v))
        pre = [0] * (n + 1)
        for i in range(n):
            pre[i + 1] = pre[i] + ord(s[i])
        dp = [0] * n
        for i in range(n - 2, -1, -1):
            for c in ch[ord(s[i]) - 97]:
                j = nxt[i][c - 97]
                if j != -1:
                    dp[i] = max(dp[i], pre[j] - pre[i + (c == ord(s[i]))] + dp[j])
        return dp[0]
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




