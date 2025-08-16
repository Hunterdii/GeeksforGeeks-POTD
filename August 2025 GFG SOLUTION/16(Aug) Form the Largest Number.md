---
title: "🔢 Form the Largest Number | GFG Solution 🔍"
keywords🏷️: ["🔢 largest number", "🔍 custom comparator", "📍 sorting", "📈 string manipulation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Form the Largest Number problem: arrange integers to form the largest possible number using custom comparator sorting technique. 🚀"
date: 📅 2025-08-16
---

# *16. Form the Largest Number*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1)

## **🧩 Problem Description**

You are given an array `arr[]` of non-negative integers. Your task is to arrange them so that after concatenating all of them in order, it results in the **largest possible number**. Since the result may be very large, return it as a string.

The key insight is that we need to sort the numbers based on which arrangement produces a larger concatenated result, not by their numerical values.

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

The optimal approach uses **Custom Comparator Sorting** with **String Concatenation** to determine the correct order:

### **Custom Comparator + String Sorting**

1. **Convert to Strings:**
   * Convert all integers to strings for easy concatenation comparison.
   * This allows us to compare concatenated results directly.

2. **Custom Comparator Logic:**
   * For any two numbers `a` and `b`, compare `a+b` vs `b+a` (concatenation).
   * If `a+b > b+a`, then `a` should come before `b` in the final arrangement.
   * This ensures optimal ordering for maximum result.

3. **Sort with Comparator:**
   * Use the custom comparator to sort the string array.
   * The comparator function: `(x + y > y + x)` determines order.

4. **Handle Edge Case:**
   * If the largest number is "0", return "0" (handles arrays like [0, 0, 0]).
   * This prevents returning "000" instead of "0".

5. **Build Result:**
   * Concatenate all sorted strings to form the final result.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n × k), where n is the number of elements and k is the average number of digits per number. The sorting takes O(n log n) comparisons, and each comparison involves string operations that take O(k) time.
* **Expected Auxiliary Space Complexity:** O(n × k), where we store n strings each of average length k. The sorting algorithm may use additional O(log n) space for recursion stack.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string findLargest(vector<int>& arr) {
        vector<string> s;
        for (int x : arr) s.push_back(to_string(x));
        sort(s.begin(), s.end(), [](const string& x, const string& y) { 
            return x + y > y + x; 
        });
        if (s[0] == "0") return "0";
        string result;
        for (const string& str : s) result += str;
        return result;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Custom Comparator with Reserve**

### 💡 Algorithm Steps:

1. Pre-allocate string vector capacity to avoid reallocations.
2. Use custom comparator function to determine optimal concatenation order.
3. Build result string with pre-calculated capacity for better memory usage.
4. Handle edge case of all zeros efficiently.

```cpp
class Solution {
public:
    string findLargest(vector<int>& arr) {
        vector<string> nums;
        nums.reserve(arr.size());
        int totalLen = 0;
        for(int x : arr) {
            string s = to_string(x);
            nums.push_back(s);
            totalLen += s.length();
        }
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if(nums[0] == "0") return "0";
        string result;
        result.reserve(totalLen);
        for(const string& num : nums) result += num;
        
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n × k) - Where k is average digit length
* **Auxiliary Space:** 💾 O(n × k) - For string vector storage

### ✅ **Why This Approach?**

* Memory efficient with pre-allocation
* Reduces string reallocation overhead
* Better cache performance

## 📊 **3️⃣ In-Place Integer Sorting**

### 💡 Algorithm Steps:

1. Sort integers directly using custom comparison without string conversion.
2. Convert to strings only after sorting is complete.
3. Use integer arithmetic to compare concatenation results.
4. Build final result string in single pass.

```cpp
class Solution {
public:
    string findLargest(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            string sa = to_string(a), sb = to_string(b);
            return sa + sb > sb + sa;
        });
        if(arr[0] == 0) return "0";
        string result;
        for(int x : arr) result += to_string(x);
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n × k) - String creation during comparison
* **Auxiliary Space:** 💾 O(k) - Temporary strings in comparator

### ✅ **Why This Approach?**

* Works directly with original integer array
* Minimal additional space usage
* Clear separation of sorting and string building

## 📊 **4️⃣ Digit-Based Comparison**

### 💡 Algorithm Steps:

1. Use mathematical approach to compare numbers without string conversion.
2. Calculate concatenation result using digit manipulation.
3. Compare numbers by computing actual concatenated values.
4. Build result efficiently with minimal conversions.

```cpp
class Solution {
public:
    int digitCount(int n) {
        return n == 0 ? 1 : floor(log10(n)) + 1;
    }
    string findLargest(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b) {
            long long ab = a * pow(10, digitCount(b)) + b;
            long long ba = b * pow(10, digitCount(a)) + a;
            return ab > ba;
        });
        if(arr[0] == 0) return "0";
        string result;
        for(int x : arr) result += to_string(x);
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n × log k) - Where k is maximum number value
* **Auxiliary Space:** 💾 O(1) - No extra string storage during sort

### ✅ **Why This Approach?**

* Pure mathematical approach without string operations
* Potentially faster for large numbers
* Demonstrates algorithmic creativity

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Lambda Comparator + String Accumulation**           | 🟢 O(n log n × k)      | 🟢 O(n × k)             | 🚀 Clean and readable             | 🔧 Multiple string creations         |
| 🔍 **Reserved Memory**             | 🟢 O(n log n × k)      | 🟡 O(n × k)             | 📖 Memory optimized               | 💾 Complex memory management         |
| 📊 **Integer Sorting**             | 🟢 O(n log n × k)      | 🟢 O(k)                 | 🎯 Minimal space usage            | 🐌 String creation in comparator     |
| 🔄 **Digit Manipulation**          | 🟡 O(n log n × log k)  | 🟢 O(1)                 | ⭐ Pure mathematical              | 🔧 Complex overflow handling         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General purpose/Interview**                      | 🥇 **Lambda Comparator + String Accumulation**             | ★★★★★                     |
| 📖 **Memory constrained**                             | 🥈 **Integer Sorting**               | ★★★★☆                     |
| 🔧 **Large datasets**                                 | 🥉 **Reserved Memory**               | ★★★★☆                     |
| 🎯 **Academic/Research**                              | 🏅 **Digit Manipulation**            | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public String findLargest(int[] arr) {
        String[] s = new String[arr.length];
        for (int i = 0; i < arr.length; i++) s[i] = String.valueOf(arr[i]);
        Arrays.sort(s, (x, y) -> (x + y).compareTo(y + x) > 0 ? -1 : 1); 
        if (s[0].equals("0")) return "0";
        StringBuilder res = new StringBuilder();
        Arrays.stream(s).forEach(res::append);
        return res.toString();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findLargest(self, arr):
        s = sorted(map(str, arr), key=cmp_to_key(lambda x, y: -1 if x + y > y + x else 1))
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
