# *20. Find Only Repetitive Element from 1 to n-1*

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/find-repetitive-element-from-1-to-n-1/1)


## **Problem Description**

Given an array `arr[]` of size `n`, filled with numbers from `1` to `n-1` in random order. The array has **only one repetitive element**. Your task is to find this **repeating element**.

> It is guaranteed that **there is exactly one repeating element**.


## **Examples**

### **Example 1:**

#### **Input:**
```
arr[] = [1, 3, 2, 3, 4]
```

#### **Output:**
```
3
```

#### **Explanation:**
The number `3` is repeated in the array.


### **Example 2:**

#### **Input:**
```
arr[] = [1, 5, 1, 2, 3, 4]
```

#### **Output:**
```
1
```

#### **Explanation:**
The number `1` appears twice.


### **Example 3:**

#### **Input:**
```
arr[] = [1, 1]
```

#### **Output:**
```
1
```

#### **Explanation:**
The only possible value `1` is repeated.


## **Constraints:**

- $\(2 \leq \text{arr.size()} \leq 10^5\)$
- $\(1 \leq \text{arr}[i] \leq n - 1\)$


## **My Approach**

### **Floyd’s Tortoise and Hare (Cycle Detection Algorithm)**

The problem of finding a duplicate number in an array can be visualized as detecting a cycle in a linked list. Here's the intuition:

- Each element in the array represents a "pointer" to the next index, i.e., `arr[i]` points to `arr[arr[i]]`.
- Because there's one number that appears twice, it effectively creates a **cycle** in this virtual "linked list".
- Our goal is to **find the entry point of this cycle**, which corresponds to the repeated number.

To do this, we apply **Floyd’s Cycle Detection Algorithm**, commonly known as the *Tortoise and Hare* algorithm:

### **Algorithm Steps:**

1. **Phase 1 – Finding the Intersection Point:**
   - Initialize two pointers, `slow` and `fast`, both starting at the first index.
   - Move `slow` one step at a time (`slow = arr[slow]`).
   - Move `fast` two steps at a time (`fast = arr[arr[fast]]`).
   - Eventually, the two pointers will meet *inside* the cycle.

2. **Phase 2 – Finding the Entrance to the Cycle (Duplicate):**
   - Reinitialize one pointer (`fast`) to the start of the array.
   - Move both `slow` and `fast` one step at a time.
   - The point where they meet again is the **duplicate number** (the cycle's entry point).


## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), since each phase (finding intersection and finding entrance) takes linear time.
- **Expected Auxiliary Space Complexity:** O(1), as only a constant number of pointers are used.


## **Code (C++)**

```cpp
class Solution {
  public:
    int findDuplicate(vector<int>& a) {
        int s = a[0], f = a[0];
        do { 
            s = a[s];
            f = a[a[f]];
        } while (s != f);
        f = a[0];
        while (s != f) { 
            s = a[s];
            f = a[f];
        }
        return s;
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Negative Marking**

### **Algorithm Steps:**
1. Iterate through the array.
2. For each value, treat its absolute as an index and negate the number at that index.
3. If the number is already negative, it means we've seen it before → duplicate.

```cpp
class Solution {
  public:
    int findDuplicate(vector<int>& a) {
        for (int i = 0; i < a.size(); i++) {
            int idx = abs(a[i]);
            if (a[idx] < 0) return idx;
            a[idx] = -a[idx];
        }
        return -1;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)` (in-place)

> #### ⚠️ **Note:** Modifies the array.


## 📊 **3️⃣ HashSet**

### **Algorithm Steps:**
1. Maintain a set to track seen numbers.
2. On encountering a number already in set → duplicate.

```cpp
class Solution {
  public:
    int findDuplicate(vector<int>& a) {
        unordered_set<int> s;
        for (int x : a)
            if (!s.insert(x).second) return x;
        return -1;
    }
};
```

#### 📝 **Complexity Analysis:**
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

#### ✅ **Why This Approach?**
Easy to implement. Reliable for interview settings with clarity in logic.


### 🆚 **Comparison of Approaches**

| **Approach**             | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                          | ⚠️ **Cons**                         |
|--------------------------|------------------------|--------------------------|--------------------------------------|-------------------------------------|
| **Floyd's Algorithm**    | 🟢 `O(n)`              | 🟢 `O(1)`                 | Most efficient, no extra space       | Tricky to understand initially      |
| **Negative Marking**     | 🟢 `O(n)`              | 🟢 `O(1)` (in-place)       | Fast and memory efficient            | Modifies input array                |
| **HashSet Method**       | 🟢 `O(n)`              | 🔴 `O(n)`                 | Simple, beginner-friendly            | Uses extra space                    |

✅ **Best Choice?**
- **No space + optimal runtime:** Use **Floyd’s Tortoise and Hare**.
- **Modifying array allowed:** Try **Negative Marking**.
- **Easy & quick prototype:** Go with **HashSet**.
</details>

## **Code (Java)**

```java
class Solution {
    public int findDuplicate(int[] a) {
        int s = a[0], f = a[0];
        do { 
            s = a[s]; 
            f = a[a[f]];
        } while (s != f);
        f = a[0];
        while (s != f) { 
            s = a[s];
            f = a[f];
        }
        return s;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def findDuplicate(self, a):
        s = f = a[0]
        while True:
            s = a[s]
            f = a[a[f]]
            if s == f: break
        f = a[0]
        while s != f:
            s = a[s]
            f = a[f]
        return s
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
