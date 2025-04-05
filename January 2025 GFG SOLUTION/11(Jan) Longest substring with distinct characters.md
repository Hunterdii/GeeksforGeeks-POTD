# _11. Longest Substring with Distinct Characters_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1)

## Problem Description

Given a string `s`, your task is to find the length of the longest substring with all distinct characters.

## Examples:

**Input:**  
`s = "geeksforgeeks"`  
**Output:**  
`7`  
**Explanation:**  
"eksforg" is the longest substring with all distinct characters.

**Input:**  
`s = "aaa"`  
**Output:**  
`1`  
**Explanation:**  
The longest substring with all distinct characters is "a".

**Input:**  
`s = "abcdefabcbb"`  
**Output:**  
`6`  
**Explanation:**  
The longest substring with all distinct characters is "abcdef", which has a length of 6.

### Constraints:

- $`1 <= s.size() <= 3 * 10^4`$
- All characters are lowercase English alphabets.

## My Approach

1. **Sliding Window Technique**:  
   To find the longest substring with distinct characters, we maintain a sliding window that contains only unique characters. If a duplicate character is found, we slide the window forward to remove it.

2. **Steps**:

   - Use an array `lastSeen` to store the last seen index of each character.
   - Traverse the string using a pointer (`end`) to extend the window.
   - Use a second pointer (`start`) to mark the beginning of the valid window. If a duplicate is found, move `start` to ensure all characters in the window are unique.
   - Keep track of the maximum length of the substring during the traversal.

3. **Edge Cases**:
   - Empty or very small strings.
   - Strings with all identical characters.
   - Strings with all unique characters.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the length of the string. Each character is processed at most twice (once when extending the window and once when shrinking it).
- **Expected Auxiliary Space Complexity:** O(1), as the space used for the `lastSeen` array is constant (128 elements for ASCII).

## Code (C++)

```cpp
class Solution {
public:
    int longestUniqueSubstr(string &s) {
        int lastSeen[128] = {}, maxLength = 0, start = 0;
        for (int end = 0; end < s.size(); ++end) {
            start = max(start, lastSeen[s[end]]);
            lastSeen[s[end]] = end + 1;
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
    }
};
```

## Code (Java)

```java
class Solution {
    public int longestUniqueSubstr(String s) {
        int[] lastSeen = new int[128];
        int maxLength = 0, start = 0;
        for (int end = 0; end < s.length(); end++) {
            start = Math.max(start, lastSeen[s.charAt(end)]);
            lastSeen[s.charAt(end)] = end + 1;
            maxLength = Math.max(maxLength, end - start + 1);
        }
        return maxLength;
    }
}
```

## Code (Python)

```python
class Solution:
    def longestUniqueSubstr(self, s):
        last_seen = [-1] * 128
        max_length = 0
        start = 0

        for end, char in enumerate(s):
            start = max(start, last_seen[ord(char)] + 1)
            last_seen[ord(char)] = end
            max_length = max(max_length, end - start + 1)

        return max_length
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
