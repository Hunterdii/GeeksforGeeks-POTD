# <b>22. Alien Dictionary</b>

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/alien-dictionary/1)

### Problem Description

Given a sorted dictionary of an alien language containing `N` words and `K` starting alphabets of a standard dictionary, find the order of characters in the alien language.

**Example 1:**

Input:

```
n = 5, k = 4
dict = {"baa","abcd","abca","cab","cad"}
```

Output:

```
1
```

Explanation: The order of characters is 'b', 'd', 'a', 'c'. Words are sorted, so "baa" comes before "abcd", indicating 'b' before 'a'.

**Example 2:**

Input:

```
n = 3, k = 3
dict = {"caa","aaa","aab"}
```

Output:

```
1
```

Explanation: The order of characters is 'c', 'a', 'b'. Words are sorted, so "caa" comes before "aaa", indicating 'c' before 'a'.

### My Approach

1. **Graph Construction:**

   - Compare adjacent words in the dictionary to determine the first mismatched character, which indicates the order.
   - Build a directed graph where each character points to the character that comes after it.

2. **Topological Sorting:**
   - Perform topological sorting on the graph to determine the correct order of characters in the alien language.
   - Use DFS (Depth-First Search) to ensure that the order is consistent with the constraints imposed by the dictionary.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* |s| + k), where `n` is the number of words, `|s|` is the average length of the words, and `k` is the number of unique characters.
- **Expected Auxiliary Space Complexity:** O(k), as we are storing a graph with `k` nodes and additional space for recursion stack during DFS.

### Code (C++)

```cpp
class Solution {
public:
    void buildGraph(vector<vector<int>>& adj, string str1, string str2) {
        int len = min(str1.length(), str2.length());
        for (int i = 0; i < len; i++) {
            if (str1[i] != str2[i]) {
                adj[str1[i] - 'a'].push_back(str2[i] - 'a');
                break;
            }
        }
    }

    void topologicalSort(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                topologicalSort(neighbor, adj, visited, st);
            }
        }
        st.push(node);
    }

    string findOrder(string dict[], int n, int k) {
        vector<vector<int>> adj(k);
        for (int i = 1; i < n; i++) {
            buildGraph(adj, dict[i - 1], dict[i]);
        }
        stack<int> st;
        vector<bool> visited(k, false);
        for (int i = 0; i < k; i++) {
            if (!visited[i]) {
                topologicalSort(i, adj, visited, st);
            }
        }
        string order;
        while (!st.empty()) {
            order += (char)(st.top() + 'a');
            st.pop();
        }
        return order;
    }
};
```

### Code (Java)

```java
class Solution {
    public String findOrder(String[] dict, int n, int k) {
        List<List<Integer>> adj = new ArrayList<>(k);
        for (int i = 0; i < k; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 1; i < n; i++) {
            buildGraph(adj, dict[i - 1], dict[i]);
        }

        Stack<Integer> st = new Stack<>();
        boolean[] visited = new boolean[k];
        for (int i = 0; i < k; i++) {
            if (!visited[i]) {
                topologicalSort(i, adj, visited, st);
            }
        }

        StringBuilder order = new StringBuilder();
        while (!st.isEmpty()) {
            order.append((char) (st.pop() + 'a'));
        }
        return order.toString();
    }

    private void buildGraph(List<List<Integer>> adj, String str1, String str2) {
        int len = Math.min(str1.length(), str2.length());
        for (int i = 0; i < len; i++) {
            if (str1.charAt(i) != str2.charAt(i)) {
                adj.get(str1.charAt(i) - 'a').add(str2.charAt(i) - 'a');
                break;
            }
        }
    }

    private void topologicalSort(int node, List<List<Integer>> adj, boolean[] visited, Stack<Integer> st) {
        visited[node] = true;
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                topologicalSort(neighbor, adj, visited, st);
            }
        }
        st.push(node);
    }
}
```

### Code (Python)

```python
from typing import List

class Solution:
    def findOrder(self, dict: List[str], n: int, k: int) -> str:
        adj = [[] for _ in range(k)]
        for i in range(1, n):
            self.buildGraph(adj, dict[i - 1], dict[i])

        visited = [False] * k
        st = []
        for i in range(k):
            if not visited[i]:
                self.topologicalSort(i, adj, visited, st)

        order = ""
        while st:
            order += chr(st.pop() + ord('a'))
        return order

    def buildGraph(self, adj: List[List[int]], str1: str, str2: str) -> None:
        len_ = min(len(str1), len(str2))
        for i in range(len_):
            if str1[i] != str2[i]:
                adj[ord(str1[i]) - ord('a')].append(ord(str2[i]) - ord('a'))
                break

    def topologicalSort(self, node: int, adj: List[List[int]], visited: List[bool], st: List[int]) -> None:
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.topologicalSort(neighbor, adj, visited, st)
        st.append(node)
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
