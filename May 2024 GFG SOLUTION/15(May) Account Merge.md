## 15. Account Merge

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/account-merge/1)

### Problem Description

Given a list of accounts where each element is a list of strings, with the first element being a name, and the rest being emails, merge accounts belonging to the same person. Two accounts belong to the same person if they share at least one common email. Return the merged accounts with emails sorted.

**Example:**

Input:

```
accounts = [
    ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
    ["John", "johnsmith@mail.com", "john00@mail.com"],
    ["Mary", "mary@mail.com"],
    ["John", "johnnybravo@mail.com"]
]
```

Output:

```
[
    ["John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"],
    ["Mary", "mary@mail.com"],
    ["John", "johnnybravo@mail.com"]
]
```

### Approach

1. **Union-Find Data Structure:**

   - Use Union-Find to group accounts belonging to the same person.
   - Map each email to its owner's index and name.

2. **Union Operation:**

   - Iterate through each account.
   - For each account, union all emails with the same owner's index.

3. **Grouping:**

   - Group emails by their root (representative) indices.

4. **Building Result:**
   - Build the result by constructing accounts with sorted emails.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n _ m _ log(n)), where n is the number of accounts and m is the average size of each account.
- **Expected Auxiliary Space Complexity:** O(n \* m), where n is the number of accounts and m is the average size of each account.

## Sorry guys my answer is too big but its hard so please if once the not given correct try again in GFG complier

### Code (C++)

```cpp
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int n = accounts.size();
        UnionFind uf(n);

        // Map emails to indices and names
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                emailToIndex[email] = i;
                emailToName[email] = accounts[i][0];
            }
        }

        // Union emails with the same owner
        for (auto& acc : accounts) {
            int root = emailToIndex[acc[1]];
            for (int j = 2; j < acc.size(); ++j) {
                uf.unite(root, emailToIndex[acc[j]]);
            }
        }

        // Group emails by owner
        unordered_map<int, set<string>> mergedAccounts;
        for (auto& acc : accounts) {
            int root = uf.find(emailToIndex[acc[1]]);
            for (int j = 1; j < acc.size(); ++j) {
                mergedAccounts[root].insert(acc[j]);
            }
        }

        // Build the result
        vector<vector<string>> result;
        for (auto it = mergedAccounts.begin(); it != mergedAccounts.end(); ++it) {
            vector<string> account;
            account.push_back(emailToName[*(it->second.begin())]);
            for (auto& email : it->second) {
                account.push_back(email);
            }
            result.push_back(account);
        }

        return result;
    }
};
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
