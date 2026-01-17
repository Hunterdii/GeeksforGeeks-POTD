---
title: "🔍 Expression Contains Redundant Bracket or Not | GFG Solution ✅"
keywords🏷️: ["🔍 redundant parentheses", "📚 stack", "🎯 expression parsing", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to check if an expression contains redundant brackets using stack-based approach for optimal validation. 🚀"
date: 📅 2025-01-17
---

# *17. Expression Contains Redundant Bracket or Not*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1)

## **🧩 Problem Description**

Given a string of balanced expression `s`, check if it contains a redundant parenthesis or not. A set of parentheses are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets.

The expression may contain `+`, `-`, `*`, and `/` operators. The given expression is valid and there are no white spaces present.

## **📘 Examples**

### Example 1

```cpp
Input: s = "((a+b))"
Output: true
Explanation: ((a+b)) can be reduced to (a+b).
```

### Example 2

```cpp
Input: s = "(a+(b)/c)"
Output: true
Explanation: (a+(b)/c) can be reduced to (a+b/c) because b is surrounded by () which is redundant.
```

### Example 3

```cpp
Input: s = "(a+b+(c+d))"
Output: false
Explanation: (a+b+(c+d)) doesn't have any redundant or multiple brackets.
```

## **🔒 Constraints**

* $1 \le |s| \le 10^5$

## **✅ My Approach**

The optimal approach uses a **Stack-Based** technique to efficiently detect redundant parentheses by tracking operators between bracket pairs:

### **Stack-Based Operator Detection**

1. **Initialize Stack:**
   * Use a stack to store opening brackets and operators.
   * Process each character in the expression sequentially.

2. **Character Processing:**
   * For opening brackets `(` and operators (`+`, `-`, `*`, `/`), push them onto the stack.
   * Skip operands (variables/numbers) as they don't affect redundancy.

3. **Closing Bracket Detection:**
   * When encountering `)`, pop elements from stack until `(` is found.
   * Track if any operator exists between the bracket pair using a boolean flag.

4. **Redundancy Check:**
   * If no operator is found between a parenthesis pair, return `true` (redundant).
   * If an operator exists, the brackets are necessary, continue checking.

5. **Final Result:**
   * If all bracket pairs contain operators, return `false` (no redundancy).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. Each character is pushed and popped from the stack at most once, resulting in linear time processing.
* **Expected Auxiliary Space Complexity:** O(n), as in the worst case (highly nested expression), the stack may store all opening brackets and operators, which is proportional to the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool checkRedundancy(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')') {
                bool op = false;
                while (st.top() != '(') {
                    char top = st.top(); st.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') op = true;
                }
                st.pop();
                if (!op) return true;
            } else if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/') {
                st.push(c);
            }
        }
        return false;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Operator Count Approach**

### 💡 Algorithm Steps:

1. Push all characters except closing parenthesis to stack.
2. On encountering closing parenthesis, count operators between parentheses.
3. If no operator exists between a pair, parentheses are redundant.
4. Continue checking all parentheses pairs in the expression.

```cpp
class Solution {
public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')') {
                bool hasOp = false;
                while (st.top() != '(') {
                    char t = st.top();
                    st.pop();
                    if (t == '+' || t == '-' || t == '*' || t == '/') hasOp = true;
                }
                st.pop();
                if (!hasOp) return true;
            } else {
                st.push(c);
            }
        }
        return false;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through the string
* **Auxiliary Space:** 💾 O(n) - Stack space for characters

### ✅ **Why This Approach?**

* Clear operator detection logic
* Easy to extend for more operators
* Intuitive flag-based checking

## 📊 **3️⃣ Minimal Element Count**

### 💡 Algorithm Steps:

1. Maintain stack and track elements between each parenthesis pair.
2. On closing bracket, pop until opening bracket is found.
3. Check if at least one element exists between the pair.
4. Empty or single-element pairs indicate redundancy.

```cpp
class Solution {
public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ')') {
                st.push(s[i]);
            } else {
                int elems = 0;
                while (!st.empty() && st.top() != '(') {
                    st.pop();
                    elems++;
                }
                if (!st.empty()) st.pop();
                if (elems <= 1) return true;
            }
        }
        return false;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal of string
* **Auxiliary Space:** 💾 O(n) - Stack storage

### ✅ **Why This Approach?**

* Counts all elements including operands
* Works for various expression formats
* Simple counting mechanism

## 📊 **4️⃣ Character Type Tracking**

### 💡 Algorithm Steps:

1. Use stack to store all non-closing parenthesis characters.
2. When closing parenthesis found, extract substring between brackets.
3. Analyze extracted content for meaningful operators or operands.
4. Return true if parentheses wrap nothing useful.

```cpp
class Solution {
public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == ')') {
                char top = st.top();
                st.pop();
                int cnt = 0;
                while (top != '(') {
                    if (top == '+' || top == '-' || top == '*' || top == '/') cnt++;
                    top = st.top();
                    st.pop();
                }
                if (cnt == 0) return true;
            } else {
                st.push(ch);
            }
        }
        return false;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Process each character once
* **Auxiliary Space:** 💾 O(n) - Stack for expression storage

### ✅ **Why This Approach?**

* Direct operator counting method
* Efficient single-pass solution
* Minimal condition checking

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Optimized Stack** (Main)     | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Faster runtime (less pushing)  | 🔧 Still uses stack memory            |
| ⚙️ **Operator Count**             | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear operator detection       | 🔧 Operator list maintenance         |
| 📏 **Minimal Element**            | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Generic element checking       | 🐌 Less specific validation          |
| 🔍 **Character Type**             | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Efficient operator check       | 🔧 Similar to other approaches       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Optimized Stack**               | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Operator Count**                | ★★★★☆                     |
| 🔧 **Generic expression handling**                    | 🥉 **Minimal Element**               | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Optimized Stack**               | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public boolean checkRedundancy(String s) {
        java.util.Stack<Character> st = new java.util.Stack<>();
        for (char c : s.toCharArray()) {
            if (c == ')') {
                boolean op = false;
                while (st.peek() != '(') {
                    char t = st.pop();
                    if (t == '+' || t == '-' || t == '*' || t == '/') op = true;
                }
                st.pop();
                if (!op) return true;
            } else if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/') {
                st.push(c);
            }
        }
        return false;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def checkRedundancy(self, s):
        st = []
        for c in s:
            if c == ')':
                op = False
                while st[-1] != '(':
                    if st.pop() in '+-*/': op = True
                st.pop()
                if not op: return True
            elif c == '(' or c in '+-*/':
                st.append(c)
        return False
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
