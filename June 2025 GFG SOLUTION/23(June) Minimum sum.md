---
title: "💰 Minimum Sum | GFG Solution 🔍"
keywords🏷️: ["💰 minimum sum",  "➕ string addition", "🧮 greedy algorithm","🔢 digit manipulation", "📈 counting sort", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Sum problem: form two numbers using all digits to minimize their sum using greedy approach and counting sort. 🚀"
date: 📅 2025-06-23
---

# *23. Minimum Sum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-sum4058/1)

## **🧩 Problem Description**

Given an array `arr[]` consisting of digits, your task is to form **two numbers** using all the digits such that their **sum is minimized**. Return the minimum possible sum as a string with **no leading zeroes**.

The key insight is to distribute the smallest digits optimally between two numbers to minimize their sum.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: "604"
Explanation: The minimum sum is formed by numbers 358 and 246.
358 + 246 = 604
```

### Example 2

```cpp
Input: arr[] = [5, 3, 0, 7, 4]
Output: "82"
Explanation: The minimum sum is formed by numbers 35 and 047.
35 + 47 = 82 (leading zero removed from 047)
```

### Example 3

```cpp
Input: arr[] = [9, 4]
Output: "13"
Explanation: The minimum sum is formed by numbers 9 and 4.
9 + 4 = 13
```

## **🔒 Constraints**

* $2 \le \text{arr.size()} \le 10^6$
* $0 \le \text{arr}[i] \le 9$

## **✅ My Approach**

The optimal approach uses **Counting Sort** followed by **Greedy Distribution** to minimize the sum:

### **Counting + Greedy Distribution**

1. **Count Digit Frequencies:**
   * Use a counting array to store frequency of each digit (0-9).
   * This naturally sorts the digits in O(n) time.

2. **Greedy Distribution Strategy:**
   * Distribute digits alternately between two strings `s1` and `s2`.
   * Start with the smallest available digit to ensure minimum sum.
   * Skip leading zeros to avoid invalid number formation.

3. **String Addition:**
   * Implement custom string addition to handle large numbers.
   * Add digits from right to left with carry propagation.
   * Remove trailing zeros from the result.

4. **Optimization Details:**
   * Use alternating distribution to balance the lengths of both numbers.
   * Smaller digits in higher positions contribute less to the final sum.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the array size. Counting takes O(n), distribution takes O(n), and string addition takes O(n) where n is the maximum length of formed numbers.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for counting array (size 10) and string operations (excluding the output strings).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string addString(string &s1, string &s2) {
        int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += (s1[i--] - '0');
            if (j >= 0) sum += (s2[j--] - '0');
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        while (!res.empty() && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
    string minSum(vector<int> &arr) {
        vector<int> count(10, 0);
        for (int num : arr) count[num]++;
        string s1 = "", s2 = "";
        bool firstNum = true;
        for (int digit = 0; digit < 10; digit++) {
            while (count[digit]--) {
                if (firstNum) {
                    if (!(s1.empty() && digit == 0)) s1.push_back(digit + '0');
                    firstNum = false;
                } else {
                    if (!(s2.empty() && digit == 0)) s2.push_back(digit + '0');
                    firstNum = true;
                }
            }
        }
        if (s1.empty()) s1 = "0";
        if (s2.empty()) s2 = "0";
        return addString(s1, s2);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized String Building**

### 💡 Algorithm Steps:

1. Use counting approach but build strings more efficiently.
2. Pre-calculate string lengths to avoid repeated allocations.
3. Use character arrays for faster string operations.

```cpp
class Solution {
public:
    string addString(string &a, string &b) {
        int i = a.size()-1, j = b.size()-1, c = 0;
        string r;
        r.reserve(max(a.size(), b.size()) + 1);
        while (i>=0||j>=0||c) {
            if (i>=0) c += a[i--]-'0';
            if (j>=0) c += b[j--]-'0';
            r.push_back(c%10+'0');
            c /= 10;
        }
        while (r.size()>1 && r.back()=='0') r.pop_back();
        reverse(r.begin(), r.end());
        return r;
    }
    string minSum(vector<int> &arr) {
        int count[10] = {0};
        for (int x : arr) count[x]++;
        string s1, s2;
        s1.reserve(arr.size()/2 + 1);
        s2.reserve(arr.size()/2 + 1);
        bool first = true;
        for (int d = 0; d < 10; d++) {
            while (count[d]--) {
                if (first) {
                    if (!s1.empty() || d) s1 += char('0'+d);
                    first = false;
                } else {
                    if (!s2.empty() || d) s2 += char('0'+d);
                    first = true;
                }
            }
        }
        if (s1.empty()) s1 = "0";
        if (s2.empty()) s2 = "0";
        return addString(s1, s2);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Pre-allocated strings reduce memory allocations.
* Faster character operations with direct array access.

## 📊 **3️⃣ Sort-Based Greedy Approach**

### 💡 Algorithm Steps:

1. Sort the input array in non-decreasing order.
2. Distribute digits alternately into two strings `s1` and `s2` (even indices → `s1`, odd indices → `s2`), skipping leading zeros.
3. Add the two resulting strings with the same `addString` routine.

```cpp
class Solution {
public:
    string addString(string &a, string &b) {
        int i = a.size()-1, j = b.size()-1, c = 0;
        string r;
        while (i>=0||j>=0||c) {
            if (i>=0) c += a[i--]-'0';
            if (j>=0) c += b[j--]-'0';
            r.push_back(c%10+'0');
            c /= 10;
        }
        while (r.size()>1 && r.back()=='0') r.pop_back();
        reverse(r.begin(), r.end());
        return r;
    }
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        string s1, s2;
        for (int i = 0; i < arr.size(); i++) {
            char d = char(arr[i] + '0');
            if (i % 2 == 0) { if (!s1.empty() || d!='0') s1 += d; }
            else          { if (!s2.empty() || d!='0') s2 += d; }
        }
        if (s1.empty()) s1="0";
        if (s2.empty()) s2="0";
        return addString(s1, s2);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Very simple to implement with standard STL sort.
* Works well when n is moderate.

## 📊 **4️⃣ Priority Queue (Min-Heap) Approach**

### 💡 Algorithm Steps:

1. Push all digits into a min-heap (priority_queue with `greater<int>`).
2. Pop one by one, alternately appending to `s1` and `s2`, skipping leading zeros.
3. Sum with `addString`.

```cpp
class Solution {
public:
    string addString(string &a, string &b) {
        int i = a.size()-1, j = b.size()-1, c = 0;
        string r;
        while (i>=0||j>=0||c) {
            if (i>=0) c += a[i--]-'0';
            if (j>=0) c += b[j--]-'0';
            r.push_back(c%10+'0');
            c /= 10;
        }
        while (r.size()>1 && r.back()=='0') r.pop_back();
        reverse(r.begin(), r.end());
        return r;
    }
    string minSum(vector<int> &arr) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        string s1, s2;
        bool turn = true;
        while (!pq.empty()) {
            char d = char(pq.top()+'0');
            pq.pop();
            if (turn) {
                if (!s1.empty() || d!='0') s1 += d;
            } else {
                if (!s2.empty() || d!='0') s2 += d;
            }
            turn = !turn;
        }
        if (s1.empty()) s1="0";
        if (s2.empty()) s2="0";
        return addString(s1, s2);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Avoids explicit sort call; uses heap to stream smallest digits first.
* Useful if you want to interleave extraction with processing.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                          | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | ----------------------------------- | ------------------------------------- |
| 🔍 **Count-Array Greedy**          | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Fastest, constant extra space     | 🧮 Requires digit frequency logic    |
| 🚀 **Optimized String Building**   | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Memory-efficient, fast strings   | 🧮 More complex implementation       |
| 🔄 **Sort-Based Greedy**           | 🟡 O(n log n)          | 🔸 O(n)                 | 🔧 Very simple, uses STL sort      | ⏱️ Sorting overhead                  |
| 📊 **Priority Queue**              | 🟡 O(n log n)          | 🔸 O(n)                 | 🏎️ Stream processing capability     | 💾 Heap overhead                     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                           | 🎖️ **Recommended Approach**      | 🔥 **Performance Rating** |
| ---------------------------------------- | -------------------------------- | ------------------------- |
| ⚡ Maximum performance, large datasets    | 🥇 **Count-Array Greedy**        | ★★★★★                     |
| 💾 Memory-critical applications          | 🥈 **Optimized String Building** | ★★★★★                     |
| 🔧 Quick implementation, simplicity       | 🥉 **Sort-Based Greedy**         | ★★★★☆                     |
| 🏎️ Stream processing, partial data       | 🏅 **Priority Queue**            | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    String minSum(int[] arr) {
        int[] count = new int[10];
        for (int num : arr) count[num]++;
        StringBuilder s1 = new StringBuilder(), s2 = new StringBuilder();
        boolean firstNum = true;
        for (int d = 0; d < 10; d++) {
            while (count[d]-- > 0) {
                if (firstNum) {
                    if (!(s1.length() == 0 && d == 0)) s1.append(d);
                    firstNum = false;
                } else {
                    if (!(s2.length() == 0 && d == 0)) s2.append(d);
                    firstNum = true;
                }
            }
        }
        if (s1.length() == 0) s1.append('0');
        if (s2.length() == 0) s2.append('0');
        return addString(s1.toString(), s2.toString());
    }
    String addString(String s1, String s2) {
        int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
        StringBuilder res = new StringBuilder();
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += s1.charAt(i--) - '0';
            if (j >= 0) sum += s2.charAt(j--) - '0';
            res.append(sum % 10);
            carry = sum / 10;
        }
        while (res.length() > 1 && res.charAt(res.length() - 1) == '0')
            res.deleteCharAt(res.length() - 1);
        return res.reverse().toString();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minSum(self, arr):
        count = [0]*10
        for x in arr: count[x]+=1
        s1 = s2 = ""
        first = True
        for d in range(10):
            while count[d]>0:
                if first:
                    if s1 or d!=0: s1 += str(d)
                    first = False
                else:
                    if s2 or d!=0: s2 += str(d)
                    first = True
                count[d] -= 1
        if not s1: s1="0"
        if not s2: s2="0"
        return self.addString(s1, s2)
    def addString(self, s1, s2):
        i, j, carry, res = len(s1)-1, len(s2)-1, 0, []
        while i>=0 or j>=0 or carry>0:
            if i>=0: carry += int(s1[i]); i-=1
            if j>=0: carry += int(s2[j]); j-=1
            res.append(str(carry%10))
            carry//=10
        while len(res)>1 and res[-1]=='0': res.pop()
        return ''.join(reversed(res))
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
