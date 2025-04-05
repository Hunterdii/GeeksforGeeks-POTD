# _24. Smallest Window in a String Containing All the Characters of Another String_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1)

### Problem Description

Given two strings, `s` and `p`, find the smallest window in the string `s` that contains all the characters (including duplicates) of the string `p`. If no such window exists, return "-1". In case there are multiple such windows of the same length, return the one with the least starting index.

**Example:**

Input:

```
s = "timetopractice", p = "toc"
```

Output:

```
toprac
```

Explanation: "toprac" is the smallest substring in which "toc" can be found.

Input:

```
s = "zoomlazapzo", p = "oza"
```

Output:

```
apzo
```

Explanation: "apzo" is the smallest substring in which "oza" can be found.

### My Approach

1. **Character Count Initialization:**

   - Create a frequency array `phash` to count characters in `p`.
   - Create a frequency array `shash` to count characters in the current window of `s`.

2. **Sliding Window Technique:**

   - Use two pointers (`left` and `right`) to represent the current window.
   - Expand the `right` pointer to include characters until all characters in `p` are covered.
   - Once all characters are included, attempt to contract the `left` pointer to find the smallest window while still covering all characters.

3. **Window Size Calculation:**

   - Track the minimum length of valid windows and their starting indices.
   - If a valid window is found, update the result with the smallest window's substring.

4. **Final Answer:**
   - Return the smallest window found, or "-1" if no valid window exists.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|s|), as we iterate through the string `s` at most twice (once for expanding the window and once for contracting it).
- **Expected Auxiliary Space Complexity:** O(n), where n is the length of `p`, due to the character frequency arrays used to track counts.

### Code (C++)

```cpp
class Solution {
public:
    string smallestWindow(string s, string p) {
        if (p.length() > s.length()) {
            return "-1";
        }
        vector<int> phash(256, 0);
        for (char ch : p) {
            phash[ch]++;
        }

        vector<int> shash(256, 0);
        int minLength = INT_MAX;
        int startIndex = -1;
        int count = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            shash[ch]++;
            if (phash[ch] != 0 && shash[ch] <= phash[ch]) {
                count++;
            }
            while (count == p.length()) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }
                char leftChar = s[left];
                shash[leftChar]--;
                if (phash[leftChar] != 0 && shash[leftChar] < phash[leftChar]) {
                    count--;
                }
                left++;
            }
        }
        if (startIndex == -1) {
            return "-1";
        }
        return s.substr(startIndex, minLength);
    }
};
```

### Code (Java)

```java
class Solution {
    public static String smallestWindow(String s, String p) {
        if (p.length() > s.length()) {
            return "-1";
        }

        int[] phash = new int[256];
        for (char ch : p.toCharArray()) {
            phash[ch]++;
        }

        int[] shash = new int[256];
        int minLength = Integer.MAX_VALUE;
        int startIndex = -1;
        int count = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            shash[ch]++;

            if (phash[ch] != 0 && shash[ch] <= phash[ch]) {
                count++;
            }

            while (count == p.length()) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }
                char leftChar = s.charAt(left);
                shash[leftChar]--;

                if (phash[leftChar] != 0 && shash[leftChar] < phash[leftChar]) {
                    count--;
                }
                left++;
            }
        }

        if (startIndex == -1) {
            return "-1";
        }
        return s.substring(startIndex, startIndex + minLength);
    }
}
```

### Code (Python)

```python
class Solution:
    def smallestWindow(self, s, p):
        if len(p) > len(s):
            return "-1"

        phash = [0] * 256
        for ch in p:
            phash[ord(ch)] += 1

        shash = [0] * 256
        minLength = float('inf')
        startIndex = -1
        count = 0
        left = 0

        for right in range(len(s)):
            ch = s[right]
            shash[ord(ch)] += 1

            if phash[ord(ch)] != 0 and shash[ord(ch)] <= phash[ord(ch)]:
                count += 1

            while count == len(p):
                if right - left + 1 < minLength:
                    minLength = right - left + 1
                    startIndex = left

                leftChar = s[left]
                shash[ord(leftChar)] -= 1

                if phash[ord(leftChar)] != 0 and shash[ord(leftChar)] < phash[ord(leftChar)]:
                    count -= 1

                left += 1

        if startIndex == -1:
            return "-1"
        return s[startIndex:startIndex + minLength]
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
