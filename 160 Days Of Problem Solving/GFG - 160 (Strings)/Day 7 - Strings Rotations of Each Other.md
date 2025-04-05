---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Strings
---

# 🚀 _Day 7. Strings Rotations of Each Other_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/string-gfg-160/problem/check-if-strings-are-rotations-of-each-other-or-not-1587115620)

## 💡 **Problem Description:**

You are given two strings of equal lengths, `s1` and `s2`. The task is to check if `s2` is a rotated version of `s1`.  
Rotation means that the string `s2` can be formed by shifting the characters of `s1` cyclically.

**Note:** The characters in the strings are in lowercase.

## 🔍 **Example Walkthrough:**

**Input:**  
`s1 = "abcd", s2 = "cdab"`  
**Output:**  
`true`

**Explanation:**  
After two right rotations, `s1` becomes equal to `s2`.

**Input:**  
`s1 = "aab", s2 = "aba"`  
**Output:**  
`true`

**Explanation:**  
After one left rotation, `s1` becomes equal to `s2`.

**Input:**  
`s1 = "abcd", s2 = "acbd"`  
**Output:**  
`false`

**Explanation:**  
The strings are not rotations of each other.

### Constraints:

- $\(1 \leq \text{s1.size(), s2.size()} \leq 10^5\)$

## 🎯 **My Approach:**

1. **String Concatenation and Substring Check**:

   - The solution relies on the fact that a rotated version of `s1` will always be a substring of `s1 + s1`.
   - By concatenating `s1` with itself, all possible rotations of `s1` are included in the resulting string.
   - Then, we check if `s2` is a substring of the concatenated string.

2. **Edge Cases:**

   - If the lengths of `s1` and `s2` are different, they cannot be rotations.
   - Strings with only one character are trivially rotations if they are equal.

3. **Steps:**
   - Check if the lengths of `s1` and `s2` are equal.
   - Concatenate `s1` with itself to create a new string.
   - Use efficient substring search techniques like `strstr` or `KMP` to check if `s2` is present in the concatenated string.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** \(O(n)\), where \(n\) is the length of the string. The concatenation takes \(O(n)\), and the substring search also runs in \(O(n)\) using algorithms like KMP.
- **Expected Auxiliary Space Complexity:** \(O(n)\), as concatenating the string requires additional space for storing \(s1 + s1\).

## 📝 **Solution Code**

## Code (C)

```c
int areRotations(char* s1, char* s2) {
    if (strlen(s1) != strlen(s2)) return 0;
    char* temp = (char*)malloc(2 * strlen(s1) + 1);
    strcpy(temp, s1);
    strcat(temp, s1);
    int result = (strstr(temp, s2) != NULL);

    free(temp);
    return result;
}
```

## Code (Cpp)

```cpp
class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length()) return false;
        string temp = s1 + s1;
        return (temp.find(s2) != string::npos);
    }
};
```

## Code (Java)

```java
class Solution {
    public static boolean areRotations(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        String temp = s1 + s1;
        return kmpSearch(temp, s2);
    }

    private static boolean kmpSearch(String text, String pattern) {
        int[] lps = computeLPSArray(pattern);
        int i = 0, j = 0;

        while (i < text.length()) {
            if (text.charAt(i) == pattern.charAt(j)) {
                i++;
                j++;

                if (j == pattern.length()) {
                    return true;
                }
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return false;
    }
    private static int[] computeLPSArray(String pattern) {
        int[] lps = new int[pattern.length()];
        int len = 0, i = 1;

        while (i < pattern.length()) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
}
```

## Code (Python)

```python
class Solution:
    def areRotations(self, s1, s2):
        if len(s1) != len(s2):
            return False
        temp = s1 + s1
        return s2 in temp
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
