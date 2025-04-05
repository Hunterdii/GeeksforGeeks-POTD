---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Mathematical
  - Hash
---

# 🚀 _Day 5. Union of Arrays with Duplicates_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/union-of-two-arrays3538)

## 💡 **Problem Description:**

You are given two arrays `a[]` and `b[]`. The task is to find the number of distinct elements in the union of the two arrays.

The **Union** of two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, only one occurrence of the element is considered.

## 🔍 **Example Walkthrough:**

**Input:**  
`a[] = [1, 2, 3, 4, 5]`  
`b[] = [1, 2, 3]`  
**Output:**  
`5`  
**Explanation:**  
The union set of both arrays is `{1, 2, 3, 4, 5}`. The count of distinct elements is `5`.

**Input:**  
`a[] = [85, 25, 1, 32, 54, 6]`  
`b[] = [85, 2]`  
**Output:**  
`7`  
**Explanation:**  
The union set of both arrays is `{85, 25, 1, 32, 54, 6, 2}`. The count of distinct elements is `7`.

**Input:**  
`a[] = [1, 2, 1, 1, 2]`  
`b[] = [2, 2, 1, 2, 1]`  
**Output:**  
`2`  
**Explanation:**  
The union set of both arrays is `{1, 2}`. The count of distinct elements is `2`.

## Constraints

- $`1 ≤ a.size(), b.size() ≤ 10^6`$
- $`0 ≤ a[i], b[i] ≤ 10^5`$

## 🎯 **My Approach:**

### **Efficient Approach Using Hashing**

1. **Key Idea**: Use a hash set to automatically store unique elements from both arrays.
2. **Steps**:
   - Insert all elements from the first array `a[]` into the hash set.
   - Insert all elements from the second array `b[]` into the hash set.
   - The size of the hash set gives the total number of distinct elements in the union.
3. This approach is efficient because:
   - Insertion into a hash set is **O(1)** on average.
   - By directly storing unique elements, the problem of duplicates is handled efficiently.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(a.size() + b.size())

  - Traversing each array once and inserting into the hash set takes linear time proportional to the size of the arrays.

- **Expected Auxiliary Space Complexity:** O(a.size() + b.size())
  - The hash set can hold up to `a.size() + b.size()` distinct elements in the worst case.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    int findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> s(a.begin(), a.end());
        s.insert(b.begin(), b.end());
        return s.size();
    }
};
```

## Code (Java)

```java
class Solution {
    public static int findUnion(int[] a, int[] b) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : a) set.add(num);
        for (int num : b) set.add(num);
        return set.size();
    }
}
```

## Code (Python)

```python
class Solution:
    def findUnion(self, a, b):
        return len(set(a).union(b))
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
