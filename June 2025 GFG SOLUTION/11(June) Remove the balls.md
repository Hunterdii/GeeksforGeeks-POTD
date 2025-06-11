---
title: "🎯 Remove the Balls | GFG Solution 🔵🔴"
keywords🏷️: ["🟣 remove balls", "🧹 stack removal", "🧠 in-place optimization", "📘 GFG", "💥 duplicate removal", "🔁 repeated pair", "🧮 DSA", "🏁 competitive programming"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the 'Remove the Balls' problem: simulate consecutive removal of matching balls using stack or in-place logic. 🚀"
date: 📅 2025-06-11
---

# *11. Remove the Balls*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/remove-the-balls--170647/1)


## **🧩 Problem Description**

You are given two arrays `color[]` and `radius[]`, representing a sequence of balls:

* `color[i]` denotes the color of the i-th ball.
* `radius[i]` denotes the radius of the i-th ball.

👉 If **two consecutive balls** have the **same color** and **same radius**, they are removed.
🧹 This removal process is repeated until no more such adjacent pairs exist.

🧮 Your task is to return the **number of balls remaining** after all possible removals.


## **📘 Examples**

### Example 1

```cpp
Input:
color[] = [2, 3, 5]
radius[] = [3, 3, 5]

Output:
3

Explanation:
All balls have different properties — no removals possible.
```

### Example 2

```cpp
Input:
color[] = [2, 2, 5]
radius[] = [3, 3, 5]

Output:
1

Explanation:
First two balls match in color and radius, so are removed.
Only one ball remains which cannot be removed.
```


## **🔒 Constraints**

* 1 ≤ color.length = radius.length ≤ 10⁵
* 1 ≤ color\[i] ≤ 10⁹
* 1 ≤ radius\[i] ≤ 10⁹


## ✅ My Approach

We simulate the **removal of consecutive equal balls** using **in-place stack simulation**:

### **Two-Pointer In-Place Simulation**

#### 💡 Idea:

Use a variable `j` as a **stack pointer** (think of it like the top of a stack):

1. Traverse through the `color[]` and `radius[]` arrays using `i`.
2. At each index `i`, check if `color[i] == color[j]` and `radius[i] == radius[j]`:

   * If **yes**, it’s a matching pair — **remove both** by decrementing `j`.
   * If **no**, move the current ball to the new `j` index (simulate pushing to stack).
3. Finally, return `j + 1` as the number of remaining balls.


## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where `n` is the number of balls. We traverse the list once and do constant work per step.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a few variables and modify the input in-place without extra space.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int findLength(vector<int>& color, vector<int>& radius) {
        int n = color.size(), j = -1;
        for (int i = 0; i < n; ++i) {
            if (j >= 0 && color[i] == color[j] && radius[i] == radius[j])
                --j;
            else {
                ++j;
                color[j] = color[i];
                radius[j] = radius[i];
            }
        }
        return j + 1;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Stack-Based Approach**

### 💡 Algorithm Steps:

1. Initialize a stack `st`.
2. For each index `i` from `0` to `n-1`:

   * If the stack is **not empty** and the `color[i] == color[st.top()]` **and** `radius[i] == radius[st.top()]`, pop the top of the stack.
   * Otherwise, push the index `i` into the stack.
3. Return the final size of the stack as the answer.

```cpp
class Solution {
public:
    int findLength(vector<int>& color, vector<int>& radius) {
        int n = color.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (!st.empty() && color[i] == color[st.top()] && radius[i] == radius[st.top()]) {
                st.pop();
            } else {
                st.push(i);
            }
        }
        return st.size();
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Space:** 💾 O(n) for stack

### ✅ **Pros:**

* Very intuitive — follows the direct simulation of the problem.
* Easy to debug and implement.

### ⚠️ **Cons:**

* Uses additional space for the stack (not in-place).


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**             | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**             | ⚠️ **Cons**            |
| --------------------------- | ---------------------- | ----------------------- | ---------------------- | ---------------------- |
| 🔲 **Stack**                | 🟢 O(n)                | 🟡 O(n)                 | Easy, clear logic      | Extra memory usage     |
| 🔳 **In-Place Two-Pointer** | 🟢 O(n)                | 🟢 O(1)                 | Memory-efficient, fast | Input gets overwritten |



### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                  | 🎖️ **Recommended Approach** |
| -------------------------------- | ---------------------------- |
| ⚡ Large inputs, best performance | 🥇 **In-Place Two-Pointer**  |
| 🔍 Easy to write & maintain      | 🥈 **Stack**                 |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int findLength(int[] color, int[] radius) {
        int j = -1;
        for (int i = 0; i < color.length; ++i) {
            if (j >= 0 && color[i] == color[j] && radius[i] == radius[j])
                j--;
            else {
                ++j;
                color[j] = color[i];
                radius[j] = radius[i];
            }
        }
        return j + 1;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findLength(self, color, radius):
        j = -1
        for i, (c, r) in enumerate(zip(color, radius)):
            if j >= 0 and c == color[j] and r == radius[j]:
                j -= 1
            else:
                j += 1
                color[j], radius[j] = c, r
        return j + 1
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
