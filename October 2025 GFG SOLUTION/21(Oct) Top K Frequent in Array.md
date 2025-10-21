---
title: "🔢 Top K Frequent Elements in Array | GFG Solution 🔍"
keywords🏷️: ["🔢 top k elements", "🔍 frequency count", "📊 quickselect", "📈 hash map", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Top K Frequent Elements problem: find k most frequent elements using QuickSelect partitioning with optimal time complexity. 🚀"
date: 📅 2025-10-21
---

# *21. Top K Frequent Elements in Array*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1)

## **🧩 Problem Description**

You are given a non-empty integer array `arr[]`. Your task is to find and return the **top k elements** which have the **highest frequency** in the array.

**Note:** If two numbers have the same frequency, the larger number should be given the higher priority.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [3, 1, 4, 4, 5, 2, 6, 1], k = 2
Output: [4, 1]
Explanation: Frequency of 4 is 2 and frequency of 1 is 2, these two have the maximum 
frequency and 4 is larger than 1.
```

### Example 2

```cpp
Input: arr[] = [7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9], k = 4
Output: [5, 11, 7, 10]
Explanation: Frequency of 5 is 3, frequency of 11 is 2, frequency of 7 is 2, 
frequency of 10 is 1.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^5$
* $1 \le k \le \text{no. of distinct elements}$

## **✅ My Approach**

The optimal approach uses **QuickSelect Partitioning** combined with **Hash Map** frequency counting to efficiently find the top k frequent elements:

### **QuickSelect + Partial Sort Algorithm**

1. **Build Frequency Map:**
   * Traverse the entire array once to count the frequency of each element.
   * Store frequencies in an unordered hash map for O(1) average lookup time.
   * Time: O(n) where n is the array size.

2. **Create Frequency-Element Pairs:**
   * Convert the frequency map into a vector of pairs.
   * Each pair contains (frequency, element) for easy sorting and comparison.
   * This transformation takes O(m) time where m is the number of unique elements.

3. **Partition Using nth_element:**
   * Apply C++ STL's `nth_element` function with greater comparator.
   * This uses the QuickSelect algorithm to partition the vector.
   * After partitioning, the top k frequent elements are guaranteed to be in the first k positions.
   * Average time complexity: O(m) for partitioning.

4. **Sort Top K Elements:**
   * Sort only the first k elements in descending order by frequency.
   * When frequencies are equal, the larger element value gets priority.
   * This ensures the correct order as per problem requirements.
   * Time: O(k log k) which is typically much smaller than O(m log m).

5. **Extract Result:**
   * Iterate through the first k sorted pairs.
   * Extract only the element values (second component of pair) into result vector.
   * Return the final result containing top k frequent elements.

### **Why This Approach?**

* **Optimal Time Complexity:** Combines the efficiency of QuickSelect (O(m) average) with minimal sorting overhead (O(k log k)).
* **Space Efficient:** Uses only O(m) extra space for frequency map and pairs vector.
* **Handles Tie-Breaking:** Automatically prioritizes larger values when frequencies are equal through pair comparison.
* **Scalable:** Performs exceptionally well when k << m (k is much smaller than unique elements count).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + m + k log k), where n is the size of the input array, m is the number of distinct elements, and k is the number of top elements to find. Breaking down: O(n) for frequency counting, O(m) average for nth_element partitioning, and O(k log k) for sorting the top k elements. Since typically k << m << n, the overall complexity is highly efficient.
* **Expected Auxiliary Space Complexity:** O(m), where m is the number of distinct elements in the array. We use a hash map to store element frequencies (O(m)) and a vector of pairs to store frequency-element combinations (O(m)). The result vector uses O(k) space which is included in O(m) since k ≤ m.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> topKFreq(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<pair<int, int>> v;
        for (auto& p : freq) v.push_back({p.second, p.first});
        nth_element(v.begin(), v.begin() + k - 1, v.end(), greater<pair<int, int>>());
        sort(v.begin(), v.begin() + k, greater<pair<int, int>>());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(v[i].second);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Min Heap (Priority Queue) Approach**

### 💡 Algorithm Steps:

1. Build a frequency map by counting occurrences of each element in the array.
2. Create a min heap (priority queue) to maintain exactly k elements with highest frequencies.
3. Iterate through the frequency map:
   * Push each (frequency, element) pair into the min heap.
   * If heap size exceeds k, pop the element with minimum frequency.
4. After processing all elements, the heap contains exactly k most frequent elements.
5. Extract elements from heap into result vector and reverse to get descending order.
6. This approach maintains only k elements in memory at any time.

```cpp
class Solution {
public:
    vector<int> topKFreq(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto& p : freq) {
            pq.push({p.second, p.first});
            if (pq.size() > k) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k) - Building frequency map takes O(n), and for each of m unique elements, we perform heap operations taking O(log k) time
* **Auxiliary Space:** 💾 O(m + k) - Hash map stores m unique elements, heap stores at most k elements

### ✅ **Why This Approach?**

* Memory efficient when k is significantly smaller than the number of unique elements
* Maintains optimal heap size throughout execution
* Excellent choice for streaming data or when memory is constrained
* Heap naturally maintains the k largest frequencies without sorting all elements

## 📊 **3️⃣ Simple Sorting Approach**

### 💡 Algorithm Steps:

1. Build a frequency map to count occurrences of each element in the input array.
2. Transform the frequency map into a vector of (frequency, element) pairs.
3. Sort the entire vector in descending order by frequency.
4. When frequencies are equal, pairs are automatically sorted by element value in descending order.
5. Extract the first k elements from the sorted vector as the result.
6. This approach is straightforward but sorts all unique elements even when k is small.

```cpp
class Solution {
public:
    vector<int> topKFreq(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<pair<int, int>> v;
        for (auto& p : freq) v.push_back({p.second, p.first});
        sort(v.rbegin(), v.rend());
        vector<int> res;
        for (int i = 0; i < k; i++) res.push_back(v[i].second);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + m log m) - O(n) for frequency counting and O(m log m) for sorting where m is number of unique elements
* **Auxiliary Space:** 💾 O(m) - Space for frequency map and vector of pairs

### ✅ **Why This Approach?**

* Extremely simple and easy to understand implementation
* No complex data structures or algorithms needed
* Good baseline solution for interviews or when code clarity is priority
* Works reliably for all input sizes without edge cases
* Ideal when m (unique elements) is relatively small

## 📊 **4️⃣ Bucket Sort Approach**

### 💡 Algorithm Steps:

1. Count frequency of each element and track the maximum frequency encountered.
2. Create an array of buckets where each index represents a frequency value.
3. Place each element into its corresponding frequency bucket (bucket[frequency]).
4. Traverse buckets from highest frequency to lowest (max to 1).
5. For each bucket, sort elements in descending order to handle tie-breaking.
6. Collect elements from buckets until we have k elements in the result.
7. This achieves linear time by avoiding comparison-based sorting of all elements.

```cpp
class Solution {
public:
    vector<int> topKFreq(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int x : arr) maxFreq = max(maxFreq, ++freq[x]);
        vector<vector<int>> buckets(maxFreq + 1);
        for (auto& [num, f] : freq) buckets[f].push_back(num);
        vector<int> res;
        for (int i = maxFreq; i > 0 && res.size() < k; i--) {
            sort(buckets[i].rbegin(), buckets[i].rend());
            for (int x : buckets[i]) {
                res.push_back(x);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + m) - Linear time for frequency counting and bucket distribution, with small overhead for sorting within each bucket
* **Auxiliary Space:** 💾 O(n) - Buckets array of size maxFreq + 1, plus frequency map

### ✅ **Why This Approach?**

* Achieves optimal O(n) time complexity in the average case
* Natural grouping of elements by frequency reduces comparison operations
* Excellent performance when frequency distribution is dense
* Efficient when maximum frequency is not extremely large
* Demonstrates clever use of counting sort principles

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **QuickSelect + Sort**         | 🟢 O(n + m + k log k)  | 🟢 O(m)                 | 🚀 Best average case, optimal k sorting | 🔧 Slightly complex implementation |
| 📦 **Min Heap**                   | 🟢 O(n log k)          | 🟢 O(m + k)             | 💾 Memory efficient for small k    | 🐌 Slower when k is large            |
| 📊 **Sorting**                    | 🟡 O(n + m log m)      | 🟢 O(m)                 | 📖 Simplest implementation         | 🐌 Sorts all elements unnecessarily   |
| 🪣 **Bucket Sort**                | 🟢 O(n + m)            | 🟡 O(n)                 | ⚡ Best time complexity            | 💾 Higher space when maxFreq is large |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Small k, very large dataset**                | 🥇 **Min Heap**                      | ★★★★★                     |
| 📖 **Balanced performance & code clarity**        | 🥈 **QuickSelect + Sort**            | ★★★★★                     |
| 🎯 **Maximum speed, frequency distribution known** | 🥉 **Bucket Sort**                   | ★★★★★                     |
| 🔧 **Quick implementation, small datasets**       | 🎖️ **Sorting**                       | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> topKFreq(int[] a, int k) {
        HashMap<Integer, Integer> f = new HashMap<>();
        for (int x : a) f.put(x, f.getOrDefault(x, 0) + 1);
        List<int[]> v = new ArrayList<>();
        for (var e : f.entrySet()) v.add(new int[]{e.getValue(), e.getKey()});
        v.sort((x, y) -> y[0] == x[0] ? y[1] - x[1] : y[0] - x[0]);
        ArrayList<Integer> r = new ArrayList<>();
        for (int i = 0; i < k; i++) r.add(v.get(i)[1]);
        return r;
    }
}
```

## **🐍 Code (Python)**

```python
from collections import Counter
class Solution:
    def topKFreq(self, a, k):
        f = Counter(a)
        return [x for x, _ in sorted(f.items(), key=lambda x: (-x[1], -x[0]))[:k]]
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
