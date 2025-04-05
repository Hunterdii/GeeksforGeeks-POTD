## 05. Bottom View of Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)

### Problem Description

Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

**Note:** If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered.

**Example:**

Input:

```
       1
     /   \
    3     2
```

Output:

```
3 1 2
```

Explanation:
The bottom view of the binary tree will be 3, 1, 2.

### My Approach

1. **Initialization:**

   - Create a map `bottomViewMap` to store the bottom view nodes at each horizontal distance (hd).
   - Use a queue to perform a level order traversal of the tree, storing pairs of nodes and their corresponding horizontal distances.

2. **Level Order Traversal:**

   - Push the root node with horizontal distance 0 into the queue.
   - For each node, update the `bottomViewMap` with the node's value at its horizontal distance.
   - If the node has a left child, push it into the queue with horizontal distance `hd - 1`.
   - If the node has a right child, push it into the queue with horizontal distance `hd + 1`.

3. **Extract Bottom View:**
   - Iterate through the sorted keys of `bottomViewMap` to create the result array containing the bottom view of the binary tree.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we perform a level order traversal of the tree visiting each node once.
- **Expected Auxiliary Space Complexity:** O(n), as we use a map to store the nodes' values and a queue for the traversal.

### Code

#### C++

```cpp
class Solution {
  public:
    vector<int> bottomView(Node* root) {
        vector<int> res;
        if (root == NULL)
            return res;
        map<int, int> bottomViewMap;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            Node* node = p.first;
            int hd = p.second;
            bottomViewMap[hd] = node->data;

            if (node->left != NULL)
                q.push({node->left, hd - 1});
            if (node->right != NULL)
                q.push({node->right, hd + 1});
        }
        for (auto it : bottomViewMap)
            res.push_back(it.second);

        return res;
    }
};
```

#### Java

```java
import java.util.*;

class Solution {
    public ArrayList<Integer> bottomView(Node root) {
        ArrayList<Integer> res = new ArrayList<>();
        if (root == null)
            return res;

        TreeMap<Integer, Integer> bottomViewMap = new TreeMap<>();

        Queue<Pair<Node, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(root, 0));

        while (!q.isEmpty()) {
            Pair<Node, Integer> p = q.poll();
            Node node = p.getKey();
            int hd = p.getValue();

            bottomViewMap.put(hd, node.data);

            if (node.left != null)
                q.add(new Pair<>(node.left, hd - 1));
            if (node.right != null)
                q.add(new Pair<>(node.right, hd + 1));
        }

        for (Map.Entry<Integer, Integer> entry : bottomViewMap.entrySet())
            res.add(entry.getValue());

        return res;
    }

    class Pair<K, V> {
        private K key;
        private V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }
    }
}
```

#### Python

```python
from collections import deque, defaultdict

class Solution:
    def bottomView(self, root):
        res = []
        if not root:
            return res

        bottom_view_map = defaultdict(int)
        q = deque([(root, 0)])

        while q:
            node, hd = q.popleft()
            bottom_view_map[hd] = node.data

            if node.left:
                q.append((node.left, hd - 1))
            if node.right:
                q.append((node.right, hd + 1))

        for key in sorted(bottom_view_map.keys()):
            res.append(bottom_view_map[key])

        return res
```

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
