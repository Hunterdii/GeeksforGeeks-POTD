# *14. Look and Say Pattern*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/decode-the-pattern1138/1)

## **🧩 Problem Description**

Given an integer `n`, return the `n`th term in the **Look-and-Say Sequence**, also known as the **Count and Say** sequence.

This sequence is built by describing the previous term in terms of the **count of digits in groups of the same digit**.


### 🔁 **How It Works:**

Start with `"1"` as the first term. To generate each subsequent term:

* Read off the digits of the previous term.
* For each group of consecutive identical digits, state:

  * The number of times it appears (the count),
  * Followed by the digit itself.


### 📚 **Examples of the Sequence:**

```
1           # First term
11          # One 1 → "11"
21          # Two 1s → "21"
1211        # One 2, One 1 → "1211"
111221      # One 1, One 2, Two 1s → "111221"
...
```



## **📘 Examples**

### **Example 1:**

**Input:**
`n = 5`

**Output:**
`111221`

**Explanation:**
The sequence evolves as:
1 → 11 → 21 → 1211 → **111221**



### **Example 2:**

**Input:**
`n = 3`

**Output:**
`21`

**Explanation:**
The third term is:
1 → 11 → **21**



## **🔒 Constraints**

* \$1 \leq n \leq 30\$


## ✅ **My Approach**

### **🧠 Iterative Character Grouping**

We iteratively build each term in the Look-and-Say sequence by scanning the previous term and counting consecutive digits.

#### 🔹 Algorithm Steps:

1. **Initialize** the sequence with the first term as `"1"`.
2. **Repeat** the following process from the 2nd term to the `n`th term:

   * Create an empty string `next_term`.
   * Traverse the current term:

     * Count how many times a digit repeats consecutively.
     * Append the **count** followed by the **digit** to `next_term`.
   * Update the current term to `next_term` for the next iteration.
3. **Return** the final term after `n - 1` transformations.



## **🧮 Time and Auxiliary Space Complexity**

| Metric              | Complexity                                                                                                                              |
| ------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| **Time**            | O(n × L), where `L` is the average length of terms in the sequence. Each of the `n` iterations processes a string with increasing size. |
| **Auxiliary Space** | O(L), used for building the next term at each step.                                                                                     |


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; ++i) {
            string temp;
            for (int j = 0; j < res.size(); ) {
                int k = j;
                while (k < res.size() && res[k] == res[j]) ++k;
                temp += to_string(k - j) + res[j];
                j = k;
            }
            res = temp;
        }
        return res;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ Using `ostringstream` for Cleaner Formatting**

### **💡 Algorithm Steps:**

1. Initialize the result as `"1"`.
2. Repeat the following for `n-1` times:

   * Create an `ostringstream` to build the next sequence.
   * Traverse the current result:

     * Count consecutive identical digits.
     * Append count and digit to the stream.
   * Convert stream to string for the next iteration.

```cpp
class Solution {
  public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i) {
            ostringstream oss;
            int count = 1;
            for (int j = 1; j < result.size(); ++j) {
                if (result[j] == result[j - 1]) {
                    ++count;
                } else {
                    oss << count << result[j - 1];
                    count = 1;
                }
            }
            oss << count << result.back();
            result = oss.str();
        }
        return result;
    }
};
```

### ✅ **Why This Approach?**

* 🧹 Makes code cleaner and more readable.
* 🧵 Uses standard `ostringstream` for better formatting.

#### 📝 **Complexity Analysis:**

* **Time:** O(n × L), where L = average length of result strings.
* **Auxiliary Space:** O(L) per iteration.


## 📊 **3️⃣ Recursive Implementation**

### **💡 Algorithm Steps:**

1. Base case: If `n == 1`, return `"1"`.
2. Recursively get the string for `n - 1`.
3. Traverse that result:

   * Count repeating digits.
   * Build the result string using count and digit.

```cpp
class Solution {
  public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string result;
        for (int i = 0; i < prev.size(); ) {
            int count = 1;
            while (i + count < prev.size() && prev[i + count] == prev[i]) ++count;
            result += to_string(count) + prev[i];
            i += count;
        }
        return result;
    }
};
```

### ✅ **Why This Approach?**

* 🧠 Clear and elegant for recursive thinkers.
* 🎯 Shows the conceptual chain between `n` and `n-1`.

#### 📝 **Complexity Analysis:**

* **Time:** O(n × L)
* **Auxiliary Space:** O(n × L) (due to recursion stack + strings)


## 🆚 **Comparison of Approaches**

| **Approach**                 | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                             | ⚠️ **Cons**                          |
| ---------------------------- | ----------- | ------------- | -------------------------------------- | ------------------------------------ |
| 🧠 Iterative                 | 🟢 O(n × L) | 🟢 O(L)       | Efficient, easy to follow              | Manual string manipulation           |
| 🧵 `ostringstream` version   | 🟢 O(n × L) | 🟢 O(L)       | Cleaner, readable syntax               | Slightly more memory due to stream   |
| 🔁 Recursive version         | 🔸 O(n × L) | 🔸 O(n × L)   | Short, expressive, good for interviews | ⚠️ Stack overflow risk for large `n` |


### ✅ **Best Choice by Scenario**

| **Scenario**                       | **Recommended Approach**    |
| ---------------------------------- | --------------------------- |
| 🏎️ Performance-focused            | 🥇 Iterative (main version) |
| 🧼 Clean, readable formatting      | 🥈 `ostringstream` version  |
| 💬 Interviews / Conceptual Clarity | 🥉 Recursive implementation |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public String countAndSay(int n) {
        String result = "1";
        for (int i = 2; i <= n; i++) {
            StringBuilder temp = new StringBuilder();
            int count = 1;
            for (int j = 1; j < result.length(); j++) {
                if (result.charAt(j) == result.charAt(j - 1)) {
                    count++;
                } else {
                    temp.append(count).append(result.charAt(j - 1));
                    count = 1;
                }
            }
            temp.append(count).append(result.charAt(result.length() - 1));
            result = temp.toString();
        }
        return result;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def countAndSay(self, n: int) -> str:
        result = "1"
        for _ in range(n - 1):
            i = 0
            new_result = ""
            while i < len(result):
                count = 1
                while i + 1 < len(result) and result[i] == result[i + 1]:
                    count += 1
                    i += 1
                new_result += str(count) + result[i]
                i += 1
            result = new_result
        return result
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
