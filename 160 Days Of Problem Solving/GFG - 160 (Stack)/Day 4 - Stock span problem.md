---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Stack
  - Arrays
---

# 🚀 _Day 4. Stock span problem_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/stock-span-problem-1587115621)

## 💡 **Problem Description:**

The **Stock Span Problem** is a financial problem where we have a series of **daily stock prices**, and we need to compute the **span of each day's stock price**.

The **span of stock price on a given day i** is defined as the **maximum number of consecutive days** just before day `i`, for which the price of the stock on the given day is **less than or equal to its price on the current day**.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```plaintext
arr[] = [100, 80, 60, 70, 60, 75, 85]
```

#### **Output:**

```plaintext
[1, 1, 1, 2, 1, 4, 6]
```

#### **Explanation:**

- **Day 1:** `100` (No previous prices) → Span = `1`
- **Day 2:** `80` (Only `100` before it) → Span = `1`
- **Day 3:** `60` (Only `100, 80` before it) → Span = `1`
- **Day 4:** `70` (`60` before it) → Span = `2`
- **Day 5:** `60` (`70, 60` before it) → Span = `1`
- **Day 6:** `75` (`60, 70, 60` before it) → Span = `4`
- **Day 7:** `85` (`75, 60, 70, 60, 80` before it) → Span = `6`

### **Example 2:**

#### **Input:**

```plaintext
arr[] = [10, 4, 5, 90, 120, 80]
```

#### **Output:**

```plaintext
[1, 1, 2, 4, 5, 1]
```

#### **Explanation:**

- **Day 1:** `10` → Span = `1`
- **Day 2:** `4` → Span = `1`
- **Day 3:** `5` → Span = `2`
- **Day 4:** `90` → Span = `4`
- **Day 5:** `120` → Span = `5`
- **Day 6:** `80` → Span = `1`

### **Constraints:**

- $\(1 \leq \text{arr.size()} \leq 10^5\)$
- $\(1 \leq \text{arr[i]} \leq 10^5\)$

## 🎯 **My Approach:**

### **Optimized Stack-Based Approach (O(N) Time, O(N) Space)**

1. **Use a stack** to store indices of elements while iterating through the array.
2. **For each price, check previous smaller elements** by popping elements from the stack.
3. **The span is the difference between current index and stack's top** (or entire length if stack is empty).
4. **Push the current index into the stack** for future calculations.

### **Algorithm Steps:**

1. **Initialize an empty stack** and a result array.
2. **Iterate through the price array**:
   - Pop elements from the stack while they are **less than or equal to** current price.
   - Compute **span = current index - top of stack** (or full length if stack is empty).
   - Push the **current index** to the stack.
3. **Return the computed span array**.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** **O(N)**, since we process each element **only once** and each element is pushed and popped from the stack **at most once**.
- **Expected Auxiliary Space Complexity:** **O(N)**, due to the stack storing indices.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> span(arr.size());
        stack<int> st;

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            span[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        return span;
    }
};
```

<details>
  <summary><h2 align="center">📌 Alternative Approach</h2></summary>

## **Optimized Approach Using Precomputed Span (O(N) Time, O(N) Space)**

1. **Instead of using a stack, this approach precomputes span values directly.**
2. **For each element, it checks the previous smaller values using the already computed spans.**
3. **Time Complexity is O(N) because each element is processed once.**

```cpp
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> span(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            int spanCount = 1;
            while ((i - spanCount) >= 0 && arr[i - spanCount] <= arr[i]) {
                spanCount += span[i - spanCount];
            }
            span[i] = spanCount;
        }
        return span;
    }
};
```

🔹 **This approach avoids using a stack but still maintains O(N) complexity.**

## **📊 Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ⚡ **Method** | ✅ **Pros**                       | ⚠️ **Cons**            |
| --------------------------- | ---------------------- | ----------------------- | ------------- | --------------------------------- | ---------------------- |
| **Stack-Based (Optimized)** | 🟢 O(N)                | 🟡 O(N)                 | Stack         | Efficient and works for large `N` | Extra space for stack  |
| **Precomputed Span**        | 🟢 O(N)                | 🟡 O(N)                 | Iteration     | Avoids stack but still efficient  | Slightly complex logic |

## 💡 **Best Choice?**

- **For large constraints:** ✅ **Stack-Based Approach (O(N) Time, O(N) Space)** is the best.
- **Alternative Efficient Approach:** ✅ **Precomputed Span (O(N) Time, O(N) Space)** can be used if stack is not preferred.

</details>

## **Code (Java)**

```java
class Solution {
    public ArrayList<Integer> calculateSpan(int[] arr) {
        ArrayList<Integer> span = new ArrayList<>();
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < arr.length; i++) {
            int days = 1;
            while (!st.isEmpty() && arr[st.peek()] <= arr[i]) {
                days += span.get(st.pop());
            }
            span.add(days);
            st.push(i);
        }
        return span;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def calculateSpan(self, arr):
        span, st = [], []

        for i, price in enumerate(arr):
            days = 1
            while st and arr[st[-1]] <= price:
                days += span[st.pop()]
            span.append(days)
            st.append(i)

        return span
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
