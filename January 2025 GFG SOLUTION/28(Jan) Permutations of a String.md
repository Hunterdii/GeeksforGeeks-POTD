# _28. Permutations of a String_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1)

## Problem Description

You are given a string `s`, which may contain duplicate characters. Your task is to generate and return an array of all unique permutations of the string. You can return the permutations in any order.

## Examples:

### **Example 1**

**Input:**  
`s = "ABC"`  
**Output:**  
`["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]`  
**Explanation:**  
Given string `ABC` has 6 unique permutations.

### **Example 2**

**Input:**  
`s = "ABSG"`  
**Output:**  
`["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]`  
**Explanation:**  
Given string `ABSG` has 24 unique permutations.

### **Example 3**

**Input:**  
`s = "AAA"`  
**Output:**  
`["AAA"]`  
**Explanation:**  
No other unique permutations can be formed as all the characters are the same.

### **Constraints**

- `1 <= s.size() <= 9`
- `s` contains only uppercase English alphabets.

## My Approach

1. **Lexicographical Permutation Method:**

   - Sort the characters of the string to generate permutations in lexicographical order.
   - Use a loop to find the **next lexicographical permutation** until all permutations are found.

2. **DFS with Backtracking:**

   - Use backtracking to generate all permutations.
   - Avoid duplicates by skipping over elements that are the same and ensuring a sorted order before starting.

3. **Key Steps:**
   - Sort the string or array of characters to start with the smallest permutation.
   - Generate all permutations using a **DFS approach** or iterate through lexicographical order using the `next_permutation()` function.
   - Ensure uniqueness by checking and avoiding duplicate entries in the result.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(N! \* N), where N is the length of the string. Generating all permutations takes **O(N!)**, and sorting or creating permutations takes **O(N)**.
- **Expected Auxiliary Space Complexity:** O(N), for storing intermediate permutations in recursion or iteration.

## **Approach : Using STL `next_permutation()`**

## Code (C++)

```cpp
class Solution {
public:
    vector<string> findPermutation(string s) {
        vector<string> res;
        sort(s.begin(), s.end());
        do {
            res.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        return res;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

**Approach 2: Using DFS with Backtracking**

- **Expected Time Complexity:** O(N! \* N), where N is the length of the string. Backtracking generates all unique permutations.
- **Expected Auxiliary Space Complexity:** O(N), for recursion stack and used flags.

## **Approach 2: DFS with Backtracking**

## Code (C++)

```cpp
class Solution {
public:
    void dfs(string &s, vector<bool> &used, string &curr, vector<string> &res) {
        if (curr.size() == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            // Skip used characters or duplicates
            if (used[i] || (i > 0 && s[i] == s[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            curr += s[i];
            dfs(s, used, curr, res); // Recursive call
            used[i] = false; // Backtrack
            curr.pop_back();
        }
    }

    vector<string> findPermutation(string s) {
        vector<string> res;
        sort(s.begin(), s.end()); // Step 1: Sort to handle duplicates
        vector<bool> used(s.size(), false);
        string curr;
        dfs(s, used, curr, res); // Start backtracking
        return res;
    }
};
```

## Code (Python)

```python3
from itertools import permutations

class Solution:
    def findPermutation(self, s):
        return sorted(set(["".join(p) for p in permutations(s)]))  # Unique permutations
```

</details>

## Code (Java)

```java
class Solution {
    public ArrayList<String> findPermutation(String s) {
        ArrayList<String> res = new ArrayList<>();
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        do res.add(new String(chars));
        while (next(chars));
        return res;
    }

    private boolean next(char[] c) {
        int i = c.length - 2, j = c.length - 1;
        while (i >= 0 && c[i] >= c[i + 1]) i--;
        if (i < 0) return false;
        while (c[j] <= c[i]) j--;
        char t = c[i]; c[i] = c[j]; c[j] = t;
        for (int l = i + 1, r = c.length - 1; l < r; l++, r--) {
            t = c[l]; c[l] = c[r]; c[r] = t;
        }
        return true;
    }
}
```

## Code (Python)

```python
class Solution:
    def findPermutation(self, s):
        s, res = ''.join(sorted(s)), []
        while s:
            res.append(s)
            s = self.next(s)
        return res

    def next(self, s):
        s = list(s)
        i = len(s) - 2
        while i >= 0 and s[i] >= s[i + 1]: i -= 1
        if i < 0: return None
        j = len(s) - 1
        while s[j] <= s[i]: j -= 1
        s[i], s[j] = s[j], s[i]
        return ''.join(s[:i + 1] + s[i + 1:][::-1])
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
