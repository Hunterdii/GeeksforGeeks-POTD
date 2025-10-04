---
title: "🧮 Expression Add Operators | GFG Solution 🔍"
keywords🏷️: ["🧮 expression add operators", "🔍 backtracking", "📍 recursion", "💡 DFS", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Expression Add Operators problem: insert +, -, * between digits to reach a target value using DFS & backtracking. 🚀"
date: 📅 2025-10-04
---


# *04. Expression Add Operators*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/expression-add-operators/1)

## **🧩 Problem Description**

Given a string `s` that contains only digits (0-9) and an integer `target`, return all possible strings by inserting the binary operators `'+'`, `'-'`, and/or `'*'` between the digits of `s` such that the resultant expression evaluates to the target value.

**Note:**
- Operands in the returned expressions should not contain leading zeros. For example, `2 + 03` is not allowed whereas `20 + 3` is fine.
- It is allowed to not insert any of the operators.
- Driver code will print the final list of strings in lexicographically smallest order.

## **📘 Examples**

### Example 1

```cpp
Input: s = "124", target = 9
Output: ["1+2*4"]
Explanation: The valid expression that evaluates to 9 is 1 + 2 * 4
```

### Example 2

```cpp
Input: s = "125", target = 7
Output: ["1*2+5", "12-5"]
Explanation: The two valid expressions that evaluate to 7 are 1 * 2 + 5 and 12 - 5.
```

### Example 3

```cpp
Input: s = "12", target = 12
Output: ["12"] 
Explanation: s itself matches the target. No other expressions are possible.
```

### Example 4

```cpp
Input: s = "987612", target = 200
Output: []
Explanation: There are no expressions that can be created from "987612" to evaluate to 200.
```

## **🔒 Constraints**

* $1 \le \text{s.size()} \le 9$
* s consists of only digits (0-9)
* $-2^{31} \le \text{target} \le 2^{31}-1$

## **✅ My Approach**

The optimal approach uses **Backtracking with Expression Evaluation** to explore all possible ways to insert operators between digits:

### **Backtracking with DFS**

1. **Initialize Variables:**
   * Use recursive DFS to explore all possible placements of operators.
   * Track three critical values: current position `i`, running evaluation `val`, and previous operand `prev`.
   * Build expression string `path` as we recurse.

2. **Base Case:**
   * When we reach the end of string (`i == s.length()`), check if `val == target`.
   * If yes, add the current `path` to results.

3. **Recursive Exploration:**
   * Try all possible number formations from current position to end.
   * For each valid number:
     - **Leading Zero Check**: Skip if number starts with '0' and has multiple digits.
     - **First Number**: If at position 0, simply take the number as-is.
     - **Subsequent Numbers**: Try three operators:
       * **Addition (+)**: Add current number to evaluation.
       * **Subtraction (-)**: Subtract current number from evaluation.
       * **Multiplication (*)**: Handle operator precedence by adjusting with previous operand.

4. **Operator Precedence Handling:**
   * For multiplication, we need to "undo" the last addition/subtraction and apply multiplication first.
   * Formula: `new_val = val - prev + (prev * cur)`
   * This ensures correct evaluation order without using eval().

5. **Pruning:**
   * Skip numbers with leading zeros (except single '0').
   * This reduces the search space significantly.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(4^n), where n is the length of the string. At each position, we have up to 4 choices: no operator, +, -, or *. In practice, it's closer to O(3^n) due to pruning and the constraint that we must place operators between valid numbers.
* **Expected Auxiliary Space Complexity:** O(n), where n is the length of the string. This accounts for the recursion call stack depth and the temporary string being built during backtracking. The output space is not counted toward auxiliary space complexity.

## **Ⓜ️ Code (C)**

```c
char** findExpr(char* s, int target, int* returnSize) {
    int cap = 1000, cnt = 0, len = strlen(s);
    char** res = malloc(cap * sizeof(char*));
    void dfs(int i, long val, long prev, char* path, int plen) {
        if (i == len) {
            if (val == target) {
                res[cnt] = malloc(plen + 1);
                strcpy(res[cnt++], path);
                if (cnt == cap) res = realloc(res, (cap *= 2) * sizeof(char*));
            }
            return;
        }
        for (int j = i; j < len; j++) {
            if (j > i && s[i] == '0') break;
            long cur = 0;
            for (int k = i; k <= j; k++) cur = cur * 10 + (s[k] - '0');
            char num[20]; sprintf(num, "%ld", cur);
            int nlen = strlen(num);
            if (i == 0) {
                strcpy(path, num);
                dfs(j + 1, cur, cur, path, nlen);
            } else {
                path[plen] = '+'; strcpy(path + plen + 1, num);
                dfs(j + 1, val + cur, cur, path, plen + 1 + nlen);
                path[plen] = '-'; strcpy(path + plen + 1, num);
                dfs(j + 1, val - cur, -cur, path, plen + 1 + nlen);
                path[plen] = '*'; strcpy(path + plen + 1, num);
                dfs(j + 1, val - prev + prev * cur, prev * cur, path, plen + 1 + nlen);
            }
        }
    }
    char path[100];
    dfs(0, 0, 0, path, 0);
    *returnSize = cnt;
    return res;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<string> findExpr(string& s, int target) {
        vector<string> res;
        function<void(int, long, long, string)> dfs = [&](int i, long val, long prev, string path) {
            if (i == s.size()) {
                if (val == target) res.push_back(path);
                return;
            }
            for (int j = i; j < s.size(); j++) {
                if (j > i && s[i] == '0') break;
                long cur = stol(s.substr(i, j - i + 1));
                if (i == 0) dfs(j + 1, cur, cur, to_string(cur));
                else {
                    dfs(j + 1, val + cur, cur, path + "+" + to_string(cur));
                    dfs(j + 1, val - cur, -cur, path + "-" + to_string(cur));
                    dfs(j + 1, val - prev + prev * cur, prev * cur, path + "*" + to_string(cur));
                }
            }
        };
        dfs(0, 0, 0, "");
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative with Stack**

### 💡 Algorithm Steps:

1. Use a stack to store states (index, expression, value, last operand).
2. Process each state by trying all possible number partitions.
3. For each partition, generate new states with +, -, * operators.
4. When reaching end of string with matching target, store result.

```cpp
class Solution {
public:
    vector<string> findExpr(string& s, int target) {
        vector<string> res;
        stack<tuple<int, string, long, long>> st;
        st.push({0, "", 0, 0});
        while (!st.empty()) {
            auto [i, expr, val, prev] = st.top(); st.pop();
            if (i == s.size()) {
                if (val == target) res.push_back(expr);
                continue;
            }
            for (int j = i; j < s.size(); j++) {
                if (j > i && s[i] == '0') break;
                long cur = stol(s.substr(i, j - i + 1));
                string num = to_string(cur);
                if (i == 0) st.push({j + 1, num, cur, cur});
                else {
                    st.push({j + 1, expr + "*" + num, val - prev + prev * cur, prev * cur});
                    st.push({j + 1, expr + "-" + num, val - cur, -cur});
                    st.push({j + 1, expr + "+" + num, val + cur, cur});
                }
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(4^n) - Four choices per position in worst case
* **Auxiliary Space:** 💾 O(n * 4^n) - Stack space for all states

### ✅ **Why This Approach?**

* Avoids recursion stack overflow for large inputs
* Explicit state management for better control
* Easier to add pruning optimizations

## 📊 **3️⃣ Memoization with Hash Map**

### 💡 Algorithm Steps:

1. Cache results for each (index, current_value) pair to avoid recomputation.
2. Use hash map to store partial results at each state.
3. Before computing, check if state was already processed.
4. Return cached results when available to skip redundant work.

```cpp
class Solution {
public:
    vector<string> findExpr(string& s, int target) {
        unordered_map<string, vector<string>> memo;
        function<vector<string>(int, long, long)> solve = [&](int i, long val, long prev) -> vector<string> {
            string key = to_string(i) + "," + to_string(val) + "," + to_string(prev);
            if (memo.count(key)) return memo[key];
            vector<string> res;
            if (i == s.size()) {
                if (val == target) res.push_back("");
                return memo[key] = res;
            }
            for (int j = i; j < s.size(); j++) {
                if (j > i && s[i] == '0') break;
                long cur = stol(s.substr(i, j - i + 1));
                string num = to_string(cur);
                if (i == 0) {
                    for (auto& x : solve(j + 1, cur, cur))
                        res.push_back(num + x);
                } else {
                    for (auto& x : solve(j + 1, val + cur, cur))
                        res.push_back("+" + num + x);
                    for (auto& x : solve(j + 1, val - cur, -cur))
                        res.push_back("-" + num + x);
                    for (auto& x : solve(j + 1, val - prev + prev * cur, prev * cur))
                        res.push_back("*" + num + x);
                }
            }
            return memo[key] = res;
        };
        return solve(0, 0, 0);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * 4^n) - With memoization overhead
* **Auxiliary Space:** 💾 O(n * 4^n) - Hash map storage

### ✅ **Why This Approach?**

* Reduces redundant computations in overlapping subproblems
* Better for inputs with repeated patterns
* Trade-off between time and space

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Lambda Recursion**           | 🟡 O(4^n)              | 🟢 O(n)                 | 🚀 Clean and concise              | 📚 Deep recursion risk               |
| 🔍 **Iterative Stack**            | 🟡 O(4^n)              | 🟡 O(n * 4^n)           | 🛡️ No stack overflow             | 💾 Higher memory usage               |
| 📊 **Memoization**                | 🟡 O(n * 4^n)          | 🟡 O(n * 4^n)           | 🎯 Avoids recomputation           | 🐌 Overhead for unique paths         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Short strings (n ≤ 10)**                     | 🥇 **Lambda Recursion**              | ★★★★★                     |
| 📖 **Medium strings (n ≤ 15)**                    | 🥈 **Memoization**                   | ★★★★☆                     |
| 🔧 **Stack overflow concerns**                     | 🥉 **Iterative Stack**               | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<String> findExpr(String s, int target) {
        ArrayList<String> res = new ArrayList<>();
        dfs(s, target, 0, 0, 0, "", res);
        return res;
    }
    void dfs(String s, int target, int i, long val, long prev, String path, ArrayList<String> res) {
        if (i == s.length()) {
            if (val == target) res.add(path);
            return;
        }
        for (int j = i; j < s.length(); j++) {
            if (j > i && s.charAt(i) == '0') break;
            long cur = Long.parseLong(s.substring(i, j + 1));
            if (i == 0) dfs(s, target, j + 1, cur, cur, "" + cur, res);
            else {
                dfs(s, target, j + 1, val + cur, cur, path + "+" + cur, res);
                dfs(s, target, j + 1, val - cur, -cur, path + "-" + cur, res);
                dfs(s, target, j + 1, val - prev + prev * cur, prev * cur, path + "*" + cur, res);
            }
        }
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findExpr(self, s, target):
        res = []
        def dfs(i, val, prev, path):
            if i == len(s):
                if val == target: res.append(path)
                return
            for j in range(i, len(s)):
                if j > i and s[i] == '0': break
                cur = int(s[i:j+1])
                if i == 0: dfs(j + 1, cur, cur, str(cur))
                else:
                    dfs(j + 1, val + cur, cur, path + '+' + str(cur))
                    dfs(j + 1, val - cur, -cur, path + '-' + str(cur))
                    dfs(j + 1, val - prev + prev * cur, prev * cur, path + '*' + str(cur))
        dfs(0, 0, 0, '')
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
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
