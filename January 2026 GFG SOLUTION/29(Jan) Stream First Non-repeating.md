---
title: "🔤 Stream First Non-repeating | GFG Solution 🌊"
keywords🏷️: ["🔤 stream processing", "🔍 queue", "📊 frequency array", "📘 GFG", "🏁 competitive programming", "📚 DSA", "🌊 data stream"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Stream First Non-repeating problem: efficiently find the first non-repeating character at each position using queue-based stream processing. 🚀"
date: 📅 2025-01-29
---

# *29. Stream First Non-repeating*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1)

## **🧩 Problem Description**

Given a string `s` consisting of only lowercase alphabets, for each index `i` in the string (0 ≤ i < n), find the **first non-repeating character** in the prefix `s[0..i]`. If no such character exists, use `'#'`.

This problem simulates processing a stream of characters where at each step, we need to determine the first character that has appeared exactly once so far.

## **📘 Examples**

### Example 1

```cpp
Input: s = "aabc"
Output: "a#bb"
Explanation: 
At i=0 ("a"): First non-repeating character is 'a'.
At i=1 ("aa"): No non-repeating character, so '#'.
At i=2 ("aab"): First non-repeating character is 'b'.
At i=3 ("aabc"): Non-repeating characters are 'b' and 'c'; 'b' appeared first, so 'b'.
```

### Example 2

```cpp
Input: s = "bb"
Output: "b#"
Explanation: 
At i=0 ("b"): First non-repeating character is 'b'.
At i=1 ("bb"): No non-repeating character, so '#'.
```

## **🔒 Constraints**

* $1 \le \text{s.size()} \le 10^5$

## **✅ My Approach**

The optimal approach uses a **Queue with Frequency Array** to efficiently track non-repeating characters in the order they appear:

### **Queue-Based Stream Processing**

1. **Initialize Data Structures:**
   * Use a frequency array `freq[26]` to count occurrences of each character.
   * Maintain a queue to store characters in the order they first appear.
   * Build result string incrementally.

2. **Process Each Character:**
   * For each character `c` in the stream:
     - Increment its frequency in the array.
     - Add the character to the queue.

3. **Remove Repeating Characters:**
   * While the queue is not empty and the front character has frequency > 1:
     - Remove it from the queue (it's no longer a candidate).

4. **Determine First Non-Repeating:**
   * If queue is empty: append `'#'` to result.
   * Otherwise: append the front of the queue (first non-repeating character).

5. **Build Result:**
   * Repeat for all characters and return the final result string.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. Each character is added to the queue once and removed at most once, resulting in linear time complexity. The frequency update and queue operations are O(1) per character.
* **Expected Auxiliary Space Complexity:** O(26) = O(1), as we use a fixed-size frequency array of 26 elements for lowercase letters and a queue that stores at most 26 distinct characters at any time, resulting in constant auxiliary space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string firstNonRepeating(string &s) {
        int freq[26] = {0};
        queue<char> q;
        string res = "";
        for (char c : s) {
            freq[c - 'a']++;
            q.push(c);
            while (!q.empty() && freq[q.front() - 'a'] > 1) q.pop();
            res += q.empty() ? '#' : q.front();
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Doubly Linked List with Hash Map**

### 💡 Algorithm Steps:

1. Maintain a doubly linked list to track non-repeating characters in order.
2. Use a hash map to store frequency and node reference for each character.
3. For each character, update frequency and remove from list if frequency becomes 2.
4. The head of the list always points to the first non-repeating character.

```cpp
class Solution {
public:
    string firstNonRepeating(string &s) {
        list<char> dll;
        unordered_map<char, pair<int, list<char>::iterator>> mp;
        string res = "";
        for (char c : s) {
            if (mp.find(c) == mp.end()) {
                dll.push_back(c);
                mp[c] = {1, --dll.end()};
            } else if (mp[c].first == 1) {
                dll.erase(mp[c].second);
                mp[c].first = 2;
            }
            res += dll.empty() ? '#' : dll.front();
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each character processed once with O(1) operations
* **Auxiliary Space:** 💾 O(26) - Constant space for at most 26 lowercase letters

### ✅ **Why This Approach?**

* Efficient removal of repeating characters
* Maintains insertion order automatically
* Optimal for stream processing scenarios

## 📊 **3️⃣ Two-Pass Array Approach**

### 💡 Algorithm Steps:

1. First pass: count frequency of each character in the string.
2. Second pass: for each position, scan all 26 characters to find earliest non-repeating.
3. Track first occurrence position for each character during initial scan.
4. Build result by finding minimum position character with frequency 1 at each step.

```cpp
class Solution {
public:
    string firstNonRepeating(string &s) {
        int freq[26] = {0}, pos[26];
        fill(pos, pos + 26, -1);
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (pos[s[i] - 'a'] == -1) pos[s[i] - 'a'] = i;
            freq[s[i] - 'a']++;
            int mn = INT_MAX;
            char ch = '#';
            for (int j = 0; j < 26; j++) {
                if (freq[j] == 1 && pos[j] < mn) {
                    mn = pos[j];
                    ch = 'a' + j;
                }
            }
            res += ch;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(26*n) = O(n) - Constant factor of 26 for each position
* **Auxiliary Space:** 💾 O(1) - Fixed size arrays only

### ✅ **Why This Approach?**

* No dynamic data structures needed
* Simple array-based implementation
* Predictable memory usage pattern

## 📊 **4️⃣ Deque-Based Sliding Window**

### 💡 Algorithm Steps:

1. Use deque to maintain potential non-repeating characters in order.
2. Track frequency array to check repetition status.
3. For each new character, add to deque and update frequency.
4. Remove characters from front of deque if they have become repeating.

```cpp
class Solution {
public:
    string firstNonRepeating(string &s) {
        int cnt[26] = {0};
        deque<char> dq;
        string res = "";
        for (char c : s) {
            cnt[c - 'a']++;
            if (cnt[c - 'a'] == 1) dq.push_back(c);
            while (!dq.empty() && cnt[dq.front() - 'a'] > 1) dq.pop_front();
            res += dq.empty() ? '#' : dq.front();
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each character enters and leaves deque at most once
* **Auxiliary Space:** 💾 O(26) - Constant space for lowercase letters

### ✅ **Why This Approach?**

* Clean deque-based implementation
* Natural FIFO behavior for ordering
* Efficient front and back operations

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Queue-Based**                | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Simple and optimal             | 💡 Requires queue understanding      |
| 🔗 **Doubly Linked List**         | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Fast removal operations        | 🔧 More complex implementation       |
| 📊 **Two-Pass Array**             | 🟡 O(26*n)             | 🟢 O(1)                 | 📖 Easy to understand             | 🐌 Constant factor overhead          |
| 🪟 **Deque-Based**                | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Natural ordering               | 💾 Slightly more space than queue    |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                 | 🥇 **Queue-Based**                    | ★★★★★                     |
| 📖 **Simplicity priority**                        | 🥈 **Deque-Based**                    | ★★★★☆                     |
| 🔧 **No STL containers**                          | 🥉 **Two-Pass Array**                 | ★★★☆☆                     |
| 🎯 **Interview/Stream processing**                | 🏅 **Doubly Linked List**             | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public String firstNonRepeating(String s) {
        int[] freq = new int[26];
        Queue<Character> q = new LinkedList<>();
        StringBuilder res = new StringBuilder();
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
            q.add(c);
            while (!q.isEmpty() && freq[q.peek() - 'a'] > 1) q.poll();
            res.append(q.isEmpty() ? '#' : q.peek());
        }
        return res.toString();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def firstNonRepeating(self, s):
        freq = [0] * 26
        q = []
        res = []
        for c in s:
            freq[ord(c) - ord('a')] += 1
            q.append(c)
            while q and freq[ord(q[0]) - ord('a')] > 1:
                q.pop(0)
            res.append(q[0] if q else '#')
        return ''.join(res)
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
