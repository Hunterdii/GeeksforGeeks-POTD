# _30. Anagram_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/anagram-1587115620/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Started ✨</h2>
</div>

- As promised in the poll, I’ve started solving and uploading **LeetCode Problem of the Day (POTD)** solutions! 🎯
- My solution for today's problem is now live:  
  **[2097. Valid Arrangement of Pairs](https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2097.Valid%20Arrangement%20of%20Pairs.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2097.Valid%20Arrangement%20of%20Pairs.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/2097.Valid%20Arrangement%20of%20Pairs.md">
  <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
</div>

<br/>

## Problem Description

You are given two strings `s1` and `s2`, both consisting of lowercase alphabets. Your task is to check whether the two strings are anagrams of each other. Two strings are anagrams if they contain the same characters, but the order of characters may differ.

### Examples:

**Input:**  
`s1 = "geeks", s2 = "kseeg"`  
**Output:**  
`true`

**Explanation:**  
Both strings contain the same characters with the same frequency, so they are anagrams.

**Input:**  
`s1 = "allergy", s2 = "allergic"`  
**Output:**  
`false`

**Explanation:**  
The characters in both strings are not the same, so they are not anagrams.

**Input:**  
`s1 = "g", s2 = "g"`  
**Output:**  
`true`

**Explanation:**  
Both strings contain the same character, so they are anagrams.

### Constraints:

- `1 ≤ s1.size(), s2.size() ≤ 10^5`

## My Approach

1. **Character Counting**:

   - Since anagrams contain the same characters with the same frequency, we can compare the frequency of characters in both strings.
   - To do this efficiently, we use an array of size 26 (for the 26 lowercase letters) to count the frequency of characters in both strings.
   - The idea is to increment the count for characters in `s1` and decrement the count for characters in `s2`. If the counts match after processing both strings, the strings are anagrams.

2. **Steps:**
   - Check if both strings have the same length. If not, they cannot be anagrams.
   - Iterate through the strings and update the frequency count for each character.
   - After processing both strings, check if all the counts are zero. If they are, return `true`; otherwise, return `false`.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the length of the strings. We traverse both strings once, performing constant-time operations for each character.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the frequency count array (size 26).

## Code (C)

```c
bool areAnagrams(char s1[], char s2[]) {
    if (strlen(s1) != strlen(s2)) return false;

    int counts[26] = {0};
    for (int i = 0; i < strlen(s1); i++) {
        counts[s1[i] - 'a']++;
        counts[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (counts[i] != 0) return false;
    }

    return true;
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    bool areAnagrams(string& s1, string& s2) {
        if (s1.length() != s2.length()) return false;
        int counts[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            counts[s1[i] - 'a']++;
            counts[s2[i] - 'a']--;
        }
        for (int count : counts) {
            if (count != 0) return false;
        }
        return true;
    }
};
```

## Code (Java)

```java
class Solution {
    public static boolean areAnagrams(String s1, String s2) {
        if (s1.length() != s2.length()) return false;

        int[] counts = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            counts[s1.charAt(i) - 'a']++;
            counts[s2.charAt(i) - 'a']--;
        }

        for (int count : counts) {
            if (count != 0) return false;
        }

        return true;
    }
}
```

## Code (Python)

```python
class Solution:
    def areAnagrams(self, s1, s2):
        if len(s1) != len(s2):
            return False

        counts = [0] * 26
        for i in range(len(s1)):
            counts[ord(s1[i]) - ord('a')] += 1
            counts[ord(s2[i]) - ord('a')] -= 1

        for count in counts:
            if count != 0:
                return False

        return True
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
