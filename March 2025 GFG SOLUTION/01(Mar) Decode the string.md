# _1. Decode the String_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/decode-the-string2444/1)

## **Problem Description**

Given an encoded string `s`, the task is to decode it.  
The encoding rule is:

- `k[encoded_string]`, where the encoded string inside the square brackets is repeated exactly `k` times.
- Note: `k` is guaranteed to be a positive integer.

## **Examples**

### **Example 1:**

#### **Input:**

s = "1[b]"

#### **Output:**

b

#### **Explanation:**

The string "b" is present only once.

### **Example 2:**

#### **Input:**

s = "3[b2[ca]]"

#### **Output:**

bcacabcacabcaca

#### **Explanation:**

- First, `2[ca]` expands to `caca`
- Then, `3[bcaca]` expands to `bcacabcacabcaca` which is the final output.

### **Constraints:**

- $\(1 \leq |s| \leq 10^5\)$

## **My Approach**

### **Stack-Based Iterative Approach (O(N) Time, O(N) Space)**

The goal is to parse and decode nested patterns like `k[encoded_string]` using a **stack-based simulation**.

### **Algorithm Steps:**

1. **Use two stacks**:
   - One for tracking the string built so far.
   - One for tracking the repetition counts (`k`).
2. **Iterate over the string**:
   - If you see a digit, accumulate it into `k`.
   - If you see `[`, push the current string and current `k` to the stacks, then reset them.
   - If you see `]`, pop the previous string and `k`, and append the current string repeated `k` times.
   - Otherwise, append the character to the current string.
3. The final decoded string will be the result.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), since each character is processed at most twice (once when pushed, once when popped).
- **Expected Auxiliary Space Complexity:** O(N), as the worst case (deeply nested or large repeated sections) can push every character onto the stack.

## **Code (C++)**

```cpp
class Solution {
public:
    string decodedString(string &s) {
        stack<string> str;
        stack<int> num;
        string cur = "", temp;
        int n = 0;

        for (char c : s) {
            if (isdigit(c)) n = n * 10 + (c - '0');
            else if (c == '[') { str.push(cur); num.push(n); cur = ""; n = 0; }
            else if (c == ']') {
                temp = cur;
                cur = str.top(); str.pop();
                for (int i = 0, x = num.top(); i < x; i++) cur += temp;
                num.pop();
            } else cur += c;
        }
        return cur;
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Using `deque` Instead of `Stack` (O(N) Time, O(N) Space)**

This approach uses `deque` instead of `stack` for better performance on larger inputs.

```cpp
class Solution {
public:
    string decodedString(string &s) {
        deque<string> str;
        deque<int> num;
        string cur;
        int n = 0;

        for (char c : s) {
            if (isdigit(c)) n = n * 10 + (c - '0');
            else if (c == '[') { str.push_back(cur); num.push_back(n); cur = ""; n = 0; }
            else if (c == ']') {
                string temp = cur;
                cur = str.back(); str.pop_back();
                for (int i = 0; i < num.back(); i++) cur += temp;
                num.pop_back();
            } else cur += c;
        }
        return cur;
    }
};
```

🔹 **Pros:** Faster due to `deque`'s optimized access.  
🔹 **Cons:** Similar complexity but slight memory overhead.

## **3️⃣ Recursive Approach (O(N) Time, O(N) Space)**

This recursive solution simulates decoding via DFS.

```cpp
class Solution {
    int idx = 0;

    string decode(string &s) {
        string cur = "";
        int n = 0;

        while (idx < s.length()) {
            if (isdigit(s[idx])) n = n * 10 + (s[idx++] - '0');
            else if (s[idx] == '[') {
                idx++;
                string temp = decode(s);
                while (n--) cur += temp;
                n = 0;
            } else if (s[idx] == ']') {
                idx++;
                return cur;
            } else cur += s[idx++];
        }
        return cur;
    }

public:
    string decodedString(string &s) {
        idx = 0;
        return decode(s);
    }
};
```

🔹 **Pros:** Uses recursion to break down the problem naturally.  
🔹 **Cons:** Higher memory usage due to recursive stack frames.

## **📊 Comparison of Approaches**

| **Approach**              | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                    | ⚠️ **Cons**           |
| ------------------------- | ---------------------- | ----------------------- | ------------------------------ | --------------------- |
| **Stack-Based Iterative** | 🟢 O(N)                | 🟢 O(N)                 | Simple and fast                | None                  |
| **Deque-Based Iterative** | 🟢 O(N)                | 🟡 O(N)                 | Slightly faster for large data | Slightly more complex |
| **Recursive DFS**         | 🟢 O(N)                | 🔴 O(N)                 | Elegant for nested parsing     | Stack overflow risk   |

## 💡 **Best Choice?**

- ✅ **For practical use:** Stack-based iterative (O(N) time, O(N) space) is the best balance.
- ✅ **For highly nested strings:** Recursive DFS can be more intuitive.
- ✅ **For micro-optimizations:** Deque-based version is worth considering.

</details>

## **Code (Java)**

```java
class Solution {
    static String decodeString(String s) {
        Stack<String> str = new Stack<>();
        Stack<Integer> num = new Stack<>();
        String cur = "";
        int n = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) n = n * 10 + (c - '0');
            else if (c == '[') { str.push(cur); num.push(n); cur = ""; n = 0; }
            else if (c == ']') {
                String temp = cur;
                cur = str.pop();
                cur += temp.repeat(num.pop());
            } else cur += c;
        }
        return cur;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def decodedString(self, s: str) -> str:
        str_st, num_st, cur, n = [], [], "", 0

        for c in s:
            if c.isdigit():
                n = n * 10 + int(c)
            elif c == "[":
                str_st.append(cur)
                num_st.append(n)
                cur, n = "", 0
            elif c == "]":
                cur = str_st.pop() + cur * num_st.pop()
            else:
                cur += c
        return cur
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
