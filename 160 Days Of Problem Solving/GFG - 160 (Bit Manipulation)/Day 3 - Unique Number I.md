---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Bit Manipulation
  - Bit Magic
---

# 🚀 _Day 3. Unique Number I_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/find-unique-number)


## 💡 **Problem Description:**

You are given an **unsorted array** of positive integers in which **every element occurs exactly twice**, except for **one element that appears only once**. Your task is to **find that unique number**.


## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**
```
arr[] = [1, 2, 1, 5, 5]
```

#### **Output:**
```
2
```

#### **Explanation:**
All elements except **2** occur twice. Hence, the unique number is **2**.


### **Example 2:**

#### **Input:**
```
arr[] = [2, 30, 2, 15, 20, 30, 15]
```

#### **Output:**
```
20
```

#### **Explanation:**
Only **20** appears once. All other elements occur twice.


### **Constraints:**
- $\(1 \leq \text{arr.size()} \leq 10^6\)$  
- $\(0 \leq \text{arr}[i] \leq 10^9\)$


## 🎯 **My Approach:**

### **Bit Manipulation (XOR Method)**

- The **XOR** of two equal numbers is 0.  
- XOR of a number with 0 is the number itself.  
- Thus, XOR-ing all numbers will cancel out the duplicates and leave the unique one.

### **Algorithm Steps:**
1. Initialize result as 0.
2. Iterate over the array and XOR each number with the result.
3. Final result is the unique number.


## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(n)`, as we traverse the array once.  
- **Expected Auxiliary Space Complexity:** `O(1)`, as we only use a constant amount of extra space.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    int findUnique(vector<int> &a) {
        int r = 0;
        for (int x : a) r ^= x;
        return r;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Hash Map Frequency Count**

### **Algorithm Steps:**
1. Traverse the array and store frequencies in a hash map.
2. Return the element with frequency `1`.

```cpp
class Solution {
  public:
    int findUnique(vector<int> &a) {
        unordered_map<int, int> freq;
        for (int x : a) freq[x]++;
        for (auto it = freq.begin(); it != freq.end(); ++it)
            if (it->second == 1) return it->first;
        return -1;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

#### ✅ **Why This Approach?**
Straightforward and useful when duplicates can appear more than twice or in non-pair counts.


## 📊 **3️⃣ Sorting and Pair Check**

### **Algorithm Steps:**
1. Sort the array.
2. Compare elements in pairs. The one not matching its pair is unique.

```cpp
class Solution {
  public:
    int findUnique(vector<int> &a) {
        sort(a.begin(), a.end());
        int i = 0, n = a.size();
        while (i < n - 1) {
            if (a[i] != a[i + 1]) return a[i];
            i += 2;
        }
        return a[n - 1];
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(1)`

#### ✅ **Why This Approach?**
Good when extra space isn’t allowed but we can afford sorting time.


### 🆚 **Comparison of Approaches**

| **Approach**           | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                    |
|------------------------|------------------------|--------------------------|------------------------------------|-------------------------------|
| **XOR Method**         | 🟢 `O(n)`              | 🟢 `O(1)`                | Fastest, minimal space             | Only works with exact pairs   |
| **Hash Map Frequency** | 🟢 `O(n)`              | 🔴 `O(n)`                | Easy to extend to generic cases    | Extra memory used             |
| **Sorting + Pairing**  | 🔴 `O(n log n)`        | 🟢 `O(1)`                | No extra memory, simple comparison | Slower due to sorting         |


### ✅ **Best Choice?**

| **Scenario**                                          | **Recommended Approach**      |
|-------------------------------------------------------|-------------------------------|
| ✅ **Optimal runtime and no extra space**             | 🥇 **XOR Method**             |
| ✅ **Handles non-standard frequencies**               | 🥈 **Hash Map Frequency**     |
| ✅ **Array can be modified and space is a concern**   | **Sorting + Pair Check**      |

> 🔹 **Overall Best** for **performance and space**: **XOR Method**  
> 🔹 **Best for generic input flexibility**: **Hash Map Approach**

</details>

## **Code (Java)**

```java
class Solution {
    public int findUnique(int[] arr) {
        int r = 0;
        for (int x : arr) r ^= x;
        return r;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def findUnique(self, arr):
        r = 0
        for x in arr: r ^= x
        return r
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
