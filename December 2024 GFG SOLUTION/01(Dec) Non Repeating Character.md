# _01. Non-Repeating Character_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/non-repeating-character-1587115620/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Continued ✨</h2>
</div>

- As part of the **LeetCode Problem of the Day (POTD)** series, here is the solution for **December 1, 2024**. 🎯
- My latest solution is now live:  
  **[1346. Check If N and Its Double Exist](https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/1346.Check%20If%20N%20and%20Its%20Double%20Exist.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/1346.Check%20If%20N%20and%20Its%20Double%20Exist.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/December%202024%20Leetcode%20Solution/1346.Check%20If%20N%20and%20Its%20Double%20Exist.md">
  <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
</div>

<br/>

## Problem Description

Given a string `s` consisting of lowercase Latin letters, return the first non-repeating character in `s`. If there is no non-repeating character, return `'$'`.

**Note:** When you return `'$'`, the driver code will output `-1`.

### Examples:

**Input:**  
`s = "geeksforgeeks"`  
**Output:**  
`'f'`

**Explanation:**  
In the given string, `'f'` is the first character in the string which does not repeat.

**Input:**  
`s = "racecar"`  
**Output:**  
`'e'`

**Explanation:**  
In the given string, `'e'` is the only character in the string which does not repeat.

**Input:**  
`s = "aabbccc"`  
**Output:**  
`-1`

**Explanation:**  
All the characters in the given string are repeating.

### Constraints:

- $`1 <= s.size() <= 10^5`$

## My Approach

1. **Frequency Array Method**:

   - Since the input consists only of lowercase Latin letters, a frequency array of size `26` is sufficient to count occurrences of each character.
   - Traverse the string once to update the frequency of each character in the array.
   - Traverse the string a second time to identify the first character with a frequency of `1`.

2. **Steps:**
   - Initialize a frequency array `freq[26]` and set all elements to `0`.
   - For each character in the string, increment its corresponding frequency in the array.
   - Iterate through the string again, checking for the first character with a frequency of `1`.
   - If no such character exists, return `'$'`.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the size of the string. The algorithm requires two linear passes through the string.
- **Expected Auxiliary Space Complexity:** O(1), as the frequency array uses a fixed amount of additional space (`26` elements).

## Code (C)

```c
char nonRepeatingChar(char s[]) {
    int freq[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }
    return '$';
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    char nonRepeatingChar(string &s) {
        int freq[26] = {0};
        for (char c : s) {
            freq[c - 'a']++;
        }
        for (char c : s) {
            if (freq[c - 'a'] == 1) {
                return c;
            }
        }
        return '$';
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>
  
```cpp
class Solution {
public:
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }
        for (char c : s) {
            if (freq[c] == 1) {
                return c;
            }
        }
        return '$';
    }

};

````
</details>

## Code (Java)

```java
class Solution {
    static char nonRepeatingChar(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }
        for (char c : s.toCharArray()) {
            if (freq[c - 'a'] == 1) {
                return c;
            }
        }
        return '$';
    }
}
````

## Code (Python)

```python
class Solution:
    def nonRepeatingChar(self, s):
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord('a')] += 1
        for c in s:
            if freq[ord(c) - ord('a')] == 1:
                return c
        return '$'
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
