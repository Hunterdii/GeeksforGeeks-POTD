---
title: "🔁 Exactly One Swap | GFG Solution 🎯"
keywords🏷️: ["🔁 one swap", "🧠 string permutations", "⚡ efficient counting", "📘 GFG", "📚 DSA", "💻 competitive programming"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Exactly One Swap problem: count distinct strings after one swap. Uses hashing & counting. 🚀"
date: 📅 2025-06-10
---
# *10. Exactly One Swap*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/exactly-one-swap--170637/1)

## **🧩 Problem Description**

Given a string **s**, return the **number of distinct strings** that can be obtained by **exactly one swap** of two different indices `(i < j)`.

## **📘 Examples**

### Example 1

```
Input: s = "geek"
Output: 6
Explanation: After one swap, there are 6 distinct strings possible:
"egek", "eegk", "geek", "geke", "gkee", and "keeg".
```

### Example 2

```
Input: s = "aaaa"
Output: 1
Explanation: Only one distinct string is possible after any swap ("aaaa").
```

## **🔒 Constraints**

* **$2 ≤ s.size() ≤ 10^4$**
* `s` consists of lowercase English letters.

## **✅ My Approach**

### 💡 Idea

1. Maintain a frequency array `m[26]` to track how many times each lowercase character has appeared.
2. For each character at index `i` in the string:

   * Add `i - m[s[i] - 'a']` to the result, which effectively counts how many earlier characters are *not equal* to the current character.
   * Increment the frequency of `s[i]`.
3. After the loop, check if any character appears more than once:

   * If so, increment the result once more to reflect the presence of a duplicate.

### ⚙️ Algorithm Steps:

1. Initialize `vector<int> m(26)` to store character counts.
2. Initialize `ans = 0`.
3. Loop through the string:

   * For each character `s[i]`, add `i - m[s[i]-'a']` to `ans`.
   * Increment `m[s[i]-'a']` by 1.
4. After the loop, scan the frequency array:

   * If any value > 1, increment `ans` by 1 and break.
5. Return `ans`.



## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), as we iterate through the string once while maintaining a constant-size frequency array.
* **Expected Auxiliary Space Complexity:** O(1), as we only use an array of fixed size 26.


## **🧑‍💻 Code (C++)**

```cpp
class Solution{
public:
    int countStrings(string &s){
        vector<int> m(26);
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            ans += i - m[s[i] - 'a'];
            ++m[s[i] - 'a'];
        }
        for(int x : m) if(x > 1){ ++ans; break; }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Hash Map + Count Difference Pairs**

### 💡 Algorithm Steps:

1. Maintain a fixed-size array `map[26]` to count the occurrences of each character.
2. For each character at position `i`, increment `ans` by `(i - map[s[i] - 'a'])`.
3. After the loop, check if any character appeared more than once. If so, increment `ans` once more.

```cpp
class Solution {
  public:
    int countStrings(string &s) {
        int map[26] = {}, ans = 0, n = s.size();
        for (int i = 0; i < n; ++i) {
            ans += i - map[s[i] - 'a'];
            map[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
            if (map[i] > 1) return ans + 1;
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Clean and constant-space method.
* Slightly more compact than vector + loop alternative.


## 📊 **3️⃣ Prefix Count + Single Pass**

### 💡 Algorithm Steps:

1. Initialize an integer array `a[26]` for prefix counts.
2. For each index `i`, add `(i - a[s[i] - 'a'])` to the answer and increment the character count.
3. After traversal, check if any character has frequency > 1 and add 1 if so.

```cpp
class Solution{
public:
    int countStrings(string &s){
        int n = s.size(), a[26] = {}, ans = 0;
        for(int i = 0; i < n; ++i){
            ans += i - a[s[i] - 'a'];
            ++a[s[i] - 'a'];
        }
        return ans + (any_of(a, a+26, [](int x){ return x > 1; }) ? 1 : 0);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Compact and expressive using STL utilities like `any_of`.
* Perfectly suited for interview or contest environments.


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                  | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**               | ⚠️ **Cons**                     |
| -------------------------------- | ---------------------- | ----------------------- | ------------------------ | ------------------------------- |
| ⚡ **Last‐Occurrence Vector**     | 🟢 O(n)                | 🟢 O(1)                 | Clean and fast           | Minor overhead with `vector`    |
| 🧠 **Hash Map Difference Pairs** | 🟢 O(n)                | 🟢 O(1)                 | Short, efficient         | Less expressive error checking  |
| 🚀 **Prefix Count + any\_of**    | 🟢 O(n)                | 🟢 O(1)                 | Shortest and STL-powered | Slightly less readable for some |

### 🏆 **Best Choice Recommendation**

| 🎯 Scenario                 | 🎖️ Recommended Approach        |
| --------------------------- | ------------------------------- |
| ⚡ Want fastest and cleanest | 🥇 Prefix Count + any\_of       |
| 🧵 Prefer simple loop logic | 🥈 Vector/Hash Difference Logic |


</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int countStrings(String s) {
        int[] m = new int[26];
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
            ans += i - m[s.charAt(i) - 'a'];
            ++m[s.charAt(i) - 'a'];
        }
        for (int x : m) if (x > 1) { ans++; break; }
        return ans;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def countStrings(self, s):
        m = [0]*26
        ans = 0
        for i, ch in enumerate(s):
            ans += i - m[ord(ch) - 97]
            m[ord(ch) - 97] += 1
        if any(x > 1 for x in m):
            ans += 1
        return ans
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
