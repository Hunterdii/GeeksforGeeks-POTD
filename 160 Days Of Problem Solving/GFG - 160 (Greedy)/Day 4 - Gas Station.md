---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Greedy
---

# 🚀 _Day 4. Gas Station_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/circular-tour-1587115620)

## 💡 **Problem Description:**

There are some gas stations along a **circular route**. You are given two integer arrays **gas[]** (the amount of gas at each station) and **cost[]** (the cost to travel to the next station).

You have a car with an **unlimited gas tank** and you start the journey with an **empty tank** from one of the gas stations.

Return the **index** of the starting gas station if it's possible to travel around the circuit without running out of gas at any station in a **clockwise direction**.  
If **no such starting station exists**, return **-1**.  
**Note:** If a solution exists, it is **guaranteed to be unique**.

> Note: Sorry for uploading late, my exam is going on.

## 🔍 **Example Walkthrough:**

### **Example 1:**

**Input:**

```cpp
gas[] = [4, 5, 7, 4]
cost[] = [6, 6, 3, 5]
```

**Output:**

```cpp
2
```

**Explanation:**

- Start at **index 2** (gas = 7).
- Travel to index 3: **7 - 3 + 4 = 8** (gas left).
- Travel to index 0: **8 - 5 + 4 = 7** (gas left).
- Travel to index 1: **7 - 6 + 5 = 6** (gas left).
- Return to index 2: **6 - 6 = 0** (gas left).  
  Hence, starting from **index 2** allows a complete circuit.

### **Example 2:**

**Input:**

```cpp
gas[] = [1, 2, 3, 4, 5]
cost[] = [3, 4, 5, 1, 2]
```

**Output:**

```cpp
3
```

**Explanation:**

- Start at **index 3** (gas = 4).
- Travel to index 4: **4 - 1 + 5 = 8** (gas left).
- Travel to index 0: **8 - 2 + 1 = 7** (gas left).
- Travel to index 1: **7 - 3 + 2 = 6** (gas left).
- Travel to index 2: **6 - 4 + 3 = 5** (gas left).
- Return to index 3: **5 - 5 = 0** (gas left).  
  Hence, starting from **index 3** allows a complete circuit.

### **Example 3:**

**Input:**

```cpp
gas[] = [3, 9]
cost[] = [7, 6]
```

**Output:**

```cpp
-1
```

**Explanation:**  
There is **no gas station** to start such that you can complete the circuit.

### **Constraints:**

- $\(1 \leq \text{gas.size()}, \text{cost.size()} \leq 10^6\)$
- $\(1 \leq \text{gas}[i], \text{cost}[i] \leq 10^3\)$

## 🎯 **My Approach:**

### **Greedy (Optimized)**

#### **Algorithm Steps:**

1. Traverse the gas stations and maintain:
   - **total:** Total difference between gas and cost.
   - **curr:** Current gas balance.
   - **start:** Starting index.
2. For each station:
   - Calculate the difference: **diff = gas[i] - cost[i]**.
   - Add **diff** to **total** and **curr**.
   - If **curr < 0**, it means that starting from the current start is not possible, so:
     - Update **start = i + 1**.
     - Reset **curr = 0**.
3. After traversing all stations:
   - If **total >= 0**, return **start**.
   - Otherwise, return **-1**.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** \(O(N)\), as we traverse the gas stations once.
- **Expected Auxiliary Space Complexity:** \(O(1)\), since we use only a few variables for calculation.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if (curr < 0) start = i + 1, curr = 0;
        }
        return total >= 0 ? start : -1;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Two-Pass Approach**

#### **Algorithm Steps:**

1. Calculate the **total gas balance**.
2. If the total gas is negative, it's **impossible to complete the circuit**.
3. If positive, find the **optimal start point**.

```cpp
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            if (curr < 0) {
                start = i + 1;
                curr = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
```

#### 📝 **Complexity Analysis:**

- ✅ **Time Complexity:** O(N) - We traverse the gas stations twice in the worst case.
- ✅ **Space Complexity:** O(1) - Only a few variables are used.

#### ✅ **Why This Approach?**

This method is intuitive, as it first ensures the total gas is non-negative and then finds the optimal start point.

## 🔁 **3️⃣ Prefix Sum Approach**

#### **Algorithm Steps:**

1. Calculate the **total gas balance**.
2. Track the **cumulative gas difference** while iterating.
3. If the cumulative gas drops below 0, update the start to the next station.

```cpp
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, sum = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            sum += diff;
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
```

#### 📝 **Complexity Analysis:**

- ✅ **Time Complexity:** O(N)
- ✅ **Space Complexity:** O(1)

#### ✅ **Why This Approach?**

Uses cumulative gas difference to determine a viable start point while maintaining efficiency.

## 🔄 **4️⃣ Efficient Circular Check**

#### **Algorithm Steps:**

1. Traverse the array in a **circular manner** using modular arithmetic.
2. If the **current gas balance** becomes negative, reset the start station to the next one.
3. If the **total gas** is positive, return the start station, otherwise return -1.

```cpp
class Solution {
  public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        int n = gas.size();
        for (int i = 0; i < 2 * n; i++) {
            int index = i % n;
            int diff = gas[index] - cost[index];
            total += diff;
            curr += diff;
            if (curr < 0) {
                start = index + 1;
                curr = 0;
                if (start >= n) break;
            }
        }
        return total >= 0 ? start : -1;
    }
};
```

#### 📝 **Complexity Analysis:**

- ✅ **Time Complexity:** O(N)
- ✅ **Space Complexity:** O(1)

#### ✅ **Why This Approach?**

Efficiently handles circular routes using modular arithmetic while keeping the logic simple.

### 🆚 **Comparison of Approaches**

| **Approach**             | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                             |
| ------------------------ | ---------------------- | ----------------------- | ---------------------------------- | --------------------------------------- |
| Greedy (Optimized)       | 🟢 O(N)                | 🟢 O(1)                 | Best performance, minimal space    | Harder to derive intuitively            |
| Two-Pass Approach        | 🟢 O(N)                | 🟢 O(1)                 | Simple to understand, efficient    | Requires two passes in some scenarios   |
| Prefix Sum Approach      | 🟢 O(N)                | 🟢 O(1)                 | Simple logic with cumulative sum   | Not significantly different from greedy |
| Efficient Circular Check | 🟢 O(N)                | 🟢 O(1)                 | Handles circular cases effectively | Slightly more complex logic             |

✅ **Best Choice?**

- Use the **Greedy (Optimized)** for maximum efficiency.
- The **Two-Pass** or **Prefix Sum** are suitable for simpler implementation.
- The **Efficient Circular Check** is ideal for circular track scenarios.

</details>

## **Code (Java)**

```java
class Solution {
    public int startStation(int[] gas, int[] cost) {
        int total = 0, curr = 0, start = 0;
        for (int i = 0; i < gas.length; i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            curr += diff;
            if (curr < 0) { start = i + 1; curr = 0; }
        }
        return total >= 0 ? start : -1;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def startStation(self, gas, cost):
        total = curr = start = 0
        for i in range(len(gas)):
            diff = gas[i] - cost[i]
            total += diff
            curr += diff
            if curr < 0: start, curr = i + 1, 0
        return start if total >= 0 else -1
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
