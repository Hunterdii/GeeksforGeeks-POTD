---
title: "🍭 Shop in Candy Store | GFG Solution 🛒"
keywords🏷️: ["🍭 candy store", "🎯 greedy algorithm", "📊 sorting", "💰 min max cost", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Shop in Candy Store problem: find minimum and maximum cost to buy all candies with free candy offer using greedy approach. 🚀"
date: 📅 2025-08-12
---

# *12. Shop in Candy Store*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/shop-in-candy-store1145/1)

## **🧩 Problem Description**

In a candy store, there are different types of candies available and `prices[i]` represent the price of `ith` types of candies. You are provided with an attractive offer: **For every candy you buy from the store, you can get up to k other different candies for free.**

Your task is to find the **minimum and maximum amount of money** needed to buy all the candies.

**Note:** In both cases, you must take the maximum number of free candies possible during each purchase.

## **📘 Examples**

### Example 1

```cpp
Input: prices[] = [3, 2, 1, 4], k = 2
Output: [3, 7]
Explanation: 
- Minimum cost: Buy candy worth 1, get candies worth 3 and 4 for free. Also buy candy worth 2.
  Total: 1 + 2 = 3
- Maximum cost: Buy candy worth 4, get candies worth 1 and 2 for free. Also buy candy worth 3.
  Total: 3 + 4 = 7
```

### Example 2

```cpp
Input: prices[] = [3, 2, 1, 4, 5], k = 4
Output: [1, 5]
Explanation: 
- Minimum cost: Buy candy with cost 1 and get all other candies for free. Total: 1
- Maximum cost: Buy candy with cost 5 and get all other candies for free. Total: 5
```

## **🔒 Constraints**

* $1 \le \text{prices.size()} \le 10^5$
* $0 \le k \le \text{prices.size()}$
* $1 \le \text{prices}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses **Greedy Algorithm** with **Sorting** to maximize the benefit from free candies:

### **Greedy + Sorting Strategy**

1. **Sort the Array:**
   * Sort prices in ascending order to enable optimal greedy selection.

2. **Minimum Cost Strategy:**
   * Buy the cheapest candy and get k most expensive remaining candies for free.
   * Start from index 0 (cheapest), after each purchase, reduce remaining count by k.
   * Continue until all candies are covered.

3. **Maximum Cost Strategy:**
   * Buy the most expensive candy and get k cheapest remaining candies for free.
   * Start from last index (most expensive), after each purchase, increase lower bound by k.
   * Continue until all candies are covered.

4. **Implementation Details:**
   * Use remaining count tracking for minimum cost calculation.
   * Use index boundary tracking for maximum cost calculation.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the prices array. The sorting step dominates the complexity, while the two loops run in O(n) time combined.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like indices, costs, and bounds.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size(), min = 0, max = 0;
        for (int i = 0, rem = n; i < rem; i++, rem -= k) min += prices[i];
        for (int j = n - 1, idx = -1; j > idx; j--, idx += k) max += prices[j];
        return {min, max};
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pass Approach**

### 💡 Algorithm Steps:

1. Sort the prices array to enable optimal selection strategy.
2. For minimum: Buy cheapest, skip k items as free after each purchase.
3. For maximum: Buy most expensive, but account for k free items we must give.
4. Use remaining count and index tracking for accurate calculations.

```cpp
class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size(), minCost = 0, maxCost = 0;
        for (int i = 0, remaining = n; i < remaining; i++, remaining -= k) 
            minCost += prices[i];
        for (int j = n - 1, index = -1; j > index; j--, index += k) 
            maxCost += prices[j];
        return {minCost, maxCost};
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting dominates the complexity
* **Auxiliary Space:** 💾 O(1) - Only constant extra space used

### ✅ **Why This Approach?**

* Clear separation of min and max calculations
* Easy to debug and verify correctness
* Straightforward loop increment logic

## 📊 **3️⃣ Mathematical Approach**

### 💡 Algorithm Steps:

1. Sort prices to enable greedy selection strategy.
2. Calculate exact number of purchases needed: ceil(n / (k + 1)).
3. For minimum: Select cheapest items with calculated purchase count.
4. For maximum: Select expensive items with calculated purchase count.

```cpp
class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size(), minCost = 0, maxCost = 0;
        int purchases = (n + k) / (k + 1); 
        for (int i = 0; i < purchases; i++) minCost += prices[i];
        for (int i = n - purchases; i < n; i++) maxCost += prices[i];
        return {minCost, maxCost};
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting step dominates
* **Auxiliary Space:** 💾 O(1) - Mathematical calculation approach

### ✅ **Why This Approach?**

* Pre-calculates exact number of purchases needed
* Eliminates complex loop conditions
* More mathematically elegant solution


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Single Loop Combined**        | 🟢 O(n log n)          | 🟢 O(1)                 | 🚀 Compact single loop per calc   | 🔧 Complex loop conditions            |
| 🔄 **Two-Pass**                    | 🟢 O(n log n)          | 🟢 O(1)                 | 📖 Clear separation of logic      | 🔄 Two separate loops                 |
| 🧮 **Mathematical**                | 🟢 O(n log n)          | 🟢 O(1)                 | 🎯 Pre-calculated buy count       | 💭 Less intuitive for some           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Code Golf/Shortest**                         | 🥇 **Single Loop Combined**          | ★★★★★                     |
| 📖 **Readability Priority**                       | 🥈 **Two-Pass**                      | ★★★★★                     |
| 🧮 **Mathematical Elegance**                      | 🥉 **Mathematical**                  | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> minMaxCandy(int[] prices, int k) {
        Arrays.sort(prices);
        int n = prices.length, min = 0, max = 0;
        for (int i = 0, rem = n; i < rem; i++, rem -= k) min += prices[i];
        for (int j = n - 1, idx = -1; j > idx; j--, idx += k) max += prices[j];
        return new ArrayList<>(Arrays.asList(min, max));
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minMaxCandy(self, prices, k):
        prices.sort()
        n, min_, max_ = len(prices), 0, 0
        i, rem = 0, n
        while i < rem:
            min_ += prices[i]; i += 1; rem -= k
        j, idx = n - 1, -1
        while j > idx:
            max_ += prices[j]; j -= 1; idx += k
        return [min_, max_]
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


