---
title: "👀 Maximum People Visible in a Line | GFG Solution 🔥"
keywords🏷️: ["👀 visibility problem", "📐 monotonic stack", "📊 nearest greater", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum People Visible in a Line problem using monotonic stacks to efficiently count visible people in both directions. 🚀"
date: 📅 2025-01-23
---

# *23. Maximum People Visible in a Line*

The problem can be found at the following link:🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-people-visible-in-a-line/1)

## **🧩 Problem Description**

You are given an array `arr[]`, where `arr[i]` represents the height of the ith person standing in a line.

A person i can see another person j if:
- `height[j] < height[i]`
- There is no person k standing between them such that `height[k] ≥ height[i]`

Each person can see in both directions (front and back).

Your task is to find the maximum number of people that any person can see (including themselves).

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [6, 2, 5, 4, 5, 1, 6]
Output: 6
Explanation: Person 1 (height = 6) can see five other people at positions (2, 3, 4, 5, 6) 
in addition to himself, i.e., total 6. Person 7 (height = 6) can also see 6 people total.
```

### Example 2

```cpp
Input: arr[] = [1, 3, 6, 4]
Output: 4
Explanation: Person with height 6 can see persons with heights 1, 3 on the left and 4 
on the right, along with himself, giving a total of 4.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^4$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses a **Monotonic Stack** technique to efficiently compute visibility in both directions:

### **Monotonic Stack Algorithm**

1. **Left Visibility Computation:**
   * Initialize a visibility array `left[]` where each person can see themselves (value = 1).
   * Use a monotonic decreasing stack to track indices of people.
   * For each person at position `i`, pop all shorter people from the stack and accumulate their visibility counts.
   * This works because if person `i` can see person `j`, then person `i` can also see everyone that person `j` could see.

2. **Right Visibility Computation:**
   * Similarly, initialize a visibility array `right[]` with value 1 for each person.
   * Process the array from right to left using the same monotonic stack approach.
   * Accumulate visibility counts for people shorter than the current person.

3. **Calculate Maximum:**
   * For each person at position `i`, the total visible count is `left[i] + right[i] - 1`.
   * Subtract 1 to avoid counting the person themselves twice.
   * Return the maximum value across all positions.

4. **Key Insight:**
   * The monotonic stack ensures we only process each element once in each direction.
   * When a taller person appears, all shorter people in the stack become invisible to future processing.
   * The accumulated counts propagate visibility transitively.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is pushed and popped from the stack at most once during each pass (left and right), resulting in linear time complexity overall.
* **Expected Auxiliary Space Complexity:** O(n), as we use two auxiliary arrays of size n to store left and right visibility counts, along with a stack that can hold at most n elements in the worst case.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxPeople(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> l(n, 1), r(n, 1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) l[i] += l[s.top()], s.pop();
            s.push(i);
        }
        s = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] < arr[i]) r[i] += r[s.top()], s.pop();
            s.push(i);
        }
        for (int i = 0; i < n; i++) res = max(res, l[i] + r[i] - 1);
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass with Combined Visibility**

### 💡 Algorithm Steps:

1. Process array from left maintaining monotonic stack for left visibility
2. Store indices and their visible counts in auxiliary structure
3. Process from right and combine results on the fly
4. Track maximum visibility count during traversal

```cpp
class Solution {
public:
    int maxPeople(vector<int>& arr) {
        int n = arr.size(), ans = 1;
        vector<int> vis(n, 1);
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (!s.empty() && s.top().first < arr[i]) {
                cnt += s.top().second;
                s.pop();
            }
            s.push({arr[i], cnt});
            vis[i] = cnt;
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;
            while (!s.empty() && s.top().first < arr[i]) {
                cnt += s.top().second;
                s.pop();
            }
            s.push({arr[i], cnt});
            ans = max(ans, vis[i] + cnt - 1);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two linear passes through array
* **Auxiliary Space:** 💾 O(n) - Stack and visibility array

### ✅ **Why This Approach?**

* Combines computation with result tracking
* Uses value-count pairs for clarity
* Reduces redundant stack operations
 
## 📊 **3️⃣ Optimized Stack with Index Only**

### 💡 Algorithm Steps:

1. Use single visibility array updated bidirectionally
2. Maintain monotonic decreasing stack with indices only
3. Accumulate counts directly without separate left/right arrays
4. Find maximum in single final pass

```cpp
class Solution {
public:
    int maxPeople(vector<int>& arr) {
        int n = arr.size(), mx = 0;
        vector<int> dp(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            while (!st.empty() && arr[st.top()] < arr[i]) 
                dp[i] += dp[st.top()], st.pop();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            int r = 1;
            while (!st.empty() && arr[st.top()] < arr[i]) 
                r += dp[st.top()], st.pop();
            mx = max(mx, dp[i] + r - 1);
            dp[i] = r;
            st.push(i);
        }
        return mx;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time with stack operations
* **Auxiliary Space:** 💾 O(n) - Single DP array and stack

### ✅ **Why This Approach?**

* Memory efficient with single array reuse
* Cleaner stack management
* Direct maximum computation

## 📊 **4️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. For each person, scan left to count visible people with smaller heights.
2. For each person, scan right to count visible people with smaller heights.
3. Stop scanning when a person with equal or greater height is encountered.
4. Sum both directions and add 1 for the person themselves.

```cpp
class Solution {
public:
    int maxPeople(vector<int>& arr) {
        int n = arr.size(), mx = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            for (int j = i - 1; j >= 0 && arr[j] < arr[i]; j--) cnt++;
            for (int j = i + 1; j < n && arr[j] < arr[i]; j++) cnt++;
            mx = max(mx, cnt);
        }
        return mx;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested iteration for each position
* **Auxiliary Space:** 💾 O(1) - No extra space needed

### ✅ **Why This Approach?**

* Simplest to understand and implement.
* No complex data structures required.
* Good for small input sizes.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Two Array Stack**            | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Clear separation of logic      | 💾 Uses two auxiliary arrays         |
| 🔍 **Combined Visibility**         | 🟢 O(n)                | 🟡 O(n)                 | 📖 Inline result tracking         | 🔧 Slightly complex pair handling    |
| 🔄 **Single Array Stack**         | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Memory efficient               | 🔧 Array reuse needs care            |
| 📊 **Brute Force**                | 🔴 O(n²)               | 🟢 O(1)                 | 📖 Simple implementation          | 🐌 Slow for large inputs             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Two Array Stack**               | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Combined Visibility**           | ★★★★☆                     |
| 🔧 **Memory constraints**                             | 🥉 **Single Array Stack**            | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Two Array Stack**               | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxPeople(int[] arr) {
        int n = arr.length, res = 0;
        int[] l = new int[n], r = new int[n];
        Arrays.fill(l, 1);
        Arrays.fill(r, 1);
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!s.isEmpty() && arr[s.peek()] < arr[i]) l[i] += l[s.pop()];
            s.push(i);
        }
        s.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && arr[s.peek()] < arr[i]) r[i] += r[s.pop()];
            s.push(i);
        }
        for (int i = 0; i < n; i++) res = Math.max(res, l[i] + r[i] - 1);
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxPeople(self, arr):
        n = len(arr)
        l, r, s = [1] * n, [1] * n, []
        for i in range(n):
            while s and arr[s[-1]] < arr[i]: l[i] += l[s.pop()]
            s.append(i)
        s.clear()
        for i in range(n - 1, -1, -1):
            while s and arr[s[-1]] < arr[i]: r[i] += r[s.pop()]
            s.append(i)
        return max(l[i] + r[i] - 1 for i in range(n))
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>

