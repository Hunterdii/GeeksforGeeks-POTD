---
Difficulty: Hard
Source: 160 Days of Problem Solving
Tags:
  - Graph
  - Strings
  - Sorting
---

# 🚀 _Day 15. Alien Dictionary_ 🧠


The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/alien-dictionary)  



## 💡 **Problem Description:**

A new alien language uses the English alphabet, but the order of the letters is unknown. You are given a list of words from the alien language’s dictionary, where the words are said to be sorted lexicographically by the language's own letter order.

Your task is to **determine the correct order of letters** based on the given words.  
If multiple valid orderings are possible, return any one of them.  
If no valid ordering exists (i.e., the words are not consistent with any letter ordering), return an empty string (`""`).



## 🔍 **Example Walkthrough:**

### **Example 1:**  
**Input:**  
`words[] = ["cb", "cba", "a", "bc"]`  
**Output:**  
`true`  
**Explanation:**  
One valid letter order is: `"cab"`.

### **Example 2:**  
**Input:**  
`words[] = ["ab", "aa", "a"]`  
**Output:**  
`""`  
**Explanation:**  
The order is invalid because `"aa"` appears before `"a"`.

### **Example 3:**  
**Input:**  
`words[] = ["ab", "cd", "ef", "ad"]`  
**Output:**  
`""`  
**Explanation:**  
There is a contradiction in the letter ordering.



### **Constraints**
- $1 \leq \text{words.length} \leq 500$  
- $1 \leq \text{words}[i].\text{length} \leq 100$  
- $\text{words}[i]$ consists only of lowercase English letters.  



## 🎯 **My Approach:**

### **Topological Sort using Kahn’s Algorithm (BFS)**

We model the **characters as graph nodes**, and **directed edges represent the precedence** between letters.

### **Algorithm Steps**:
1. Create an adjacency list `graph` to store the directed relationships (edges) between characters.
2. Build the graph by comparing adjacent words in the list:
   - For two words `a` and `b`, find the first index `i` where `a[i] != b[i]`.
   - Add a directed edge from `a[i]` to `b[i]`.
   - If `b` is a prefix of `a` and shorter, the input is invalid.
3. Compute in-degrees for all characters.
4. Use a **queue to apply Kahn’s Algorithm** for topological sorting:
   - Initialize the queue with all characters having `0 in-degree`.
   - Repeatedly remove a character from the queue, append to result, and decrement the in-degree of its neighbors.
5. If the result length is less than the number of unique characters, a cycle exists — return `""`.


## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N + K)`, where  
  - `N` is the total number of characters across all words, and  
  - `K` is the number of distinct precedence relationships (edges in the graph).  
  We traverse each word once and process each edge once during topological sort.

- **Expected Auxiliary Space Complexity:** `O(N + K)`,  
  for the graph representation, in-degree array, and the result string.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    string findOrder(vector<string> &w) {
        vector<vector<int>> g(26);
        vector<int> in(26), seen(26);
        for (auto &s : w) for (char c : s) seen[c - 'a'] = 1;
        for (int i = 0; i < w.size() - 1; i++) {
            string &a = w[i], &b = w[i + 1];
            int j = 0, n = min(a.size(), b.size());
            while (j < n && a[j] == b[j]) j++;
            if (j == n && a.size() > b.size()) return "";
            if (j < n) g[a[j] - 'a'].push_back(b[j] - 'a'), in[b[j] - 'a']++;
        }
        queue<int> q;
        for (int i = 0; i < 26; i++) if (seen[i] && !in[i]) q.push(i);
        string res;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res += u + 'a';
            for (int v : g[u]) if (--in[v] == 0) q.push(v);
        }
        for (int i = 0; i < 26; i++) if (seen[i] && in[i]) return "";
        return res;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ DFS-Based Topological Sort (Recursive)**

### **Algorithm Steps:**

1. Build a character graph as in Kahn’s algorithm.
2. Use DFS to visit unvisited characters.
3. On post-visit, add the character to a result list.
4. Reverse the result to get the alien dictionary order.
5. Detect cycles using a visiting state array.

```cpp
// ✅ C++ Code (Recursive DFS)
class Solution {
    bool dfs(int u, vector<vector<int>> &g, vector<int> &vis, string &res) {
        vis[u] = 1;
        for (int v : g[u]) {
            if (vis[v] == 1) return false;
            if (vis[v] == 0 && !dfs(v, g, vis, res)) return false;
        }
        vis[u] = 2;
        res += (char)(u + 'a');
        return true;
    }
public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> g(26);
        vector<int> seen(26);
        for (auto &w : words)
            for (char c : w) seen[c - 'a'] = 1;
        for (int i = 0; i < words.size() - 1; i++) {
            string &a = words[i], &b = words[i + 1];
            int j = 0, n = min(a.size(), b.size());
            while (j < n && a[j] == b[j]) j++;
            if (j == n && a.size() > b.size()) return "";
            if (j < n) g[a[j] - 'a'].push_back(b[j] - 'a');
        }
        vector<int> vis(26, 0);
        string res;
        for (int i = 0; i < 26; i++)
            if (seen[i] && vis[i] == 0 && !dfs(i, g, vis, res)) return "";
        reverse(res.begin(), res.end());
        return res;
    }
};
```
#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(N + K)`
- **Space Complexity:** `O(N + K)`

#### ✅ **Why This Approach?**

It uses post-order DFS with cycle detection to build the order naturally and efficiently in recursive style.

### 🆚 **Comparison of Approaches**

| **Approach**                     | ⏱️ Time Complexity | 🗂️ Space Complexity | ✅ Pros                                  | ⚠️ Cons                                  |
|----------------------------------|---------------------|----------------------|------------------------------------------|-------------------------------------------|
| Kahn’s Algorithm (BFS)           | 🟢 `O(N + K)`          | 🟢 `O(N + K)`           | Detects cycles easily, iterative         | More verbose for simple problems          |
| DFS-Based Topological Sort       | 🟢 `O(N + K)`          | 🟢 `O(N + K)`           | Simple logic, natural ordering           | Stack overflow possible on deep graphs    |

- `N`: Total number of characters processed  
- `K`: Total number of unique precedence relationships (edges in the graph)

✅ **Best Choice?**

- Use **Kahn’s Algorithm** when you need iterative processing and cycle detection.
- Use **DFS (Recursive)** for a more elegant solution when input depth is manageable.

</details>

## **Code (Java)**

```java
class Solution {
    public String findOrder(String[] w) {
        List<List<Integer>> g = new ArrayList<>();
        int[] in = new int[26];
        boolean[] seen = new boolean[26];
        for (int i = 0; i < 26; i++) g.add(new ArrayList<>());
        for (String s : w) for (char c : s.toCharArray()) seen[c - 'a'] = true;
        for (int i = 0; i < w.length - 1; i++) {
            String a = w[i], b = w[i + 1];
            int j = 0, n = Math.min(a.length(), b.length());
            while (j < n && a.charAt(j) == b.charAt(j)) j++;
            if (j == n && a.length() > b.length()) return "";
            if (j < n) {
                g.get(a.charAt(j) - 'a').add(b.charAt(j) - 'a');
                in[b.charAt(j) - 'a']++;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < 26; i++) if (seen[i] && in[i] == 0) q.add(i);
        StringBuilder res = new StringBuilder();
        while (!q.isEmpty()) {
            int u = q.poll();
            res.append((char)(u + 'a'));
            for (int v : g.get(u)) if (--in[v] == 0) q.add(v);
        }
        for (int i = 0; i < 26; i++) if (seen[i] && in[i] > 0) return "";
        return res.toString();
    }
}
```

## **Code (Python)**

```python
class Solution:
    @staticmethod
    def findOrder(words):
        from collections import deque, defaultdict
        g = defaultdict(list)
        in_deg = [0] * 26
        seen = [0] * 26
        for w in words:
            for c in w:
                seen[ord(c) - 97] = 1
        for i in range(len(words) - 1):
            a, b = words[i], words[i + 1]
            j, n = 0, min(len(a), len(b))
            while j < n and a[j] == b[j]: j += 1
            if j == n and len(a) > len(b): return ""
            if j < n:
                u, v = ord(a[j]) - 97, ord(b[j]) - 97
                g[u].append(v)
                in_deg[v] += 1
        q = deque(i for i in range(26) if seen[i] and in_deg[i] == 0)
        res = []
        while q:
            u = q.popleft()
            res.append(chr(u + 97))
            for v in g[u]:
                in_deg[v] -= 1
                if in_deg[v] == 0: q.append(v)
        return "".join(res) if sum(seen) == len(res) else ""
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
