---
title: "🔤 Palindrome Sentence | GFG Solution 🔍"
keywords🏷️: ["🔤 palindrome", "🔍 two pointers", "📍 string processing", "📈 case insensitive", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Palindrome Sentence problem: check if a string is palindromic after removing non-alphanumeric characters and converting to lowercase using two pointers technique. 🚀"
date: 📅 2025-08-05
---

# *05. Palindrome Sentence*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1)

## **🧩 Problem Description**

A palindrome sentence is a sequence of characters, such as word, phrase, or series of symbols that reads the same backward as forward after converting all uppercase letters to lowercase and removing all non-alphanumeric characters (including spaces and punctuation).

Your task is to determine if the given string `s` forms a palindrome sentence according to the above definition.

## **📘 Examples**

### Example 1

```cpp
Input: s = "Too hot to hoot"
Output: true
Explanation: If we remove all non-alphanumeric characters and convert all uppercase letters to lowercase, 
string s will become "toohottohoot" which is a palindrome.
```

### Example 2

```cpp
Input: s = "Abc 012..## 10cbA"
Output: true
Explanation: If we remove all non-alphanumeric characters and convert all uppercase letters to lowercase, 
string s will become "abc01210cba" which is a palindrome.
```

### Example 3

```cpp
Input: s = "ABC $. def01ASDF"
Output: false
Explanation: The processed string becomes "abcdef01asdf", which is not a palindrome.
```

## **🔒 Constraints**

* $1 \le s.length() \le 10^6$

## **✅ My Approach**

The optimal approach uses the **Two Pointers** technique to check palindrome properties without creating an additional string:

### **Two Pointers Technique**

1. **Initialize Pointers:**
   * Use two pointers: `left` starting from beginning and `right` starting from end.
   * Move pointers towards each other while checking palindrome condition.

2. **Skip Non-Alphanumeric:**
   * When `left` pointer encounters non-alphanumeric character, increment it.
   * When `right` pointer encounters non-alphanumeric character, decrement it.
   * Continue until both pointers point to valid alphanumeric characters.

3. **Compare Characters:**
   * Convert both characters to lowercase using `tolower()` function.
   * If characters don't match, return `false` immediately.
   * If they match, move both pointers inward.

4. **Continue Until Complete:**
   * Repeat process until `left >= right`.
   * If all comparisons pass, return `true`.

5. **Edge Cases:**
   * Empty string or single character is considered palindrome.
   * String with only non-alphanumeric characters is palindrome.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. Each character is visited at most once by either the left or right pointer, making it a single pass algorithm.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the two pointers and temporary variables, regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool isPalinSent(string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ String Building Approach**

### 💡 Algorithm Steps:

1. Build a cleaned string containing only alphanumeric characters in lowercase.
2. Compare characters from both ends moving towards center.
3. Return false if any mismatch is found during comparison.
4. Return true if all characters match perfectly.

```cpp
class Solution {
public:
    bool isPalinSent(string &s) {
        string clean;
        for (char c : s) if (isalnum(c)) clean += tolower(c);
        int n = clean.size();
        for (int i = 0; i < n / 2; i++)
            if (clean[i] != clean[n - 1 - i]) return false;
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass for cleaning and comparison
* **Auxiliary Space:** 💾 O(n) - Additional space for cleaned string

### ✅ **Why This Approach?**

* Clear separation of cleaning and checking logic
* Easy to debug and understand flow
* Good for scenarios where original string preservation matters

## 📊 **3️⃣ Recursive Approach**

### 💡 Algorithm Steps:

1. Use recursion to check palindrome by comparing outer characters.
2. Skip non-alphanumeric characters at both ends recursively.
3. Compare current valid characters in case-insensitive manner.
4. Recursively check the remaining substring between valid characters.

```cpp
class Solution {
public:
    bool isPalinSent(string &s) {
        return check(s, 0, s.size() - 1);
    }
private:
    bool check(string &s, int l, int r) {
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;
        if (l >= r) return true;
        return tolower(s[l]) == tolower(s[r]) && check(s, l + 1, r - 1);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each character visited once
* **Auxiliary Space:** 💾 O(n) - Recursion stack space

### ✅ **Why This Approach?**

* Elegant recursive solution pattern
* Natural divide and conquer approach
* Good for understanding algorithmic thinking

## 📊 **4️⃣ STL Algorithm Approach**

### 💡 Algorithm Steps:

1. Use STL algorithms to transform and filter the string efficiently.
2. Remove non-alphanumeric characters using remove_if predicate.
3. Transform all characters to lowercase using transform algorithm.
4. Use equal algorithm to compare string with its reverse.

```cpp
class Solution {
public:
    bool isPalinSent(string &s) {
        string clean = s;
        clean.erase(remove_if(clean.begin(), clean.end(), 
                   [](char c) { return !isalnum(c); }), clean.end());
        transform(clean.begin(), clean.end(), clean.begin(), ::tolower);
        return equal(clean.begin(), clean.begin() + clean.size() / 2, clean.rbegin());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - STL algorithms are optimized
* **Auxiliary Space:** 💾 O(n) - Copy of string for processing

### ✅ **Why This Approach?**

* Leverages powerful STL algorithms
* Functional programming style approach
* Demonstrates advanced C++ knowledge

## 📊 **5️⃣ Reverse and Compare**

### 💡 Algorithm Steps:

1. Create a cleaned version of the string with only alphanumeric characters in lowercase.
2. Create a reversed version of the cleaned string.
3. Compare the cleaned string with its reverse.
4. Return true if they are identical, false otherwise.

```cpp
class Solution {
public:
    bool isPalinSent(string &s) {
        string clean, reversed;
        for (char c : s) {
            if (isalnum(c)) {
                char lower = tolower(c);
                clean += lower;
                reversed = lower + reversed;
            }
        }
        return clean == reversed;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass to build both strings
* **Auxiliary Space:** 💾 O(n) - Space for both cleaned and reversed strings

### ✅ **Why This Approach?**

* Intuitive approach mimicking the problem statement
* Easy to understand and implement
* Good for demonstrating string manipulation

> **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs _(fails ~1110 /1111 test cases due to time constraints)_.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Two Pointer**                | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal space complexity       | 🔧 In-place character checking        |
| 🔍 **String Building**            | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear logic separation         | 💾 Extra space for cleaned string    |
| 📊 **Recursive**                  | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Elegant recursive pattern      | 📚 Stack space overhead              |
| 🔄 **STL Algorithms**             | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Advanced C++ features          | 🔧 Complex STL understanding needed  |
| 🔄 **Reverse and Compare (TLE)**        | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Intuitive problem mapping      | 💾 Double string storage             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Memory constrained environment**             | 🥇 **Two Pointer**                   | ★★★★★                     |
| 📖 **Code readability priority**                  | 🥈 **String Building**               | ★★★★☆                     |
| 🔧 **Learning recursion patterns**                | 🥉 **Recursive**                     | ★★★☆☆                     |
| 🎯 **Advanced C++ demonstration**                 | 🏅 **STL Algorithms**                | ★★★★☆                     |
| 📚 **Educational/Intuitive understanding**        | 🎖️ **Reverse and Compare (TLE)**           | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public boolean isPalinSent(String s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (l < r && !Character.isLetterOrDigit(s.charAt(l))) l++;
            while (l < r && !Character.isLetterOrDigit(s.charAt(r))) r--;
            if (Character.toLowerCase(s.charAt(l++)) != Character.toLowerCase(s.charAt(r--))) return false;
        }
        return true;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def isPalinSent(self, s):
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not s[l].isalnum(): l += 1
            while l < r and not s[r].isalnum(): r -= 1
            if s[l].lower() != s[r].lower(): return False
            l, r = l + 1, r - 1
        return True
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
