---
title: "🕰️ Difference Check | GFG Solution 🔍"
keywords🏷️: ["⏰ minimum difference", "🔍 sorting", "📍 time parsing", "📈 array processing", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Time Difference problem: find minimum difference in seconds between any two time strings using efficient sorting technique. 🚀"
date: 📅 2025-08-07
---

# *07. Difference Check*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/difference-check/1)

## **🧩 Problem Description**

You are given an array `arr[]` of time strings in 24-hour clock format **"HH:MM:SS"**. Your task is to find the **minimum difference in seconds** between any two time strings in the array.

The clock wraps around at midnight, so the time difference between "23:59:59" and "00:00:00" is 1 second.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = ["12:30:15", "12:30:45"]
Output: 30
Explanation: The minimum time difference is 30 seconds.
```

### Example 2

```cpp
Input: arr[] = ["00:00:01", "23:59:59", "00:00:05"]
Output: 2
Explanation: The time difference is minimum between "00:00:01" and "23:59:59".
```

## **🔒 Constraints**

* $2 \le \text{arr.size()} \le 10^5$
* $\text{arr}[i]$ is in "HH:MM:SS" format.

## **✅ My Approach**

The optimal approach uses **Time Conversion** and **Sorting** to efficiently find the minimum difference:

### **Time Parsing + Sorting Algorithm**

1. **Convert Time to Seconds:**
   * Parse each time string "HH:MM:SS" and convert to total seconds from midnight.
   * Formula: `seconds = hours * 3600 + minutes * 60 + seconds`
   * This normalizes all times to a single integer format for easy comparison.

2. **Sort the Seconds:**
   * Sort all converted time values in ascending order.
   * This allows us to check adjacent pairs for minimum differences efficiently.

3. **Find Minimum Adjacent Differences:**
   * Iterate through sorted array and calculate difference between consecutive elements.
   * Keep track of the minimum difference found.

4. **Handle Circular Clock:**
   * Consider the wrap-around case: difference between the last time and first time of next day.
   * Calculate: `first_time + 86400 - last_time` (86400 = total seconds in a day).
   * Compare this with other differences to find the global minimum.

5. **Early Termination:**
   * If any two times are identical, return 0 immediately.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. The time conversion takes O(n) time, but sorting dominates with O(n log n) complexity.
* **Expected Auxiliary Space Complexity:** O(n), where n is the size of the array. We use additional space to store the converted seconds in a vector/array.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minDifference(vector<string>& arr) {
        vector<int> mins;
        for (auto& t : arr) {
            int h = (t[0] - '0') * 10 + (t[1] - '0');
            int m = (t[3] - '0') * 10 + (t[4] - '0');
            int s = (t[6] - '0') * 10 + (t[7] - '0');
            mins.push_back(h * 3600 + m * 60 + s);
        }
        sort(mins.begin(), mins.end());
        int res = mins[0] + 86400 - mins.back();
        for (int i = 1; i < mins.size(); i++) {
            res = min(res, mins[i] - mins[i-1]);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Boolean Array Approach (Original Optimized)**

### 💡 Algorithm Steps:

1. Convert all times to seconds and mark them in a boolean array
2. Check for duplicates during marking (return 0 if found)
3. Find consecutive marked positions to calculate minimum differences
4. Handle wrap-around case between last and first times

```cpp
class Solution {
public:
    int minDifference(vector<string>& arr) {
        vector<bool> seen(86400, false);
        for (auto& t : arr) {
            int sec = ((t[0]-'0')*10+(t[1]-'0'))*3600 + ((t[3]-'0')*10+(t[4]-'0'))*60 + (t[6]-'0')*10+(t[7]-'0');
            if (seen[sec]) return 0;
            seen[sec] = true;
        }
        int prev = -1, first = -1, res = 86400;
        for (int i = 0; i < 86400; i++) {
            if (!seen[i]) continue;
            if (prev == -1) first = i;
            else res = min(res, i - prev);
            prev = i;
        }
        return min(res, first + 86400 - prev);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(1) - Fixed 86400 iterations regardless of input size
* **Auxiliary Space:** 💾 O(1) - Fixed 86400 boolean array

### ✅ **Why This Approach?**

* Handles duplicates efficiently with early return
* Constant time complexity independent of input size
* Direct indexing provides fast lookups

## 📊 **3️⃣ Set-Based Approach**

### 💡 Algorithm Steps:

1. Convert times to seconds and store in a set for duplicate detection
2. Sort the unique time values for sequential processing
3. Calculate differences between adjacent times in sorted order
4. Consider circular difference between last and first times

```cpp
class Solution {
public:
    int minDifference(vector<string>& arr) {
        set<int> times;
        for (auto& t : arr) {
            int sec = stoi(t.substr(0,2))*3600 + stoi(t.substr(3,2))*60 + stoi(t.substr(6,2));
            if (!times.insert(sec).second) return 0;
        }
        vector<int> sorted(times.begin(), times.end());
        int res = sorted[0] + 86400 - sorted.back();
        for (int i = 1; i < sorted.size(); i++) {
            res = min(res, sorted[i] - sorted[i-1]);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Set operations and sorting
* **Auxiliary Space:** 💾 O(n) - Set and vector storage

### ✅ **Why This Approach?**

* Clean duplicate handling with set properties
* Natural sorting through set data structure
* Memory efficient for sparse time distributions

## 📊 **4️⃣ Direct Parsing Approach**

### 💡 Algorithm Steps:

1. Parse time strings directly without substring operations
2. Sort converted seconds for efficient difference calculation
3. Use single pass to find minimum adjacent differences
4. Include wrap-around calculation for complete coverage

```cpp
class Solution {
public:
    int minDifference(vector<string>& arr) {
        vector<int> secs;
        for (auto& t : arr) {
            secs.push_back(((t[0]-'0')*10+(t[1]-'0'))*3600 + 
                          ((t[3]-'0')*10+(t[4]-'0'))*60 + 
                          (t[6]-'0')*10+(t[7]-'0'));
        }
        sort(secs.begin(), secs.end());
        int res = secs[0] + 86400 - secs.back();
        for (int i = 1; i < secs.size(); i++) {
            if (secs[i] == secs[i-1]) return 0;
            res = min(res, secs[i] - secs[i-1]);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting dominates the complexity
* **Auxiliary Space:** 💾 O(n) - Vector for storing converted times

### ✅ **Why This Approach?**

* Fastest string parsing without substring operations
* Efficient duplicate detection during comparison
* Optimal for most practical input sizes

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Sorting-Based**              | 🟡 O(n log n)          | 🟢 O(n)                 | 🚀 Simple and efficient           | 🐌 Sorting overhead                   |
| 🔍 **Boolean Array**              | 🟢 O(1)                | 🟢 O(1)                 | ⚡ Constant time complexity       | 💾 Fixed large memory usage          |
| 📊 **Set-Based**                  | 🟡 O(n log n)          | 🟢 O(n)                 | 🎯 Clean duplicate handling       | 🔧 Multiple data structure overhead   |
| 🔄 **Direct Parsing**             | 🟡 O(n log n)          | 🟢 O(n)                 | ⭐ Fastest parsing               | 🔧 Manual duplicate check needed     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Small input size (n < 1000)**                    | 🥇 **Sorting-Based**                 | ★★★★★                     |
| 📖 **Large input with sparse times**                  | 🥈 **Boolean Array**                 | ★★★★★                     |
| 🔧 **Memory constrained environment**                 | 🥉 **Direct Parsing**                | ★★★★☆                     |
| 🎯 **Interview/Competitive Programming**              | 🏅 **Sorting-Based**                 | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minDifference(String[] arr) {
        int[] mins = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            String t = arr[i];
            int h = (t.charAt(0) - '0') * 10 + (t.charAt(1) - '0');
            int m = (t.charAt(3) - '0') * 10 + (t.charAt(4) - '0');
            int s = (t.charAt(6) - '0') * 10 + (t.charAt(7) - '0');
            mins[i] = h * 3600 + m * 60 + s;
        }
        Arrays.sort(mins);
        int res = mins[0] + 86400 - mins[mins.length - 1];
        for (int i = 1; i < mins.length; i++) {
            res = Math.min(res, mins[i] - mins[i - 1]);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minDifference(self, arr):
        mins = []
        for t in arr:
            h = int(t[:2])
            m = int(t[3:5])
            s = int(t[6:8])
            mins.append(h * 3600 + m * 60 + s)
        mins.sort()
        res = mins[0] + 86400 - mins[-1]
        for i in range(1, len(mins)):
            res = min(res, mins[i] - mins[i-1])
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
