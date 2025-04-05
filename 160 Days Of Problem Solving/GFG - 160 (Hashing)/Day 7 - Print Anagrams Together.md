---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Hash
  - Strings
---

# 🚀 _Day 7. Print Anagrams Together_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/print-anagrams-together)

## 💡 **Problem Description:**

You are given an array `arr[]` of strings. Your task is to group the anagrams together and return all such groups. The groups must be created in order of their appearance in the original array.

Note: The final output will be in lexicographic order.

## 🔍 **Example Walkthrough:**

**Input:**  
`arr[] = ["act", "god", "cat", "dog", "tac"]`  
**Output:**  
`[["act", "cat", "tac"], ["god", "dog"]]`  
Explanation:  
There are 2 groups of anagrams:

- "god", "dog" make group 1
- "act", "cat", "tac" make group 2

**Input:**  
`arr[] = ["no", "on", "is"]`  
**Output:**  
`[["is"], ["no", "on"]]`  
Explanation:  
There are 2 groups of anagrams:

- "is" makes group 1
- "no", "on" make group 2

**Input:**  
`arr[] = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]`  
**Output:**  
`[["abc", "cab", "bac"], ["listen", "silent", "enlist"], ["rat", "tar", "art"]]`  
Explanation:

- Group 1: "abc", "bac", and "cab" are anagrams.
- Group 2: "listen", "silent", and "enlist" are anagrams.
- Group 3: "rat", "tar", and "art" are anagrams.

### Constraints:

- `1 <= arr.size() <= 100`
- `1 <= arr[i].size() <= 10`

## 🎯 **My Approach:**

1. **Sorting-Based Grouping**:

   - An anagram is a word formed by rearranging the letters of another word. Hence, for grouping anagrams, we can sort each string and use the sorted version as the key in a map (unordered_map).
   - The key idea is that anagrams, when sorted, will produce the same string. For example, "act", "cat", and "tac" will all produce "act" when sorted.

2. **Steps:**
   - Create a hashmap (unordered_map) where the key is the sorted string and the value is a list of anagrams corresponding to that key.
   - For each string in the array, sort it, and add the original string to the list of the corresponding key in the map.
   - After processing all strings, return the values of the hashmap as a list of anagram groups.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:**  
  O(n _ m _ log(m)), where `n` is the number of strings and `m` is the maximum length of any string. Sorting each string takes O(m \* log(m)), and we do this for all `n` strings.

- **Expected Auxiliary Space Complexity:**  
  O(n \* m), where `n` is the number of strings and `m` is the maximum length of any string. The space is used for the hashmap and the output list.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> umap;

        for (const string& s : arr) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            umap[sorted_s].push_back(s);
        }

        vector<vector<string>> result;
        for (auto it = umap.begin(); it != umap.end(); ++it)
            result.push_back(move(it->second));

        return result;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

## Approach Using Sorting and Hash Map

```cpp
class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> umap;
        for (string s : arr) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            umap[sorted_s].push_back(s);
        }
        vector<vector<string>> result;
        for (auto it : umap)
            result.push_back(it.second);
        return result;
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    public ArrayList<ArrayList<String>> anagrams(String[] arr) {
        Map<String, ArrayList<String>> umap = new HashMap<>();
        for (String s : arr) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String sorted_s = new String(chars);
            umap.computeIfAbsent(sorted_s, k -> new ArrayList<>()).add(s);
        }

        ArrayList<ArrayList<String>> result = new ArrayList<>(umap.values());
        return result;
    }
}
```

## Code (Python)

```python
from collections import defaultdict

class Solution:
    def anagrams(self, arr):
        umap = defaultdict(list)
        for s in arr:
            sorted_s = ''.join(sorted(s))
            umap[sorted_s].append(s)

        return list(umap.values())
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
