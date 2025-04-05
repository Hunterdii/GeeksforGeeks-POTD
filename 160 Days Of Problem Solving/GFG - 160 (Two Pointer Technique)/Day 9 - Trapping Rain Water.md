---
Difficulty: Hard
Source: 160 Days of Problem Solving
Tags:
  - two-pointer-algorithm
  - Arrays
  - Dynamic Programming
  - Stack
---

# 🚀 _Day 9. Trapping Rain Water_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/trapping-rain-water-1587115621)

## 💡 **Problem Description:**

You are given an array `arr[]` of size `n`, where `arr[i]` represents the height of blocks, and the width of each block is 1. Your task is to calculate how much water can be trapped between the blocks after rainfall.

## 🔍 **Example Walkthrough:**

**Input:**  
`arr[] = [3, 0, 1, 0, 4, 0, 2]`  
**Output:**  
`10`  
**Explanation:**  
Water trapped = 0 + 3 + 2 + 3 + 0 + 2 + 0 = **10 units**

<img src="https://github.com/user-attachments/assets/0e54aa0d-cfd0-4e8c-87b5-c8a3df9b854c" width="45%">

**Input:**  
`arr[] = [3, 0, 2, 0, 4]`  
**Output:**  
`7`  
**Explanation:**  
Water trapped = 0 + 3 + 1 + 3 + 0 = **7 units**

**Input:**  
`arr[] = [2, 1, 5, 3, 1, 0, 4]`  
**Output:**  
`9`  
**Explanation:**  
Water trapped = 0 + 1 + 0 + 1 + 3 + 4 + 0 = **9 units**

**Input:**  
`arr[] = [1, 2, 3, 4]`  
**Output:**  
`0`  
**Explanation:**  
No water can be trapped as there are no height bounds on both sides.

### Constraints:

- $`1 < arr.size() < 10^5`$
- $`0 < arr[i] < 10^3`$

## 🎯 **My Approach:**

The problem can be solved efficiently using the **two-pointer technique**. This avoids the need for additional arrays to store left and right maximum heights, making the solution both time and space efficient. The key idea is to calculate the water trapped at each index by determining the minimum of the maximum heights on the left and right sides.

### Algorithm:

1. Initialize two pointers: `l` (left) starting at index 0 and `r` (right) starting at the last index.
2. Maintain two variables, `lMax` and `rMax`, to track the maximum heights seen so far from the left and right sides, respectively.
3. Use the following rules:
   - If `arr[l]` is smaller, calculate the water trapped at `l` using `lMax`, update `lMax` if needed, and move the left pointer (`l`) one step right.
   - If `arr[r]` is smaller, calculate the water trapped at `r` using `rMax`, update `rMax` if needed, and move the right pointer (`r`) one step left.
4. Continue until the two pointers meet.
5. The total water trapped is the sum of all individual contributions.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), as each element in the array is processed exactly once using the two-pointer approach.
- **Expected Auxiliary Space Complexity:** O(1), as no additional arrays or data structures are used, and only a constant amount of extra space is required for the pointers and variables.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    int maxWater(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, res = 0, lMax = 0, rMax = 0;
        while (l < r) {
            arr[l] < arr[r] ? (lMax = max(lMax, arr[l]), res += lMax - arr[l++]) : (rMax = max(rMax, arr[r]), res += rMax - arr[r--]);
        }
        return res;
    }
};
```

## Code (Java)

```java
class Solution {
    public int maxWater(int[] arr) {
        int l = 0, r = arr.length - 1, res = 0, lMax = 0, rMax = 0;
        while (l < r) {
            if (arr[l] < arr[r]) {
                lMax = lMax > arr[l] ? lMax : arr[l];
                res += lMax - arr[l++];
            } else {
                rMax = rMax > arr[r] ? rMax : arr[r];
                res += rMax - arr[r--];
            }
        }
        return res;
    }
}
```

## Code (Python)

```python
class Solution:
    def maxWater(self, arr):
        l, r, res, lMax, rMax = 0, len(arr) - 1, 0, 0, 0
        while l < r:
            if arr[l] < arr[r]: res += max(0, lMax - arr[l]); lMax = max(lMax, arr[l]); l += 1
            else: res += max(0, rMax - arr[r]); rMax = max(rMax, arr[r]); r -= 1
        return res
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
