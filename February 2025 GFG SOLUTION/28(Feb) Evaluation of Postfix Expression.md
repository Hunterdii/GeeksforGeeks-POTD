# _28. Evaluation of Postfix Expression_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1)

## **Problem Description**

You are given an array of strings `arr` that represents a valid arithmetic expression written in **Reverse Polish Notation (Postfix Notation)**.

Your task is to evaluate the expression and return an integer representing its value.

### **Operators Supported**

- `+` Addition
- `-` Subtraction
- `*` Multiplication
- `/` Integer Division (rounds towards zero)

### **Key Points**

- All numbers are valid integers.
- No division by zero.
- Result and intermediate values fit in **32-bit signed integer**.

## **Examples**

### **Example 1**

#### **Input:**

arr = ["2", "3", "1", "*", "+", "9", "-"]

#### **Output:**

`-4`

#### **Explanation:**

Expression equivalent to:  
$\(2 + (3 \times 1) - 9 = 5 - 9 = -4\)$

### **Example 2**

#### **Input:**

arr = ["100", "200", "+", "2", "/", "5", "*", "7", "+"]

#### **Output:**

`757`

#### **Explanation:**

Expression equivalent to:  
$\(\frac{100 + 200}{2} \times 5 + 7 = 150 \times 5 + 7 = 757\)$

### **Constraints**

- $\(1 \leq arr.size() \leq 10^5\)$
- $\(arr[i]\)$ is either an **operator**: "+", "-", "\*", "/" or an **integer** in the range $\([-10^4, 10^4]\)$

## **My Approach**

### **Stack-Based Evaluation (O(N) Time, O(N) Space)**

This approach processes each element in the postfix expression in a **single pass** and uses a **stack** to store operands. Operators pop the top two operands, evaluate them, and push the result back onto the stack.

### **Algorithm Steps:**

1. **Initialize an empty stack.**
2. **Iterate through each token in the array:**
   - If the token is an **operator**, pop the top two operands, apply the operation, and push the result back.
   - If the token is a **number**, convert it to integer and push it onto the stack.
3. **At the end, the stack will contain exactly one value — the final result.**

This method guarantees all operations happen in **O(1)** time, and we iterate over the array exactly once.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), where N = length of `arr`, as each token is processed exactly once.
- **Expected Auxiliary Space Complexity:** O(N), for storing the operands in the stack.

## **Code (C++)**

```cpp
class Solution {
public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        for (auto &s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else st.push(a / b);
            } else st.push(stoi(s));
        }
        return st.top();
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Using `vector<int>` as Stack (O(N) Time, O(N) Space)**

This approach **simulates a stack using a `vector<int>`**, treating the `back()` element as the top of the stack.

```cpp
class Solution {
public:
    int evaluate(vector<string>& arr) {
        vector<int> st;
        for (const string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.back(); st.pop_back();
                int a = st.back(); st.pop_back();
                if (token == "+") st.push_back(a + b);
                else if (token == "-") st.push_back(a - b);
                else if (token == "*") st.push_back(a * b);
                else st.push_back(a / b);
            } else {
                st.push_back(stoi(token));
            }
        }
        return st.back();
    }
};
```

🔹 **Pros:** Avoids `stack<int>`, works similarly.  
🔹 **Cons:** Same time and space complexity.

## **3️⃣ Recursive Approach (O(N) Time, O(N) Space)**

This approach recursively processes tokens from **right to left**, mimicking evaluation directly from the postfix array itself. It’s more theoretical and educational than practical due to recursion overhead.

```cpp
class Solution {
    int idx;

    int eval(vector<string>& arr) {
        string token = arr[idx--];
        if (isdigit(token.back()) || (token.size() > 1 && isdigit(token[1]))) {
            return stoi(token);
        }
        int b = eval(arr);
        int a = eval(arr);
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;
        return a / b;
    }

public:
    int evaluate(vector<string>& arr) {
        idx = arr.size() - 1;
        return eval(arr);
    }
};
```

🔹 **Pros:** Recursive parsing for educational purposes.  
🔹 **Cons:** Not suitable for large input due to stack overflow risk.

## **📊 Comparison of Approaches**

| **Approach**          | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**         | ⚠️ **Cons**         |
| --------------------- | ---------------------- | ----------------------- | ------------------- | ------------------- |
| **Iterative Stack**   | 🟢 O(N)                | 🟢 O(N)                 | Simple & optimal    | None                |
| **Vector as Stack**   | 🟢 O(N)                | 🟢 O(N)                 | Avoids `stack<int>` | Same complexity     |
| **Recursive Parsing** | 🟡 O(N)                | 🔴 O(N) (call stack)    | Educational         | Stack overflow risk |

## 💡 **Best Choice?**

- ✅ **For competitive programming:** **Iterative Stack (`O(N)` Time, `O(N)` Space)**.
- ✅ **For educational learning:** Recursive parsing is interesting to explore recursion-based parsing.

</details>

## **Code (Java)**

```java
class Solution {
    public int evaluate(String[] arr) {
        Stack<Integer> st = new Stack<>();
        for (String s : arr) {
            if ("+-*/".contains(s)) {
                int b = st.pop(), a = st.pop();
                if (s.equals("+")) st.push(a + b);
                else if (s.equals("-")) st.push(a - b);
                else if (s.equals("*")) st.push(a * b);
                else st.push(a / b);
            } else {
                st.push(Integer.parseInt(s));
            }
        }
        return st.peek();
    }
}
```

## **Code (Python)**

```python
class Solution:
    def evaluate(self, arr):
        st = []
        for s in arr:
            if s in {"+", "-", "*", "/"}:
                b, a = st.pop(), st.pop()
                if s == "+": st.append(a + b)
                elif s == "-": st.append(a - b)
                elif s == "*": st.append(a * b)
                else: st.append(int(a / b))
            else:
                st.append(int(s))
        return st[-1]
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
