---
title: "🔢 XOR Pairs less than K | GFG Solution 🔍"
keywords🏷️: ["🔢 XOR pairs", "🌳 trie", "⚡ bit manipulation", "📊 counting pairs", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Count Pairs with XOR Less Than K problem: efficiently count pairs whose XOR is less than k using Binary Trie data structure. 🚀"
date: 📅 2025-12-01
---

# *01. XOR Pairs less than K*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-pairs-having-bitwise-xor-less-than-k/1)

## **🧩 Problem Description**

Given an array `arr[]` and an integer `k`, count the number of pairs from the array such that the **Bitwise XOR** of each pair is **less than k**.

A pair (i, j) is valid if `i < j` and `arr[i] ^ arr[j] < k`.

## **📘 Examples**

### Example 1

```cpp
Input: arr = [1, 2, 3, 5], k = 5
Output: 4
Explanation: Valid pairs with XOR < 5:
1 ^ 2 = 3
1 ^ 3 = 2
1 ^ 5 = 4
2 ^ 3 = 1
Total = 4 pairs
```

### Example 2

```cpp
Input: arr[] = [3, 5, 6, 8], k = 7
Output: 3
Explanation: Valid pairs with XOR < 7:
3 ^ 5 = 6
3 ^ 6 = 5
5 ^ 6 = 3
Total = 3 pairs
```

## **🔒 Constraints**

* $1 \le \text{arr.size()}, k \le 5 \times 10^4$
* $1 \le \text{arr}[i] \le 5 \times 10^4$

## **✅ My Approach**

The optimal solution uses a **Binary Trie** data structure to efficiently count XOR pairs:

### **Binary Trie Approach**

1. **Trie Structure:**
   * Build a binary trie where each node represents a bit (0 or 1).
   * Store 32-bit representation of numbers from MSB to LSB.
   * Each node maintains a count of numbers passing through it.

2. **Query Operation:**
   * For each element, traverse the trie to count existing numbers whose XOR is less than k.
   * At each bit position, compare bits of current number, k, and trie path.
   * If k's bit is 1, we can take the path that makes XOR smaller and count those numbers.
   * If k's bit is 0, we must follow the exact path to keep XOR minimal.

3. **Insertion:**
   * After counting pairs for current element, insert it into the trie.
   * This ensures we only count each pair once (avoiding duplicates).

4. **Bit Manipulation Logic:**
   * For bit position i: if `k[i] = 1`, numbers with `XOR[i] = 0` are valid (< k).
   * Count all numbers in the matching branch, then explore the opposite branch.
   * If `k[i] = 0`, only exact matching path keeps XOR < k.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × 32) ≈ O(n), where n is the size of the array. Each element requires traversing a fixed-depth trie of 32 levels (for 32-bit integers), making it effectively linear time.
* **Expected Auxiliary Space Complexity:** O(n × 32) ≈ O(n), for storing the binary trie structure. In worst case, each number creates 32 new nodes, resulting in linear space proportional to the number of elements.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    class T {
    public:
        T* c[2];
        int n;
        T() { c[0] = c[1] = NULL; n = 0; }
    };
    void add(T* r, int v) {
        for (int i = 31; i >= 0; i--) {
            int b = (v >> i) & 1;
            if (!r->c[b]) r->c[b] = new T();
            r->c[b]->n++;
            r = r->c[b];
        }
    }
    int cnt(T* r, int v, int k) {
        int res = 0;
        for (int i = 31; i >= 0 && r; i--) {
            int bv = (v >> i) & 1, bk = (k >> i) & 1;
            if (bk) {
                if (r->c[bv]) res += r->c[bv]->n;
                r = r->c[1 - bv];
            } else r = r->c[bv];
        }
        return res;
    }
    int cntPairs(vector<int>& a, int k) {
        T* r = new T();
        int ans = 0;
        for (int x : a) {
            ans += cnt(r, x, k);
            add(r, x);
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Hash Map Frequency Approach**

### 💡 Algorithm Steps:

1. Use hash map to track XOR frequencies as we iterate.
2. For each element, check previously seen elements for valid XOR pairs.
3. Calculate XOR with all previous elements and count those less than k.
4. Add current element to the frequency map for future iterations.

```cpp
class Solution {
public:
    int cntPairs(vector<int>& a, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int x : a) {
            for (auto& p : m) 
                if ((x ^ p.first) < k) ans += p.second;
            m[x]++;
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested iteration through map for each element
* **Auxiliary Space:** 💾 O(n) - Hash map storage for unique elements

### ✅ **Why This Approach?**

* Simple and intuitive without complex data structures
* Easy to implement and debug
* Good for small input sizes

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1010/1120 test cases due to time constraints).

## 📊 **3️⃣ Brute Force Nested Loop**

### 💡 Algorithm Steps:

1. Use two nested loops to generate all possible pairs.
2. For each pair (i, j) where i < j, calculate XOR value.
3. Check if XOR is less than k and increment counter.
4. Return total count of valid pairs found.

```cpp
class Solution {
public:
    int cntPairs(vector<int>& a, int k) {
        int ans = 0, n = a.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((a[i] ^ a[j]) < k) ans++;
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - All pairs checked explicitly
* **Auxiliary Space:** 💾 O(1) - No extra space needed

### ✅ **Why This Approach?**

* Most straightforward implementation possible
* No data structure overhead
* Perfect for understanding the problem

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1010/1120 test cases due to time constraints).

## 📊 **4️⃣ Optimized Trie with Path Compression**

### 💡 Algorithm Steps:

1. Build trie with 32-bit representation for efficient storage.
2. Use bit manipulation to traverse optimal paths quickly.
3. Count valid pairs by exploiting XOR properties in trie structure.
4. Prune branches early when XOR result exceeds k threshold.

```cpp
class Solution {
public:
    struct Node {
        Node* ch[2] = {};
        int freq = 0;
    };
    void insert(Node* root, int val) {
        for (int i = 31; i >= 0; i--) {
            int bit = (val >> i) & 1;
            if (!root->ch[bit]) root->ch[bit] = new Node();
            root->ch[bit]->freq++;
            root = root->ch[bit];
        }
    }
    int query(Node* root, int val, int k) {
        int count = 0;
        for (int i = 31; i >= 0 && root; i--) {
            int vb = (val >> i) & 1, kb = (k >> i) & 1;
            if (kb) {
                if (root->ch[vb]) count += root->ch[vb]->freq;
                root = root->ch[!vb];
            } else {
                root = root->ch[vb];
            }
        }
        return count;
    }
    int cntPairs(vector<int>& a, int k) {
        Node* root = new Node();
        int result = 0;
        for (int x : a) {
            result += query(root, x, k);
            insert(root, x);
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(32n) ≈ O(n) - Fixed depth trie traversal
* **Auxiliary Space:** 💾 O(32n) ≈ O(n) - Trie storage with optimization

### ✅ **Why This Approach?**

* Best time complexity for large datasets
* Exploits binary XOR properties efficiently
* Industry-standard for XOR range queries

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🌳 **Trie-Based**                 | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Optimal for large n            | 🔧 Complex implementation            |
| 🗺️ **Hash Map**                   | 🟡 O(n²)               | 🟡 O(n)                 | 📖 Moderate complexity            | 🐌 Slower for large inputs           |
| 🔄 **Brute Force**                | 🔴 O(n²)               | 🟢 O(1)                 | 💡 Simplest to code               | 🐌 Not scalable                      |
| ⚡ **Optimized Trie**             | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Best performance               | 🔧 Requires bit manipulation         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Large datasets (n > 10⁵)**                      | 🥇 **Trie-Based**                    | ★★★★★                     |
| 📖 **Quick implementation**                           | 🥈 **Hash Map**                      | ★★★☆☆                     |
| 🔧 **Small inputs (n < 100)**                         | 🥉 **Brute Force**                   | ★★★☆☆                     |
| 🎯 **Competitive programming**                        | 🏅 **Optimized Trie**                | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    class Node {
        Node[] ch = new Node[2];
        int cnt = 0;
    }
    void add(Node r, int v) {
        for (int i = 31; i >= 0; i--) {
            int b = (v >> i) & 1;
            if (r.ch[b] == null) r.ch[b] = new Node();
            r.ch[b].cnt++;
            r = r.ch[b];
        }
    }
    int query(Node r, int v, int k) {
        int res = 0;
        for (int i = 31; i >= 0 && r != null; i--) {
            int bv = (v >> i) & 1, bk = (k >> i) & 1;
            if (bk == 1) {
                if (r.ch[bv] != null) res += r.ch[bv].cnt;
                r = r.ch[1 - bv];
            } else r = r.ch[bv];
        }
        return res;
    }
    public int cntPairs(int[] a, int k) {
        Node r = new Node();
        int ans = 0;
        for (int x : a) {
            ans += query(r, x, k);
            add(r, x);
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    class Node:
        def __init__(self):
            self.ch = [None, None]
            self.cnt = 0
    def add(self, r, v):
        for i in range(31, -1, -1):
            b = (v >> i) & 1
            if not r.ch[b]: r.ch[b] = self.Node()
            r.ch[b].cnt += 1
            r = r.ch[b]
    def query(self, r, v, k):
        res = 0
        for i in range(31, -1, -1):
            if not r: break
            bv, bk = (v >> i) & 1, (k >> i) & 1
            if bk:
                if r.ch[bv]: res += r.ch[bv].cnt
                r = r.ch[1 - bv]
            else: r = r.ch[bv]
        return res
    def cntPairs(self, a, k):
        r = self.Node()
        ans = 0
        for x in a:
            ans += self.query(r, x, k)
            self.add(r, x)
        return ans
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
