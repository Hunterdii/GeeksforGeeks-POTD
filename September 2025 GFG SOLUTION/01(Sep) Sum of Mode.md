---
title: "🔢 Sum of Mode | GFG Solution 🔍"
keywords🏷️: ["🔢 sum of mode", "🔍 sliding window", "📍 frequency tracking", "📈 hash map", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Sum of Mode problem: find sum of modes of all subarrays of size k using efficient sliding window with frequency buckets technique. 🚀"
date: 📅 2025-09-01
---

# *01. Sum of Mode*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sum-of-mode/1)

## **🧩 Problem Description**

You are given an array `arr[]` of positive integers and an integer `k`. Your task is to find the **sum of the modes** of all the subarrays of size `k`.

**Note:** The mode of a subarray is the element that occurs with the highest frequency. If multiple elements have the same highest frequency, the smallest such element is considered the mode.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3, 2, 5, 2, 4, 4], k = 3
Output: 13
Explanation: The subarrays of size 3 are:
[1, 2, 3] → mode = 1 (all have frequency 1, smallest is 1)
[2, 3, 2] → mode = 2 (frequency 2)
[3, 2, 5] → mode = 2 (all have frequency 1, smallest is 2)
[2, 5, 2] → mode = 2 (frequency 2)
[5, 2, 4] → mode = 2 (all have frequency 1, smallest is 2)
[2, 4, 4] → mode = 4 (frequency 2, but 2 also has frequency 1, so smallest among max freq is 4)
Actually: [2, 4, 4] → mode = 4 (frequency 2 for element 4)
Sum = 1 + 2 + 2 + 2 + 2 + 4 = 13
```

### Example 2

```cpp
Input: arr[] = [1, 2, 1, 3, 5], k = 2
Output: 6
Explanation: The subarrays of size 2 are:
[1, 2] → mode = 1 (all have frequency 1, smallest is 1)
[2, 1] → mode = 1 (all have frequency 1, smallest is 1) 
[1, 3] → mode = 1 (all have frequency 1, smallest is 1)
[3, 5] → mode = 3 (all have frequency 1, smallest is 3)
Sum = 1 + 1 + 1 + 3 = 6
```

## **🔒 Constraints**

* $1 \le k \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses **Sliding Window** technique with **Frequency Buckets** to efficiently track modes across all subarrays:

### **Sliding Window + Frequency Buckets**

1. **Data Structures:**
   * `freq`: Hash map to store frequency of each element in current window.
   * `buckets`: Map where key is frequency and value is set of elements with that frequency.

2. **Initial Window Setup:**
   * Process first `k` elements to populate frequency map.
   * Organize elements by their frequencies in buckets.
   * Mode is the smallest element from the bucket with highest frequency.

3. **Sliding Window Process:**
   * **Remove Element:** When sliding window, remove `arr[i-k]` from current window:
     - Remove from its current frequency bucket
     - Decrease its frequency
     - Add to new frequency bucket if frequency > 0
   * **Add Element:** Add `arr[i]` to current window:
     - Remove from its current frequency bucket (if exists)
     - Increase its frequency  
     - Add to new frequency bucket

4. **Mode Calculation:**
   * After each window update, find the bucket with maximum frequency.
   * From that bucket, select the smallest element as mode.
   * Add this mode to running sum.

5. **Efficiency:**
   * Bucket structure allows O(log k) access to maximum frequency.
   * Set within each bucket allows O(log k) access to smallest element with that frequency.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log k), where n is the size of the array and k is the window size. Each element is processed with map/set operations that take O(log k) time.
* **Expected Auxiliary Space Complexity:** O(k), where k is the window size. We maintain frequency map and buckets that together store at most k distinct elements and their frequency distributions.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        unordered_map<int, int> freq;
        map<int, set<int>> buckets;
        
        for (int i = 0; i < k; i++) freq[arr[i]]++;
        for (auto& p : freq) buckets[p.second].insert(p.first);
        sum += *buckets.rbegin()->second.begin();
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            
            buckets[freq[out]].erase(out);
            if (buckets[freq[out]].empty()) buckets.erase(freq[out]);
            if (--freq[out] > 0) buckets[freq[out]].insert(out);
            else freq.erase(out);
            if (freq[in] > 0) {
                buckets[freq[in]].erase(in);
                if (buckets[freq[in]].empty()) buckets.erase(freq[in]);
            }
            buckets[++freq[in]].insert(in);
            sum += *buckets.rbegin()->second.begin();
        }
        return sum;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Priority Queue with Lazy Deletion**

### 💡 Algorithm Steps:

1. Use priority queue to track frequency and value pairs for efficient mode access.
2. Store pairs as (frequency, -value) to get max frequency and min value priority.
3. Use lazy deletion to handle outdated entries in priority queue.
4. Clean invalid entries only when accessing the top element.

```cpp
class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) freq[arr[i]]++;
        for (auto& p : freq) pq.push({p.second, -p.first});
        auto getMode = [&]() {
            while (!pq.empty() && freq[-pq.top().second] != pq.top().first) 
                pq.pop();
            return -pq.top().second;
        };
        sum += getMode();
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            if (--freq[out] == 0) freq.erase(out);
            else pq.push({freq[out], -out});
            pq.push({++freq[in], -in});
            sum += getMode();
        }
        return sum;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k) - Priority queue operations
* **Auxiliary Space:** 💾 O(k) - Frequency map and priority queue

### ✅ **Why This Approach?**

* Lazy deletion reduces unnecessary operations
* Priority queue automatically maintains ordering
* Good balance between complexity and efficiency

## 📊 **3️⃣ Multiset for Direct Mode Tracking**

### 💡 Algorithm Steps:

1. Use multiset to store frequency-value pairs for automatic sorting.
2. Maintain pairs as {frequency, -value} to get largest frequency first, then smallest value.
3. Directly access mode from multiset's last element.
4. Update multiset by erasing old pairs and inserting new ones.

```cpp
class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        unordered_map<int, int> freq;
        multiset<pair<int, int>> ms; 
        for (int i = 0; i < k; i++) freq[arr[i]]++;
        for (auto& p : freq) ms.insert({p.second, -p.first});
        sum += -ms.rbegin()->second;
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            ms.erase(ms.find({freq[out], -out}));
            if (--freq[out] > 0) ms.insert({freq[out], -out});
            else freq.erase(out);
            if (freq[in] > 0) ms.erase(ms.find({freq[in], -in}));
            freq[in]++;
            ms.insert({freq[in], -in});
            
            sum += -ms.rbegin()->second;
        }
        return sum;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k) - Multiset operations
* **Auxiliary Space:** 💾 O(k) - Frequency map and multiset

### ✅ **Why This Approach?**

* Direct access to mode without bucket management
* Automatic sorting of frequency-value pairs
* Clean insert/erase operations

## 📊 **4️⃣ Simple Frequency Map with Linear Scan**

### 💡 Algorithm Steps:

1. Maintain only frequency map for minimal space usage.
2. For each window, find mode by scanning all frequencies to get maximum.
3. Among max frequency elements, select the smallest value.
4. Simple but less efficient for large datasets.

```cpp
class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < k; i++) freq[arr[i]]++;
        auto getMode = [&]() {
            int maxFreq = 0;
            for (auto& p : freq) maxFreq = max(maxFreq, p.second);
            int mode = INT_MAX;
            for (auto& p : freq) 
                if (p.second == maxFreq) mode = min(mode, p.first);
            return mode;
        };
        sum += getMode();
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            if (--freq[out] == 0) freq.erase(out);
            freq[in]++;
            sum += getMode();
        }
        return sum;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × k) - Linear scan for each mode calculation
* **Auxiliary Space:** 💾 O(k) - Only frequency map

### ✅ **Why This Approach?**

* Minimal space usage and simple logic
* Easy to understand and debug
* Good for small window sizes

> **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs _(fails ~1110 /1111 test cases due to time constraints)_.
> 
## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🗂️ **Frequency Buckets**           | 🟢 O(n log k)          | 🟢 O(k)                 | 🎯 Optimal mode access, clean     | 🔧 Complex bucket management         |
| 📊 **Priority Queue**               | 🟢 O(n log k)          | 🟢 O(k)                 | 🧹 Lazy deletion, automatic sort  | 🔍 Cleanup overhead                  |
| 📋 **Multiset Tracking**           | 🟢 O(n log k)          | 🟢 O(k)                 | 💡 Direct mode access            | 🔧 Pair management complexity        |
| 📋 **Simple Frequency Map**        | 🟡 O(n × k)            | 🟢 O(k)                 | 💡 Straightforward logic         | 🐌 Linear scan per window            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Large datasets, competitive programming**       | 🥇 **Frequency Buckets**             | ★★★★★                     |
| 📊 **Clean code, good performance**                  | 🥈 **Multiset Tracking**             | ★★★★☆                     |
| 🔧 **Memory efficient, lazy cleanup**                | 🥉 **Priority Queue**                | ★★★★☆                     |
| 🎓 **Learning purposes, small inputs**               | 🎖️ **Simple Frequency Map**          | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int sumOfModes(int[] arr, int k) {
        int n = arr.length, sum = 0;
        Map<Integer, Integer> freq = new HashMap<>();
        TreeMap<Integer, TreeSet<Integer>> buckets = new TreeMap<>();
        for (int i = 0; i < k; i++) freq.merge(arr[i], 1, Integer::sum);
        freq.forEach((val, f) -> buckets.computeIfAbsent(f, x -> new TreeSet<>()).add(val));
        sum += buckets.lastEntry().getValue().first();
        for (int i = k; i < n; i++) {
            int out = arr[i - k], in = arr[i];
            TreeSet<Integer> outSet = buckets.get(freq.get(out));
            outSet.remove(out);
            if (outSet.isEmpty()) buckets.remove(freq.get(out));
            freq.merge(out, -1, Integer::sum);
            if (freq.get(out) > 0) 
                buckets.computeIfAbsent(freq.get(out), x -> new TreeSet<>()).add(out);
            else freq.remove(out);
            if (freq.containsKey(in)) {
                TreeSet<Integer> inSet = buckets.get(freq.get(in));
                inSet.remove(in);
                if (inSet.isEmpty()) buckets.remove(freq.get(in));
            }
            freq.merge(in, 1, Integer::sum);
            buckets.computeIfAbsent(freq.get(in), x -> new TreeSet<>()).add(in);
            sum += buckets.lastEntry().getValue().first();
        }
        return sum;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def sumOfModes(self, arr, k):
        n, sum_val = len(arr), 0
        freq = defaultdict(int)
        buckets = defaultdict(set)
        for i in range(k):
            freq[arr[i]] += 1
        for val, f in freq.items():
            buckets[f].add(val)
        max_freq = max(buckets.keys())
        sum_val += min(buckets[max_freq])
        for i in range(k, n):
            out, in_val = arr[i - k], arr[i]
            buckets[freq[out]].remove(out)

            if not buckets[freq[out]]:
                del buckets[freq[out]]
            freq[out] -= 1
            if freq[out] > 0:
                buckets[freq[out]].add(out)
            else:
                del freq[out]
            if freq[in_val] > 0:
                buckets[freq[in_val]].remove(in_val)
                if not buckets[freq[in_val]]:
                    del buckets[freq[in_val]]

            freq[in_val] += 1
            buckets[freq[in_val]].add(in_val)
            max_freq = max(buckets.keys())
            sum_val += min(buckets[max_freq])
        
        return sum_val
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
