---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - prefix-sum
  - Arrays
---

# 🚀 _Day 1. Equilibrium Point_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/equilibrium-point-1587115620)

## 💡 **Problem Description:**

You are given an array of integers `arr[]`. The task is to find the **first equilibrium point** in the array.

The equilibrium point is an index (0-based indexing) such that the sum of all elements before that index is equal to the sum of elements after it. Return `-1` if no such point exists.

## 🔍 **Example Walkthrough:**

**Input:**  
`arr[] = [1, 2, 0, 3]`  
**Output:**  
`2`

**Explanation:**  
The sum of elements to the left of index `2` is `1 + 2 = 3`, and the sum of elements to the right is `0 + 3 = 3`.

**Input:**  
`arr[] = [1, 1, 1, 1]`  
**Output:**  
`-1`

**Explanation:**  
There is no equilibrium index in the array.

**Input:**  
`arr[] = [-7, 1, 5, 2, -4, 3, 0]`  
**Output:**  
`3`

**Explanation:**  
The sum of elements to the left of index `3` is `-7 + 1 + 5 = -1`, and the sum of elements to the right is `-4 + 3 + 0 = -1`.

### Constraints:

- $`3 <= arr.size() <= 10^6`$
- $`0 <= arr[i] <= 10^9`$

## 🎯 **My Approach:**

### 1. Prefix and Total Sum Comparison:

The problem can be efficiently solved by maintaining a **prefix sum** (sum of elements from the start to the current index) and comparing it with the **remaining sum** (total sum minus the prefix sum and the current element).

### Steps:

1. Compute the total sum of the array.
2. Iterate through the array while maintaining a running prefix sum.
3. At each index:
   - Subtract the current element from the total sum (this gives the remaining sum to the right of the index).
   - Compare the prefix sum with the remaining sum.
   - If they are equal, return the current index as the equilibrium point.
4. If no equilibrium point is found, return `-1`.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), where `n` is the size of the array. Each element is processed exactly once.
- **Expected Auxiliary Space Complexity:** O(1), as only a constant amount of extra space is used for variables like `prefix`, `total`, and loop counters.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    int findEquilibrium(vector<int>& arr) {
        for (long long sum = accumulate(arr.begin(), arr.end(), 0LL), sum2 = 0, i = 0; i < arr.size(); sum2 += arr[i++])
            if ((sum -= arr[i]) == sum2) return i;
        return -1;
    }
};
```

## Code (Java)

```java
class Solution {
    public static int findEquilibrium(int[] arr) {
        long sum = Arrays.stream(arr).asLongStream().sum(), sum2 = 0;
        for (int i = 0; i < arr.length; sum2 += arr[i++])
            if ((sum -= arr[i]) == sum2) return i;
        return -1;
    }
}
```

## Code (Python)

```python
class Solution:
    def findEquilibrium(self, arr):
        total, prefix = sum(arr), 0
        for i, val in enumerate(arr):
            total -= val
            if prefix == total:
                return i
            prefix += val
        return -1
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
