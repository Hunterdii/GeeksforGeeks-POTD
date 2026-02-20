---
title: "🔢 Form the Largest Number | GFG Solution 🎯"
keywords🏷️: ["🔢 largest number", "🔍 custom sorting", "📊 string comparison", "📈 greedy algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Form the Largest Number: arrange numbers to create the largest possible concatenated value using custom comparator sorting. 🚀"
date: 📅 2025-02-20
---

# *20. Form the Largest Number*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1)

## **🧩 Problem Description**

Given an array of integers `arr[]` representing non-negative integers, arrange them so that after concatenating all of them in order, it results in the **largest possible number**. Since the result may be very large, return it as a string.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [3, 30, 34, 5, 9]
Output: "9534330"
Explanation: Given numbers are [3, 30, 34, 5, 9], the arrangement [9, 5, 34, 3, 30] 
gives the largest value.
```

### Example 2

```cpp
Input: arr[] = [54, 546, 548, 60]
Output: "6054854654"
Explanation: Given numbers are [54, 546, 548, 60], the arrangement [60, 548, 546, 54] 
gives the largest value.
```

### Example 3

```cpp
Input: arr[] = [3, 4, 6, 5, 9]
Output: "96543"
Explanation: Given numbers are [3, 4, 6, 5, 9], the arrangement [9, 6, 5, 4, 3] 
gives the largest value.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The solution uses a **Custom Comparator with Greedy Sorting**:

### **Custom Comparator Sorting**

1. **Key Insight:**
   * To determine if number `a` should come before `b`, compare the concatenations: `ab` vs `ba`.
   * If `ab > ba` lexicographically, then `a` should come before `b`.
   * Example: For 3 and 30, compare "330" vs "303" → "330" > "303", so 3 comes before 30.

2. **Convert to Strings:**
   * Convert all integers to strings for easy concatenation and comparison.

3. **Sort with Custom Comparator:**
   * Sort the string array using a comparator that compares `s1+s2` with `s2+s1`.
   * Sort in descending order to get larger combinations first.

4. **Handle Edge Case:**
   * If the first element after sorting is "0", all elements are zeros.
   * Return "0" instead of "000...".

5. **Concatenate Result:**
   * Join all sorted strings to form the final largest number.

**Why This Works:** The custom comparator ensures transitivity. If `a` should come before `b` and `b` before `c`, then `a` comes before `c`, making the sorting valid and optimal.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. The dominant operation is sorting with a custom comparator, which takes O(n log n) comparisons. Each comparison involves string concatenation and comparison, which takes O(k) where k is the average number of digits, but this is constant for the given constraints (max 5 digits).
* **Expected Auxiliary Space Complexity:** O(n), as we create an array of n strings to store the string representations of the numbers. The concatenation result also uses O(n*k) space where k is the average length of numbers.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string findLargest(vector<int>& arr) {
        vector<string> s;
        for (int x : arr) s.push_back(to_string(x));
        sort(s.begin(), s.end(), [](string& a, string& b) { return a + b > b + a; });
        if (s[0] == "0") return "0";
        string res;
        for (auto& x : s) res += x;
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Static Comparator Function**

### 💡 Algorithm Steps:

1. Define a static comparison function outside the class or as a static member.
2. Convert all integers to strings for comparison.
3. Sort using the custom comparator that compares concatenated results.
4. Handle the all-zeros edge case by checking the first element.

```cpp
class Solution {
public:
    static bool myCompare(string& s1, string& s2) { 
        return (s1 + s2) > (s2 + s1); 
    }
    
    string findLargest(vector<int>& arr) {
        vector<string> numbers;
        for (int ele : arr) numbers.push_back(to_string(ele));
        sort(numbers.begin(), numbers.end(), myCompare);
        if (numbers[0] == "0") return "0";
        string res = "";
        for (string& num : numbers) res.append(num);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting dominates
* **Auxiliary Space:** 💾 O(n) - String array storage

### ✅ **Why This Approach?**

* Clear separation with named comparator function
* Easier to debug and test comparator independently
* More readable for those unfamiliar with lambdas

## 📊 **3️⃣ In-Place String Building**

### 💡 Algorithm Steps:

1. Convert numbers to strings and store in vector.
2. Use custom comparator for sorting.
3. Build result string incrementally without separate loop.
4. Optimize by using string reserve for better performance.

```cpp
class Solution {
public:
    string findLargest(vector<int>& arr) {
        vector<string> strs;
        strs.reserve(arr.size());
        for (int x : arr) strs.push_back(to_string(x));
        sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if (strs[0] == "0") return "0";
        string result;
        for (const string& s : strs) result += s;
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sort operation
* **Auxiliary Space:** 💾 O(n) - Vector of strings

### ✅ **Why This Approach?**

* Uses const references for better performance
* Reserve optimization reduces reallocations
* Professional code style

## 📊 **4️⃣ Direct Integer Comparison (Alternative Logic)**

### 💡 Algorithm Steps:

1. Keep numbers as integers initially.
2. Convert to strings only during comparison.
3. Sort using inline comparator with on-the-fly conversion.
4. Build final string from sorted integers.

```cpp
class Solution {
public:
    string findLargest(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            string sa = to_string(a), sb = to_string(b);
            return sa + sb > sb + sa;
        });
        if (arr[0] == 0) return "0";
        string ans;
        for (int x : arr) ans += to_string(x);
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting with string operations
* **Auxiliary Space:** 💾 O(1) - Sorts in-place (excluding output)

### ✅ **Why This Approach?**

* Minimal auxiliary space before final result
* Sorts original array in-place
* Reduces initial memory allocation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Lambda Comparator**          | 🟢 O(n log n)          | 🟡 O(n)                 | 🚀 Concise, modern C++            | 🔧 Lambda overhead (minimal)         |
| 🔄 **Static Comparator**          | 🟢 O(n log n)          | 🟡 O(n)                 | 📖 Clear, debuggable              | 🔧 More verbose                      |
| 📊 **In-Place Building**          | 🟢 O(n log n)          | 🟡 O(n)                 | ⚡ Optimized with reserve          | 🔧 Similar to main approach          |
| 🔢 **Direct Integer Sort**        | 🟢 O(n log n)          | 🟢 O(1)*               | 💾 Space efficient                | 🔧 Repeated to_string calls          |

*Excluding output string

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive programming**                        | 🥇 **Lambda Comparator**             | ★★★★★                     |
| 📖 **Interview clarity**                              | 🥈 **Static Comparator**             | ★★★★★                     |
| 💾 **Memory constrained**                             | 🥉 **Direct Integer Sort**           | ★★★★☆                     |
| 🔧 **Production code**                                | 🏅 **In-Place Building**             | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public String findLargest(int[] arr) {
        String[] s = new String[arr.length];
        for (int i = 0; i < arr.length; i++) s[i] = String.valueOf(arr[i]);
        Arrays.sort(s, (a, b) -> (b + a).compareTo(a + b));
        if (s[0].equals("0")) return "0";
        StringBuilder res = new StringBuilder();
        for (String x : s) res.append(x);
        return res.toString();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findLargest(self, arr):
        from functools import cmp_to_key
        s = list(map(str, arr))
        s.sort(key=cmp_to_key(lambda a, b: -1 if a + b > b + a else 1))
        return '0' if s[0] == '0' else ''.join(s)
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
