# _22. Longest Valid Parentheses_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1)

## **Problem Description**

Given a string **s** consisting of only **'('** and **')'**, find the **length of the longest valid parentheses substring**.

A parenthesis string is **valid** if:

1. Every opening parenthesis **'('** has a corresponding closing **')'**.
2. The closing parenthesis appears **after** its matching opening parenthesis.

## **Examples**

### **Example 1:**

#### **Input:**

```
s = "((()"
```

#### **Output:**

```
2
```

#### **Explanation:**

The longest valid parentheses substring is `"()"`.

### **Example 2:**

#### **Input:**

```
s = ")()())"
```

#### **Output:**

```
4
```

#### **Explanation:**

The longest valid parentheses substring is `"()()"`.

### **Example 3:**

#### **Input:**

```
s = "())()"
```

#### **Output:**

```
2
```

#### **Explanation:**

The longest valid parentheses substring is `"()"`.

### **Constraints:**

- $1 \leq s.length \leq 10^6$
- **s** consists of **'('** and **')'** only.

## **My Approach**

### **Stack-Based Approach (O(N) Time, O(N) Space)**

1. **Use a stack to track indices** of parentheses.
2. **Push opening parentheses ('(') indices** onto the stack.
3. **For closing parentheses (')')**:
   - If the stack is not empty, pop the top element.
   - If the stack is empty, push the current index as a new base.
   - Maintain the **maximum valid length** by subtracting indices.

### **Algorithm Steps:**

1. Initialize a **stack** and push `-1` as a base index.
2. Traverse **s** character by character:
   - If `'('`, push its index onto the stack.
   - If `')'`, pop from the stack.
     - If the stack becomes empty, push the current index.
     - Otherwise, update `max_length = max(max_length, i - st.top())`.
3. Return `max_length`.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** **O(N)**, as we traverse the string once.
- **Expected Auxiliary Space Complexity:** **O(N)**, for storing indices in the stack.

## **Code (C++)**

```cpp
class Solution {
public:
    int maxLength(string s) {
        stack<int> st; st.push(-1);
        int m = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) st.push(i);
                else m = max(m, i - st.top());
            }
        return m;
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Two-Pass Counter Approach (O(N) Time, O(1) Space)**

1. Use **left-right counters** to track valid parentheses.
2. Forward pass ensures extra right brackets are ignored.
3. Backward pass ensures extra left brackets are ignored.

```cpp
class Solution {
public:
    int maxLength(string s) {
        int l = 0, r = 0, m = 0;
        for (char c : s) {
            if (c == '(') l++;
            else r++;
            if (l == r) m = max(m, 2 * r);
            else if (r > l) l = r = 0;
        }
        l = r = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') l++;
            else r++;
            if (l == r) m = max(m, 2 * l);
            else if (l > r) l = r = 0;
        }
        return m;
    }
};
```

🔹 **Pros:** No extra space needed.  
🔹 **Cons:** Requires two passes.

## **📊 Comparison of Approaches**

| **Approach**                  | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**             | ⚠️ **Cons**                    |
| ----------------------------- | ---------------------- | ----------------------- | ----------------------- | ------------------------------ |
| **Stack (Using Indices)**     | 🟢 `O(N)`              | 🟡 `O(N)`               | Simple and effective    | Extra stack memory used        |
| **Two-Pass Counter Approach** | 🟢 `O(N)`              | 🟢 `O(1)`               | No extra space required | Requires two passes over input |

### **💡 Best Choice?**

- ✅ **For best efficiency:** **Two-Pass Counter (`O(N)`)** (No extra space).
- ✅ **For simpler implementation:** **Stack Approach (`O(N)`)** (Easier to understand).

</details>

## **Code (Java)**

```java
class Solution {
    static int maxLength(String s) {
        java.util.Stack<Integer> st = new java.util.Stack<>();
        st.push(-1);
        int m = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') st.push(i);
            else {
                st.pop();
                if (st.empty()) st.push(i);
                else m = Math.max(m, i - st.peek());
            }
        }
        return m;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def maxLength(self, s):
        st=[-1]; m=0
        for i,c in enumerate(s):
            if c=='(':
                st.append(i)
            else:
                st.pop()
                if not st: st.append(i)
                else: m = max(m, i - st[-1])
        return m
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
