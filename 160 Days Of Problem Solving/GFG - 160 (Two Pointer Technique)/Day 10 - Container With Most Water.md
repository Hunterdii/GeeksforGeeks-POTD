---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - two-pointer-algorithm
  - Arrays
  - Mathematical
  - Puzzles
---

# 🚀 _Day 10. Container With Most Water_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/container-with-most-water0535)

## 💡 **Problem Description:**

Given an array `arr[]` of non-negative integers, where each element `arr[i]` represents the height of vertical lines, determine the maximum amount of water that can be contained between any two lines, along with the x-axis.

**Note:** In the case of a single vertical line, it will not be able to hold water.

## 🔍 **Example Walkthrough:**

**Input:**  
`arr[] = [1, 5, 4, 3]`  
**Output:**  
`6`  
**Explanation:**  
The vertical lines at heights `5` and `3` are 2 distance apart. The base size is `2`. The height of the container is the minimum of these two values, `min(5, 3) = 3`.  
So, the total area to hold water is `3 * 2 = 6`.

**Input:**  
`arr[] = [3, 1, 2, 4, 5]`  
**Output:**  
`12`  
**Explanation:**  
The vertical lines at heights `5` and `3` are 4 distance apart. The base size is `4`. The height of the container is the minimum of these two values, `min(5, 3) = 3`.  
So, the total area to hold water is `4 * 3 = 12`.

**Input:**  
`arr[] = [2, 1, 8, 6, 4, 6, 5, 5]`  
**Output:**  
`25`  
**Explanation:**  
The vertical lines at heights `8` and `5` are 5 distance apart. The base size is `5`. The height of the container is the minimum of these two values, `min(8, 5) = 5`.  
So, the total area to hold water is `5 * 5 = 25`.

### Constraints:

- $`1 <= arr.size() <= 10^5`$
- $`1 <= arr[i] <= 10^4`$

## 🎯 **My Approach:**

To solve this problem efficiently, we use the **two-pointer technique**:

1. **Two Pointers:** Start with two pointers, one at the beginning (`l`) and the other at the end (`r`) of the array.
2. **Calculate Area:** At every step, calculate the area between the lines at `arr[l]` and `arr[r]` using the formula:  
   $\[
   \text{Area} = (\text{r - l}) \times \min(\text{arr[l], arr[r]})
   $\]
3. **Update Result:** Keep track of the maximum area encountered.
4. **Move Pointers:** Move the pointer pointing to the shorter line inward to try to find a taller line and potentially increase the area.

This approach ensures that we efficiently traverse the array in $\(O(n)\)$ time.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** $\(O(n)\)$, where $\(n\)$ is the size of the array. Each element is processed once as we move the pointers inward.
- **Expected Auxiliary Space Complexity:** $\(O(1)\)$, as we only use a constant amount of additional space.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    int maxWater(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, res = 0;
        while (l < r) res = max(res, (r - l) * (arr[l] < arr[r] ? arr[l++] : arr[r--]));
        return res;
    }
};
```

## Code (Java)

```java
class Solution {
    public int maxWater(int[] arr) {
        int l = 0, r = arr.length - 1, res = 0;
        while (l < r) res = Math.max(res, (r - l) * (arr[l] < arr[r] ? arr[l++] : arr[r--]));
        return res;
    }
}
```

## Code (Python)

```python
class Solution:
    def maxWater(self, arr):
        l, r, res = 0, len(arr) - 1, 0
        while l < r:
            res = max(res, (r - l) * (arr[l] if arr[l] < arr[r] else arr[r]))
            l, r = (l + 1, r) if arr[l] < arr[r] else (l, r - 1)
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
