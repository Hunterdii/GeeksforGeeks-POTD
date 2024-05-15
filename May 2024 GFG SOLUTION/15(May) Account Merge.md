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

- **Expected Time Complexity:** O(n * m * log(n)), where n is the number of accounts and m is the average size of each account.
- **Expected Auxiliary Space Complexity:** O(n * m), where n is the number of accounts and m is the average size of each account.

### Code (C++)

```cpp
// Union-Find Class
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

// Solution Class
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Implementation
    }
};
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/).
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐