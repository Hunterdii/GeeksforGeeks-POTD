---
title: "🔧 Min Add to Make Parentheses Valid | GFG Solution 🚀"
keywords🏷️: ["🔧 parentheses validation", "🎯 greedy algorithm", "📊 string processing", "⚡ single pass", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Min Add to Make Parentheses Valid problem: find minimum parentheses to add using greedy single-pass algorithm. 🚀"
date: 📅 2025-09-19
---

# *19. Min Add to Make Parentheses Valid*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/min-add-to-make-parentheses-valid/1)

## **🧩 Problem Description**

You are given a string `s` consisting only of the characters `'('` and `')'`. Your task is to determine the **minimum number of parentheses** (either `'('` or `')'`) that must be inserted at any positions to make the string `s` a **valid parentheses string**.

A parentheses string is considered valid if:
- Every opening parenthesis `'('` has a corresponding closing parenthesis `')'`.
- Every closing parenthesis `')'` has a corresponding opening parenthesis `'('`.
- Parentheses are properly nested.

## **📘 Examples**

### Example 1

```cpp
Input: s = "(()("
Output: 2
Explanation: There are two unmatched '(' at the end, so we need to add two ')' to make the string valid.
```

### Example 2

```cpp
Input: s = ")))"
Output: 3
Explanation: Three '(' need to be added at the start to make the string valid.
```

### Example 3

```cpp
Input: s = ")()()"
Output: 1
Explanation: The very first ')' is unmatched, so we need to add one '(' at the beginning.
```

## **🔒 Constraints**

* $1 \le \text{s.size()} \le 10^5$
* $\text{s}[i] \in \{'\text{(}', '\text{)}'\}$

## **✅ My Approach**

The optimal approach uses a **Greedy Single-Pass Algorithm** to count unmatched opening and closing parentheses:

### **Greedy Counting Strategy**

1. **Initialize Counters:**
   * `open`: Track unmatched opening brackets `'('`
   * `close`: Track unmatched closing brackets `')'` that cannot be paired

2. **Single Pass Through String:**
   * For each `'('`: Increment `open` counter (potential match available)
   * For each `')'`: 
     - If `open > 0`: Decrement `open` (successful pairing)
     - Else: Increment `close` (unmatched closing bracket)

3. **Calculate Result:**
   * Total insertions needed = `open + close`
   * `open` represents unmatched opening brackets (need closing brackets)
   * `close` represents unmatched closing brackets (need opening brackets)

4. **Why This Works:**
   * Greedy approach: Always try to match closing brackets with available opening brackets
   * Left-to-right traversal ensures optimal pairing
   * No backtracking needed as each decision is locally optimal

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. We make a single pass through the string, examining each character exactly once.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the two integer counters regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minParentheses(string& s) {
        int open = 0, close = 0;
        for (char c : s) {
            if (c == '(') open++;
            else if (c == ')') open > 0 ? open-- : close++;
        }
        return open + close;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass Counter Approach**

### 💡 Algorithm Steps:

1. Track unmatched opening brackets with a counter
2. Count closing brackets that cannot be matched
3. Use conditional operator for compact logic
4. Return sum of unmatched brackets

```cpp
class Solution {
public:
    int minParentheses(string& s) {
        int balance = 0, additions = 0;
        for (char c : s) {
            balance += (c == '(') ? 1 : (c == ')') ? -1 : 0;
            if (balance < 0) additions++, balance = 0;
        }
        return balance + additions;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through string
* **Auxiliary Space:** 💾 O(1) - Only constant variables used

### ✅ **Why This Approach?**

* Handles all characters in one expression
* Clear balance tracking mechanism
* Efficient reset on negative balance

## 📊 **3️⃣ Stack Simulation Approach**

### 💡 Algorithm Steps:

1. Simulate stack behavior without actual stack data structure
2. Increment counter for opening brackets (push simulation)
3. Decrement for closing brackets when possible (pop simulation)
4. Track unmatched closing brackets separately

```cpp
class Solution {
public:
    int minParentheses(string& s) {
        int stack_size = 0, unmatched = 0;
        for (char& c : s) {
            if (c == '(') stack_size++;
            else if (c == ')') {
                stack_size ? stack_size-- : unmatched++;
            }
        }
        return stack_size + unmatched;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal of string
* **Auxiliary Space:** 💾 O(1) - No additional data structures

### ✅ **Why This Approach?**

* Intuitive stack-like logic without overhead
* Clear separation of opening and closing tracking
* Easy to understand and debug

## 📊 **4️⃣ Bit Manipulation Approach**

### 💡 Algorithm Steps:

1. Use bitwise operations to identify parentheses characters
2. Leverage bit patterns for efficient character comparison
3. Apply fast arithmetic operations for balance tracking
4. Minimize branching with bitwise logic

```cpp
class Solution {
public:
    int minParentheses(string& s) {
        int open = 0, close = 0;
        for (unsigned char c : s) {
            open += (c == 40);
            close += (c == 41) & (open == 0);
            open -= (c == 41) & (open > 0);
        }
        return open + close;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with bitwise operations
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Minimal branching for better CPU pipeline efficiency
* ASCII values used directly for comparison
* Compact boolean arithmetic operations

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Ternary Counter**             | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Most concise and readable      | 🔍 Less explicit logic flow          |
| ⚖️ **Balance Tracker**             | 🟢 O(n)                | 🟢 O(1)                 | 📊 Clear balance visualization    | 🔧 Multiple conditional checks        |
| 📚 **Stack Simulation**            | 🟢 O(n)                | 🟢 O(1)                 | 🎓 Easy to understand             | 📝 More verbose implementation        |
| ⚡ **Bit Manipulation**            | 🟢 O(n)                | 🟢 O(1)                 | 🔥 CPU-optimized performance      | 🧮 Less readable for beginners       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Interview/Contest**                              | 🥇 **Ternary Counter**               | ★★★★★                     |
| 📖 **Code Readability**                              | 🥈 **Stack Simulation**             | ★★★★☆                     |
| 🔧 **Teaching/Learning**                              | 🥉 **Balance Tracker**              | ★★★★☆                     |
| 🚀 **Performance Critical**                          | 🏅 **Bit Manipulation**             | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minParentheses(String s) {
        int open = 0, close = 0;
        for (char c : s.toCharArray()) {
            if (c == '(') open++;
            else if (c == ')') if (open > 0) open--; else close++;
        }
        return open + close;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minParentheses(self, s):
        open = close = 0
        for c in s:
            if c == '(':
                open += 1
            elif c == ')':
                if open > 0:
                    open -= 1
                else:
                    close += 1
        return open + close
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
