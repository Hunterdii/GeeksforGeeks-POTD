# _27. Get Min from Stack_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/)

## **Problem Description**

Implement a stack that supports the following operations in **O(1) time**:

- `push(x)`: Push an integer **x** onto the stack.
- `pop()`: Remove the top element from the stack.
- `peek()`: Return the top element of the stack. If empty, return `-1`.
- `getMin()`: Retrieve the **minimum element** in the stack. If empty, return `-1`.

### **Examples**

#### **Example 1**

**Input:**

```
q = 7
queries = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
```

**Output:**

```
[3, 2, 1]
```

**Explanation:**

```
push(2) -> Stack: [2]
push(3) -> Stack: [2, 3]
peek() -> 3
pop() -> Stack: [2]
getMin() -> 2
push(1) -> Stack: [2, 1]
getMin() -> 1
```

#### **Example 2**

**Input:**

```
q = 4
queries = [[1, 4], [1, 2], [4], [3]]
```

**Output:**

```
[2, 2]
```

**Explanation:**

```
push(4) -> Stack: [4]
push(2) -> Stack: [4, 2]
getMin() -> 2
peek() -> 2
```

### **Constraints**

- $\(1 \leq q \leq 10^5\)$ (Number of queries)
- $\(1 \leq x \leq 10^9\)$ (Stack elements are within this range)

## **My Approach**

### **Using Two Stacks (O(1) Time, O(N) Space)**

1. Use **two stacks**:
   - `s` → **Normal stack** for elements.
   - `minStack` → **Keeps track of minimum values**.
2. When pushing an element `x`, check:
   - If `minStack` is empty or `x <= minStack.top()`, push `x` into `minStack`.
3. While popping, if the popped element is the **current min**, pop from `minStack`.
4. `getMin()` always returns `minStack.top()`.

## **Time and Auxiliary Space Complexity**

| **Operation** | **Time Complexity** | **Space Complexity** |
| ------------- | ------------------- | -------------------- |
| `push(x)`     | O(1)                | O(N) (extra stack)   |
| `pop()`       | O(1)                | O(N) (extra stack)   |
| `peek()`      | O(1)                | O(1)                 |
| `getMin()`    | O(1)                | O(1)                 |

## **Code (C++)**

```cpp
class Solution {
    stack<int> s, minStack;
public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) minStack.push(x);
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() == minStack.top()) minStack.pop();
        s.pop();
    }

    int peek() {
        return s.empty() ? -1 : s.top();
    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};
```

<details>
  <summary><h2 align="center">📌 Alternative Approaches</h2></summary>

### **2️⃣ Using Single Stack with Pair (`O(1)` Space Overhead)**

#### **Approach**

- Instead of maintaining two stacks, store **(value, min_so_far)** as a pair in one stack.
- This ensures `getMin()` always retrieves the min value in **O(1)** time.

```cpp
class Solution {
    stack<pair<int, int>> s;
public:
    void push(int x) { s.push({x, s.empty() ? x : min(x, s.top().second)}); }
    void pop() { if (!s.empty()) s.pop(); }
    int peek() { return s.empty() ? -1 : s.top().first; }
    int getMin() { return s.empty() ? -1 : s.top().second; }
};
```

🔹 **Reduces extra space needed for `minStack`!**

### **3️⃣ Using Single Stack with Variable (`O(1)` Extra Space)**

#### **Approach**

- Store the **minimum value separately** instead of using an extra stack.
- If `x` is **less than the current minimum**, **push a modified value** (2\*x - min).
- While popping, **restore the previous minimum**.

```cpp
class Solution {
    stack<long long> s;
    long long minVal;
public:
    void push(int x) {
        if (s.empty()) { minVal = x; s.push(x); }
        else if (x >= minVal) s.push(x);
        else { s.push(2LL * x - minVal); minVal = x; }
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() < minVal) minVal = 2 * minVal - s.top();
        s.pop();
    }

    int peek() { return s.empty() ? -1 : (s.top() < minVal ? minVal : s.top()); }
    int getMin() { return s.empty() ? -1 : minVal; }
};
```

🔹 **Uses `O(1)` extra space while maintaining `O(1)` operations!**

## **Comparison of Approaches**

| **Approach**                      | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                      | ⚠️ **Cons**                     |
| --------------------------------- | ---------------------- | ----------------------- | -------------------------------- | ------------------------------- |
| **Two Stacks (`s` & `minStack`)** | 🟢 `O(1)`              | 🟡 `O(N)`               | Simple & direct implementation   | Extra stack memory required     |
| **Single Stack with Pair**        | 🟢 `O(1)`              | 🟡 `O(N)`               | Stores min directly in one stack | Uses `pair<int, int>` overhead  |
| **Single Stack with Variable**    | 🟢 `O(1)`              | 🟢 `O(1)`               | Space-efficient, no extra stack  | Requires special encoding logic |

## **💡 Best Choice?**

- ✅ **For space efficiency:** Single stack with min encoding (`O(1)` space).
- ✅ **For clarity:** Two stacks (`s` & `minStack`).
- ✅ **For best of both worlds:** Single stack with pairs (`O(1)` operations).

</details>

## **Code (Java)**

```java
class Solution {
    private Stack<Integer> s = new Stack<>();
    private Stack<Integer> minStack = new Stack<>();
    public void push(int x) {
        s.push(x);
        if (minStack.isEmpty() || x <= minStack.peek()) {
            minStack.push(x);
        }
    }
    public void pop() {
        if (!s.isEmpty()) {
            if (s.peek().equals(minStack.peek())) {
                minStack.pop();
            }
            s.pop();
        }
    }
    public int peek() {
        return s.isEmpty() ? -1 : s.peek();
    }
    public int getMin() {
        return minStack.isEmpty() ? -1 : minStack.peek();
    }
}
```

## **Code (Python)**

```python
class Solution:
    def __init__(self):
        self.s, self.m = [], []

    def push(self, x):
        self.s.append(x)
        self.m.append(x if not self.m else min(x, self.m[-1]))

    def pop(self):
        if self.s: self.s.pop(), self.m.pop()

    def peek(self):
        return -1 if not self.s else self.s[-1]

    def getMin(self):
        return -1 if not self.m else self.m[-1]
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
