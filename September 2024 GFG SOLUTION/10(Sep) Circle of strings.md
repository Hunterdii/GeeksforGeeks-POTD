# **10. Circle of Strings**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/circle-of-strings4530/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given an array `arr[]` of lowercase strings, determine if the strings can be chained together to form a circle. A string `X` can be chained together with another string `Y` if the last character of `X` is the same as the first character of `Y`. If every string in the array can be chained with exactly two strings (one with the first character and the other with the last character), it will form a circle.

#### Example:

Input:

```
arr[] = {"abc", "bcd", "cdf"}
```

Output:

```
0
```

Explanation: These strings can't form a circle because no string starts with 'd'.

Input:

```
arr[] = {"ab", "bc", "cd", "da"}
```

Output:

```
1
```

Explanation: These strings can form a circle: "ab" -> "bc" -> "cd" -> "da".

### My Approach

1. **Graph Representation:**

   - Represent each string as an edge between two nodes in a directed graph. The first character of the string is the starting node, and the last character is the ending node.

2. **Degree Condition:**

   - For the strings to form a circle, the in-degree and out-degree of every node (character) must be equal. This ensures that for every character in the set, there is an equal number of incoming and outgoing edges.

3. **Connectedness Condition:**

   - All nodes with a non-zero degree must belong to the same strongly connected component. This ensures that every string can eventually connect to every other string.

4. **DFS (Depth First Search):**
   - Use DFS to check if all the nodes with non-zero degrees are strongly connected.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the total number of strings in the array. We traverse through each string to check degree conditions and perform DFS.
- **Expected Auxiliary Space Complexity:** O(n), as we need additional space for adjacency lists and the DFS stack.

### Code (C++)

```cpp
class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;
        for (int u : adj[node]) {
            if (!visited[u])
                dfs(u, adj, visited);
        }
    }

    bool isConnected(vector<int> adj[], vector<int> &indegree) {
        vector<bool> visited(26, false);
        int start = -1;

        for (int i = 0; i < 26; ++i) {
            if (indegree[i] > 0) {
                start = i;
                break;
            }
        }

        if (start == -1) return true;

        dfs(start, adj, visited);
        for (int i = 0; i < 26; ++i) {
            if (indegree[i] > 0 && !visited[i])
                return false;
        }

        return true;
    }

    int isCircle(vector<string> &arr) {
        int N = arr.size();
        vector<int> adj[26], adjr[26];
        vector<int> indegree(26, 0), outdegree(26, 0);
        for (int i = 0; i < N; ++i) {
            int u = arr[i][0] - 'a';
            int v = arr[i].back() - 'a';
            adj[u].push_back(v);
            adjr[v].push_back(u);
            outdegree[u]++;
            indegree[v]++;
        }
        for (int i = 0; i < 26; ++i) {
            if (indegree[i] != outdegree[i])
                return 0;
        }
        if (!isConnected(adj, indegree))
            return 0;
        if (!isConnected(adjr, outdegree))
            return 0;

        return 1;
    }
};
```

### Code (Java)

```java
class Solution {
    public void dfs(int node, ArrayList<Integer>[] adj, boolean[] visited) {
        visited[node] = true;
        for (int u : adj[node]) {
            if (!visited[u]) {
                dfs(u, adj, visited);
            }
        }
    }

    public boolean isConnected(ArrayList<Integer>[] adj, int[] indegree) {
        boolean[] visited = new boolean[26];
        int start = -1;

        for (int i = 0; i < 26; i++) {
            if (indegree[i] > 0) {
                start = i;
                break;
            }
        }

        if (start == -1) return true;

        dfs(start, adj, visited);

        for (int i = 0; i < 26; i++) {
            if (indegree[i] > 0 && !visited[i])
                return false;
        }

        return true;
    }

    public int isCircle(String[] arr) {
        int N = arr.length;
        ArrayList<Integer>[] adj = new ArrayList[26];
        ArrayList<Integer>[] adjr = new ArrayList[26];
        int[] indegree = new int[26], outdegree = new int[26];

        for (int i = 0; i < 26; i++) {
            adj[i] = new ArrayList<>();
            adjr[i] = new ArrayList<>();
        }

        for (int i = 0; i < N; i++) {
            int u = arr[i].charAt(0) - 'a';
            int v = arr[i].charAt(arr[i].length() - 1) - 'a';
            adj[u].add(v);
            adjr[v].add(u);
            outdegree[u]++;
            indegree[v]++;
        }

        for (int i = 0; i < 26; i++) {
            if (indegree[i] != outdegree[i])
                return 0;
        }

        if (!isConnected(adj, indegree))
            return 0;

        if (!isConnected(adjr, outdegree))
            return 0;

        return 1;
    }
}
```

### Code (Python)

```python
class Solution:
    def dfs(self, node, adj, visited):
        visited[node] = True
        for u in adj[node]:
            if not visited[u]:
                self.dfs(u, adj, visited)

    def isConnected(self, adj, indegree):
        visited = [False] * 26
        start = -1

        for i in range(26):
            if indegree[i] > 0:
                start = i
                break

        if start == -1:
            return True

        self.dfs(start, adj, visited)

        for i in range(26):
            if indegree[i] > 0 and not visited[i]:
                return False

        return True

    def isCircle(self, arr):
        N = len(arr)
        adj = [[] for _ in range(26)]
        adjr = [[] for _ in range(26)]
        indegree = [0] * 26
        outdegree = [0] * 26

        for word in arr:
            u = ord(word[0]) - ord('a')
            v = ord(word[-1]) - ord('a')
            adj[u].append(v)
            adjr[v].append(u)
            outdegree[u] += 1
            indegree[v] += 1

        for i in range(26):
            if indegree[i] != outdegree[i]:
                return 0

        if not self.isConnected(adj, indegree):
            return 0

        if not self.isConnected(adjr, outdegree):
            return 0

        return 1
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
