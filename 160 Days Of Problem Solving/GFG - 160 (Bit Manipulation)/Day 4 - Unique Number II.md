---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Bit Manipulation
  - Bit Magic
---

# 🚀 _Day 4. Unique Number II_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/finding-the-numbers0215)  

## 💡 **Problem Description:**

Given an array `arr[]` of size **2*N + 2**, where **2*N** elements appear in pairs and **two elements appear only once**, your task is to find those two **distinct unique numbers** and return them in **increasing order**.  

## 🔍 **Example Walkthrough:**

### **Example 1:**  

#### **Input:**  
`arr[] = [1, 2, 3, 2, 1, 4]`  

#### **Output:**  
`[3, 4]`

#### **Explanation:**  
3 and 4 occur exactly once in the array. All other elements appear in pairs.


### **Example 2:**  

#### **Input:**  
`arr[] = [2, 1, 3, 2]`  

#### **Output:**  
`[1, 3]`  

#### **Explanation:**  
1 and 3 occur only once. 2 appears twice.


### **Example 3:**  

#### **Input:**  
`arr[] = [2, 1, 3, 3]`  

#### **Output:**  
`[1, 2]`  

#### **Explanation:**  
1 and 2 occur once. 3 appears twice.


### **Constraints:**  
- $\(2 \leq \text{arr.size()} \leq 10^6\)$  
- $\(1 \leq \text{arr}[i] \leq 5 \times 10^6\)$  
- `arr.size()` is even  


## 🎯 **My Approach:**

### **XOR Partition Method**

This is the most efficient and clever approach using **bit manipulation**.

### **Algorithm Steps:**  
1. XOR all elements → result is XOR of the two unique numbers: `x = a ^ b`.  
2. Find the **rightmost set bit** in `x`.  
3. Partition the array into **two groups** based on this bit.  
4. XOR each group → you get `a` and `b` separately.  
5. Return the numbers in increasing order.


## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(n)`, as we iterate through the array a constant number of times.  
- **Expected Auxiliary Space Complexity:** `O(1)`, as we only use a constant number of variables.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    vector<int> singleNum(vector<int>& A) {
        int x = 0, a = 0, b = 0;
        for (int n : A) x ^= n;
        for (int n : A) (n & (x & -x) ? a : b) ^= n;
        return a < b ? vector<int>{a, b} : vector<int>{b, a};
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Hash Map Frequency Count**

### **Algorithm Steps:**
1. Traverse the array and count frequencies using a hash map.
2. Collect the two numbers that appear exactly once.

```cpp
class Solution {
  public:
    vector<int> singleNum(vector<int>& a) {
        unordered_map<int, int> freq;
        for (int x : a) freq[x]++;
        vector<int> res;
        for (auto it = freq.begin(); it != freq.end(); ++it)
            if (it->second == 1) res.push_back(it->first);
        sort(res.begin(), res.end());
        return res;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(n log n)` (due to final sorting)
- **Space Complexity:** `O(n)`

#### ✅ **Why This Approach?**
Simple and works with generalized inputs — even if frequencies are not exactly two.


## 📊 **3️⃣ Sorting and Pair Skipping**

### **Algorithm Steps:**
1. Sort the array.
2. Compare elements in pairs. Push elements that do not match with their pair.

```cpp
class Solution {
  public:
    vector<int> singleNum(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<int> res;
        int i = 0, n = a.size();
        while (i < n - 1) {
            if (a[i] != a[i + 1]) {
                res.push_back(a[i++]);
            } else {
                i += 2;
            }
        }
        if (res.size() < 2) res.push_back(a[n - 1]);
        sort(res.begin(), res.end());
        return res;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(1)` (excluding result storage)

#### ✅ **Why This Approach?**
No extra data structures used beyond sorting. Best when space is limited.



### 🆚 **Comparison of Approaches**

| **Approach**           | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                          | ⚠️ **Cons**                    |
|------------------------|------------------------|--------------------------|--------------------------------------|-------------------------------|
| **XOR Partition**      | 🟢 `O(n)`              | 🟢 `O(1)`                | Fastest, elegant, minimal space      | Works only with exactly two unique elements |
| **Hash Map Frequency** | 🟢 `O(n)`              | 🔴 `O(n)`                | Simple, handles arbitrary frequencies| More memory used              |
| **Sorting + Pairing**  | 🔴 `O(n log n)`        | 🟢 `O(1)`                | No extra space, good for sorted data | Slower due to sorting         |


### ✅ **Best Choice?**

| **Scenario**                                           | **Recommended Approach**     |
|--------------------------------------------------------|------------------------------|
| ✅ **Exactly 2 unique elements, rest in pairs**        | 🥇 **XOR Partition**         |
| ✅ **Frequencies may vary**                            | 🥈 **Hash Map Frequency**    |
| ✅ **Limited space, sorting is acceptable**            | 🥉 **Sorting + Pair Check**  |

> 🔹 **Overall Best**: **XOR Partition**, optimal in both time and space.  
> 🔹 **Best for flexible scenarios**: **Hash Map**.

</details>

## **Code (Java)**

```java
class Solution {
    public int[] singleNum(int[] arr) {
        int x = 0, a = 0, b = 0;
        for (int n : arr) x ^= n;
        for (int n : arr) if ((n & (x & -x)) != 0) a ^= n; else b ^= n;
        return a < b ? new int[]{a, b} : new int[]{b, a};
    }
}
```

## **Code (Python)**

```python
class Solution:
    def singleNum(self, arr):
        x = 0
        for n in arr: x ^= n
        a = b = 0
        for n in arr:
            (a, b) = (a ^ n, b) if n & (x & -x) else (a, b ^ n)
        return [a, b] if a < b else [b, a]
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
