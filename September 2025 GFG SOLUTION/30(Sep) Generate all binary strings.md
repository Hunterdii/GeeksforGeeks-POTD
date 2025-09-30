---
title: "🔢 Generate All Binary Strings | GFG Solution 🔍"
keywords🏷️: ["🔢 binary strings", "🔍 bit manipulation", "📍 backtracking", "🔄 recursion", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Generate All Binary Strings problem: generate all possible binary strings of length n using bit manipulation, backtracking, and iterative techniques. 🚀"
date: 📅 2025-09-30
---

# *30. Generate All Binary Strings*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1)

## **🧩 Problem Description**

Given an integer `n`, you need to generate all the **binary strings** of `n` characters representing bits. Each position in the string can be either '0' or '1', resulting in 2^n possible combinations.

**Note:** Return the strings in ascending order.

## **📘 Examples**

### Example 1

```cpp
Input: n = 2
Output: [00, 01, 10, 11]
Explanation: As each position can be either 0 or 1, the total possible combinations are 4.
```

### Example 2

```cpp
Input: n = 3
Output: [000, 001, 010, 011, 100, 101, 110, 111]
Explanation: As each position can be either 0 or 1, the total possible combinations are 8.
```

## **🔒 Constraints**

* $1 \le n \le 20$

## **✅ My Approach**

The optimal approach uses **Bit Manipulation** to generate all binary strings efficiently by treating each number from 0 to 2^n-1 as a binary representation:

### **Bit Manipulation Approach**

1. **Calculate Total Combinations:**
   * Total number of binary strings = 2^n, computed using left shift: `(1 << n)`.

2. **Iterate Through All Numbers:**
   * Loop from 0 to 2^n - 1, where each number represents a unique binary string.

3. **Extract Binary Representation:**
   * For each number, extract its binary form by checking each bit from position n-1 to 0.
   * Use right shift and bitwise AND operations: `((i >> j) & 1)`.

4. **Build String:**
   * Append '1' if bit is set, '0' otherwise.
   * Add the constructed string to result vector.

5. **Return Result:**
   * All strings are naturally generated in ascending order due to sequential number iteration.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n * 2^n), as we generate 2^n strings, and each string construction takes O(n) time to build n characters.
* **Expected Auxiliary Space Complexity:** O(1), excluding the output space, as we only use constant extra space for loop variables and temporary string construction.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<string> binstr(int n) {
        vector<string> res;
        for (int i = 0; i < (1 << n); i++) {
            string s = "";
            for (int j = n - 1; j >= 0; j--) s += ((i >> j) & 1) ? '1' : '0';
            res.push_back(s);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Backtracking with String Building**

### 💡 Algorithm Steps:

1. Use backtracking to explore both choices at each position.
2. Build string character by character during recursion.
3. Add character to current string and recurse deeper.
4. Backtrack by removing last character after exploring path.

```cpp
class Solution {
public:
    void solve(string cur, int n, vector<string>& res) {
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }
        solve(cur + "0", n, res);
        solve(cur + "1", n, res);
    }
    vector<string> binstr(int n) {
        vector<string> res;
        solve("", n, res);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * 2^n) - Generate and copy strings
* **Auxiliary Space:** 💾 O(n) - Recursion stack depth

### ✅ **Why This Approach?**

* Clean backtracking pattern implementation
* String building happens naturally during traversal
* Good for understanding recursive string generation

## 📊 **3️⃣ Queue-Based BFS Generation**

### 💡 Algorithm Steps:

1. Use queue initialized with empty string for BFS traversal.
2. For each string in queue, check if length equals n.
3. If complete add to result otherwise enqueue with '0' and '1' appended.
4. Process level by level until all strings generated.

```cpp
class Solution {
public:
    vector<string> binstr(int n) {
        vector<string> res;
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur.size() == n) res.push_back(cur);
            else {
                q.push(cur + "0");
                q.push(cur + "1");
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * 2^n) - Process all possible strings
* **Auxiliary Space:** 💾 O(2^n) - Queue storage for intermediate strings

### ✅ **Why This Approach?**

* Iterative approach using BFS pattern
* Avoids recursion stack limitations
* Level order generation of binary strings

## 📊 **4️⃣ In-Place Recursive Modification**

### 💡 Algorithm Steps:

1. Create a string of size n initialized with '0' characters.
2. Use recursive function with string reference and current index.
3. Base case: when index reaches n, add the current string to result.
4. At each position, first try '0', recurse, then modify to '1' and recurse again.
5. String is modified in-place, reducing memory allocations during recursion.

```cpp
class Solution {
public:
    void generate(string &s, int i, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        s[i] = '0';
        generate(s, i + 1, res);
        s[i] = '1';
        generate(s, i + 1, res);
    }
    vector<string> binstr(int n) {
        string s(n, '0');
        vector<string> res;
        generate(s, 0, res);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * 2^n) - Generate all strings with copying overhead
* **Auxiliary Space:** 💾 O(n) - Recursion depth plus string storage

### ✅ **Why This Approach?**

* Memory efficient with in-place string modification
* Demonstrates reference parameter usage in recursion
* Similar to the original problem's reference code structure


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔢 **Bit Manipulation**           | 🟢 O(n * 2^n)          | 🟢 O(1)                 | 🚀 Fastest execution              | 🧮 Requires bit operation knowledge  |
| 🔄 **Backtracking**               | 🟢 O(n * 2^n)          | 🟢 O(n)                 | 🎯 Clean recursive pattern        | 🔁 String creation overhead          |
| 🌊 **BFS Queue**                  | 🟢 O(n * 2^n)          | 🟡 O(2^n)               | ⭐ No recursion needed            | 💾 Queue storage overhead            |
| 🔧 **In-Place Recursive**         | 🟢 O(n * 2^n)          | 🟢 O(n)                 | 💡 Memory efficient modification  | 🧠 Requires understanding references |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Bit Manipulation**              | ★★★★★                     |
| 📖 **Learning recursion**                             | 🥈 **Backtracking**                  | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🥉 **Bit Manipulation**              | ★★★★★                     |
| 💡 **Understanding in-place techniques**              | 🎖️ **In-Place Recursive**           | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<String> binstr(int n) {
        ArrayList<String> res = new ArrayList<>();
        for (int i = 0; i < (1 << n); i++) {
            StringBuilder s = new StringBuilder();
            for (int j = n - 1; j >= 0; j--) s.append((i >> j & 1) == 1 ? '1' : '0');
            res.add(s.toString());
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def binstr(self, n):
        res = []
        for i in range(1 << n):
            s = ""
            for j in range(n - 1, -1, -1):
                s += '1' if (i >> j) & 1 else '0'
            res.append(s)
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


