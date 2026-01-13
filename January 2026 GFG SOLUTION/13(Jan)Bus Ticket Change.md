---
title: "💰 Bus Ticket Change | GFG Solution 🚍"
keywords🏷️: ["💰 lemonade change", "🚌 bus ticket change", "📍 greedy algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Bus Ticket Change problem using a greedy strategy to ensure correct change for every customer in sequence. 🚀"
date: 📅 2025-01-13
---


# *13. Bus Ticket Change*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/lemonade-change/1)

## **🧩 Problem Description**

You are given an array `arr[]` representing passengers in a queue. Each bus ticket costs **5 coins**, and `arr[i]` denotes the note a passenger uses to pay (which can be **5, 10, or 20**). You must serve the passengers in the given order and always provide the correct change so that each passenger effectively pays exactly **5 coins**. Your task is to determine whether it is possible to serve all passengers in the queue without ever running out of change.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [5, 5, 5, 10, 20]
Output: true
Explanation: From the first 3 customers, we collect three 5 coins bills in order.
From the fourth customer, we collect a 10 coins bill and give back a 5 coins.
From the fifth customer, we give a 10 coins bill and a 5 coins bill.
Since all customers got correct change we return true.
```

### Example 2

```cpp
Input: arr[] = [5, 5, 10, 10, 20]
Output: false
Explanation: From the first two customers in order, we collect two 5 coins bills. 
For the next two customers in order, we collect a 10 coins bill and give back a 5 coins bill. 
For the last customer, we cannot give the change of 15 coins back because we only have two 10 coins bills. 
Since not every customer received the correct change, the answer is false.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $\text{arr}[i]$ contains only **[5, 10, 20]**

## **✅ My Approach**

The optimal approach uses a **Greedy Strategy** with **denomination tracking** to efficiently validate change-making capability:

### **Greedy Change Management**

1. **Initialize Counters:**
   * Track two counters: `f` (count of 5-coin notes) and `t` (count of 10-coin notes).
   * These represent the available change at any point.

2. **Process Each Payment:**
   * **For 5-coin payment:** Simply increment the count of 5-coin notes (no change needed).
   * **For 10-coin payment:** Check if we have at least one 5-coin note for change. If yes, give it and store the 10-coin note. Otherwise, return false.
   * **For 20-coin payment:** Apply greedy strategy - prefer giving one 10-coin and one 5-coin note (to preserve 5-coin notes). If not possible, give three 5-coin notes. If neither option works, return false.

3. **Greedy Optimization:**
   * Always prefer larger denominations when giving change for 20-coin payments.
   * This preserves smaller 5-coin notes which are more versatile for future transactions.

4. **Validation:**
   * If all passengers are served successfully without running out of change, return true.
   * Return false immediately upon first failure to provide correct change.

## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n), where n is the size of the array. We process each passenger exactly once in a single pass through the array.
* **Expected Auxiliary Space Complexity:** O(1), as we only use two integer variables to track the count of 5-coin and 10-coin notes, regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool canServe(vector<int>& arr) {
        int f = 0, t = 0;
        for (int x : arr) {
            if (x == 5) f++;
            else if (x == 10) {
                if (!f) return false;
                f--; t++;
            } else {
                if (t && f) { t--; f--; }
                else if (f >= 3) f -= 3;
                else return false;
            }
        }
        return true;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass with Early Exit**

### 💡 Algorithm Steps:

1. Track counts of 5 and 10 rupee notes in hand.
2. Process each customer payment sequentially.
3. Return immediately if unable to provide change.
4. Optimize change-giving strategy to preserve smaller denominations.

```cpp
class Solution {
public:
    bool canServe(vector<int>& arr) {
        int c5 = 0, c10 = 0;
        for (int bill : arr) {
            if (bill == 5) c5++;
            else if (bill == 10 && c5) { c5--; c10++; }
            else if (bill == 20 && c10 && c5) { c10--; c5--; }
            else if (bill == 20 && c5 >= 3) c5 -= 3;
            else return false;
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through array
* **Auxiliary Space:** 💾 O(1) - Only two counters used

### ✅ **Why This Approach?**

* Clean conditional structure for each case
* Early exit on first failure improves average performance
* Explicit handling of all payment scenarios

## 📊 **3️⃣ Switch-Case Pattern**

### 💡 Algorithm Steps:

1. Use switch statement for clear case handling of different bills.
2. Maintain denomination counters for available change.
3. Apply greedy strategy preferring larger notes first.
4. Validate change availability before accepting payment.

```cpp
class Solution {
public:
    bool canServe(vector<int>& arr) {
        int notes[2] = {0};
        for (int payment : arr) {
            switch(payment) {
                case 5: notes[0]++; break;
                case 10: if (!notes[0]--) return false; notes[1]++; break;
                default: 
                    if (notes[1] && notes[0]) { notes[1]--; notes[0]--; }
                    else if (notes[0] >= 3) notes[0] -= 3;
                    else return false;
            }
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear iteration through payments
* **Auxiliary Space:** 💾 O(1) - Fixed array of size 2

### ✅ **Why This Approach?**

* Switch statement provides clear branching logic
* Array storage for scalable denomination tracking
* Structured approach suitable for code maintenance

## 📊 **4️⃣ Bitwise State Compression**

### 💡 Algorithm Steps:

1. Pack both counters into single integer using bit manipulation.
2. Extract and update counts using bitwise operations.
3. Process payments with compact state representation.
4. Reduce memory footprint while maintaining logic.

```cpp
class Solution {
public:
    bool canServe(vector<int>& arr) {
        int state = 0;
        for (int x : arr) {
            int f = state & 0xFFFF, t = state >> 16;
            if (x == 5) f++;
            else if (x == 10) { if (!f) return false; f--; t++; }
            else { 
                if (t && f) { t--; f--; } 
                else if (f >= 3) f -= 3; 
                else return false; 
            }
            state = (t << 16) | f;
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Same linear scan with bitwise ops
* **Auxiliary Space:** 💾 O(1) - Single integer for state

### ✅ **Why This Approach?**

* Minimized variable usage through bit packing
* Educational demonstration of state compression
* Maintains constant space with clever encoding

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Greedy Counter**              | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal and simple             | 🔧 Requires careful logic            |
| 🔍 **Early Exit**                  | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Fast on invalid inputs         | 📝 More verbose conditionals         |
| 📊 **Switch-Case**                 | 🟢 O(n)                | 🟢 O(1)                 | 📖 Clear case separation          | 🔧 Slightly more code                |
| 🔄 **Bitwise Compression**         | 🟢 O(n)                | 🟢 O(1)                 | 💾 Ultra-compact state            | 🧠 Less readable code                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production code**                                | 🥇 **Greedy Counter**                | ★★★★★                     |
| 📖 **Interview clarity**                              | 🥈 **Early Exit**                    | ★★★★★                     |
| 🔧 **Structured design**                              | 🥉 **Switch-Case**                   | ★★★★☆                     |
| 🎯 **Memory-constrained**                             | 🏅 **Bitwise Compression**           | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public boolean canServe(int[] arr) {
        int f = 0, t = 0;
        for (int x : arr) {
            if (x == 5) f++;
            else if (x == 10) {
                if (f == 0) return false;
                f--; t++;
            } else {
                if (t > 0 && f > 0) { t--; f--; }
                else if (f >= 3) f -= 3;
                else return false;
            }
        }
        return true;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def canServe(self, arr):
        f = t = 0
        for x in arr:
            if x == 5: f += 1
            elif x == 10:
                if not f: return False
                f -= 1; t += 1
            else:
                if t and f: t -= 1; f -= 1
                elif f >= 3: f -= 3
                else: return False
        return True
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
