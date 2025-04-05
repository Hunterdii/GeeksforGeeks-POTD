---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Greedy
---

# 🚀 _Day 5. Maximize partitions in a String_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/maximize-partitions-in-a-string)

## 💡 **Problem Description:**

Given a string **s** consisting of lowercase English alphabets, your task is to determine the **maximum number of substrings** that can be formed by partitioning **s** such that **no two substrings share common characters**.

> Note: Sorry for uploading late, my exam is going on.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```plaintext
s = "acbbcc"
```

#### **Output:**

```plaintext
2
```

#### **Explanation:**

Possible partitions:

- `"a"` and `"cbbcc"`
- `"ac"` and `"bbcc"`

The maximum possible substrings with **no common characters** are **2**.

### **Example 2:**

#### **Input:**

```plaintext
s = "ababcbacadefegdehijhklij"
```

#### **Output:**

```plaintext
3
```

#### **Explanation:**

Partitioning at index **8** and **15** produces three substrings:

- `"ababcbaca"`
- `"defegde"`
- `"hijhklij"`

Each of these substrings contains **unique** characters within them.

### **Example 3:**

#### **Input:**

```plaintext
s = "aaa"
```

#### **Output:**

```plaintext
1
```

#### **Explanation:**

Since the string consists of the **same** character, no partition can be performed.  
The entire string itself is a **single valid substring**.

### **Constraints:**

- $1 \leq |s| \leq 10^5$
- $'a' \leq s[i] \leq 'z'$

## 🎯 **My Approach:**

### **Greedy Approach Using Last Occurrence**

1. **Find the last occurrence of each character** and store it.
2. **Traverse the string** and maintain an interval that expands based on character occurrences.
3. When the **current index reaches the last occurrence of the characters in that segment**, count it as a partition.

### **Algorithm Steps:**

1. **Precompute the last occurrence** of each character in **O(N)** time.
2. **Traverse the string**, maintaining an `end` pointer that marks the furthest last occurrence of encountered characters.
3. If the **current index** reaches `end`, increment the partition count.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), as we scan the string twice (once to find last occurrences, once for partitioning).
- **Expected Auxiliary Space Complexity:** O(1), since we use a **fixed-size** array (26 elements for lowercase letters).

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
public:
    int maxPartitions(string &s) {
        int ans = 0, end = 0;
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) ans++;
        }
        return ans;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Interval Merging Approach**

#### **Algorithm Steps:**

1. **Preprocess:** For each character, record its first and last occurrence in the string.
2. **Interval Creation:** Create intervals \([first, last]\) for each character that appears.
3. **Merge Intervals:** Sort these intervals by their starting index and merge overlapping intervals. Each merged interval represents a valid partition.

```cpp
class Solution {
public:
    int maxPartitions(string &s) {
        vector<pair<int, int>> intervals;
        vector<int> first(26, s.size()), last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            first[idx] = min(first[idx], i);
            last[idx] = i;
        }
        for (int i = 0; i < 26; i++) {
            if (last[i] != -1)
                intervals.push_back({first[i], last[i]});
        }
        sort(intervals.begin(), intervals.end());
        int count = 0, start = intervals[0].first, end = intervals[0].second;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first > end) {
                count++;
                start = intervals[i].first;
                end = intervals[i].second;
            } else {
                end = max(end, intervals[i].second);
            }
        }
        return count + 1;
    }
};
```

#### 📝 **Complexity Analysis:**

- ✅ **Time Complexity:** O(N + K log K)
  - O(N) for scanning the string (where N is the string length)
  - O(K log K) for sorting intervals (with at most K = 26 intervals)
- ✅ **Space Complexity:** O(K) – Uses extra space for intervals (K is constant, at most 26).

🔹 **Pros:** Visualizes problem as merging intervals.  
🔹 **Cons:** Requires sorting, making it slightly slower than the greedy approach.

#### ✅ **Why This Approach?**

This method visualizes the problem as merging intervals, making it easier to understand the segmentation of the string, especially for conceptual clarity.

## 🔁 **3️⃣ First & Last Occurrence Approach**

#### **Algorithm Steps:**

1. **Record Occurrences:** Use two arrays to store the first and last occurrences of each character.
2. **Greedy Partitioning:** Traverse the string and update the partition end using the last occurrence of each character. When the current index equals the partition end, a partition is identified.

```cpp
class Solution {
public:
    int maxPartitions(string &s) {
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1)
                first[idx] = i;
            last[idx] = i;
        }
        int count = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
                count++;
        }
        return count;
    }
};
```

#### 📝 **Complexity Analysis:**

- ✅ **Time Complexity:** O(N) – Single pass for recording occurrences and one pass for partitioning.
- ✅ **Space Complexity:** O(1) – Fixed-size arrays (26 elements each) are used.

🔹 **Pros:** Fastest approach, minimal space usage.  
🔹 **Cons:** Needs careful index management.

#### ✅ **Why This Approach?**

It leverages the concept of last occurrence effectively to decide partitions with minimal extra space and linear runtime.

### 🆚 **Comparison of Approaches**

| **Approach**                     | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                                       | ⚠️ **Cons**                             |
| -------------------------------- | ---------------------- | ----------------------- | ------------------------------------------------- | --------------------------------------- |
| Greedy (Optimized)               | 🟢 O(N)                | 🟢 O(1)                 | Best performance, straightforward implementation. | Requires careful management of indices. |
| Interval Merging Approach        | 🟢 O(N + K log K)      | 🟢 O(K)                 | Intuitive by visualizing partitions as intervals. | Slightly more code due to sorting.      |
| First & Last Occurrence Approach | 🟢 O(N)                | 🟢 O(1)                 | Simple and efficient with minimal extra space.    | Similar to the greedy approach.         |

✅ **Best Choice?**

- **For best performance:** Use the **Greedy Approach (O(N), O(1))**.
- **For conceptual clarity:** Use the **Interval Merging Approach**.
- **For a structured solution:** Use **First & Last Occurrence Approach**.

</details>

## **Code (Java)**

```java
class Solution {
    public int maxPartitions(String s) {
        int[] last = new int[26];
        for (int i = 0; i < s.length(); i++)
            last[s.charAt(i) - 'a'] = i;
        int count = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = Math.max(end, last[s.charAt(i) - 'a']);
            if (i == end)
                count++;
        }
        return count;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def maxPartitions(self, s: str) -> int:
        last = {c: i for i, c in enumerate(s)}
        count = end = 0
        for i, c in enumerate(s):
            end = max(end, last[c])
            if i == end:
                count += 1
        return count
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
