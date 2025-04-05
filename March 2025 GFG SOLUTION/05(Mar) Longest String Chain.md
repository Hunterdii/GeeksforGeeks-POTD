# _5. Longest String Chain_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-string-chain/1)

## **Problem Description**

You are given an array of words where each word consists of lowercase English letters.

A **wordA** is a **predecessor** of **wordB** if and only if we can insert exactly **one letter** anywhere in wordA without changing the order of the other characters to make it equal to wordB.  
For example, **"abc"** is a predecessor of **"abac"**, but **"cba"** is not a predecessor of **"bcad"**.

A **word chain** is a sequence of words [word1, word2, ..., wordk] with k >= 1, where **word1** is a predecessor of **word2**, **word2** is a predecessor of **word3**, and so on.  
A single word is trivially a word chain with k = 1.

You need to **return the length of the longest possible word chain** with words chosen from the given list in any order.

## **Examples**

### **Example 1:**

#### **Input:**

```
words[] = ["ba", "b", "a", "bca", "bda", "bdca"]
```

#### **Output:**

```
4
```

#### **Explanation:**

One of the longest word chains is ["a", "ba", "bda", "bdca"].

### **Example 2:**

#### **Input:**

```
words[] = ["abc", "a", "ab"]
```

#### **Output:**

```
3
```

#### **Explanation:**

The longest chain is ["a", "ab", "abc"].

### **Example 3:**

#### **Input:**

```
words[] = ["abcd", "dbqca"]
```

#### **Output:**

```
1
```

#### **Explanation:**

The trivial word chain ["abcd"] is one of the longest word chains.

### **Constraints:**

- $1 \leq \text{words.length} \leq 10^4$
- $1 \leq \text{words}[i].\text{length} \leq 10$
- words[i] only consists of lowercase English letters.

## **My Approach**

### **Dynamic Programming with Predecessor Check**

### **Algorithm Steps:**

1. **Sort words by length**. This ensures that whenever we process a word, all possible predecessors (shorter words) are already processed.
2. Use a **HashMap (dp)** where `dp[word]` stores the length of the longest chain ending at `word`.
3. For each word, **try removing every character one by one** to form all possible predecessors.
4. If a predecessor exists in the map, **update the chain length** for the current word.
5. Keep track of the **maximum chain length** found.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N \* L²), where N is the number of words and L is the maximum length of a word.
- **Expected Auxiliary Space Complexity:** O(N), where N is the number of words stored in the DP table.

## **Code (C++)**

```cpp
class Solution {
public:
    int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int res = 1;
        for (auto &w : words) {
            dp[w] = 1;
            for (int i = 0; i < w.size(); i++) {
                string pred = w.substr(0, i) + w.substr(i + 1);
                if (dp.count(pred)) dp[w] = max(dp[w], dp[pred] + 1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming (State Compression)**

### **Algorithm Steps:**

- Use a hashmap `dp` where `dp[word]` stores the length of the longest chain ending at `word`.
- Sort words by length.
- For each word, try removing every character one by one to check all possible predecessors.
- If a predecessor exists, update `dp[word]` as `dp[pred] + 1`.

```cpp
class Solution {
public:
    int longestStringChain(vector<string>& words) {
        unordered_map<string, int> dp;
        int res = 1;
        for (auto &w : words) dp[w] = 1;
        sort(words.begin(), words.end(), [](string &a, string &b) { return a.size() < b.size(); });
        for (auto &w : words)
            for (int i = 0; i < w.size(); i++)
                res = max(res, dp[w] = max(dp[w], dp[w.substr(0, i) + w.substr(i + 1)] + 1));
        return res;
    }
};
```

## 📊 **Comparison of Approaches**

| **Approach**          | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**           | ⚠️ **Cons**             |
| --------------------- | ---------------------- | ----------------------- | --------------------- | ----------------------- |
| **Sorting + HashMap** | **🟡 O(N \* L²)**      | **🟡 O(N)**             | Simple & Fast         | Needs sorting           |
| **State Compression** | **🟡 O(N \* L²)**      | **🟡 O(N)**             | Slightly more compact | Slightly harder to read |

## 🔔 **Best Choice**

- ✅ Use **Standard DP with HashMap** for readability and clarity.
- ✅ Use **State Compression version** for cleaner, more concise code if you're comfortable with the logic.

</details>

## **Code (Java)**

```java
class Solution {
    public int longestStringChain(String[] words) {
        Arrays.sort(words, Comparator.comparingInt(String::length));
        Map<String, Integer> dp = new HashMap<>();
        int res = 1;
        for (String w : words) {
            dp.put(w, 1);
            for (int i = 0; i < w.length(); i++) {
                String pred = w.substring(0, i) + w.substring(i + 1);
                dp.put(w, Math.max(dp.get(w), dp.getOrDefault(pred, 0) + 1));
            }
            res = Math.max(res, dp.get(w));
        }
        return res;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def longestStringChain(self, words):
        words.sort(key=len)
        dp = {}
        res = 1
        for w in words:
            dp[w] = 1
            for i in range(len(w)):
                pred = w[:i] + w[i+1:]
                if pred in dp:
                    dp[w] = max(dp[w], dp[pred] + 1)
            res = max(res, dp[w])
        return res
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
