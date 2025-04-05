# _21. Parenthesis Checker_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1)

## **Problem Description**

Given a string `s`, composed of different combinations of `(`, `)`, `{`, `}`, `[`, `]`, verify the **validity of the arrangement**.

A string is **valid** if:

1. **Open brackets** must be closed by the **same type** of brackets.
2. **Open brackets** must be closed in the **correct order**.

## **Examples**

### **Example 1:**

#### **Input:**

```plaintext
s = "[{()}]"
```

#### **Output:**

```plaintext
true
```

#### **Explanation:**

All brackets are correctly paired and well-formed.

### **Example 2:**

#### **Input:**

```plaintext
s = "[()()]{}"
```

#### **Output:**

```plaintext
true
```

#### **Explanation:**

All brackets are well-formed.

### **Example 3:**

#### **Input:**

```plaintext
s = "([]"
```

#### **Output:**

```plaintext
false
```

#### **Explanation:**

The expression is **not balanced** as there is a missing `')'` at the end.

### **Example 4:**

#### **Input:**

```plaintext
s = "([{]})"
```

#### **Output:**

```plaintext
false
```

#### **Explanation:**

The expression is **not balanced** as there is a **closing `]` before the closing `}`**.

### **Constraints:**

- $1 \leq |s| \leq 10^6$
- `s[i]` ∈ `{ '(', ')', '{', '}', '[', ']' }`

## **My Approach**

### **Stack-Based Validation (O(N) Time, O(N) Space)**

1. **Iterate over the string** and use a **stack** to track opening brackets.
2. **When encountering a closing bracket**:
   - If the stack is empty, return `false`.
   - Check whether the **top of the stack matches** the expected opening bracket.
   - If matched, pop the stack. Otherwise, return `false`.
3. **After iterating the string**, the stack should be **empty** for a valid expression.

### **Algorithm Steps:**

1. **Use a stack** to store open brackets `{[(`.
2. **Iterate through the string**:
   - If `s[i]` is an **opening bracket**, push it onto the stack.
   - If `s[i]` is a **closing bracket**:
     - Check if the **stack is empty** (invalid case).
     - **Compare the top element** of the stack with `s[i]`.
     - If it **matches**, pop the stack. Otherwise, return `false`.
3. **After the loop**, return **true** if the stack is empty, else **false**.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N)`, since each character is processed once in the loop.
- **Expected Auxiliary Space Complexity:** `O(N)`, in the worst case, all characters are pushed onto the stack.

## **Code (C++)**

```cpp
class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else if (st.empty() || abs(st.top() - c) > 2) return false;
            else st.pop();
        }
        return st.empty();
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Hash Map Lookup (O(N) Time, O(N) Space)**

1. Store **matching pairs** in a **hash map**.
2. **Push opening brackets** onto a stack.
3. On encountering a closing bracket:
   - **Check stack is empty**.
   - **Compare top of stack** with map lookup.
   - If matched, **pop**.
4. Return **true** if stack is empty.

```cpp
class Solution {
  public:
    bool isBalanced(string& s) {
        unordered_map<char, char> m = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> st;
        for (char c : s) {
            if (m.count(c)) {
                if (st.empty() || st.top() != m[c]) return false;
                st.pop();
            } else st.push(c);
        }
        return st.empty();
    }
};
```

🔹 **Pros:** **Explicit matching** is better than `abs(top - c) > 2`.  
🔹 **Cons:** Uses **extra hash map** (though small overhead).

## **📊 Comparison of Approaches**

| **Approach**             | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**            |
| ------------------------ | ---------------------- | ----------------------- | ---------------------------------- | ---------------------- |
| **Stack-Based Matching** | 🟢 `O(N)`              | 🟡 `O(N)`               | Simple and effective               | Uses extra stack space |
| **Hash Map Lookup**      | 🟢 `O(N)`              | 🟡 `O(N)`               | Explicit and easy-to-read matching | Slightly more memory   |

## **💡 Best Choice?**

✅ **For general use:** **Stack-Based Matching (`O(N)`)**.  
✅ **For minimal space usage:** **Two-Pointer (`O(1)`)**, but fails for mixed brackets.  
✅ **For explicit matching:** **Hash Map (`O(N)`)**, great for readability.

</details>

## **Code (Java)**

```java
class Solution {
    static boolean isBalanced(String s) {
        Stack<Character> st = new Stack<>();
        for (char c : s.toCharArray())
            if ("({[".indexOf(c) >= 0) st.push(c);
            else if (st.isEmpty() || Math.abs(st.peek() - c) > 2) return false;
            else st.pop();
        return st.isEmpty();
    }
}
```

## **Code (Python)**

```python
class Solution:
    def isBalanced(self, s):
        st = []
        for c in s:
            if c in "({[": st.append(c)
            elif not st or abs(ord(st[-1]) - ord(c)) > 2: return False
            else: st.pop()
        return not st
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
