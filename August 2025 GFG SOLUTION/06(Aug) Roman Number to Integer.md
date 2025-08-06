---
title: "🔢 Roman Number to Integer | GFG Solution 🏛️"
keywords🏷️: ["🔢 roman numerals", "🏛️ string processing", "📊 greedy algorithm", "🔍 pattern matching", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Roman Number to Integer problem: convert Roman numerals to decimal using greedy pattern matching technique for optimal performance. 🚀"
date: 📅 2025-08-06
---

# *06. Roman Number to Integer*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1)

## **🧩 Problem Description**

Given a string `s` in Roman number format, your task is to convert it to an integer. Various symbols and their values are given below:

**Roman Numeral Values:**
- I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000

**Special Cases (Subtraction Rules):**
- IV = 4, IX = 9, XL = 40, XC = 90, CD = 400, CM = 900

The goal is to parse the Roman numeral string and return its equivalent decimal integer value.

## **📘 Examples**

### Example 1

```cpp
Input: s = "IX"
Output: 9
Explanation: IX is a Roman symbol which represents 10 – 1 = 9.
```

### Example 2

```cpp
Input: s = "XL"
Output: 40
Explanation: XL is a Roman symbol which represents 50 – 10 = 40.
```

### Example 3

```cpp
Input: s = "MCMIV"
Output: 1904
Explanation: M is 1000, CM is 1000 – 100 = 900, and IV is 4. 
So we have total as 1000 + 900 + 4 = 1904.
```

## **🔒 Constraints**

* $1 \le \text{roman number} \le 3999$
* $s[i] \in [I, V, X, L, C, D, M]$

## **✅ My Approach**

The optimal approach uses a **Greedy Pattern Matching** technique that processes Roman numerals from largest to smallest values:

### **Greedy Pattern Matching Algorithm**

1. **Initialize Data Structures:**
   * Create parallel arrays: `vals[]` for decimal values and `syms[]` for corresponding Roman patterns.
   * Order them from largest to smallest value (M=1000 down to I=1).
   * Include subtraction cases (CM=900, CD=400, XC=90, XL=40, IX=9, IV=4).

2. **Greedy Matching:**
   * For each Roman pattern in descending order of value:
   * Check if current position in string matches the pattern.
   * If match found, add its value to result and advance position by pattern length.
   * Repeat until no more matches for current pattern.

3. **Process All Patterns:**
   * Continue with next smaller pattern until all 13 patterns are processed.
   * This ensures larger values are consumed first (greedy approach).

4. **Return Result:**
   * The accumulated sum represents the decimal equivalent.

**Key Insight:** By processing patterns in descending order, we naturally handle subtraction cases (like CM, CD) before their individual components, ensuring correct interpretation.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the Roman numeral string. Each character is processed at most once as we advance through the string systematically.
* **Expected Auxiliary Space Complexity:** O(1), as we use fixed-size arrays for storing the 13 Roman patterns and their values, requiring constant extra space regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int romanToDecimal(string s) {
        int vals[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string syms[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int res = 0, i = 0;
        for (int j = 0; j < 13; j++) {
            while (i + syms[j].length() <= s.length() && s.substr(i, syms[j].length()) == syms[j]) {
                res += vals[j];
                i += syms[j].length();
            }
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Map-Based Single Pass Approach**

### 💡 Algorithm Steps:

1. Create a map for Roman numeral values for O(1) lookup.
2. Traverse string once from left to right.
3. Compare current and next character values to handle subtraction cases.
4. Add or subtract based on the comparison result.

```cpp
class Solution {
public:
    int romanToDecimal(string s) {
        unordered_map<char,int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && m[s[i]] < m[s[i+1]]) {
                res += m[s[i+1]] - m[s[i]];
                i++;
            } else {
                res += m[s[i]];
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through string
* **Auxiliary Space:** 💾 O(1) - Fixed size map

### ✅ **Why This Approach?**

* Clean and readable logic
* Handles all Roman numeral rules naturally
* Good for understanding Roman numeral principles

## 📊 **3️⃣ Reverse Traversal Approach**

### 💡 Algorithm Steps:

1. Start from the rightmost character and move left.
2. Keep track of the maximum value seen so far.
3. If current value is less than max, subtract it (handles IV, IX cases).
4. Otherwise add it to result and update maximum.

```cpp
class Solution {
public:
    int romanToDecimal(string s) {
        int vals[256] = {0};
        vals['I'] = 1; vals['V'] = 5; vals['X'] = 10; vals['L'] = 50;
        vals['C'] = 100; vals['D'] = 500; vals['M'] = 1000;
        int res = 0, maxVal = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int val = vals[s[i]];
            if (val < maxVal) res -= val;
            else {
                res += val;
                maxVal = val;
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single reverse pass
* **Auxiliary Space:** 💾 O(1) - Array lookup table

### ✅ **Why This Approach?**

* Elegant reverse logic eliminates lookahead
* Simple comparison rule for subtraction cases
* Efficient array-based character lookup

## 📊 **4️⃣ Switch-Case Optimized**

### 💡 Algorithm Steps:

1. Use switch statement for fastest character to value mapping.
2. Process string left to right with lookahead for subtraction cases.
3. Skip next character when subtraction pair is found.
4. Accumulate result with addition or subtraction.

```cpp
class Solution {
public:
    int getVal(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    
    int romanToDecimal(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            int curr = getVal(s[i]);
            int next = (i + 1 < s.length()) ? getVal(s[i+1]) : 0;
            if (curr < next) {
                res += next - curr;
                i++;
            } else {
                res += curr;
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal with constant lookups
* **Auxiliary Space:** 💾 O(1) - No extra data structures

### ✅ **Why This Approach?**

* Switch statement provides fastest character mapping
* Branch prediction friendly code structure
* Minimal memory footprint

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Greedy Pattern Match**       | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Handles all cases directly     | 📝 More complex setup                |
| 🔍 **Map-Based**                  | 🟢 O(n)                | 🟢 O(1)                 | 📖 Clean and intuitive           | 🐌 Map lookup overhead               |
| 📊 **Reverse Traversal**          | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Elegant logic                  | 🔄 Less intuitive flow              |
| 🔄 **Switch-Case**                | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Fastest execution              | 📝 More verbose code                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Maximum performance needed**                 | 🥇 **Switch-Case**                   | ★★★★★                     |
| 📖 **Code readability priority**                  | 🥈 **Map-Based**                     | ★★★★☆                     |
| 🔧 **Pattern matching elegance**                  | 🥉 **Greedy Pattern**                | ★★★★★                     |
| 🎯 **Interview/Competitive**                      | 🏅 **Reverse Traversal**             | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int romanToDecimal(String s) {
        int[] vals = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] syms = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int res = 0, i = 0;
        for (int j = 0; j < 13; j++) {
            while (i + syms[j].length() <= s.length() && s.substring(i, i + syms[j].length()).equals(syms[j])) {
                res += vals[j];
                i += syms[j].length();
            }
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def romanToDecimal(self, s): 
        vals = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        syms = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        res = i = 0
        for j in range(13):
            while i + len(syms[j]) <= len(s) and s[i:i+len(syms[j])] == syms[j]:
                res += vals[j]
                i += len(syms[j])
        return res
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
