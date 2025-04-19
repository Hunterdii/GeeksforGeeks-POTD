---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Bit Magic
  - Tries
---

# 🚀 _Day 2. Maximum XOR of two numbers in an array_ 🧠


The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tries-gfg-160/problem/maximum-xor-of-two-numbers-in-an-array)  

## 💡 **Problem Description:**

Given an array `arr[]` of **non-negative integers**, your task is to find the **maximum XOR** value that can be obtained by XORing any two distinct elements of the array.


## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**
`arr[] = [25, 10, 2, 8, 5, 3]`

#### **Output:**  
`28`

#### **Explanation:**  
The pair `(25 ^ 5)` gives the maximum XOR value which is `28`.


### **Example 2:**

#### **Input:**
`arr[] = [1, 2, 3, 4, 5, 6, 7]`

#### **Output:**  
`7`

#### **Explanation:**  
The pair `(1 ^ 6)` gives the maximum XOR value which is `7`.


### **Constraints:**  
- $\(2 \leq \text{arr.size()} \leq 5 \times 10^4\)$  
- $\(1 \leq \text{arr[i]} \leq 10^6\)$  


## 🎯 **My Approach:**

### **Greedy Bitmasking with HashSet**
1. Iterate from **MSB to LSB** (31 to 0).
2. At each bit position:
   - Mask numbers to keep the current prefix.
   - Try setting the current bit in the result.
   - Use a set to check if there's a pair that can form this potential result.
3. This way, we **greedily try to set each bit** from left to right, ensuring it's possible.


### **Algorithm Steps:**
1. Initialize `max_xor = 0` and `mask = 0`.
2. Loop over 31 bits from high to low.
3. For each bit:
   - Add the bit to the `mask`.
   - Store all prefixes using the current mask.
   - Try setting the bit in `max_xor`, and see if two prefixes exist that form it.
4. If yes, update `max_xor`.


## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(32 × N), where N is the size of the array. We iterate through 32 bits and for each bit, we traverse the entire array once.
- **Expected Auxiliary Space Complexity:** O(N), used to store prefixes in a hash set at each bit position.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
public:
    int maxXor(vector<int>& a) {
        int max_xor = 0, mask = 0;
        unordered_set<int> s;
        for(int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            s.clear();
            int temp = max_xor | (1 << i);
            for(int num : a) {
                int prefix = num & mask;
                if(s.count(temp ^ prefix)) { max_xor = temp; break; }
                s.insert(prefix);
            }
        }
        return max_xor;
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Trie-based Optimal**

### **Algorithm Steps:**
1. **Build a Trie** to store binary representations of numbers (MSB to LSB).
2. **Insert all numbers** into the Trie bit by bit.
3. **Query each number** against the Trie to find the maximum possible XOR by choosing opposite bits greedily.

```cpp
class Solution {
    struct T { T* c[2]{}; } *r = new T;
    void i(int x) {
        T* n = r;
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (!n->c[b]) n->c[b] = new T;
            n = n->c[b];
        }
    }
    int q(int x) {
        T* n = r;
        int m = 0;
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (n->c[1 - b]) m |= 1 << i, n = n->c[1 - b];
            else n = n->c[b];
        }
        return m;
    }
public:
    int maxXor(vector<int>& a) {
        for (int x : a) i(x);
        int res = 0;
        for (int x : a) res = max(res, q(x));
        return res;
    }
};
```


#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(32n)`  
- **Space Complexity:** `O(32n)` (Trie storage)

#### ✅ **Why This Approach?**
Optimal for large datasets. Uses bitwise Trie to efficiently compute maximum XOR in linear time.


## 📊 **3️⃣ Brute-force (Check All Pairs)**

#### **Algorithm Steps:**
1. Check all possible pairs of elements.
2. Compute XOR for each pair and track the maximum.

```cpp
class Solution {
public:
    int maxXor(vector<int>& a) {
        int max_val = 0;
        for(int i = 0; i < a.size(); i++)
            for(int j = i + 1; j < a.size(); j++)
                max_val = max(max_val, a[i] ^ a[j]);
        return max_val;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(n²)`  
- **Space Complexity:** `O(1)`

#### ✅ **Why This Approach?**
Simple to implement for small arrays. Avoids complex data structures.

> **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs _(fails ~30/1140 test cases due to time constraints)_.



### 🆚 **Comparison of Approaches**

| **Approach**       | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                | ⚠️ **Cons**                |
|---------------------|-------------------------|--------------------------|----------------------------|----------------------------|
| **Bitmask Greedy**  | 🟢 `O(31n)`                | 🟡 `O(n)`                   | Balanced speed & memory    | Complex bit manipulation   |
| **Trie-based**      | 🟢 `O(32n)`                | 🟡 `O(32n)`                | Optimal for large datasets | Higher memory usage        |
| **Brute-force**     | 🔴 `O(n²)`                 | 🟢 `O(1)`                   | Simple implementation      | **TLE for large inputs** Impractical for large `n`  |

✅ **Best Choice?**
- **Large Arrays:** Use **Bitmask Greedy** or **Trie-based**.
- **Small Arrays (n ≤ 1e3):** **Brute-force** is acceptable.

</details>

## **Code (Java)**

```java
class Solution {
    public int maxXor(int[] arr) {
        int maxXor = 0, mask = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            set.clear();
            int temp = maxXor | (1 << i);
            boolean found = false;
            for (int num : arr) {
                int prefix = num & mask;
                if (set.contains(temp ^ prefix)) {
                    found = true;
                    break;
                }
                set.add(prefix);
            }
            if (found) maxXor = temp;
        }
        return maxXor;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def maxXor(self, arr):
        max_xor, mask = 0, 0
        for i in range(30, -1, -1):
            mask |= (1 << i)
            prefixes = set()
            temp = max_xor | (1 << i)
            found = False
            for num in arr:
                prefix = num & mask
                if (temp ^ prefix) in prefixes:
                    found = True
                    break
                prefixes.add(prefix)
            if found:
                max_xor = temp
        return max_xor
```


## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
