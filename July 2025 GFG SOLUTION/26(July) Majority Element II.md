---
title: "🗳️ Majority Element II | GFG Solution 🔍"
keywords🏷️: ["🔢 majority element", "🗳️ voting algorithm", "📈 boyer moore", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Majority Element II problem: find all elements appearing more than n/3 times using Boyer-Moore Majority Vote algorithm. 🚀"
date: 📅 2025-07-26
---

# *26. Majority Element II*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/majority-vote/1)

## **🧩 Problem Description**

You are given an array of integer `arr[]` where each number represents a vote to a candidate. Return the candidates that have votes **greater than one-third of the total votes**. If there's not a majority vote, return an empty array.

**Note:** The answer should be returned in an increasing format.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 occurs 4 times and 6 occurs 5 times. Both appear more than n/3 = 11/3 = 3.67 times.
Hence, both 5 and 6 are majority elements.
```

### Example 2

```cpp
Input: arr[] = [1, 2, 3, 4, 5]
Output: []
Explanation: The total number of votes are 5. No candidate occurs more than floor(5/3) = 1 time.
Since we need elements appearing more than n/3 times, no element qualifies.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses the **Boyer-Moore Majority Vote Algorithm** extended for finding elements appearing more than n/3 times:

### **Boyer-Moore Voting Algorithm (Extended)**

1. **Key Insight:**
   * At most 2 elements can appear more than n/3 times in an array.
   * We maintain two candidates and their counts during the voting phase.

2. **Phase 1 - Candidate Selection:**
   * Initialize two candidates `a` and `b` with different values, and their counts `ca` and `cb`.
   * For each element `x`:
     * If `x` equals candidate `a`, increment `ca`
     * Else if `x` equals candidate `b`, increment `cb`
     * Else if `ca` is 0, set `a = x` and `ca = 1`
     * Else if `cb` is 0, set `b = x` and `cb = 1`
     * Else decrement both `ca` and `cb` (voting against both candidates)

3. **Phase 2 - Verification:**
   * Reset counts and verify if the selected candidates actually appear more than n/3 times.
   * Count actual occurrences of candidates `a` and `b` in the array.

4. **Result Formation:**
   * Add candidates to result if their count > n/3.
   * Sort the result for increasing order output.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We make two passes through the array - one for candidate selection and one for verification.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for storing two candidates and their counts.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size(), a = 0, b = 1, ca = 0, cb = 0;
        for (int x : arr) {
            if (x == a) ca++;
            else if (x == b) cb++;
            else if (!ca) a = x, ca = 1;
            else if (!cb) b = x, cb = 1;
            else ca--, cb--;
        }
        ca = cb = 0;
        for (int x : arr) {
            if (x == a) ca++;
            else if (x == b) cb++;
        }
        vector<int> res;
        if (ca > n / 3) res.push_back(a);
        if (cb > n / 3 && a != b) res.push_back(b);
        sort(res.begin(), res.end());
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Hash Map Frequency Count**

### 💡 Algorithm Steps:

1. Count frequency of each element using unordered_map
2. Filter elements with count > n/3
3. Sort result for consistent output
4. Single pass solution with O(n) space

```cpp
class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res;
        for (auto& p : freq) {
            if (p.second > n / 3) res.push_back(p.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + k log k) where k is unique elements
* **Auxiliary Space:** 💾 O(n) - for hash map

### ✅ **Why This Approach?**

* Simple to understand and implement
* Works well for small datasets
* Good when memory is not a constraint

## 📊 **3️⃣ Sorting Based Approach**

### 💡 Algorithm Steps:

1. Sort the array to group identical elements
2. Count consecutive occurrences
3. Check if count exceeds n/3 threshold
4. Collect qualifying elements

```cpp
class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> res;
        for (int i = 0; i < n; ) {
            int cnt = 1, val = arr[i];
            while (++i < n && arr[i] == val) cnt++;
            if (cnt > n / 3) res.push_back(val);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - for sorting
* **Auxiliary Space:** 💾 O(1) - constant extra space

### ✅ **Why This Approach?**

* Space optimal solution
* Modifies input array (saves space)
* Good for memory-constrained environments

## 📊 **4️⃣ Divide and Conquer Approach**

### 💡 Algorithm Steps:

1. Recursively divide array into two halves
2. Find majority candidates from both halves
3. Merge and validate candidates
4. Return elements exceeding n/3 threshold

```cpp
class Solution {
private:
    vector<int> merge(vector<int>& arr, vector<int> left, vector<int> right, int l, int r) {
        vector<int> candidates;
        for (int x : left) candidates.push_back(x);
        for (int x : right) candidates.push_back(x);  
        vector<int> res;
        for (int cand : candidates) {
            int cnt = 0;
            for (int i = l; i <= r; i++) {
                if (arr[i] == cand) cnt++;
            }
            if (cnt > (r - l + 1) / 3) {
                if (find(res.begin(), res.end(), cand) == res.end()) {
                    res.push_back(cand);
                }
            }
        }
        return res;
    }
    vector<int> majorityRec(vector<int>& arr, int l, int r) {
        if (l == r) return {arr[l]};
        int mid = l + (r - l) / 2;
        vector<int> left = majorityRec(arr, l, mid);
        vector<int> right = majorityRec(arr, mid + 1, r);
        return merge(arr, left, right, l, r);
    }
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        vector<int> candidates = majorityRec(arr, 0, n - 1);
        vector<int> res;
        for (int cand : candidates) {
            int cnt = 0;
            for (int x : arr) {
                if (x == cand) cnt++;
            }
            if (cnt > n / 3) res.push_back(cand);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - divide and conquer
* **Auxiliary Space:** 💾 O(log n) - recursion stack

### ✅ **Why This Approach?**

* Demonstrates divide and conquer paradigm
* Good for parallel processing
* Educational value for algorithm design

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Boyer-Moore Voting**         | 🟢 O(n)               | 🟢 O(1)                 | 🚀 Optimal time and space        | 🔧 Complex logic to understand       |
| 🗂️ **Hash Map Frequency**         | 🟡 O(n + k log k)     | 🔴 O(n)                 | 🔧 Simple and intuitive           | 💾 High space complexity             |
| 📊 **Sorting Based**              | 🔴 O(n log n)         | 🟢 O(1)                 | ⚡ Space optimal                  | ⏰ Slower due to sorting             |
| 🌀 **Divide and Conquer**         | 🔴 O(n log n)         | 🟡 O(log n)             | 🎓 Educational value              | 🔄 Complex implementation             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Optimal performance required**                | 🥇 **Boyer-Moore Voting**            | ★★★★★                     |
| 📊 **Simple implementation needed**               | 🥈 **Hash Map Frequency**            | ★★★★☆                     |
| 🎯 **Memory constrained environment**             | 🥉 **Sorting Based**                 | ★★★☆☆                     |
| 🚀 **Learning algorithm design**                  | 🏅 **Divide and Conquer**            | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> findMajority(int[] arr) {
        int n = arr.length, a = 0, b = 1, ca = 0, cb = 0;
        for (int x : arr) {
            if (x == a) ca++;
            else if (x == b) cb++;
            else if (ca == 0) { a = x; ca = 1; }
            else if (cb == 0) { b = x; cb = 1; }
            else { ca--; cb--; }
        }
        ca = cb = 0;
        for (int x : arr) {
            if (x == a) ca++;
            else if (x == b) cb++;
        }
        ArrayList<Integer> res = new ArrayList<>();
        if (ca > n / 3) res.add(a);
        if (cb > n / 3 && a != b) res.add(b);
        Collections.sort(res);
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findMajority(self, arr):
        n, a, b, ca, cb = len(arr), 0, 1, 0, 0
        for x in arr:
            if x == a: ca += 1
            elif x == b: cb += 1
            elif ca == 0: a, ca = x, 1
            elif cb == 0: b, cb = x, 1
            else: ca, cb = ca - 1, cb - 1
        ca = cb = 0
        for x in arr:
            if x == a: ca += 1
            elif x == b: cb += 1
        res = []
        if ca > n // 3: res.append(a)
        if cb > n // 3 and a != b: res.append(b)
        return sorted(res)
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

