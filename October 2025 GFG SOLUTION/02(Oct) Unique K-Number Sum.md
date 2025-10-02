---
title: "🔢 Unique K-Number Sum | GFG Solution 🔍"  
keywords🏷️: ["🔢 combination sum", "🔍 backtracking", "📍 recursion", "📈 DFS", "📘 GFG", "🏁 competitive programming", "📚 DSA"]  
author: "✍️ Het Patel (Hunterdii)"  
description: "✅ GFG solution to the Unique K-Number Sum problem: find all valid combinations of k distinct numbers from 1-9 that sum to n using backtracking and DFS techniques. 🚀"  
date: 📅 2025-10-02  
---

# *02. Unique K-Number Sum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/combination-sum-iii--111703/1)

## **🧩 Problem Description**

You are given two integers `n` and `k`. Your task is to find all valid combinations of `k` numbers that add up to `n` based on the following conditions:

- Only numbers from the range **[1, 9]** can be used.
- Each number can only be used **at most once**.

A valid combination is a set of `k` distinct numbers from 1 to 9 whose sum equals `n`. The goal is to return all such combinations.

## **📘 Examples**

### Example 1

```cpp
Input: n = 9, k = 3
Output: [[1, 2, 6], [1, 3, 5], [2, 3, 4]]
Explanation: There are three valid combinations of 3 numbers that sum to 9: 
[1, 2, 6], [1, 3, 5] and [2, 3, 4].
```

### Example 2

```cpp
Input: n = 3, k = 3
Output: []
Explanation: It is not possible to pick 3 distinct numbers from 1 to 9 that sum to 3, 
so no valid combinations exist.
```

### Example 3

```cpp
Input: n = 7, k = 2
Output: [[1, 6], [2, 5], [3, 4]]
Explanation: Valid pairs of 2 numbers that sum to 7 are: [1, 6], [2, 5], and [3, 4].
```

## **🔒 Constraints**

* $1 \le n \le 50$
* $1 \le k \le 9$

## **✅ My Approach**

The optimal approach uses **Backtracking with DFS (Depth-First Search)** to efficiently explore all valid combinations while pruning invalid paths early:

### **Backtracking with Pruning**

1. **Base Cases:**
   * If `k` numbers have been selected (`cnt == k`):
     * Check if their sum equals `n`. If yes, add the combination to results.
   * If impossible conditions detected (sum already exceeds `n` or remaining numbers can't reach target), return early.

2. **Early Pruning:**
   * Before starting, check if `n < k` (impossible to have k positive numbers sum to less than k).
   * Check if `n > 9 * k` (maximum possible sum with k numbers from 1-9 is 9+8+...+(9-k+1)).
   * During recursion, if current sum + current number exceeds `n`, break the loop (no need to try larger numbers).

3. **Explore Choices:**
   * For each number from `start` to 9:
     * Add the number to current combination.
     * Recursively explore with updated sum, count, and next starting number.
     * Backtrack by removing the number to try other possibilities.

4. **Track State:**
   * `start`: Ensures we only pick numbers greater than previously selected ones (avoids duplicates and maintains sorted order).
   * `sum`: Current sum of selected numbers.
   * `cnt`: Count of numbers selected so far.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(C(9, k)), where C(9, k) represents the binomial coefficient "9 choose k". In the worst case, we explore all possible combinations of choosing k numbers from 9 options. The actual time is reduced by pruning invalid branches early.
* **Expected Auxiliary Space Complexity:** O(k), as the recursion depth is at most k levels deep (we select k numbers), and we maintain a current combination vector of size k.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(int n, int k) {
        if (n < k || n > 9 * k) return {};
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int, int, int)> dfs = [&](int start, int sum, int cnt) {
            if (cnt == k) {
                if (sum == n) res.push_back(cur);
                return;
            }
            for (int i = start; i <= 9; i++) {
                if (sum + i > n) break;
                cur.push_back(i);
                dfs(i + 1, sum + i, cnt + 1);
                cur.pop_back();
            }
        };
        dfs(1, 0, 0);
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative Bitmask Approach**

### 💡 Algorithm Steps:

1. Generate all possible subsets using bitmask from 0 to 2^9 - 1.
2. For each bitmask, count set bits and calculate sum of corresponding digits.
3. Check if count equals k and sum equals n simultaneously.
4. Add valid combinations to result maintaining sorted order.

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> res;
        for (int mask = 0; mask < 512; mask++) {
            if (__builtin_popcount(mask) != k) continue;
            int sum = 0;
            vector<int> cur;
            for (int i = 0; i < 9; i++) {
                if (mask & (1 << i)) {
                    cur.push_back(i + 1);
                    sum += i + 1;
                }
            }
            if (sum == n) res.push_back(cur);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(2^9 × 9) = O(4608) - Constant time for checking all subsets
* **Auxiliary Space:** 💾 O(k) - Space for current combination

### ✅ **Why This Approach?**

* No recursion overhead or stack space needed
* Guaranteed to explore all valid combinations
* Predictable constant time performance


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🌲 **Backtracking DFS**           | 🟢 O(C(9,k))           | 🟢 O(k)                 | 🚀 Clean and intuitive            | 🔄 Recursion overhead                |
| 🎭 **Bitmask Iteration**          | 🟢 O(512)              | 🟢 O(k)                 | 📊 Constant time guarantee        | 💾 Checks invalid combinations       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Interview/Clean code**                        | 🥇 **Backtracking DFS**              | ★★★★★                     |
| 📖 **Small constraints guaranteed**                | 🥈 **Bitmask Iteration**             | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<ArrayList<Integer>> combinationSum(int n, int k) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        if (n < k || n > 9 * k) return res;
        backtrack(res, new ArrayList<>(), n, k, 1);
        return res;
    }
    
    void backtrack(ArrayList<ArrayList<Integer>> res, ArrayList<Integer> cur, int rem, int left, int start) {
        if (left == 0) {
            if (rem == 0) res.add(new ArrayList<>(cur));
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (rem < i) break;
            cur.add(i);
            backtrack(res, cur, rem - i, left - 1, i + 1);
            cur.remove(cur.size() - 1);
        }
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def combinationSum(self, n, k):
        if n < k or n > 9 * k: return []
        res = []
        def bt(start, rem, left, cur):
            if left == 0:
                if rem == 0: res.append(cur[:])
                return
            for i in range(start, 10):
                if rem < i: break
                cur.append(i)
                bt(i + 1, rem - i, left - 1, cur)
                cur.pop()
        bt(1, n, k, [])
        return res
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
