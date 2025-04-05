---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Stack
---

# 🚀 _Day 3. Next Greater Element_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/next-larger-element-1587115620)

## 💡 **Problem Description:**

Given an array `arr[]` of integers, the task is to find the **next greater element** for each element of the array in order of their appearance in the array.  
The **next greater element** of an element in the array is the **nearest element on the right** which is **greater than the current element**.

If there does not exist a next greater element for the current element, then **next greater element** is **-1**.  
For example, the next greater element of the last element is always **-1**.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```plaintext
arr[] = [1, 3, 2, 4]
```

#### **Output:**

```plaintext
[3, 4, 4, -1]
```

#### **Explanation:**

- The next greater element for **1** is **3**.
- The next greater element for **3** is **4**.
- The next greater element for **2** is **4**.
- **4** has no greater element, so it is **-1**.

### **Example 2:**

#### **Input:**

```plaintext
arr[] = [6, 8, 0, 1, 3]
```

#### **Output:**

```plaintext
[8, -1, 1, 3, -1]
```

#### **Explanation:**

- The next greater element for **6** is **8**.
- The next greater element for **8** does not exist, so it is **-1**.
- The next greater element for **0** is **1**.
- The next greater element for **1** is **3**.
- **3** has no greater element, so it is **-1**.

### **Constraints:**

- $\(1 \leq \text{arr.size()} \leq 10^6\)$
- $\(0 \leq arr[i] \leq 10^9\)$

## 🎯 **My Approach:**

### **Optimized Stack-Based Approach (O(N) Time, O(N) Space)**

1. **Use a stack** to efficiently find the next greater element.
2. **Iterate from right to left**, maintaining a **monotonic decreasing stack**.
3. For each element:
   - **Pop elements** from the stack that are **smaller** than the current element.
   - The **top of the stack** is the next greater element.
   - **Push the current element** onto the stack for future comparisons.

### **Algorithm Steps:**

1. Initialize an **empty stack**.
2. Traverse the array **from right to left**.
3. For each element:
   - **Pop elements from the stack** while they are **≤ the current element**.
   - If the stack is **empty**, the next greater element is **-1**.
   - Otherwise, the top of the stack is the **next greater element**.
   - **Push the current element onto the stack**.
4. Return the modified array.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), since each element is pushed and popped at most once.
- **Expected Auxiliary Space Complexity:** O(N), due to the stack storing at most N elements in the worst case.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> s;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int val = arr[i];
            while (!s.empty() && s.top() <= val) s.pop();
            arr[i] = s.empty() ? -1 : s.top();
            s.push(val);
        }
        return arr;
    }
};
```

<details>
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Using Linked List (O(N) Time, O(N) Space)**

1. Iterate through the array and use a linked list to store indices of the next greater element.
2. As we traverse, pop elements from the linked list that are smaller than the current element.

```cpp
class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        list<int> indices;
        vector<int> res(arr.size(), -1);

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!indices.empty() && arr[indices.back()] <= arr[i]) indices.pop_back();
            if (!indices.empty()) res[i] = arr[indices.back()];
            indices.push_back(i);
        }
        return res;
    }
};
```

🔹 **Pros:** Simplifies stack implementation using a linked list.  
🔹 **Cons:** A little more complex and less intuitive than using a stack.

## **📊 Comparison of Approaches**

| **Approach**          | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**               | ⚠️ **Cons**                    |
| --------------------- | ---------------------- | ----------------------- | ------------------------- | ------------------------------ |
| **Optimized (Stack)** | 🟢 `O(N)`              | 🟡 `O(N)`               | Efficient and simple      | Requires extra space for stack |
| **Linked List**       | 🟡 `O(N)`              | 🟡 `O(N)`               | Efficient and alternative | Slightly more complex          |

## **💡 Best Choice?**

- ✅ **For best efficiency:** **Optimized Stack Approach (`O(N)`)**.
- ✅ **For alternative approach:** **Linked List (`O(N)`)**.

</details>

## **Code (Java)**

```java
class Solution {
    public ArrayList<Integer> nextLargerElement(int[] arr) {
        Stack<Integer> s = new Stack<>();
        for (int i = arr.length - 1; i >= 0; i--) {
            int val = arr[i];
            while (!s.isEmpty() && s.peek() <= val) s.pop();
            arr[i] = s.isEmpty() ? -1 : s.peek();
            s.push(val);
        }
        ArrayList<Integer> res = new ArrayList<>();
        for (int num : arr) res.add(num);
        return res;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def nextLargerElement(self, arr):
        s = []
        for i in range(len(arr) - 1, -1, -1):
            val = arr[i]
            while s and s[-1] <= val:
                s.pop()
            arr[i] = -1 if not s else s[-1]
            s.append(val)
        return arr
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
