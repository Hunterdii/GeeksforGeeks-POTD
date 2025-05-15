# *15. Substrings with Same First and Last Characters*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/substrings-with-similar-first-and-last-characters3644/1)


## **🧩 Problem Description**

Given a string `s` consisting of lowercase English letters, count all substrings in which the first and last characters are the same.

A substring is a contiguous sequence of characters within the string. Single-character substrings are always valid.


## **📘 Examples**

### **Example 1:**

#### **Input:**

`s = "abcab"`

#### **Output:**

`7`

#### **Explanation:**

The valid substrings are `"a"`, `"b"`, `"c"`, `"a"`, `"b"`, `"abca"`, and `"bcab"`.

### **Example 2:**

#### **Input:**

`s = "aba"`

#### **Output:**

`4`

#### **Explanation:**

The valid substrings are `"a"`, `"b"`, `"a"`, and `"aba"`.


## **🔒 Constraints**

* \$1 \leq |s| \leq 10^4\$
* `s` contains only lowercase English alphabets (`'a'` to `'z'`)


## **✅ My Approach**

### **Frequency Count using Combinatorics**

A substring starts and ends with the same character if we consider all positions where a character appears.
For a character appearing `f` times, the number of such substrings is:

$$
\text{count} = \frac{f \times (f + 1)}{2}
$$

This accounts for:

* `f` single-character substrings
* `fC2` substrings where both ends are the same character

We use a frequency array of size 256 (or 26 if lowercase only) to count characters, then sum this formula over all counts.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n), as we scan the string once to count character frequencies and once more to sum results.
* **Expected Auxiliary Space Complexity:** O(1), as we use a fixed-size array of length 256 regardless of input size.


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    int countSubstring(string &s) {
        long long cnt[256]={}, ans=0;
        for(char c:s) cnt[(unsigned char)c]++;
        for(int i=0;i<256;i++)
            ans += cnt[i]*(cnt[i]+1)/2;
        return (int)ans;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>



## 📊 **2️⃣ HashMap-Based Frequency Count**

### **💡 Algorithm Steps:**

1. Initialize a `unordered_map<char, int>`.
2. Traverse the string `s`, incrementing count for each character.
3. For each `(char, freq)` in the map, add `freq * (freq + 1) / 2` to result.

```cpp
class Solution {
  public:
    int countSubstring(string &s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        long long ans = 0;
        for (auto &[ch, f] : freq) ans += 1LL * f * (f + 1) / 2;
        return (int)ans;
    }
};
```

### ✅ Why This Approach?

* Reduces unnecessary storage compared to fixed-size array (good for limited character sets).

#### 📝 Complexity Analysis:

* **Time:** O(n)
* **Auxiliary Space:** O(k), where `k` is the number of unique characters


## 📊 **3️⃣ Using C++ STL `map` or `array<int, 26>` (If Input is Lowercase Only)**

### **💡 Algorithm Steps:**

1. Initialize an array of size 26 for lowercase letter counts.
2. Traverse string and increment count.
3. Compute total using same formula.

```cpp
class Solution {
  public:
    int countSubstring(string &s) {
        array<int, 26> cnt = {};
        for (char c : s) cnt[c - 'a']++;
        long long ans = 0;
        for (int f : cnt) ans += 1LL * f * (f + 1) / 2;
        return (int)ans;
    }
};
```

### ✅ Why This Approach?

* Fast and space-efficient when you know the character set (a–z).
* Constant-size array is faster than unordered\_map.

#### 📝 Complexity Analysis:

* **Time:** O(n)
* **Auxiliary Space:** O(1) (since 26 is constant)


### 🆚 **Comparison of Approaches**

| **Approach**           | ⏱️ Time | 💾 Space | ✅ Pros                             | ⚠️ Cons                         |
| ---------------------- | ------- | -------- | ---------------------------------- | ------------------------------- |
| Frequency array (main) | 🟢 O(n)  | 🟢 O(Σ=256) | Fastest, simplest                  | Wastes space for small charsets |
| `unordered_map` count  | 🟢 O(n)  | 🔸 O(k)     | Efficient for limited unique chars | Slightly longer code            |
| `array<int, 26>`       | 🟢 O(n)  | 🔸 O(1)     | Best for lowercase-only strings    | Only works with known charsets  |


### ✅ Best Choice by Scenario

| **Scenario**                      | **Recommended Approach**      |
| --------------------------------- | ----------------------------- |
| Performance-critical, any charset | 🥇 Fixed-size array of 256     |
| Lowercase input (a–z)             | 🥈 26-letter frequency array         |
| Space-aware and clean design      | 🥉 HashMap |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int countSubstring(String s) {
        int[] cnt = new int[256];
        long ans = 0;
        for (char c : s.toCharArray()) cnt[c]++;
        for (int x : cnt) ans += (long)x * (x + 1) / 2;
        return (int)ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countSubstring(self, s):
        from collections import Counter
        return sum(v * (v + 1) // 2 for v in Counter(s).values())
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
