# *20. Burning Tree*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/burning-tree/1)

## **🧩 Problem Description**

You are given a binary tree and a target node. The task is to determine the minimum time required to burn the entire tree if the fire starts from the target node.

In each time unit, the fire spreads to adjacent nodes: the parent, left child, and right child of a burning node.

## **📘 Examples**

### **Example 1:**

#### **Input:**

```
Input: root[] = [1, 2, 3, 4, 5, 6, 7]
Target = 2
```


<img src="https://github.com/user-attachments/assets/1939164d-f574-4660-9558-32d93b68fd12" width="30%">


#### **Output:**

`3`

#### **Explanation:**

* Initially 2 is set to fire at 0 sec 
* At 1 sec: Nodes 4, 5, 1 catches fire.
* At 2 sec: Node 3 catches fire.
* At 3 sec: Nodes 6, 7 catches fire.
* It takes 3s to burn the complete tree.

### **Example 2:**

#### **Input:**

```
Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10]
Target = 10
```


<img src="https://github.com/user-attachments/assets/392736f2-8147-43a3-9951-68a821c73ab5" width="30%">


#### **Output:**

`5`

#### **Explanation:**

* Initially 10 is set to fire at 0 sec 
* At 1 sec: Node 5 catches fire.
* At 2 sec: Node 2 catches fire.
* At 3 sec: Nodes 1 and 4 catches fire.
* At 4 sec: Node 3 and 8 catches fire.
* At 5 sec: Node 7 catches fire.
* It takes 5s to burn the complete tree.


## **🔒 Constraints**

* Number of nodes in the tree: \$1 \leq N \leq 10^5\$
* Node values are unique and in the range $\[1, 10^5]\$


## **✅ My Approach**

### **DFS with Postorder Backtracking**

We use a recursive DFS to calculate:

* The **height** of each subtree.
* The **distance** from the current node to the target node (if it exists in the subtree).
* The maximum time taken to burn all affected nodes from the target.

The idea is to perform a postorder traversal and:

1. Track when the target is found and how far it is from the current node.
2. Compute burn time as the **maximum of:**

   * Distance to target in one subtree + height of the other subtree.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** `O(N)` — Every node is visited once during DFS.
* **Expected Auxiliary Space Complexity:** `O(H)` — Due to recursion stack, where `H` is the height of the tree.


## **🧠 Code (C++)**

```cpp
class Solution {
public:
    int ans;
    pair<int,int> dfs(Node* r,int t){
        if(!r) return {0,-1};
        auto l=dfs(r->left,t), ri=dfs(r->right,t);
        int h=max(l.first,ri.first)+1, d=-1;
        if(r->data==t) d=0, ans=max(ans,h-1);
        else if(l.second>=0) d=l.second+1, ans=max(ans,ri.first+d);
        else if(ri.second>=0) d=ri.second+1, ans=max(ans,l.first+d);
        return {h,d};
    }
    int minTime(Node* root,int target){
        ans=0;
        dfs(root,target);
        return ans;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ BFS from Target with Parent Mapping**

### 📌 **Algorithm Steps**

1. Traverse the tree and create a map from each node to its parent.
2. Find the node with the target value using DFS.
3. Perform a level-order BFS starting from the target node.
4. At each level, spread the fire to the left, right, and parent nodes.
5. Track visited nodes to avoid reprocessing and count the number of levels needed to burn all nodes.



```cpp
class Solution {
  void mapParents(Node* root, unordered_map<Node*, Node*>& par) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      Node* cur = q.front(); q.pop();
      if (cur->left) par[cur->left] = cur, q.push(cur->left);
      if (cur->right) par[cur->right] = cur, q.push(cur->right);
    }
  }

  Node* findTarget(Node* root, int target) {
    if (!root) return nullptr;
    if (root->data == target) return root;
    Node* l = findTarget(root->left, target);
    if (l) return l;
    return findTarget(root->right, target);
  }

public:
  int minTime(Node* root, int target) {
    unordered_map<Node*, Node*> par;
    mapParents(root, par);
    Node* start = findTarget(root, target);
    
    unordered_set<Node*> vis;
    queue<Node*> q;
    q.push(start);
    vis.insert(start);

    int time = -1;
    while (!q.empty()) {
      int sz = q.size();
      time++;
      for (int i = 0; i < sz; ++i) {
        Node* cur = q.front(); q.pop();
        if (cur->left && !vis.count(cur->left)) vis.insert(cur->left), q.push(cur->left);
        if (cur->right && !vis.count(cur->right)) vis.insert(cur->right), q.push(cur->right);
        if (par[cur] && !vis.count(par[cur])) vis.insert(par[cur]), q.push(par[cur]);
      }
    }
    return time;
  }
};
```


### ✅ **Why This Approach?**

* Conceptually simple and flexible.
* Converts tree to a graph and simulates fire propagation.
* Works well for problems requiring path traversal in all directions.


### 📝 **Complexity Analysis**

* **Time Complexity:** 🔸 `O(N)` — Each node is visited once during mapping and once during BFS.
* **Auxiliary Space:** 🔸 `O(N)` — Space used for parent map, visited set, and BFS queue.


## 📊 **3️⃣ Postorder DFS with Distance Tracking**

### 📌 **Algorithm Steps**

1. Perform a DFS traversal.
2. If the current node is the target, return distance 0.
3. If one of the subtrees returns a valid distance, update the global burn time by summing distance to this node and height of the other subtree.
4. Return height and distance for further propagation.


```cpp
class Solution {
  int ans = 0;

  int dfs(Node* root, int target, int& dist) {
    if (!root) return 0;
    
    if (root->data == target) {
      dist = 0;
      int l = dfs(root->left, target, dist), r = dfs(root->right, target, dist);
      ans = max(ans, max(l, r));
      return max(l, r) + 1;
    }

    int ldist = -1, rdist = -1;
    int lh = dfs(root->left, target, ldist);
    int rh = dfs(root->right, target, rdist);

    if (ldist != -1) {
      dist = ldist + 1;
      ans = max(ans, dist + rh);
    } else if (rdist != -1) {
      dist = rdist + 1;
      ans = max(ans, dist + lh);
    }

    return max(lh, rh) + 1;
  }

public:
  int minTime(Node* root, int target) {
    int dist = -1;
    dfs(root, target, dist);
    return ans;
  }
};
```


### ✅ **Why This Approach?**

* Pure DFS solution without auxiliary structures like parent maps.
* Computes everything during a single recursive pass.
* Slightly cleaner than the original if structured properly.


### 📝 **Complexity Analysis**

* **Time Complexity:** 🔸 `O(N)` — Each node is visited once during DFS.
* **Auxiliary Space:** 🔸 `O(H)` — Stack space used in recursion (H = tree height).


## 🆚 Comparison

| **Approach**               | ⏱️ **Time** | 🗂️ **Aux Space** | ✅ **Pros**                                        | ⚠️ **Cons**                      |
| -------------------------- | ----------- | ----------------- | ------------------------------------------------- | -------------------------------- |
| Original DFS               | 🟢 O(N)     | 🟢 O(H)           | Elegant, no parent map needed                     | Slightly harder to debug         |
| BFS with Parent Map        | 🔸 O(N)     | 🔸 O(N)           | Conceptually clean, simulates spread step-by-step | Needs extra space for parent map |
| DFS with Distance Tracking | 🔸 O(N)     | 🔸 O(H)           | Simplified and intuitive recursive structure      | Slightly verbose                 |


### ✅ **Best Choice by Scenario**

| **Scenario**                        | **Recommended Approach**      |
| ----------------------------------- | ----------------------------- |
| General tree with multiple targets  | 🥇 BFS with Parent Map        |
| Purely recursive solution preferred | 🥈 DFS with Distance Tracking |
| Shortest & most optimized code      | 🥉 Original Postorder DFS     |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    static int ans;
    public static int minTime(Node root,int t){
        ans=0;
        dfs(root,t);
        return ans;
    }
    static int[] dfs(Node r,int t){
        if(r==null) return new int[]{0,-1};
        int[] l=dfs(r.left,t), ri=dfs(r.right,t);
        int h=Math.max(l[0],ri[0])+1, d=-1;
        if(r.data==t){ d=0; ans=Math.max(ans,h-1); }
        else if(l[1]>=0){ d=l[1]+1; ans=Math.max(ans,ri[0]+d); }
        else if(ri[1]>=0){ d=ri[1]+1; ans=Math.max(ans,l[0]+d); }
        return new int[]{h,d};
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minTime(self, root, target):
        self.ans = 0
        def dfs(r):
            if not r: return (0, -1)
            l0, l1 = dfs(r.left)
            r0, r1 = dfs(r.right)
            h = max(l0, r0) + 1
            d = -1
            if r.data == target:
                d = 0
                self.ans = max(self.ans, h-1)
            elif l1 >= 0:
                d = l1 + 1
                self.ans = max(self.ans, r0 + d)
            elif r1 >= 0:
                d = r1 + 1
                self.ans = max(self.ans, l0 + d)
            return (h, d)
        dfs(root)
        return self.ans
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
