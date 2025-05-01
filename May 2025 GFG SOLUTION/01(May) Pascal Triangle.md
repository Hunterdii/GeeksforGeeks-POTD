# *1. Pascal Triangle*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/pascal-triangle0652/1)


## **🧩 Problem Description**

Given a positive integer `n`, return the `n`th row of Pascal's Triangle.  
Pascal's Triangle is a triangular array where each element is the sum of the two elements directly above it in the previous row. The `n`th row contains `n` elements indexed from 0 to `n-1`, and follows the binomial coefficient formula:  
&nbsp; &nbsp; **`row[k] = C(n-1, k)`**

<img src="https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif" >

## **📘 Examples**

### **Example 1:**
#### **Input:**  
`n = 4`  
#### **Output:**  
`[1, 3, 3, 1]`  
#### **Explanation:**  
The 4<sup>th</sup> row of Pascal’s Triangle is `[1, 3, 3, 1]`.  

### **Example 2:**
#### **Input:**  
`n = 5`  
#### **Output:**  
`[1, 4, 6, 4, 1]`  
#### **Explanation:**  
The 5<sup>th</sup> row of Pascal’s Triangle is `[1, 4, 6, 4, 1]`.  

### **Example 3:**
#### **Input:**  
`n = 1`  
#### **Output:**  
`[1]`  
#### **Explanation:**  
The 1<sup>st</sup> row of Pascal’s Triangle is `[1]`.  

## **🔒 Constraints**

- $1 \leq n \leq 20$


## **✅ My Approach**

### **Optimized Approach: Direct Binomial Formula**
We use the mathematical identity:  
`C(n, k) = C(n, k - 1) * (n - k + 1) / k` 

$\[
\text{row}[0] = 1,\quad
\text{row}[i] = \text{row}[i-1] \times \frac{n-1 - (i-1)}{i}\quad \text{for } i=1,\dots,n-1
\]$

This builds the row in a single pass, using only integer arithmetic and avoiding overflow when $n\le20$.


### **Algorithm Steps:**

1. Initialize result list `row = []`.
2. Set variable `val = 1` (first element is always 1).
3. For each index `k` from `0` to `n-1`:
   - Append current `val` to `row`.
   - Compute next `val` as: `val = val * (n - 1 - k) / (k + 1)`
4. Return the `row`.


## **🧮 Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), as we compute each of the `n` elements once using constant-time math.
- **Expected Auxiliary Space Complexity:** O(n), as we store exactly `n` integers in the result list.

## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> row(n);
        row[0]=1;
        for(int i=1;i<n;++i) row[i]=row[i-1]*(n-i)/i;
        return row;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Build from Previous Row**

### **Algorithm Steps:**
1. Initialize a vector `prev = {1}`.  
2. For each level `i` from 2 to `n`:
   - Create a new `curr` of size `i`, set `curr[0]=curr[i-1]=1`.
   - For `j` in `[1..i-2]`, `curr[j] = prev[j-1] + prev[j]`.
   - Swap `prev` and `curr`.  
3. Return `prev`.

```cpp
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<int> prev={1}, curr;
        for(int i=2;i<=n;++i){
            curr.assign(i,1);
            for(int j=1;j<i-1;++j) curr[j]=prev[j-1]+prev[j];
            prev.swap(curr);
        }
        return prev;
    }
};
```

### ✅ **Why This Approach?**
- Conceptually simple (direct use of Pascal’s definition).  
- No risk of overflow if values small.

#### 📝 **Complexity Analysis:**
- **Time:** O(n²) (summing up all elements up to row n).  
- **Auxiliary Space:** O(n) (two rows of length ≤ n).


## 📊 **3️⃣ Full Triangle Generation**

### **Algorithm Steps:**
1. Create a 2D vector `T` of size `n × n`, initialize all to 0.
2. Set `T[i][0]=T[i][i]=1` for each row `i`.
3. For each `i` from 2 to `n-1` and `j` from 1 to `i-1`, `T[i][j]=T[i-1][j-1]+T[i-1][j]`.  
4. Return `T[n-1]`.

```cpp
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<vector<int>> T(n, vector<int>(n));
        for(int i=0;i<n;++i){
            T[i][0]=T[i][i]=1;
            for(int j=1;j<i;++j) T[i][j]=T[i-1][j-1]+T[i-1][j];
        }
        return T[n-1];
    }
};
```

### ✅ **Why This Approach?**
- Good for when multiple rows are needed.  
- Directly produces the entire triangle.

#### 📝 **Complexity Analysis:**
- **Time:** O(n²)  
- **Auxiliary Space:** O(n²)


## 📊 **4️⃣ Factorial‐Based Formula**

### **Algorithm Steps:**
1. Precompute factorials `fact[k]` for `k` up to `n-1`.
2. For each `k` in `[0..n-1]`, compute `C(n-1,k) = fact[n-1] / (fact[k]*fact[n-1-k])`.

```cpp
class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        vector<long long> fact(n);
        fact[0]=1;
        for(int i=1;i<n;++i) fact[i]=fact[i-1]*i;
        vector<int> row(n);
        for(int k=0;k<n;++k)
            row[k]=fact[n-1]/(fact[k]*fact[n-1-k]);
        return row;
    }
};
```

### ✅ **Why This Approach?**
- Uses closed‐form combinatorics.  
- If factorials cached, can answer multiple queries very fast.

#### 📝 **Complexity Analysis:**
- **Time:** O(n) for factorial build + O(n) for row → O(n)  
- **Auxiliary Space:** O(n)


## 🆚 **Comparison of Approaches**

| **Approach**                | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                             | ⚠️ **Cons**                           |
|-----------------------------|-------------|--------------|-----------------------------------------|----------------------------------------|
| Direct Binomial Formula     | 🟢 O(n)      | 🟢 O(n)       | Fast, no factorials needed              | Risk of overflow if `n` is large       |
| Build from Previous Row     | 🔸 O(n²)     | 🟢 O(n)       | Intuitive, avoids math operations       | Slower for larger `n`                  |
| Full Triangle Generation    | 🔸 O(n²)     | 🔸 O(n²)      | Useful if full triangle needed          | High memory usage                      |
| Factorial-Based             | 🟢 O(n)      | 🟢 O(n)       | Mathematical, supports batch queries    | Needs extra space and handling overflow|

### ✅ **Best Choice?**

| **Scenario**                             | **Recommended Approach**    |
|------------------------------------------|-----------------------------|
| Single large row, optimal runtime       | 🥇 Direct Formula           |
| Need to inspect multiple rows           | 🥈 Full Triangle Generation |
| Educational/demo purpose                | 🥉 Build from Previous Row  |
| Batch queries with varying n            | 🎖️ Factorial‐Based          |
</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public ArrayList<Integer> nthRowOfPascalTriangle(int n) {
        ArrayList<Integer> row=new ArrayList<>();
        long v=1;
        for(int i=0;i<n;++i){
            row.add((int)v);
            v=v*(n-1-i)/(i+1);
        }
        return row;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def nthRowOfPascalTriangle(self, n):
        row, v = [], 1
        for i in range(n):
            row.append(v)
            v = v * (n-1-i) // (i+1)
        return row
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>


