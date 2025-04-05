## 26. K-Pangrams

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/k-pangrams0909/1)

### Problem Description

Given a string `str` and an integer `k`, return `true` if the string can be changed into a pangram after at most `k` operations, else return `false`.

A single operation consists of swapping an existing alphabetic character with any other alphabetic character.

**Example:**

Input:

```
str = "the quick brown fox jumps over the lazy dog", k = 0
```

Output:

```
true
```

Explanation: The sentence contains all 26 characters and is already a pangram.

Input:

```
str = "aaaaaaaaaaaaaaaaaaaaaaaaaa", k = 25
```

Output:

```
true
```

Explanation: The string contains 26 instances of 'a'. Since only 25 operations are allowed, we can keep 1 instance and change all others to make `str` a pangram.

### My Approach

1. **Frequency Calculation:**

   - Create a frequency map to count occurrences of each alphabetic character in the string.

2. **Check for Pangram:**

   - Calculate the total number of characters in the string (`cnt`).
   - Count the number of unique alphabetic characters (`uniq`).
   - Check if the string has at least 26 characters (`cnt >= 26`) and if the number of missing unique characters to form a pangram is less than or equal to `k` (`(26 - uniq) <= k`).

3. **Return:**
   - Return `true` if the conditions for forming a pangram with at most `k` operations are met, otherwise return `false`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the length of the string, as we iterate through the string to build the frequency map.
- **Expected Auxiliary Space Complexity:** O(1), as the size of the frequency map is constant (only alphabetic characters are considered).

### Code (C++)

```cpp
class Solution {
public:
    bool kPangram(string str, int k) {
        unordered_map<char, int> frequency;
        for (char c : str) {
            if (isalpha(c)) {
                frequency[c]++;
            }
        }

        int cnt = 0;
        int uniq = 0;

        for (const auto& pair : frequency) {
            if (isalpha(pair.first)) {
                cnt += pair.second;
                uniq++;
            }
        }

        return cnt >= 26 && (26 - uniq) <= k;
    }
};
```

### Code (Java)

```java
class Solution {
    boolean kPangram(String str, int k) {
        Map<Character, Integer> frequency = new HashMap<>();
        for (char c : str.toCharArray()) {
            if (Character.isAlphabetic(c)) {
                frequency.put(c, frequency.getOrDefault(c, 0) + 1);
            }
        }

        int cnt = 0;
        int uniq = 0;
        for (Map.Entry<Character, Integer> entry : frequency.entrySet()) {
            if (Character.isAlphabetic(entry.getKey())) {
                cnt += entry.getValue();
                uniq++;
            }
        }

        return cnt >= 26 && (26 - uniq) <= k;
    }
}
```

### Code (Python)

```python
class Solution:
    def kPangram(self, string, k):
        frequency = {}
        for c in string:
            if c.isalpha():
                frequency[c] = frequency.get(c, 0) + 1

        cnt = 0
        uniq = 0
        for key, value in frequency.items():
            if key.isalpha():
                cnt += value
                uniq += 1

        return cnt >= 26 and (26 - uniq) <= k
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
