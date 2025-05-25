# *25. Pythagorean Triplet*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1)

## **🧩 Problem Description**

Given an integer array `arr[]`, determine if there exists a triplet `(a, b, c)` in the array such that they satisfy the Pythagorean condition:

$$
a^2 + b^2 = c^2
$$

where `a`, `b`, and `c` are elements at different indices of the array.

## **📘 Examples**

### **Example 1:**

#### **Input:**

`arr = [3, 2, 4, 6, 5]`

#### **Output:**

`true`

#### **Explanation:**

The triplet `(3, 4, 5)` satisfies $3^2 + 4^2 = 5^2$.

### **Example 2:**

#### **Input:**

`arr = [3, 8, 5]`

#### **Output:**

`false`

#### **Explanation:**

No triplet satisfies the Pythagorean condition.

### **Example 3:**

#### **Input:**

`arr = [1, 1, 1]`

#### **Output:**

`false`

#### **Explanation:**

No such triplet possible.

## **🔒 Constraints**

* $1 \leq \text{arr.size()} \leq 10^5$
* $1 \leq \text{arr}[i] \leq 10^3$


## **✅ My Approach**

### **Using Hash Set of Squares**

To efficiently check for the Pythagorean triplet, we use the following insight:

* If $a^2 + b^2 = c^2$, then $c^2$ must be present in the array.
* We can precompute the squares of all elements and store them in a hash set.
* Then, iterate over all pairs $(a, b)$ in the array, compute $a^2 + b^2$, and check if this sum exists in the set.

### **Algorithm Steps:**

1. Create a hash set `squares` that contains the square of every element in `arr`.
2. Iterate over all pairs `(arr[i], arr[j])` where `i < j`.
3. For each pair, calculate `sum_squares = arr[i]^2 + arr[j]^2`.
4. Check if `sum_squares` exists in `squares`.

   * If yes, return `true` immediately.
5. If no such triplet is found after checking all pairs, return `false`.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n²), since we check all pairs `(i, j)` of elements in the array.
* **Expected Auxiliary Space Complexity:** O(n), as we store squares of all elements in a hash set.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        unordered_set<int> s;
        for (int& x : arr) s.insert(x * x);
        for (int i = 0; i < arr.size(); ++i)
            for (int j = i + 1; j < arr.size(); ++j)
                if (s.count(arr[i]*arr[i] + arr[j]*arr[j])) return true;
        return false;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approach</h2></summary>


## 📊 **2️⃣ Frequency Array & Math (O(k²))**

Use a fixed-size frequency array (max value ≤1000) and check `c = √(a²+b²)`.

### **Algorithm Steps:**

1. Build `freq[1001]` for counts of each value.
2. Collect sorted `unique_nums` where `freq[x] > 0`.
3. For each `i ≤ j` in `unique_nums`:

   * Compute `c2 = a*a + b*b`, `c = round(sqrt(c2))`.
   * If `c ≤ 1000`, `c*c == c2`, and `freq[c] > 0`, validate counts:

     * If all three equal, `freq[a] ≥ 3`.
     * If two equal, those freq≥2.
     * Else all distinct.
   * Return `true` if valid.
4. Return `false`.

```cpp
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        int freq[1001] = {0};
        for(int x: arr) freq[x]++;
        vector<int> u;
        for(int i=1;i<=1000;++i) if(freq[i]) u.push_back(i);
        int m = u.size();
        for(int i=0;i<m;++i) for(int j=i;j<m;++j) {
            int a=u[i], b=u[j], c2=a*a + b*b;
            int c = int(round(sqrt(c2)));
            if(c>1000 || c*c!=c2 || freq[c]==0) continue;
            if(a==b && b==c && freq[a]>=3) return true;
            if(a==b && freq[a]>=2 && freq[c]>=1 && c!=a) return true;
            if(a==c && freq[a]>=2 && freq[b]>=1 && b!=a) return true;
            if(b==c && freq[b]>=2 && freq[a]>=1 && a!=b) return true;
            if(a!=b && b!=c && a!=c) return true;
        }
        return false;
    }
};
```

### ✅ **Why This Approach?**

* Exploits small value range for O(1) existence checks.
* Ensures correct index‐distinctness via frequency validation.

#### 📝 **Complexity Analysis:**

* **Time:** O(k²), k ≤ 1000 unique values → worst \~10⁶ operations.
* **Auxiliary Space:** O(1) (fixed array of size 1001).



## 🆚 **Comparison of Approaches**

| **Approach**                | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                                  | ⚠️ **Cons**                        |
| --------------------------- | ----------- | ------------- | ------------------------------------------- | ---------------------------------- |
| 🔢 Hash Set of Squares      | 🟢 O(n²)    | 🟢 O(n)       | Simple, single pass, O(1) lookups           | Extra hash memory                  |
| ⚙️ Frequency Array & Math   | 🟢 O(k²)    | 🟢 O(1)       | Constant extra space, leverages constraints | Only works when max(arr\[i]) small |


### ✅ **Best Choice by Scenario**

| **Scenario**                              | **Recommended Approach**              |
|-------------------------------------------|-------------------------------------|
| 🏆 Fastest solution for large or generic input   | 🥇 Hash Set of Squares (One-Pass DP) |
| 🔧 Optimized for small value ranges with O(1) space | 🥈 Frequency Array & Math            |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public boolean pythagoreanTriplet(int[] arr) {
        HashSet<Integer> squares = new HashSet<>();
        for (int x : arr) squares.add(x * x);
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (squares.contains(arr[i]*arr[i] + arr[j]*arr[j])) return true;
        return false;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def pythagoreanTriplet(self, arr):
        s = set(x * x for x in arr)
        n = len(arr)
        for i in range(n):
            for j in range(i + 1, n):
                if arr[i]**2 + arr[j]**2 in s:
                    return True
        return False
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
