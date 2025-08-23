---
title: "📚 Allocate Minimum Pages | GFG Solution 🔍"
keywords🏷️: ["📚 book allocation", "🔍 binary search", "📊 optimization", "📈 divide and conquer", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Allocate Minimum Pages problem: find optimal book allocation to minimize maximum pages per student using binary search technique. 🚀"
date: 📅 2025-08-23
---

# *23. Allocate Minimum Pages*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1)

## **🧩 Problem Description**

You are given an array `arr[]` of integers, where each element `arr[i]` represents the number of pages in the i-th book. You also have an integer `k` representing the number of students. The task is to allocate books to each student such that:

- Each student receives at least one book.
- Each student is assigned a contiguous sequence of books.
- No book is assigned to more than one student.

The objective is to **minimize the maximum number of pages** assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

**Note:** If it is not possible to allocate books to all students, return -1.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
```

### Example 2

```cpp
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $1 \le \text{arr}[i], k \le 10^3$

## **✅ My Approach**

The optimal approach uses **Binary Search** on the answer space to efficiently find the minimum possible maximum pages allocation:

### **Binary Search on Answer**

1. **Define Search Space:**
   * **Lower bound:** Maximum element in array (minimum possible answer - at least one student must get the largest book)
   * **Upper bound:** Sum of all elements (maximum possible answer - one student gets all books)

2. **Binary Search Logic:**
   * For each mid value, check if it's possible to allocate books to `k` students such that no student gets more than `mid` pages
   * If possible, search for smaller values (move right boundary to mid)
   * If not possible, search for larger values (move left boundary to mid + 1)

3. **Feasibility Check:**
   * Use greedy approach: assign books to current student until adding next book exceeds `mid`
   * When limit exceeded, assign remaining books to next student
   * If total students needed ≤ k, allocation is feasible

4. **Edge Case:**
   * If k > number of books, return -1 (impossible to give each student at least one book)

### **Algorithm Steps:**
1. Check if k > n, return -1
2. Set left = max(arr), right = sum(arr)
3. While left < right:
   - Calculate mid = left + (right - left) / 2
   - Check if allocation with max pages = mid is feasible
   - If feasible: right = mid (try for smaller maximum)
   - If not feasible: left = mid + 1 (need larger maximum)
4. Return left (minimum possible maximum pages)

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × log(sum)), where n is the number of books and sum is the total pages. The binary search runs in O(log(sum)) iterations, and each feasibility check takes O(n) time.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables regardless of input size.

## **⚡ Code (C)**

```c
int findPages(int arr[], int n, int k) {
    if (k > n) return -1;
    int l = arr[0], r = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > l) l = arr[i];
        r += arr[i];
    }
    while (l < r) {
        int m = l + (r - l) / 2;
        int s = 1, p = 0;
        for (int i = 0; i < n; i++) {
            if (p + arr[i] > m) { s++; p = arr[i]; }
            else p += arr[i];
        }
        s <= k ? (r = m) : (l = m + 1);
    }
    return l;
}
```


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        while (l < r) {
            int m = l + (r - l) / 2;
            int s = 1, p = 0;
            for (int x : arr) {
                if (p + x > m) { s++; p = x; } 
                else p += x;
            }
            s <= k ? r = m : l = m + 1;
        }
        return l;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Recursive Binary Search**

### 💡 Algorithm Steps:

1. Use recursive binary search instead of iterative approach
2. Base condition when low >= high to return the minimum pages
3. Calculate mid and check feasibility using helper function
4. Recursively search in appropriate half based on feasibility

```cpp
class Solution {
public:
    bool canAllocate(vector<int> &arr, int k, int limit) {
        int cnt = 1, sum = 0;
        for (int x : arr) {
            if (sum + x > limit) cnt++, sum = x;
            else sum += x;
        }
        return cnt <= k;
    }
    
    int solve(vector<int> &arr, int k, int l, int r) {
        if (l >= r) return l;
        int m = l + (r - l) / 2;
        return canAllocate(arr, k, m) ? solve(arr, k, l, m) : solve(arr, k, m + 1, r);
    }
    
    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;
        return solve(arr, k, *max_element(arr.begin(), arr.end()), 
                     accumulate(arr.begin(), arr.end(), 0));
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log(sum)) - Recursive calls with O(n) feasibility check
* **Auxiliary Space:** 💾 O(log(sum)) - Recursion stack space

### ✅ **Why This Approach?**

* Clean recursive structure for better understanding
* Natural divide and conquer implementation
* Good for educational purposes and interviews

## 📊 **3️⃣ Optimized Single Pass**

### 💡 Algorithm Steps:

1. Combine boundary calculation with binary search setup
2. Use single loop for both sum and max calculation
3. Inline feasibility check to reduce function call overhead
4. Early termination when exact allocation found

```cpp
class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;
        
        int l = 0, r = 0;
        for (int x : arr) l = max(l, x), r += x;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            int cnt = 1, sum = 0;
            bool possible = true;
            
            for (int x : arr) {
                if (sum + x > m) {
                    if (++cnt > k) { possible = false; break; }
                    sum = x;
                } else sum += x;
            }
            
            possible ? r = m : l = m + 1;
        }
        return l;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log(sum)) - Single pass with early termination
* **Auxiliary Space:** 💾 O(1) - Only constant variables used

### ✅ **Why This Approach?**

* Minimal function calls and overhead
* Early termination for better average case
* Combines multiple operations in single pass

## 📊 **4️⃣ Template-Based Binary Search**

### 💡 Algorithm Steps:

1. Use standard binary search template for consistency
2. Define clear search predicate function
3. Maintain invariant: left is always feasible, right is always infeasible
4. Return left as the minimum feasible allocation

```cpp
class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;
        
        auto feasible = [&](int limit) {
            int students = 1, pages = 0;
            for (int book : arr) {
                if (pages + book > limit) students++, pages = book;
                else pages += book;
            }
            return students <= k;
        };
        
        int left = *max_element(arr.begin(), arr.end()) - 1;
        int right = accumulate(arr.begin(), arr.end(), 0) + 1;
        
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            (feasible(mid) ? right : left) = mid;
        }
        return right;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log(sum)) - Standard binary search pattern
* **Auxiliary Space:** 💾 O(1) - Lambda function with constant space

### ✅ **Why This Approach?**

* Follows standard competitive programming template
* Less prone to off-by-one errors
* Clean separation of search logic and feasibility check

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Iterative Binary Search**    | 🟢 O(n log(sum))       | 🟢 O(1)                 | 🚀 Most efficient                 | 🔧 Requires careful implementation    |
| 🔍 **Recursive Approach**         | 🟢 O(n log(sum))       | 🟡 O(log(sum))          | 📖 Clean recursive structure      | 💾 Extra stack space                 |
| 📊 **Single Pass Optimized**      | 🟢 O(n log(sum))       | 🟢 O(1)                 | 🎯 Early termination              | 🔧 Complex inline logic              |
| 🔄 **Template-Based**             | 🟢 O(n log(sum))       | 🟢 O(1)                 | ⭐ Standard pattern               | 🐌 Slightly more overhead            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive Programming**                        | 🥇 **Iterative Binary Search**       | ★★★★★                     |
| 📖 **Learning/Teaching**                              | 🥈 **Recursive Approach**            | ★★★★☆                     |
| 🔧 **Production Code**                                | 🥉 **Template-Based**                | ★★★★★                     |
| 🎯 **Interview Optimization**                         | 🏅 **Single Pass Optimized**         | ★★★★☆                     |

</details>


## **☕ Code (Java)**

```java
class Solution {
    public int findPages(int[] arr, int k) {
        if (k > arr.length) return -1;
        int l = arr[0], r = 0;
        for (int x : arr) {
            l = Math.max(l, x);
            r += x;
        }
        while (l < r) {
            int m = l + (r - l) / 2;
            int s = 1, p = 0;
            for (int x : arr) {
                if (p + x > m) { s++; p = x; }
                else p += x;
            }
            if (s <= k) r = m;
            else l = m + 1;
        }
        return l;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findPages(self, arr, k):
        if k > len(arr): return -1
        l, r = max(arr), sum(arr)
        while l < r:
            m = (l + r) // 2
            s, p = 1, 0
            for x in arr:
                if p + x > m: s, p = s + 1, x
                else: p += x
            r, l = (m, l) if s <= k else (r, m + 1)
        return l
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
