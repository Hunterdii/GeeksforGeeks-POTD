---
title: "📝 Implement Undo & Redo | GFG Solution 🔄"
keywords🏷️: ["📝 text editor", "🔄 undo redo", "📚 stack", "⚡ operations", "📘 GFG", "🏁 competitive programming", "📊 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Implement Undo & Redo problem: build a text editor with append, undo, redo, and read operations using stack-based approach. 🚀"
date: 📅 2025-01-20
---

# *20. Implement Undo & Redo*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/implement-undo-redo/1)

## **🧩 Problem Description**

You are given a text document that is initially empty. You need to implement the following operations:

- **append(char x)** - Append the character x to the end of the document.
- **undo()** - Undo the most recent append operation (remove the last appended character).
- **redo()** - Reapply the most recent undone operation (restore the last character removed by undo).
- **read()** - Return the current content of the document as a string.

The operations are represented in numeric form through queries:
- `1 x` - Call append(x)
- `2` - Call undo()
- `3` - Call redo()
- `4` - Call read()

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [[1 'A'], [1 'B'], [1 'C'], [2], [4], [3], [4]]
Output: ["AB", "ABC"]
Explanation: 
1st query: Append('A'), Document contains "A".
2nd query: Append('B'), Document contains "AB".
3rd query: Append('C'), Document contains "ABC".
4th query: UNDO(), Last character is removed, Document contains "AB".
5th query: READ(), Document content "AB" will be printed.
6th query: REDO(), Document contains "ABC".
7th query: READ(), Document content "ABC" will be printed.
```

### Example 2

```cpp
Input: arr[] = [[1 'D'], [2], [4]]
Output: [""]
Explanation: 
1st query: Append('D'), Document contains "D".
2nd query: UNDO(), Last character is removed, Document becomes empty.
3rd query: READ(), Empty Document will be printed.
```

## **🔒 Constraints**

* $1 \le q \le 10^4$

## **✅ My Approach**

The optimal approach uses a **Stack-Based** technique to efficiently manage undo and redo operations:

### **Stack-Based Approach**

1. **Data Structures:**
   * Use a string `d` to maintain the current document content.
   * Use a stack `r` to store characters that were undone for redo functionality.

2. **Append Operation:**
   * Add the character to the end of the document string.
   * Clear the redo stack since any new append invalidates previous redo history.

3. **Undo Operation:**
   * If the document is not empty, remove the last character from the document.
   * Push this removed character onto the redo stack for potential redo operation.

4. **Redo Operation:**
   * If the redo stack is not empty, pop the top character.
   * Append this character back to the document string.

5. **Read Operation:**
   * Simply return the current document string.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(1) for append, undo, and redo operations, as each operation performs a constant number of stack/string operations. O(n) for read operation where n is the length of the document, as we need to return the entire string.
* **Expected Auxiliary Space Complexity:** O(n), where n is the total number of characters that have been appended to the document. In the worst case, all appended characters could be stored in the redo stack.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
    string d;
    stack<char> r;
public:
    void append(char x) {
        d += x;
        while (!r.empty()) r.pop();
    }
    void undo() {
        if (!d.empty()) {
            r.push(d.back());
            d.pop_back();
        }
    }
    void redo() {
        if (!r.empty()) {
            d += r.top();
            r.pop();
        }
    }
    string read() { return d; }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Deque-Based History Approach**

### 💡 Algorithm Steps:

1. Use a deque to maintain the document state for efficient operations.
2. Store snapshots of document states in a vector for undo capability.
3. Track current position in history to enable both undo and redo.
4. Navigate through document history using position pointer.

```cpp
class Solution {
    deque<char> d;
    vector<deque<char>> h;
    int p = 0;
public:
    void append(char x) {
        d.push_back(x);
        h.resize(p + 1);
        h.push_back(d);
        p++;
    }
    void undo() {
        if (p > 0) d = h[--p];
    }
    void redo() {
        if (p < h.size() - 1) d = h[++p];
    }
    string read() {
        return string(d.begin(), d.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) per operation - Due to state copying
* **Auxiliary Space:** 💾 O(n*m) - Stores m versions of document with n characters

### ✅ **Why This Approach?**

* Full history preservation for unlimited undo/redo.
* Flexible navigation through document states.
* Supports complex multi-operation undo scenarios.

## 📊 **3️⃣ Two-Stack Command Pattern**

### 💡 Algorithm Steps:

1. Maintain two stacks: one for undo commands and one for redo commands.
2. Store operation type and character in each stack entry.
3. On append, push to undo stack and clear redo stack.
4. Execute reverse operations when undo/redo is triggered.

```cpp
class Solution {
    string d;
    stack<pair<int, char>> u, r;
public:
    void append(char x) {
        d += x;
        u.push({1, x});
        while (!r.empty()) r.pop();
    }
    void undo() {
        if (!u.empty()) {
            auto [op, ch] = u.top();
            u.pop();
            d.pop_back();
            r.push({1, ch});
        }
    }
    void redo() {
        if (!r.empty()) {
            auto [op, ch] = r.top();
            r.pop();
            d += ch;
            u.push({1, ch});
        }
    }
    string read() { return d; }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(1) - Constant time per operation
* **Auxiliary Space:** 💾 O(n) - Stores operation history

### ✅ **Why This Approach?**

* Extensible to support multiple operation types.
* Clean command pattern implementation.
* Efficient operation tracking and reversal.

## 📊 **4️⃣ Vector with Position Tracking**

### 💡 Algorithm Steps:

1. Use vector to store all characters ever appended to document.
2. Track active length of document instead of physically removing characters.
3. Adjust length pointer for undo and redo operations.
4. Return substring based on current active length for read operation.

```cpp
class Solution {
    vector<char> d;
    int len = 0, cap = 0;
public:
    void append(char x) {
        if (len == d.size()) d.push_back(x);
        else d[len] = x;
        len++;
        cap = len;
    }
    void undo() {
        if (len > 0) len--;
    }
    void redo() {
        if (len < cap) len++;
    }
    string read() {
        return string(d.begin(), d.begin() + len);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(1) for append/undo/redo, O(n) for read
* **Auxiliary Space:** 💾 O(n) - Stores maximum document size

### ✅ **Why This Approach?**

* Minimal memory reallocation with vector.
* Fast pointer-based undo/redo operations.
* Cache-friendly sequential memory access.

## 📊 **5️⃣ List-Based Approach**

### 💡 Algorithm Steps:

1. Use a doubly linked list or list container to store characters.
2. Maintain iterators for current document end and redo position.
3. On append, insert character and move iterator forward.
4. On undo, move iterator backward; on redo, move forward.

```cpp
class Solution {
    list<char> d;
    list<char>::iterator curr;
public:
    Solution() { curr = d.end(); }
    void append(char x) {
        d.erase(curr, d.end());
        d.push_back(x);
        curr = d.end();
    }
    void undo() {
        if (curr != d.begin()) curr--;
    }
    void redo() {
        if (curr != d.end()) curr++;
    }
    string read() {
        return string(d.begin(), curr);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(1) for append/undo/redo, O(n) for read
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Natural implementation with list iterators.
* Efficient insertion and deletion at any position.
* Clean separation between current and future states.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Stack-Based**               | 🟢 O(1)                | 🟢 O(n)                 | 🚀 Optimal & simple               | 🔧 Single character operations only   |
| 🔍 **Deque History**              | 🟡 O(n)                | 🔴 O(n*m)               | 📖 Full history access            | 💾 High memory usage                  |
| 📊 **Command Pattern**            | 🟢 O(1)                | 🟢 O(n)                 | 🎯 Extensible design              | 🐌 Extra overhead for simple cases    |
| 🔄 **Vector Tracking**            | 🟢 O(1)                | 🟢 O(n)                 | ⭐ Cache efficient                | 🔧 Read operation slower              |
| 📝 **List-Based**                 | 🟢 O(1)                | 🟢 O(n)                 | 🎯 Iterator elegance              | 🐌 Not cache-friendly                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Simple editor operations**                      | 🥇 **Stack-Based**                   | ★★★★★                     |
| 📖 **Complex undo history needed**                   | 🥈 **Deque History**                 | ★★★★☆                     |
| 🔧 **Multiple operation types**                      | 🥉 **Command Pattern**               | ★★★★☆                     |
| 🎯 **Memory optimization**                           | 🏅 **Vector Tracking**               | ★★★★☆                     |
| 📚 **Iterator-based design**                         | 🎖️ **List-Based**                    | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    StringBuilder d = new StringBuilder();
    Stack<Character> r = new Stack<>();
    
    public void append(char x) {
        d.append(x);
        r.clear();
    }
    
    public void undo() {
        if (d.length() > 0) {
            r.push(d.charAt(d.length() - 1));
            d.deleteCharAt(d.length() - 1);
        }
    }
    
    public void redo() {
        if (!r.isEmpty()) {
            d.append(r.pop());
        }
    }
    
    public String read() {
        return d.toString();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def __init__(self):
        self.d = []
        self.r = []
    
    def append(self, x):
        self.d.append(x)
        self.r.clear()
    
    def undo(self):
        if self.d:
            self.r.append(self.d.pop())
    
    def redo(self):
        if self.r:
            self.d.append(self.r.pop())
    
    def read(self):
        return ''.join(self.d)
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
