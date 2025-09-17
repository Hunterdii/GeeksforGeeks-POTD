---
title: "🔢 Decode the String | GFG Solution 🔍"
keywords🏷️: ["🔢 string decoding", "🔍 stack", "📍 bracket matching", "📈 nested structures", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Decode the String problem: expand encoded patterns k[substring] using stack-based approach for nested bracket handling. 🚀"
date: 📅 2025-09-17
---

# *17. Decode the String*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/decode-the-string2444/1)

## **🧩 Problem Description**

Given an encoded string `s`, decode it by expanding the pattern `k[substring]`, where the substring inside brackets is written `k` times. `k` is guaranteed to be a positive integer, and the encoded string contains only lowercase English alphabets and digits. Return the final decoded string.

The test cases are generated so that the length of the output string will never exceed $10^5$.

## **📘 Examples**

### Example 1

```cpp
Input: s = "3[b2[ca]]"
Output: "bcacabcacabcaca"
Explanation: Inner substring "2[ca]" breaks down into "caca".
Now, new string becomes "3[bcaca]"
Similarly "3[bcaca]" becomes "bcacabcacabcaca" which is the final result.
```

### Example 2

```cpp
Input: s = "3[ab]"
Output: "ababab"
Explanation: The substring "ab" is repeated 3 times giving "ababab".
```

### Example 3

```cpp
Input: s = "2[bc]3[cd]ef"
Output: "bcbccdcdcdef"
Explanation: "2[bc]" becomes "bcbc", "3[cd]" becomes "cdcdcd", 
and concatenating with "ef" gives "bcbccdcdcdef".
```

## **🔒 Constraints**

* $1 \le |s| \le 10^5$
* $1 \le k \le 100$

## **✅ My Approach**

The optimal approach uses a **Stack** to handle nested bracket structures and decode patterns from inside out:

### **Stack-Based Decoding**

1. **Initialize Data Structures:**
   * Use a stack of pairs to store `{current_string, repeat_count}`.
   * Maintain `curr` string for building current segment.
   * Track `num` for parsing repeat counts.

2. **Process Each Character:**
   * **Digit:** Build the repeat count by multiplying by 10 and adding current digit.
   * **Opening Bracket '[' :** Push current state `{curr, num}` to stack, reset variables.
   * **Closing Bracket ']' :** Pop from stack, repeat current string `num` times, and append to previous string.
   * **Letter:** Simply append to current string.

3. **Handle Nested Patterns:**
   * Stack naturally handles nested brackets by processing innermost patterns first.
   * Each closing bracket resolves one level of nesting.

4. **Return Result:**
   * After processing all characters, `curr` contains the fully decoded string.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the input string. Each character is processed exactly once, and string operations are amortized constant time.
* **Expected Auxiliary Space Complexity:** O(d × m), where d is the maximum depth of nested brackets and m is the average length of strings at each level. In the worst case, this is O(n) where all characters could be stored in the stack.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string decodedString(string& s) {
        stack<pair<string, int>> st;
        string curr = "";
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                st.push({curr, num});
                curr = "";
                num = 0;
            } else if (c == ']') {
                auto [prev, cnt] = st.top();
                st.pop();
                string temp = curr;
                for (int i = 1; i < cnt; i++) curr += temp;
                curr = prev + curr;
            } else {
                curr += c;
            }
        }
        return curr;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Recursive Approach**

### 💡 Algorithm Steps:

1. Use recursion with index tracking to parse nested structures
2. Parse numbers and handle bracket pairs recursively
3. Build result string by combining recursive calls
4. Return decoded string with updated index position

```cpp
class Solution {
public:
    string decodedString(string& s) {
        int idx = 0;
        return decode(s, idx);
    }
    
private:
    string decode(string& s, int& i) {
        string res = "";
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i++] - '0';
                }
                i++; 
                string sub = decode(s, i);
                i++; 
                while (num--) res += sub;
            } else {
                res += s[i++];
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through string
* **Space:** 💾 O(d) - Recursion depth for nested brackets

### ✅ **Why This Approach?**

* Natural handling of nested structures
* Cleaner code without explicit stack management
* Easy to understand recursive pattern

## 📊 **3️⃣ Two-Stack Approach**

### 💡 Algorithm Steps:

1. Use separate stacks for strings and numbers
2. Track current string and current number independently
3. Process brackets by combining stack tops
4. Build final result through stack operations

```cpp
class Solution {
public:
    string decodedString(string& s) {
        stack<string> strSt;
        stack<int> numSt;
        string curr = "";
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (c == '[') {
                strSt.push(curr);
                numSt.push(num);
                curr = "";
                num = 0;
            } else if (c == ']') {
                string temp = curr;
                curr = strSt.top();
                strSt.pop();
                int cnt = numSt.top();
                numSt.pop();
                while (cnt--) curr += temp;
            } else {
                curr += c;
            }
        }
        return curr;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal with stack operations
* **Space:** 💾 O(n) - Two stacks for nested levels

### ✅ **Why This Approach?**

* Clear separation of concerns with two stacks
* Straightforward stack-based parsing
* Good for understanding bracket matching patterns

## 📊 **4️⃣ String Stream Approach**

### 💡 Algorithm Steps:

1. Use string stream for efficient string building
2. Process characters with minimal string concatenation
3. Handle nested brackets with stack-based state management
4. Optimize memory usage through stream operations

```cpp
class Solution {
public:
    string decodedString(string& s) {
        stack<pair<stringstream, int>> st;
        stringstream curr;
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (c == '[') {
                st.push({move(curr), num});
                curr = stringstream();
                num = 0;
            } else if (c == ']') {
                string temp = curr.str();
                curr = move(st.top().first);
                int cnt = st.top().second;
                st.pop();
                while (cnt--) curr << temp;
            } else {
                curr << c;
            }
        }
        return curr.str();
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Efficient string building with streams
* **Space:** 💾 O(n) - Stack space plus string stream buffers

### ✅ **Why This Approach?**

* Memory-efficient string construction
* Reduced temporary string allocations
* Better performance for large decoded strings

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Pair Stack**                 | 🟢 O(n)                | 🟢 O(n)                 | 🚀 Clean single stack             | 🔧 Requires C++17 for auto           |
| 🔄 **Recursive**                   | 🟢 O(n)                | 🟡 O(d)                 | 📖 Natural nested handling       | 💾 Recursion stack overhead          |
| 🔍 **Two-Stack**                  | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Clear separation               | 🐌 Two stack management              |
| 📊 **String Stream**              | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Memory efficient               | 🔧 Complex stream handling            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Modern C++**                                 | 🥇 **Pair Stack**                    | ★★★★★                     |
| 📖 **Readability priority**                       | 🥈 **Recursive**                     | ★★★★☆                     |
| 🔧 **Learning/Teaching**                          | 🥉 **Two-Stack**                     | ★★★★☆                     |
| 🎯 **Memory optimization**                        | 🏅 **String Stream**                 | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    static String decodeString(String s) {
        Stack<StringBuilder> stStr = new Stack<>();
        Stack<Integer> stNum = new Stack<>();
        StringBuilder curr = new StringBuilder();
        int num = 0;
        
        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                stStr.push(curr);
                stNum.push(num);
                curr = new StringBuilder();
                num = 0;
            } else if (c == ']') {
                StringBuilder temp = curr;
                curr = stStr.pop();
                int cnt = stNum.pop();
                while (cnt-- > 0) curr.append(temp);
            } else {
                curr.append(c);
            }
        }
        return curr.toString();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def decodedString(self, s):
        st_str, st_num = [], []
        curr, num = "", 0
        
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == '[':
                st_str.append(curr)
                st_num.append(num)
                curr, num = "", 0
            elif c == ']':
                temp = curr
                curr = st_str.pop()
                cnt = st_num.pop()
                curr += temp * cnt
            else:
                curr += c
        return curr
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
