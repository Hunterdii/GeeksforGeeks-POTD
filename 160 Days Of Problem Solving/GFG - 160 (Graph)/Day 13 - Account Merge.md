---
Difficulty: Hard  
Source: 160 Days of Problem Solving  
Tags:
  - Graph
  - Union Find
  - Arrays
  - Hash
  - DFS
---

# 🚀 _Day 13. Account Merge_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/account-merge)

## 💡 **Problem Description:**

You are given a list of accounts, where each account is a list of strings. The first string represents the name of the account holder, and the remaining strings represent the account holder's emails.  

Your task is to **merge accounts** that belong to the same person. Two accounts belong to the same person **if there is at least one common email address** between them.  

After merging, each account should contain the name followed by all unique emails in **sorted order**. The result can be in any order.


## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**
```
accounts = [
  ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
  ["John", "johnsmith@mail.com", "john00@mail.com"],
  ["Mary", "mary@mail.com"],
  ["John", "johnnybravo@mail.com"]
]
```

#### **Output:**
```
[
  ["John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"],
  ["Mary", "mary@mail.com"],
  ["John", "johnnybravo@mail.com"]
]
```

#### **Explanation:**
- The first and second accounts for "John" are merged because they share the email `"johnsmith@mail.com"`.
- The third account belongs to "Mary", and the fourth account is a separate "John" (with a different set of emails).
- The emails in each merged account are sorted.


### **Example 2:**

#### **Input:**
```
accounts = [
  ["Gabe","Gabe00@m.co","Gabe3@m.co","Gabe1@m.co"],
  ["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],
  ["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],
  ["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],
  ["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]
]
```

#### **Output:**
```
[
  ["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],
  ["Gabe","Gabe00@m.co","Gabe1@m.co","Gabe3@m.co"],
  ["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],
  ["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],
  ["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]
]
```

#### **Explanation:**
- None of the accounts share a common email. Hence, each account remains separate.
- For each account, the emails are sorted.
- The merged accounts (or non-merged ones in this case) can be returned in any order.


## 🎯 **My Approach**

### **Disjoint Set Union (Union-Find)**

We treat each email as a node in a graph. If two emails appear in the same account, they are connected. Our goal is to find connected components of emails, and group them under the same user.

### **Algorithm Steps:**

1. **Initialization:**
   - Use two hash maps:
     - **Parent Map (`P`)**: To keep track of the representative (or parent) for each email.
     - **Name Map (`N`)**: To map each email to a name (since all emails in one account share the same name).
     
   - A helper function `find(email)` is defined to return the representative for the given email using **path compression**.

2. **Union-Find Setup:**
   - For each account:
     - The first element is the name.
     - For each email in the account:
       - Initialize the parent for the email (if not already present) and record the name.
       - **Union** the current email with the first email in the account. This effectively groups all emails from the same account together.

3. **Grouping Emails:**
   - After processing all accounts, traverse the parent map.
   - For each email, use the `find(email)` function to find its representative.
   - Group emails by their representative in a map (for example, `M`), using a structure (like a set) to store emails in sorted order later.

4. **Prepare the Result:**
   - For each group in the map:
     - Create a list starting with the name (obtained from the Name Map).
     - Append the sorted emails.
   - Return the final list of merged account details.


## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(n * m * logn)`, where `n` is the number of accounts and `m` is the average number of emails per account.  
  - Union-Find operations are nearly constant with path compression.
  - Sorting emails for each group takes `log n` time per group.
  
- **Expected Auxiliary Space Complexity:** `O(n * m)`, to store mappings of emails to names, parent references, and grouped components.


## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& A) {
        unordered_map<string,string> P, N;
        function<string(string)> f = [&](string a) -> string { return P[a] == a ? a : P[a] = f(P[a]); };
        for(auto &a : A) {
            string n = a[0];
            for (int i = 1; i < a.size(); i++) {
                if(!P.count(a[i])) P[a[i]] = a[i], N[a[i]] = n;
                P[f(a[i])] = f(a[1]);
            }
        }
        unordered_map<string, set<string>> M;
        for(auto &p : P) M[f(p.first)].insert(p.first);
        vector<vector<string>> R;
        for(auto &m : M) {
            vector<string> t;
            t.push_back(N[m.first]);
            for(auto &s : m.second) t.push_back(s);
            R.push_back(t);
        }
        return R;
    }
};
```

## **Code (Java)**

```java
class Solution {
    static ArrayList<ArrayList<String>> accountsMerge(ArrayList<ArrayList<String>> A) {
        HashMap<String, String> p = new HashMap<>(), n = new HashMap<>();
        for (ArrayList<String> a : A) {
            String name = a.get(0);
            for (int i = 1; i < a.size(); i++) {
                p.putIfAbsent(a.get(i), a.get(i));
                n.putIfAbsent(a.get(i), name);
                p.put(find(p, a.get(i)), find(p, a.get(1)));
            }
        }
        HashMap<String, TreeSet<String>> m = new HashMap<>();
        for (String mail : p.keySet()) m.computeIfAbsent(find(p, mail), k -> new TreeSet<>()).add(mail);
        ArrayList<ArrayList<String>> r = new ArrayList<>();
        for (String root : m.keySet()) {
            ArrayList<String> t = new ArrayList<>();
            t.add(n.get(root));
            t.addAll(m.get(root));
            r.add(t);
        }
        return r;
    }

    static String find(HashMap<String, String> p, String s) {
        if (!p.get(s).equals(s)) p.put(s, find(p, p.get(s)));
        return p.get(s);
    }
}
```

## **Code (Python)**

```python
class Solution:
    def accountsMerge(self, A):
        p, n = {}, {}
        def f(x): p.setdefault(x, x); p[x] = f(p[x]) if p[x] != x else x; return p[x]
        for a in A:
            for e in a[1:]:
                p.setdefault(e, e)
                n.setdefault(e, a[0])
                p[f(e)] = f(a[1])
        m = {}
        for e in p: m.setdefault(f(e), set()).add(e)
        return [[n[k]] + sorted(v) for k, v in m.items()]
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
