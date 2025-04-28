# *28. Maximum Sum of Non-Adjacent Nodes*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1)


## **🧩 Problem Description**

Given a binary tree where each node has a positive integer value, the task is to find the **maximum sum of nodes** such that no two nodes are **directly connected** (i.e., if you pick a node, you cannot pick its parent or its immediate children).


## **📘 Examples**

### **Example 1:**

#### **Input:**
`root[] = [11, 1, 2]`

#### **Output:**
`11`

#### **Explanation:**
The maximum sum is obtained by selecting node `11`. Since selecting its children would violate the non-adjacency rule, they are skipped.


### **Example 2:**

#### **Input:**
`root[] = [1, 2, 3, 4, N, 5, 6]`

#### **Output:**
`16`

#### **Explanation:**
Pick nodes `1, 4, 5, and 6` for maximum sum `16`, maintaining the rule that no two selected nodes are directly connected.


## **🔒 Constraints**

- $1 \leq \text{No. of nodes in the tree} \leq 10^4$
- $1 \leq \text{Node.val} \leq 10^5$


## **✅ My Approach:**

### **Dynamic Programming on Trees (Pair Recursion)**

This method uses **postorder traversal** and **dynamic programming** to calculate two values at each node:
- **Include** current node → Node's value + exclude sum of left and right children.
- **Exclude** current node → Maximum of include/exclude from both children.

We recursively return a pair representing these two choices for each node.


### **Algorithm Steps:**

1. Define a recursive function `solve(root)` returning a `pair<int, int>`.
2. For a node:
   - If `root` is NULL, return `{0, 0}`.
   - Recursively solve for left and right children.
   - Calculate:
     - **Include** current node → root's value + exclude left + exclude right.
     - **Exclude** current node → max of left include/exclude + max of right include/exclude.
3. The final answer will be the maximum of the two values at the root.


## **🧮 Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), as each node is visited exactly once during the traversal.
- **Expected Auxiliary Space Complexity:** O(h), where *h* is the height of the tree, due to the recursion call stack.



## 🧠 **Code (C++)**

```cpp
class Solution {
  public:
    pair<int,int> solve(Node* root) {
        if (!root) return {0,0};
        auto l = solve(root->left), r = solve(root->right);
        return {root->data+l.second+r.second, max(l.first,l.second)+max(r.first,r.second)};
    }
    int getMaxSum(Node* root) {
        auto p=solve(root);
        return max(p.first,p.second);
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ DP with Memoization Map**

### **Algorithm Steps:**

- Maintain a `HashMap<Node*, pair<int,int>>` to store precomputed results.
- For each node:
  - Before solving, check if the result already exists in the map.
  - Otherwise, compute and store in the map.

```cpp
class Solution {
    unordered_map<Node*, pair<int,int>> dp;
    pair<int,int> solve(Node* root) {
        if (!root) return {0,0};
        if (dp.count(root)) return dp[root];
        auto l = solve(root->left), r = solve(root->right);
        return dp[root] = {root->data+l.second+r.second, max(l.first,l.second)+max(r.first,r.second)};
    }
  public:
    int getMaxSum(Node* root) {
        auto p = solve(root);
        return max(p.first,p.second);
    }
};
```

### ✅ **Why This Approach?**
- Useful when there are repeated subtrees (though rare in standard binary trees).


#### 📝 **Complexity Analysis:**
- **Expected Time Complexity:** O(n), as memoization ensures each node processed once.
- **Expected Auxiliary Space Complexity:** O(n), due to storage in the map.


### 🆚 **Comparison of Approaches**

| **Approach**                   | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                         | ⚠️ **Cons**                  |
|----------------------------------|-------------|--------------|-------------------------------------|-------------------------------|
| Simple DP Recursion             | 🟢 O(n)      | 🟢 O(h)       | Clean, minimal extra space          | Stack overflow if tree too deep |
| DP + Memoization Map             | 🟢 O(n)      | 🔴 O(n)       | Better in overlapping cases         | More memory consumption        |


</details>


## 🧑‍💻 **Code (Java)**

```java
class Solution {
    int[] solve(Node r){
        if(r==null)return new int[]{0,0};
        int[] l=solve(r.left),r1=solve(r.right);
        return new int[]{r.data+l[1]+r1[1],Math.max(l[0],l[1])+Math.max(r1[0],r1[1])};
    }
    public int getMaxSum(Node r){
        int[] p=solve(r);
        return Math.max(p[0],p[1]);
    }
}
```


## 🐍 **Code (Python)**

```python
class Solution:
    def solve(self,r):
        if not r: return (0,0)
        l,r1=self.solve(r.left),self.solve(r.right)
        return (r.data+l[1]+r1[1],max(l)+max(r1))
    def getMaxSum(self,root):
        return max(self.solve(root))
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
