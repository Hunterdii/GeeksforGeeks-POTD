---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Sorting
  - Arrays
---

# 🚀 _Day 2. Find H-Index_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/sorting-gfg-160/problem/find-h-index--165609)

## 💡 **Problem Description:**

You are given an array of integers `citations[]`, where `citations[i]` is the number of citations a researcher received for the `i-th` paper. Your task is to find the H-Index of the researcher.

H-Index is the largest value `H` such that the researcher has at least `H` papers that have been cited at least `H` times.

## 🔍 **Example Walkthrough:**

**Input:**  
`citations[] = [3, 0, 5, 3, 0]`  
**Output:**  
`3`

**Explanation:**  
There are at least 3 papers (with 3, 5, and 3 citations) that have been cited at least 3 times.

**Input:**  
`citations[] = [5, 1, 2, 4, 1]`  
**Output:**  
`2`

**Explanation:**  
There are at least 2 papers (with 5 and 4 citations) that have been cited at least 2 times.

**Input:**  
`citations[] = [0, 0]`  
**Output:**  
`0`

**Explanation:**  
No paper has been cited at least once.

### Constraints:

- $`1 ≤ citations.size() ≤ 10^6`$
- $`0 ≤ citations[i] ≤ 10^6`$

## 🎯 **My Approach:**

1. **Bucket Sort Method:**

   - We create an array `buckets[]` where `buckets[i]` stores the count of papers with exactly `i` citations.
   - If a paper has citations greater than or equal to the number of papers, it is counted in a special `buckets[n]`.
   - After building the bucket, we compute the cumulative count of papers with at least `i` citations to determine the H-Index.

2. **Steps:**
   - Traverse the `citations[]` array to populate the `buckets[]`.
   - Traverse the `buckets[]` array from the back to compute the cumulative counts and find the H-Index.
   - This approach ensures a linear time complexity.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), where `n` is the size of the `citations` array. We perform one traversal to populate the `buckets[]` and another traversal to compute the H-Index.
- **Expected Auxiliary Space Complexity:** O(n), as we use an array of size `n+1` for the bucket sort.

## 📝 **Solution Code**

## Code (C)

```c
int hIndex(int citations[], int citationsSize) {
    int buckets[citationsSize + 1];
    memset(buckets, 0, sizeof(buckets));

    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] >= citationsSize)
            buckets[citationsSize]++;
        else
            buckets[citations[i]]++;
    }

    int cumulative = 0;
    for (int i = citationsSize; i >= 0; i--) {
        cumulative += buckets[i];
        if (cumulative >= i)
            return i;
    }
    return 0;
}
```

## Code (Cpp)

```cpp
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);

        for (int c : citations) {
            if (c >= n)
                buckets[n]++;
            else
                buckets[c]++;
        }

        int cumulative = 0;
        for (int i = n; i >= 0; --i) {
            cumulative += buckets[i];
            if (cumulative >= i)
                return i;
        }
        return 0;
    }
};
```

## Code (Java)

```java
class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        int[] buckets = new int[n + 1];

        for (int c : citations) {
            if (c >= n)
                buckets[n]++;
            else
                buckets[c]++;
        }

        int cumulative = 0;
        for (int i = n; i >= 0; i--) {
            cumulative += buckets[i];
            if (cumulative >= i)
                return i;
        }
        return 0;
    }
}
```

## Code (Python)

```python
class Solution:
    def hIndex(self, citations):
        n = len(citations)
        buckets = [0] * (n + 1)

        for c in citations:
            if c >= n:
                buckets[n] += 1
            else:
                buckets[c] += 1

        cumulative = 0
        for i in range(n, -1, -1):
            cumulative += buckets[i]
            if cumulative >= i:
                return i
        return 0
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
