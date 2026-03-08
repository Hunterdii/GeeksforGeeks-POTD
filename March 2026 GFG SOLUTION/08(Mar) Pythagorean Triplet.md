---
title: "📐 Pythagorean Triplet | GFG Solution 🔍"
keywords🏷️: ["📐 pythagorean triplet", "🔢 array problem", "📦 hash set", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Pythagorean Triplet problem: determine whether three numbers in an array satisfy a² + b² = c² using hashing and mathematical observation. 🚀"
date: 📅 2025-03-08
---

# *08. Pythagorean Triplet*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1)

## **🧩 Problem Description**

Given an array `arr[]`, return `true` if there exists a triplet `(a, b, c)` from the array (where `a`, `b`, and `c` are at **different indexes**) that satisfies `a² + b² = c²`, otherwise return `false`.

## **📘 Examples**

### Example 1

```
Input: arr[] = [3, 2, 4, 6, 5]
Output: true
Explanation: a=3, b=4, and c=5 forms a Pythagorean triplet.
```

### Example 2

```
Input: arr[] = [3, 8, 5]
Output: false
Explanation: No such triplet possible.
```

### Example 3

```
Input: arr[] = [1, 1, 1]
Output: false
Explanation: 1² + 1² = 2 ≠ 1², so no valid triplet exists.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^3$

## **✅ My Approach**

The optimal approach uses a **Hash Set of Squares** for O(1) existence lookup combined with a double-loop over all pairs:

### **Hash Set of Squares**

1. **Precompute Squares:**
   * Insert the square of every element (`x * x`) into an `unordered_set`.
   * This enables O(1) average-case lookup for any target value.

2. **Enumerate All Pairs:**
   * Iterate over every pair `(i, j)` with `i < j`.
   * For each pair, compute the sum of squares: `arr[i]² + arr[j]²`.

3. **Check Existence:**
   * If the computed sum exists in the set, then there is some element `c` in the array such that `c² = arr[i]² + arr[j]²`, which means a valid Pythagorean triplet exists — return `true`.

4. **Return Result:**
   * If no such pair is found after checking all combinations, return `false`.

> **Key Insight:** By storing squares (not values), we directly check the Pythagorean condition `a² + b² = c²` without needing to compute square roots, avoiding any floating-point precision issues.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²), as we iterate over all pairs `(i, j)` with `i < j`, which results in approximately n*(n-1)/2 iterations, and each lookup in the hash set takes O(1) average time.
* **Expected Auxiliary Space Complexity:** O(n), as we store the square of each element in an unordered set of size at most n.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        unordered_set<int> s;
        for (int& x : arr) s.insert(x * x);
        for (int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j < arr.size(); ++j)
                if (s.count(arr[i]*arr[i] + arr[j]*arr[j])) return true;
        return false;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Frequency Array & Math (O(k²))**

### 💡 Algorithm Steps:

1. Build a `freq[1001]` array to store the count of each value present in `arr`.
2. Collect all unique values (where `freq[x] > 0`) into a sorted list `unique_nums`.
3. For every pair `(a, b)` from `unique_nums` (with `a ≤ b`):
   - Compute `c2 = a² + b²` and `c = round(√c2)`.
   - If `c ≤ 1000`, `c² == c2`, and `freq[c] > 0`:
     - Validate element distinctness using frequency counts (e.g., if `a == b`, need `freq[a] ≥ 2`; if all three are equal, need `freq[a] ≥ 3`).
     - Return `true` if valid.
4. Return `false` if no valid triplet is found.

```cpp
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int freq[1001] = {0};
        for (int x : arr) freq[x]++;
        vector<int> u;
        for (int i = 1; i <= 1000; ++i) if (freq[i]) u.push_back(i);
        int m = u.size();
        for (int i = 0; i < m; ++i) for (int j = i; j < m; ++j) {
            int a = u[i], b = u[j], c2 = a*a + b*b;
            int c = int(round(sqrt(c2)));
            if (c > 1000 || c*c != c2 || freq[c] == 0) continue;
            if (a == b && b == c && freq[a] >= 3) return true;
            if (a == b && freq[a] >= 2 && freq[c] >= 1 && c != a) return true;
            if (a == c && freq[a] >= 2 && freq[b] >= 1 && b != a) return true;
            if (b == c && freq[b] >= 2 && freq[a] >= 1 && a != b) return true;
            if (a != b && b != c && a != c) return true;
        }
        return false;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** O(k²), where k ≤ 1000 unique values, giving at most ~10⁶ operations in the worst case.
* **Auxiliary Space:** O(1), as only a fixed-size array of 1001 elements is used regardless of input size.

### ✅ **Why This Approach?**

* Exploits the small value constraint (`arr[i] ≤ 1000`) for bounded iteration.
* Uses O(1) extra space — no dynamic data structures needed.
* Handles duplicate element edge cases precisely through frequency validation.

## 🆚 **Comparison of Approaches**

| **Approach**              | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                                  | ⚠️ **Cons**                         |
| ------------------------- | ----------- | ------------ | -------------------------------------------- | ----------------------------------- |
| 🔢 Hash Set of Squares    | 🟡 O(n²)    | 🟡 O(n)      | Simple logic, clean code, O(1) lookups       | Extra hash memory, n can be large   |
| ⚙️ Frequency Array & Math | 🟢 O(k²)    | 🟢 O(1)      | Constant extra space, leverages constraints  | Only works when max(arr[i]) is small |

### ✅ **Best Choice by Scenario**

| **Scenario**                                        | **Recommended Approach**              |
| --------------------------------------------------- | ------------------------------------- |
| 🏆 General input, straightforward implementation    | 🥇 Hash Set of Squares               |
| 🔧 Optimized for small value ranges with O(1) space | 🥈 Frequency Array & Math            |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public boolean pythagoreanTriplet(int[] arr) {
        HashSet<Integer> squares = new HashSet<>();
        for (int x : arr) squares.add(x * x);
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (squares.contains(arr[i]*arr[i] + arr[j]*arr[j])) return true;
        return false;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def pythagoreanTriplet(self, arr):
        s = set(x * x for x in arr)
        n = len(arr)
        for i in range(n):
            for j in range(i + 1, n):
                if arr[i]**2 + arr[j]**2 in s:
                    return True
        return False
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
