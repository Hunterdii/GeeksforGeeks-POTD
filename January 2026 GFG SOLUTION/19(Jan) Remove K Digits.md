---
title: "🔢 Remove K Digits | GFG Solution 🔍"  
keywords🏷️: ["🔢 remove k digits", "🔍 monotonic stack", "📍 greedy algorithm", "📈 string manipulation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]  
author: "✍️ Het Patel (Hunterdii)"  
description: "✅ GFG solution to the Remove K Digits problem: find the smallest possible number after removing k digits using greedy monotonic stack approach. 🚀"  
date: 📅 2025-01-19  
---

# *19. Remove K Digits*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/remove-k-digits/1)

## **🧩 Problem Description**

Given a non-negative integer `s` represented as a string and an integer `k`, remove exactly `k` digits from the string so that the resulting number is the **smallest possible**, while maintaining the relative order of the remaining digits.

**Note:** The resulting number must not contain any leading zeros. If the resulting number is an empty string after the removal, return `"0"`.

## **📘 Examples**

### Example 1

```cpp
Input: s = "4325043", k = 3
Output: "2043"
Explanation: Remove the three digits 4, 3, and 5 to form the new number "2043" 
which is smallest among all possible removals.
```

### Example 2

```cpp
Input: s = "765028321", k = 5
Output: "221"
Explanation: Remove the five digits 7, 6, 5, 8 and 3 to form the new number "0221". 
Since we are not supposed to keep leading 0s, we get "221".
```

## **🔒 Constraints**

* $1 \le k \le |s| \le 10^6$

## **✅ My Approach**

The optimal solution uses a **Greedy Monotonic Stack** approach to build the smallest possible number:

### **Greedy Monotonic Stack Strategy**

1. **Initialize Result String:**
   * Use a string/stack to build the result digit by digit.
   * Maintain monotonic increasing property for optimal smallest number.

2. **Process Each Digit:**
   * Iterate through each character in the input string.
   * While the result is not empty, k > 0, and the last digit in result is greater than current digit:
     - Remove the last digit from result (greedy removal of larger digit).
     - Decrement k.

3. **Handle Leading Zeros:**
   * Only add digits to result if result is non-empty OR current digit is not '0'.
   * This ensures no leading zeros in final result.

4. **Remove Remaining Digits:**
   * If k > 0 after processing all digits, remove k digits from the end of result.
   * These are the largest remaining digits at the end.

5. **Return Result:**
   * If result is empty, return `"0"`.
   * Otherwise, return the constructed result string.

## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n), where n is the length of the string. Each digit is processed at most twice - once when added and once when potentially removed, resulting in linear time complexity.
* **Expected Auxiliary Space Complexity:** O(n), as we use a result string/stack to store the processed digits. In the worst case, all digits might be retained in the result.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string removeKdig(string &s, int k) {
        string res;
        for (char c : s) {
            while (res.size() && k && res.back() > c) {
                res.pop_back();
                k--;
            }
            if (res.size() || c != '0') res += c;
        }
        while (res.size() && k--) res.pop_back();
        return res.empty() ? "0" : res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Deque-Based Approach**

### 💡 Algorithm Steps:

1. Use deque to maintain digits in monotonic increasing order.
2. Remove larger digits from back when smaller digit arrives and k > 0.
3. Skip leading zeros by checking if deque is empty before insertion.
4. Remove remaining digits from back if k budget still remains.

```cpp
class Solution {
public:
    string removeKdig(string &s, int k) {
        deque<char> dq;
        for (char c : s) {
            while (!dq.empty() && k && dq.back() > c) {
                dq.pop_back();
                k--;
            }
            if (!dq.empty() || c != '0') dq.push_back(c);
        }
        while (!dq.empty() && k--) dq.pop_back();
        string res(dq.begin(), dq.end());
        return res.empty() ? "0" : res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through string
* **Auxiliary Space:** 💾 O(n) - Deque storage

### ✅ **Why This Approach?**

* Flexible data structure for both ends
* Similar performance to string approach
* Good for bidirectional operations

## 📊 **3️⃣ Vector-Based Approach**

### 💡 Algorithm Steps:

1. Build result using vector for efficient operations.
2. Maintain monotonic stack property using vector.
3. Handle leading zeros and remaining removals.
4. Convert vector to string at the end.

```cpp
class Solution {
public:
    string removeKdig(string &s, int k) {
        vector<char> v;
        for (char c : s) {
            while (!v.empty() && k && v.back() > c) {
                v.pop_back();
                k--;
            }
            if (!v.empty() || c != '0') v.push_back(c);
        }
        while (!v.empty() && k--) v.pop_back();
        return v.empty() ? "0" : string(v.begin(), v.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal
* **Auxiliary Space:** 💾 O(n) - Vector storage

### ✅ **Why This Approach?**

* Fast random access if needed
* Cache-friendly memory layout
* Standard container familiarity

## 📊 **4️⃣ In-Place String Modification**

### 💡 Algorithm Steps:

1. Use two pointers to modify string in-place.
2. Write pointer tracks where to place next valid digit.
3. Read pointer scans through original string.
4. Minimize allocations by reusing input string.

```cpp
class Solution {
public:
    string removeKdig(string &s, int k) {
        int w = 0;
        for (int i = 0; i < s.size(); i++) {
            while (w > 0 && k && s[w - 1] > s[i]) {
                w--;
                k--;
            }
            if (w > 0 || s[i] != '0') s[w++] = s[i];
        }
        w = max(0, w - k);
        return w ? s.substr(0, w) : "0";
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with in-place modification
* **Auxiliary Space:** 💾 O(1) - No extra data structures

### ✅ **Why This Approach?**

* Most space-efficient solution
* No additional memory allocation
* Optimal for memory-constrained environments

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔤 **String Builder**              | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Clean and readable             | 💾 Extra space for result            |
| 🔄 **Deque-Based**                | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Flexible operations            | 📦 Overhead of deque                 |
| 📊 **Vector-Based**               | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Cache-friendly                 | 🔧 Conversion overhead               |
| ✏️ **In-Place**                   | 🟢 O(n)                | 🟢 O(1)                 | 💎 Optimal space usage            | 🔧 Modifies input                    |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Clean code priority**                            | 🥇 **String Builder**                | ★★★★★                     |
| 💾 **Memory constraints**                             | 🥈 **In-Place**                      | ★★★★★                     |
| 🔧 **Bidirectional needs**                            | 🥉 **Deque-Based**                   | ★★★★☆                     |
| 🎯 **General purpose**                                | 🏅 **Vector-Based**                  | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public String removeKdig(String s, int k) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            while (sb.length() > 0 && k > 0 && sb.charAt(sb.length() - 1) > c) {
                sb.deleteCharAt(sb.length() - 1);
                k--;
            }
            if (sb.length() > 0 || c != '0') sb.append(c);
        }
        while (sb.length() > 0 && k-- > 0) sb.deleteCharAt(sb.length() - 1);
        return sb.length() == 0 ? "0" : sb.toString();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def removeKdig(self, s, k):
        stk = []
        for c in s:
            while stk and k and stk[-1] > c:
                stk.pop()
                k -= 1
            if stk or c != '0':
                stk.append(c)
        while stk and k:
            stk.pop()
            k -= 1
        return ''.join(stk) if stk else '0'
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
