### 31. Longest Common Prefix in an Array

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1)

### Problem Description

Given an array of strings `arr`, return the longest common prefix among all strings present in the array. If there's no common prefix, return "-1".

**Examples:**

Input:

```
arr = ["geeksforgeeks", "geeks", "geek", "geezer"]
```

Output:

```
gee
```

Explanation:
"gee" is the longest common prefix among all the given strings.

### My Approach

1. **Edge Case Handling:**

- Check if the input array `arr` is empty. If it is, return "-1".

2. **Initialization:**

- Initialize the prefix as the first string in the array: `prefix = arr[0]`.

3. **Prefix Comparison:**

- Iterate over each string in the array starting from the second string.
- For each string, reduce the prefix by removing the last character until the current string starts with the prefix.

4. **Check Prefix:**

- If the prefix becomes empty during the comparison, return "-1".

5. **Return:**

- Return the final prefix if it is not empty, otherwise return "-1".

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* min(|arri|)), where `n` is the number of strings and `|arri|` is the length of the shortest string in the array. This is because for each string, we may need to check up to the length of the shortest string in the worst case.
- **Expected Auxiliary Space Complexity:** O(1), as we are only using a constant amount of additional space for the prefix variable.

### Code (C++)

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        if (arr.empty()) return "-1";
        int n = arr.size();
        string prefix = arr[0];

        for (int i = 1; i < n; ++i) {
            while (arr[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "-1";
            }
        }
        return prefix.empty() ? "-1" : prefix;
    }
};
```

### Code (Java)

```java
class Solution {
    public String longestCommonPrefix(String arr[]) {
        if (arr.length == 0) return "-1";
        String prefix = arr[0];

        for (int i = 1; i < arr.length; ++i) {
            while (arr[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
                if (prefix.isEmpty()) return "-1";
            }
        }
        return prefix.isEmpty() ? "-1" : prefix;
    }
}
```

### Code (Python)

```python
class Solution:
    def longestCommonPrefix(self, arr):
        if not arr:
            return "-1"
        prefix = arr[0]

        for i in range(1, len(arr)):
            while not arr[i].startswith(prefix):
                prefix = prefix[:-1]
                if not prefix:
                    return "-1"
        return prefix if prefix else "-1"
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
