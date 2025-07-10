---
title: "🔤 Find the Longest String | GFG Solution 🔍"
keywords🏷️: ["🔤 longest string", "🔍 prefix validation", "📍 sorting", "📈 hash set", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Find the Longest String problem: find the longest string where every prefix exists in the array using efficient prefix validation technique. 🚀"
date: 📅 2025-07-10
---

# *10. Find the Longest String*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1)

## **🧩 Problem Description**

Given an array of strings `words[]`, find the longest string in `words[]` such that every prefix of it is also present in the array `words[]`.

If multiple strings have the same maximum length, return the lexicographically smallest one.

## **📘 Examples**

### Example 1

```cpp
Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
Output: pros
Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present in the array words[].
```

### Example 2

```cpp
Input: words[] = ["ab", "a", "abc", "abd"]
Output: abc
Explanation: Both "abc" and "abd" has all the prefixes in words[]. Since, "abc" is lexicographically smaller than "abd", so the output is "abc".
```

## **🔒 Constraints**

* $1 \le \text{words.length} \le 10^3$
* $1 \le \text{words}[i].\text{length} \le 10^3$

## **✅ My Approach**

The optimal approach uses **Sorting** combined with **Hash Set** for efficient prefix validation:

### **Sorting + Hash Set Validation**

1. **Sort the Array:**
   * Sort the words array to ensure lexicographical order.
   * This guarantees that when we find a valid string, it's the lexicographically smallest among strings of the same length.

2. **Initialize Data Structures:**
   * Use an `unordered_set` to store valid strings (those whose all prefixes exist).
   * Initialize result string as empty.

3. **Validate Each Word:**
   * For each word in the sorted array:
     * If word length is 1 (single character), it's automatically valid.
     * Otherwise, check if the prefix (word without last character) exists in the set.
   * If valid, add the word to the set and update result if it's longer.

4. **Prefix Validation:**
   * For a word to be valid, all its prefixes must exist in the array.
   * We build valid strings incrementally, ensuring each new string's prefix is already validated.

5. **Lexicographical Ordering:**
   * Sorting ensures that among strings of equal length, the lexicographically smallest is processed first.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n + n*m), where n is the number of words and m is the average length of words. The sorting takes O(n log n) and prefix validation takes O(n*m) time.
* **Expected Auxiliary Space Complexity:** O(n*m), where n is the number of words and m is the average length of words for storing valid strings in the hash set.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> st;
        string res = "";
        for (string& w : words) {
            if (w.length() == 1 || st.count(w.substr(0, w.length() - 1))) {
                st.insert(w);
                if (w.length() > res.length()) res = w;
            }
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized Set-Based Approach**

### 💡 Algorithm Steps:

1. Sort words to ensure lexicographical order
2. Use unordered_set for O(1) prefix lookup
3. Check if previous prefix exists before adding
4. Track longest valid string

```cpp
class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> valid;
        string ans = "";
        for (auto& word : words) {
            if (word.size() == 1 || valid.find(word.substr(0, word.size() - 1)) != valid.end()) {
                valid.insert(word);
                if (word.size() > ans.size()) ans = word;
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + n*m) where m is average word length
* **Auxiliary Space:** 💾 O(n*m) - for storing valid words

### ✅ **Why This Approach?**

* Faster prefix checking with hash set
* Lexicographical ordering guaranteed by sorting
* Efficient string operations

## 📊 **3️⃣ DFS-Based Validation**

### 💡 Algorithm Steps:

1. Build adjacency list based on prefix relationships
2. Use DFS to validate complete prefix chains
3. Track maximum length during traversal
4. Return lexicographically smallest among longest

```cpp
class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_map<string, vector<string>> adj;
        unordered_set<string> wordSet(words.begin(), words.end());
        
        for (string& w : words) {
            if (w.length() > 1) {
                string prefix = w.substr(0, w.length() - 1);
                if (wordSet.count(prefix)) adj[prefix].push_back(w);
            }
        }
        
        string result = "";
        for (string& w : words) {
            if (w.length() == 1) {
                string temp = dfs(w, adj);
                if (temp.length() > result.length()) result = temp;
            }
        }
        return result;
    }
    
private:
    string dfs(string word, unordered_map<string, vector<string>>& adj) {
        string longest = word;
        for (string& next : adj[word]) {
            string candidate = dfs(next, adj);
            if (candidate.length() > longest.length()) longest = candidate;
        }
        return longest;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + n*m)
* **Auxiliary Space:** 💾 O(n*m) - for adjacency list and recursion

### ✅ **Why This Approach?**

* Comprehensive validation of prefix chains
* Handles complex word relationships
* Optimal for sparse prefix connections

## 📊 **4️⃣ Trie with Optimized Traversal**

### 💡 Algorithm Steps:

1. Build trie with end markers for complete words
2. Traverse trie to find longest valid chain
3. Track path during traversal
4. Return longest valid word

```cpp
class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        TrieNode* root = new TrieNode();
        
        for (string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                if (!node->children[c - 'a']) 
                    node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->isEnd = true;
        }
        
        return dfs(root, "");
    }
    
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() : isEnd(false) {
            fill(children, children + 26, nullptr);
        }
    };
    
    string dfs(TrieNode* node, string path) {
        string result = path;
        for (int i = 0; i < 26; i++) {
            if (node->children[i] && node->children[i]->isEnd) {
                string candidate = dfs(node->children[i], path + char('a' + i));
                if (candidate.length() > result.length()) result = candidate;
            }
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + n*m)
* **Auxiliary Space:** 💾 O(n*m) - for trie structure

### ✅ **Why This Approach?**

* Memory efficient for large datasets
* Natural prefix validation
* Optimal for prefix-heavy problems

## 📊 **5️⃣ Length-Based Sorting Approach**

### 💡 Algorithm Steps:

1. Sort words by length first, then lexicographically
2. Use set to track valid words
3. Check prefix existence for each word
4. Return longest valid word found

```cpp
class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.length() != b.length()) return a.length() < b.length();
            return a < b;
        });
        
        unordered_set<string> valid;
        string result = "";
        
        for (string& w : words) {
            if (w.length() == 1 || valid.count(w.substr(0, w.length() - 1))) {
                valid.insert(w);
                if (w.length() > result.length()) result = w;
            }
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + n*m)
* **Auxiliary Space:** 💾 O(n*m) - for storing valid words

### ✅ **Why This Approach?**

* Processes shorter words first
* Ensures prefix availability before longer words
* Clear logical flow

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Set + Sort**       | 🟢 O(n log n + n*m)    | 🟡 O(n*m)              | 🚀 Simple, lex order inherently handled          | 💾 Hash set overhead                 |
| 🔁 **Set-Based Validation**       | 🟢 O(n log n + n*m)    | 🟡 O(n*m)              | 🚀 Simple and efficient          | 💾 Substring copies                 |
| 🔺 **DFS Validation**             | 🟢 O(n log n + n*m)    | 🟡 O(n*m)              | 🔧 Comprehensive validation       | 💾 Recursion stack overhead          |
| ⏰ **Trie-Based**                 | 🟢 O(n log n + n*m)    | 🟡 O(n*m)              | 🚀 Memory efficient              | 🔄 Complex implementation             |
| 📊 **Length-Based Sorting**       | 🟢 O(n log n + n*m)    | 🟡 O(n*m)              | ⚡ Logical processing order       | 🔧 Custom comparator needed          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🧠 **Quick implementation & clarity**	                              | 🥇 **Set + Sort**          | ★★★★★                     |
| ⚡ **General use cases**                              | 🥈 **Set-Based Validation**          | ★★★★★                     |
| 📊 **Memory constrained**                            | 🥉 **Trie-Based**                    | ★★★★☆                     |
| 🎯 **Complex prefix relationships**                  | 🎖️ **DFS Validation**               | ★★★★☆                     |
| 🚀 **Competitive programming**                       | 🏅 **Length-Based Sorting**          | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public String longestString(String[] words) {
        Arrays.sort(words);
        Set<String> st = new HashSet<>();
        String res = "";
        for (String w : words) {
            if (w.length() == 1 || st.contains(w.substring(0, w.length() - 1))) {
                st.add(w);
                if (w.length() > res.length()) {
                    res = w;
                }
            }
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def longestString(self, words):
        words.sort()
        st = set()
        res = ""
        for w in words:
            if len(w) == 1 or w[:-1] in st:
                st.add(w)
                if len(w) > len(res):
                    res = w
        return res
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

