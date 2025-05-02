# *2. Bitonic Point*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1)

## **🧩 Problem Description**

Given an array `arr[]` of `n` elements that is first strictly increasing and then (optionally) strictly decreasing, return the **Bitonic Point** — the **maximum** element in the array.
It is guaranteed that the array contains **exactly one** bitonic point.

> A Bitonic Point is the element where the sequence changes from increasing to decreasing — or simply the largest number in a bitonic array.

> **Edge Cases:**
>
> * Entirely increasing → last element is peak.
> * Entirely decreasing → first element is peak.

## **📘 Examples**

### **Example 1:**

**Input:**

```
arr = [1, 2, 4, 5, 7, 8, 3]
```

**Output:**

```
8
```

**Explanation:**

* Increasing: `[1, 2, 4, 5, 7]`
* Peak: `8`
* Decreasing: `[3]`


### **Example 2:**

**Input:**

```
arr = [10, 20, 30, 40, 50]
```

**Output:**

```
50
```

**Explanation:**

* Increasing: `[10, 20, 30, 40]`
* Peak: `50`
* Decreasing: `[]`


### **Example 3:**

**Input:**

```
arr = [120, 100, 80, 20, 0]
```

**Output:**

```
120
```

**Explanation:**

* Increasing: `[]`
* Peak: `120`
* Decreasing: `[100, 80, 20, 0]`

## **🔒 Constraints**

* \$3 \leq n \leq 10^5\$
* \$1 \leq arr\[i] \leq 10^6\$

## **✅ My Approach**

### **Optimized Approach: Binary Search on Bitonic Pattern**

We observe that:

* If `arr[mid] > arr[mid+1]`, then the maximum lies **to the left** (including mid).
* If `arr[mid] < arr[mid+1]`, then the maximum lies **to the right**.

This is a classical bitonic binary search:

* We use a variant of binary search to reduce the search space logarithmically.
* We stop when we find the peak element such that `arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]`.


### **Algorithm Steps:**

1. Initialize `low = 0`, `high = n - 1`.
2. While `low < high`:

   * Compute `mid = (low + high) // 2`.
   * If `arr[mid] < arr[mid + 1]`: Move right → `low = mid + 1`
   * Else: Move left (may include mid) → `high = mid`
3. Return `arr[low]` as the maximum bitonic point.

## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(log n), as we use binary search to find the peak.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional variables.


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < arr[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }
        return arr[low];
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **1️⃣ STL `max_element`**

#### **Algorithm Steps:**

1. Return `*max_element(arr.begin(), arr.end())`.

```cpp
class Solution {
  public:
    int findBitonicPoint(vector<int> &arr) {
        return *max_element(arr.begin(), arr.end());
    }
};
```

### ✅ **Why This Approach?**

* Utilizes STL to find the maximum with minimal code.
* Very readable and quick for small or throwaway tasks.

#### 📝 **Complexity Analysis:**

* **Time:** O(n) – full array scan.
* **Auxiliary Space:** O(1)

## 📊 **2️⃣ Single‐Pass Manual Scan**

### **Algorithm Steps:**

1. Initialize `mx = arr[0]`.
2. For each element `x` in `arr` from index 1 onward:

   * If `x > mx`, set `mx = x`.
3. Return `mx`.

```cpp
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int mx = arr[0];
        for (int i = 1; i < arr.size(); ++i)
            if (arr[i] > mx) mx = arr[i];
        return mx;
    }
};
```

### ✅ **Why This Approach?**

* Straightforward, explicit control over the process.
* Easy to debug and adapt, good for beginner-level implementations.

#### 📝 **Complexity Analysis:**

* **Time:** O(n) – scans each element once.
* **Auxiliary Space:** O(1)


## 📊 **3️⃣ Divide & Conquer**

### **Algorithm Steps:**

1. Recursively split `arr` into two halves.
2. Base case: size 1 → return `arr[l]`.
3. Combine step: return `max(left_max, right_max)`.

```cpp
class Solution {
    int dc(vector<int>& a, int l, int r) {
        if (l == r) return a[l];
        int m = (l + r) >> 1;
        return max(dc(a, l, m), dc(a, m+1, r));
    }
  public:
    int findMaximum(vector<int> &arr) {
        return dc(arr, 0, arr.size() - 1);
    }
};
```

### ✅ **Why This Approach?**

* Demonstrates recursive problem-solving.
* Useful in educational contexts or recursive design practice.

#### 📝 **Complexity Analysis:**

* **Time:** O(n) – full traversal through recursion.
* **Auxiliary Space:** O(log n) – due to recursion stack.


## 📊 **4️⃣ Ternary Search**

### **Algorithm Steps:**

1. Since the array is unimodal, use ternary search.
2. At each step:

   * Calculate two midpoints: `mid1` and `mid2`.
   * Narrow search to the region containing the peak.

```cpp
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        while (r - l > 2) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (arr[m1] < arr[m2])
                l = m1;
            else
                r = m2;
        }
        return max({arr[l], arr[l+1], arr[r]});
    }
};
```

### ✅ **Why This Approach?**

* Takes advantage of the unimodal nature of bitonic arrays.
* Achieves efficient peak-finding in logarithmic time.

#### 📝 **Complexity Analysis:**

* **Time:** O(log n) – search space reduced by thirds.
* **Auxiliary Space:** O(1)


## 🆚 **Comparison of Approaches**

| **Approach**          | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                                           | ⚠️ **Cons**                    |
| --------------------- | ----------- | ------------- | ---------------------------------------------------- | ------------------------------ |
| **Binary Search**     | 🟢 O(log n) | 🟢 O(1)       | Optimal, efficient for large input, fast convergence | Requires bitonic property      |
| **STL `max_element`** | 🟡 O(n)     | 🟢 O(1)       | Minimal code, clean and expressive                   | Linear time, C++ only          |
| **Manual Scan**       | 🟡 O(n)     | 🟢 O(1)       | Simple, intuitive, good for learning                 | Not optimal for large datasets |
| **Divide & Conquer**  | 🟡 O(n)     | 🔸 O(log n)   | Demonstrates recursion, educational                  | Recursion overhead, slower     |
| **Ternary Search**    | 🟢 O(log n) | 🟢 O(1)       | Logarithmic time, elegant for unimodal arrays        | Slightly more complex to write |


### ✅ **Best Choice?**

| **Scenario**                         | **Recommended Approach** |
| ------------------------------------ | ------------------------ |
| Optimal performance (log time)       | 🥇 Binary Search         |
| Writing minimal code (C++ only)      | 🥈 STL `max_element`     |
| Simple, readable implementation      | 🥉 Manual Scan           |
| Practicing recursion / divide & rule | 🎯 Divide & Conquer      |
| Applying unimodal search techniques  | 🎖️ Ternary Search       |


</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int findMaximum(int[] arr) {
        int low = 0, high = arr.length - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < arr[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }
        return arr[low];
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def findMaximum(self, arr):
        low, high = 0, len(arr) - 1
        while low < high:
            mid = (low + high) // 2
            if arr[mid] < arr[mid + 1]:
                low = mid + 1
            else:
                high = mid
        return arr[low]
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

