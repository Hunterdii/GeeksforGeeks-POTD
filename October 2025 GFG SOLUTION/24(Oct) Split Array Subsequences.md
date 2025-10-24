---
title: "🔢 Split Array Subsequences | GFG Solution 🔍"
keywords🏷️: ["🔢 consecutive subsequences", "🔍 greedy algorithm", "📍 hash map", "📈 frequency tracking", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Split Array into Consecutive Subsequences: determine if array can be split into consecutive subsequences of length at least k using greedy approach with hash maps. 🚀"
date: 📅 2025-10-24
---

# *24. Split Array Subsequences*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/split-array-subsequences/1)

## **🧩 Problem Description**

You are given a sorted integer array `arr[]` and an integer `k`. Your task is to determine if it is possible to split the array into one or more **consecutive subsequences** such that:

* Each subsequence consists of consecutive integers (each number is exactly one greater than the previous).
* Every subsequence has a length of **at least k**.

Return `true` if such a split is possible, otherwise return `false`.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 2, 3, 3, 4, 5], k = 2
Output: true
Explanation: arr can be split into three subsequences of length k - [2, 3], [2, 3], [4, 5].
```

### Example 2

```cpp
Input: arr[] = [1, 1, 1, 1, 1], k = 4
Output: false
Explanation: It is impossible to split arr into consecutive increasing subsequences of length 4 or more.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^5$
* $1 \le k \le \text{arr.size()}$

## **✅ My Approach**

The optimal approach uses a **Greedy Algorithm** with **Two Hash Maps** to track frequencies and subsequence needs:

### **Greedy with Frequency and Need Tracking**

1. **Initialize Two Hash Maps:**
   * `freq`: Tracks the frequency of each element remaining in the array.
   * `need`: Tracks how many subsequences are waiting to be extended with a specific number.

2. **First Pass - Build Frequency Map:**
   * Count the frequency of each element in the array.

3. **Second Pass - Greedy Assignment:**
   * For each element `x` in the array:
     * If `freq[x]` is 0, skip (already used).
     * Decrement `freq[x]`.
     * **Try to extend existing subsequence:** If `need[x] > 0`, extend a subsequence ending at `x-1` by adding `x`. Decrement `need[x]` and increment `need[x+1]`.
     * **Create new subsequence:** Otherwise, try to create a new subsequence starting from `x`. Check if next `k-1` consecutive elements are available. If yes, consume them and mark `need[x+k]` for future extension.
     * If neither option works, return `false`.

4. **Return Result:**
   * If all elements are successfully assigned to valid subsequences, return `true`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × k), where n is the size of the array. We iterate through the array once, and for each element that starts a new subsequence, we check up to k consecutive elements. In practice, with the greedy approach, many elements extend existing subsequences, making the average case closer to O(n).
* **Expected Auxiliary Space Complexity:** O(n), as we use two hash maps to store frequency and need information for distinct elements in the array. In the worst case, all elements are distinct, requiring O(n) space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool isPossible(vector<int>& a, int k) {
        unordered_map<int,int> freq, need;
        for (int x : a) freq[x]++;
        for (int x : a) {
            if (!freq[x]) continue;
            freq[x]--;
            if (need[x] > 0) need[x]--, need[x + 1]++;
            else {
                for (int i = 1; i < k; i++) {
                    if (--freq[x + i] < 0) return false;
                }
                need[x + k]++;
            }
        }
        return true;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Priority Queue Approach**

### 💡 Algorithm Steps:

1. Use a min-heap to track active subsequences with their last element and length.
2. For each element, try to extend an existing subsequence or start a new one.
3. If starting new is impossible and extension fails, return false.
4. Finally verify all subsequences meet minimum length requirement.

```cpp
class Solution {
public:
    bool isPossible(vector<int>& arr, int k) {
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        for (int x : arr) {
            if (m[x - 1].size()) {
                int len = m[x - 1].top();
                m[x - 1].pop();
                m[x].push(len + 1);
            } else {
                m[x].push(1);
            }
        }
        for (auto& p : m) {
            while (p.second.size()) {
                if (p.second.top() < k) return false;
                p.second.pop();
            }
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Priority queue operations
* **Auxiliary Space:** 💾 O(n) - Storage for subsequences

### ✅ **Why This Approach?**

* Tracks all subsequence lengths explicitly
* Natural handling of multiple subsequences
* Clear priority-based extension logic

## 📊 **3️⃣ Greedy Two-Pass**

### 💡 Algorithm Steps:

1. First pass: count frequency of each element.
2. Second pass: greedily try to extend existing chains or form new minimum chains.
3. Track available chain endings that can be extended.
4. Reject if unable to form valid chain at any point.

```cpp
class Solution {
public:
    bool isPossible(vector<int>& arr, int k) {
        map<int, int> cnt, end;
        for (int x : arr) cnt[x]++;
        for (int x : arr) {
            if (!cnt[x]) continue;
            cnt[x]--;
            if (end[x - 1]) {
                end[x - 1]--;
                end[x]++;
            } else {
                bool ok = true;
                for (int i = 1; i < k; i++) {
                    if (cnt[x + i] <= 0) {ok = false; break;}
                    cnt[x + i]--;
                }
                if (!ok) return false;
                end[x + k - 1]++;
            }
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × k) - Checking k elements ahead
* **Auxiliary Space:** 💾 O(n) - Map storage

### ✅ **Why This Approach?**

* Explicit validation of minimum length chains
* Clear greedy choice at each step
* Works well for smaller k values

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Greedy Frequency-Need**      | 🟡 O(n × k)            | 🟢 O(n)                 | 🚀 Space efficient               | 🐌 May check k elements              |
| 🔍 **Priority Queue**              | 🟡 O(n log n)          | 🟢 O(n)                 | 📖 Clear subsequence tracking    | 🐌 Log factor overhead               |
| 🔄 **Two-Pass Greedy**             | 🟡 O(n × k)            | 🟢 O(n)                 | ⭐ Explicit validation            | 🐌 Depends on k value                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Greedy Frequency-Need**         | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Priority Queue**                | ★★★★☆                     |
| 🎯 **Small k values**                                 | 🏅 **Two-Pass Greedy**               | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public boolean isPossible(int[] a, int k) {
        Map<Integer,Integer> freq = new HashMap<>(), need = new HashMap<>();
        for (int x : a) freq.put(x, freq.getOrDefault(x, 0) + 1);
        for (int x : a) {
            if (freq.get(x) == 0) continue;
            freq.put(x, freq.get(x) - 1);
            if (need.getOrDefault(x, 0) > 0) {
                need.put(x, need.get(x) - 1);
                need.put(x + 1, need.getOrDefault(x + 1, 0) + 1);
            } else {
                for (int i = 1; i < k; i++) {
                    if (freq.getOrDefault(x + i, 0) <= 0) return false;
                    freq.put(x + i, freq.get(x + i) - 1);
                }
                need.put(x + k, need.getOrDefault(x + k, 0) + 1);
            }
        }
        return true;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def isPossible(self, a, k):
        freq, need = {}, {}
        for x in a:
            freq[x] = freq.get(x, 0) + 1
        for x in a:
            if not freq[x]:
                continue
            freq[x] -= 1
            if need.get(x, 0):
                need[x] -= 1
                need[x + 1] = need.get(x + 1, 0) + 1
            else:
                for i in range(1, k):
                    if freq.get(x + i, 0) <= 0:
                        return False
                    freq[x + i] -= 1
                need[x + k] = need.get(x + k, 0) + 1
        return True
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
