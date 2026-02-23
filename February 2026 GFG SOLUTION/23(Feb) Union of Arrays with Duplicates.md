---
title: "🔗 Union of Arrays with Duplicates | GFG Solution 🎯"
keywords🏷️: ["🔗 array union", "🔍 set operations", "📊 deduplication", "📈 merge arrays", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Union of Arrays with Duplicates: find all distinct elements from two arrays using efficient set-based or sorting techniques. 🚀"
date: 📅 2025-02-23
---

# *23. Union of Arrays with Duplicates*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1)

## **🧩 Problem Description**

You are given two arrays `a[]` and `b[]`, return the **Union** of both the arrays in any order.

The Union of two arrays is a collection of all **distinct elements** present in either of the arrays. If an element appears more than once in one or both arrays, it should be included only once in the result.

**Note:** Elements of `a[]` and `b[]` are not necessarily distinct. You can return the Union in any order but the driver code will print the result in sorted order only.

## **📘 Examples**

### Example 1

```cpp
Input: a[] = [1, 2, 3, 2, 1], b[] = [3, 2, 2, 3, 3, 2]
Output: [1, 2, 3]
Explanation: Union set of both the arrays will be 1, 2 and 3.
```

### Example 2

```cpp
Input: a[] = [1, 2, 3], b[] = [4, 5, 6]
Output: [1, 2, 3, 4, 5, 6]
Explanation: Union set of both the arrays will be 1, 2, 3, 4, 5 and 6.
```

### Example 3

```cpp
Input: a[] = [1, 2, 1, 1, 2], b[] = [2, 2, 1, 2, 1]
Output: [1, 2]
Explanation: Union set of both the arrays will be 1 and 2.
```

## **🔒 Constraints**

* $1 \le \text{a.size()}, \text{b.size()} \le 10^6$
* $0 \le \text{a}[i], \text{b}[i] \le 10^5$

## **✅ My Approach**

The optimal solution uses **Merge and Sort with Deduplication**:

### **Merge + Sort + Unique**

1. **Merge Arrays:**
   * Combine both arrays into a single array.
   * This preserves all elements from both sources.

2. **Sort Combined Array:**
   * Sort the merged array to group duplicate elements together.
   * Sorting brings identical elements adjacent to each other.

3. **Remove Duplicates:**
   * Use two-pointer or set to eliminate consecutive duplicates.
   * In C++, use `unique()` algorithm which removes consecutive duplicates.

4. **Return Result:**
   * The resulting array contains all distinct elements from both arrays.

**Key Advantage:** This approach is straightforward and leverages standard library functions for efficiency. While it requires sorting (O(n log n)), it's cache-friendly and has good practical performance.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O((n + m) log(n + m)), where n and m are the sizes of the two arrays. Merging takes O(n + m), sorting the combined array takes O((n + m) log(n + m)), and removing duplicates takes O(n + m). The sorting operation dominates the overall complexity.
* **Expected Auxiliary Space Complexity:** O(n + m), as we create a new array to store the merged elements from both input arrays. The space required is proportional to the total number of elements.

## **🧑‍💻 Code (C)**

```c
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int* findUnion(int* a, int n, int* b, int m, int* returnSize) {
    int* res = (int*)malloc((n + m) * sizeof(int));
    int k = 0;
    for (int i = 0; i < n; i++) res[k++] = a[i];
    for (int i = 0; i < m; i++) res[k++] = b[i];
    qsort(res, k, sizeof(int), cmp);
    int j = 0;
    for (int i = 1; i < k; i++) {
        if (res[i] != res[j]) res[++j] = res[i];
    }
    *returnSize = j + 1;
    return res;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        vector<int> res(a.begin(), a.end());
        res.insert(res.end(), b.begin(), b.end());
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Set-Based Approach**

### 💡 Algorithm Steps:

1. Create an unordered set to store unique elements.
2. Insert all elements from first array into the set.
3. Insert all elements from second array into the set.
4. Convert set back to vector and return.

```cpp
class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> st;
        for (int x : a) st.insert(x);
        for (int x : b) st.insert(x);
        return vector<int>(st.begin(), st.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + m) - Linear insertion for both arrays
* **Auxiliary Space:** 💾 O(n + m) - Set storage in worst case

### ✅ **Why This Approach?**

* Optimal time complexity with linear performance
* Automatic deduplication via set properties
* Simple and clean implementation

## 📊 **3️⃣ TreeSet (Ordered Set) Approach**

### 💡 Algorithm Steps:

1. Use ordered set (TreeSet in Java, set in C++) for automatic sorting.
2. Insert all elements from both arrays.
3. The set maintains elements in sorted order and removes duplicates.
4. Convert to array/list and return.

```cpp
class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int> s;
        for (int x : a) s.insert(x);
        for (int x : b) s.insert(x);
        return vector<int>(s.begin(), s.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O((n + m) log(n + m)) - Set insertion with log factor
* **Auxiliary Space:** 💾 O(n + m) - Set storage

### ✅ **Why This Approach?**

* Result is automatically sorted
* Clean single data structure usage
* Predictable performance characteristics

## 📊 **4️⃣ Frequency Map Approach**

### 💡 Algorithm Steps:

1. Use hash map to track which elements have been seen.
2. Iterate through first array, mark elements as seen.
3. Iterate through second array, mark new elements.
4. Collect all marked elements into result vector.

```cpp
class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_map<int, bool> mp;
        vector<int> res;
        for (int x : a) mp[x] = true;
        for (int x : b) mp[x] = true;
        for (auto& p : mp) res.push_back(p.first);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + m) - Linear traversal with hash operations
* **Auxiliary Space:** 💾 O(n + m) - Map storage

### ✅ **Why This Approach?**

* Similar to set but shows map usage
* Can be extended to track frequencies if needed
* Explicit marking logic

## 📊 **5️⃣ Two-Pointer Merge (Sorted Arrays)**

### 💡 Algorithm Steps:

1. First sort both arrays individually.
2. Use two pointers to merge arrays while avoiding duplicates.
3. Compare elements at both pointers and add smaller unique element.
4. Handle remaining elements from either array.

```cpp
class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                if (res.empty() || res.back() != a[i]) res.push_back(a[i]);
                i++;
            } else if (a[i] > b[j]) {
                if (res.empty() || res.back() != b[j]) res.push_back(b[j]);
                j++;
            } else {
                if (res.empty() || res.back() != a[i]) res.push_back(a[i]);
                i++; j++;
            }
        }
        while (i < a.size()) {
            if (res.empty() || res.back() != a[i]) res.push_back(a[i]);
            i++;
        }
        while (j < b.size()) {
            if (res.empty() || res.back() != b[j]) res.push_back(b[j]);
            j++;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n + m log m) - Sorting both arrays separately
* **Auxiliary Space:** 💾 O(1) - Excluding output array

### ✅ **Why This Approach?**

* Classic merge technique from merge sort
* Space efficient if sorting in-place
* Good for teaching two-pointer patterns

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Merge + Sort + Unique**      | 🟡 O((n+m) log(n+m))   | 🟡 O(n + m)             | 🚀 STL optimized, cache-friendly  | 🔧 Sorting overhead                  |
| 🔍 **Unordered Set**              | 🟢 O(n + m)            | 🟡 O(n + m)             | ⚡ Fastest average case           | 🔧 Unordered output                  |
| 📊 **TreeSet (Ordered)**          | 🟡 O((n+m) log(n+m))   | 🟡 O(n + m)             | 🎯 Sorted output automatically    | 🐌 Log factor per insertion          |
| 🗂️ **Frequency Map**              | 🟢 O(n + m)            | 🟡 O(n + m)             | 🔧 Extensible for frequencies     | 🔧 Similar to set                    |
| 🔄 **Two-Pointer Merge**          | 🟡 O(n log n + m log m)| 🟢 O(1)*               | 💾 Space efficient               | 🔧 Complex duplicate handling        |

*Excluding output array

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Fastest average performance**                    | 🥇 **Unordered Set**                 | ★★★★★                     |
| 📖 **Need sorted output**                             | 🥈 **TreeSet (Ordered)**             | ★★★★★                     |
| 💾 **Memory constrained**                             | 🥉 **Two-Pointer Merge**             | ★★★★☆                     |
| 🎯 **Competitive programming**                        | 🏅 **Merge + Sort + Unique**         | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static ArrayList<Integer> findUnion(int[] a, int[] b) {
        Set<Integer> set = new HashSet<>();
        for (int x : a) set.add(x);
        for (int x : b) set.add(x);
        return new ArrayList<>(set);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:    
    def findUnion(self, a, b):
        return list(set(a) | set(b))
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
