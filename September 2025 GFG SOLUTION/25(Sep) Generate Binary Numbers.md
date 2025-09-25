---
title: "🔢 Generate Binary Numbers | GFG Solution 🔍"
keywords🏷️: ["🔢 binary generation", "🔍 number conversion", "📍 bit manipulation", "📈 queue", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Generate Binary Numbers problem: generate binary representation of numbers from 1 to n using efficient conversion techniques. 🚀"
date: 📅 2025-09-25
---

# *25. Generate Binary Numbers*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1)

## **🧩 Problem Description**

Given a number `n`, the task is to generate all binary numbers with decimal values from `1` to `n`.

A binary number is the base-2 representation of a decimal number, using only digits 0 and 1. The goal is to convert each decimal number from 1 to n into its corresponding binary string representation.

## **📘 Examples**

### Example 1

```cpp
Input: n = 4
Output: ["1", "10", "11", "100"]
Explanation: Binary numbers from 1 to 4 are 1, 10, 11 and 100.
```

### Example 2

```cpp
Input: n = 6
Output: ["1", "10", "11", "100", "101", "110"]
Explanation: Binary numbers from 1 to 6 are 1, 10, 11, 100, 101 and 110.
```

## **🔒 Constraints**

* $1 \le n \le 10^6$

## **✅ My Approach**

The optimal approach uses **Direct Decimal to Binary Conversion** technique:

### **Direct Conversion Method**

1. **Initialize Result Array:**
   * Create a vector/array to store binary strings for numbers 1 to n.

2. **For Each Number i (1 to n):**
   * Convert decimal number i to its binary representation.
   * Use division by 2 method: repeatedly divide by 2 and collect remainders.
   * Build binary string by prepending each remainder to the result.

3. **Binary Conversion Process:**
   * Start with number i and empty string.
   * While number > 0: get remainder (i % 2), prepend to string, divide i by 2.
   * Continue until number becomes 0.

4. **Store and Continue:**
   * Add the generated binary string to result array.
   * Process next number until all n numbers are converted.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n * log n), where n is the input number. For each number i from 1 to n, we perform O(log i) operations to convert it to binary, resulting in O(n * log n) total operations.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for temporary variables during conversion (excluding the output array space).

## **🔧 Code (C)**

```c
char** generate(int n) {
    char** res = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        int num = i + 1, len = 0, temp = num;
        while (temp) { len++; temp /= 2; }
        res[i] = malloc((len + 1) * sizeof(char));
        res[i][len] = '\0';
        for (int j = len - 1; j >= 0; j--) {
            res[i][j] = '0' + (num & 1);
            num >>= 1;
        }
    }
    return res;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            string s = "";
            for (int x = i + 1; x; x /= 2) s = char('0' + x % 2) + s;
            res[i] = s;
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Queue-Based BFS Approach**

### 💡 Algorithm Steps:

1. Use queue to simulate BFS traversal of binary tree representation.
2. Start with "1" as root, for each element append "0" and "1" as children.
3. Process first n elements from queue to get binary numbers 1 to n.
4. This naturally generates binary numbers in ascending order.

```cpp
class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res;
        queue<string> q;
        q.push("1");
        for(int i = 0; i < n; i++) {
            string curr = q.front(); q.pop();
            res.push_back(curr);
            q.push(curr + "0");
            q.push(curr + "1");
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Process each number exactly once
* **Auxiliary Space:** 💾 O(n) - Queue storage for pending binary strings

### ✅ **Why This Approach?**

* Natural BFS tree traversal pattern for binary generation.
* Linear time complexity, fastest among all approaches.
* Elegant representation of binary number hierarchy.

## 📊 **3️⃣ Bit Manipulation Approach**

### 💡 Algorithm Steps:

1. Generate each binary number using bitwise operations.
2. For each number i, extract bits using AND operation with 1.
3. Right shift the number and repeat until all bits are processed.
4. Build binary string by collecting bit values from right to left.

```cpp
class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++) {
            string bin = "";
            int num = i;
            while(num) {
                bin = (num & 1 ? "1" : "0") + bin;
                num >>= 1;
            }
            res.push_back(bin);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * log n) - Converting each number takes O(log i) time
* **Auxiliary Space:** 💾 O(1) - Only temporary variables for conversion

### ✅ **Why This Approach?**

* Direct bit-level manipulation for optimal performance.
* No additional data structures needed beyond result storage.
* Educational value for understanding bitwise operations.

## 📊 **4️⃣ Built-in Library Approach**

### 💡 Algorithm Steps:

1. Use language-specific built-in functions for binary conversion.
2. Iterate through numbers 1 to n.
3. Apply built-in binary conversion function to each number.
4. Store results directly without manual conversion logic.

```cpp
class Solution {
public:
    vector<string> generateBinary(int n) {
        vector<string> res;
        for(int i = 1; i <= n; i++) {
            res.push_back(bitset<32>(i).to_string().substr(
                bitset<32>(i).to_string().find('1')));
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * log n) - Built-in conversion plus string processing
* **Auxiliary Space:** 💾 O(1) - Constant extra space per conversion

### ✅ **Why This Approach?**

* Leverages optimized library functions.
* Minimal code with maximum readability.
* Good for rapid prototyping and simple solutions.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔢 **Direct Conversion**           | 🟡 O(n * log n)        | 🟢 O(1)                 | 🚀 Simple and memory efficient   | 🐌 Slower for very large n           |
| 🔍 **Queue-Based BFS**            | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Fastest time complexity        | 💾 Extra queue space required        |
| 📊 **Bit Manipulation**           | 🟡 O(n * log n)        | 🟢 O(1)                 | 🎯 Educational bit operations     | 🧮 More complex bit logic             |
| 📚 **Built-in Library**           | 🟡 O(n * log n)        | 🟢 O(1)                 | 📖 Readable and concise          | 🔧 Platform/language dependent       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Maximum Speed Required**                         | 🥇 **Queue-Based BFS**               | ★★★★★                     |
| 🔧 **Memory Constrained Environment**                | 🥈 **Direct Conversion**             | ★★★★☆                     |
| 📖 **Learning Bit Operations**                       | 🥉 **Bit Manipulation**              | ★★★☆☆                     |
| 🎯 **Quick Implementation**                           | 🏅 **Built-in Library**              | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<String> generateBinary(int n) {
        ArrayList<String> res = new ArrayList<>(n);
        for (int i = 1; i <= n; i++) {
            StringBuilder sb = new StringBuilder();
            for (int x = i; x > 0; x /= 2) sb.append(x % 2);
            res.add(sb.reverse().toString());
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def generateBinary(self, n):
        return [bin(i)[2:] for i in range(1, n + 1)]
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
