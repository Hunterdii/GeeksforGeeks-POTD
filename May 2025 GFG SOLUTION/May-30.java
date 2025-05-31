/*
class Node {
    int data;
    Node left, right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}
*/

// 1) Recursive version
class Solution {
    public int findMaxFork(Node root, int k) {
        if (root == null) return -1;
        if (root.data == k) return k;
        if (root.data < k) {
            int x = findMaxFork(root.right, k);
            return x == -1 ? root.data : x;
        }
        return findMaxFork(root.left, k);
    }
}

// 2) Iterative version
class Solution {
    public int findMaxFork(Node root, int k) {
        int res = -1;
        while (root != null) {
            if (root.data == k) return k;
            if (root.data < k) {
                res = root.data;
                root = root.right;
            } else {
                root = root.left;
            }
        }
        return res;
    }
}
