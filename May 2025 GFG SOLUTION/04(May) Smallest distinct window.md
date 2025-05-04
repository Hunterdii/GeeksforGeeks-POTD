# *4. Smallest Distinct Window*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1)


## **🧩 Problem Description**

Given a string `str`, find the length of the smallest window (substring) that contains **all the distinct characters** of the string **at least once**.


## **📘 Examples**

### **Example 1:**
#### **Input:**  
`str = "aabcbcdbca"`  
#### **Output:**  
`4`  
#### **Explanation:**  
The smallest window that contains all characters is `"dbca"`.


### **Example 2:**
#### **Input:**  
`str = "aaab"`  
#### **Output:**  
`2`  
#### **Explanation:**  
The smallest window that contains all distinct characters is `"ab"`.


### **Example 3:**
#### **Input:**  
`str = "geeksforgeeks"`  
#### **Output:**  
`8`  
#### **Explanation:**  
Substrings `"geeksfor"` and `"forgeeks"` are both valid.


## **🔒 Constraints**

- $1 \leq \text{str.length} \leq 10^5$
- `str` contains only lowercase English letters.

## **✅ My Approach**

### **Sliding Window + Frequency Table**

This is a classic sliding window problem where we dynamically maintain a window that tries to include all unique characters, and then shrink it from the left as much as possible while still retaining all distinct characters.

### **Algorithm Steps:**

1. Compute the number of **distinct characters** in the string `str`. Let this be `d`.
2. Use a sliding window from two pointers `i` and `j`.
3. Use a **frequency array of size 256** to count characters in the window.
4. Keep expanding the window by moving `j` and updating character counts.
5. When the current window includes **all `d` characters**, try to shrink it by moving `i`.
6. Keep track of the minimum window length during this process.


## **🧮 Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), as we process each character at most twice (once when expanding, once when shrinking).
- **Expected Auxiliary Space Complexity:** O(1), as we use a fixed-size frequency array of size 256 and a set for unique characters.

## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    int findSubString(string& s) {
        unordered_set<char> all(s.begin(), s.end());
        int n = s.size(), i = 0, j = 0, d = all.size(), c = 0, res = n;
        vector<int> freq(256, 0);
        while (j < n) {
            if (++freq[s[j++]] == 1) c++;
            while (c == d) {
                res = min(res, j - i);
                if (--freq[s[i++]] == 0) c--;
            }
        }
        return res;
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ HashMap instead of Frequency Array**

### **Algorithm Steps:**

1. Use a sliding window with two pointers.
2. Maintain a `HashMap<char, int>` instead of a fixed-size frequency array.
3. Track how many unique characters are currently in the window and shrink from left when all are found.

```cpp
class Solution {
  public:
    int findSubString(string& s) {
        unordered_set<char> all(s.begin(), s.end());
        unordered_map<char, int> freq;
        int d = all.size(), c = 0, i = 0, res = s.size();
        for (int j = 0; j < s.size(); ++j) {
            if (++freq[s[j]] == 1) c++;
            while (c == d) {
                res = min(res, j - i + 1);
                if (--freq[s[i++]] == 0) c--;
            }
        }
        return res;
    }
};
```

### ✅ **Why This Approach?**

* Flexible for Unicode/extended character sets.
* Easier to extend for character frequency-based problems.

#### 📝 **Complexity Analysis:**

* **Time:** O(n)
* **Auxiliary Space:** O(n)


## 📊 **3️⃣ Dynamic Character Indexing with Array Shrink**

### **Algorithm Steps:**

1. Store the last seen index of characters.
2. Maintain a window with a queue (or vector) of indices.
3. Use a `Set` to track which distinct characters are present.
4. When the current window has all characters, update result.

```cpp
class Solution {
  public:
    int findSubString(string& s) {
        unordered_set<char> all(s.begin(), s.end());
        unordered_map<char, int> last;
        int res = s.size(), count = 0;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            last[s[j]]++;
            while (last.size() == all.size()) {
                res = min(res, j - i + 1);
                if (--last[s[i]] == 0) last.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};
```

### ✅ **Why This Approach?**

* Another variation with similar runtime but more dynamic character tracking.

#### 📝 **Complexity Analysis:**

* **Time:** O(n)
* **Auxiliary Space:** O(n)


## 🆚 **Comparison of Approaches**

| **Approach**                          | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                                  | ⚠️ **Cons**                       |
| ------------------------------------- | ----------- | ------------- | ------------------------------------------- | --------------------------------- |
| Frequency Array Sliding Window        | 🟢 O(n)     | 🟢 O(1)       | Fastest, uses fixed array                   | ASCII-bound only                  |
| HashMap-Based Sliding Window           | 🟢 O(n)     | 🟢 O(n)       | Generalized for any char set                | Slightly more overhead than array |
| Last-Seen Map-Based Window              | 🟢 O(n)     | 🟢 O(n)       | Flexible, works well with character streams | More complex to implement         |


### ✅ **Best Choice?**

| **Scenario**                           | **Recommended Approach**          |
| -------------------------------------- | --------------------------------- |
| Fastest solution for standard ASCII strings      | 🥇 Frequency Array Sliding Window |
| Extended characters / multilingual string compatibility       | 🥈 HashMap-Based Sliding Window  |
| Handling character streams or online inputs dynamically | 🥉 Last-Seen Map-Based Window   |

</details>



## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int findSubString(String s) {
        Set<Character> all = new HashSet<>();
        for (char c : s.toCharArray()) all.add(c);
        int n = s.length(), i = 0, j = 0, d = all.size(), c = 0, res = n;
        int[] freq = new int[256];
        while (j < n) {
            if (++freq[s.charAt(j++)] == 1) c++;
            while (c == d) {
                res = Math.min(res, j - i);
                if (--freq[s.charAt(i++)] == 0) c--;
            }
        }
        return res;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def findSubString(self, s):
        d = len(set(s))
        i = j = c = 0
        res = len(s)
        freq = [0]*256
        while j < len(s):
            if freq[ord(s[j])] == 0:
                c += 1
            freq[ord(s[j])] += 1
            j += 1
            while c == d:
                res = min(res, j - i)
                freq[ord(s[i])] -= 1
                if freq[ord(s[i])] == 0:
                    c -= 1
                i += 1
        return res
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
