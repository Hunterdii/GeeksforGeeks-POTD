# *21. Missing in Array*  

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1)  

## **Problem Description**  

You are given an array `arr[]` of size **n - 1** that contains distinct integers in the range from **1 to n** (inclusive).  
The array represents a permutation of numbers from `1` to `n` with **one number missing**. Your task is to **find the missing number**.  

## **Examples**

### **Example 1:**  

#### **Input:**  
arr[] = [1, 2, 3, 5]  

#### **Output:**  
4  

#### **Explanation:**  
All numbers from 1 to 5 should be present. The number **4** is missing.  


### **Example 2:**  

#### **Input:**  
arr[] = [8, 2, 4, 5, 3, 7, 1]  

#### **Output:**  
6  

#### **Explanation:**  
All numbers from 1 to 8 should be present. The number **6** is missing.  


### **Example 3:**  

#### **Input:**  
arr[] = [1]  

#### **Output:**  
2  

#### **Explanation:**  
Only 1 is present, hence the missing number is **2**.  


### **Constraints:**  
- $\(1 \leq \text{arr.size()} \leq 10^6\)$  
- $\(1 \leq \text{arr[i]} \leq \text{arr.size()} + 1\)$  


## **My Approach**

### **Optimal XOR Approach**

This approach relies on properties of XOR:
- **a ⊕ a = 0** and **a ⊕ 0 = a**
- If you XOR all numbers from `1 to n` and all elements in the array, the duplicate numbers cancel each other out, leaving only the missing number.

### **Algorithm Steps:**  
1. Initialize `x = 0`.  
2. XOR all elements of the array with `x`.  
3. XOR all numbers from `1` to `n` with `x`.  
4. The result is the missing number.  


## **Time and Auxiliary Space Complexity**  

- **Expected Time Complexity:** `O(n)`, as we make two passes over the array (XOR and loop from 1 to n).  
- **Expected Auxiliary Space Complexity:** `O(1)`, as we use only a constant amount of additional space.  


## **Code (C)**

```c
int missingNum(int *a, int n){
    int x=0;
    for(int i=0;i<n;++i) x^=a[i]^(i+1);
    return x^(n+1);
}
```

## **Code (C++)**

```cpp
class Solution{
public:
    int missingNum(vector<int>&a){
        int x=0,n=a.size()+1;
        for(int i=0;i<a.size();++i) x^=a[i]^(i+1);
        return x^n;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Sum Formula**

### **Algorithm Steps:**
1. Calculate the expected sum of 1 to `n` using the formula `n*(n+1)/2`.
2. Subtract the sum of the array from it to get the missing number.

```cpp
class Solution {
public:
    int missingNum(vector<int>& a) {
        long long n = a.size() + 1;
        long long total = n * (n + 1) / 2;
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        return total - sum;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

#### ✅ **Why This Approach?**
Simple and intuitive. Effective when integer overflow is handled using `long long`.


## 📊 **3️⃣ Sorting**

### **Algorithm Steps:**
1. Sort the array.
2. Traverse from 1 to `n` and compare values at each index.
3. The first mismatch is the missing number.

```cpp
class Solution {
public:
    int missingNum(vector<int>& a) {
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++)
            if (a[i] != i + 1) return i + 1;
        return a.size() + 1;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(n log n)`
- **Space Complexity:** `O(1)`

#### ✅ **Why This Approach?**
Easy to understand and implement, but not optimal due to the sorting step.


## 📊 **4️⃣ Hashing (Boolean Array)**

### **Algorithm Steps:**
1. Create a boolean array of size `n+1`.
2. Mark visited indices.
3. The index with `false` is the missing number.

```cpp
class Solution {
public:
    int missingNum(vector<int>& a) {
        int n = a.size();
        vector<bool> seen(n + 2, false);
        for (int x : a) seen[x] = true;
        for (int i = 1; i <= n + 1; i++)
            if (!seen[i]) return i;
        return -1;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

#### ✅ **Why This Approach?**
Straightforward and effective. Especially helpful when array contains invalid or repeated values. Useful in debugging.


### 🆚 **Comparison of Approaches**

| **Approach**             | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                          | ⚠️ **Cons**                         |
|-----------------------|-------------|--------------|------------------------------|----------------------------------|
| **XOR Method**        | 🟢 `O(n)`   | 🟢 `O(1)`     | Fastest + no extra memory    | Less intuitive                  |
| **Sum Formula**       | 🟢 `O(n)`   | 🟢 `O(1)`     | Clean math-based             | Needs care with overflow        |
| **Sorting**           | 🔴 `O(n log n)` | 🟢 `O(1)` | Simple logic                 | Slower due to sorting           |
| **Hashing/Boolean**   | 🟢 `O(n)`   | 🔴 `O(n)`     | Easy to read/debug           | Uses extra memory               |

### ✅ **Best Choice?**

| **Scenario**                                           | **Recommended Approach**         |
|--------------------------------------------------------|----------------------------------|
| ✅ **No extra space allowed & optimal runtime needed** | 🥇 **XOR Method**                |
| ✅ **Readable and simple with math knowledge**         | 🥈 **Sum Formula**               |
| ✅ **Array can be modified and performance matters less** | **Sorting**                     |
| ✅ **Clarity and debugging are priorities**            | **Hashing (Boolean Array)**      |

> 🔹 **Overall Best** for **runtime and space**: **XOR Method**  
> 🔹 **Best for clarity**: **Hashing or Sum Formula**

</details>


## **Code (Java)**

```java
class Solution {
    int missingNum(int[] a) {
        int x = 0;
        for (int i = 0; i < a.length; ++i) x ^= a[i] ^ (i + 1);
        return x ^ (a.length + 1);
    }
}
```

## **Code (Python)**

```python
class Solution:
    def missingNum(self, a):
        x = 0
        for i, v in enumerate(a): x ^= v ^ (i + 1)
        return x ^ (len(a) + 1)
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
