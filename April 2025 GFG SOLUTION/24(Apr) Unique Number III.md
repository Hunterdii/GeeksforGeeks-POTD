
# *24. Unique Number III*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1)


## **🧩 Problem Description**

Given an array `arr[]` where every element occurs **thrice** except one element which occurs **only once**, your task is to find that unique element.


## **📘 Examples**

### **Example 1:**

#### **Input:**
`arr[] = [1, 10, 1, 1]`

#### **Output:**
`10`

#### **Explanation:**
All numbers except `10` occur three times. Hence, the answer is `10`.


### **Example 2:**

#### **Input:**
`arr[] = [3, 2, 1, 34, 34, 1, 2, 34, 2, 1]`

#### **Output:**
`3`

#### **Explanation:**
Only `3` occurs once. All other numbers appear exactly three times.


### **🔒 Constraints**

- $\( 1 \leq \text{arr.size()} \leq 10^5 \)$  
- $\( \text{arr.size()}$ \% 3 = 1 \)
- $\( -10^9 \leq \text{arr[i]} \leq 10^9 \)$

## **✅ My Approach:**

### **Optimized Bitwise Counting**

This method uses **bitwise manipulation** to keep track of bits appearing once, twice, and thrice across the array.

### **Algorithm Steps:**
1. Initialize two variables `ones` and `twos` to 0.  
2. For each element:
   - Update `ones` as: `(ones ^ num) & ~twos`
   - Update `twos` as: `(twos ^ num) & ~ones`
3. After the loop, `ones` will hold the element that appears only once.


## **🧮 Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), since we iterate once through the array.  
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant number of variables.


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int ones = 0, twos = 0;
        for (int num : arr) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Hash Map Frequency Count**

### **Algorithm Steps:**
1. Traverse the array and record each number’s count in an `unordered_map`.  
2. Iterate over the map and return the key with frequency = 1.

```cpp
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int x : arr) freq[x]++;
        for (auto &p : freq)
            if (p.second == 1) 
                return p.first;
        return 0;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time:** O(n)  
- **Space:** O(n)  

#### ✅ **Why This Approach?**
- Straightforward to implement  
- Handles any distribution of frequencies, not limited to exactly three repeats  


## 📊 **3️⃣ Sorting and Scan**

### **Algorithm Steps:**
1. Sort the array.  
2. Scan with index `i` from 0 to n−1 in steps of 3:  
   - If `arr[i] == arr[i+1] == arr[i+2]`, skip these three (`i += 3`);  
   - Else, return `arr[i]`.  
3. If loop ends, the last element is the single one.

```cpp
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), i = 0;
        while (i + 2 < n) {
            if (arr[i] == arr[i+1] && arr[i] == arr[i+2])
                i += 3;
            else
                return arr[i];
        }
        return arr[n-1];
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time:** O(n log n)  
- **Space:** O(1) (in-place sort)  

#### ✅ **Why This Approach?**
- No extra data structures beyond sorting  
- Intuitive when you can afford the sort overhead  


### 🆚 **Comparison of Approaches**

| **Approach**           | ⏱️ **Time**   | 🗂️ **Space** | ✅ **Pros**                     | ⚠️ **Cons**                    |
|------------------------|---------------|--------------|---------------------------------|--------------------------------|
| **Bitwise Counting**   | 🟢 O(n)          | 🟢 O(1)         | Fastest, constant space         | Bitwise logic can be tricky    |
| **Hash Map Frequency** | 🟢 O(n)          | 🔴 O(n)         | Easiest to implement            | Extra memory for map           |
| **Sorting + Scan**     | 🔴 O(n log n)    | 🟢 O(1)         | No extra DS (in-place)          | Slower due to sort             |


### ✅ **Best Choice?**

| **Scenario**                                              | **Recommended Approach**     |
|-----------------------------------------------------------|------------------------------|
| ✅ Exactly one unique, rest appear thrice                  | 🥇 Bitwise Counting          |
| ✅ Quick implementation, input size moderate               | 🥈 Hash Map Frequency        |
| ✅ Memory very tight, sorting overhead acceptable          | 🥉 Sorting + Scan            |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int getSingle(int[] arr) {
        int ones = 0, twos = 0;
        for (int num : arr) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def getSingle(self, arr):
        ones = twos = 0
        for num in arr:
            ones = (ones ^ num) & ~twos
            twos = (twos ^ num) & ~ones
        return ones
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐


<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
