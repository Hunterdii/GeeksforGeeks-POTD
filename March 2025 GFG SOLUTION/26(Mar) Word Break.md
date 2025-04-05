# _26. Word Break_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/word-break1352/1)

## **Problem Description**

You are given a string `s` and a list `dictionary[]` of words. Your task is to determine whether the string `s` can be formed by concatenating one or more words from the `dictionary[]`.

**Note:** From `dictionary[]`, any word can be taken any number of times and in any order.

## **Examples**

### **Example 1:**

#### **Input:**

```plaintext
s = "ilike"
dictionary[] = ["i", "like", "gfg"]
```

#### **Output:**

```plaintext
true
```

#### **Explanation:**

The given string `s` can be broken down as `"i like"` using words from the dictionary.

### **Example 2:**

#### **Input:**

```plaintext
s = "ilikegfg"
dictionary[] = ["i", "like", "man", "india", "gfg"]
```

#### **Output:**

```plaintext
true
```

#### **Explanation:**

The given string `s` can be broken down as `"i like gfg"` using words from the dictionary.

### **Example 3:**

#### **Input:**

```plaintext
s = "ilikemangoes"
dictionary[] = ["i", "like", "man", "india", "gfg"]
```

#### **Output:**

```plaintext
false
```

#### **Explanation:**

The given string `s` **cannot** be formed using the dictionary words.

### **Constraints:**

- $\( 1 \leq |s| \leq 3000 \)$
- $\( 1 \leq |dictionary| \leq 1000 \)$
- $\( 1 \leq |dictionary[i]| \leq 100 \)$

## **My Approach**

### **Dynamic Programming**

#### **Algorithm Steps:**

1. Use a boolean DP vector `dp` of size _n+1_ where `dp[i]` indicates if the substring `s[0...i-1]` can be segmented.
2. Insert dictionary words into an unordered set for O(1) lookups.
3. Iterate through the string and check all possible substrings using the dictionary.
4. If a valid word is found and its prefix was segmentable, mark `dp[i+j]` as true.
5. Return `dp[n]`.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** $\( O(n \times m) \)$, as each substring is checked in the dictionary.
- **Expected Auxiliary Space Complexity:** $\( O(n) \)$, as we use a DP array of size `n+1`.

## **Code (C++)**

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        unordered_set<string> u(d.begin(), d.end());
        int n = s.size(), m = 0;
        for(auto &w : d) m = max(m, (int)w.size());
        vector<bool> dp(n + 1);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            if(!dp[i]) continue;
            for(int j = 1; j <= m && i + j <= n; j++)
                if(u.count(s.substr(i, j))) dp[i + j] = 1;
        }
        return dp[n];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

### **1️⃣ Dynamic Programming (Optimized Iterative DP)**

#### **Algorithm Steps:**

1. Use a boolean DP vector `dp` of size _n+1_ where `dp[i]` indicates if the substring `s[0...i-1]` can be segmented.
2. Insert dictionary words into an unordered set for O(1) lookups.
3. Iterate through the string and check all possible substrings using the dictionary.
4. If a valid word is found and its prefix was segmentable, mark `dp[i+j]` as true.
5. Return `dp[n]`.

```cpp
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size(), maxLen = 0;
        for (auto &w : wordDict) maxLen = max(maxLen, (int)w.size());

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            for (int j = 1; j <= maxLen && i + j <= n; j++) {
                if (dict.count(s.substr(i, j))) dp[i + j] = true;
            }
        }
        return dp[n];
    }
};
```

✅ **Time Complexity:** O(n × m)  
✅ **Space Complexity:** O(n)

### **2️⃣ Trie-Based Approach with DFS and DP**

#### **Algorithm Steps:**

1. Build a Trie from the dictionary words.
2. Use a DP vector where `dp[i]` is true if `s[i...n-1]` can be segmented.
3. Start from the end of the string, traverse the Trie, and mark segmentable indexes.
4. Return `dp[0]`.

```cpp
struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isEnd(false) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(const string &word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        Trie trie;
        for(auto &w: d) trie.insert(w);
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for(int i = n - 1; i >= 0; i--) {
            TrieNode* node = trie.root;
            for(int j = i; j < n; j++){
                char c = s[j];
                if(!node->children.count(c)) break;
                node = node->children[c];
                if(node->isEnd && dp[j+1]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
```

✅ **Time Complexity:** O(n × m), where _m_ is the maximum word length  
✅ **Space Complexity:** O(n + total characters in dictionary)

## **Comparison of Approaches**

| **Approach**                        | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                       | ⚠️ **Cons**                  |
| ----------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ---------------------------- |
| **Dynamic Programming (Optimized)** | 🟢 O(n × m)            | 🟢 O(n)                 | Efficient and easy to implement   | Still requires full DP array |
| **Trie-Based Approach**             | 🟢 O(n × m)            | 🟡 O(n + dictionary)    | Faster lookups, avoids substrings | More complex implementation  |

✅ **Best Choice?**

- If you want **best efficiency**: Use **DP Optimized** approach.
- If you prefer **Trie-based lookup**: Use **Trie + DP**.

</details>

## **Code (Java)**

```java
class Solution {
    public boolean wordBreak(String s, String[] d) {
        Set<String> set = new HashSet<>(Arrays.asList(d));
        int n = s.length(), m = 0;
        for (String w : d) m = Math.max(m, w.length());
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            for (int j = 1; j <= m && i + j <= n; j++)
                if (set.contains(s.substring(i, i + j))) dp[i + j] = true;
        }
        return dp[n];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def wordBreak(self, s, dictionary):
        d = set(dictionary)
        m = max((len(w) for w in dictionary), default=0)
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(n):
            if not dp[i]:
                continue
            for j in range(1, m + 1):
                if i + j <= n and s[i:i + j] in d:
                    dp[i + j] = True
        return dp[n]
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
