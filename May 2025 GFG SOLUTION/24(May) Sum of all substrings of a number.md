# *24. Sum of All Substrings of a Number*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1)


## **🧩 Problem Description**

Given a string `s` representing an integer number, return the **sum of all possible substrings** of this string interpreted as integers.

Each substring is formed by selecting a continuous sequence of characters from the original string. You must return the **sum of all such substrings**.

💡 The number may contain **leading zeros** and the result will always fit in a **32-bit signed integer**.


## **📘 Examples**

### **Example 1:**

#### **Input:**

`s = "6759"`

#### **Output:**

`8421`

#### **Explanation:**

Substrings: `6`, `7`, `5`, `9`, `67`, `75`, `59`, `675`, `759`, `6759`

Sum = `6 + 7 + 5 + 9 + 67 + 75 + 59 + 675 + 759 + 6759 = 8421`


### **Example 2:**

#### **Input:**

`s = "421"`

#### **Output:**

`491`

#### **Explanation:**

Substrings: `4`, `2`, `1`, `42`, `21`, `421`

Sum = `4 + 2 + 1 + 42 + 21 + 421 = 491`


## **🔒 Constraints**

* \$1 \leq |s| \leq 9\$


## **✅ My Approach**

### **One-Pass Dynamic Contribution**

The idea is to use dynamic programming to compute the cumulative contribution of each digit to all substrings ending at its position.

Let `f(i)` be the sum of all substrings ending at index `i`.
Then we observe that:

* `f(0) = int(s[0])`
* `f(i) = f(i-1) * 10 + (i+1) * int(s[i])`

We maintain a running total of the result and update the current contribution using the above formula.


### **Algorithm Steps:**

1. Initialize `res = 0` and `f = 0`
2. Traverse the string from index `0` to `n-1`:

   * Convert `s[i]` to integer and update:
     `f = f * 10 + (i + 1) * digit`
   * Add `f` to the result.
3. Return `res`.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n), as we iterate through the string once and perform constant-time operations at each step.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a fixed number of variables (`res`, `f`, and loop index), regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int sumSubstrings(string &s) {
        long long res=0,f=0;
        for(int i=0;i<s.size();++i){
            f=f*10+(s[i]-'0')*(i+1);
            res+=f;
        }
        return (int)res;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Two-Pointer Accumulation (O(n²))**

Instead of the one-pass DP, build each substring ending at `i` by extending with the current digit:

### **Algorithm Steps:**

1. Initialize `res = 0`.
2. For each ending index `i` from `0` to `n-1`:

   * Let `num = 0`.
   * For `j` from `i` down to `0`:

     * `num = num + (s[j]-'0') * pow(10, i-j)`
     * Add `num` to `res`.
3. Return `res`.

```cpp
class Solution {
  public:
    int sumSubstrings(string &s) {
        long long res=0;
        for(int i=0;i<s.size();++i){
            long long num=0, p=1;
            for(int j=i;j>=0;--j){
                num += (s[j]-'0') * p;
                p *= 10;
                res += num;
            }
        }
        return (int)res;
    }
};
```

### ✅ **Why This Approach?**

* Simpler to visualize each substring build-up.
* No extra DP array or variables beyond local ones.

#### 📝 **Complexity Analysis:**

* **Time:** O(n²) — due to nested iteration.
* **Auxiliary Space:** O(1) — no additional memory used.


## 📊 **3️⃣ Brute-Force Substrings (O(n³))**

Generate every substring, convert to integer, and sum:

### **Algorithm Steps:**

1. Initialize `res = 0`.
2. For each start `i` and end `j` (`i ≤ j`):

   * Extract substring `s.substr(i, j-i+1)`.
   * Convert to integer and add to `res`.
3. Return `res`.

```cpp
class Solution {
  public:
    int sumSubstrings(string &s) {
        long long res=0;
        for(int i=0;i<s.size();++i)
            for(int j=i;j<s.size();++j)
                res += stoll(s.substr(i,j-i+1));
        return (int)res;
    }
};
```

### ✅ **Why This Approach?**

* Direct and trivial implementation.
* Useful for validating small inputs during testing.

#### 📝 **Complexity Analysis:**

* **Time:** O(n³) — triple nested work due to substring creation and conversion.
* **Auxiliary Space:** O(n) per substring.

## 🆚 **Comparison of Approaches**

| **Approach**                 | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                            | ⚠️ **Cons**                        |
| ---------------------------- | ----------- | ------------- | ------------------------------------- | ---------------------------------- |
| 🥇 **One-Pass DP**           | 🟡 O(n)     | 🟢 O(1)       | Fastest, minimal memory               | Requires insight into contribution |
| ➡️ **Accumulation (nested)** | 🔶 O(n²)    | 🟢 O(1)       | Easy to understand substring build-up | Slower for large `n`               |
| 🔁 **Brute-Force**           | 🔴 O(n³)    | 🔶 O(n)       | Simplest conceptual method            | Impractical beyond small `n`       |

### ✅ **Best Choice by Scenario**

| **Scenario**                      | **Recommended Approach** |
| --------------------------------- | ------------------------ |
| 🏆 Fastest solution for any valid input    | 🥇 One-Pass DP           |
| 📚 Educational and clear logic         | 🥈 Accumulation with Powers |
| 🧪 Debugging or verifying small cases | 🥉 Brute Force Substrings          |


</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public static int sumSubstrings(String s) {
        long res=0,f=0;
        for(int i=0;i<s.length();++i){
            f=f*10+(s.charAt(i)-'0')*(i+1);
            res+=f;
        }
        return (int)res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def sumSubstrings(self,s):
        res=f=0
        for i,ch in enumerate(s):
            f=f*10+int(ch)*(i+1)
            res+=f
        return res
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
