---
title: "🧮 Postfix Evaluation | GFG Solution 🔍"
keywords🏷️: ["🧮 postfix evaluation", "🔍 stack", "📊 expression evaluation", "🎯 reverse polish notation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Postfix Evaluation problem: evaluate arithmetic expressions written in Reverse Polish Notation using stack data structure. 🚀"
date: 📅 2025-09-16
---

# *16. Postfix Evaluation*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1)

## **🧩 Problem Description**

You are given an array of strings `arr[]` that represents a valid arithmetic expression written in **Reverse Polish Notation (Postfix Notation)**. Your task is to evaluate the expression and return an integer representing its value.

**Note:** A postfix expression is of the form `operand1 operand2 operator` (e.g., "a b +"). The division operation between two integers always computes the floor value, i.e `floor(5 / 3) = 1` and `floor(-5 / 3) = -2`. It is guaranteed that the result of the expression and all intermediate calculations will fit in a 32-bit signed integer.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = ["2", "3", "1", "*", "+", "9", "-"]
Output: -4
Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.
```

### Example 2

```cpp
Input: arr[] = ["2", "3", "^", "1", "+"]
Output: 9
Explanation: If the expression is converted into an infix expression, it will be 2 ^ 3 + 1 = 8 + 1 = 9.
```

## **🔒 Constraints**

* $3 \le \text{arr.size()} \le 10^3$
* `arr[i]` is either an operator: "+", "-", "*", "/" or "^", or an integer in the range $[-10^4, 10^4]$

## **✅ My Approach**

The optimal approach uses a **Stack** data structure to efficiently evaluate postfix expressions:

### **Stack-Based Evaluation**

1. **Initialize Stack:**
   * Create an empty stack to store operands during evaluation.

2. **Process Each Token:**
   * Iterate through each element in the array from left to right.
   * If the token is an operand (number), push it onto the stack.
   * If the token is an operator, pop two operands from the stack.

3. **Perform Operation:**
   * Pop the second operand (`b`) first, then the first operand (`a`).
   * Apply the operator: `a operator b`.
   * Handle special division case for floor division with negative numbers.
   * Push the result back onto the stack.

4. **Return Result:**
   * After processing all tokens, the stack contains exactly one element - the final result.

### **Key Insight:**
Postfix notation eliminates the need for parentheses and operator precedence rules. The stack naturally handles the order of operations by processing operands and operators in the correct sequence.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We traverse each element exactly once and perform constant time operations (push, pop, arithmetic) for each element.
* **Expected Auxiliary Space Complexity:** O(k), where k is the maximum number of operands that can be stored on the stack simultaneously. In the worst case, k can be up to n/2 for expressions with many consecutive operands.

## **🔧 Code (C)**

```c
int evaluate(char* arr[], int size) {
    int stack[size], top = -1;
    for (int i = 0; i < size; i++) {
        char* t = arr[i];
        if (strlen(t) == 1 && strchr("+-*/^", t[0])) {
            int b = stack[top--], a = stack[top--];
            if (t[0] == '/') stack[++top] = (a < 0) ^ (b < 0) && a % b ? a / b - 1 : a / b;
            else stack[++top] = t[0] == '+' ? a + b : t[0] == '-' ? a - b : 
                              t[0] == '*' ? a * b : (int)pow(a, b);
        } else stack[++top] = atoi(t);
    }
    return stack[top];
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for (const auto& t : arr) {
            if (t.size() == 1 && strchr("+-*/^", t[0])) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (t[0] == '/') st.push((a < 0) ^ (b < 0) && a % b ? a / b - 1 : a / b);
                else st.push(t[0] == '+' ? a + b : t[0] == '-' ? a - b : 
                           t[0] == '*' ? a * b : pow(a, b));
            } else st.push(stoi(t));
        }
        return st.top();
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Array-Based Stack Simulation**

### 💡 Algorithm Steps:

1. Use fixed array with index pointer instead of STL stack for better performance.
2. Handle operators with switch statement for faster dispatch.
3. Process negative numbers by checking first character and length.
4. Eliminate dynamic memory allocation overhead.

```cpp
class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        int stack[arr.size()], top = -1;
        for (const string& t : arr) {
            if (t.size() == 1) {
                switch (t[0]) {
                    case '+': { int b = stack[top--], a = stack[top--]; stack[++top] = a + b; break; }
                    case '-': { int b = stack[top--], a = stack[top--]; stack[++top] = a - b; break; }
                    case '*': { int b = stack[top--], a = stack[top--]; stack[++top] = a * b; break; }
                    case '/': { int b = stack[top--], a = stack[top--]; 
                               stack[++top] = (a < 0) ^ (b < 0) && a % b ? a / b - 1 : a / b; break; }
                    case '^': { int b = stack[top--], a = stack[top--]; stack[++top] = pow(a, b); break; }
                    default: stack[++top] = stoi(t); break;
                }
            } else stack[++top] = stoi(t);
        }
        return stack[top];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with O(1) operations per token
* **Auxiliary Space:** 💾 O(n) - Fixed array allocation based on input size

### ✅ **Why This Approach?**

* Zero dynamic allocation overhead
* Faster operator dispatch with switch
* Direct memory access without STL abstraction

## 📊 **3️⃣ Two-Pointer Recursion**

### 💡 Algorithm Steps:

1. Use recursive approach with two pointers for expression parsing.
2. Parse from right to left to handle postfix notation naturally.
3. Build expression tree implicitly through recursion stack.
4. Evaluate during unwinding phase of recursion.

```cpp
class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        int idx = arr.size() - 1;
        return helper(arr, idx);
    }
private:
    int helper(vector<string>& arr, int& idx) {
        string t = arr[idx--];
        if (t.size() == 1 && strchr("+-*/^", t[0])) {
            int right = helper(arr, idx);
            int left = helper(arr, idx);
            if (t[0] == '/') return (left < 0) ^ (right < 0) && left % right ? left / right - 1 : left / right;
            return t[0] == '+' ? left + right : t[0] == '-' ? left - right :
                   t[0] == '*' ? left * right : pow(left, right);
        }
        return stoi(t);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each token processed exactly once
* **Auxiliary Space:** 💾 O(h) - Recursion stack depth proportional to operators

### ✅ **Why This Approach?**

* Elegant recursive solution without explicit stack
* Natural handling of postfix evaluation order
* Cleaner code structure for complex expressions

## 📊 **4️⃣ Single-Pass Inline Evaluation**

### 💡 Algorithm Steps:

1. Process tokens in single pass with immediate evaluation.
2. Use vector as dynamic stack with reserve for performance.
3. Inline all operations to minimize function call overhead.
4. Handle edge cases like division by zero and negative numbers.

```cpp
class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        vector<int> st;
        st.reserve(arr.size());
        for (auto& t : arr) {
            if (t == "+") { int b = st.back(); st.pop_back(); st.back() += b; }
            else if (t == "-") { int b = st.back(); st.pop_back(); st.back() -= b; }
            else if (t == "*") { int b = st.back(); st.pop_back(); st.back() *= b; }
            else if (t == "/") { int b = st.back(); st.pop_back(); int a = st.back(); 
                                st.back() = (a < 0) ^ (b < 0) && a % b ? a / b - 1 : a / b; }
            else if (t == "^") { int b = st.back(); st.pop_back(); st.back() = pow(st.back(), b); }
            else st.push_back(stoi(t));
        }
        return st.back();
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal with constant time operations
* **Auxiliary Space:** 💾 O(k) - Space proportional to maximum operands on stack

### ✅ **Why This Approach?**

* Optimized memory usage with vector reserve
* Inline operations reduce function call overhead
* Dynamic stack growth handles variable expression sizes

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Standard Stack**             | 🟢 O(n)                | 🟢 O(k)                 | 🚀 Simple and reliable            | 🔧 STL overhead                      |
| 🔍 **Array Simulation**           | 🟢 O(n)                | 🟢 O(n)                 | 📖 Fastest execution              | 💾 Fixed memory allocation           |
| 📊 **Recursive**                  | 🟢 O(n)                | 🟢 O(h)                 | 🎯 Elegant code structure         | 🐌 Recursion overhead               |
| 🔄 **Vector-based**               | 🟢 O(n)                | 🟢 O(k)                 | ⭐ Dynamic memory optimization     | 🔧 Slightly more complex             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Maximum performance needed**                     | 🥇 **Array Simulation**              | ★★★★★                     |
| 📖 **General purpose usage**                          | 🥈 **Standard Stack**                | ★★★★★                     |
| 🔧 **Memory optimization priority**                   | 🥉 **Vector-based**                  | ★★★★☆                     |
| 🎯 **Educational/Interview**                          | 🏅 **Recursive Approach**            | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int evaluatePostfix(String[] arr) {
        Stack<Integer> st = new Stack<>();
        for (String t : arr) {
            if (t.length() == 1 && "+-*/^".contains(t)) {
                int b = st.pop(), a = st.pop();
                if (t.equals("/")) st.push((a < 0) ^ (b < 0) && a % b != 0 ? a / b - 1 : a / b);
                else st.push(t.equals("+") ? a + b : t.equals("-") ? a - b : 
                           t.equals("*") ? a * b : (int)Math.pow(a, b));
            } else st.push(Integer.parseInt(t));
        }
        return st.peek();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def evaluatePostfix(self, arr):
        st = []
        for t in arr:
            if t in "+-*/^" and len(t) == 1:
                b, a = st.pop(), st.pop()
                if t == '/':
                    st.append(a // b)
                else:
                    st.append(a + b if t == '+' else a - b if t == '-' else 
                             a * b if t == '*' else a ** b)
            else:
                st.append(int(t))
        return st[-1]
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
