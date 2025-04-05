---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - two-pointer-technique
  - Arrays
  - prefix-sum
  - Searching
  - Sliding-window
---

# 🚀 _Day 6. Indexes of Subarray Sum_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/subarray-with-given-sum-1587115621)

## 💡 **Problem Description:**

You are given an array `arr[]` containing only non-negative integers and a target sum `target`. Your task is to find the first continuous subarray (a contiguous sequence of elements) whose sum equals the specified value `target`. If such a subarray exists, return the **1-based indices** of the leftmost and rightmost elements of this subarray. Otherwise, return `[-1]`.

## 🔍 **Example Walkthrough:**

#### **Input:**

`arr[] = [1, 2, 3, 7, 5]`  
`target = 12`

**Output:**  
`[2, 4]`

**Explanation:**  
The sum of elements from the 2nd to 4th positions (2, 3, and 7) is 12.

#### **Input:**

`arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]`  
`target = 15`

**Output:**  
`[1, 5]`

**Explanation:**  
The sum of elements from the 1st to 5th positions (1, 2, 3, 4, and 5) is 15.

#### **Input:**

`arr[] = [5, 3, 4]`  
`target = 2`

**Output:**  
`[-1]`

**Explanation:**  
No subarray exists with a sum equal to 2.

### **Constraints**

- $\( 1 \leq \text{arr.size()} \leq 10^6 \) $
- $\( 0 \leq \text{arr}[i] \leq 10^3 \) $
- $\( 0 \leq \text{target} \leq 10^9 \) $

## 🎯 **My Approach:**

1. **Sliding Window Technique (Two-Pointer Approach):**

   - Utilize a variable `curr` to keep track of the sum of elements in the current subarray.
   - Use two pointers:
     - A start pointer `s` that marks the beginning of the current subarray.
     - A moving end pointer `e` that iterates through the array.
   - Expand the window by adding the current element (`arr[e]`) to `curr`.
   - Shrink the window from the start by incrementing `s` while `curr > target`. Subtract elements from the sum during this process.
   - If `curr == target`, return the indices `[s + 1, e + 1]`.
   - If no subarray with the target sum exists, return `[-1]`.

2. **Edge Cases:**
   - If the array contains only one element: check if it equals the target.
   - If `target == 0`: return `[-1]` since all elements are non-negative.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** \( O(n) \), where \( n \) is the size of the array. The algorithm traverses the array only once, using the sliding window technique.
- **Expected Auxiliary Space Complexity:** \( O(1) \), as the solution uses a constant amount of additional space.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    vector<int> subarraySum(vector<int>& arr, int target) {
        int s = 0, curr = 0;
        for (int e = 0; e < arr.size(); ++e) {
            curr += arr[e];
            while (curr > target && s <= e) curr -= arr[s++];
            if (curr == target) return {s + 1, e + 1};
        }
        return {-1};
    }
};
```

## Code (Java)

```java
class Solution {
    static ArrayList<Integer> subarraySum(int[] arr, int target) {
        int s = 0, curr = 0;
        for (int e = 0; e < arr.length; e++) {
            curr += arr[e];
            while (curr > target && s <= e) curr -= arr[s++];
            if (curr == target) return new ArrayList<>(Arrays.asList(s + 1, e + 1));
        }
        return new ArrayList<>(Arrays.asList(-1));
    }
}
```

## Code (Python)

```python
class Solution:
    def subarraySum(self, arr, target):
        s, curr = 0, 0
        for e in range(len(arr)):
            curr += arr[e]
            while curr > target and s <= e:
                curr -= arr[s]
                s += 1
            if curr == target:
                return [s + 1, e + 1]
        return [-1]
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
