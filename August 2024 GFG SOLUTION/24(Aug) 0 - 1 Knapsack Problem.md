# **24. 0-1 Knapsack Problem**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)

### **Problem Description**

You are given weights and values of items, and you need to put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack. Note that we have only one quantity of each item.

Given two integer arrays `val[]` and `wt[]` which represent values and weights associated with items, respectively. Also given an integer `W` which represents the knapsack's capacity, find the maximum sum of values in `val[]` such that the sum of the weights in the corresponding subset is less than or equal to `W`. You cannot break an item, either pick the complete item or don't pick it (0-1 property).

**Examples:**

**Input:**

```
W = 4, val[] = {1, 2, 3}, wt[] = {4, 5, 1}
```

**Output:**

```
3
```

**Explanation:** Choose the last item that weighs 1 unit and holds a value of 3.

### **My Approach**

1. **Dynamic Programming Approach:**

   - Initialize an array `K` of size `W + 1` with all elements as 0. This array will store the maximum value that can be obtained for each capacity from `0` to `W`.
   - Iterate through each item, and for each item, iterate through the capacities from `W` down to the weight of the item. Update the array `K` to store the maximum value possible for each capacity.

2. **Optimal Substructure:**
   - The problem exhibits optimal substructure, as the solution to a problem of size `n` can be derived from solutions to problems of size `n-1`.

### **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N\*W), as we iterate through each item and for each item, we iterate through the capacities.
- **Expected Auxiliary Space Complexity:** O(W), as we use a one-dimensional array of size `W + 1` to store the maximum value for each capacity.

### **Code (C++)**

```cpp
class Solution {
public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<int> K(W + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) {
                K[w] = max(K[w], val[i] + K[w - wt[i]]);
            }
        }
        return K[W];
    }
};
```

### **Code (Java)**

```java
class Solution {
    static int knapSack(int W, int[] wt, int[] val) {
        int n = wt.length;
        int[] K = new int[W + 1];

        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) {
                K[w] = Math.max(K[w], val[i] + K[w - wt[i]]);
            }
        }
        return K[W];
    }
}
```

### **Code (Python)**

```python
class Solution:
    def knapSack(self, W, wt, val):
        n = len(wt)
        K = [0] * (W + 1)

        for i in range(n):
            for w in range(W, wt[i] - 1, -1):
                K[w] = max(K[w], val[i] + K[w - wt[i]])

        return K[W]
```

## **Note**

Sorry for uploading this late; my exams are going on.

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
